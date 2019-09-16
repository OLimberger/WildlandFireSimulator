#ifndef MONTH_H
#define MONTH_H

#include <string>

namespace wildland_firesim {

enum Month {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

constexpr int NumberOfMonths = 12;

struct MonthParseResult {
    Month value;
    bool success;
};

// Returns a `MonthParseResult`. If the parsing was successful, then `MonthParseResult::success` is
// `true`, else if the parsing failed it is set to `false` and the contents of
// `MonthParseResult::value` are undefined.
MonthParseResult stringToMonth(const std::string &m);

}  // namespace wildland_firesim

#endif // MONTH_H
