#include "tree_sorts.h"

#include "arena_allocator.h"
#include "trees.h"

using sort_utils::allocators::LinArenaAllocator;
using sort_utils::TreeNode;

namespace tree_sorts {

void tree_sort(uint32_t *array, uint32_t len) {
    if (len < 1) {
        return;
    }

    auto arena_a = LinArenaAllocator(len);

    auto root = TreeNode(array[0]);

    for (uint32_t i = 1; i < len; i++) {
        auto node = arena_a.alloc<TreeNode>();
        node->val = array[i];
        root.insert(node);
    }

    root.print_to_array(array);
}

}  // namespace tree_sorts
