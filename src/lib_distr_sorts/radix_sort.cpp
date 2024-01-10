#include "radix_sort.h"

#include <cstdlib>

namespace distribution_sorts {

void radix_sort_lsd_16(uint32_t* array, const uint32_t len) {
    constexpr uint32_t mask     = 0b1111;
    uint32_t shift_amount       = 0;
    auto* a                     = array;
    uint32_t worker_array[len];
    auto b                          = worker_array;

    constexpr uint32_t counters_len = 16;
    uint32_t counters[counters_len];

    while (shift_amount < sizeof(uint32_t) * 8) {
        // zero out counter array
        for (unsigned int& counter : counters) { counter = 0; }

        // count occurrences of 'digit'
        for (uint32_t i = 0; i < len; i++) {
            // put interesting 'digit' in last place
            auto shifted_val = a[i] >> shift_amount;
            auto c_index     = shifted_val bitand mask;
            counters[c_index]++;
        }

        // prefix sum
        for (uint32_t i = 1; i < counters_len; i++) {
            counters[i] += counters[i - 1];
        }

        // put values at the right place
        for (uint32_t a_i = len - 1; a_i < len; a_i--) {
            // put interesting 'digit' in last place
            auto val               = a[a_i];
            auto shifted_val       = val >> shift_amount;
            auto c_index           = shifted_val bitand mask;
            b[--counters[c_index]] = val;
        }

        // swap a and b pointer
        auto temp     = a;
        a             = b;
        b             = temp;

        shift_amount += 4;
    }
}
}  // namespace distribution_sorts
