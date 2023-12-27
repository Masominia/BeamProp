#include <cmath>

#include "beamprop/slab.hpp"
#include "beamprop/types.hpp"
#include "check.hpp"

void test_slab(Suite& suite) {
    using namespace bp;
    const double lambda = 1.55, nc = 2.848, ncl = 1.444, k = 2.0 * kPi / lambda;
    // cut-off widths: mode m appears at m lambda / (2 sqrt(nc^2 - ncl^2))
    const double step = lambda / (2.0 * std::sqrt(nc * nc - ncl * ncl));
    CHECK(slab_mode_count(lambda, 0.9 * step, nc, ncl) == 1);
    CHECK(slab_mode_count(lambda, 1.1 * step, nc, ncl) == 2);
    CHECK(slab_mode_count(lambda, 3.5 * step, nc, ncl) == 4);
    CHECK(slab_mode_count(lambda, 0.5, 1.0, 1.444) == 0);

    for (int order = 0; order < 3; ++order) {
        const SlabMode m = slab_mode(lambda, 2.0, nc, ncl, order);
        CHECK(m.n_eff > ncl && m.n_eff < nc);
        // transverse wavenumbers are consistent with the index
        CHECK_NEAR(m.kappa * m.kappa, k * k * (nc * nc - m.n_eff * m.n_eff), 1e-9);
        CHECK_NEAR(m.gamma * m.gamma, k * k * (m.n_eff * m.n_eff - ncl * ncl), 1e-9);
        // dispersion relation kappa w = 2 atan(gamma / kappa) + m pi
        CHECK_NEAR(m.kappa * 2.0, 2.0 * std::atan(m.gamma / m.kappa) + order * kPi, 1e-9);
        // field and slope are continuous at the wall
        const double h = 1e-6, wall = 1.0;
        CHECK_NEAR(m.profile(wall - h), m.profile(wall + h), 1e-5);
        CHECK_NEAR((m.profile(wall) - m.profile(wall - h)) / h, (m.profile(wall + h) - m.profile(wall)) / h, 1e-4);
        // parity
        CHECK_NEAR(m.profile(-0.37), (order % 2 == 0 ? 1.0 : -1.0) * m.profile(0.37), 1e-12);
    }
    // higher orders have lower index
    CHECK(slab_mode(lambda, 2.0, nc, ncl, 1).n_eff < slab_mode(lambda, 2.0, nc, ncl, 0).n_eff);
    // wider guides have higher index
    CHECK(slab_mode(lambda, 0.4, nc, ncl, 0).n_eff < slab_mode(lambda, 0.8, nc, ncl, 0).n_eff);
    CHECK_THROWS(slab_mode(lambda, 0.3, nc, ncl, 1));
    CHECK_THROWS(slab_mode(lambda, 0.5, nc, ncl, -1));
}
