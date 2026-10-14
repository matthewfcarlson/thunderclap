// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001e32b0 @ 0x001e32b0
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

struct Item_1e32b0 {
    int FUN_001d5dd0(int arg);
};

struct Part_1e32b0 {
    char pad0[0x40];
    int key;                 // 0x40
    char pad1[0xec - 0x44];
    Item_1e32b0 *item;              // 0xec
};

class Factory_1e32b0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Item_1e32b0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_1e32b0 { Factory_1e32b0 *FUN_00203d70(); };
struct Holder28_1e32b0 { Holder44_1e32b0 *FUN_000862a0(); };
struct Globals_1e32b0 { char pad0[0x54]; Holder28_1e32b0 *holder; };
extern Globals_1e32b0 *DAT_004dd700;

struct Slot_1e32b0 {
    unsigned char flags;
    char pad[19];
};

struct Entry_1e32b0 {
    char pad0[8];
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
    char pad1[0x18 - 0x10];
    Part_1e32b0 *part;              // 0x18
    char pad2[0x22 - 0x1c];
    short group;             // 0x22
    char pad3[0x26 - 0x24];
    signed char index;       // 0x26
    char pad4[0x28 - 0x27];
};

class Manager_1e32b0 {
public:
    int FUN_001e32b0(int name);
    int FUN_001dbfe0(int name);

    char pad0[0x608];
    Entry_1e32b0 entries[1];        // 0x608
};

int Manager_1e32b0::FUN_001e32b0(int name)
{
    int idx = FUN_001dbfe0(name);
    if (idx < 0)
        return 0;
    Entry_1e32b0 *e = &entries[idx];
    Slot_1e32b0 *slots = (Slot_1e32b0 *)this;
    if ((slots[e->group + 0x104e].flags & 1) && e->part != 0)
        return e->part->item->FUN_001d5dd0(e->part->key);

    Factory_1e32b0 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Item_1e32b0 *obj = fa->f3(&caster, e->idLo, e->idHi);
    if (obj != 0)
        return obj->FUN_001d5dd0(e->index);
    return 0;
}
