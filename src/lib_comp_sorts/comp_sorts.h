#ifndef C_SORTS_COMP_SORTS_H
#define C_SORTS_COMP_SORTS_H

#include <cstdint>

namespace comparison_sorts {

    /**
     * Bubble sort (improved)
     * stable
     * in-place
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void bubble_sort(uint32_t *array, uint32_t len);

    /**
     * Insertion sort
     * stable
     * in-place
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void insertion_sort(uint32_t *array, uint32_t len);
}


#endif //C_SORTS_COMP_SORTS_H
