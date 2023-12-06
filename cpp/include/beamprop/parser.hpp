// Reader for layout files.
//
//   title <text>
//   wavelength <um>
//   index core=<n> clad=<n>
//   reference <n>                                  reference index; default: the launched mode, else the cladding
//   grid dx=<um> dz=<um>
//   window width=<um> length=<um>                  x from -width/2 to width/2, z from 0 to length
//   absorber width=<um> strength=<imaginary permittivity at the edge>
//   guide straight x= width= from= to=
//   guide taper x= w0= w1= from= to=
//   guide sbend x0= x1= width= from= to=           raised-cosine offset
//   guide line x0= x1= width= from= to=            straight but tilted
//   launch mode x= width= [order=]
//   launch gaussian x= radius= [tilt=<deg>]
//   monitor <name> z= x= width= [order=]           power in a slab mode at a plane
//   plane <name> z=                                total power, centroid and beam radius at a plane
//   expect <kind> <args...>
#pragma once

#include <istream>
#include <string>

#include "beamprop/layout.hpp"

namespace bp {

// Throws std::invalid_argument with the line number on any error.
Layout parse_layout(std::istream& in);
Layout parse_layout_text(const std::string& text);
Layout load_layout(const std::string& path);

}  // namespace bp
