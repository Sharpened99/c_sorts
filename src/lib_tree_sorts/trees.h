#ifndef C_SORTS_TREES_H
#define C_SORTS_TREES_H

#include <cstdint>

namespace sort_utils {
struct TreeNode {
    uint32_t val;
    TreeNode* lhs = nullptr;
    TreeNode* rhs = nullptr;

    explicit TreeNode(uint32_t _val) {
        val = _val;
    }

    void insert(TreeNode* node);

    [[maybe_unused]] uint32_t print_to_array(uint32_t* array,
                                             uint32_t next_index = 0) const;
};  // struct TreeNode
}  // namespace sort_utils

#endif  // C_SORTS_TREES_H
