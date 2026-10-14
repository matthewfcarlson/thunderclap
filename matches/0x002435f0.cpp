// Same code shape as 0x002418d0 (propagated; names are from that function)
struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Tree_2435f0 {
    Node* root;
    Node head;
};
void swap_node(Tree_2435f0* tree, Node* node) {
    Node* child = node->left;
    node->left = child->parent;
    if (child->parent != &tree->head)
        child->parent->right = node;
    child->right = node->right;
    Node* p = node->right;
    if (p == &tree->head) {
        tree->root = child;
        child->parent = node;
        node->right = child;
        return;
    }
    if (node == p->left) {
        p->left = child;
        child->parent = node;
        node->right = child;
        return;
    }
    p->parent = child;
    child->parent = node;
    node->right = child;
}