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

    void selection_sort_min(uint32_t *array, uint32_t len) {
        uint32_t swap_index = 0;

        while (swap_index < len) {
            uint32_t search_index = swap_index + 1;
            uint32_t min_index = swap_index;

            while (search_index < len) {
                min_index = array[search_index] < array[min_index] ? search_index : min_index;
                search_index++;
            }
            if (swap_index != min_index) {
                swap(array, swap_index, min_index);
            }
            swap_index++;
        }
    }

    void selection_sort_minmax(uint32_t *array, uint32_t len) {
        for (uint32_t sorted_before = 0, sorted_after = len - 1;
             sorted_before < sorted_after; sorted_before++, sorted_after--) {
            uint32_t min_found_value = array[sorted_before], max_found_value = array[sorted_before];
            uint32_t min_found_i = sorted_before, max_found_i = sorted_before;
            for (uint32_t search_i = sorted_before; search_i <= sorted_after; search_i++) {
                uint32_t cmp_value = array[search_i];
                if (cmp_value > max_found_value) {
                    max_found_value = array[search_i];
                    max_found_i = search_i;
                } else if (cmp_value < min_found_value) {
                    min_found_value = array[search_i];
                    min_found_i = search_i;
                }
            }

            // shifting the min_found_value.
            swap(array, sorted_before, min_found_i);

            // Shifting the max_found_value. The equal condition
            // happens if we shifted the max_found_value to array[min_found_i]
            // in the previous swap.
            if (array[min_found_i] == max_found_value) {
                swap(array, sorted_after, min_found_i);
            } else {
                swap(array, sorted_after, max_found_i);
            }
        }
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