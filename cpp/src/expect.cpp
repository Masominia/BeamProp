#include "beamprop/expect.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>

#include "beamprop/strutil.hpp"

namespace bp {

static std::string fmt(const char* pattern, double a, double b, double c) {
    char buffer[200];
    std::snprintf(buffer, sizeof buffer, pattern, a, b, c);
    return buffer;
}

static void arity(const Expectation& e, std::size_t count) {
    if (e.args.size() != count) throw std::invalid_argument("'" + e.kind + "' takes " + std::to_string(count) + " argument" + (count == 1 ? "" : "s"));
}

static const MonitorResult& monitor(const Result& r, const std::string& name) {
    for (const MonitorResult& m : r.monitors)
        if (m.name == name) return m;
    throw std::invalid_argument("no monitor named '" + name + "'");
}

static const PlaneResult& plane(const Result& r, const std::string& name) {
    for (const PlaneResult& p : r.planes)
        if (p.name == name) return p;
    throw std::invalid_argument("no plane named '" + name + "'");
}

static Check near(double got, double want, double tol) { return {"", std::fabs(got - want) <= tol, fmt("%.8f, expected %.8f, off by %.2e", got, want, got - want)}; }

static Check one(const Result& r, const Expectation& e) {
    const std::string& k = e.kind;
    auto num = [&](std::size_t i) { return to_number(e.args[i]); };
    if (k == "power") return arity(e, 3), near(monitor(r, e.args[0]).power, num(1), num(2));
    if (k == "power_db") return arity(e, 3), near(10.0 * std::log10(std::fmax(monitor(r, e.args[0]).power, 1e-30)), num(1), num(2));
    if (k == "power_above" || k == "power_below") {
        arity(e, 2);
        const double p = monitor(r, e.args[0]).power, bound = num(1);
        return {"", k == "power_above" ? p >= bound : p <= bound, fmt("%.6f against the bound %.6f (margin %.2e)", p, bound, p - bound)};
    }
    if (k == "sum") return arity(e, 4), near(monitor(r, e.args[0]).power + monitor(r, e.args[1]).power, num(2), num(3));
    if (k == "ratio") return arity(e, 4), near(monitor(r, e.args[0]).power / std::fmax(monitor(r, e.args[1]).power, 1e-300), num(2), num(3));
    if (k == "total") return arity(e, 3), near(plane(r, e.args[0]).total, num(1), num(2));
    if (k == "centroid") return arity(e, 3), near(plane(r, e.args[0]).centroid, num(1), num(2));
    if (k == "radius") return arity(e, 3), near(plane(r, e.args[0]).radius, num(1), num(2));
    if (k == "neff") return arity(e, 2), near(r.n_track, num(0), num(1));
    if (k == "conserved") {
        arity(e, 1);
        double worst = 0.0;
        for (double t : r.total) worst = std::fmax(worst, std::fabs(t - 1.0));
        return {"", worst <= num(0), fmt("largest change of the total power %.2e over %.0f steps of %.3f um", worst, static_cast<double>(r.nz), r.z.size() > 1 ? r.z[1] : 0.0)};
    }
    throw std::invalid_argument("unknown expectation '" + k + "'");
}

std::vector<Check> evaluate(const Layout& layout, const Result& result) {
    std::vector<Check> out;
    for (const Expectation& e : layout.expectations) {
        std::string name = e.kind;
        for (const std::string& arg : e.args) name += " " + arg;
        Check c;
        try {
            c = one(result, e);
        } catch (const std::invalid_argument& err) {
            c = {"", false, "line " + std::to_string(e.line) + ": " + err.what()};
        }
        c.name = name;
        out.push_back(c);
    }
    return out;
}

}  // namespace bp
