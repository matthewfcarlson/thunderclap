// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 20/24, incomplete)
// FUN_001e2ed0 @ 0x001e2ed0
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

struct Item {
    char pad0[8];
    int keyLo;
    int keyHi;
};

struct ItemList {
    char pad0[0x1c];
    Item **begin;
    Item **end;
};

class Skeleton;

struct Indexer {
    int FUN_001d5c70(int index);
    ItemList *FUN_001d4fc0();
};

class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(int index, int flag);
    char pad04[0xec - 4];
    Indexer *indexer;
    void FUN_001d63b0(int count);
};

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Indexer *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, int lo, int hi);
};

struct Holder44 {
    Factory *FUN_00203d70();
};

struct Holder28 {
    Holder44 *FUN_000862a0();
};

struct Manager {
    char pad0[0x54];
    Holder28 *holder;
};

struct Entry {
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

struct Slot {
    char pad0[0x10];
    unsigned char flags;
    char pad11[3];
};

class Inventory {
public:
    char pad0[0x608];
    Entry entries[0x800];
    Slot slots[1];
    char pad_rest[0x1e830 - 0x14608 - 0x14];
    Manager *mgr;
    int FUN_001e2ed0(int idx, int lo, int hi);
};

int Inventory::FUN_001e2ed0(int idx, int lo, int hi)
{
    if (idx < 0)
        return -1;
    Entry *e = &entries[idx];
    Slot *s = &slots[e->slot];
    Indexer *indexer;
    bool direct;
    if ((s->flags & 1) && e->skel) {
        indexer = e->skel->indexer;
        direct = true;
    } else {
        int rlo = e->resLo;
        int rhi = e->resHi;
        direct = false;
        Factory *factory = mgr->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
        indexer = factory->f3(&caster, rlo, rhi);
        if (!indexer)
            return -1;
    }
    ItemList *list = indexer->FUN_001d4fc0();
    if (!list)
        return -1;
    int count = list->end - list->begin;
    int n;
    for (n = 0; n < count; n++) {
        Item *it = list->begin[n];
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
