// STATUS: equivalent (tools/equiv.py level 3: 1020 inputs, branch coverage 35/40, incomplete)
// hulkfight::motion::AnimationLinkedAction::vfunc_3 @ 0x0013e070
// equiv-map: ?FUN_0008d690@@YAPAXI@Z = 0x00263ea0
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
    char pad24[0x218];
    float value;        // 0x23c
    choreo2_AnimationDriver *FUN_00225950(void *rig, Animation *anim);
    void FUN_002224a0(int v);
    void FUN_00225e00(float t, V3 v);
    void FUN_00225cf0(float v);
    float FUN_00225b30();
};

struct Rig {
    char pad0[0x34];
    int vec34;
    int vec38;
    int FUN_0027b670(unsigned int lo, unsigned int hi);
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct LayerSet {
    char pad0[0x64];
    Rig **rigRef;
    unsigned int count;
    Rig *FUN_002226b0();
    choreo2_Driver *FUN_00222e20(unsigned int index);
    int FUN_00222bf0(choreo2_Driver *d);
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
    unsigned int idLo;      // 0x18
    unsigned int idHi;      // 0x1c
    V3 posA;                // 0x20
    char pad2c[4];
    unsigned int id2Lo;     // 0x30
    unsigned int id2Hi;     // 0x34
    V3 posB;                // 0x38
};

void *__cdecl FUN_0008d690(unsigned int size);

class AnimationLinkedAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    AnimData *data;                 // 0x1c
    void *owner;                    // 0x20
    choreo2_AnimationDriver *driver; // 0x24
};

bool AnimationLinkedAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    LayerSet *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;
    struct Frame {
        content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
        Rig *rig;
        unsigned int lo;
        unsigned int hi;
    } fr;
    fr.rig = layers->FUN_002226b0();
    fr.lo = data->idLo;
    fr.hi = data->idHi;
    Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    Animation *anim = factory->f3(&fr.caster, fr.lo, fr.hi);
    Rig *rig = fr.rig;
    unsigned int lo = fr.lo;
    unsigned int hi = fr.hi;
    if (anim == 0)
        return false;
    float best = -1.0f;
    int bestKey = 0x7fffffff;
    for (unsigned int i = 0; i < layers->count; i++) {
        choreo2_Driver *d = layers->FUN_00222e20(i);
        if (d->id.lo != lo || d->id.hi != hi)
            continue;
        int key = layers->FUN_00222bf0(d);
        if (key > bestKey)
            continue;
        choreo2_AnimationDriver *ad = dynamic_cast<choreo2_AnimationDriver *>(d);
        if (ad == 0 || ad->anim != anim)
            continue;
        float v = ad->value;
        if (key < bestKey || v > best) {
            best = v;
            bestKey = key;
        }
    }
    choreo2_AnimationDriver *nd = (choreo2_AnimationDriver *)FUN_0008d690(0x240);
    if (nd != 0)
        nd = nd->FUN_00225950(rig, anim);
    if (nd != 0)
        nd->AddRef();
    if (driver != 0)
        driver->Release();
    driver = nd;
    nd->id.FUN_0027af70(&anim->id);
    if ((data->id2Lo | data->id2Hi) != 0) {
        int r = rig->FUN_0027b670(data->id2Lo, data->id2Hi);
        if (r != 0)
            driver->FUN_002224a0(r);
    }
    AnimData *dd = data;
    V3 pa = dd->posA;
    V3 pb = dd->posB;
    driver->FUN_00225e00(dd->GetValue(), pa);
    driver->FUN_00225cf0(data->posA.y);
    float lim = data->posA.z;
    if (best > 0.0f && best < lim) {
        float t = driver->FUN_00225b30();
        if (t > 0.0f) {
            V3 vv;
            vv.x = 1.0f;
            vv.y = best;
            vv.z = lim;
            driver->FUN_00225e00(t, vv);
            driver->FUN_00225cf0(best);
        }
    }
    layers->FUN_00222890(driver, driver->FUN_00225b30(), pb.x, 1.0f, pb.y, pb.z, -1.0f);
    return true;
}
