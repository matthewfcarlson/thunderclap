struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char unused[4];
    Node sentinel;
};
Node* __cdecl FUN_002439c0(Tree* tree, Node* node) {
    Node* nil = &tree->sentinel;
    Node* next = node->parent;
    if (next != nil) {
        while (next->left != nil)
            next = next->left;
    } else {
        next = node->right;
        while (next != nil && node == next->parent) {
            node = next;
            next = next->right;
        }
    }
    return next;
}