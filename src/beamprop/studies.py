"""Results drawn from several layouts of the library at once."""

from __future__ import annotations

from pathlib import Path

import numpy as np
import pandas as pd

from . import reference


def modal_error(path: Path, result: dict) -> float:
    """Largest difference between the stepped output field and the solution that needs no stepping, over its peak."""
    lay = reference.read_layout(path)
    exact = reference.modal(lay, lay["length"])
    return float(np.max(np.abs(result["output"] - exact)) / np.max(np.abs(exact)))


def step_convergence(paths: dict[str, Path], results: dict[str, dict]) -> pd.DataFrame:
    """Error of the output field against step size for the step_dz family, with the fitted order."""
    names = sorted(n for n in results if n.startswith("step_dz"))
    if len(names) < 3:
        return pd.DataFrame()
    lay = reference.read_layout(paths[names[0]])
    exact = reference.modal(lay, lay["length"])  # the same for every member: only the step differs
    rows = []
    for name in names:
        error = float(np.max(np.abs(results[name]["output"] - exact)) / np.max(np.abs(exact)))
        rows.append({"step, um": results[name]["metrics"]["dz"], "error of the output field": error})
    table = pd.DataFrame(rows).sort_values("step, um").reset_index(drop=True)
    table.attrs["order"] = float(
        np.polyfit(np.log(table["step, um"]), np.log(table["error of the output field"]), 1)[0]
    )
    return table


def lengths(results: dict[str, dict], prefix: str, monitor: str = "out") -> pd.DataFrame:
    """Transmission against length for families named <prefix><length>."""
    rows = []
    for name, r in results.items():
        if name.startswith(prefix) and name.removeprefix(prefix).isdigit():
            rows.append({"length, um": int(name.removeprefix(prefix)), "transmission": r["monitors"][monitor]["power"]})
    return pd.DataFrame(rows).sort_values("length, um").reset_index(drop=True) if rows else pd.DataFrame()


def couplers(paths: dict[str, Path], results: dict[str, dict]) -> pd.DataFrame:
    """Coupling length from the supermodes of the grid, beside the length at which the launch guide empties."""
    rows = []
    for name in sorted(n for n in results if n.startswith("coupler_gap")):
        lay = reference.read_layout(paths[name])
        n_even, n_odd = reference.discrete_mode_index(lay, 0.0, 2)
        n0, lam, dz = results[name]["metrics"]["reference"], lay["wavelength"], lay["dz"]
        predicted = lam / (
            2 * (reference.stepped_index(n_even, n0, lam, dz) - reference.stepped_index(n_odd, n0, lam, dz))
        )
        trace = results[name]["trace"]
        first = trace[trace[:, 0] <= 1.5 * predicted]
        observed = float(first[np.argmin(first[:, 2]), 0])
        rows.append(
            {
                "gap, nm": int(name.removeprefix("coupler_gap")),
                "n_even - n_odd": n_even - n_odd,
                "coupling length, um": predicted,
                "launch guide empty at, um": observed,
            }
        )
    return pd.DataFrame(rows).sort_values("gap, nm").reset_index(drop=True) if rows else pd.DataFrame()


def mmi_scans(results: dict[str, dict]) -> pd.DataFrame:
    """Power per output of the 1x2 interferometers against length, one column per body width."""
    rows = {}
    for name, r in results.items():
        if name.startswith("mmi_1x2_w"):
            width, scale = name.removeprefix("mmi_1x2_w").split("_l")
            rows.setdefault(int(scale) / 100, {})[f"{width} um wide"] = r["monitors"]["upper"]["power"]
    if not rows:
        return pd.DataFrame()
    return pd.DataFrame(rows).T.sort_index().rename_axis("length over the imaging length").reset_index()


def absorbers(results: dict[str, dict], layouts: dict[str, dict]) -> pd.DataFrame:
    rows = []
    for name, r in results.items():
        if name.startswith("absorber_"):
            lay = layouts[name]
            rows.append(
                {
                    "absorber width, um": lay["absorber_width"],
                    "strength": lay["absorber_strength"],
                    "power left in the window": r["metrics"]["total_out"],
                }
            )
    return (
        pd.DataFrame(rows).sort_values(["absorber width, um", "strength"]).reset_index(drop=True)
        if rows
        else pd.DataFrame()
    )
