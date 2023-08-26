import numpy as np
import pytest

from beamprop import engine

pytestmark = pytest.mark.skipif(not engine.available(), reason="C++ solver not built")

GUIDE = "window width=12 length=20\nguide straight x=0 width=0.5 from=0 to=20\nlaunch mode x=0 width=0.5\n"


def write(tmp_path, text):
    path = tmp_path / "layout.bpm"
    path.write_text(text)
    return path


def test_run_returns_arrays(tmp_path):
    r = engine.run(write(tmp_path, "title Test\n" + GUIDE + "monitor out z=20 x=0 width=0.5\nplane end z=20\n"))
    assert r["title"] == "Test"
    assert r["output"].shape == (600,) and r["x"][0] == pytest.approx(-5.99)
    assert r["trace"].shape == (81, 3) and r["trace"][0, 1] == pytest.approx(1.0)
    assert r["map"].shape == (len(r["map_z"]), len(r["map_x"])) and len(r["map_x"]) <= 400
    assert r["monitors"]["out"]["power"] > 0.9999 and r["planes"]["end"]["total"] > 0.9999
    assert abs(np.sum(np.abs(r["output"]) ** 2) * 0.02 - r["metrics"]["total_out"]) < 1e-8


def test_check_reports_pass_and_fail(tmp_path):
    text = GUIDE + "monitor out z=20 x=0 width=0.5\nexpect power_above out 0.99\nexpect power_below out 0.5\n"
    r = engine.run(write(tmp_path, text), "check")
    assert [c["status"] for c in r["checks"]] == ["PASS", "FAIL"]
    assert "output" not in r


def test_bad_file_raises_with_the_line(tmp_path):
    with pytest.raises(RuntimeError, match="line 2"):
        engine.run(write(tmp_path, "wavelength 1.55\nnonsense 1\n"))
    with pytest.raises(RuntimeError, match="whole number of steps"):
        engine.run(write(tmp_path, "window width=12.01 length=20\n"))
    with pytest.raises(RuntimeError, match="not guided"):
        engine.run(write(tmp_path, "window width=12 length=20\nlaunch mode x=0 width=0.3 order=1\n"))
    with pytest.raises(RuntimeError, match="cannot read"):
        engine.run(tmp_path / "missing.bpm")
