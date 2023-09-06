#include "arena_allocator.h"

#include <cstdlib>
#include <iostream>

#include "trees.h"

namespace sort_utils::allocators {

LinArenaAllocator::LinArenaAllocator(uint32_t array_len) : m_size(array_len) {
    uint64_t size = array_len * sizeof(sort_utils::TreeNode);
    m_region = static_cast<std::byte*>(
            malloc(size));
    if (!m_region) {
        std::cerr << "malloc failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_offset = m_region;
}

template<typename T>
T* LinArenaAllocator::alloc() {
    if (m_region + m_size < m_offset) {
        std::cerr << "Ran out of space in arena." << std::endl;
        exit(EXIT_FAILURE);
    }
    void* ptr = static_cast<void*>(m_offset);
    m_offset += sizeof(T);
    return static_cast<T*>(ptr);
}

LinArenaAllocator::~LinArenaAllocator() {
    free(m_region);
}

}  // namespace sort_utils::allocators
