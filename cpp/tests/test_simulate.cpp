#include <cmath>

#include "beamprop/parser.hpp"
#include "beamprop/simulate.hpp"
#include "beamprop/stepper.hpp"
#include "check.hpp"

void test_simulate(Suite& suite) {
    using namespace bp;
    const Layout guide = parse_layout_text("window width=12 length=50\nguide straight x=0 width=0.5 from=0 to=50\nlaunch mode x=0 width=0.5\n"
                                           "monitor mid z=25.1 x=0 width=0.5\nmonitor out z=50 x=0 width=0.5\nmonitor side z=50 x=3 width=0.5\nplane end z=50\n");
    // launch and mode fields carry unit power
    CHECK_NEAR(power(launch_field(guide), guide.dx), 1.0, 1e-12);
    CHECK_NEAR(power(mode_field(guide, 1.0, 0.8, 0), guide.dx), 1.0, 1e-12);

    const Result r = simulate(guide, true);
    CHECK(r.nx == 600 && r.nz == 200);
    CHECK(r.z.size() == 201 && r.total.size() == 201 && r.in_launch.size() == 201);
    CHECK_NEAR(r.total.front(), 1.0, 1e-12);
    CHECK_NEAR(r.in_launch.front(), 1.0, 1e-12);
    CHECK(r.monitors.size() == 3 && r.planes.size() == 1);
    CHECK_NEAR(r.monitors[0].z, 25.0, 1e-12);  // snapped to a whole step
    CHECK(r.monitors[0].power > 0.9999 && r.monitors[1].power > 0.9999);
    CHECK(r.monitors[2].power < 1e-8);
    CHECK_NEAR(r.planes[0].centroid, 0.0, 1e-9);
    CHECK(r.planes[0].radius > 0.2 && r.planes[0].radius < 0.4);
    CHECK(std::fabs(r.n_track - r.n0) < 2e-3);
    // map: at most 240 rows plus the last, 400 columns
    CHECK(r.map.size() == r.map_z.size() && r.map.size() >= 200 && r.map.size() <= 242);
    CHECK(r.map_x.size() == r.map.front().size() && r.map_x.size() <= 400);
    CHECK_NEAR(r.map_z.back(), 50.0, 1e-12);
    CHECK(simulate(guide, false).map.empty());

    // a Gaussian launch with a tilt has the right transverse phase
    const Layout beam = parse_layout_text("grid dx=0.05 dz=0.5\nwindow width=40 length=10\nlaunch gaussian x=1 radius=3 tilt=5\n");
    const Field g = launch_field(beam);
    CHECK_NEAR(power(g, beam.dx), 1.0, 1e-12);
    const double kx = 2.0 * kPi / 1.55 * 1.444 * std::sin(5.0 * kPi / 180.0);
    CHECK_NEAR(std::arg(g[420] * std::conj(g[400])), kx * 20 * beam.dx, 1e-9);

    // monitors and planes must lie inside the window
    CHECK_THROWS(simulate(parse_layout_text("window width=12 length=50\nguide straight x=0 width=0.5 from=0 to=50\nlaunch mode x=0 width=0.5\nplane far z=60\n"), false));
    CHECK_THROWS(simulate(parse_layout_text("window width=12 length=50\nlaunch mode x=0 width=0.5\nmonitor m z=-5 x=0 width=0.5\n"), false));
    // a launch mode that is not guided
    CHECK_THROWS(simulate(parse_layout_text("window width=12 length=50\nlaunch mode x=0 width=0.3 order=1\n"), false));
}
