#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

using std::cerr;
using std::cout;
using std::endl;
using std::make_pair;
using std::string;
using std::to_string;

#include "comp_sorts.h"
#include "merge_sorts.h"
#include "quick_sorts.h"
#include "radix_sort.h"
#include "test.h"
#include "tree_sorts.h"
#include "utils.h"

using comparison_sorts::bubble_sort;
using comparison_sorts::insertion_sort;
using comparison_sorts::merge_sort_bu;
using comparison_sorts::merge_sort_td;
using comparison_sorts::quick_sort;
using comparison_sorts::select_sort_min;
using comparison_sorts::select_sort_minmax;
using distribution_sorts::radix_sort_lsd_16;
using tree_sorts::tree_sort;

//-----------------------------------------------------------------------------

uint32_t MAX_RAN_VALUE;  // Set depending on build type

std::vector<std::pair<string, void (*)(uint32_t *, const uint32_t)>>
        sorts_list = {
                make_pair(string("Improved Bubble sort"), bubble_sort),
                make_pair(string("Selection Sort Min"), select_sort_min),
                make_pair(string("Selection Sort MinMax"), select_sort_minmax),
                make_pair(string("Insertion sort"), insertion_sort),
                make_pair(string("Quicksort"), quick_sort),
                make_pair(string("Top-Down Merge sort"), merge_sort_td),
                make_pair(string("Bottom-Up Merge sort"), merge_sort_bu),
                make_pair(string("Tree Sort"), tree_sort),
                make_pair(string("LSD Radix Sort Base 16"), radix_sort_lsd_16),
};  // Put all future algorithms in this list

//-----------------------------------------------------------------------------

[[maybe_unused]] string array_to_string(const uint32_t *array,
                                        const uint32_t len) {
    auto stream     = std::stringstream();
    auto max_digits = num_digits(max_value(array, len));

    for (uint32_t i = 0; i < len; i++) {
        string num_as_str = to_string(array[i]);
        stream << left_pad(num_as_str, ' ', max_digits) << "; ";
    }
    return std::move(stream.str());
}

bool is_sorted(const uint32_t *array, const uint32_t len) {
    for (uint32_t i = 0; i < len - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

uint32_t rnd_uint32_t(const uint32_t max_value) {
    static auto engine = std::mt19937(
            (uint32_t) std::chrono::high_resolution_clock::now()
                    .time_since_epoch()
                    .count());
    static auto dist = std::uniform_int_distribution<unsigned int>((uint32_t) 0,
                                                                   max_value);
    return dist(engine);
}

void fill_with_random(uint32_t *array, const uint32_t len) {
    for (uint32_t i = 0; i < len; i++) {
        array[i] = rnd_uint32_t(MAX_RAN_VALUE);
    }
}

template<typename Func>
uint64_t time_function(Func f) {
    const auto start = std::chrono::system_clock::now();

    f();

    const auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();
}

uint32_t *copy_array(uint32_t *dst, const uint32_t *src, const uint32_t len) {
    for (uint32_t i = 0; i < len; i++) { dst[i] = src[i]; }
    return dst;
}

uint64_t time_sort(const string &name,
                   void sort_function(uint32_t *, const uint32_t),
                   const uint32_t len) {
    uint32_t sorting_array[len];
    fill_with_random(sorting_array, len);

#ifdef DEBUG_BUILD
    uint32_t array_copy[len];
    copy_array(array_copy, sorting_array, len);
#endif

    auto duration = time_function([&]() { sort_function(sorting_array, len); });

    // did it sort correctly?
    if (!is_sorted(sorting_array, len)) {
        cerr << name << " did not the values in the correct order. Exiting..."
             << endl;
#ifdef DEBUG_BUILD
        cerr << "Starting array was:" << endl
             << array_to_string(array_copy, len) << endl;
        cerr << "Array ended up as:" << endl
             << array_to_string(sorting_array, len) << endl;
#endif
        exit(EXIT_FAILURE);
    }

    return duration;
}

void measure_sort_perf(const string &name,
                       void sort_function(uint32_t *, uint32_t),
                       const uint32_t len) {
    uint64_t duration = time_sort(name, sort_function, len);
    cout << std::right << std::setw(25) << name << " took " << std::right
         << std::setw(6) << to_string(duration) << "ms." << endl;
}

int main() {
#ifdef DEBUG_BUILD
    MAX_RAN_VALUE            = 0xFF;
    const uint32_t ARRAY_LEN = 10;
#else
    MAX_RAN_VALUE            = 0xFF'FF'FF;
    const uint32_t ARRAY_LEN = 100'000;
#endif
    unittest::run_all_tests();

    cout << endl
         << "Memory Usage of sorting array (" << ARRAY_LEN << " elements): "
         << formatted_memory_amount(ARRAY_LEN * sizeof(uint32_t)) << endl
         << endl;

    for (const auto &algorithm : sorts_list) {
        measure_sort_perf(algorithm.first, algorithm.second, ARRAY_LEN);
    }

    return 0;
}
