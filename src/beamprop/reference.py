"""An independent beam propagation calculation in NumPy and SciPy, and an exact modal solution.

It shares no code with the C++ solver: its own layout reader, permittivity profile, slab modes by root finding and
Crank-Nicolson stepping with a banded solver. For layouts that do not change along z, `modal` gives the solution
of the same transverse grid with no stepping at all, by diagonalising the transverse operator.
"""

from __future__ import annotations

from pathlib import Path

import numpy as np
from scipy.linalg import solve_banded
from scipy.optimize import brentq


def read_layout(path: Path | str) -> dict:
    """Reads a layout file into a dictionary, ignoring its expectations."""
    lay = {
        "title": "",
        "wavelength": 1.55,
        "core": 2.848,
        "clad": 1.444,
        "reference": 0.0,
        "dx": 0.02,
        "dz": 0.25,
        "width": 20.0,
        "length": 100.0,
        "absorber_width": 2.0,
        "absorber_strength": 0.3,
        "guides": [],
        "launch": {"kind": "mode", "x": 0.0, "width": 0.5, "order": 0},
        "monitors": [],
        "planes": [],
    }
    for raw in Path(path).read_text().splitlines():
        w = raw.split("#")[0].split()
        if not w or w[0] == "expect":
            continue
        first = 2 if w[0] in ("guide", "launch", "monitor", "plane") else 1
        kv = {k: float(v) for k, v in (x.split("=") for x in w[first:] if "=" in x)}
        if w[0] == "title":
            lay["title"] = " ".join(w[1:])
        elif w[0] in ("wavelength", "reference"):
            lay[w[0]] = float(w[1])
        elif w[0] in ("index", "grid", "window"):
            lay.update(kv)
        elif w[0] == "absorber":
            lay.update({f"absorber_{k}": v for k, v in kv.items()})
        elif w[0] == "guide":
            x0, x1 = (kv.get("x", 0.0),) * 2 if w[1] in ("straight", "taper") else (kv["x0"], kv["x1"])
            w0, w1 = (kv["w0"], kv["w1"]) if w[1] == "taper" else (kv["width"],) * 2
            lay["guides"].append(
                {"shape": w[1], "x0": x0, "x1": x1, "w0": w0, "w1": w1, "from": kv["from"], "to": kv["to"]}
            )
        elif w[0] == "launch":
            lay["launch"] = {"kind": w[1], "x": kv.get("x", 0.0), **{k: v for k, v in kv.items() if k != "x"}}
        elif w[0] == "monitor":
            lay["monitors"].append({"name": w[1], "x": 0.0, "order": 0, **kv})
        elif w[0] == "plane":
            lay["planes"].append({"name": w[1], **kv})
    return lay


def grid(lay: dict) -> np.ndarray:
    n = round(lay["width"] / lay["dx"])
    return -0.5 * lay["width"] + (np.arange(n) + 0.5) * lay["dx"]


def slab_mode(lam: float, width: float, n_core: float, n_clad: float, order: int = 0) -> tuple[float, float, float]:
    """Effective index, core wavenumber and cladding decay rate of a TE mode of a symmetric slab."""
    k = 2 * np.pi / lam

    def mismatch(n):
        kappa, gamma = k * np.sqrt(n_core**2 - n**2), k * np.sqrt(n**2 - n_clad**2)
        return kappa * width - 2 * np.arctan2(gamma, kappa) - order * np.pi

    n = brentq(mismatch, n_clad + 1e-13, n_core - 1e-13, xtol=1e-15)
    return n, k * np.sqrt(n_core**2 - n**2), k * np.sqrt(n**2 - n_clad**2)


def mode_field(lay: dict, x0: float, width: float, order: int = 0) -> np.ndarray:
    _, kappa, gamma = slab_mode(lay["wavelength"], width, lay["core"], lay["clad"], order)
    x = grid(lay) - x0
    inside = np.cos(kappa * x) if order % 2 == 0 else np.sin(kappa * x)  # cosine for even orders, sine for odd
    edge = np.cos(kappa * width / 2) if order % 2 == 0 else np.sin(kappa * width / 2)
    outside = edge * np.exp(-gamma * (np.abs(x) - width / 2)) * (np.sign(x) if order % 2 else 1.0)
    f = np.where(np.abs(x) <= width / 2, inside, outside)
    return f / np.sqrt(np.sum(f**2) * lay["dx"])


