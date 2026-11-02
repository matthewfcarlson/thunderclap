extern "C" int strcmp(const char*, const char*);
struct Node {
    Node* left;
    Node* right;
    int pad[3];
    const char* key;
};
struct Tree_25f670 {
    Node* root;
};
extern "C" void * FUN_0025f670(void * t, const char** key) {
    Node* n = ((Tree_25f670 *)t)->root;
    Node* end = (Node*)((char*)((Tree_25f670 *)t) + 4);
    while (n != end) {
        int c = strcmp(*key, n->key);
        if (c < 0)
            n = n->left;
        else if (c <= 0)
            return (Node *)((Node*)((char*)n - 4));
        else
            n = n->right;
    }
    return (Node *)0;
}