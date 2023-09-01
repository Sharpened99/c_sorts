add_library(comp_sorts
        comp_sorts.cpp comp_sorts.h
        sort_utils.cpp sort_utils.h
        merge_sorts.cpp merge_sorts.h
        quick_sorts.cpp quick_sorts.h
)

target_include_directories(comp_sorts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
