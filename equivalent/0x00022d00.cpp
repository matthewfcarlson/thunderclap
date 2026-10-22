// STATUS: equivalent (tools/equiv.py level 3: 19940 inputs, branch coverage 42/42)
// CStunAnimationAction::vfunc_6 @ 0x00022d00
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"

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

struct V3_22d00 {
    float x, y, z;
};

struct Id64_22d00 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_22d00 *src);
};

struct Animation {
    char pad0[8];
    Id64_22d00 id;
    char pad10[8];
    char flag18;
};

class choreo2_Driver_22d00 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_22d00 id;            // 8
};

class AnimationDriver_22d00 : public choreo2_Driver_22d00 {
public:
    char pad10[0x10];
    Animation *anim;    // 0x20
    char pad24[0x200];
    char b224;
    char b225;
    char pad226[6];
    float f22c;
    float f230;
    char pad234[0xc];
    AnimationDriver_22d00 *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3_22d00 v);
    void FUN_00225cf0(float v);
};

struct Rig_22d00 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Stats_22d00 {
    char pad0[0x120];
    struct Inner {
        char pad0[8];
        Rig_22d00 *rig;
    } *inner;
};

class Owner_22d00;
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Owner_22d00 *owner);
Stats_22d00 *__fastcall FUN_00059a30(Context *ctx);

struct LayerSet_22d00 {
    char pad0[0x64];
    Rig_22d00 **rigRef;
    unsigned int count;
    void *FUN_002226b0();
    choreo2_Driver_22d00 *FUN_00222e20(unsigned int index);
    void FUN_00222890(AnimationDriver_22d00 *d, float r, float a, float b, float c, float e, float f);
};
LayerSet_22d00 *__fastcall FUN_00059a40(Context *ctx);

class Factory_22d00 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_22d00 { Factory_22d00 *FUN_00203d70(); };
struct Holder28_22d00 { Holder44_22d00 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_22d00 *holder; };

struct Speed_22d00 {
    char pad0[0x68];
    float speed;
};

class Owner_22d00 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Speed_22d00 *GetSpeed();
};

struct StunData {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    float f18;
    float f1c;
    float f20;
    float f24;
    int mode;
    char pad2c[4];
    unsigned int key2Lo;
    unsigned int key2Hi;
    float f38;
    float f3c;
    float f40;
};

void *thunk_FUN_0008d690(unsigned int size);
float FUN_000964e0();
float __cdecl FUN_00225be0(float a, float b, float c, int d);

class CStunAnimationAction {
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
    Owner_22d00 *owner;                    // 0x1c
    StunData *data;                  // 0x20
    AnimationDriver_22d00 *driver; // 0x24
};

bool CStunAnimationAction::vfunc_6(int arg)
{
    LayerSet_22d00 *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;

    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    Factory_22d00 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    unsigned int lo = data->idLo;
    unsigned int hi = data->idHi;
    Animation *anim = factory->f3(&caster, lo, hi);
    if (anim == 0)
        return false;

    bool reuse;
    int mode = data->mode;
    if (mode == 2 || (mode == 0 && anim->flag18)) {
        reuse = true;
        for (unsigned int i = 0; i < layers->count; i++) {
            choreo2_Driver_22d00 *d = layers->FUN_00222e20(i);
            if (d->id.lo != lo || d->id.hi != hi)
                continue;
            AnimationDriver_22d00 *ad = dynamic_cast<AnimationDriver_22d00 *>(d);
            if (ad != 0 && ad->anim == anim) {
                driver = ad;
                break;
            }
        }
    } else {
        reuse = false;
    }

    bool created;
    if (driver == 0) {
        AnimationDriver_22d00 *nd = (AnimationDriver_22d00 *)thunk_FUN_0008d690(0x240);
        if (nd != 0)
            nd = nd->FUN_00225950(layers->FUN_002226b0(), anim);
        driver = nd;
        created = true;
    } else {
        created = false;
    }
    driver->AddRef();
    driver->id.FUN_0027af70(&anim->id);

    StunData *cfg = data;
    unsigned int key2Lo = cfg->key2Lo;
    unsigned int key2Hi = cfg->key2Hi;
    AnimationDriver_22d00 *drv = driver;
    if ((key2Lo | key2Hi) != 0) {
        int r = FUN_00059a30(FUN_000592a0(owner))->inner->rig->FUN_0027b670(key2Lo, key2Hi);
        if (r != 0)
            drv->FUN_002224a0(r);
    }

    float f38 = data->f38;
    float f3c = data->f3c;
    float f40 = data->f40;
    driver->b224 = reuse;
    driver->b225 = data->mode == 3;

    Speed_22d00 *sp = owner->GetSpeed();
    if (sp == 0)
        return false;
    float speed = sp->speed;
    if (speed < 0.0f)
        speed = 0.0f;
    float lead;
    if (driver->b225)
        lead = -1.0f;
    else
        lead = speed;

    V3_22d00 dir;
    dir.x = data->f18;
    dir.y = data->f20;
    dir.z = data->f24;
    driver->FUN_00225e00(lead, dir);
    layers->FUN_00222890(driver, speed, f38, 1.0f, f3c, f40, -1.0f);

    float f1c = data->f1c;
    if (f1c < 0.0f) {
        float lo2 = driver->f22c;
        float span = driver->f230 - lo2;
        float v = FUN_000964e0() * span + lo2;
        driver->FUN_00225cf0(v);
    } else if (created) {
        float value = FUN_00225be0(f1c, driver->f22c, driver->f230, 0);
        driver->FUN_00225cf0(value);
    }
    return true;
}
