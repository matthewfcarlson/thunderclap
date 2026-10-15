struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* findNode(Node* base, Node* node) {
    Node* sentinel = (Node*)&base->parent;
    Node* p = node->parent;
    if (p != sentinel) {
        while (p->left != sentinel)
            p = p->left;
        return p;
    }
    p = node->right;
    while (p != sentinel && node == p->parent) {
        node = p;
        p = p->right;
    }
    return p;
}