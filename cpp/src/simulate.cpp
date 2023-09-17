#include "beamprop/simulate.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "beamprop/slab.hpp"
#include "beamprop/stepper.hpp"

namespace bp {

Field mode_field(const Layout& layout, double x, double width, int order) {
    const SlabMode mode = slab_mode(layout.wavelength, width, layout.n_core, layout.n_clad, order);
    Field f(layout.nx());
    for (int i = 0; i < layout.nx(); ++i) f[i] = mode.profile(layout.x(i) - x);
    const double norm = std::sqrt(power(f, layout.dx));
    for (Complex& v : f) v /= norm;
    return f;
}

Field launch_field(const Layout& layout) {
    const Launch& l = layout.launch;
    if (!l.gaussian) return mode_field(layout, l.x, l.width, l.order);
    if (!(l.radius > 0.0)) throw std::invalid_argument("a Gaussian launch needs a positive radius");
    const double kx = 2.0 * kPi / layout.wavelength * layout.n_clad * std::sin(l.tilt * kPi / 180.0);
    Field f(layout.nx());
    for (int i = 0; i < layout.nx(); ++i) {
        const double x = layout.x(i);
        f[i] = std::exp(-std::pow((x - l.x) / l.radius, 2)) * std::exp(Complex(0.0, kx * x));
    }
    const double norm = std::sqrt(power(f, layout.dx));
    for (Complex& v : f) v /= norm;
    return f;
}

static PlaneResult measure(const Layout& layout, const Field& u, const std::string& name, double z, double launched) {
    PlaneResult p;
    p.name = name, p.z = z;
    double s0 = 0.0, s1 = 0.0, s2 = 0.0, peak = -1.0;
    for (int i = 0; i < layout.nx(); ++i) {
        const double w = std::norm(u[i]), x = layout.x(i);
        s0 += w, s1 += w * x, s2 += w * x * x;
        if (w > peak) peak = w, p.peak_x = x;
    }
    p.total = s0 * layout.dx / launched;
    p.centroid = s0 > 0.0 ? s1 / s0 : 0.0;
    p.radius = s0 > 0.0 ? 2.0 * std::sqrt(std::fmax(0.0, s2 / s0 - p.centroid * p.centroid)) : 0.0;
    return p;
}

Result simulate(const Layout& layout, bool keep_map) {
    const int nx = layout.nx(), nz = layout.nz();
    const double k = 2.0 * kPi / layout.wavelength, n0 = layout.reference_index();
    Result r;
    r.nx = nx, r.nz = nz, r.n0 = n0;
    const Field start = launch_field(layout);
    Field u = start;
    r.launched = power(u, layout.dx);

    auto step_of = [&](double z, const std::string& what) {
        if (z < -1e-9 || z > layout.length + 1e-9) throw std::invalid_argument(what + " lies outside the window");
        return static_cast<int>(std::lround(z / layout.dz));
    };
    std::vector<std::pair<int, Field>> monitor_modes;
    for (const Monitor& m : layout.monitors) monitor_modes.emplace_back(step_of(m.z, "monitor " + m.name), mode_field(layout, m.x, m.width, m.order));
    std::vector<int> plane_steps;
    for (const Plane& p : layout.planes) plane_steps.push_back(step_of(p.z, "plane " + p.name));

    const int row_stride = (nz + 239) / 240, column_stride = (nx + 399) / 400;
    if (keep_map)
        for (int i = 0; i < nx; i += column_stride) r.map_x.push_back(layout.x(i));

    double phase = 0.0, tracked = 0.0;
    Complex previous = overlap(start, u, layout.dx);
    const double threshold = 1e-6 * std::abs(previous);
    bool tracking = true;
    r.monitors.resize(layout.monitors.size());
    r.planes.resize(layout.planes.size());
    for (int s = 0; s <= nz; ++s) {
        const double z = s * layout.dz;
        if (s > 0) {
            u = step(u, permittivity(layout, z - 0.5 * layout.dz), k, n0, layout.dx, layout.dz);
            const Complex c = overlap(start, u, layout.dx);
            if (tracking && std::abs(c) > threshold) {
                phase += std::arg(c * std::conj(previous));
                tracked = z;
            } else {
                tracking = false;
            }
            previous = c;
        }
        r.z.push_back(z);
        r.total.push_back(power(u, layout.dx) / r.launched);
        r.in_launch.push_back(std::norm(overlap(start, u, layout.dx)) / (r.launched * r.launched));
        for (std::size_t m = 0; m < monitor_modes.size(); ++m) {
            if (monitor_modes[m].first != s) continue;
            const Complex c = overlap(monitor_modes[m].second, u, layout.dx);
            r.monitors[m] = {layout.monitors[m].name, z, std::norm(c) / r.launched, std::arg(c)};
        }
        for (std::size_t p = 0; p < plane_steps.size(); ++p)
            if (plane_steps[p] == s) r.planes[p] = measure(layout, u, layout.planes[p].name, z, r.launched);
        if (keep_map && (s % row_stride == 0 || s == nz)) {
            std::vector<double> row;
            for (int i = 0; i < nx; i += column_stride) row.push_back(std::norm(u[i]));
            r.map_z.push_back(z);
            r.map.push_back(row);
        }
    }
    r.n_track = tracked > 0.0 ? n0 + phase / (k * tracked) : n0;
    r.output = u;
    return r;
}

}  // namespace bp
