#include "../month.h"

#include "catch.hpp"

using namespace wildland_firesim;

TEST_CASE("Valid month names are parsed correctly", "[month]")
{
    static constexpr struct TestMapEntry {
        const char *name;
        Month month;
    } months[] {
        { "JAN", Month::January },
        { "jan", Month::January },
        { "FEB", Month::February },
        { "feb", Month::February},
        { "MAR", Month::March },
        { "mar", Month::March },
        { "APR", Month::April },
        { "apr", Month::April },
        { "MAY", Month::May },
        { "may", Month::May },
        { "JUN", Month::June },
        { "jun", Month::June },
        { "JUL", Month::July },
        { "jul", Month::July },
        { "AUG", Month::August },
        { "aug", Month::August },
        { "SEP", Month::September },
        { "sep", Month::September },
        { "OCT", Month::October },
        { "oct", Month::October },
        { "NOV", Month::November },
        { "nov", Month::November },
        { "DEC", Month::December }
    };

    for (const auto &mapping : months) {
        SECTION("parsing is successful and yields the correct result") {
            const auto res = stringToMonth(mapping.name);
            CHECK(res.success);
            CHECK(res.value == mapping.month);
        }
    }
}

TEST_CASE("Parse errors on invalid month names are handled", "[month]")
{
    static constexpr const char *inputs[] = {
        "ja",
        "january",
        "",
        "\x00",
        "\xff",
        "\xff\x00\ff\x00",
        "\xf0\x9f\x92\xa9"
    };

    for (const auto *input : inputs) {
        const auto res = stringToMonth(input);
        CHECK(!res.success);
    }
}
