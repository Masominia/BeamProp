// Propagation through a layout, with everything recorded on the way.
#pragma once

#include <string>
#include <vector>

#include "beamprop/layout.hpp"

namespace bp {

struct MonitorResult {
    std::string name;
    double z = 0.0;       // the plane actually used (a whole number of steps)
    double power = 0.0;   // power in the monitored mode over the launched power
    double phase = 0.0;   // phase of the overlap, radians
};

struct PlaneResult {
    std::string name;
    double z = 0.0;
    double total = 0.0;     // power in the window over the launched power
    double centroid = 0.0;  // intensity-weighted mean position, um
    double radius = 0.0;    // twice the root mean square width: the 1/e^2 radius of a Gaussian, um
    double peak_x = 0.0;
};

struct Result {
    int nx = 0, nz = 0;
    double n0 = 0.0;
    double launched = 0.0;          // sum of |u|^2 dx at the input
    Field output;                   // field after the last step
    std::vector<double> z;          // every step, starting at 0
    std::vector<double> total;      // power in the window over the launched power
    std::vector<double> in_launch;  // power in the launch profile over the launched power
    double n_track = 0.0;           // index of the launched profile from the phase of its overlap along z
    std::vector<MonitorResult> monitors;
    std::vector<PlaneResult> planes;
    // intensity map, decimated: map[r] is the row at map_z[r], columns at map_x
    std::vector<double> map_z, map_x;
    std::vector<std::vector<double>> map;
};

// The launch field on the grid of the layout.
Field launch_field(const Layout& layout);

// The normalised profile of a slab mode centred at `x` on the grid of the layout (unit power).
Field mode_field(const Layout& layout, double x, double width, int order);

// Runs the propagation. `keep_map` stores the intensity map for plotting.
Result simulate(const Layout& layout, bool keep_map);

}  // namespace bp
