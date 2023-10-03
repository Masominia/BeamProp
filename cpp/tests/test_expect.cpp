#include "beamprop/expect.hpp"
#include "beamprop/parser.hpp"
#include "check.hpp"

static std::vector<bp::Check> run(const std::string& text) {
    const bp::Layout l = bp::parse_layout_text(
        "window width=14 length=20\nguide straight x=-0.35 width=0.5 from=0 to=20\nguide straight x=0.35 width=0.5 from=0 to=20\nlaunch mode x=-0.35 width=0.5\n"
        "monitor bar z=20 x=-0.35 width=0.5\nmonitor cross z=20 x=0.35 width=0.5\nplane end z=20\n" + text);
    return bp::evaluate(l, bp::simulate(l, false));
}

void test_expect(Suite& suite) {
    const auto c = run("expect power bar 0.5 0.5\nexpect power bar 2 0.1\nexpect power_above cross 0.01\nexpect power_below cross 0.01\n");
    CHECK(c.size() == 4);
    CHECK(c[0].pass && !c[1].pass && c[2].pass && !c[3].pass);
    CHECK(c[0].name == "power bar 0.5 0.5");

    const auto all = run("expect power_db bar -3 40\nexpect sum bar cross 1.0 0.01\nexpect ratio bar cross 1 1e9\nexpect total end 1.0 1e-4\nexpect centroid end 0 0.4\n"
                         "expect radius end 0.8 0.6\nexpect neff 2.63 0.05\nexpect conserved 1e-4\n");
    CHECK(all.size() == 8);
    for (const auto& check : all) CHECK(check.pass);

    const auto bad = run("expect power bar 0.5\nexpect wobble 1 2\nexpect power bar abc 1\nexpect power nowhere 0.5 0.1\nexpect total nowhere 1 0.1\nexpect conserved\n");
    CHECK(bad.size() == 6);
    for (const auto& check : bad) CHECK(!check.pass);
    CHECK(bad[0].detail.find("line 8") != std::string::npos && bad[0].detail.find("takes 3 arguments") != std::string::npos);
    CHECK(bad[1].detail.find("unknown expectation") != std::string::npos);
    CHECK(bad[2].detail.find("not a number") != std::string::npos);
    CHECK(bad[3].detail.find("no monitor named 'nowhere'") != std::string::npos);
    CHECK(bad[4].detail.find("no plane named 'nowhere'") != std::string::npos);
    CHECK(bad[5].detail.find("takes 1 argument") != std::string::npos);
}
