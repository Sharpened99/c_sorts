#include "test.h"

#include <iostream>
#include <array>
#include <algorithm>

using std::cerr;
using std::endl;
using std::pair;
using std::make_pair;


#include "utils.h"

namespace unittest {

    bool test_num_digits() {
        std::array<pair<uint32_t, uint32_t>, 4> test_cases = {
                make_pair<uint32_t, uint32_t>(1, 1),
                make_pair<uint32_t, uint32_t>(23, 2),
                make_pair<uint32_t, uint32_t>(532, 3),
                make_pair<uint32_t, uint32_t>(312860, 6)
        };

        return std::all_of(test_cases.begin(), test_cases.end(), [](auto test_case) {
            return num_digits(test_case.first) == test_case.second;
        });
    }

    bool test_max_value() {
        uint32_t values[9] = {123, 12, 2435, 3485, 2397479, 2384, 65342, UINT32_MAX, 3848};

        return max_value(values, 9) == UINT32_MAX;
    }

    bool test_left_pad() {
        std::array<std::string, 4> test_cases = {
                std::to_string((uint32_t) 13),
                "hey",
                std::to_string((uint32_t) 0),
                ""
        };
        return std::all_of(test_cases.begin(), test_cases.end(), [](auto test_case) {
            return left_pad(test_case, ' ', 10).length() == 10;
        });
    }

    void run_all_tests() {

        if (!test_num_digits()) {
            cerr << "num_digits test failed. Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        if (!test_max_value()) {
            cerr << "max_value test failed. Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        if (!test_left_pad()) {
            cerr << "left_pad test failed. Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "All tests passed. Continuing..." << endl;
    }
}