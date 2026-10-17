// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 12/12)
// FUN_00248370 @ 0x00248370
struct Node { Node* left; Node* parent; Node* right; };
struct Tree { char pad[4]; Node sentinel; };
Node* __cdecl FUN_00248370(Tree* tree, Node* node) {
    Node* nil = &tree->sentinel;
    Node* next = node->parent;
    if (next != nil) {
        Node* child = next->left;
        while (child != nil) {
            next = child;
            child = next->left;
        }
        return next;
    }
    next = node->right;
    while (next != nil && node == next->parent) {
        node = next;
        next = next->right;
    }
    return next;
}