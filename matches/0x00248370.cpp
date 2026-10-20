struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
Node* __cdecl FUN_00248370(Tree* tree, Node* node) {
    Node* nil = &tree->sentinel;
    Node* next = node->parent;
    if (next != nil) {
        while (next->left != nil)
            next = next->left;
        return next;
    }
    next = node->right;
    while (next != nil && node == next->parent) {
        node = next;
        next = next->right;
    }
    return next;
}