// Same code shape as 0x00241880 (propagated; names are from that function)
struct Node {
    Node* a;
    Node* b;
    Node* c;
};
struct Tree_2482a0 {
    Node* root;
};
extern "C" void FUN_002482a0(void * tree, void * node) {
    Node* child = ((Node *)node)->b;
    ((Node *)node)->b = child->a;
    if (child->a != (Node*)(((Tree_2482a0 *)tree) + 1)) {
        child->a->c = ((Node *)node);
    }
    child->c = ((Node *)node)->c;
    Node* parent = ((Node *)node)->c;
    if (parent == (Node*)(((Tree_2482a0 *)tree) + 1)) {
        *reinterpret_cast<Node**>(((Tree_2482a0 *)tree)) = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    if (((Node *)node) == parent->a) {
        parent->a = child;
        child->a = ((Node *)node);
        ((Node *)node)->c = child;
        return;
    }
    parent->b = child;
    child->a = ((Node *)node);
    ((Node *)node)->c = child;
}