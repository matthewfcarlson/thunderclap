// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025a160 @ 0x0025a160
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree_25a160 { Node *root; Node sentinel; };
struct Entry_25a160 { int data; Node node; };
extern Node *__cdecl FUN_00259de0(Tree_25a160 *, Node *);
extern void __cdecl FUN_00259e20(Tree_25a160 *, Node *);
void __cdecl FUN_0025a160(Tree_25a160 *tree, Entry_25a160 *entry) {
    Node *node = &entry->node;
    Node *nil = &tree->sentinel;
    Node *removed;
    if (node->left != nil && node->right != nil)
        removed = FUN_00259de0(tree, node);
    else
        removed = node;
    Node *child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node *parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool black = removed->color == 0;
    if (removed != node) {
        removed->parent = node->parent;
        removed->left = node->left;
        removed->right = node->right;
        removed->color = node->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == node) parent->left = removed;
        else parent->right = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (black) FUN_00259e20(tree, child);
}
