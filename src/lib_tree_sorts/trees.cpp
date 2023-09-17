#include "trees.h"

namespace sort_utils::tree_func {

TreeNode* tree_insert(TreeNode* root, TreeNode* new_node) {
    if (!root) {
        return new_node;
    }
    if (new_node->val < root->val) {
        root->lhs = tree_insert(root->lhs, new_node);
    } else {
        root->rhs = tree_insert(root->rhs, new_node);
    }

    return root;
}

void store_to_array(TreeNode* root, uint32_t* array, uint32_t& next_index) {
    if (!root) {
        return;
    }

    if (root->lhs) {
        store_to_array(root->lhs, array, next_index);
    }

    array[next_index++] = root->val;

    if (root->rhs) {
        store_to_array(root->rhs, array, next_index);
    }
}

}  // namespace sort_utils::tree_func
