#include "beamprop/tridiagonal.hpp"

#include <stdexcept>

namespace bp {

Field solve_tridiagonal(const Field& lower, const Field& diagonal, const Field& upper, const Field& rhs) {
    const std::size_t n = rhs.size();
    if (n == 0 || lower.size() != n || diagonal.size() != n || upper.size() != n) throw std::invalid_argument("tridiagonal system with mismatched sizes");
    Field c(n), d(n);
    Complex pivot = diagonal[0];
    if (std::abs(pivot) < 1e-300) throw std::runtime_error("zero pivot in the tridiagonal solve");
    c[0] = upper[0] / pivot;
    d[0] = rhs[0] / pivot;
    for (std::size_t i = 1; i < n; ++i) {
        pivot = diagonal[i] - lower[i] * c[i - 1];
        if (std::abs(pivot) < 1e-300) throw std::runtime_error("zero pivot in the tridiagonal solve");
        c[i] = upper[i] / pivot;
        d[i] = (rhs[i] - lower[i] * d[i - 1]) / pivot;
    }
    for (std::size_t i = n - 1; i-- > 0;) d[i] -= c[i] * d[i + 1];
    return d;
}

Field solve_tridiagonal(Complex off, const Field& diagonal, const Field& rhs) {
    const Field side(rhs.size(), off);
    return solve_tridiagonal(side, diagonal, side, rhs);
}

}  // namespace bp
