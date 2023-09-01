#ifndef C_SORTS_SORT_UTILS_H
#define C_SORTS_SORT_UTILS_H

#include <cstdint>

namespace sort_utils {
    /**
     * swaps the values of the given array at the given indices
     * @param array array to swap values in
     * @param first_index index of first value
     * @param second_index index of second value
     */
    void swap(uint32_t *array, uint32_t first_index, uint32_t second_index);
}

#endif //C_SORTS_SORT_UTILS_H
