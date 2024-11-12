#ifndef ARENA_ALLOCATOR_INL
#define ARENA_ALLOCATOR_INL

#include <iostream>

namespace sort_utils::allocators {

template<typename T>
T* LinArenaAllocator::alloc() {
    if (m_region + m_size < m_offset) {
        std::cerr << "Ran out of space in arena." << std::endl;
        exit(EXIT_FAILURE);
    }

    void* ptr = m_offset;
    m_offset += sizeof(T);
    return static_cast<T*>(ptr);
}
}  // namespace sort_utils::allocators

#endif
