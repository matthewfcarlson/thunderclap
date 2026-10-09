struct Node {
    Node* left;
    Node* right;
    int pad[2];
    int key;
};
struct Tree {
    Node* root;
    Node sentinel;
};
int* find(Tree* tree, int* key) {
    Node* p = tree->root;
    Node* end = (Node*)((char*)tree + 4);
    while (p != end) {
        int k = *key;
        int d = k - p->key;
        if (d < 0)
            p = p->left;
        else if (d <= 0)
            return (int*)((char*)p - 0x58);
        else
            p = p->right;
    }
    return 0;
}