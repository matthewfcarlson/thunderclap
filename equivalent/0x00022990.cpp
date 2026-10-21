// STATUS: equivalent (tools/equiv.py level 3: 19908 inputs, branch coverage 44/44)
// CProceduralDurationAnimationAction::vfunc_6 @ 0x00022990
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

struct V3_22990 {
    float x, y, z;
};

struct Id64_22990 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_22990 *src);
};

struct Animation {
    char pad0[8];
    Id64_22990 id;
    float f10;
    float f14;
    char flag18;
};

class choreo2_Driver_22990 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_22990 id;            // 8
};

class choreo2_AnimationDriver_22990 : public choreo2_Driver_22990 {
public:
    char pad10[0x10];
    Animation *anim;    // 0x20
    char pad24[0x200];
    char b224;
    char b225;
    char pad226[6];
    float f22c;
    float f230;
    char b234;
    char pad235[0xb];
    choreo2_AnimationDriver_22990 *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3_22990 v);
    void FUN_00225cf0(float v);
};

struct Rig_22990 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Stats_22990 {
    char pad0[0x120];
    struct Inner {
        char pad0[8];
        Rig_22990 *rig;
    } *inner;
};

class Owner_22990;
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Owner_22990 *owner);
Stats_22990 *__fastcall FUN_00059a30(Context *ctx);

struct LayerSet_22990 {
    char pad0[0x64];
    Rig_22990 **rigRef;
    unsigned int count;
    void *FUN_002226b0();
    choreo2_Driver_22990 *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2_AnimationDriver_22990 *d, float r, float a, float b, float c, float e, float f);
};
LayerSet_22990 *__fastcall FUN_00059a40(Context *ctx);

class Factory_22990 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_22990 { Factory_22990 *FUN_00203d70(); };
struct Holder28_22990 { Holder44_22990 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_22990 *holder; };

class Owner_22990 {
public:
    virtual void v0();
};

class ProcData {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad04[0xc];
    float f10;
    float f14;
    unsigned int idLo;
    unsigned int idHi;
    float f20;
    float f24;
    float f28;
    float f2c;
    int mode;
    char pad34[4];
    unsigned int key2Lo;
    unsigned int key2Hi;
    float f40;
    float f44;
    float f48;
    char b4c;
};

void *thunk_FUN_0008d690(unsigned int size);
float FUN_000964e0();
float __cdecl FUN_00225be0(float a, float b, float c, int d);

class CProceduralDurationAnimationAction {
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
    virtual float vfunc_9();
    char pad04[0x18];
    Owner_22990 *owner;                    // 0x1c
    ProcData *data;                  // 0x20
    choreo2_AnimationDriver_22990 *driver; // 0x24
};

bool CProceduralDurationAnimationAction::vfunc_6(int arg)
{
    Context *ctx = FUN_000592a0(owner);
    FUN_00059a30(ctx);
    LayerSet_22990 *layers = FUN_00059a40(ctx);
    if (layers == 0)
        return false;

    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    Factory_22990 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
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
            choreo2_Driver_22990 *d = layers->FUN_00222e20(i);
            if (d->id.lo != lo || d->id.hi != hi)
                continue;
            choreo2_AnimationDriver_22990 *ad = dynamic_cast<choreo2_AnimationDriver_22990 *>(d);
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
        choreo2_AnimationDriver_22990 *nd = (choreo2_AnimationDriver_22990 *)thunk_FUN_0008d690(0x240);
        if (nd != 0)
            nd = nd->FUN_00225950(layers->FUN_002226b0(), anim);
        driver = nd;
        created = true;
    } else {
        created = false;
    }
    driver->AddRef();
    driver->id.FUN_0027af70(&anim->id);

    ProcData *cfg = data;
    unsigned int key2Lo = cfg->key2Lo;
    unsigned int key2Hi = cfg->key2Hi;
    choreo2_AnimationDriver_22990 *drv = driver;
    if ((key2Lo | key2Hi) != 0) {
        int r = FUN_00059a30(FUN_000592a0(owner))->inner->rig->FUN_0027b670(key2Lo, key2Hi);
        if (r != 0)
            drv->FUN_002224a0(r);
    }

    float f40 = data->f40;
    float f44 = data->f44;
    float f48 = data->f48;
    driver->b224 = reuse;
    driver->b225 = data->mode == 3;

    float v9 = vfunc_9();
    float dur = v9 * data->f10;
    float f14 = data->f14;
    float rem = f14 - data->v6();
    if (rem < 0.0f)
        rem = 0.0f;
    if (dur < rem)
        dur = rem;
    float f28 = data->f28;
    float f2c = data->f2c;
    float f20 = data->f20;
    if (driver->b225) {
        float x = f2c;
        if (x == -1.0f)
            x = anim->f10;
        f20 = (x - f28) / anim->f14 / dur;
        dur = -1.0f;
    }
    V3_22990 dir;
    dir.x = f20;
    dir.y = f28;
    dir.z = f2c;
    driver->FUN_00225e00(dur, dir);
    layers->FUN_00222890(driver, dur, f40, 1.0f, f44, f48, -1.0f);
    driver->b234 = data->b4c;

    float f24 = data->f24;
    if (f24 < 0.0f) {
        float lo2 = driver->f22c;
        float span = driver->f230 - lo2;
        float v = FUN_000964e0() * span + lo2;
        driver->FUN_00225cf0(v);
    } else if (created) {
        float value = FUN_00225be0(f24, driver->f22c, driver->f230, 0);
        driver->FUN_00225cf0(value);
    }
    return true;
}
