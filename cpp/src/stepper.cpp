#include "beamprop/stepper.hpp"

#include <stdexcept>

#include "beamprop/tridiagonal.hpp"

namespace bp {

Field step(const Field& u, const Field& eps, double k, double n0, double dx, double dz) {
    const std::size_t n = u.size();
    if (eps.size() != n || n < 3) throw std::invalid_argument("field and permittivity must have the same length, at least three");
    // (1 - i a H) u_new = (1 + i a H) u_old, H = second difference + k^2 (eps - n0^2), a = dz / (4 k n0)
    const Complex ia(0.0, dz / (4.0 * k * n0));
    const double off = 1.0 / (dx * dx);
    Field diagonal(n), rhs(n);
    for (std::size_t i = 0; i < n; ++i) {
        const Complex h = -2.0 * off + k * k * (eps[i] - n0 * n0);
        const Complex left = i > 0 ? u[i - 1] : Complex(0.0), right = i + 1 < n ? u[i + 1] : Complex(0.0);
        rhs[i] = u[i] + ia * (h * u[i] + off * (left + right));
        diagonal[i] = 1.0 - ia * h;
    }
    return solve_tridiagonal(-ia * off, diagonal, rhs);
}

double power(const Field& u, double dx) {
    double s = 0.0;
    for (const Complex& v : u) s += std::norm(v);
    return s * dx;
}

Complex overlap(const Field& a, const Field& b, double dx) {
    if (a.size() != b.size()) throw std::invalid_argument("overlap of fields of different length");
    Complex s = 0.0;
    for (std::size_t i = 0; i < a.size(); ++i) s += std::conj(a[i]) * b[i];
    return s * dx;
}

}  // namespace bp
