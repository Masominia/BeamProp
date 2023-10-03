// Expectations of a layout file, checked against its simulation.
//
//   power <monitor> <fraction> <tol>         power in the monitored mode over the launched power
//   power_db <monitor> <dB> <tol>
//   power_above <monitor> <fraction>         at least this much
//   power_below <monitor> <fraction>         at most this much
//   sum <monitor> <monitor> <fraction> <tol> two monitors together
//   ratio <monitor> <monitor> <value> <tol>  first over second
//   total <plane> <fraction> <tol>           power left in the window
//   centroid <plane> <um> <tol>
//   radius <plane> <um> <tol>                twice the root mean square width
//   neff <value> <tol>                       index of the launched profile, from its phase along z
//   conserved <tol>                          total power stays within tol of 1 at every step
#pragma once

#include <string>
#include <vector>

#include "beamprop/simulate.hpp"

namespace bp {

struct Check {
    std::string name;
    bool pass = false;
    std::string detail;
};

// A malformed expectation becomes a failed check with its line number; it does not stop the others.
std::vector<Check> evaluate(const Layout& layout, const Result& result);

}  // namespace bp
