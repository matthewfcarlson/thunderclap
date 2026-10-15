struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
Node* Walk(Node* head, Node* node) {
    Node* nil = (Node*)((char*)head + 4);
    Node* p = node->parent;
    if (p != nil) {
        while (p->left != nil)
            p = p->left;
        return p;
    }
    p = node->right;
    while (p != nil) {
        if (node != p->parent)
            break;
        node = p;
        p = p->right;
    }
    return p;
}