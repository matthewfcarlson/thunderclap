struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int data;
};
void* FUN_00247f80(void*, void*);
void FUN_00247fc0(void*, void*);
void FUN_00248ac0(Node* tree, Node* node) {
    Node* nil = (Node*)((char*)tree + 4);
    Node* x;
    if (node->left == nil || node->right == nil)
        x = node;
    else
        x = (Node*)FUN_00247f80(tree, node);
    Node* y;
    if (x->left != nil)
        y = x->left;
    else
        y = x->right;
    y->parent = x->parent;
    if (x->parent == nil)
        tree->left = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    int flag = (x->data == 0);
    if (x != node) {
        x->parent = node->parent;
        x->left = node->left;
        x->right = node->right;
        x->data = node->data;
        if (x->parent != nil) {
            if (x->parent->left == node)
                x->parent->left = x;
            else
                x->parent->right = x;
        } else
            tree->left = x;
        if (x->left != nil)
            x->left->parent = x;
        if (x->right->parent != nil)
            x->right->parent = x;
    }
    if (flag)
        FUN_00247fc0(tree, y);
}