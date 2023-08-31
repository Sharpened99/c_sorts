#include "sorts.h"


#include "utils.h"

namespace comparison_sorts {
    void swap(uint32_t *array, uint32_t first_index, uint32_t second_index);

    void bubble_sort(uint32_t *array, uint32_t len) {
        bool swapped;
        do {
            swapped = false;
            for (uint32_t i = 0; i < len - 1; i++) {
                if (array[i] > array[i + 1]) {
                    swap(array, i, i + 1);
                    swapped = true;
                }
            }
            len--;
        } while (swapped);
    }

    // partition the array and return pivot index
    uint32_t quick_sort_partition(uint32_t *array, const uint32_t len, const uint32_t pivot) {
        uint32_t swap_index = 0;
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
        if (array[len] < array[0]) {
            swap(array, 0, len - 1);
        }
        if (array[mid_index] < array[len - 1]) {
            swap(array, mid_index, len - 1);
        }
        uint32_t pivot = array[len - 1];

        //partitioning
        uint32_t pivot_index = quick_sort_partition(array, len, pivot);

        // Recursively sort partitions
        quick_sort(array, pivot_index);
        quick_sort(array + pivot_index + 1, len - pivot_index - 1);
    }

    void merge_sort_td_merge(uint32_t *array, const uint32_t len, uint32_t *worker_array) {
        uint32_t half = len / 2;
        uint32_t i_left = 0;
        uint32_t i_right = half;
        uint32_t i_worker = 0;

        // first merge
        while (i_left < half && i_right < len) {
            if (array[i_left] < array[i_right]) {
                worker_array[i_worker] = array[i_left++];
            } else {
                worker_array[i_worker] = array[i_right++];
            }
            i_worker++;
        }
        // leftovers
        while (i_left < half) {
            worker_array[i_worker++] = array[i_left++];
        }
        while (i_right < len) {
            worker_array[i_worker++] = array[i_right++];
        }

        // copy to original array
        for (int i = 0; i < len; i++) {
            array[i] = worker_array[i];
        }
    }

    void merge_sort_td(uint32_t *array, const uint32_t len, uint32_t *worker_array) {
        // base case
        if (len < 2) {
            return;
        }

        // recursively sort each half
        uint32_t half = len / 2;
        merge_sort_td(array, half, worker_array);
        merge_sort_td(array + half, len - half, worker_array);

        // merge halfs together
        merge_sort_td_merge(array, len, worker_array);
    }

    void merge_sort_td(uint32_t *array, const uint32_t len) {
        merge_sort_td(array, len, new uint32_t[len]);
    }

    void merge_sort_bu_merge(const uint32_t *array, const uint32_t start_index, const uint32_t block_size,
                             const uint32_t len, uint32_t *worker_array) {
        uint32_t i_left = start_index;
        uint32_t left_end = i_left + block_size;
        uint32_t i_right = start_index + block_size;
        uint32_t right_end = i_right + block_size;
        uint32_t i_worker = start_index;

        // first merge
        while (i_left < left_end && i_right < right_end && i_right < len) {
            if (array[i_left] < array[i_right]) {
                worker_array[i_worker] = array[i_left++];
            } else {
                worker_array[i_worker] = array[i_right++];
            }
            i_worker++;
        }
        // leftovers
        while (i_left < left_end) {
            worker_array[i_worker++] = array[i_left++];
        }
        while (i_right < right_end && i_right < len) {
            worker_array[i_worker++] = array[i_right++];
        }
    }

    void merge_sort_bu(uint32_t *array, const uint32_t len, uint32_t *worker_array) {
        if (len < 2) {
            return;
        }
        uint32_t block_size = 1;

        while (block_size <= len) {
            for (uint32_t offset = 0; offset < len; offset += 2 * block_size) {
                merge_sort_bu_merge(array, offset, block_size, len, worker_array);
            }
            // copy to original array
            for (int i = 0; i < len; i++) {
                array[i] = worker_array[i];
            }
            block_size *= 2;
        }
    }

    void merge_sort_bu(uint32_t *array, const uint32_t len) {
        merge_sort_bu(array, len, new uint32_t[len]);
    }

    /**
     * swaps the values of the given array at the given indices
     * @param array
     * @param first_index
     * @param second_index
     */
    void swap(uint32_t *array, const uint32_t first_index, const uint32_t second_index) {
        uint32_t temp = array[first_index];
        array[first_index] = array[second_index];
        array[second_index] = temp;
    }
}