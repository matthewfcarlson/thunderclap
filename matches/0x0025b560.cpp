struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree {
    char pad[4];
    Node sentinel;
};
Node* __cdecl FUN_0025b560(Tree* tree, Node* node) {
    Node* current = node->parent;
    Node* end = &tree->sentinel;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        current = node->right;
        while (current != end && node == current->parent) {
            node = current;
            current = current->right;
        }
    }
    return current == end ? 0 : current;
}