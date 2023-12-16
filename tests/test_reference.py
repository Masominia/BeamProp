import numpy as np
import pytest

from beamprop import engine, reference
from beamprop.compare import compare
from beamprop.engine import ROOT


def layout(tmp_path, text):
    path = tmp_path / "l.bpm"
    path.write_text(text)
    return reference.read_layout(path)


def test_reader_understands_every_statement(tmp_path):
    lay = layout(
        tmp_path,
        "# note\ntitle A B\nwavelength 1.31\nindex core=3.0 clad=1.45\nreference 2.7\ngrid dx=0.025 dz=0.5\nwindow width=16 length=120\n"
        "absorber width=3 strength=0.2\nguide straight x=1 width=0.5 from=0 to=10\nguide taper x=0 w0=0.5 w1=2 from=10 to=30 # widen\n"
        "guide sbend x0=0 x1=3 width=0.5 from=30 to=90\nlaunch gaussian x=0.1 radius=1.5 tilt=2\nmonitor up z=120 x=3 width=0.5 order=1\n"
        "plane end z=120\nexpect power up 0.4 0.1\n",
    )
    assert (lay["title"], lay["wavelength"], lay["core"], lay["clad"], lay["reference"]) == (
        "A B",
        1.31,
        3.0,
        1.45,
        2.7,
    )
    assert (lay["dx"], lay["dz"], lay["width"], lay["length"]) == (0.025, 0.5, 16.0, 120.0)
    assert (lay["absorber_width"], lay["absorber_strength"]) == (3.0, 0.2)
    assert [g["shape"] for g in lay["guides"]] == ["straight", "taper", "sbend"]
    assert lay["guides"][0]["x0"] == 1.0 and lay["guides"][1]["w1"] == 2.0 and lay["guides"][2]["x1"] == 3.0
    assert lay["launch"] == {"kind": "gaussian", "x": 0.1, "radius": 1.5, "tilt": 2.0}
    assert lay["monitors"][0]["name"] == "up" and lay["monitors"][0]["order"] == 1.0
    assert lay["planes"] == [{"name": "end", "z": 120.0}]


def test_slab_mode_satisfies_its_equation():
    for order in range(3):
        n, kappa, gamma = reference.slab_mode(1.55, 2.0, 2.848, 1.444, order)
        assert abs(kappa * 2.0 - 2 * np.arctan(gamma / kappa) - order * np.pi) < 1e-10
        assert 1.444 < n < 2.848


def test_mode_fields_are_orthonormal(tmp_path):
    lay = layout(tmp_path, "window width=16 length=10\n")
    modes = [reference.mode_field(lay, 0.0, 2.0, m) for m in range(3)]
    gram = np.array([[np.sum(a * b) * lay["dx"] for b in modes] for a in modes])
    assert np.allclose(gram, np.eye(3), atol=2e-4)


def test_stepping_conserves_power_without_absorber(tmp_path):
    lay = layout(
        tmp_path,
        "grid dx=0.05 dz=0.5\nwindow width=30 length=40\nabsorber width=0 strength=0\nlaunch gaussian x=0 radius=2 tilt=6\nplane end z=40\n",
    )
    r = reference.propagate(lay)
    assert max(abs(t - 1) for t in r["total"]) < 1e-11


def test_modal_solution_matches_fine_stepping(tmp_path):
    text = "grid dx=0.05 dz={dz}\nreference 2.5\nwindow width=10 length=10\nguide straight x=0 width=0.5 from=0 to=10\nlaunch mode x=0 width=0.5\n"
    errors = []
    for dz in (0.5, 0.25, 0.125):
        lay = layout(tmp_path, text.format(dz=dz))
        errors.append(np.max(np.abs(reference.propagate(lay)["output"] - reference.modal(lay, 10.0))))
    assert errors[0] / errors[1] == pytest.approx(4, rel=0.15) and errors[1] / errors[2] == pytest.approx(4, rel=0.15)
    assert reference.invariant(lay)
    assert not reference.invariant(
        layout(tmp_path, "window width=10 length=10\nguide taper x=0 w0=0.5 w1=1 from=0 to=10\n")
    )


def test_index_formulas():
    assert reference.paraxial_index(2.6, 2.6) == 2.6
    assert reference.paraxial_index(2.6, 2.0) > 2.6  # a poor reference overestimates the phase
    assert reference.stepped_index(2.6, 2.0, 1.55, 1e-6) == pytest.approx(reference.paraxial_index(2.6, 2.0), abs=1e-9)
    assert reference.stepped_index(2.6, 2.0, 1.55, 0.5) < reference.paraxial_index(2.6, 2.0)
    assert reference.gaussian_radius(1.55, 1.444, 2.0, 0.0) == 2.0
    z_r = np.pi * 1.444 * 4 / 1.55
    assert reference.gaussian_radius(1.55, 1.444, 2.0, z_r) == pytest.approx(2 * np.sqrt(2))


def test_grid_mode_is_close_to_the_analytic_one(tmp_path):
    lay = layout(tmp_path, "window width=12 length=10\nguide straight x=0 width=0.5 from=0 to=10\n")
    analytic = reference.slab_mode(1.55, 0.5, 2.848, 1.444)[0]
    assert abs(reference.discrete_mode_index(lay)[0] - analytic) < 2e-3


@pytest.mark.skipif(not engine.available(), reason="C++ solver not built")
@pytest.mark.parametrize(
    "name", ["free_tilt05", "coupler_gap200", "mmi_1x2_w6_l100", "taper_up_l20", "sbend_off2_l40", "absorber_s030"]
)
def test_solver_and_reference_agree(name):
    path = ROOT / "cases" / f"{name}.bpm"
    cmp = compare(path, engine.run(path))
    assert not cmp["outside"], cmp["outside"]
    assert cmp["differences"]["field"] < 1e-8
