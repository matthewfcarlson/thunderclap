// STATUS: equivalent (tools/equiv.py level 3: 2143 inputs, branch coverage 12/12)
// FUN_002067d0 @ 0x002067d0
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int __cdecl sprintf(char *, const char *, ...);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

typedef unsigned __int64 ID;

namespace pure3d { class Geometry; class Shadow; class LightGroup; }
namespace physics { class WorldCollisionObject; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Name {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *f3(void *caster, unsigned int lo, unsigned int hi);
    void FUN_002660a0(int v);
};

struct Entry {
    char pad0[8];
    char loaded;            // 0x08
    char pad9[0x56 - 9];
    short f56;              // 0x56
    float f58;              // 0x58
    void FUN_001c6cb0(void *geom);
    void FUN_001c6ce0(void *shadow);
    void FUN_001c6950(void *lights);
};

struct Item {
    char pad0[0x38];
    Factory *factory;       // 0x38
};

struct SlotA { void FUN_001dd320(int idx); };
struct SlotB { void FUN_001fd180(int idx); };
struct SlotC { void FUN_001fb300(Factory *f); };
struct SlotD { void FUN_0007da70(int idx); };
struct SlotE { void FUN_001b5ec0(void *obj, int idx); };

struct Bank {
    char pad0[0xc];
    SlotA *a;               // 0x0c
    SlotE *e;               // 0x10
    char pad14[0x28 - 0x14];
    SlotB *b;               // 0x28
    char pad2c[0x48 - 0x2c];
    SlotC *c;               // 0x48
    SlotD *d;               // 0x4c
};

struct Mid {
    char pad0[0xc];
    Bank *bank;             // 0x0c
};

struct Event {
    int f0, f4, f8, fc, f10, f14;
    void FUN_001cad10(int idx);
};

struct Queue {
    void FUN_001cbc20(Event *e);
};

struct Globals {
    char pad0[0x30];
    Queue *queue;           // 0x30
};

struct Registry3 {
    Entry *FUN_001c7f70(Name *n);
};

struct Registry2 {
    char pad0[4];
    Registry3 *table;       // 0x04
};

Registry2 *FUN_001c3d90();
ID __cdecl FUN_002672f0(const char *s, int a, int b);

extern char DAT_004c91d8;
extern char DAT_004e5a58;
extern Globals *DAT_004dd700;

struct Loader {
    char pad0[0x24];
    char name[0x588 - 0x24];
    Mid *mid;               // 0x588
    char pad58c[4];
    short *f590;            // 0x590
    char pad594[0x5a4 - 0x594];
    char flags[0x100];      // 0x5a4
    Item *FUN_00204540(const char *name);
    int FUN_00203db0(int v);
    void FUN_002067d0(int idx, char flag);
};

struct Frame {
    char casters[8];        // 0x00, 0x04
    Name nm;                // 0x08
    Event ev;               // 0x10
    char name[0x100];
    char buf[0x100];
    unsigned int cookie;
};

void Loader::FUN_002067d0(int idx, char flag)
{
    Frame f;
    f.cookie = DAT_004d9968;
    sprintf(f.name, "%s_r%03d", this->name, idx);
    Factory *fac = 0;
    if (DAT_004c91d8)
        fac = FUN_00204540(f.name)->factory;
    Name &nm = f.nm;
    nm.FUN_0027b0e0(f.name);
    Entry *entry = FUN_001c3d90()->table->FUN_001c7f70(&nm);
    nm.FUN_0027af50();
    fac->FUN_002660a0(FUN_00203db0(entry->f56));
    mid->bank->a->FUN_001dd320(idx);
    mid->bank->b->FUN_001fd180(idx);
    mid->bank->c->FUN_001fb300(fac);

    sprintf(f.buf, "%sScene", f.name);
    ID sceneKey = FUN_002672f0(f.buf, 0, 0);
    {
        content::LoadInventory::DynamicCaster<pure3d::Geometry> *c = new (&f.casters[4]) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
        entry->FUN_001c6cb0(fac->f3(c, (unsigned int)sceneKey, (unsigned int)(sceneKey >> 32)));
    }
    sprintf(f.buf, "%sShadow", f.name);
    {
        ID k = FUN_002672f0(f.buf, 0, 0);
        content::LoadInventory::DynamicCaster<pure3d::Shadow> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<pure3d::Shadow>;
        entry->FUN_001c6ce0(fac->f3(c, (unsigned int)k, (unsigned int)(k >> 32)));
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<pure3d::LightGroup>;
        entry->FUN_001c6950(fac->f3(c, (unsigned int)sceneKey, (unsigned int)(sceneKey >> 32)));
    }
    if (f590 && *f590 != 0 && !flag)
        entry->f58 = 1.0f;
    entry->loaded = 1;
    flags[idx] = 1;
    mid->bank->d->FUN_0007da70(idx);
    sprintf(f.buf, "%sWorldCollision", f.name);
    {
        ID k = FUN_002672f0(f.buf, 0, 0);
        content::LoadInventory::DynamicCaster<physics::WorldCollisionObject> *c = new (&f.casters[0]) content::LoadInventory::DynamicCaster<physics::WorldCollisionObject>;
        void *wc = fac->f3(c, (unsigned int)k, (unsigned int)(k >> 32));
        if (wc)
            mid->bank->e->FUN_001b5ec0(wc, idx);
    }
    if (!DAT_004e5a58) {
        f.ev.FUN_001cad10(idx);
        DAT_004dd700->queue->FUN_001cbc20(&f.ev);
    }
    __security_check_cookie(f.cookie);
}
