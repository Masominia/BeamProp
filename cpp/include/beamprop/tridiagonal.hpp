// Complex tridiagonal systems (Thomas algorithm).
#pragma once

#include "beamprop/types.hpp"

namespace bp {

// Solves a system with sub-diagonal `lower`, diagonal `diagonal` and super-diagonal `upper`, all of the length
// of `rhs`; lower[0] and upper[n-1] are ignored. Returns the solution. Throws std::invalid_argument on a size
// mismatch and std::runtime_error on a zero pivot. No pivoting: meant for diagonally dominant systems.
Field solve_tridiagonal(const Field& lower, const Field& diagonal, const Field& upper, const Field& rhs);

// Same system with one off-diagonal value everywhere, as produced by a uniform grid.
Field solve_tridiagonal(Complex off, const Field& diagonal, const Field& rhs);

}  // namespace bp
