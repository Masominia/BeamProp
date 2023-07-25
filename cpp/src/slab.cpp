#include "beamprop/slab.hpp"

#include <cmath>
#include <stdexcept>
#include <string>

#include "beamprop/types.hpp"

namespace bp {

static double v_number(double lambda, double width, double n_core, double n_clad) {
    return 0.5 * width * 2.0 * kPi / lambda * std::sqrt(n_core * n_core - n_clad * n_clad);
}

int slab_mode_count(double lambda, double width, double n_core, double n_clad) {
    if (!(n_core > n_clad) || !(width > 0.0)) return 0;
    // mode m exists when the half-width V number exceeds m pi / 2
    return static_cast<int>(std::floor(v_number(lambda, width, n_core, n_clad) / (0.5 * kPi))) + 1;
}

SlabMode slab_mode(double lambda, double width, double n_core, double n_clad, int order) {
    if (order < 0 || order >= slab_mode_count(lambda, width, n_core, n_clad)) throw std::invalid_argument("slab mode " + std::to_string(order) + " is not guided");
    const double v = v_number(lambda, width, n_core, n_clad), half = 0.5 * width;
    // u = kappa * half lies in (m pi/2, min(v, (m+1) pi/2)); the root of u tan(u - m pi/2) = sqrt(v^2 - u^2)
    double lo = order * 0.5 * kPi, hi = std::fmin(v, (order + 1) * 0.5 * kPi);
    for (int i = 0; i < 200; ++i) {
        const double u = 0.5 * (lo + hi);
        const double f = u * std::tan(u - order * 0.5 * kPi) - std::sqrt(std::fmax(v * v - u * u, 0.0));
        if (f < 0.0) lo = u;
        else hi = u;
    }
    const double u = 0.5 * (lo + hi), k = 2.0 * kPi / lambda;
    SlabMode m;
    m.kappa = u / half;
    m.gamma = std::sqrt(std::fmax(v * v - u * u, 0.0)) / half;
    m.n_eff = std::sqrt(n_core * n_core - std::pow(m.kappa / k, 2));
    m.width = width, m.order = order;
    return m;
}

double SlabMode::profile(double x) const {
    const double half = 0.5 * width;
    const bool even = order % 2 == 0;
    const double inside = even ? std::cos(kappa * std::fmin(std::fabs(x), half)) : std::sin(kappa * std::fmin(std::fabs(x), half));
    const double value = std::fabs(x) <= half ? inside : inside * std::exp(-gamma * (std::fabs(x) - half));
    return (!even && x < 0.0) ? -value : value;
}

}  // namespace bp
