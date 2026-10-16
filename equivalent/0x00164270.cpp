// STATUS: equivalent (tools/equiv.py level 3: 513 inputs, branch coverage 56/56)
// hulkfight::motion::LocomotionSteerAction::vfunc_3 @ 0x00164270
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

struct V3_164270 {
    float x, y, z;
};

struct Id64_164270 {
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
    Id64_164270 id;                // 0x08
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
    void FUN_00228700(V3_164270 *v);
    float FUN_002287a0(int v);
};
}

struct SubObj_164270 {
    void FUN_00222120(V3_164270 *out);
};

struct LayerSet_164270 {
    char pad0[0x10];
    SubObj_164270 sub;
    char pad11[0x68 - 0x11];
    unsigned int count;     // 0x68
    void *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2::LocomotionSteerDriver *d, float r, float a, float b, float c, float e, float f);
};

struct Stats_164270 {
    bool FUN_000356c0(V3_164270 *out);
    void FUN_00035980(int v);
};

struct Ctx_164270 {
    Stats_164270 *FUN_00059a30();
    LayerSet_164270 *FUN_00059a40();
};

struct Owner_164270 {
    Ctx_164270 *FUN_000592a0();
};

class Factory_164270 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_164270 { Factory_164270 *FUN_00203d70(); };
struct Holder28_164270 { Holder44_164270 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_164270 *holder; };

struct Config_164270 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x1c - 4];
    float f1c;
    float f20;
    float f24;
    unsigned int key28[2];
    unsigned int key30[2];
    unsigned int key38[2];
    unsigned int key40[2];
    char f48;
    char pad49[7];
    unsigned int key50[2];
    float f58, f5c, f60;
};

void *thunk_FUN_0008d690(unsigned int size);
float FUN_000964e0();
void __cdecl FUN_0015cfd0(void *rig, choreo2::LocomotionSteerDriver *d);

union Slot10 {
    char caster[4];
    choreo2::LocomotionSteerDriver *found;
    Animation *anim;
};

union Slot28 {
    Stats_164270 *stats;
    float f;
};

namespace hulkfight {
namespace motion {
class LocomotionSteerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Config_164270 *cfg;                            // 0x1c
    Owner_164270 *owner;                           // 0x20
    choreo2::LocomotionSteerDriver *driver; // 0x24
    float f28;
    float f2c;
    float FUN_0015c590(float v);
};
}
}

bool hulkfight::motion::LocomotionSteerAction::vfunc_3(int a, int b)
{
    struct Frame {
        float best;
        Slot10 s10;
        void *rig;
        char casterB[4];
        unsigned int *keyptr;
        unsigned int keyhi;
        LayerSet_164270 *layers;
        Slot28 s28;
        V3_164270 w;
        V3_164270 out;
        Animation *desc[3];
    } f;
    Ctx_164270 *ctx = owner->FUN_000592a0();
    f.s28.stats = ctx->FUN_00059a30();
    f.layers = ctx->FUN_00059a40();
    if (f.layers == 0)
        return false;
    f.rig = f.layers->FUN_002226b0();
    unsigned int keylo = cfg->key28[0];
    f.keyhi = cfg->key28[1];
    f.best = -1.0f;
    f.s10.found = 0;
    if (f.layers->count != 0) {
        unsigned int i = 0;
        do {
            choreo2::Driver *d = f.layers->FUN_00222e20(i);
            choreo2::LocomotionSteerDriver *ac = dynamic_cast<choreo2::LocomotionSteerDriver *>(d);
            if (ac != 0) {
                if (f.best < 0.0f)
                    f.best = ac->f24;
                if ((keylo | f.keyhi) != 0 && ac->id.lo == keylo && ac->id.hi == f.keyhi) {
                    f.s10.found = ac;
                    break;
                }
            }
            i++;
        } while (i < f.layers->count);
    }
    if (f.s10.found != 0)
        f.s10.found->AddRef();
    if (driver != 0)
        driver->Release();
    driver = f.s10.found;
    if (f.s10.found == 0) {
        Config_164270 *c = cfg;
        unsigned int lo = c->key30[0];
        unsigned int hi = c->key30[1];
        f.keyptr = c->key28;
        if ((lo | hi) == 0) {
            f.s10.anim = 0;
        } else {
            Factory_164270 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.s10.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            f.s10.anim = fac->f3(caster, lo, hi);
        }
        Animation *animB;
        lo = cfg->key38[0];
        hi = cfg->key38[1];
        if ((lo | hi) == 0) {
            animB = 0;
        } else {
            Factory_164270 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.casterB) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            animB = fac->f3(caster, lo, hi);
        }
        Animation *animC;
        lo = cfg->key40[0];
        hi = cfg->key40[1];
        if ((lo | hi) == 0) {
            animC = 0;
        } else {
            Factory_164270 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (f.casterB) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            animC = fac->f3(caster, lo, hi);
        }
        int n = 3;
        if (animB == 0) {
            animB = animC;
            n = 2;
        } else if (animC == 0) {
            n = 2;
        }
        f.desc[0] = f.s10.anim;
        f.desc[1] = animB;
        f.desc[2] = animC;
        void *mem = thunk_FUN_0008d690(0x910);
        choreo2::LocomotionSteerDriver *nd;
        if (mem != 0)
            nd = ((choreo2::LocomotionSteerDriver *)mem)->FUN_00229760(f.rig, 0, n, f.desc, 0);
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
    float f20 = cfg->f20;
    if (f20 < 0.0f)
        f2c = driver->FUN_002287a0(driver->f2c - 1);
    else
        f2c = f20;
    float f1c = cfg->f1c;
    if (f1c < 0.0f) {
        if (driver->f2c == 3)
            f28 = driver->FUN_002287a0(1);
        else
            f28 = driver->FUN_002287a0(driver->f2c - 1) * 0.5f;
    } else {
        f28 = f1c;
    }
    float f24 = cfg->f24;
    if (f24 < 0.0f) {
        if (f.best < 0.0f)
            driver->f24 = FUN_000964e0();
        else
            driver->f24 = f.best;
    } else {
        driver->f24 = f24;
    }
    f.layers->sub.FUN_00222120(&f.out);
    driver->FUN_00228700(&f.out);
    Stats_164270 *stats = f.s28.stats;
    f.w.x = 0;
    f.w.y = 0;
    f.w.z = 0;
    stats->FUN_000356c0(&f.w);
    double dot = f.out.z * f.w.z + f.out.y * f.w.y + f.out.x * f.w.x;
    volatile float dotf = (float)dot;
    if (dot > 0.0) {
        double m = FUN_0015c590(1.0f) * 2.0;
        if (m > 0.0 && dotf > m)
            driver->f8b0 = (float)m;
        else
            driver->f8b0 = dotf;
    } else {
        driver->f8b0 = 0;
    }
    f.s28.f = cfg->v7();
    f.layers->FUN_00222890(driver, f.s28.f, cfg->f58, 1.0f, cfg->f5c, cfg->f60, -1.0f);
    if (cfg->f48)
        stats->FUN_00035980(1);
    return true;
}
