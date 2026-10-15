struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Header {
    int pad;
    Node node;
};
Node* __cdecl findNext(Header* h, Node* x) {
    Node* end = &h->node;
    Node* p = x->parent;
    if (p != end) {
        while (p->left != end)
            p = p->left;
    } else {
        p = x->right;
        while (p != end && x == p->parent) {
            x = p;
            p = p->right;
        }
    }
    return p;
}