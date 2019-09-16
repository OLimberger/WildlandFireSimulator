// Compiling the main function of Catch2 takes quite some time. Therefore, it is only compiled once,
// here in `test_base.cpp'. All other tests should depend on `test_base.cpp'. This way,
// `test_base.o' is compiled only once and used by all other tests. This increases the turnaround
// times of quick change-and-test circles.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
