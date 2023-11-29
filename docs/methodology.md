# Methodology

BeamProp propagates a scalar field through a planar photonic circuit described in the plane (x, z): x across the circuit, z along it. The vertical direction is assumed to have been removed beforehand by the effective index method, so that the "core" and "cladding" indices are slab effective indices.

## 1. Equation

The field is written E = u exp(i k n0 z), with n0 a reference index. Dropping the second derivative of the envelope u along z gives the paraxial equation

    du/dz = i / (2 k n0) [ d2u/dx2 + k^2 (eps(x, z) - n0^2) u ]

It is exact for a plane wave travelling along z at index n0 and degrades with the angle to the axis and with the distance of the local index from n0:

- a mode of true index n shows the index n0 + (n^2 - n0^2) / (2 n0);
- a beam tilted by an angle a advances sideways by z sin(a) instead of z tan(a).

Both are reproduced exactly by the library and both are small for the guided-wave circuits it contains, where light travels within a few degrees of the axis.

## 2. Discretisation

Across: equal cells, field at cell centres, second difference, zero field beyond both edges. A cell cut by a waveguide wall takes the covered fraction of the core permittivity, which lets bends and tapers move smoothly across the grid.

Along: Crank-Nicolson,

    (1 - i a H) u(z + dz) = (1 + i a H) u(z),    a = dz / (4 k n0)

with H the transverse operator evaluated at the middle of the step. Each step is one complex tridiagonal solve. The step is unitary when the permittivity is real, so power is conserved to rounding; it is second order in dz. An eigenfunction of H with eigenvalue h gathers the phase 2 atan(a h) per step instead of 2 a h: accurate for slowly varying envelopes, saturating for fast ones.

That last point decides what a given step resolves. Guided light near the reference index has a small phase per step and is propagated accurately with steps of a quarter micrometre. Light radiated at large angles has a large one and its pattern is not accurate at such steps; it only needs to leave.

## 3. Edges

An absorbing layer adds an imaginary part to the permittivity, rising quadratically from zero at its inner edge to `strength` at the wall. It is not a perfectly matched layer. The library shows its three failure modes with a beam at 15 degrees: too weak and the beam reaches the wall and returns (34% left at strength 0.03), too strong and it reflects from the layer itself (3% at strength 3), too thin and both happen (1.4% for 2 um). With 5 um at strength 0.3, 0.05% is left.

## 4. Launch and monitors

A launch is an analytic TE mode of a symmetric slab of the given width (any guided order) or a Gaussian beam with an optional tilt. A monitor is the squared overlap of the field with such a mode at a plane, over the launched power. Planes report total power, centroid and beam radius (twice the root mean square width, which is the 1/e^2 radius for a Gaussian).

The analytic mode is not exactly the mode of the discretised guide, so a launch sheds a little radiation (of order 1e-6 of the power on a 20 nm grid) and monitors of neighbouring guides are not exactly orthogonal when the guides are closer than about 200 nm.

The solver also follows the phase of the overlap of the field with its own launch profile along z and reports the index it implies.

## 5. Validation

1. C++ unit tests: the tridiagonal solver, slab modes against their dispersion relation and boundary conditions, permittivity profiles, unitarity and the exact phase of one step on an eigenfunction, and physics with a closed form or a symmetry (Gaussian diffraction, equal arms of a symmetric splitter, reciprocity of a taper to 1e-9).
2. The layout library. Each file's expectations come from `reference.py`, an independent NumPy implementation (own reader, own profile, banded solver), plus closed forms where they exist: Gaussian beam radius, z sin(a) for tilted beams, the index n0 + 2 atan(t / 2) / (k dz) for a mode, overlap integrals of analytic modes for mismatched and offset launches, sin^2 transfer in couplers with the coupling length from a dense eigen-solve of the transverse grid, the imaging lengths of multimode interferometers from the same eigen-solve.
3. The report pipeline repeats the independent propagation for every layout and compares monitors, planes, the tracked index and the whole output field.
4. Modal solution. For a guide that does not change along z the transverse operator can be diagonalised and each of its modes advanced by its own phase, with no stepping at all. Guided modes agree with it within 1e-3 of the field peak at the default step, and the error falls as the square of the step (fitted order 1.97).
5. Consistency across layouts: transmission of tapers and bends rising with length, reciprocity of a taper and its mirror image, coupling lengths, the optimum length of each interferometer.

What this does not validate: the paraxial and scalar approximations themselves, and the reduction of a three-dimensional circuit to two dimensions. Those are stated in the README.
