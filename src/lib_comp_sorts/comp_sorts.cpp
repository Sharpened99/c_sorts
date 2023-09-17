#include "comp_sorts.h"

#include "sort_utils.h"

using sort_utils::swap;

namespace comparison_sorts {

void bubble_sort(uint32_t *array, uint32_t len) {
    uint32_t max_swap_i;
    do {
        max_swap_i = 0;
        for (uint32_t i = 0; i < len - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array, i, i + 1);
                max_swap_i = i;
            }
        }
        len = max_swap_i + 1;
    } while (len > 1);
}

void select_sort_min(uint32_t *array, uint32_t len) {
    uint32_t swap_index = 0;

    while (swap_index < len) {
        uint32_t search_i = swap_index + 1;
        uint32_t min_i    = swap_index;

        while (search_i < len) {
            min_i = array[search_i] < array[min_i] ? search_i : min_i;
            search_i++;
        }
        if (swap_index != min_i) {
            swap(array, swap_index, min_i);
        }
        swap_index++;
    }
}

void select_sort_minmax(uint32_t *array, uint32_t len) {
    // s_bef = index indicating start of unsorted part
    // s_aft = index indicating end of unsorted part (inclusive)
    for (uint32_t s_bef = 0, s_aft = len - 1; s_bef < s_aft; s_bef++, s_aft--) {

        // found min / max values and their indices
        uint32_t min_val = array[s_bef];
        uint32_t max_val = array[s_bef];
        uint32_t min_i = s_bef, max_i = s_bef;

        // search unsorted part for min / max value
        for (uint32_t search_i = s_bef; search_i <= s_aft; search_i++) {
            auto cmp_value = array[search_i];
            if (cmp_value > max_val) {
                max_val = array[search_i];
                max_i   = search_i;
            } else if (cmp_value < min_val) {
                min_val = array[search_i];
                min_i   = search_i;
            }
        }

        // shifting the min_val.
        swap(array, s_bef, min_i);

        // Shifting the max_val. The equal condition
        // happens if we shifted the max_val to array[min_i]
        // in the previous swap.
        if (array[min_i] == max_val) {
            swap(array, s_aft, min_i);
        } else {
            swap(array, s_aft, max_i);
        }
    }
}

void insertion_sort(uint32_t *array, uint32_t len) {
    uint32_t i = 1;
    while (i < len) {
        uint32_t val = array[i];
        uint32_t j   = i - 1;
        // we use j < len so when 'j' is zero and j--
        // wraps around to UINT32_MAX the loop ends
        while (j < len && val < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = val;
        i++;
    }
}
}  // namespace comparison_sorts
