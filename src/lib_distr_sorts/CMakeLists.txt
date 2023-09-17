add_library(distr_sorts
        radix_sort.cpp radix_sort.h
)

target_include_directories(distr_sorts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})