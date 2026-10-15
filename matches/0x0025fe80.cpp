struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* __cdecl FUN_0025fe80(Node* n, Node* x) {
    Node* p = (Node*)&n->parent;
    Node* a = x->parent;
    if (a != p) {
        while (a->left != p)
            a = a->left;
        return a;
    }
    a = x->right;
    while (a != p && x == a->parent) {
        x = a;
        a = a->right;
    }
    return a;
}