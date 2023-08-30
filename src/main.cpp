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

using comparison_sorts::bubble_sort;
using comparison_sorts::quick_sort;

typedef uint64_t ulong;


[[maybe_unused]] void print_array(const uint *array, const uint len) {
    auto max_digits = num_digits(max_value(array, len));

    for (uint i = 0; i < len; i++) {
        string num_as_str = to_string(array[i]);
        cout << left_pad(num_as_str, ' ', max_digits) << "; ";
    }
    cout << endl;
}

bool is_sorted(uint *array, uint len) {
    for (uint i = 0; i < len - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}


uint rnd_uint32() {
    static uint MAX_RAN_VALUE = 0xFFFFFF;
    static auto engine = std::mt19937(
            (uint) std::chrono::high_resolution_clock::now().time_since_epoch().count());
    static auto dist = std::uniform_int_distribution<unsigned int>((uint) 0, MAX_RAN_VALUE);
    return dist(engine);
}

void fill_with_random(uint *array, const uint len) {
    for (uint i = 0; i < len; i++) {
        array[i] = rnd_uint32();
    }
}

template<typename Func>
ulong time_function(Func f) {
    auto start = std::chrono::system_clock::now();

    f();

    auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

ulong time_sort(void f(uint *, uint), uint len) {
    auto sorting_array = new uint[len];
    fill_with_random(sorting_array, len);

    auto duration = time_function([&]() { f(sorting_array, len); });

    // did it sort correctly?
    if (!is_sorted(sorting_array, len)) {
        cerr << "Sort did not sort. Exiting..." << endl;
        cerr << "function pointer is " << f << endl;
        exit(EXIT_FAILURE);
    }
    return duration;
}


int main() {
    const uint ARRAY_LEN = 50000;

    // unittest::run_all_tests();


    cout << "Bubble sort took " << to_string(time_sort(bubble_sort, ARRAY_LEN)) << "ms to sort " << to_string(ARRAY_LEN)
         << " elements."
         << endl;
    cout << "Quicksort took " << to_string(time_sort(quick_sort, ARRAY_LEN)) << "ms to sort " << to_string(ARRAY_LEN)
         << " elements." << endl;

    return 0;
}
