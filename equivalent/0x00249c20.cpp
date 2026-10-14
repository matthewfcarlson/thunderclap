// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_00249c20 @ 0x00249c20
struct Node { Node *left; Node *right; Node *parent; int color; };
struct Tree { Node *root; Node sentinel; };
struct Entry { int value; Node node; };
extern Node* __cdecl FUN_00247d10(Tree*,Node*);
extern void __cdecl FUN_00248d40(Tree*,Node*);
void __cdecl FUN_00249c20(Tree* tree, Entry* entry) {
    Node* node = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (node->left != nil && node->right != nil)
        removed = FUN_00247d10(tree,node);
    else
        removed = node;
    Node* child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool rebalance = removed->color == 0;
    if (removed != node) {
        removed->parent = node->parent;
        removed->left = node->left;
        removed->right = node->right;
        removed->color = node->color;
        parent = removed->parent;
        if (parent != nil) {
            if (parent->left == node) parent->left = removed;
            else parent->right = removed;
        } else tree->root = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (rebalance) FUN_00248d40(tree,child);
}
