#include "beamprop/parser.hpp"

#include <fstream>
#include <set>
#include <sstream>
#include <stdexcept>

#include "beamprop/strutil.hpp"

namespace bp {

static void only(const Params& p, std::initializer_list<const char*> allowed, const std::string& owner) {
    const std::set<std::string> names(allowed.begin(), allowed.end());
    for (const auto& kv : p)
        if (!names.count(kv.first)) throw std::invalid_argument(owner + " does not have '" + kv.first + "'");
}

static Segment guide(const std::vector<std::string>& w) {
    if (w.size() < 2) throw std::invalid_argument("guide needs a shape");
    const Params p = parse_params(w, 2);
    Segment s;
    s.from = require(p, "from", "guide"), s.to = require(p, "to", "guide");
    if (w[1] == "straight") {
        only(p, {"x", "width", "from", "to"}, "guide straight");
        s.shape = Shape::Straight, s.x0 = s.x1 = get(p, "x", 0.0), s.w0 = s.w1 = require(p, "width", "guide straight");
    } else if (w[1] == "taper") {
        only(p, {"x", "w0", "w1", "from", "to"}, "guide taper");
        s.shape = Shape::Taper, s.x0 = s.x1 = get(p, "x", 0.0), s.w0 = require(p, "w0", "guide taper"), s.w1 = require(p, "w1", "guide taper");
    } else if (w[1] == "sbend" || w[1] == "line") {
        only(p, {"x0", "x1", "width", "from", "to"}, "guide " + w[1]);
        s.shape = w[1] == "sbend" ? Shape::SBend : Shape::Line;
        s.x0 = require(p, "x0", "guide " + w[1]), s.x1 = require(p, "x1", "guide " + w[1]), s.w0 = s.w1 = require(p, "width", "guide " + w[1]);
    } else {
        throw std::invalid_argument("unknown guide shape '" + w[1] + "'");
    }
    if (!(s.to > s.from)) throw std::invalid_argument("a guide needs from < to");
    if (!(s.w0 > 0.0) || !(s.w1 > 0.0)) throw std::invalid_argument("guide widths must be positive");
    return s;
}

static void statement(Layout& l, const std::string& line, const std::vector<std::string>& w, int line_number) {
    const std::string& key = w[0];
    if (key == "title") {
        l.title = line.size() > 6 ? line.substr(6) : "";
    } else if (key == "wavelength" || key == "reference") {
        if (w.size() != 2) throw std::invalid_argument(key + " takes one number");
        const double v = to_number(w[1]);
        if (!(v > 0.0)) throw std::invalid_argument(key + " must be positive");
        (key == "wavelength" ? l.wavelength : l.reference) = v;
    } else if (key == "index") {
        const Params p = parse_params(w, 1);
        only(p, {"core", "clad"}, "index");
        l.n_core = get(p, "core", l.n_core), l.n_clad = get(p, "clad", l.n_clad);
        if (!(l.n_core > l.n_clad) || !(l.n_clad >= 1.0)) throw std::invalid_argument("index needs core > clad >= 1");
    } else if (key == "grid") {
        const Params p = parse_params(w, 1);
        only(p, {"dx", "dz"}, "grid");
        l.dx = get(p, "dx", l.dx), l.dz = get(p, "dz", l.dz);
        if (!(l.dx > 0.0) || !(l.dz > 0.0)) throw std::invalid_argument("grid steps must be positive");
    } else if (key == "window") {
        const Params p = parse_params(w, 1);
        only(p, {"width", "length"}, "window");
        l.width = get(p, "width", l.width), l.length = get(p, "length", l.length);
        if (!(l.width > 0.0) || !(l.length > 0.0)) throw std::invalid_argument("the window must have a positive size");
    } else if (key == "absorber") {
        const Params p = parse_params(w, 1);
        only(p, {"width", "strength"}, "absorber");
        l.absorber_width = get(p, "width", l.absorber_width), l.absorber_strength = get(p, "strength", l.absorber_strength);
        if (l.absorber_width < 0.0 || l.absorber_strength < 0.0) throw std::invalid_argument("absorber values cannot be negative");
    } else if (key == "guide") {
        l.segments.push_back(guide(w));
    } else if (key == "launch") {
        if (w.size() < 2) throw std::invalid_argument("launch needs mode or gaussian");
        const Params p = parse_params(w, 2);
        Launch la;
        if (w[1] == "mode") {
            only(p, {"x", "width", "order"}, "launch mode");
            la.x = get(p, "x", 0.0), la.width = require(p, "width", "launch mode"), la.order = static_cast<int>(get(p, "order", 0.0));
        } else if (w[1] == "gaussian") {
            only(p, {"x", "radius", "tilt"}, "launch gaussian");
            la.gaussian = true, la.x = get(p, "x", 0.0), la.radius = require(p, "radius", "launch gaussian"), la.tilt = get(p, "tilt", 0.0);
            if (!(la.radius > 0.0)) throw std::invalid_argument("the radius must be positive");
        } else {
            throw std::invalid_argument("launch must be mode or gaussian");
        }
        l.launch = la;
    } else if (key == "monitor") {
        if (w.size() < 2 || w[1].find('=') != std::string::npos) throw std::invalid_argument("monitor needs a name");
        const Params p = parse_params(w, 2);
        only(p, {"z", "x", "width", "order"}, "monitor");
        for (const Monitor& m : l.monitors)
            if (m.name == w[1]) throw std::invalid_argument("monitor '" + w[1] + "' is defined twice");
        l.monitors.push_back({w[1], require(p, "z", "monitor"), get(p, "x", 0.0), require(p, "width", "monitor"), static_cast<int>(get(p, "order", 0.0))});
    } else if (key == "plane") {
        if (w.size() < 2 || w[1].find('=') != std::string::npos) throw std::invalid_argument("plane needs a name");
        const Params p = parse_params(w, 2);
        only(p, {"z"}, "plane");
        for (const Plane& q : l.planes)
            if (q.name == w[1]) throw std::invalid_argument("plane '" + w[1] + "' is defined twice");
        l.planes.push_back({w[1], require(p, "z", "plane")});
    } else if (key == "expect") {
        if (w.size() < 2) throw std::invalid_argument("expect needs a kind");
        l.expectations.push_back({w[1], std::vector<std::string>(w.begin() + 2, w.end()), line_number});
    } else {
        throw std::invalid_argument("unknown statement '" + key + "'");
    }
}

Layout parse_layout(std::istream& in) {
    Layout l;
    std::string raw;
    int line_number = 0;
    while (std::getline(in, raw)) {
        ++line_number;
        const std::string line = strip_comment(raw);
        if (line.empty()) continue;
        try {
            statement(l, line, split_words(line), line_number);
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("line " + std::to_string(line_number) + ": " + e.what());
        }
    }
    return l;
}

Layout parse_layout_text(const std::string& text) {
    std::istringstream in(text);
    return parse_layout(in);
}

Layout load_layout(const std::string& path) {
    std::ifstream in(path);
    if (!in) throw std::invalid_argument("cannot read " + path);
    return parse_layout(in);
}

}  // namespace bp