def launch_field(lay: dict) -> np.ndarray:
    la = lay["launch"]
    if la["kind"] == "mode":
        return mode_field(lay, la["x"], la["width"], int(la.get("order", 0))).astype(complex)
    x = grid(lay)
    kx = 2 * np.pi / lay["wavelength"] * lay["clad"] * np.sin(np.radians(la.get("tilt", 0.0)))
    f = np.exp(-(((x - la["x"]) / la["radius"]) ** 2)) * np.exp(1j * kx * x)
    return f / np.sqrt(np.sum(np.abs(f) ** 2) * lay["dx"])


def reference_index(lay: dict) -> float:
    if lay["reference"] > 0:
        return lay["reference"]
    la = lay["launch"]
    if la["kind"] == "mode":
        return slab_mode(lay["wavelength"], la["width"], lay["core"], lay["clad"], int(la.get("order", 0)))[0]
    return lay["clad"]


def permittivity(lay: dict, z: float) -> np.ndarray:
    x = grid(lay)
    lo, hi = x - 0.5 * lay["dx"], x + 0.5 * lay["dx"]
    fill = np.zeros_like(x)
    for g in lay["guides"]:
        if z < g["from"] - 1e-9 or z > g["to"] + 1e-9:
            continue
        t = min(max((z - g["from"]) / (g["to"] - g["from"]), 0.0), 1.0)
        centre = g["x0"] + (g["x1"] - g["x0"]) * (0.5 * (1 - np.cos(np.pi * t)) if g["shape"] == "sbend" else t)
        half = 0.5 * (g["w0"] + (g["w1"] - g["w0"]) * t)
        fill = np.minimum(
            1.0, fill + np.clip(np.minimum(hi, centre + half) - np.maximum(lo, centre - half), 0, None) / lay["dx"]
        )
    eps = (lay["clad"] ** 2 + fill * (lay["core"] ** 2 - lay["clad"] ** 2)).astype(complex)
    if lay["absorber_width"] > 0:
        depth = lay["absorber_width"] - (0.5 * lay["width"] - np.abs(x))
        eps += 1j * lay["absorber_strength"] * np.where(depth > 0, depth / lay["absorber_width"], 0.0) ** 2
    return eps


def _measure(lay: dict, u: np.ndarray, launched: float) -> dict:
    x, p = grid(lay), np.abs(u) ** 2
    centroid = float((p * x).sum() / p.sum())
    return {
        "total": float(p.sum() * lay["dx"] / launched),
        "centroid": centroid,
        "radius": float(2 * np.sqrt(max((p * x * x).sum() / p.sum() - centroid**2, 0.0))),
    }


