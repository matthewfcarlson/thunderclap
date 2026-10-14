// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 6/6)
// CKeyPoseAction::vfunc_6 @ 0x00022ff0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

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

struct Id64_22ff0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(Id64_22ff0 *src);
};

struct Animation {
    char pad0[8];
    Id64_22ff0 id;
};

class choreo2_Driver_22ff0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    Id64_22ff0 id;            // 8
};

class choreo2_AnimationDriver_22ff0 : public choreo2_Driver_22ff0 {
public:
    char pad10[0x214];
    char b224;
    char b225;
    char pad226[0xe];
    char b234;
    char pad235[0xb];
    choreo2_AnimationDriver_22ff0 *FUN_00225950(void *rig, Animation *anim);
};

class Owner;
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Owner *owner);

struct LayerSet_22ff0 {
    char pad0[0x64];
    void *FUN_002226b0();
    void FUN_00222890(choreo2_AnimationDriver_22ff0 *d, float a, float b, float c, float e, float f, float g);
};
LayerSet_22ff0 *__fastcall FUN_00059a40(Context *ctx);

class Factory_22ff0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Animation *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo,
                          unsigned int hi);
};

struct Holder44_22ff0 { Factory_22ff0 *FUN_00203d70(); };
struct Holder28_22ff0 { Holder44_22ff0 *FUN_000862a0(); };
struct Manager_22ff0 { char pad0[0x54]; Holder28_22ff0 *holder; };
extern Manager_22ff0 *DAT_004dd700;

struct PoseBinding {
    char pad00[0x10];
    unsigned int idLo;
    unsigned int idHi;
    char pad18[0x40];
    char b58;
    char pad59[7];
    char sub60[8];
    float f68;
    float f6c;
    float f70;
};

void *thunk_FUN_0008d690(unsigned int size);
extern void __cdecl FUN_000139b0(void *sub, Owner *owner, choreo2_AnimationDriver_22ff0 *driver);

class CKeyPoseAction {
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
    bool FUN_000149e0(int flag);
    char pad04[0x18];
    Owner *owner;                    // 0x1c
    PoseBinding *binding;            // 0x20
    choreo2_AnimationDriver_22ff0 *driver; // 0x24
};

bool CKeyPoseAction::vfunc_6(int arg)
{
    LayerSet_22ff0 *layers = FUN_00059a40(FUN_000592a0(owner));
    if (layers == 0)
        return false;

    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    unsigned int lo = binding->idLo;
    unsigned int hi = binding->idHi;
    Factory_22ff0 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    Animation *anim = factory->f3(&caster, lo, hi);
    if (anim == 0)
        return false;

    choreo2_AnimationDriver_22ff0 *nd = (choreo2_AnimationDriver_22ff0 *)thunk_FUN_0008d690(0x240);
    if (nd != 0)
        nd = nd->FUN_00225950(layers->FUN_002226b0(), anim);
    driver = nd;
    driver->id.FUN_0027af70(&anim->id);
    driver->AddRef();
    driver->b224 = 0;
    driver->b225 = 1;
    driver->b234 = binding->b58;
    FUN_000139b0(binding->sub60, owner, driver);
    layers->FUN_00222890(driver, -1.0f, binding->f68, 1.0f, binding->f6c, binding->f70, -1.0f);
    return FUN_000149e0(1);
}
