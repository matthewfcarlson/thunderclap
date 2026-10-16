// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001e3360 @ 0x001e3360
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

class CSPHulkProp;

struct Item_1e3360 {
    int FUN_001d5e80(int arg);
};

struct Part_1e3360 {
    char pad0[0x40];
    int key;                 // 0x40
    char pad1[0xec - 0x44];
    Item_1e3360 *item;              // 0xec
};

class Factory_1e3360 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Item_1e3360 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e3360 { Factory_1e3360 *FUN_00203d70(); };
struct Holder28_1e3360 { Holder44_1e3360 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_1e3360 *holder; };

struct Slot_1e3360 {
    unsigned char flags;
    char pad[19];
};

struct Entry_1e3360 {
    char pad0[8];
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
    char pad1[0x18 - 0x10];
    Part_1e3360 *part;              // 0x18
    char pad2[0x22 - 0x1c];
    short group;             // 0x22
    char pad3[0x26 - 0x24];
    signed char index;       // 0x26
    char pad4[0x28 - 0x27];
};

class Manager_1e3360 {
public:
    int FUN_001e3360(int name);
    int FUN_001dbfe0(int name);

    char pad0[0x608];
    Entry_1e3360 entries[1];        // 0x608
};

int Manager_1e3360::FUN_001e3360(int name)
{
    int idx = FUN_001dbfe0(name);
    if (idx < 0)
        return 0;
    Entry_1e3360 *e = &entries[idx];
    Slot_1e3360 *slots = (Slot_1e3360 *)this;
    if ((slots[e->group + 0x104e].flags & 1) && e->part != 0)
        return e->part->item->FUN_001d5e80(e->part->key);

    Factory_1e3360 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Item_1e3360 *obj = fa->f3(&caster, e->idLo, e->idHi);
    if (obj != 0)
        return obj->FUN_001d5e80(e->index);
    return 0;
}
