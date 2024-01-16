import json

import pytest

from beamprop import engine
from beamprop.pipeline import run


@pytest.mark.skipif(not engine.available(), reason="C++ solver not built")
def test_fast_pipeline(tmp_path):
    m = run(out=tmp_path, fast=True)
    assert not [c for c in m["checks"] if c["status"] == "FAIL"]
    assert m["layouts"] >= 30 and m["largest_differences"]["field"] < 1e-7
    assert 1.7 < m["studies"]["step_convergence"]["order"] < 2.3 and m["studies"]["reciprocity"] < 1e-8
    assert (tmp_path / "report.md").exists() and (tmp_path / "figures" / "overview.png").exists()
    records = list((tmp_path / "cases").glob("*.json"))
    assert len(records) == m["layouts"] == len(list((tmp_path / "figures" / "cases").glob("*.png")))
    assert "field" in json.loads(records[0].read_text())["against_reference"]
