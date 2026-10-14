// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0024a1c0 @ 0x0024a1c0
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree { Node* root; Node sentinel; };
struct Entry { int data; Node node; };
Node* __cdecl FUN_00248370(Tree*, Node*);
void __cdecl FUN_00249200(Tree*, Node*);
void __cdecl FUN_0024a1c0(Tree* tree, Entry* entry) {
    Node* target = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (target->left != nil && target->right != nil)
        removed = FUN_00248370(tree, target);
    else removed = target;
    Node* replacement = removed->left;
    if (replacement == nil) replacement = removed->right;
    replacement->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = replacement;
    else if (parent->left == removed) parent->left = replacement;
    else parent->right = replacement;
    bool fix = removed->color == 0;
    if (removed != target) {
        removed->parent = target->parent;
        removed->left = target->left;
        removed->right = target->right;
        removed->color = target->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == target) parent->left = removed;
        else parent->right = removed;
        if (removed->left != nil) removed->left->parent = removed;
        if (removed->right->parent != nil) removed->right->parent = removed;
    }
    if (fix) FUN_00249200(tree, replacement);
}