def propagate(lay: dict) -> dict:
    """Steps the field through the layout. Returns monitors, planes, traces and the output field."""
    k, n0 = 2 * np.pi / lay["wavelength"], reference_index(lay)
    dx, dz = lay["dx"], lay["dz"]
    nz = round(lay["length"] / dz)
    start = launch_field(lay)
    u = start.copy()
    launched = float(np.sum(np.abs(u) ** 2) * dx)
    a = 1j * dz / (4 * k * n0)
    at_step = lambda z: round(z / dz)  # noqa: E731
    monitors = {
        m["name"]: (at_step(m["z"]), mode_field(lay, m["x"], m["width"], int(m["order"]))) for m in lay["monitors"]
    }
    planes = {p["name"]: at_step(p["z"]) for p in lay["planes"]}
    out = {"monitors": {}, "planes": {}, "total": [1.0], "n0": n0}
    phase, tracked, previous = 0.0, 0.0, np.vdot(start, u) * dx
    threshold, tracking = 1e-6 * abs(previous), True
    banded = np.empty((3, len(u)), dtype=complex)
    for s in range(nz + 1):
        if s > 0:
            h = -2 / dx**2 + k * k * (permittivity(lay, (s - 0.5) * dz) - n0**2)
            neighbours = np.zeros_like(u)
            neighbours[1:] += u[:-1]
            neighbours[:-1] += u[1:]
            rhs = u + a * (h * u + neighbours / dx**2)
            banded[0], banded[1], banded[2] = -a / dx**2, 1 - a * h, -a / dx**2
            u = solve_banded((1, 1), banded, rhs)
            c = np.vdot(start, u) * dx
            if tracking and abs(c) > threshold:
                phase += np.angle(c * np.conj(previous))
                tracked = s * dz
            else:
                tracking = False
            previous = c
            out["total"].append(float(np.sum(np.abs(u) ** 2) * dx / launched))
        for name, (step, mode) in monitors.items():
            if step == s:
                out["monitors"][name] = float(abs(np.vdot(mode, u) * dx) ** 2 / launched)
        for name, step in planes.items():
            if step == s:
                out["planes"][name] = _measure(lay, u, launched)
    out["n_track"] = n0 + phase / (k * tracked) if tracked > 0 else n0
    out["output"] = u
    out["in_launch_out"] = float(abs(np.vdot(start, u) * dx) ** 2 / launched**2)
    return out


def invariant(lay: dict) -> bool:
    """True if every guide is straight and spans the whole length."""
    return all(
        g["shape"] == "straight" and g["from"] <= 1e-9 and g["to"] >= lay["length"] - 1e-9 for g in lay["guides"]
    )


def modal(lay: dict, z: float) -> np.ndarray:
    """Field at z for a layout that does not change along z, with no stepping.

    The transverse operator is diagonalised once; each of its modes advances by its own phase. This is the exact
    solution of the paraxial equation on the transverse grid, so it differs from the stepped field only by the
    error of the Crank-Nicolson step.
    """
    k, n0, dx = 2 * np.pi / lay["wavelength"], reference_index(lay), lay["dx"]
    n = len(grid(lay))
    h = np.diag(-2 / dx**2 + k * k * (permittivity(lay, 0.5 * lay["length"]) - n0**2))
    h += np.diag(np.full(n - 1, 1 / dx**2), 1) + np.diag(np.full(n - 1, 1 / dx**2), -1)
    values, vectors = np.linalg.eig(h)
    weights = np.linalg.solve(vectors, launch_field(lay))
    return vectors @ (weights * np.exp(1j * values * z / (2 * k * n0)))


def paraxial_index(n_mode: float, n0: float) -> float:
    """Index a mode of true index n_mode shows in the paraxial equation with reference index n0."""
    return n0 + (n_mode**2 - n0**2) / (2 * n0)


def stepped_index(n_mode: float, n0: float, lam: float, dz: float) -> float:
    """Index a mode shows after Crank-Nicolson stepping: the phase per step t becomes 2 atan(t / 2)."""
    k = 2 * np.pi / lam
    return n0 + 2 * np.arctan(dz * k * (n_mode**2 - n0**2) / (4 * n0)) / (k * dz)


def gaussian_radius(lam: float, n: float, w0: float, z: float) -> float:
    """1/e^2 intensity radius of a Gaussian beam of waist w0 after a distance z in a medium of index n."""
    return w0 * np.sqrt(1 + (z * lam / (np.pi * n * w0**2)) ** 2)


def discrete_mode_index(lay: dict, z: float = 0.0, count: int = 1) -> np.ndarray:
    """Highest effective indices of the transverse grid at z (no absorber): the modes the grid itself supports."""
    k, dx = 2 * np.pi / lay["wavelength"], lay["dx"]
    eps = permittivity(dict(lay, absorber_width=0.0), z).real
    h = (
        np.diag(-2 / dx**2 + k * k * eps)
        + np.diag(np.full(len(eps) - 1, 1 / dx**2), 1)
        + np.diag(np.full(len(eps) - 1, 1 / dx**2), -1)
    )
    return np.sqrt(np.linalg.eigvalsh(h)[::-1][:count]) / k
