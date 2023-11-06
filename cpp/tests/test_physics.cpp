// Results with a closed form or a symmetry behind them.
#include <cmath>
#include <cstdio>

#include "beamprop/parser.hpp"
#include "beamprop/simulate.hpp"
#include "check.hpp"

void test_physics(Suite& suite) {
    using namespace bp;
    // free diffraction of a Gaussian beam
    const double w0 = 2.0, length = 100.0, n = 1.444;
    const Result beam = simulate(parse_layout_text("grid dx=0.05 dz=0.25\nwindow width=140 length=100\nlaunch gaussian x=0 radius=2\nplane end z=100\n"), false);
    const double expected = w0 * std::sqrt(1.0 + std::pow(length * 1.55 / (kPi * n * w0 * w0), 2));
    CHECK_NEAR(beam.planes[0].radius, expected, 0.004 * expected);
    CHECK_NEAR(beam.planes[0].total, 1.0, 1e-6);

    // a tilted beam moves sideways by z sin(angle) in the paraxial equation
    const Result tilted = simulate(parse_layout_text("grid dx=0.05 dz=0.125\nwindow width=60 length=60\nlaunch gaussian x=0 radius=3 tilt=5\nplane end z=60\n"), false);
    CHECK_NEAR(tilted.planes[0].centroid, 60.0 * std::sin(5.0 * kPi / 180.0), 0.01);

    // a left-right symmetric splitter gives equal arms whatever its quality
    const char* branch = "window width=20 length=50\nguide straight x=0 width=0.5 from=0 to=10\nguide sbend x0=0.25 x1=1.5 width=0.5 from=10 to=30\n"
                         "guide sbend x0=-0.25 x1=-1.5 width=0.5 from=10 to=30\nguide straight x=1.5 width=0.5 from=30 to=50\nguide straight x=-1.5 width=0.5 from=30 to=50\n"
                         "launch mode x=0 width=0.5\nmonitor a z=50 x=1.5 width=0.5\nmonitor b z=50 x=-1.5 width=0.5\n";
    const Result y = simulate(parse_layout_text(branch), false);
    CHECK_NEAR(y.monitors[0].power, y.monitors[1].power, 1e-9);
    CHECK(y.monitors[0].power > 0.3 && y.monitors[0].power < 0.5);

    // reciprocity: a taper and its mirror image transmit the same, mode to mode, with the same reference index
    auto taper = [](double a, double b) {
        char text[400];
        std::snprintf(text, sizeof text, "reference 2.75\nwindow width=16 length=30\nguide straight x=0 width=%g from=0 to=5\nguide taper x=0 w0=%g w1=%g from=5 to=25\n"
                                         "guide straight x=0 width=%g from=25 to=30\nlaunch mode x=0 width=%g\nmonitor out z=30 x=0 width=%g\n", a, a, b, b, a, b);
        return simulate(parse_layout_text(text), false).monitors[0].power;
    };
    const double up = taper(0.5, 3.0), down = taper(3.0, 0.5);
    CHECK_NEAR(up, down, 1e-9);
    CHECK(up > 0.98 && up < 1.0);

    // a coupler exchanges power and gives it back
    const char* coupler = "window width=14 length=80\nguide straight x=-0.35 width=0.5 from=0 to=80\nguide straight x=0.35 width=0.5 from=0 to=80\nlaunch mode x=-0.35 width=0.5\n"
                          "monitor bar z=80 x=-0.35 width=0.5\nmonitor cross z=80 x=0.35 width=0.5\n";
    const Result c = simulate(parse_layout_text(coupler), false);
    double lowest = 1.0;
    for (double p : c.in_launch) lowest = std::fmin(lowest, p);
    CHECK(lowest < 0.01);
    CHECK_NEAR(c.monitors[0].power + c.monitors[1].power, 1.0, 5e-3);

    // without an absorber the walls reflect and nothing is lost
    const Result closed = simulate(parse_layout_text("grid dx=0.05 dz=0.25\nwindow width=20 length=100\nabsorber width=0 strength=0\nlaunch gaussian x=0 radius=2 tilt=10\nplane end z=100\n"), false);
    CHECK_NEAR(closed.planes[0].total, 1.0, 1e-10);
    const Result open = simulate(parse_layout_text("grid dx=0.05 dz=0.25\nwindow width=20 length=100\nabsorber width=4 strength=0.3\nlaunch gaussian x=0 radius=2 tilt=10\nplane end z=100\n"), false);
    CHECK(open.planes[0].total < 0.2);
}
