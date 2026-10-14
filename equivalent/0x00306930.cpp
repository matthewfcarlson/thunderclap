// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 14/14)
// FUN_00306930 @ 0x00306930
class Item {
public:
    virtual void AddRef();
    void FUN_003065b0(void *owner);
};

struct ItemVec {
    Item **begin;
    Item **end;
    Item **cap;
};

void *__cdecl FUN_0008d690(unsigned int size);

class Owner {
public:
    char pad0[0x10];
    void *context;      // 0x10
    ItemVec *items;     // 0x14
    void FUN_00306930(Item *item);
};

void Owner::FUN_00306930(Item *item)
{
    if (items == 0) {
        ItemVec *v = (ItemVec *)FUN_0008d690(0x10);
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
    ItemVec *v = items;
    if (v->end < v->cap) {
        Item **slot = v->end;
        v->end = slot + 1;
        if (slot)
            *slot = item;
    }
    item->AddRef();
    item->FUN_003065b0(context);
}
