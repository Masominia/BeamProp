#include "beamprop/parser.hpp"
#include "check.hpp"

void test_parser(Suite& suite) {
    using namespace bp;
    const Layout d = parse_layout_text("");
    CHECK_NEAR(d.wavelength, 1.55, 1e-12);
    CHECK(d.segments.empty() && d.monitors.empty() && !d.launch.gaussian);

    const Layout l = parse_layout_text(
        "# note\ntitle My splitter\nwavelength 1.31\nindex core=3.0 clad=1.45\nreference 2.7\ngrid dx=0.025 dz=0.5\nwindow width=16 length=120\nabsorber width=3 strength=0.2\n"
        "guide straight x=0 width=0.5 from=0 to=10\nguide taper x=0 w0=0.5 w1=2 from=10 to=30  # widen\nguide sbend x0=0 x1=3 width=0.5 from=30 to=90\nguide line x0=0 x1=-3 width=0.6 from=30 to=90\n"
        "launch gaussian x=0.1 radius=1.5 tilt=2\nmonitor up z=120 x=3 width=0.5 order=1\nplane end z=120\nexpect power up 0.4 0.1\n");
    CHECK(l.title == "My splitter");
    CHECK_NEAR(l.wavelength, 1.31, 1e-12);
    CHECK_NEAR(l.n_core, 3.0, 1e-12);
    CHECK_NEAR(l.n_clad, 1.45, 1e-12);
    CHECK_NEAR(l.reference, 2.7, 1e-12);
    CHECK_NEAR(l.dz, 0.5, 1e-12);
    CHECK_NEAR(l.length, 120.0, 1e-12);
    CHECK_NEAR(l.absorber_strength, 0.2, 1e-12);
    CHECK(l.segments.size() == 4);
    CHECK(l.segments[1].shape == Shape::Taper && l.segments[2].shape == Shape::SBend && l.segments[3].shape == Shape::Line);
    CHECK_NEAR(l.segments[1].w1, 2.0, 1e-12);
    CHECK_NEAR(l.segments[3].x1, -3.0, 1e-12);
    CHECK(l.launch.gaussian);
    CHECK_NEAR(l.launch.radius, 1.5, 1e-12);
    CHECK_NEAR(l.launch.tilt, 2.0, 1e-12);
    CHECK(l.monitors.size() == 1 && l.monitors[0].name == "up" && l.monitors[0].order == 1);
    CHECK(l.planes.size() == 1 && l.planes[0].name == "end");
    CHECK(l.expectations.size() == 1 && l.expectations[0].line == 16 && l.expectations[0].args.size() == 3);

    const char* bad[][2] = {
        {"wavelength 1.55\nfrobnicate", "line 2: unknown statement"},
        {"wavelength -1", "must be positive"},
        {"wavelength", "takes one number"},
        {"index core=1.4 clad=1.5", "core > clad"},
        {"index substrate=1.4", "does not have 'substrate'"},
        {"grid dx=0", "must be positive"},
        {"window width=-3", "positive size"},
        {"absorber strength=-1", "cannot be negative"},
        {"guide", "needs a shape"},
        {"guide spiral from=0 to=1", "unknown guide shape"},
        {"guide straight x=0 from=0 to=10", "needs width"},
        {"guide straight x=0 width=0.5 from=10 to=5", "from < to"},
        {"guide taper x=0 w0=0.5 w1=0 from=0 to=5", "must be positive"},
        {"guide sbend x0=0 width=0.5 from=0 to=5", "needs x1"},
        {"guide straight x=0 width=0.5 radius=3 from=0 to=5", "does not have 'radius'"},
        {"launch", "mode or gaussian"},
        {"launch plane x=0", "mode or gaussian"},
        {"launch gaussian x=0", "needs radius"},
        {"launch mode x=0", "needs width"},
        {"monitor z=5 x=0 width=0.5", "needs a name"},
        {"monitor a z=5 width=0.5\nmonitor a z=6 width=0.5", "defined twice"},
        {"plane p z=1\nplane p z=2", "defined twice"},
        {"plane p x=1", "does not have 'x'"},
        {"expect", "needs a kind"},
    };
    for (const auto& b : bad) CHECK(throws_with([&] { parse_layout_text(b[0]); }, b[1]));
    CHECK_THROWS(load_layout("/no/such/file.bpm"));
}
