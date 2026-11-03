// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_39 @ 0x000f4790
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"

struct Node_f4790 {
    Node_f4790* FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000fa0a0();
};

struct Item_f4790 {
};

struct Factory_f4790 {
};

struct Message_f4790 {
    virtual void m0();
    virtual unsigned int GetId();
};

char FEThingsBase::vfunc_39(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { Node_f4790 * node = (Node_f4790 *)__p0; Factory_f4790 * factory = (Factory_f4790 *)__p1; Message_f4790 * msg = (Message_f4790 *)__p2;

    Item_f4790* item;
    Node_f4790* first;
    switch (msg->GetId()) {
    case 0xceaa8e00:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f28c0 *)factory)->FUN_000f28c0((Node_f4790 *)first));
        break;
    case 0xa6210435:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f2740 *)factory)->FUN_000f2740((Node_f4790 *)first));
        break;
    case 0xa5b54458:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Y_f2860 *)factory)->FUN_000f2860((Node_f4790 *)first));
        break;
    case 0x103db79c:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Holder_f27a0 *)factory)->FUN_000f27a0((hulk_intptr)(Node_f4790 *)first));
        break;
    case 0x1ed3ea80:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Holder_f2920 *)factory)->FUN_000f2920((hulk_intptr)(Node_f4790 *)first));
        break;
    case 0x2d7a823f: {
        first = node->FUN_000fad90();
        Node_f4790* second = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = ((Item_f4790 *)((owners::Thing_f2800 *)factory)->FUN_000f2800((hulk_intptr)(Node_f4790 *)first, (hulk_intptr)(Node_f4790 *)second));
        break;
    }
    default:
        return 0;
    }
    vfunc_38(node, item);
    return 1;
}
