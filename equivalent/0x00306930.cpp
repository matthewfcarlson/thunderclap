// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 14/14)
// FUN_00306930 @ 0x00306930
#include "compat/ptr.h"
class Item_306930 {
public:
    virtual void AddRef();
    void FUN_003065b0(void *owner);
};

struct ItemVec_306930 {
    Item_306930 **begin;
    Item_306930 **end;
    Item_306930 **cap;
};

void *__cdecl FUN_0008d690(hulk_uintptr size);

class Owner_306930 {
public:
    char pad0[0x10];
    void *context;      // 0x10
    ItemVec_306930 *items;     // 0x14
    void FUN_00306930(Item_306930 *item);
};

void Owner_306930::FUN_00306930(Item_306930 *item)
{
    if (items == 0) {
        ItemVec_306930 *v = (ItemVec_306930 *)FUN_0008d690(0x10);
        if (v) {
            v->begin = 0;
            v->end = 0;
            v->cap = 0;
        }
        items = v;
    } else {
        for (unsigned int i = 0; i < (unsigned int)(items->end - items->begin); i++) {
            if (items->begin[i] == item)
                return;
        }
    }
    ItemVec_306930 *v = items;
    if (v->end < v->cap) {
        Item_306930 **slot = v->end;
        v->end = slot + 1;
        if (slot)
            *slot = item;
    }
    item->AddRef();
    item->FUN_003065b0(context);
}
