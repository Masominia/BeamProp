#include <cstdio>

#include "check.hpp"

int main() {
    Suite suite;
    struct Entry {
        const char* name;
        void (*run)(Suite&);
    };
    const Entry entries[] = {{"strutil", test_strutil}, {"tridiagonal", test_tridiagonal}, {"slab", test_slab}, {"layout", test_layout}, {"stepper", test_stepper},
                             {"simulate", test_simulate}, {"physics", test_physics}, {"parser", test_parser}, {"expect", test_expect}};
    for (const Entry& e : entries) {
        const int before = suite.failures, checks = suite.checks;
        e.run(suite);
        std::printf("%-12s %3d checks  %s\n", e.name, suite.checks - checks, suite.failures == before ? "ok" : "FAILED");
    }
    std::printf("%d checks, %d failures\n", suite.checks, suite.failures);
    return suite.failures == 0 ? 0 : 1;
}
