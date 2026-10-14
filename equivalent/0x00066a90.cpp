// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 4/4)
// FUN_00066a90 @ 0x00066a90
void FUN_00066900();
void FUN_000668c0();
void *FUN_0008d6d0(unsigned int size);

struct Key {
    int w[4];
};
struct Node {
    char pad0[0x10];
    Key key;
};
struct Result {
    Node *node;
    void *owner;
};
void *__stdcall FUN_00230be0(void (*match)(), const Key *key);

struct Owner {
    void FUN_00230c30(Node *node, void (*notify)(), void *found);
    void FUN_00066a90(Result *out, const Key *key);
};

void Owner::FUN_00066a90(Result *out, const Key *key)
{
    void *found = FUN_00230be0(FUN_00066900, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return;
    }
    Node *node = (Node *)FUN_0008d6d0(0x20);
    if (node)
        node->key = *key;
    FUN_00230c30(node, FUN_000668c0, found);
    out->owner = this;
    out->node = node;
}
