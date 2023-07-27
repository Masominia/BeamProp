"""Static figures for the report (matplotlib, PNG for the README)."""

from __future__ import annotations

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt  # noqa: E402
import numpy as np  # noqa: E402

# Validated categorical order (fixed, never cycled) + recessive ink.
SERIES = ["#2a78d6", "#eb6834", "#1baf7a", "#eda100", "#e87ba4", "#008300", "#6250d6", "#e34948"]
SURFACE, INK, INK2, GRID = "#fcfcfb", "#0b0b0b", "#52514e", "#e4e3df"
NEUTRAL = "#8a8985"
CRITICAL = "#c4271a"

plt.rcParams.update(
    {
        "figure.facecolor": SURFACE,
        "axes.facecolor": SURFACE,
        "savefig.facecolor": SURFACE,
        "axes.edgecolor": GRID,
        "axes.labelcolor": INK2,
        "xtick.color": INK2,
        "ytick.color": INK2,
        "text.color": INK,
        "axes.grid": True,
        "grid.color": GRID,
        "grid.linewidth": 0.6,
        "axes.spines.top": False,
        "axes.spines.right": False,
        "font.size": 9,
        "axes.titlesize": 10,
        "axes.titleweight": "bold",
        "legend.frameon": False,
        "lines.linewidth": 1.6,
        "figure.dpi": 150,
        "axes.axisbelow": True,
    }
)


def _save(fig, path):
    fig.tight_layout()
    fig.savefig(path, bbox_inches="tight")
    plt.close(fig)


def _map(ax, result):
    z, x, intensity = result["map_z"], result["map_x"], result["map"]
    amplitude = np.sqrt(intensity / max(intensity.max(), 1e-30)).T
    ax.imshow(
        amplitude,
        origin="lower",
        extent=(z[0], z[-1], x[0], x[-1]),
        cmap="Blues",
        aspect="auto",
        interpolation="bilinear",
        vmin=0,
        vmax=1,
    )
    # show the part of the window the light actually visits
    reach = np.abs(x)[amplitude.max(axis=1) > 0.03]
    half = min(x[-1], max(1.5, 1.3 * reach.max())) if len(reach) else x[-1]
    ax.set_ylim(-half, half)
    ax.grid(False)
    ax.set(xlabel="z, um", ylabel="x, um")


def case_figure(result, title, path):
    fig, (left, right) = plt.subplots(1, 2, figsize=(8.6, 3.2), gridspec_kw={"width_ratios": [1.5, 1]})
    _map(left, result)
    left.set_title("field amplitude", fontsize=8.5)
    trace = result["trace"]
    right.plot(trace[:, 0], trace[:, 1], color=SERIES[0], label="in the window")
    right.plot(trace[:, 0], trace[:, 2], color=SERIES[1], label="in the launch profile")
    right.set_xlim(trace[0, 0], trace[-1, 0])
    right.set_ylim(-0.03, 1.08)
    right.set(xlabel="z, um", ylabel="power over launched power")
    right.legend(loc="lower left", fontsize=7.5)
    fig.suptitle(title, fontsize=9, fontweight="bold")
    fig.tight_layout()
    fig.savefig(path, dpi=105)
    plt.close(fig)


def overview(gallery, path):
    names = list(gallery)
    fig, axes = plt.subplots(2, 3, figsize=(13, 6.6))
    for ax, name in zip(axes.ravel(), names, strict=False):
        result, title = gallery[name]
        _map(ax, result)
        ax.set_title(title if len(title) < 58 else title[:55] + "...", fontsize=8.5)
    for ax in axes.ravel()[len(names) :]:
        ax.axis("off")
    _save(fig, path)
