#include "quick_sorts.h"


#include "sort_utils.h"

using sort_utils::swap;

namespace comparison_sorts {
    // partition the array and return pivot index
    uint32_t quick_sort_partition(uint32_t *array, const uint32_t len) {
        uint32_t swap_index = 0;
        uint32_t pivot = array[len - 1];
        // Look up other partitioning methods, maybe there are improvements?
        for (uint32_t i_s = 0; i_s < len; i_s++) {
            if (array[i_s] < pivot) {
                swap(array, i_s, swap_index);
                swap_index++;
            }
        }
        swap(array, swap_index, len - 1);

        // this is the index of the pivot element
        return swap_index;
    }

    void quick_sort(uint32_t *array, const uint32_t len) {
        // Return if nothing to do
        if (len < 2) {
            return;
        }

        // Find pivot element in first, last and middle index of array
        // Bring pivot to end of array
        uint32_t mid_index = len / 2;

        if (array[mid_index] < array[0]) {
            swap(array, 0, mid_index);
        }
        if (array[len - 1] < array[0]) {
            swap(array, 0, len - 1);
        }
        if (array[mid_index] < array[len - 1]) {
            swap(array, mid_index, len - 1);
        }
        uint32_t pivot = array[len - 1];

        //partitioning
        uint32_t pivot_index = quick_sort_partition(array, len);

        // Recursively sort partitions
        quick_sort(array, pivot_index);
        quick_sort(array + pivot_index + 1, len - pivot_index - 1);
    }
}