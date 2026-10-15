struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* __cdecl f(Node* head, Node* x) {
    Node* sentinel = (Node*)((char*)head + 4);
    Node* y = x->parent;
    if (y != sentinel) {
        while (y->left != sentinel)
            y = y->left;
        return y;
    }
    y = x->right;
    while (y != sentinel && x == y->parent) {
        x = y;
        y = y->right;
    }
    return y;
}