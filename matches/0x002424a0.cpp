struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
extern "C" void* FUN_00241930(void*, void*);
extern "C" void FUN_00241970(void*, void*);
extern "C" void FUN_002424a0(void * tree, void * node) {
    Node* nil = (Node*)((char*)((Node *)tree) + 4);
    Node* x;
    if (((Node *)node)->left == nil || ((Node *)node)->right == nil)
        x = ((Node *)node);
    else
        x = (Node*)FUN_00241930(((Node *)tree), ((Node *)node));
    Node* y;
    if (x->left != nil)
        y = x->left;
    else
        y = x->right;
    y->parent = x->parent;
    if (x->parent == nil)
        ((Node *)tree)->left = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    int flag = (x->data == 0);
    if (x != ((Node *)node)) {
        x->parent = ((Node *)node)->parent;
        x->left = ((Node *)node)->left;
        x->right = ((Node *)node)->right;
        x->data = ((Node *)node)->data;
        if (x->parent != nil) {
            if (x->parent->left == ((Node *)node))
                x->parent->left = x;
            else
                x->parent->right = x;
        } else
            ((Node *)tree)->left = x;
        if (x->left != nil)
            x->left->parent = x;
        if (x->right->parent != nil)
            x->right->parent = x;
    }
    if (flag)
        FUN_00241970(((Node *)tree), y);
}