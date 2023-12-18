"""Simulate one layout file and print what the solver found.

python scripts/simulate.py cases/mmi_1x2_w6_l100.bpm
"""

import sys

from beamprop import engine

if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit(__doc__)
    r = engine.run(sys.argv[1], "check")
    m = r["metrics"]
    print(r["title"])
    print(
        f"  {int(m['nx'])} cells of {1e3 * m['dx']:g} nm, {int(m['nz'])} steps of {m['dz']:g} um, reference index {m['reference']:.4f}"
    )
    print(
        f"  power left in the window {m['total_out']:.5f}, in the launch profile {m['in_launch_out']:.5f}, index from the phase {m['n_track']:.5f}"
    )
    for name, mon in r["monitors"].items():
        print(f"  monitor {name:<12} z = {mon['z']:8.2f} um   power {mon['power']:.5f}")
    for name, p in r["planes"].items():
        print(
            f"  plane   {name:<12} z = {p['z']:8.2f} um   total {p['total']:.5f}, centroid {p['centroid']:+.3f} um, radius {p['radius']:.3f} um"
        )
    for c in r["checks"]:
        print(f"  {c['status']}  {c['check']}  ({c['detail']})")
