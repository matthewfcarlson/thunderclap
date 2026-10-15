struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* __cdecl fn(Node* n, Node* sentinel) {
    Node* nil = (Node*)&n->parent;
    Node* x = sentinel->parent;
    if (x != nil) {
        while (x->left != nil) {
            x = x->left;
        }
    } else {
        x = sentinel->right;
        while (x != nil && sentinel == x->parent) {
            sentinel = x;
            x = x->right;
        }
    }
    return x;
}