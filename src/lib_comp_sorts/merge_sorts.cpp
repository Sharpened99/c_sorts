#include "merge_sorts.h"

namespace comparison_sorts {

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
        auto worker_array = new uint32_t[len];
        merge_sort_td(array, len, worker_array);
        delete[] worker_array;
    }

    void merge_sort_bu_merge(const uint32_t *array, const uint32_t start_index, const uint32_t width,
                             const uint32_t len, uint32_t *worker_array) {
        uint32_t i_left = start_index;
        uint32_t left_end = i_left + width;
        uint32_t i_right = start_index + width;
        uint32_t right_end = i_right + width;
        uint32_t i_worker = start_index;

        // clamp to array length
        left_end = left_end < len ? left_end : len;
        right_end = right_end < len ? right_end : len;

        // first merge
        while (i_left < left_end && i_right < right_end) {
            if (array[i_left] <= array[i_right]) {
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
        while (i_right < right_end) {
            worker_array[i_worker++] = array[i_right++];
        }
    }

    void merge_sort_bu(uint32_t *array, const uint32_t len) {
        if (len < 2) {
            return;
        }
        auto worker_array = new uint32_t[len];

        for (uint32_t width = 1; width < len; width *= 2) {
            for (uint32_t offset = 0; offset < len; offset += 2 * width) {
                merge_sort_bu_merge(array, offset, width, len, worker_array);
            }
            // copy to original array
            for (int i = 0; i < len; i++) {
                array[i] = worker_array[i];
            }
        }

        delete[] worker_array;
    }
}