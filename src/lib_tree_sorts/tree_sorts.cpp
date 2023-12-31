#include "tree_sorts.h"

#include "arena_allocator.h"
#include "trees.h"

using sort_utils::allocators::LinArenaAllocator;

using namespace sort_utils::tree_func;

namespace tree_sorts {

void tree_sort(uint32_t* array, uint32_t len) {
    auto a         = LinArenaAllocator(len);

    TreeNode* root = nullptr;

    for (uint32_t i = 0; i < len; i++) {
        auto* node = a.alloc<TreeNode>();
        node->val  = array[i];
        root       = tree_insert(root, node);
    }
    uint32_t i = 0;
    store_to_array(root, array, i);
}

}  // namespace tree_sorts
