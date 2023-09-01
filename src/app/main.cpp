#include <iostream>
#include <random>
#include <chrono>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::to_string;

#include "sorts.h"
#include "utils.h"
#include "test.h"

using comparison_sorts::insertion_sort;
using comparison_sorts::bubble_sort;
using comparison_sorts::quick_sort;
using comparison_sorts::merge_sort_td;
using comparison_sorts::merge_sort_bu;


[[maybe_unused]] void print_array(const uint32_t *array, const uint32_t len) {
    auto max_digits = num_digits(max_value(array, len));

    for (uint32_t i = 0; i < len; i++) {
        string num_as_str = to_string(array[i]);
        cout << left_pad(num_as_str, ' ', max_digits) << "; ";
    }
    cout << endl;
}

bool is_sorted(const uint32_t *array, const uint32_t len) {
    for (uint32_t i = 0; i < len - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}


uint32_t rnd_uint32_t() {
    static uint32_t MAX_RAN_VALUE = 0xFF;
    static auto engine = std::mt19937(
            (uint32_t) std::chrono::high_resolution_clock::now().time_since_epoch().count());
    static auto dist = std::uniform_int_distribution<unsigned int>((uint32_t) 0, MAX_RAN_VALUE);
    return dist(engine);
}

void fill_with_random(uint32_t *array, const uint32_t len) {
    for (uint32_t i = 0; i < len; i++) {
        array[i] = rnd_uint32_t();
    }
}

template<typename Func>
uint64_t time_function(Func f) {
    const auto start = std::chrono::system_clock::now();

    f();

    const auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

uint64_t time_sort(const string &name, void sort_function(uint32_t *, const uint32_t), const uint32_t len) {
    auto sorting_array = new uint32_t[len];
    fill_with_random(sorting_array, len);

    auto duration = time_function([&]() { sort_function(sorting_array, len); });

    // did it sort correctly?
    if (!is_sorted(sorting_array, len)) {
        cerr << name << " did not the values in the correct order. Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    return duration;
}

void measure_sort_perf(const string &name, void sort_function(uint32_t *, uint32_t), const uint32_t len) {
    uint64_t duration = time_sort(name, sort_function, len);
    cout << name << " took " << to_string(duration) << "ms to sort " << to_string(len)
         << " elements."
         << endl;
}


int main() {
    const uint32_t ARRAY_LEN = 100'000;
    cout << "Memory Usage of sorting array: " << formatted_memory_amount(ARRAY_LEN * sizeof(uint32_t)) << endl << endl;

    // unittest::run_all_tests();


    measure_sort_perf(string("Improved Bubble sort"), bubble_sort, ARRAY_LEN);
    measure_sort_perf(string("Insertion sort"), insertion_sort, ARRAY_LEN);
    measure_sort_perf(string("Quicksort"), quick_sort, ARRAY_LEN);
    measure_sort_perf(string("Top-Down Merge sort"), merge_sort_td, ARRAY_LEN);
    measure_sort_perf(string("Bottom-Up Merge sort"), merge_sort_bu, ARRAY_LEN);

    return 0;
}
