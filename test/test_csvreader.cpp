#include "../csvreader.h"

#include <iostream>
#include <fstream>
#include <string>

#include "catch.hpp"

namespace {

using CsvReader = wildland_firesim::csv::Reader;

constexpr const char *kWhitespace = " \t\n\r";

std::string trim(const std::string &str)
{
    if (str.empty())
        return str;

    const auto begin = str.find_first_not_of(kWhitespace);
    const auto end = str.find_last_not_of(kWhitespace);
    auto substrLength = begin - end + 1;

    return str.substr(begin, substrLength);
}

}  // namespace

TEST_CASE("CSV data is parsed correctly", "[csv]")
{
    const char *testFileName = "/tmp/test.csv";
    auto stream = std::ofstream{testFileName};

    stream << "# 1, 2, 3, 4\n"
           << "1, 2, 3, 4\n"
           << " 1, 2, 3, 4 \n"
           << "\t1,\t,2\t3,\t4\t\n"
           << "1,2,3,4\n"
           << "   # a single comment, in the middle\n"
           << " 1 , 2 , 3 , 4 \n"
           << "1\t,\t2,3 ,4\n";
    stream.close();

    auto reader = CsvReader{',', '#'};

    const auto &data = reader.parse(testFileName);

    for (const auto &line : data) {
        for (const auto &elem : line) {
            std::cout << '"' << elem << "\" ";
        }
        std::cout << "\\n\n";
    }

    CHECK(data.size() == 6);
    for (size_t i = 0; i < data.size(); ++i) {
        const auto &line = data[i];
        SECTION("row " + std::to_string(i)) {
            for (size_t j = 0; j < line.size(); ++j) {
                CHECK(trim(line[j]) == std::to_string(j + 1));
            }
        }
    }
}
