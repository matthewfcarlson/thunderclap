struct Node {
    Node* left;
    Node* right;
};
struct Tree {
    Node* root;
    Node sentinel;
};
extern "C" int __cdecl FUN_0025ad30(void *, void *);
Node* __cdecl findNode(Tree* tree, void* key) {
    Node* p = tree->root;
    Node* end = &tree->sentinel;
    while (p != end) {
        int n = FUN_0025ad30(key, (Node *)p);
        if (n < 0)
            p = p->left;
        else if (n > 0)
            p = p->right;
        else
            return p;
    }
    return 0;
}