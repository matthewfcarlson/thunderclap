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

struct Key_1e3410 {
    unsigned int lo;
    unsigned int hi;
};

struct Container_1e3410 {
    int FUN_001d5710();
    int FUN_001d5c70(int index);
};

struct Prop_1e3410 {
    char pad0[0x40];
    int startIndex;
    char pad44[0xec - 0x44];
    Container_1e3410 *items;
    char padf0[0x108 - 0xf0];
    int baseCount;
};

struct Entry_1e3410 {
    Key_1e3410 key;
    Key_1e3410 resource;
    char pad10[8];
    Prop_1e3410 *prop;
    char pad1c[6];
    short slotIndex;
    short count;
    signed char first;
    char pad27;
};

struct Slot_1e3410 {
    unsigned char flags;
    char pad[0x13];
};

class Factory_1e3410 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Container_1e3410 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e3410 {
    Factory_1e3410 *FUN_00203d70();
};

struct Holder28_1e3410 {
    Holder44_1e3410 *FUN_000862a0();
};

struct Manager_1e3410 {
    char pad0[0x54];
    Holder28_1e3410 *holder;
};

extern Manager_1e3410 *DAT_004dd700;

struct Inventory_1e3410 {
    char pad0[0x608];
    Entry_1e3410 entries[0x800];

    int FUN_001e3410(Key_1e3410 *key);
};

int Inventory_1e3410::FUN_001e3410(Key_1e3410 *key)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].key.lo == key->lo && entries[i].key.hi == key->hi)
            break;
    }
    if (i >= 0x800)
        return 0;
    Entry_1e3410 *e = &entries[i];

    // per-slot flag array, 0x14 bytes per slot, starting at the top of this object
    Slot_1e3410 *slot = (Slot_1e3410 *)((char *)this + (e->slotIndex + 0x104e) * sizeof(Slot_1e3410));
    if ((slot->flags & 1) && e->prop != 0) {
        Prop_1e3410 *prop = e->prop;
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
    Factory_1e3410 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    // the original builds the caster in the (dead) key argument slot
    content::LoadInventory::DynamicCaster<CSPHulkProp> *caster =
        new ((void *)&key) content::LoadInventory::DynamicCaster<CSPHulkProp>;
    Container_1e3410 *items = factory->f3(caster, e->resource.lo, e->resource.hi);
    if (items != 0) {
        for (; n < items->FUN_001d5710(); n++) {
            int v = items->FUN_001d5c70(n);
            if (v > 0)
                total += v;
        }
    }
    return total;
}
