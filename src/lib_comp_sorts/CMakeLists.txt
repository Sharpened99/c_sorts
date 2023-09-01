add_library(comp_sorts
        sorts.cpp sorts.h
        sort_utils.cpp sort_utils.h
)

target_include_directories(comp_sorts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
