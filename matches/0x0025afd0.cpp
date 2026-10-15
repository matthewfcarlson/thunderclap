struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* __cdecl FUN_0025afd0(Node* head, Node* node) {
    Node* sentinel = (Node*)((char*)head + 4);
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