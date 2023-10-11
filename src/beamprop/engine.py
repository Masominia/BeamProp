"""Python side of the C++ solver: runs the binary on a layout file and parses its output."""

from __future__ import annotations

import subprocess
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
BINARY = ROOT / "cpp" / "build" / "beamprop"


def available() -> bool:
    return BINARY.exists()


def run(layout: Path | str, command: str = "run") -> dict:
    """Simulate a layout. Returns the reported quantities, monitors, planes, checks and, for `run`, the arrays.

    Raises RuntimeError with the solver's message if the file is invalid.
    """
    proc = subprocess.run([str(BINARY), command, str(layout)], capture_output=True, text=True)
    if proc.returncode == 2:
        raise RuntimeError(proc.stderr.strip())
    res: dict = {"metrics": {}, "monitors": {}, "planes": {}, "checks": [], "title": ""}
    trace, out, rows = [], [], []
    for line in proc.stdout.splitlines():
        key, _, rest = line.partition(" ")
        if key == "trace":
            trace.append(rest.split())
        elif key == "out":
            out.append(rest.split())
        elif key == "map":
            rows.append(rest.split())
        elif key == "mapx":
            res["map_x"] = np.array(rest.split(), dtype=float)
        elif key == "monitor":
            name, z, power, phase = rest.split()
            res["monitors"][name] = {"z": float(z), "power": float(power), "phase": float(phase)}
        elif key == "plane":
            name, *values = rest.split()
            res["planes"][name] = dict(
                zip(("z", "total", "centroid", "radius", "peak_x"), map(float, values), strict=True)
            )
        elif key == "check":
            status, _, tail = rest.partition(" ")
            name, _, detail = tail.partition(" :: ")
            res["checks"].append({"check": name, "status": status, "detail": detail})
        elif key == "title":
            res["title"] = rest
        else:
            res["metrics"][key] = float(rest)
    if out:
        res["trace"] = np.array(trace, dtype=float)  # columns: z, total power, power in the launch profile
        table = np.array(out, dtype=float)
        res["x"], res["output"] = table[:, 0], table[:, 1] + 1j * table[:, 2]
        grid = np.array(rows, dtype=float)
        res["map_z"], res["map"] = grid[:, 0], grid[:, 1:]
    return res
