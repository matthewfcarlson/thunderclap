struct Node {
    Node* parent;
    Node* left;
    Node* right;
};
Node* __cdecl fn(Node* x, Node* y) {
    Node* end = (Node*)&x->left;
    Node* n = y->left;
    if (n != end) {
        while (n->parent != end)
            n = n->parent;
    } else {
        n = y->right;
        while (n != end && y == n->left) {
            y = n;
            n = n->right;
        }
    }
    return n;
}