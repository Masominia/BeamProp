#include <cmath>

#include "beamprop/stepper.hpp"
#include "check.hpp"

void test_stepper(Suite& suite) {
    using namespace bp;
    const int n = 400;
    const double dx = 0.05, dz = 0.5, lambda = 1.55, k = 2.0 * kPi / lambda, n0 = 1.5;
    Field u(n), eps(n, Complex(n0 * n0, 0.0));
    for (int i = 0; i < n; ++i) {
        const double x = (i - n / 2 + 0.5) * dx;
        u[i] = std::exp(-x * x / 4.0) * std::exp(Complex(0.0, 0.8 * x));
    }
    CHECK_NEAR(power(u, dx), std::sqrt(kPi / 2.0) * 2.0, 1e-6);
    CHECK_NEAR(overlap(u, u, dx).real(), power(u, dx), 1e-12);
    CHECK_NEAR(overlap(u, u, dx).imag(), 0.0, 1e-12);

    // unitary without loss
    Field v = u;
    for (int s = 0; s < 50; ++s) v = step(v, eps, k, n0, dx, dz);
    CHECK_NEAR(power(v, dx), power(u, dx), 1e-11);

    // a sine that fits the window is an eigenfunction: only its phase changes, by 2 atan(a h)
    Field sine(n);
    const double q = 3.0 * kPi / ((n + 1) * dx);
    for (int i = 0; i < n; ++i) sine[i] = std::sin(q * (i + 1) * dx);
    const Field after = step(sine, eps, k, n0, dx, dz);
    const double h = -4.0 / (dx * dx) * std::pow(std::sin(0.5 * q * dx), 2);
    const double expected = 2.0 * std::atan(dz / (4.0 * k * n0) * h);
    double worst = 0.0;
    for (int i = 0; i < n; ++i) worst = std::fmax(worst, std::abs(after[i] - sine[i] * std::exp(Complex(0.0, expected))));
    CHECK(worst < 1e-12);

    // loss removes power
    Field lossy(n, Complex(n0 * n0, 0.5));
    CHECK(power(step(u, lossy, k, n0, dx, dz), dx) < 0.99 * power(u, dx));
    // a uniform index offset is a pure phase
    Field raised(n, Complex(n0 * n0 + 0.3, 0.0));
    CHECK_NEAR(power(step(u, raised, k, n0, dx, dz), dx), power(u, dx), 1e-12);

    CHECK_THROWS(step(u, Field(n - 1), k, n0, dx, dz));
    CHECK_THROWS(overlap(u, Field(n - 1), dx));
}
