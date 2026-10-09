extern "C" int strcmp(const char*, const char*);
struct Node {
    Node* left;
    Node* right;
    int pad[3];
    const char* key;
};
struct Tree {
    Node* root;
};
Node* Find(Tree* t, const char** key) {
    Node* n = t->root;
    Node* end = (Node*)((char*)t + 4);
    while (n != end) {
        int c = strcmp(*key, n->key);
        if (c < 0)
            n = n->left;
        else if (c <= 0)
            return (Node*)((char*)n - 4);
        else
            n = n->right;
    }
    return 0;
}