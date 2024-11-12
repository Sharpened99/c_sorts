#ifndef C_SORTS_QUICK_SORTS_H
#define C_SORTS_QUICK_SORTS_H

#include <cstdint>

namespace comparison_sorts {
/**
 * Quicksort with pivot chosen as median from start, middle and end of array \n
 * stable \n
 * in-place \n
 * avg. O(n*log(n))
 * @param array array to be sorted
 * @param len length of the array
 */
void quick_sort(uint32_t *array, uint32_t len);
}  // namespace comparison_sorts
#endif  // C_SORTS_QUICK_SORTS_H
