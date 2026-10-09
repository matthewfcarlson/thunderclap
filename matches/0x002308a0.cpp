struct Node {
    Node* left;
    Node* next;
    Node* parent;
};
struct Tree {
    Node* root;
    Node header;
    void Replace(Node*);
};
void Tree::Replace(Node* n) {
    Node* x = n->left;
    n->left = x->next;
    if (x->next != &header)
        x->next->parent = n;
    x->parent = n->parent;
    Node* p = n->parent;
    if (p == &header) {
        root = x;
        x->next = n;
        n->parent = x;
        return;
    }
    if (n == p->left)
        p->left = x;
    else
        p->next = x;
    x->next = n;
    n->parent = x;
}
