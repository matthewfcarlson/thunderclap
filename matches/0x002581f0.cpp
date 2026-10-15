struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Header {
    int pad;
    Node nil;
};
Node* __cdecl next(Header* root, Node* x) {
    Node* nil = &root->nil;
    Node* y = x->parent;
    if (y != nil) {
        if (y->left == nil)
            return y;
        do {
            y = y->left;
        } while (y->left != nil);
        return y;
    }
    y = x->right;
    if (y != nil) {
        while (y != nil && x == y->parent) {
            x = y;
            y = y->right;
        }
    }
    return y;
}