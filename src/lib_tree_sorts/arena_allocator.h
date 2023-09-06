#ifndef C_SORTS_ARENA_ALLOCATOR_H
#define C_SORTS_ARENA_ALLOCATOR_H

#include <cstddef>
#include <cstdint>

namespace sort_utils::allocators {

class LinArenaAllocator {
private:

    std::byte* m_region = nullptr;
    std::byte* m_offset;
    uint64_t m_size;  // size in bytes

public:

    LinArenaAllocator()                               = delete;

    LinArenaAllocator(const LinArenaAllocator& other) = delete;

    explicit LinArenaAllocator(uint32_t array_len);

    template<typename T>
    T* alloc();

    LinArenaAllocator operator=(const LinArenaAllocator& other) = delete;

    ~LinArenaAllocator();
};
}  // namespace sort_utils::allocators

#include "arena_allocator.inl"

#endif  // C_SORTS_ARENA_ALLOCATOR_H
