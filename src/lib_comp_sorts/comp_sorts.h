#ifndef C_SORTS_COMP_SORTS_H
#define C_SORTS_COMP_SORTS_H

#include <cstdint>

namespace comparison_sorts {

    /**
     * Bubble sort (improved) \n
     * stable \n
     * in-place \n
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void bubble_sort(uint32_t *array, uint32_t len);

    /**
     * Selection Sort (Minimum side only) \n
     * stable \n
     * in-place \n
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void selection_sort_min(uint32_t *array, uint32_t len);

    /**
    * Selection Sort (Minimum and maximum side) \n
    * stable \n
    * in-place \n
    * avg. O(n²)
    * @param array array to be sorted
    * @param len length of the array
    */
    void selection_sort_minmax(uint32_t *array, uint32_t len);

    /**
     * Insertion sort \n
     * stable \n
     * in-place \n
     * avg. O(n²)
     * @param array array to be sorted
     * @param len length of the array
     */
    void insertion_sort(uint32_t *array, uint32_t len);
}


#endif //C_SORTS_COMP_SORTS_H
