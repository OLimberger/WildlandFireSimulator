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

Month stringToMonth(const std::string &m);

}  // namespace wildland_firesim

#endif // MONTH_H
