// STATUS: equivalent (tools/equiv.py level 3: 19980 inputs, branch coverage 52/52)
// hulkfight::motion::AnimationAction::vfunc_3 @ 0x0013d410
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) { return p; }

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

struct V3_13d410 {
    float x, y, z;
};

struct Id64_13d410 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_13d410 *src);
};

struct Animation {
    char pad0[8];
    Id64_13d410 id;
    float f10;
    float f14;
    char flag18;
};

class choreo2_Driver_13d410 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_13d410 id;            // 8
};

class choreo2_AnimationDriver_13d410 : public choreo2_Driver_13d410 {
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
    char b235;
    char pad236[6];
    float f23c;
    choreo2_AnimationDriver_13d410 *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3_13d410 v);
    void FUN_00225cf0(float v);
    float FUN_00225b30();
};

struct Rig_13d410 {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *owner);

struct LayerSet_13d410 {
    char pad0[0x64];
    Rig_13d410 **rigRef;
    unsigned int count;
    Rig_13d410 *FUN_002226b0();
    choreo2_Driver_13d410 *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2_AnimationDriver_13d410 *d, float r, float a, float b, float c, float e, float f);
};
LayerSet_13d410 *__fastcall FUN_00059a40(Context *ctx);

class Factory_13d410 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_13d410 { Factory_13d410 *FUN_00203d70(); };
struct Holder28_13d410 { Holder44_13d410 *FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_13d410 *holder; };

class AnimData_13d410 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetValue();
    char pad4[0x14];
    unsigned int idLo;
    unsigned int idHi;
    float f20;
    float f24;
    float f28;
    float f2c;
    int mode;
    char b34;
    char pad35[3];
    unsigned int key2Lo;
    unsigned int key2Hi;
    float f40;
    float f44;
    float f48;
};

void *thunk_FUN_0008d690(unsigned int size);
float FUN_000964e0();
float __cdecl FUN_00225be0(float a, float b, float c, int d);

class AnimationAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    AnimData_13d410 *data;                  // 0x1c
    void *owner;                     // 0x20
    choreo2_AnimationDriver_13d410 *driver; // 0x24
};

bool AnimationAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    LayerSet_13d410 *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;

    union {
        hulk_freg v;
        char slot0[4];
    } u;
    hulk_freg f24;
    Rig_13d410 *rig = layers->FUN_002226b0();
    unsigned int lo = data->idLo;
    unsigned int hi = data->idHi;
    Factory_13d410 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
        new (u.slot0) content::LoadInventory::DynamicCaster<pure3d::Animation>;
    Animation *anim = factory->f3(caster, lo, hi);
    if (anim == 0)
        return false;

    bool reuse;
    bool found = false;
    int mode = data->mode;
    if (mode == 2 || (mode == 0 && anim->flag18)) {
        reuse = true;
        for (unsigned int i = 0; i < layers->count; i++) {
            choreo2_Driver_13d410 *d = layers->FUN_00222e20(i);
            if (d->id.lo != lo || d->id.hi != hi)
                continue;
            choreo2_AnimationDriver_13d410 *ad = dynamic_cast<choreo2_AnimationDriver_13d410 *>(d);
            if (ad != 0 && ad->anim == anim) {
                u.v = ad->f23c;
                found = true;
                break;
            }
        }
    } else {
        reuse = false;
    }

    bool created;
    choreo2_AnimationDriver_13d410 *nd = (choreo2_AnimationDriver_13d410 *)thunk_FUN_0008d690(0x240);
    if (nd != 0)
        nd = nd->FUN_00225950(rig, anim);
    if (nd != 0)
        nd->AddRef();
    if (driver != 0)
        driver->Release();
    driver = nd;
    if (found && !(u.v < 0.0f)) {
        nd->FUN_00225cf0(u.v);
        created = false;
    } else {
        created = true;
    }
    driver->id.FUN_0027af70(&anim->id);

    if ((data->key2Lo | data->key2Hi) != 0) {
        int r = rig->FUN_0027b670(data->key2Lo, data->key2Hi);
        if (r != 0)
            driver->FUN_002224a0(r);
    }

    hulk_freg f44 = data->f44;
    hulk_freg f48 = data->f48;
    hulk_freg f40 = data->f40;
    driver->b224 = reuse;
    driver->b225 = data->mode == 3;

    V3_13d410 dir;
    hulk_freg f28 = data->f28;
    hulk_freg f2c = data->f2c;
    dir.x = data->f20;
    dir.y = f28;
    dir.z = f2c;
    float arg1 = data->GetValue();
    driver->FUN_00225e00(arg1, dir);
    if (!data->b34) {
        driver->b235 = 0;
        driver->b234 = data->b34;
    }
    float arg2 = driver->FUN_00225b30();
    layers->FUN_00222890(driver, arg2, f40, 1.0f, f44, f48, -1.0f);

    f24 = data->f24;
    if (f24 < 0.0f) {
        if (driver->b224) {
            hulk_freg lo2 = driver->f22c;
            hulk_freg span = driver->f230 - lo2;
            hulk_freg v = FUN_000964e0() * span + lo2;
            driver->FUN_00225cf0(v);
        } else {
            driver->FUN_00225cf0(driver->f230);
        }
    } else if (created) {
        float arg3 = FUN_00225be0(f24, driver->f22c, driver->f230, 0);
        driver->FUN_00225cf0(arg3);
    }
    return true;
}
