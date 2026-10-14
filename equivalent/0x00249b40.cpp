// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 30/30)
// FUN_00249b40 @ 0x00249b40
struct Entry {
    Entry *next;
    char pad04[8];
    void *value;
};

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int pad0c;
    Entry *entries;
};

struct Tree {
    char pad00[0x18];
    TreeNode *root;
    TreeNode nil;
};

bool FUN_00249b40(Tree *tree)
{
    TreeNode *end = &tree->nil;
    char found = 0;
    TreeNode *cur = tree->root;
    if (cur != end) {
        while (cur->left != end)
            cur = cur->left;
        do {
            for (Entry *e = cur->entries; e != 0; e = e->next) {
                if (e->value != 0)
                    found = 1;
            }
            TreeNode *next = cur->right;
            if (next != end) {
                while (next->left != end)
                    next = next->left;
            } else {
                TreeNode *from = cur;
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
