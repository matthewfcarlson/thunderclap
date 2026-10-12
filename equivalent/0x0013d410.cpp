// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 52/52)
// hulkfight::motion::AnimationAction::vfunc_3 @ 0x0013d410
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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

struct V3 {
    float x, y, z;
};

struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64 *src);
};

struct Animation {
    char pad0[8];
    Id64 id;
    float f10;
    float f14;
    char flag18;
};

class choreo2_Driver {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64 id;            // 8
};

class choreo2_AnimationDriver : public choreo2_Driver {
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
    choreo2_AnimationDriver *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3 v);
    void FUN_00225cf0(float v);
    float FUN_00225b30();
};

struct Rig {
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *owner);

struct LayerSet {
    char pad0[0x64];
    Rig **rigRef;
    unsigned int count;
    Rig *FUN_002226b0();
    choreo2_Driver *FUN_00222e20(unsigned int index);
    void FUN_00222890(choreo2_AnimationDriver *d, float r, float a, float b, float c, float e, float f);
};
LayerSet *__fastcall FUN_00059a40(Context *ctx);

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44 { Factory *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };
struct Manager { char pad0[0x54]; Holder28 *holder; };
extern Manager *DAT_004dd700;

class AnimData {
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
    AnimData *data;                  // 0x1c
    void *owner;                     // 0x20
    choreo2_AnimationDriver *driver; // 0x24
};

bool AnimationAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    LayerSet *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;

    union {
        float v;
        char slot0[4];
    } u;
    float f24;
    Rig *rig = layers->FUN_002226b0();
    unsigned int lo = data->idLo;
    unsigned int hi = data->idHi;
    Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
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
            choreo2_Driver *d = layers->FUN_00222e20(i);
            if (d->id.lo != lo || d->id.hi != hi)
                continue;
            choreo2_AnimationDriver *ad = dynamic_cast<choreo2_AnimationDriver *>(d);
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
    choreo2_AnimationDriver *nd = (choreo2_AnimationDriver *)thunk_FUN_0008d690(0x240);
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

    float f44 = data->f44;
    float f48 = data->f48;
    float f40 = data->f40;
    driver->b224 = reuse;
    driver->b225 = data->mode == 3;

    V3 dir;
    float f28 = data->f28;
    float f2c = data->f2c;
    dir.x = data->f20;
    dir.y = f28;
    dir.z = f2c;
    driver->FUN_00225e00(data->GetValue(), dir);
    if (!data->b34) {
        driver->b235 = 0;
        driver->b234 = data->b34;
    }
    layers->FUN_00222890(driver, driver->FUN_00225b30(), f40, 1.0f, f44, f48, -1.0f);

    f24 = data->f24;
    if (f24 < 0.0f) {
        if (driver->b224) {
            float lo2 = driver->f22c;
            float span = driver->f230 - lo2;
            float v = FUN_000964e0() * span + lo2;
            driver->FUN_00225cf0(v);
        } else {
            driver->FUN_00225cf0(driver->f230);
        }
    } else if (created) {
        driver->FUN_00225cf0(FUN_00225be0(f24, driver->f22c, driver->f230, 0));
    }
    return true;
}
