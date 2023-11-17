"""Draw the field of one layout.

python scripts/plot_layout.py cases/ybranch_l40.bpm field.png
"""

import sys

from beamprop import engine, plotting

if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise SystemExit(__doc__)
    result = engine.run(sys.argv[1])
    plotting.case_figure(result, result["title"], sys.argv[2])
    print(f"wrote {sys.argv[2]}")
