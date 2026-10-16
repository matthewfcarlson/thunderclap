// STATUS: equivalent (tools/equiv.py level 3: 1026 inputs, branch coverage 52/54, incomplete)
// CGrappleLocoStrafe4Action::vfunc_6 @ 0x00023160
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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

namespace pure3d { class Animation; }

struct Id64_23160 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_23160 *src);
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_23160 id;
    void FUN_002224a0(int v);
};

class LocomotionStrafeDriver : public Driver {
public:
    char pad10[0x1330 - 0x10];
    LocomotionStrafeDriver *FUN_00227590(void *rig, int a, int n, void **anims, int z);
};
}

struct Rig_23160 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Stats_23160 {
    char pad0[0x120];
    struct Inner {
        char pad0[8];
        Rig_23160 *rig;
    } *inner;
};

class Owner_23160;
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Owner_23160 *owner);
Stats_23160 *__fastcall FUN_00059a30(Context *ctx);

struct LayerSet_23160 {
    char pad0[0x64];
    void *rigRef;
    unsigned int count;
    void *FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2::Driver *d, float dur, float a, float b, float c, float e, float f);
};
LayerSet_23160 *__fastcall FUN_00059a40(Context *ctx);

class Factory_23160 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_23160 { Factory_23160 *FUN_00203d70(); };
struct Holder28_23160 { Holder44_23160 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_23160 *holder; };

class Owner_23160 {
public:
    virtual void v0();
};

struct Key_23160 {
    unsigned int lo;
    unsigned int hi;
};

class StrafeData_23160 {
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
    Id64_23160 id;
    Key_23160 keys[9];
    Key_23160 rigKey;
    float f70;
    float f74;
    float f78;
};

void *thunk_FUN_0008d690(unsigned int size);

class CGrappleLocoStrafe4Action {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    Owner_23160 *owner;
    StrafeData_23160 *data;
    choreo2::LocomotionStrafeDriver *driver;
};

struct Frame_23160 {
    void *a1;
    void *a2;
    void *a3;
    void *a4;
    int n;
    void *a0;
    LayerSet_23160 *layers;
    Id64_23160 *idPtr;
    unsigned int t30;
    unsigned int t34;
    void *anims[12];
};

static __forceinline void *LoadAnim(StrafeData_23160 *sd, int idx, void *slot)
{
    unsigned int lo = sd->keys[idx].lo;
    unsigned int hi = sd->keys[idx].hi;
    if ((lo | hi) == 0)
        return 0;
    Factory_23160 *fa = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    return fa->f3(new (slot) content::LoadInventory::DynamicCaster<pure3d::Animation>, lo, hi);
}

bool CGrappleLocoStrafe4Action::vfunc_6(int arg)
{
    Frame_23160 f;
    Context *ctx = FUN_000592a0(owner);
    FUN_00059a30(ctx);
    f.layers = FUN_00059a40(ctx);
    LayerSet_23160 *layers = f.layers;
    if (layers == 0)
        return false;

    unsigned int lo = data->id.lo;
    unsigned int hi = data->id.hi;
    for (unsigned int i = 0; i < layers->count; i++) {
        choreo2::Driver *d = layers->FUN_00222e20(i);
        if (d->id.lo != lo || d->id.hi != hi)
            continue;
        driver = dynamic_cast<choreo2::LocomotionStrafeDriver *>(d);
        if (driver != 0)
            break;
    }

    if (driver == 0) {
        f.idPtr = &data->id;
        f.a0 = LoadAnim(data, 0, &f.a0);
        f.a1 = LoadAnim(data, 1, &f.n);
        f.a2 = LoadAnim(data, 4, &f.n);
        f.a3 = LoadAnim(data, 3, &f.n);
        f.a4 = LoadAnim(data, 2, &f.n);
        void *a5 = LoadAnim(data, 5, &f.n);
        void *a6 = LoadAnim(data, 8, &f.n);
        void *a7 = LoadAnim(data, 7, &f.n);
        void *a8 = LoadAnim(data, 6, &f.n);
        f.n = 3;
        if (a5 || a6 || a7 || a8) {
            if (!f.a1 && !f.a2 && !f.a3 && !f.a4) {
                f.a1 = a5;
                f.a2 = a6;
                f.a3 = a7;
                f.a4 = a8;
                a5 = 0;
                a6 = 0;
                a7 = 0;
                a8 = 0;
                f.n = 2;
            }
        } else {
            f.n = 2;
        }
        f.anims[0] = f.a0;
        f.anims[1] = f.a0;
        f.anims[2] = f.a0;
        f.anims[3] = f.a0;
        f.anims[4] = f.a1;
        f.anims[5] = f.a2;
        f.anims[6] = f.a3;
        f.anims[7] = f.a4;
        f.anims[8] = a5;
        f.anims[9] = a6;
        f.anims[10] = a7;
        f.anims[11] = a8;
        void *mem = thunk_FUN_0008d690(0x1330);
        choreo2::LocomotionStrafeDriver *nd = 0;
        if (mem)
            nd = ((choreo2::LocomotionStrafeDriver *)mem)->FUN_00227590(f.layers->FUN_002226b0(), 4, f.n, f.anims, 0);
        driver = nd;
        nd->id.FUN_0027af70(f.idPtr);
        layers = f.layers;
    }
    driver->AddRef();

    StrafeData_23160 *sd = data;
    unsigned int rlo = sd->rigKey.lo;
    unsigned int rhi = sd->rigKey.hi;
    Owner_23160 *own = owner;
    f.idPtr = (Id64_23160 *)driver;
    if ((rlo | rhi) != 0) {
        int r = FUN_00059a30(FUN_000592a0(own))->inner->rig->FUN_0027b670(rlo, rhi);
        if (r != 0)
            ((choreo2::Driver *)f.idPtr)->FUN_002224a0(r);
    }
    layers->FUN_00222890(driver, data->v7(), data->f70, 1.0f, data->f74, data->f78, -1.0f);
    return true;
}
