// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 29/30, incomplete)
// FUN_001e3410 @ 0x001e3410
inline void *operator new(unsigned int, void *p) { return p; }

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

struct Key {
    unsigned int lo;
    unsigned int hi;
};

struct Container {
    int FUN_001d5710();
    int FUN_001d5c70(int index);
};

struct Prop {
    char pad0[0x40];
    int startIndex;
    char pad44[0xec - 0x44];
    Container *items;
    char padf0[0x108 - 0xf0];
    int baseCount;
};

struct Entry {
    Key key;
    Key resource;
    char pad10[8];
    Prop *prop;
    char pad1c[6];
    short slotIndex;
    short count;
    signed char first;
    char pad27;
};

struct Slot {
    unsigned char flags;
    char pad[0x13];
};

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Container *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
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

extern Manager *DAT_004dd700;

struct Inventory {
    char pad0[0x608];
    Entry entries[0x800];

    int FUN_001e3410(Key *key);
};

int Inventory::FUN_001e3410(Key *key)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].key.lo == key->lo && entries[i].key.hi == key->hi)
            break;
    }
    if (i >= 0x800)
        return 0;
    Entry *e = &entries[i];

    // per-slot flag array, 0x14 bytes per slot, starting at the top of this object
    Slot *slot = (Slot *)((char *)this + (e->slotIndex + 0x104e) * sizeof(Slot));
    if ((slot->flags & 1) && e->prop != 0) {
        Prop *prop = e->prop;
        int total = 0;
        if (prop->baseCount > 0)
            total = prop->baseCount;
        for (int n = prop->startIndex + 1; n < prop->items->FUN_001d5710(); n++) {
            int v = prop->items->FUN_001d5c70(n);
            if (v > 0)
                total += v;
        }
        return total;
    }

    int total = 0;
    if (e->count > 0)
        total = e->count;
    int n = e->first + 1;
    Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    // the original builds the caster in the (dead) key argument slot
    content::LoadInventory::DynamicCaster<CSPHulkProp> *caster =
        new ((void *)&key) content::LoadInventory::DynamicCaster<CSPHulkProp>;
    Container *items = factory->f3(caster, e->resource.lo, e->resource.hi);
    if (items != 0) {
        for (; n < items->FUN_001d5710(); n++) {
            int v = items->FUN_001d5c70(n);
            if (v > 0)
                total += v;
        }
    }
    return total;
}
