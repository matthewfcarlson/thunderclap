// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_39 @ 0x000f4790
#include "gen/global.h"

struct Node_f4790 {
    Node_f4790* FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000fa0a0();
};

struct Item_f4790 {
};

struct Factory_f4790 {
    Item_f4790* FUN_000f28c0(Node_f4790* n);
    Item_f4790* FUN_000f2740(Node_f4790* n);
    Item_f4790* FUN_000f2860(Node_f4790* n);
    Item_f4790* FUN_000f27a0(Node_f4790* n);
    Item_f4790* FUN_000f2920(Node_f4790* n);
    Item_f4790* FUN_000f2800(Node_f4790* a, Node_f4790* b);
};

struct Message_f4790 {
    virtual void m0();
    virtual unsigned int GetId();
};

char FEThingsBase::vfunc_39(int __p0, int __p1, int __p2) { Node_f4790 * node = (Node_f4790 *)__p0; Factory_f4790 * factory = (Factory_f4790 *)__p1; Message_f4790 * msg = (Message_f4790 *)__p2;

    Item_f4790* item;
    Node_f4790* first;
    switch (msg->GetId()) {
    case 0xceaa8e00:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f28c0(first);
        break;
    case 0xa6210435:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2740(first);
        break;
    case 0xa5b54458:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2860(first);
        break;
    case 0x103db79c:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f27a0(first);
        break;
    case 0x1ed3ea80:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2920(first);
        break;
    case 0x2d7a823f: {
        first = node->FUN_000fad90();
        Node_f4790* second = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2800(first, second);
        break;
    }
    default:
        return 0;
    }
    vfunc_38(node, item);
    return 1;
}
