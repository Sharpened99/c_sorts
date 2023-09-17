#ifndef C_SORTS_UTILS_H
#define C_SORTS_UTILS_H

#include <string>

std::string formatted_memory_amount(uint64_t bytes);

uint32_t max_value(const uint32_t *array, uint32_t len);

uint32_t num_digits(uint64_t num);

std::string &left_pad(std::string &s, char c, uint32_t to_len);

#endif  // C_SORTS_UTILS_H
