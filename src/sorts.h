#ifndef C_SORTS_SORTS_H
#define C_SORTS_SORTS_H

#include <cstdint>

namespace comparison_sorts {

    /**
     * Bubble sort (improved)
     * in-place
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void bubble_sort(uint32_t *array, uint32_t len);

    /**
     * Quicksort with pivot chosen as median from start, middle and end of array
     * in-place
     * avg. O(n*log(n))
     * @param array array to be sorted
     * @param len length of the array
     */
    void quick_sort(uint32_t *array, uint32_t len);

    /**
     * Top-Down Mergesort
     * extra worker array (n = len)
     * avg. O(On*log(n))
     * @param array array to be sorted
     * @param len length of the array
     */
    void merge_sort_td(uint32_t *array, uint32_t len);
}


#endif //C_SORTS_SORTS_H
