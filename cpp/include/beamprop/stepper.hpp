// One Crank-Nicolson step of the paraxial wave equation.
#pragma once

#include "beamprop/types.hpp"

namespace bp {

// Advances the envelope u by dz through the permittivity `eps` (taken at the middle of the step):
//
//   du/dz = i / (2 k n0) [ d2u/dx2 + k^2 (eps - n0^2) u ]
//
// with the field E = u exp(i k n0 z) and zero field beyond both edges. Without loss the step conserves
// the sum of |u|^2 exactly.
Field step(const Field& u, const Field& eps, double k, double n0, double dx, double dz);

// Sum of |u|^2 dx.
double power(const Field& u, double dx);

// Sum of conj(a) b dx.
Complex overlap(const Field& a, const Field& b, double dx);

}  // namespace bp
