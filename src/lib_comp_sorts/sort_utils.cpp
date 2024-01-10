#include "sort_utils.h"

namespace sort_utils {
inline void swap(uint32_t *array, const uint32_t first_index,
                 const uint32_t second_index) {
    uint32_t temp       = array[first_index];
    array[first_index]  = array[second_index];
    array[second_index] = temp;
}
}  // namespace sort_utils
