#include "month.h"

#include <cctype>

namespace wildland_firesim {
namespace {

// Returns true if the input strings `s' converted to all lower case is equal to `p'.
bool equalsIgnoreCase(const std::string &s, const char *p, size_t l)
{
    if (s.size() != l) {
        return false;
    }

    for (size_t i = 0; i < l; ++i) {
        if (std::tolower(s[i]) != p[i]) {
            return false;
        }
    }

    return true;
}

}  // namespace

MonthParseResult stringToMonth(const std::string &m)
{
    static constexpr struct NameMapping {
        const char *name;
        Month month;
    } months[] {
        { "jan", Month::January },
        { "feb", Month::February },
        { "mar", Month::March },
        { "apr", Month::April },
        { "may", Month::May },
        { "jun", Month::June },
        { "jul", Month::July },
        { "aug", Month::August },
        { "sep", Month::September },
        { "oct", Month::October },
        { "nov", Month::November },
        { "dec", Month::December }
    };

    MonthParseResult result = { Month::January, false };

    for (const auto &mapping : months) {
        if (equalsIgnoreCase(m, mapping.name, 3)) {
            result.value = mapping.month;
            result.success = true;
        }
    }

    return result; //warning if used uninitialized?!
}

}  // namespace wildland_firesim
