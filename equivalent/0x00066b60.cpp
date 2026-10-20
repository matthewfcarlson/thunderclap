// STATUS: equivalent (tools/equiv.py level 3: 19961 inputs, branch coverage 4/4)
// FUN_00066b60 @ 0x00066b60
#include "compat/ptr.h"
void FUN_00066980();
void FUN_00066940();
void *FUN_0008d6d0(hulk_uintptr size);

struct Key_66b60 {
    int w[4];
};
struct Node {
    char pad0[0x10];
    Key_66b60 key;
};
struct Result_66b60 {
    Node *node;
    void *owner;
};

struct Owner_66b60 {
    void FUN_00230c30(Node *node, void (*notify)(), void *found);
    void FUN_00066b60(Result_66b60 *out, const Key_66b60 *key);
    void *FUN_00230be0(void (*match)(), const Key_66b60 *key);
};

void Owner_66b60::FUN_00066b60(Result_66b60 *out, const Key_66b60 *key)
{
    void *found = FUN_00230be0(FUN_00066980, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return;
    }
    Node *node = (Node *)FUN_0008d6d0(0x20);
    if (node)
        node->key = *key;
    FUN_00230c30(node, FUN_00066940, found);
    out->owner = this;
    out->node = node;
}
