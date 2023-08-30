#include <sstream>

#include "utils.h"

using std::string;
using std::to_string;

uint max_value(const uint *array, const uint len) {
    uint max = 0;
    for (unsigned i = 0; i < len; i++) {
        max = array[i] > max ? array[i] : max;
    }
    return max;
}

uint num_digits(uint num) {
    uint digits = 0;

    while (num) {
        digits++;
        num /= 10;
    }
    return digits;
}

std::string &left_pad(string &s, const char c, const uint to_len) {
    return s.insert(0, to_len - s.size(), c);
}