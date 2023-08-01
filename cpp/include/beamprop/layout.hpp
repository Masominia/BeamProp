// A planar circuit as a list of waveguide segments, and its permittivity profile at any z.
#pragma once

#include <string>
#include <vector>

#include "beamprop/types.hpp"

namespace bp {

enum class Shape { Straight, Taper, SBend, Line };

struct Segment {
    Shape shape = Shape::Straight;
    double x0 = 0.0, x1 = 0.0;   // centre at the start and at the end
    double w0 = 0.0, w1 = 0.0;   // width at the start and at the end
    double from = 0.0, to = 0.0; // extent along z
    // Centre and width at z; valid for from <= z <= to.
    double centre(double z) const;
    double width(double z) const;
};

struct Launch {
    bool gaussian = false;
    double x = 0.0;
    double width = 0.5;   // guide width for a mode
    int order = 0;
    double radius = 2.0;  // 1/e^2 intensity radius for a Gaussian
    double tilt = 0.0;    // degrees in the cladding, positive towards +x
};

struct Monitor {
    std::string name;
    double z = 0.0, x = 0.0, width = 0.5;
    int order = 0;
};

struct Plane {
    std::string name;
    double z = 0.0;
};

struct Expectation {
    std::string kind;
    std::vector<std::string> args;
    int line = 0;
};

struct Layout {
    std::string title;
    double wavelength = 1.55;
    double n_core = 2.848, n_clad = 1.444;
    double reference = 0.0;       // 0: chosen automatically
    double dx = 0.02, dz = 0.25;
    double width = 20.0, length = 100.0;
    double absorber_width = 2.0, absorber_strength = 0.3;
    std::vector<Segment> segments;
    Launch launch;
    std::vector<Monitor> monitors;
    std::vector<Plane> planes;
    std::vector<Expectation> expectations;

    int nx() const;
    int nz() const;
    double x(int i) const { return -0.5 * width + (i + 0.5) * dx; }
    // The reference index actually used: the given one, else the index of the launched mode, else the cladding.
    double reference_index() const;
};

// Relative permittivity of every cell at z, absorber included (positive imaginary part near the edges).
// A cell partly covered by a guide takes the covered fraction of the core permittivity.
Field permittivity(const Layout& layout, double z);

}  // namespace bp
