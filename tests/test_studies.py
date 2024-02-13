import numpy as np

from beamprop import studies


def result(power, monitor="out"):
    return {"monitors": {monitor: {"power": power}}}


def test_lengths_collects_and_sorts_a_family():
    results = {
        "taper_up_l40": result(0.99),
        "taper_up_l05": result(0.9),
        "taper_down_l40": result(0.98),
        "taper_up_long": result(0.1),
    }
    t = studies.lengths(results, "taper_up_l")
    assert list(t["length, um"]) == [5, 40] and list(t["transmission"]) == [0.9, 0.99]
    assert studies.lengths(results, "sbend_").empty


def test_mmi_scan_table():
    results = {
        "mmi_1x2_w6_l090": result(0.3, "upper"),
        "mmi_1x2_w6_l100": result(0.49, "upper"),
        "mmi_1x2_w4_l100": result(0.48, "upper"),
        "mmi_2x2_l100": result(0.4, "bar"),
    }
    t = studies.mmi_scans(results).set_index("length over the imaging length")
    assert t.loc[1.0, "6 um wide"] == 0.49 and t.loc[1.0, "4 um wide"] == 0.48
    assert np.isnan(t.loc[0.9, "4 um wide"])
    assert studies.mmi_scans({}).empty


def test_absorber_table():
    results = {
        "absorber_a": {"metrics": {"total_out": 0.3}},
        "absorber_b": {"metrics": {"total_out": 0.001}},
        "free_w20": {"metrics": {"total_out": 1.0}},
    }
    layouts = {
        "absorber_a": {"absorber_width": 5.0, "absorber_strength": 0.03},
        "absorber_b": {"absorber_width": 5.0, "absorber_strength": 0.3},
    }
    t = studies.absorbers(results, layouts)
    assert list(t["power left in the window"]) == [0.3, 0.001]
