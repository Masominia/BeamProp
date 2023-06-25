# Layout files

One statement per line. `#` starts a comment; the comment lines at the top of a file are its description and appear in the report. Lengths are in micrometres. The window runs from -width/2 to width/2 in x and from 0 to length in z.

## Statements

| statement | meaning | default |
|---|---|---|
| `title <text>` | name used in reports | empty |
| `wavelength <um>` | vacuum wavelength | 1.55 |
| `index core=<n> clad=<n>` | slab effective indices inside and outside the guides | 2.848, 1.444 |
| `reference <n>` | reference index of the envelope | index of the launched mode; the cladding index for a Gaussian launch |
| `grid dx=<um> dz=<um>` | transverse cell and step along z | 0.02, 0.25 |
| `window width=<um> length=<um>` | must be a whole number of cells and steps | 20, 100 |
| `absorber width=<um> strength=<s>` | absorbing layer at both edges; `width=0` switches it off | 2, 0.3 |
| `guide straight x= width= from= to=` | constant centre and width between two z | |
| `guide taper x= w0= w1= from= to=` | width changing linearly | |
| `guide sbend x0= x1= width= from= to=` | centre moving along a raised cosine | |
| `guide line x0= x1= width= from= to=` | centre moving linearly (a tilted guide) | |
| `launch mode x= width= order=` | slab mode of a guide of that width | x=0, width=0.5, order=0 |
| `launch gaussian x= radius= tilt=<deg>` | Gaussian beam, 1/e^2 intensity radius, tilt in the cladding | |
| `monitor <name> z= x= width= order=` | power in a slab mode at a plane | |
| `plane <name> z=` | total power, centroid and beam radius at a plane | |
| `expect <kind> <args>` | a check, see below | |

Guides may overlap; the permittivity never exceeds that of the core. A wide `guide straight` is how a multimode section is written. Monitor and plane positions are moved to the nearest whole step.

## Expectations

| kind | arguments | passes when |
|---|---|---|
| `power` | monitor, fraction, tolerance | the monitored power is within the tolerance |
| `power_db` | monitor, dB, tolerance | the same in decibels |
| `power_above`, `power_below` | monitor, fraction | a bound |
| `sum` | monitor, monitor, fraction, tolerance | two monitors together |
| `ratio` | monitor, monitor, value, tolerance | first over second |
| `total` | plane, fraction, tolerance | power left in the window |
| `centroid`, `radius` | plane, um, tolerance | beam position and size |
| `neff` | value, tolerance | index of the launched profile from its phase along z |
| `conserved` | tolerance | total power within the tolerance of 1 at every step |

A malformed expectation, or one naming a monitor or plane that does not exist, is reported as a failed check with its line number; the other checks still run.

## Output

`beamprop check <file>` prints `key value` lines, one `monitor` and one `plane` line each, and one `check PASS|FAIL <name> :: <detail>` line per expectation. Exit status: 0 if all checks pass, 1 if one fails, 2 if the file cannot be read or is invalid. `beamprop run <file>` adds the traces along z (`trace`), the complex output field (`out`) and a decimated intensity map (`mapx`, `map`).

## Example

    # A symmetric splitter: both arms must carry the same power.
    # Checked by symmetry.
    title Y-branch
    window width=24 length=70
    guide straight x=0 width=0.5 from=0 to=10
    guide taper x=0 w0=0.5 w1=1.0 from=10 to=20
    guide sbend x0=0.25 x1=1.5 width=0.5 from=20 to=60
    guide sbend x0=-0.25 x1=-1.5 width=0.5 from=20 to=60
    guide straight x=1.5 width=0.5 from=60 to=70
    guide straight x=-1.5 width=0.5 from=60 to=70
    launch mode x=0 width=0.5
    monitor upper z=70 x=1.5 width=0.5
    monitor lower z=70 x=-1.5 width=0.5
    expect ratio upper lower 1.0 1e-6
    expect power_above upper 0.45
