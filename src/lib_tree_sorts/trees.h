#ifndef C_SORTS_TREES_H
#define C_SORTS_TREES_H

#include <cstdint>

namespace sort_utils {
struct TreeNode {
    uint32_t val;
    struct TreeNode* lhs = nullptr;
    struct TreeNode* rhs = nullptr;

    explicit TreeNode(uint32_t _val) {
        val = _val;
    }
};  // struct TreeNode

namespace tree_func {

    TreeNode* tree_insert(TreeNode* root, TreeNode* new_node);

    void store_to_array(TreeNode* root, uint32_t* array, uint32_t& next_index);
}  // namespace tree_func
}  // namespace sort_utils

#endif  // C_SORTS_TREES_H
