// Same code shape as 0x00241880 (propagated; names are from that function)
struct Node {
    Node* a;
    Node* b;
    Node* c;
};
struct Tree_241c00 {
    Node* root;
};
extern "C" void FUN_00241c00(Tree_241c00* tree, Node* node) {
    Node* child = node->b;
    node->b = child->a;
    if (child->a != (Node*)(tree + 1)) {
        child->a->c = node;
    }
    child->c = node->c;
    Node* parent = node->c;
    if (parent == (Node*)(tree + 1)) {
        *reinterpret_cast<Node**>(tree) = child;
        child->a = node;
        node->c = child;
        return;
    }
    if (node == parent->a) {
        parent->a = child;
        child->a = node;
        node->c = child;
        return;
    }
    parent->b = child;
    child->a = node;
    node->c = child;
}