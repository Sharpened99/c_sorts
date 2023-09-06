#include "arena_allocator.h"

#include <cstdlib>
#include <iostream>

#include "trees.h"

namespace sort_utils::allocators {

LinArenaAllocator::LinArenaAllocator(uint32_t array_len)
    : m_size((array_len) * sizeof(sort_utils::TreeNode)) {
    m_region = static_cast<std::byte*>(malloc(m_size));
    if (!m_region) {
        std::cerr << "malloc failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_offset = m_region;
}

LinArenaAllocator::~LinArenaAllocator() {
    if (m_region) {
        free(m_region);
    }
}

}  // namespace sort_utils::allocators
