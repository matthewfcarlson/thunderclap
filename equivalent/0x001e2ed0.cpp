// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 20/24, incomplete)
// FUN_001e2ed0 @ 0x001e2ed0
#include "compat/ptr.h"
class CSPHulkProp;

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

struct Item_1e2ed0 {
    char pad0[8];
    int keyLo;
    int keyHi;
};

struct ItemList_1e2ed0 {
    char pad0[0x1c];
    Item_1e2ed0 **begin;
    Item_1e2ed0 **end;
};

class Skeleton;

struct Indexer_1e2ed0 {
    int FUN_001d5c70(int index);
    ItemList_1e2ed0 *FUN_001d4fc0();
};

class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(int index, int flag);
    char pad04[0xec - 4];
    Indexer_1e2ed0 *indexer;
    void FUN_001d63b0(int count);
};

class Factory_1e2ed0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Indexer_1e2ed0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, int lo, int hi);
};

struct Holder44_1e2ed0 {
    Factory_1e2ed0 *FUN_00203d70();
};

struct Holder28_1e2ed0 {
    Holder44_1e2ed0 *FUN_000862a0();
};

struct Manager_1e2ed0 {
    char pad0[0x54];
    Holder28_1e2ed0 *holder;
};

struct Entry_1e2ed0 {
    char pad0[8];
    int resLo;
    int resHi;
    char pad10[8];
    Skeleton *skel;
    char pad1c[4];
    short pad20;
    short slot;
    char pad24[2];
    signed char index;
    char pad27;
};

struct Slot_1e2ed0 {
    char pad0[0x10];
    unsigned char flags;
    char pad11[3];
};

class Inventory_1e2ed0 {
public:
    char pad0[0x608];
    Entry_1e2ed0 entries[0x800];
    Slot_1e2ed0 slots[1];
    char pad_rest[0x1e830 - 0x14608 - 0x14];
    Manager_1e2ed0 *mgr;
    int FUN_001e2ed0(int idx, int lo, int hi);
};

int Inventory_1e2ed0::FUN_001e2ed0(int idx, int lo, int hi)
{
    if (idx < 0)
        return -1;
    Entry_1e2ed0 *e = &entries[idx];
    Slot_1e2ed0 *s = &slots[e->slot];
    Indexer_1e2ed0 *indexer;
    bool direct;
    if ((s->flags & 1) && e->skel) {
        indexer = e->skel->indexer;
        direct = true;
    } else {
        int rlo = e->resLo;
        int rhi = e->resHi;
        direct = false;
        Factory_1e2ed0 *factory = mgr->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
        indexer = factory->f3(&caster, rlo, rhi);
        if (!indexer)
            return -1;
    }
    ItemList_1e2ed0 *list = indexer->FUN_001d4fc0();
    if (!list)
        return -1;
    hulk_intptr count = list->end - list->begin;
    int n;
    for (n = 0; n < count; n++) {
        Item_1e2ed0 *it = list->begin[n];
        if (it->keyLo == lo && it->keyHi == hi)
            break;
    }
    if (n >= count || n == -1)
        return -1;
    if (direct) {
        e->skel->v16(n, 1);
        int v = e->skel->indexer->FUN_001d5c70(n);
        if (v > 0)
            e->skel->FUN_001d63b0(v);
        return n;
    }
    e->index = (signed char)n;
    e->pad20 = (short)0xfde8;
    s->flags &= 0xfb;
    return n;
}
