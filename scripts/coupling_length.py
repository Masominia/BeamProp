"""Coupling length of two parallel guides from the supermodes of the transverse grid.

python scripts/coupling_length.py <guide width um> <gap um> [core index] [cladding index]
"""

import sys

from beamprop import reference

if __name__ == "__main__":
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    width, gap = float(sys.argv[1]), float(sys.argv[2])
    core = float(sys.argv[3]) if len(sys.argv) > 3 else 2.848
    clad = float(sys.argv[4]) if len(sys.argv) > 4 else 1.444
    centre = 0.5 * (gap + width)
    guides = [
        {"shape": "straight", "x0": s * centre, "x1": s * centre, "w0": width, "w1": width, "from": 0.0, "to": 1.0}
        for s in (-1, 1)
    ]
    lay = {
        "wavelength": 1.55,
        "core": core,
        "clad": clad,
        "dx": 0.02,
        "width": 14.0,
        "absorber_width": 0.0,
        "absorber_strength": 0.0,
        "guides": guides,
    }
    n_even, n_odd = reference.discrete_mode_index(lay, 0.5, 2)
    print(f"supermodes {n_even:.5f} and {n_odd:.5f}, coupling length {1.55 / (2 * (n_even - n_odd)):.2f} um")
