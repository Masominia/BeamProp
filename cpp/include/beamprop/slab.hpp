// Guided TE modes of a symmetric slab: the transverse modes of the planar waveguides in a layout.
#pragma once

#include <vector>

namespace bp {

struct SlabMode {
    double n_eff = 0.0;
    double kappa = 0.0;   // transverse wavenumber in the core, 1/um
    double gamma = 0.0;   // decay rate in the cladding, 1/um
    double width = 0.0;
    int order = 0;
    // Field at a distance x from the centre of the guide, unnormalised.
    double profile(double x) const;
};

// Number of guided TE modes of a slab of the given width.
int slab_mode_count(double lambda, double width, double n_core, double n_clad);

// Mode `order` (0 is the fundamental). Throws std::invalid_argument if it is not guided.
SlabMode slab_mode(double lambda, double width, double n_core, double n_clad, int order);

}  // namespace bp
