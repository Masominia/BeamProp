#include <cmath>

#include "beamprop/layout.hpp"
#include "check.hpp"

void test_layout(Suite& suite) {
    using namespace bp;
    Segment taper{Shape::Taper, 1.0, 1.0, 0.5, 2.5, 10.0, 30.0};
    CHECK_NEAR(taper.width(10.0), 0.5, 1e-12);
    CHECK_NEAR(taper.width(20.0), 1.5, 1e-12);
    CHECK_NEAR(taper.centre(25.0), 1.0, 1e-12);
    Segment bend{Shape::SBend, 0.0, 4.0, 0.5, 0.5, 0.0, 40.0};
    CHECK_NEAR(bend.centre(0.0), 0.0, 1e-12);
    CHECK_NEAR(bend.centre(20.0), 2.0, 1e-12);
    CHECK_NEAR(bend.centre(40.0), 4.0, 1e-12);
    CHECK(bend.centre(10.0) < 1.0);  // slow start of the raised cosine
    Segment line{Shape::Line, 0.0, 4.0, 0.5, 0.5, 0.0, 40.0};
    CHECK_NEAR(line.centre(10.0), 1.0, 1e-12);

    Layout l;
    l.width = 8.0, l.length = 50.0, l.dx = 0.1, l.dz = 0.5;
    l.absorber_width = 1.0, l.absorber_strength = 0.4;
    l.segments.push_back({Shape::Straight, 0.0, 0.0, 1.0, 1.0, 0.0, 20.0});
    CHECK(l.nx() == 80 && l.nz() == 100);
    CHECK_NEAR(l.x(0), -3.95, 1e-12);
    const Field eps = permittivity(l, 10.0);
    CHECK_NEAR(eps[40].real(), 2.848 * 2.848, 1e-12);  // x = 0.05, inside the core
    CHECK_NEAR(eps[46].real(), 1.444 * 1.444, 1e-12);  // x = 0.65, outside
    CHECK_NEAR(eps[40].imag(), 0.0, 1e-15);
    // absorber: quadratic rise to the full strength at the wall
    CHECK(eps[0].imag() > eps[5].imag() && eps[5].imag() > 0.0);
    CHECK_NEAR(eps[0].imag(), 0.4 * 0.95 * 0.95, 1e-12);
    CHECK_NEAR(eps[79].imag(), eps[0].imag(), 1e-12);
    // beyond the end of the guide only cladding is left
    CHECK_NEAR(permittivity(l, 30.0)[40].real(), 1.444 * 1.444, 1e-12);

    // a wall inside a cell: the cell takes the covered fraction
    l.segments[0] = {Shape::Straight, 0.0, 0.0, 1.1, 1.1, 0.0, 20.0};
    const double core = 2.848 * 2.848, clad = 1.444 * 1.444;
    CHECK_NEAR(permittivity(l, 10.0)[45].real(), clad + 0.5 * (core - clad), 1e-9);
    // overlapping guides do not exceed the core permittivity
    l.segments.push_back({Shape::Straight, 0.2, 0.2, 1.0, 1.0, 0.0, 20.0});
    CHECK_NEAR(permittivity(l, 10.0)[42].real(), core, 1e-12);

    // reference index: given, launched mode, or cladding
    CHECK(l.reference_index() > 1.444 && l.reference_index() < 2.848);
    l.launch.gaussian = true;
    CHECK_NEAR(l.reference_index(), 1.444, 1e-12);
    l.reference = 2.2;
    CHECK_NEAR(l.reference_index(), 2.2, 1e-12);
    l.width = 8.05;
    CHECK_THROWS(l.nx());
}
