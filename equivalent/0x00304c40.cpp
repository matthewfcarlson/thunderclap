// STATUS: equivalent (tools/equiv.py level 3: 848 inputs, branch coverage 7/8, incomplete)
// FUN_00304c40 @ 0x00304c40
struct Node;
struct NodeVec {
    Node** begin;
    Node** end;
};
struct Node {
    char pad0[0xc];
    unsigned char* bits;
    char pad10[4];
    NodeVec* children;
    unsigned char value;
};
struct Context {
    char pad0[8];
    int index;
};
class Walker {
public:
    void FUN_00304c40(Node* node, Context* ctx);
};
void Walker::FUN_00304c40(Node* node, Context* ctx) {
    node->value = node->bits[ctx->index];
    if (node->children == 0)
        return;
    if (node->children->end - node->children->begin == 0)
        return;
    for (unsigned int i = 0; i < (unsigned int)(node->children->end - node->children->begin); i++)
        FUN_00304c40(node->children->begin[i], ctx);
}
