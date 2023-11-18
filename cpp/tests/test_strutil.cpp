#include "beamprop/strutil.hpp"
#include "check.hpp"

void test_strutil(Suite& suite) {
    using namespace bp;
    CHECK(split_words("  guide straight  x=0 ").size() == 3);
    CHECK(strip_comment("  grid dx=0.02 # fine ") == "grid dx=0.02");
    CHECK(strip_comment("# only a comment").empty());
    CHECK_NEAR(to_number("-1.5e-1"), -0.15, 1e-15);
    CHECK_THROWS(to_number("12abc"));
    const Params p = parse_params({"grid", "dx=0.02", "dz=0.5"}, 1);
    CHECK_NEAR(get(p, "dx", 9.0), 0.02, 1e-15);
    CHECK_NEAR(get(p, "missing", 9.0), 9.0, 1e-15);
    CHECK_NEAR(require(p, "dz", "grid"), 0.5, 1e-15);
    CHECK_THROWS(require(p, "dy", "grid"));
    CHECK_THROWS(parse_params({"grid", "dx"}, 1));
}
