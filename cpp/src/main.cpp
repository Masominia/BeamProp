// Command line front end.
//
//   beamprop run <layout>     results, checks, traces along z, the output field and the intensity map
//   beamprop check <layout>   results and checks; exit status 1 if a check fails
//
// Output lines: `key value`, `monitor <name> <z> <power> <phase>`, `plane <name> <z> <total> <centroid> <radius>
// <peak x>`, `check <PASS|FAIL> <name> :: <detail>`, and for `run`: `trace <z> <total> <in launch profile>`,
// `out <x> <re> <im>`, `mapx <x...>` and `map <z> <intensity...>`.
#include <cstdio>
#include <exception>
#include <string>

#include "beamprop/expect.hpp"
#include "beamprop/parser.hpp"

int main(int argc, char** argv) {
    const std::string command = argc > 1 ? argv[1] : "";
    if (argc != 3 || (command != "run" && command != "check")) {
        std::fprintf(stderr, "usage: beamprop <run|check> <layout file>\n");
        return 2;
    }
    try {
        const bp::Layout l = bp::load_layout(argv[2]);
        const bp::Result r = bp::simulate(l, command == "run");
        std::printf("title %s\n", l.title.c_str());
        std::printf("wavelength %.6f\nnx %d\nnz %d\ndx %.6f\ndz %.6f\nreference %.10f\nn_track %.10f\n", l.wavelength, r.nx, r.nz, l.dx, l.dz, r.n0, r.n_track);
        std::printf("total_out %.10f\nin_launch_out %.10f\n", r.total.back(), r.in_launch.back());
        for (const bp::MonitorResult& m : r.monitors) std::printf("monitor %s %.6f %.10f %.8f\n", m.name.c_str(), m.z, m.power, m.phase);
        for (const bp::PlaneResult& p : r.planes) std::printf("plane %s %.6f %.10f %.8f %.8f %.6f\n", p.name.c_str(), p.z, p.total, p.centroid, p.radius, p.peak_x);
        int failed = 0;
        for (const bp::Check& c : bp::evaluate(l, r)) {
            std::printf("check %s %s :: %s\n", c.pass ? "PASS" : "FAIL", c.name.c_str(), c.detail.c_str());
            failed += c.pass ? 0 : 1;
        }
        if (command == "check") return failed == 0 ? 0 : 1;
        const std::size_t stride = r.z.size() > 600 ? r.z.size() / 600 : 1;
        for (std::size_t i = 0; i < r.z.size(); i += stride) std::printf("trace %.6f %.10f %.10f\n", r.z[i], r.total[i], r.in_launch[i]);
        for (int i = 0; i < r.nx; ++i) std::printf("out %.6f %.10e %.10e\n", l.x(i), r.output[i].real(), r.output[i].imag());
        std::printf("mapx");
        for (double x : r.map_x) std::printf(" %.5f", x);
        std::printf("\n");
        for (std::size_t row = 0; row < r.map.size(); ++row) {
            std::printf("map %.5f", r.map_z[row]);
            for (double v : r.map[row]) std::printf(" %.4e", v);
            std::printf("\n");
        }
        return 0;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "beamprop: %s\n", e.what());
        return 2;
    }
}
