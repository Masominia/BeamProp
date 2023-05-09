"""Compares what the solver reports with the independent NumPy propagation."""

from __future__ import annotations

from pathlib import Path

import numpy as np

from . import reference

TOLERANCES = {"power": 1e-8, "total": 1e-8, "centroid": 1e-6, "radius": 1e-6, "n_track": 1e-9, "field": 1e-7}


def compare(path: Path | str, result: dict) -> dict:
    """Propagates one layout again. Returns the quantities out of tolerance and the largest differences."""
    ref = reference.propagate(reference.read_layout(path))
    diff = {"power": 0.0, "total": 0.0, "centroid": 0.0, "radius": 0.0}
    for name, power in ref["monitors"].items():
        diff["power"] = max(diff["power"], abs(result["monitors"][name]["power"] - power))
    for name, plane in ref["planes"].items():
        for key in ("total", "centroid", "radius"):
            diff[key] = max(diff[key], abs(result["planes"][name][key] - plane[key]))
    diff["total"] = max(diff["total"], abs(result["metrics"]["total_out"] - ref["total"][-1]))
    diff["n_track"] = abs(result["metrics"]["n_track"] - ref["n_track"])
    diff["field"] = float(np.max(np.abs(result["output"] - ref["output"])) / np.max(np.abs(ref["output"])))
    outside = [f"{name} differs by {value:.2e}" for name, value in diff.items() if value > TOLERANCES[name]]
    return {"outside": outside, "differences": {k: float(v) for k, v in diff.items()}}
