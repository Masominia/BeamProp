#include "beamprop/layout.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "beamprop/slab.hpp"

namespace bp {

double Segment::centre(double z) const {
    const double t = to > from ? std::clamp((z - from) / (to - from), 0.0, 1.0) : 0.0;
    if (shape == Shape::SBend) return x0 + (x1 - x0) * 0.5 * (1.0 - std::cos(kPi * t));
    return x0 + (x1 - x0) * t;
}

double Segment::width(double z) const {
    const double t = to > from ? std::clamp((z - from) / (to - from), 0.0, 1.0) : 0.0;
    return w0 + (w1 - w0) * t;
}

static int whole(double length, double step, const char* what) {
    const double count = length / step;
    const int n = static_cast<int>(std::lround(count));
    if (std::fabs(count - n) > 1e-6 || n < 4) throw std::invalid_argument(std::string("the window is not a whole number of steps in ") + what);
    return n;
}

int Layout::nx() const { return whole(width, dx, "x"); }
int Layout::nz() const { return whole(length, dz, "z"); }

double Layout::reference_index() const {
    if (reference > 0.0) return reference;
    if (!launch.gaussian) return slab_mode(wavelength, launch.width, n_core, n_clad, launch.order).n_eff;
    return n_clad;
}

Field permittivity(const Layout& layout, double z) {
    const int n = layout.nx();
    const double core = layout.n_core * layout.n_core, clad = layout.n_clad * layout.n_clad;
    std::vector<double> fill(n, 0.0);
    for (const Segment& s : layout.segments) {
        if (z < s.from - 1e-9 || z > s.to + 1e-9) continue;
        const double c = s.centre(z), half = 0.5 * s.width(z);
        for (int i = 0; i < n; ++i) {
            const double lo = -0.5 * layout.width + i * layout.dx, hi = lo + layout.dx;
            const double covered = std::fmax(0.0, std::fmin(hi, c + half) - std::fmax(lo, c - half)) / layout.dx;
            fill[i] = std::fmin(1.0, fill[i] + covered);
        }
    }
    Field eps(n);
    for (int i = 0; i < n; ++i) {
        double loss = 0.0;
        if (layout.absorber_width > 0.0) {
            const double depth = layout.absorber_width - (0.5 * layout.width - std::fabs(layout.x(i)));
            if (depth > 0.0) loss = layout.absorber_strength * std::pow(depth / layout.absorber_width, 2);
        }
        eps[i] = Complex(clad + fill[i] * (core - clad), loss);
    }
    return eps;
}

}  // namespace bp
