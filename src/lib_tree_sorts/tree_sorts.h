#ifndef C_SORTS_TREE_SORTS_H
#define C_SORTS_TREE_SORTS_H

#include <cstdint>

namespace tree_sorts {

/**
 * Builds a binary search tree to sort the array \n
 * stable? \n
 * builds a binary search tree O(n) \n
 * avg. O(n*log(n))
 * @param array array to be sorted
 * @param len length of the array
 */
void tree_sort(uint32_t* array, uint32_t len);
}  // namespace tree_sorts

#endif  // C_SORTS_TREE_SORTS_H
