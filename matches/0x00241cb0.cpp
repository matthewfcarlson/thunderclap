struct Node {
    Node* left;
    Node* right;
    Node* parent;
};
Node* __cdecl FUN_00241cb0(Node* n, Node* h) {
    Node* end = (Node*)((char*)n + 4);
    Node* p = h->right;
    if (p != end) {
        while (p->left != end)
            p = p->left;
    } else {
        p = h->parent;
        while (p != end && h == p->right) {
            h = p;
            p = p->parent;
        }
    }
    return p;
}