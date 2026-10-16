// STATUS: equivalent (tools/equiv.py level 3: 445 inputs, branch coverage 42/42)
// hulkfight::motion::LocomotionSprintAction::vfunc_3 @ 0x00163ed0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

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

namespace pure3d { class Animation; }

struct V3_163ed0 {
    float x, y, z;
};

struct Id64_163ed0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(unsigned int *src);
};

struct Animation {
    char pad0[8];
    int dummy;
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_163ed0 id;                // 0x08
};

class LocomotionSteerDriver : public Driver {
public:
    char pad10[0x14];
    float f24;              // 0x24
    char pad28[4];
    int f2c;                // 0x2c
    char pad30[0x8b0 - 0x30];
    float f8b0;
    LocomotionSteerDriver *FUN_00229760(void *rig, int a, int b, void *desc, int c);
    void FUN_00222550(unsigned int lo, unsigned int hi);
    void FUN_00228700(V3_163ed0 *v);
    float FUN_002287a0(int v);
};
}

struct SubObj_163ed0 {
    void FUN_00222120(V3_163ed0 *out);
};

struct LayerSet_163ed0 {
    char pad0[0x10];
    SubObj_163ed0 sub;
    char pad11[0x68 - 0x11];
    unsigned int count;     // 0x68
    void *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2::LocomotionSteerDriver *d, float r, float a, float b, float c, float e, float f);
};

struct Stats_163ed0 {
    bool FUN_000356c0(V3_163ed0 *out);
    void FUN_00035980(int v);
};

struct Ctx_163ed0 {
    Stats_163ed0 *FUN_00059a30();
    LayerSet_163ed0 *FUN_00059a40();
};

struct Owner_163ed0 {
    Ctx_163ed0 *FUN_000592a0();
};

class Factory_163ed0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_163ed0 { Factory_163ed0 *FUN_00203d70(); };
struct Holder28_163ed0 { Holder44_163ed0 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_163ed0 *holder; };

struct Config_163ed0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x10 - 4 + 4];
    float f14;
    char pad18[0x28 - 0x18];
    float f28;
    char pad2c[4];
    unsigned int key30[2];  // 0x30
    unsigned int key38[2];  // 0x38
    unsigned int key40[2];  // 0x40
    unsigned int key48[2];  // 0x48
    unsigned int key50[2];  // 0x50
    float f58, f5c, f60;
};

void *thunk_FUN_0008d690(unsigned int size);
float FUN_000964e0();
void __cdecl FUN_0015cfd0(void *rig, choreo2::LocomotionSteerDriver *d);

union Slot14_163ed0 {
    char caster[4];
    choreo2::LocomotionSteerDriver *found;
    Animation *anim;
};

union Slot2c {
    Stats_163ed0 *stats;
    float f;
};

struct Frame_163ed0 {
    float best;                 // 0x10
    Slot14_163ed0 s14;                 // 0x14
    void *rig;                  // 0x18
    char casterC[4];            // 0x1c
    unsigned int *keyptr;       // 0x20
    unsigned int keyhi;         // 0x24
    LayerSet_163ed0 *layers;           // 0x28
    Slot2c s2c;                 // 0x2c
    V3_163ed0 w;                       // 0x30
    V3_163ed0 out;                     // 0x3c
    unsigned int desc[10];      // 0x48
};

namespace hulkfight {
namespace motion {
class LocomotionSprintAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Config_163ed0 *cfg;                            // 0x1c
    Owner_163ed0 *owner;                           // 0x20
    choreo2::LocomotionSteerDriver *driver; // 0x24
    float f28;
};
}
}

