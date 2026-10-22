// STATUS: equivalent (tools/equiv.py level 3: 848 inputs, branch coverage 7/8, incomplete)
// FUN_00304c40 @ 0x00304c40
struct Node;
struct NodeVec_304c40 {
    Node** begin;
    Node** end;
};
struct Node {
    char pad0[0xc];
    unsigned char* bits;
    char pad10[4];
    NodeVec_304c40* children;
    unsigned char value;
};
struct Context {
    char pad0[8];
    int index;
};
class CollisionObject_304c40 {
public:
    void FUN_00304c40(Node* node, Context* ctx);
};
void CollisionObject_304c40::FUN_00304c40(Node* node, Context* ctx) {
    node->value = node->bits[ctx->index];
    if (node->children == 0)
        return;
    if (node->children->end - node->children->begin == 0)
        return;
    for (unsigned int i = 0; i < (unsigned int)(node->children->end - node->children->begin); i++)
        FUN_00304c40(node->children->begin[i], ctx);
}
