#include <sstream>

#include "utils.h"

using std::string;
using std::to_string;

uint32_t max_value(const uint32_t *array, const uint32_t len) {
    uint32_t max = 0;
    for (unsigned i = 0; i < len; i++) {
        max = array[i] > max ? array[i] : max;
    }
    return max;
}

uint32_t num_digits(uint32_t num) {
    uint32_t digits = 0;

    while (num) {
        digits++;
        num /= 10;
    }
    return digits;
}

std::string &left_pad(string &s, const char c, const uint32_t to_len) {
    return s.insert(0, to_len - s.size(), c);
}