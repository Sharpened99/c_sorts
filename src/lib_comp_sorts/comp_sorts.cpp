#include "comp_sorts.h"


#include "sort_utils.h"

using sort_utils::swap;


namespace comparison_sorts {
    void bubble_sort(uint32_t *array, uint32_t len) {
        uint32_t highest_swap_index;
        do {
            highest_swap_index = 0;
            for (uint32_t i = 0; i < len - 1; i++) {
                if (array[i] > array[i + 1]) {
                    swap(array, i, i + 1);
                    highest_swap_index = i;
                }
            }
            len = highest_swap_index + 1;
        } while (len > 1);
    }

    void insertion_sort(uint32_t *array, uint32_t len) {
        uint32_t i = 1;
        while (i < len) {
            uint32_t val = array[i];
            uint32_t j = i - 1;
            // we use j < len so when 'j' is zero and j-- wraps around to UINT32_MAX the loop ends
            while (j < len && val < array[j]) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = val;
            i++;
        }
    }
}