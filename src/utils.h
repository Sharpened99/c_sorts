#ifndef C_SORTS_UTILS_H
#define C_SORTS_UTILS_H

#include <string>

typedef unsigned int uint;

uint max_value(const uint *array, uint len);

uint num_digits(uint num);

std::string &left_pad(std::string &s, char c, uint to_len);

#endif //C_SORTS_UTILS_H
