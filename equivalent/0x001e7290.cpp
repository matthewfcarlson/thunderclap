// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 22/22)
// FUN_001e7290 @ 0x001e7290
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

class CSPHulkProp;

struct Vec3 {
    float x, y, z;
};

struct Asset {
    int FUN_001d5000();
};

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Asset *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44 { Factory *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };
struct Manager { char pad0[0x54]; Holder28 *holder; };
extern Manager *DAT_004dd700;

struct Prop {
    char pad00[0x114];
    int f114;
    char FUN_001d7300();
};

class Probe {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool v8(Vec3 pos);
};

struct Entry {
    Vec3 pos;
    int unused0c;
    int flags;
};

struct Slot {
    unsigned int keyLo;
    unsigned int keyHi;
    char pad08[6];
    short used;
    Prop *prop;
    char pad14[6];
    short index;
    char pad1c[0xc];
};

class World {
public:
    char pad0000[0x610];
    Slot slots[0x800];
    // the entry table (stride 0x14) starts at +0x14608, just inside the end of the slot array
    Entry *entryAt(int index) { return (Entry *)((char *)this + 0x14608) + index; }

    void FUN_001e5bc0(int index);
    void FUN_001e7290(Probe *probe, bool mustBeReady);
};

void World::FUN_001e7290(Probe *probe, bool mustBeReady)
{
    for (int i = 0; i < 0x800; i++) {
        Slot *slot = &slots[i];
        if (slot->used == 0)
            continue;
        Entry *e = entryAt(slot->index);
        Vec3 pos = e->pos;
        char ready;
        if ((e->flags & 1) && slot->prop) {
            ready = slot->prop->FUN_001d7300();
            if (slot->prop->f114 != 0)
                continue;
        } else {
            content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
            Asset *asset = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70()->f3(&caster, slot->keyLo, slot->keyHi);
            ready = asset != 0 && asset->FUN_001d5000() != 0;
        }
        if (mustBeReady && !ready)
            continue;
        if (probe->v8(pos))
            FUN_001e5bc0(i);
    }
}
