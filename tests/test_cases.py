import json

import pytest

from beamprop import cases, engine
from beamprop.engine import ROOT

ALL = cases.discover(ROOT / "cases")


def test_library_is_present_and_described():
    assert len(ALL) >= 75
    for path in ALL:
        assert len(cases.notes(path)) >= 2, f"{path.name} has no description"
        assert "expect " in path.read_text(), f"{path.name} checks nothing"


def test_families():
    fam = {"tapers": ["taper_"], "numerics": ["step_", "grid_"]}
    assert cases.family_of("taper_up_l20", fam) == "tapers"
    assert cases.family_of("grid_dx250", fam) == "numerics"
    assert cases.family_of("ybranch_l40", fam) == "other"


@pytest.mark.skipif(not engine.available(), reason="C++ solver not built")
@pytest.mark.parametrize("path", ALL, ids=lambda p: p.stem)
def test_every_layout_meets_its_expectations(path):
    result = engine.run(path, "check")
    assert result["checks"], "no expectations evaluated"
    failed = [c for c in result["checks"] if c["status"] != "PASS"]
    assert not failed, failed


@pytest.mark.skipif(not engine.available(), reason="C++ solver not built")
def test_record_round_trip(tmp_path):
    record, result = cases.run_case(ROOT / "cases" / "ybranch_l40.bpm")
    back = json.loads(cases.write_record(record, tmp_path).read_text())
    assert back["case"] == "ybranch_l40" and back["metrics"]["total_out"] > 0.99
    assert "map" not in back and result["map"].shape[0] == len(result["map_z"])
