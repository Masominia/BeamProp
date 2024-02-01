"""Simulates the whole layout library, checks it and writes the report."""

from __future__ import annotations

import json
from pathlib import Path

import pandas as pd
import yaml

from . import cases, engine, plotting, reference, studies
from .compare import compare
from .engine import ROOT
from .report import md_table


def _check(area, check, ok, detail):
    return {"area": area, "check": check, "status": "PASS" if ok else "FAIL", "detail": detail}


def run(cfg_path=None, out=None, fast: bool = False) -> dict:
    cfg = yaml.safe_load(open(cfg_path or ROOT / "configs" / "default.yaml"))
    out = Path(out) if out else ROOT / "reports"
    (out / "figures" / "cases").mkdir(parents=True, exist_ok=True)
    if not engine.available():
        raise SystemExit("C++ solver not built: run `make build` first")
    paths = cases.discover(ROOT / cfg["cases_dir"])
    if fast:
        keep = tuple(cfg["fast_families"])
        paths = [
            p
            for i, p in enumerate(paths)
            if i % cfg["fast_every"] == 0 or p.stem in cfg["gallery"] or p.stem.startswith(keep)
        ]

    checks, rows, worst, results, where = [], [], {}, {}, {}
    for path in paths:
        record, result = cases.run_case(path)
        family = cases.family_of(path.stem, cfg["families"])
        cmp = compare(path, result)
        record["monitors"], record["planes"] = result["monitors"], result["planes"]
        record["against_reference"] = cmp["differences"]
        for name, diff in cmp["differences"].items():
            worst[name] = max(worst.get(name, 0.0), diff)
        checks.append(
            _check(
                "independent propagation",
                f"{path.stem}: monitors, planes, index and output field stepped again in NumPy",
                not cmp["outside"],
                "; ".join(cmp["outside"]) or f"output field within {cmp['differences']['field']:.1e} of its peak",
            )
        )
        if path.stem in cfg["modal_check"]:
            error = studies.modal_error(path, result)
            record["against_modal_solution"] = error
            bound = cfg["modal_bound"]
            checks.append(
                _check(
                    "solution without stepping",
                    f"{path.stem}: output field against the modal solution of the same grid",
                    error < bound,
                    f"largest difference {error:.1e} of the peak (bound {bound:g})",
                )
            )
        cases.write_record(record, out / "cases")
        plotting.case_figure(result, record["title"], out / "figures" / "cases" / f"{path.stem}.png")
        for c in record["checks"]:
            checks.append(
                {"area": family, "check": f"{path.stem}: {c['check']}", "status": c["status"], "detail": c["detail"]}
            )
        results[path.stem], where[path.stem] = result, path
        m = result["metrics"]
        best = max(result["monitors"].items(), key=lambda kv: kv[1]["power"], default=(None, None))
        rows.append(
            {
                "layout": path.stem,
                "family": family,
                "cells": int(m["nx"]),
                "steps": int(m["nz"]),
                "power left": m["total_out"],
                "strongest monitor": best[0] or "",
                "its power": best[1]["power"] if best[0] else float("nan"),
                "checks": len(record["checks"]),
                "passed": sum(c["status"] == "PASS" for c in record["checks"]),
            }
        )

    table = pd.DataFrame(rows)
    fam = table.groupby("family", sort=False).agg(
        layouts=("layout", "size"), checks=("checks", "sum"), passed=("passed", "sum")
    )
    gallery = {k: (results[k], results[k]["title"]) for k in cfg["gallery"] if k in results}
    if gallery:
        plotting.overview(gallery, out / "figures" / "overview.png")

    # studies across layouts
    lines, study = [], {}
    conv = studies.step_convergence(where, results)
    if len(conv):
        order = conv.attrs["order"]
        checks.append(
            _check(
                "step size",
                "the error of the output field falls as the square of the step",
                1.7 < order < 2.3,
                f"fitted order {order:.2f} over {len(conv)} step sizes",
            )
        )
        lines += [
            "### Step size (guide with a poor reference index, against the solution that needs no stepping)",
            "",
            f"Fitted order: {order:.2f}.",
            "",
            md_table(conv, 6, index=False),
            "",
        ]
        study["step_convergence"] = {"order": order, "rows": conv.to_dict("records")}
    for prefix, label in (
        ("taper_up_l", "Taper 0.5 to 3 um"),
        ("taper_down_l", "Taper 3 to 0.5 um"),
        ("sbend_off1_l", "S-bend, 1 um offset"),
        ("sbend_off2_l", "S-bend, 2 um offset"),
        ("ybranch_l", None),
    ):
        t = studies.lengths(results, prefix) if label else pd.DataFrame()
        if len(t) >= 3:
            values = t["transmission"].to_numpy()
            checks.append(
                _check(
                    "adiabatic transitions",
                    f"{label}: transmission does not fall as the transition gets longer",
                    bool((values[1:] >= values[:-1] - 2e-4).all()),
                    ", ".join(f"{v:.4f}" for v in values),
                )
            )
            lines += [f"### {label}: transmission against length", "", md_table(t, 5, index=False), ""]
            study[prefix.rstrip("_l")] = t.to_dict("records")
    up, down = studies.lengths(results, "taper_up_l"), studies.lengths(results, "taper_down_l")
    if len(up) and len(down):
        both = up.merge(down, on="length, um", suffixes=(" up", " down"))
        if len(both):
            gap = float((both["transmission up"] - both["transmission down"]).abs().max())
            checks.append(
                _check(
                    "reciprocity",
                    "a taper and its mirror image transmit the same, mode to mode",
                    gap < 1e-8,
                    f"largest difference {gap:.1e} over {len(both)} lengths",
                )
            )
            study["reciprocity"] = gap
    pairs = studies.couplers(where, results)
    if len(pairs):
        off = float(
            (
                (pairs["launch guide empty at, um"] - pairs["coupling length, um"]).abs() / pairs["coupling length, um"]
            ).max()
        )
        checks.append(
            _check(
                "couplers",
                "the launch guide empties at the coupling length predicted from the supermodes",
                off < 0.03,
                f"largest deviation {100 * off:.1f}% over {len(pairs)} gaps",
            )
        )
        lines += ["### Directional couplers", "", md_table(pairs, 4, index=False), ""]
        study["couplers"] = pairs.to_dict("records")
    scans = studies.mmi_scans(results)
    if len(scans) >= 3:
        centre = scans.set_index("length over the imaging length")
        ok = all(centre[col].dropna().idxmax() == 1.0 for col in centre.columns)
        checks.append(
            _check(
                "multimode interference",
                "each 1x2 interferometer is best at the imaging length 3 L_pi / 8",
                ok,
                ", ".join(f"{col}: {centre[col].max():.3f} per output" for col in centre.columns),
            )
        )
        lines += [
            "### 1x2 multimode interferometers: power per output against length",
            "",
            md_table(scans, 4, index=False),
            "",
        ]
        study["mmi"] = json.loads(scans.to_json(orient="records"))
    layouts = {name: reference.read_layout(p) for name, p in where.items() if name.startswith("absorber_")}
    absorb = studies.absorbers(results, layouts)
    if len(absorb):
        lines += [
            "### Absorbing edges: a beam at 15 degrees leaving the window",
            "",
            md_table(absorb, 5, index=False),
            "",
        ]
        study["absorbers"] = absorb.to_dict("records")

    val = pd.DataFrame(checks)
    counts = val["status"].value_counts().to_dict()
    agreement = pd.DataFrame({"largest difference over the library": worst}).rename_axis("quantity")
    report = [
        "# BeamProp report",
        "",
        f"{len(table)} layouts, {int((table['cells'] * table['steps']).sum())} cell-steps, {len(val)} checks: {counts.get('PASS', 0)} PASS, {counts.get('FAIL', 0)} FAIL.",
        "",
        "Every layout is a text file in `cases/`. Its expectations come from an independent propagation or from a closed form, stated in the comments at the top of the file.",
        "Per-layout results are in `reports/cases/`, intensity maps in `reports/figures/cases/`.",
        "",
        "## Families",
        "",
        md_table(fam, 0),
        "",
        "## Agreement with the independent propagation",
        "",
        "Each layout is read and stepped again by `reference.py` (NumPy, banded solver). Powers are fractions of the launched power, lengths in micrometres, the field relative to its peak.",
        "",
        md_table(agreement, 12),
        "",
        "## Studies",
        "",
        *lines,
        "## All layouts",
        "",
        md_table(table.drop(columns=["family"]), 4, index=False),
        "",
    ]
    (out / "report.md").write_text("\n".join(report))
    (out / "validation.md").write_text("# Validation checks\n\n" + md_table(val, index=False) + "\n")
    metrics = {
        "layouts": len(table),
        "cell_steps": int((table["cells"] * table["steps"]).sum()),
        "families": fam.to_dict("index"),
        "largest_differences": worst,
        "studies": study,
        "layouts_table": table.set_index("layout").to_dict("index"),
        "checks": checks,
    }
    (out / "metrics.json").write_text(json.dumps(metrics, indent=1, default=float))
    return metrics
