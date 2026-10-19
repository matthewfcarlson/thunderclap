// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 29/30, incomplete)
// FUN_00249b40 @ 0x00249b40
struct Entry_249b40 {
    Entry_249b40 *next;
    char pad04[8];
    void *value;
};

struct TreeNode_249b40 {
    TreeNode_249b40 *left;
    TreeNode_249b40 *right;
    TreeNode_249b40 *parent;
    int pad0c;
    Entry_249b40 *entries;
};

struct Tree_249b40 {
    char pad00[0x18];
    TreeNode_249b40 *root;
    TreeNode_249b40 nil;
};

int FUN_00249b40(Tree_249b40 *tree)
{
    TreeNode_249b40 *end = &tree->nil;
    char found = 0;
    TreeNode_249b40 *cur = tree->root;
    if (cur != end) {
        while (cur->left != end)
            cur = cur->left;
        do {
            for (Entry_249b40 *e = cur->entries; e != 0; e = e->next) {
                if (e->value != 0)
                    found = 1;
            }
            TreeNode_249b40 *next = cur->right;
            if (next != end) {
                while (next->left != end)
                    next = next->left;
            } else {
                TreeNode_249b40 *from = cur;
                next = cur->parent;
                if (next != end) {
                    while (from == next->right) {
                        from = next;
                        next = next->parent;
                        if (next == end)
                            break;
                    }
                }
            }
            cur = next;
        } while (cur != end && cur != 0);
    }
    return found == 0;
}
