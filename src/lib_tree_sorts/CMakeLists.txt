add_library(tree_sorts
        tree_sort.cpp tree_sort.h
        heap_sorts.cpp heap_sorts.h
        arena_allocator.cpp arena_allocator.h
)


target_include_directories(tree_sorts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})