#include "beamprop/tridiagonal.hpp"
#include "check.hpp"

void test_tridiagonal(Suite& suite) {
    using namespace bp;
    const std::size_t n = 30;
    Field lower(n), diagonal(n), upper(n), x(n), rhs(n);
    for (std::size_t i = 0; i < n; ++i) {
        lower[i] = Complex(-1.0, 0.2), upper[i] = Complex(0.5, -0.3);
        diagonal[i] = Complex(4.0 + 0.1 * static_cast<double>(i), 1.0);
        x[i] = Complex(std::cos(0.7 * static_cast<double>(i)), std::sin(0.3 * static_cast<double>(i)));
    }
    for (std::size_t i = 0; i < n; ++i) {
        rhs[i] = diagonal[i] * x[i];
        if (i > 0) rhs[i] += lower[i] * x[i - 1];
        if (i + 1 < n) rhs[i] += upper[i] * x[i + 1];
    }
    const Field got = solve_tridiagonal(lower, diagonal, upper, rhs);
    double worst = 0.0;
    for (std::size_t i = 0; i < n; ++i) worst = std::fmax(worst, std::abs(got[i] - x[i]));
    CHECK(worst < 1e-13);

    // constant off-diagonal form
    Field rhs2(n);
    const Complex off(0.0, -0.4);
    for (std::size_t i = 0; i < n; ++i) rhs2[i] = diagonal[i] * x[i] + (i > 0 ? off * x[i - 1] : Complex(0.0)) + (i + 1 < n ? off * x[i + 1] : Complex(0.0));
    const Field got2 = solve_tridiagonal(off, diagonal, rhs2);
    worst = 0.0;
    for (std::size_t i = 0; i < n; ++i) worst = std::fmax(worst, std::abs(got2[i] - x[i]));
    CHECK(worst < 1e-13);

    // one unknown, mismatched sizes, singular system
    CHECK_NEAR(solve_tridiagonal(Field{0.0}, Field{2.0}, Field{0.0}, Field{6.0})[0].real(), 3.0, 1e-15);
    CHECK_THROWS(solve_tridiagonal(Field(3), Field(4), Field(4), Field(4)));
    CHECK_THROWS(solve_tridiagonal(Field(2, 0.0), Field(2, 0.0), Field(2, 0.0), Field(2, 1.0)));
    CHECK_THROWS(solve_tridiagonal(Field{}, Field{}, Field{}, Field{}));
}
