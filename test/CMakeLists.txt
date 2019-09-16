add_executable(test_month
    test_month.cpp
    ../month.cpp
    test_base.cpp)
add_test(MonthTest test_month)

add_executable(test_csvreader
    test_csvreader.cpp
    ../csvreader.cpp
    test_base.cpp)
add_test(CSVReaderTest test_csvreader)
