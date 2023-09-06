#include "trees.h"

namespace sort_utils {

void TreeNode::insert(TreeNode *node) {
    if (node->val < val) {
        if (lhs) {
            lhs->insert(node);
            return;
        }
        lhs = node;
    } else if (rhs) {
        rhs->insert(node);
    }
    rhs = node;
}

uint32_t TreeNode::print_to_array(uint32_t *array, uint32_t next_index) const {
    if (lhs) {
        next_index = lhs->print_to_array(array, next_index);
    }
    array[next_index++] = val;
    if (rhs) {
        next_index = rhs->print_to_array(array, next_index);
    }
    return next_index;
}
}  // namespace sort_utils
