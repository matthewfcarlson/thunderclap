// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 41/42, incomplete)
// hulkfight::motion::ClimbLocomotion4Action::vfunc_7 @ 0x00164930
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
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

struct Animation {
    char pad0[8];
    int dummy;
};

struct Id64_164930 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(unsigned int *src);
};

struct Key_164930 {
    unsigned int lo;
    unsigned int hi;
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_164930 id;                // 0x08
};

class ClimbDriver : public Driver {
public:
    ClimbDriver *FUN_00227590(void *rig, int a, int mode, void *desc, int c);
};
}

class Factory_164930 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_164930 { Factory_164930 *FUN_00203d70(); };
struct Holder28_164930 { Holder44_164930 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_164930 *holder; };

void *thunk_FUN_0008d690(unsigned int size);

class ClimbData {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x14];
    unsigned int f18;           // 0x18
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    char pad34[4];
    unsigned int key38[2];      // 0x38
    Key_164930 kA;                     // 0x40
    Key_164930 kB;                     // 0x48
    Key_164930 kE;                     // 0x50
    Key_164930 kD;                     // 0x58
    Key_164930 kC;                     // 0x60
    Key_164930 kF;                     // 0x68
    Key_164930 kI;                     // 0x70
    Key_164930 kH;                     // 0x78
    Key_164930 kG;                     // 0x80
    Id64_164930 f88;                   // 0x88
    unsigned int f90;
    unsigned int f94;
    unsigned int f98;
};

union SlotF_164930 {
    float *out;
    Animation *anim;
    char caster[4];
};

union SlotU_164930 {
    unsigned int *out;
    Animation *anim;
    char caster[4];
    int mode;
    unsigned int *keyptr;
};

namespace hulkfight {
namespace motion {
class ClimbLocomotion4Action {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(void *rig, SlotF_164930 o2, SlotU_164930 o3, SlotU_164930 o4, SlotU_164930 o5, SlotU_164930 o6, SlotU_164930 o7, SlotU_164930 o8,
                         unsigned int *o9, Id64_164930 *o10, unsigned int *o11, unsigned int *o12, unsigned int *o13);
    char pad04[0x1c];
    choreo2::Driver *driver;    // 0x20
    char pad24[0x24];
    ClimbData *data;            // 0x48
};

void ClimbLocomotion4Action::vfunc_7(void *rig, SlotF_164930 o2, SlotU_164930 o3, SlotU_164930 o4, SlotU_164930 o5, SlotU_164930 o6,
                                     SlotU_164930 o7, SlotU_164930 o8, unsigned int *o9, Id64_164930 *o10, unsigned int *o11,
                                     unsigned int *o12, unsigned int *o13)
{
    unsigned int desc[12];

    *o2.out = data->v7();
    *o3.out = data->f18;
    *o4.out = data->f1c;
    *o5.out = data->f20;
    *o6.out = data->f24;
    *o7.out = data->f28;
    *o8.out = data->f2c;
    *o9 = data->f30;
    *o10 = data->f88;
    *o11 = data->f90;
    *o12 = data->f94;
    *o13 = data->f98;

    if (driver != 0)
        return;

    o8.keyptr = data->key38;
    Animation *aF;
    Animation *aG;
    Animation *aH;
    Animation *aI;
    unsigned int lo;
    unsigned int hi;

    lo = data->kA.lo;
    hi = data->kA.hi;
    if ((lo | hi) == 0) {
        o7.anim = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o2.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        o7.anim = fac->f3(c, lo, hi);
    }
    lo = data->kB.lo;
    hi = data->kB.hi;
    if ((lo | hi) == 0) {
        o2.anim = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o2.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        o2.anim = fac->f3(c, lo, hi);
    }
    lo = data->kC.lo;
    hi = data->kC.hi;
    if ((lo | hi) == 0) {
        o3.anim = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o3.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        o3.anim = fac->f3(c, lo, hi);
    }
    lo = data->kD.lo;
    hi = data->kD.hi;
    if ((lo | hi) == 0) {
        o4.anim = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o4.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        o4.anim = fac->f3(c, lo, hi);
    }
    lo = data->kE.lo;
    hi = data->kE.hi;
    if ((lo | hi) == 0) {
        o5.anim = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o5.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        o5.anim = fac->f3(c, lo, hi);
    }
    lo = data->kF.lo;
    hi = data->kF.hi;
    if ((lo | hi) == 0) {
        aF = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o6.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        aF = fac->f3(c, lo, hi);
    }
    lo = data->kG.lo;
    hi = data->kG.hi;
    if ((lo | hi) == 0) {
        aG = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o6.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        aG = fac->f3(c, lo, hi);
    }
    lo = data->kH.lo;
    hi = data->kH.hi;
    if ((lo | hi) == 0) {
        aH = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o6.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        aH = fac->f3(c, lo, hi);
    }
    lo = data->kI.lo;
    hi = data->kI.hi;
    if ((lo | hi) == 0) {
        aI = 0;
    } else {
        Factory_164930 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        content::LoadInventory::DynamicCaster<pure3d::Animation> *c =
            new (o6.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        aI = fac->f3(c, lo, hi);
    }

    o6.mode = 3;
    if (aF != 0 || aG != 0 || aH != 0 || aI != 0) {
        if (o2.anim == 0 && o3.anim == 0 && o4.anim == 0 && o5.anim == 0) {
            o2.anim = aF;
            o3.anim = aG;
            o4.anim = aH;
            o5.anim = aI;
            aF = 0;
            aG = 0;
            aH = 0;
            aI = 0;
            o6.mode = 2;
        }
    } else {
        o6.mode = 2;
    }

    desc[0] = (hulk_uintptr)o7.anim;
    desc[1] = (hulk_uintptr)o7.anim;
    desc[2] = (hulk_uintptr)o7.anim;
    desc[3] = (hulk_uintptr)o7.anim;
    desc[4] = (hulk_uintptr)o2.anim;
    desc[5] = (hulk_uintptr)o3.anim;
    desc[6] = (hulk_uintptr)o4.anim;
    desc[7] = (hulk_uintptr)o5.anim;
    desc[8] = (hulk_uintptr)aF;
    desc[9] = (hulk_uintptr)aG;
    desc[10] = (hulk_uintptr)aH;
    desc[11] = (hulk_uintptr)aI;

    void *mem = thunk_FUN_0008d690(0x1330);
    choreo2::ClimbDriver *nd;
    if (mem != 0)
        nd = ((choreo2::ClimbDriver *)mem)->FUN_00227590(rig, 4, o6.mode, desc, 0);
    else
        nd = 0;
    if (nd != 0)
        nd->AddRef();
    if (driver != 0)
        driver->Release();
    driver = nd;
    nd->id.FUN_0027af70(o8.keyptr);
}

}
}
