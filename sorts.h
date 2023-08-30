#ifndef C_SORTS_SORTS_H
#define C_SORTS_SORTS_H

typedef unsigned int uint;

namespace comparison_sorts {
    /**
     * standard bubble sort (in-place)
     * @param array
     * @param len
     */
    void bubble_sort(uint *array, uint len);

    /**
     * quick sort with pivot finding in three places
     * @param array
     * @param len
     */
    void quick_sort(uint *array, uint len);
}


#endif //C_SORTS_SORTS_H
