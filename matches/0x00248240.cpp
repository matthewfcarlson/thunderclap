struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* __cdecl next(Node* n, Node* current) {
    Node* h = (Node*)((char*)n + 4);
    Node* p = current->parent;
    if (p != h) {
        if (p->left == h)
            return p;
        do {
            p = p->left;
        } while (p->left != h);
        return p;
    }
    p = current->right;
    while (p != h && current == p->parent) {
        current = p;
        p = p->right;
    }
    return p;
}