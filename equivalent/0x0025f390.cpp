// STATUS: equivalent (tools/equiv.py level 3: 880 inputs, branch coverage 24/24)
// FUN_0025f390 @ 0x0025f390
struct Node { Node* left; Node* right; Node* parent; int color; };
struct Tree { Node* root; Node sentinel; };
struct Entry { int value; Node node; };
Node* __cdecl FUN_0025e9b0(Tree*, Node*);
void __cdecl FUN_0025e9f0(Tree*, Node*);
void __cdecl FUN_0025f390(Tree* tree, Entry* entry) {
    Node* target = &entry->node;
    Node* nil = &tree->sentinel;
    Node* removed;
    if (target->left == nil || target->right == nil) removed = target;
    else removed = FUN_0025e9b0(tree, target);
    Node* child = removed->left;
    if (child == nil) child = removed->right;
    child->parent = removed->parent;
    Node* parent = removed->parent;
    if (parent == nil) tree->root = child;
    else if (parent->left == removed) parent->left = child;
    else parent->right = child;
    bool black = removed->color == 0;
    if (removed != target) {
        removed->parent = target->parent;
        removed->left = target->left;
        removed->right = target->right;
        removed->color = target->color;
        parent = removed->parent;
        if (parent == nil) tree->root = removed;
        else if (parent->left == target) parent->left = removed;
        else parent->right = removed;
        Node* left = removed->left;
        if (left != nil) left->parent = removed;
        Node* right = removed->right;
        if (right->parent != nil) right->parent = removed;
    }
    if (black) FUN_0025e9f0(tree, child);
}
