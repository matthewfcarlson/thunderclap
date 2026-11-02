struct Node {
    Node* left;
    Node* right;
    int pad[2];
    int key;
};
struct Tree_244870 {
    Node* root;
    Node sentinel;
};
extern "C" int* FUN_00244870(void * tree, int* key) {
    Node* p = ((Tree_244870 *)tree)->root;
    Node* end = (Node*)((char*)((Tree_244870 *)tree) + 4);
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