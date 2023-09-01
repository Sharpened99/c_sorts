#ifndef C_SORTS_MERGE_SORTS_H
#define C_SORTS_MERGE_SORTS_H

#include <cstdint>

namespace comparison_sorts {

    /**
     * Top-Down Mergesort \n
     * stable \n
     * extra worker array (n = len) \n
     * avg. O(n*log(n)) \n
     * @param array array to be sorted
     * @param len length of the array
     */
    void merge_sort_td(uint32_t *array, uint32_t len);

    /**
     * Bottom-Up Mergesort \n
     * stable \n
     * extra worker array (n = len) \n
     * avg. O(n*log(n)) \n
     * @param array array to be sorted
     * @param len length of the array
     */
    void merge_sort_bu(uint32_t *array, uint32_t len);
}

#endif //C_SORTS_MERGE_SORTS_H
