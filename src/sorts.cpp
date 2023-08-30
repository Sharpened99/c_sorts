#include "sorts.h"


#include "utils.h"

namespace comparison_sorts {
    void swap(uint* array, uint first_index, uint second_index);

    void bubble_sort(uint *array, uint len) {
        bool swapped = true;
        for (uint i = 0; swapped && i < len; i++) {
            swapped = false;
            for (uint j = 0; j < len - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                    swapped |= true;
                }
            }
        }
    }

    // partition the array and return pivot index
    uint quick_sort_partition(uint *array, uint len, uint pivot) {
        uint swap_index = 0;
        // Look up other partitioning methods, maybe there are improvements?
        for (uint i_s = 0; i_s < len; i_s++) {
            if (array[i_s] < pivot) {
                swap(array, i_s, swap_index);
                swap_index++;
            }
        }
        swap(array, swap_index, len - 1);

        // this is the index of the pivot element
        return swap_index;
    }

    void quick_sort(uint *array, uint len) {
        // Return if nothing to do
        if (len < 2) {
            return;
        }

        // Find pivot element in first, last and middle index of array
        // Bring pivot to end of array
        uint mid_index = len / 2;

        if (array[mid_index] < array[0]) {
            swap(array, 0, mid_index);
        }
        if (array[len] < array[0]) {
            swap(array, 0, len - 1);
        }
        if (array[mid_index] < array[len - 1]) {
            swap(array, mid_index, len - 1);
        }
        uint pivot = array[len - 1];

        //partitioning
        uint pivot_index = quick_sort_partition(array, len, pivot);

        // Recursively sort other arrays
        quick_sort(array, pivot_index);
        quick_sort(array + pivot_index + 1, len - pivot_index - 1);
    }

    /**
     * swaps the values of the given array at the given indices
     * @param array
     * @param first_index
     * @param second_index
     */
    void swap(uint *array, uint first_index, uint second_index) {
        uint temp = array[first_index];
        array[first_index] = array[second_index];
        array[second_index] = temp;
    }
}