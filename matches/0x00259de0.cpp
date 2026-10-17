struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
Node* __cdecl FUN_00259de0(Tree* tree, Node* current) {
    Node* end = &tree->sentinel;
    Node* next = current->parent;
    if (next != end) {
        while (next->left != end)
            next = next->left;
        return next;
    }
    next = current->right;
    while (next != end && current == next->parent) {
        current = next;
        next = next->right;
    }
    return next;
}