bool hulkfight::motion::LocomotionSprintAction::vfunc_3(int a, int b)
{
    Frame_163ed0 f;
    Ctx_163ed0 *ctx = owner->FUN_000592a0();
    f.s2c.stats = ctx->FUN_00059a30();
    f.layers = ctx->FUN_00059a40();
    if (f.layers == 0)
        return false;
    f.rig = f.layers->FUN_002226b0();
    unsigned int keylo = cfg->key30[0];
    f.keyhi = cfg->key30[1];
    f.best = -1.0f;
    f.s14.found = 0;
    if (f.layers->count != 0) {
        unsigned int i = 0;
        do {
            choreo2::Driver *d = f.layers->FUN_00222e20(i);
            choreo2::LocomotionSteerDriver *ac = dynamic_cast<choreo2::LocomotionSteerDriver *>(d);
            if (ac != 0) {
                if (f.best < 0.0f)
                    f.best = ac->f24;
                if ((keylo | f.keyhi) != 0 && ac->id.lo == keylo && ac->id.hi == f.keyhi) {
                    f.s14.found = ac;
                    break;
                }
            }
            i++;
        } while (i < f.layers->count);
    }
    if (f.s14.found != 0)
        f.s14.found->AddRef();
    if (driver != 0)
        driver->Release();
    driver = f.s14.found;
    if (f.s14.found == 0) {
        Config_163ed0 *c = cfg;
        unsigned int lo = c->key38[0];
        unsigned int hi = c->key38[1];
        f.keyptr = c->key30;
        Animation *animA;
        if ((lo | hi) == 0) {
            animA = 0;
        } else {
            Factory_163ed0 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.s14.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            animA = fac->f3(caster, lo, hi);
        }
        lo = cfg->key48[0];
        hi = cfg->key48[1];
        if ((lo | hi) == 0) {
            f.s14.anim = 0;
        } else {
            Factory_163ed0 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.s14.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            f.s14.anim = fac->f3(caster, lo, hi);
        }
        Animation *animC;
        lo = cfg->key40[0];
        hi = cfg->key40[1];
        if ((lo | hi) == 0) {
            animC = 0;
        } else {
            Factory_163ed0 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.casterC) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            animC = fac->f3(caster, lo, hi);
        }
        f.desc[0] = 0;
        f.desc[1] = 0;
        f.desc[2] = 0;
        f.desc[3] = 0;
        f.desc[4] = 0;
        f.desc[5] = (unsigned int)animA;
        f.desc[6] = (unsigned int)animA;
        f.desc[7] = (unsigned int)f.s14.anim;
        f.desc[8] = (unsigned int)animA;
        f.desc[9] = (unsigned int)animC;
        void *mem = thunk_FUN_0008d690(0x910);
        choreo2::LocomotionSteerDriver *nd;
        if (mem != 0)
            nd = ((choreo2::LocomotionSteerDriver *)mem)->FUN_00229760(f.rig, 4, 2, f.desc, 0);
        else
            nd = 0;
        if (nd != 0)
            nd->AddRef();
        if (driver != 0)
            driver->Release();
        driver = nd;
        nd->id.FUN_0027af70(f.keyptr);
    }
    driver->FUN_00222550(cfg->key50[0], cfg->key50[1]);
    FUN_0015cfd0(f.rig, driver);
    float f14 = cfg->f14;
    if (f14 < 0.0f)
        f28 = driver->FUN_002287a0(driver->f2c - 1);
    else
        f28 = f14;
    float f28v = cfg->f28;
    if (f28v < 0.0f) {
        if (f.best < 0.0f)
            driver->f24 = FUN_000964e0();
        else
            driver->f24 = f.best;
    } else {
        driver->f24 = f28v;
    }
    f.layers->sub.FUN_00222120(&f.out);
    driver->FUN_00228700(&f.out);
    Stats_163ed0 *stats = f.s2c.stats;
    f.w.x = 0;
    f.w.y = 0;
    f.w.z = 0;
    stats->FUN_000356c0(&f.w);
    double dot = f.out.z * f.w.z + f.out.y * f.w.y + f.out.x * f.w.x;
    if (dot > 0.0)
        driver->f8b0 = (float)dot;
    else
        driver->f8b0 = 0;
    f.s2c.f = cfg->v7();
    f.layers->FUN_00222890(driver, f.s2c.f, cfg->f58, 1.0f, cfg->f5c, cfg->f60, -1.0f);
    stats->FUN_00035980(1);
    return true;
}
