// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// hulkfight::motion::PropAnimationAction::vfunc_3 @ 0x0018b4e0
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *FUN_00263ea0(unsigned int size);

namespace pure3d { class Animation; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Anim_18b4e0 {
    char pad00[0x10];
    float f10;
    char pad14[4];
    char flag18;
};

class Controller_18b4e0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(unsigned int g);
    virtual void v13();
    virtual void v14(unsigned int g, float t);
    virtual void v15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(Anim_18b4e0 *anim, unsigned int g, float t);
    char pad[0x150 - 4];
    Controller_18b4e0 *FUN_00287860();
    void FUN_00288080(int a);
    void FUN_00284ad0(int a);
};

class Entity {
public:
    virtual void AddRef();
    virtual void Release();
    int FUN_001d68d0();
    void FUN_0027e650(Controller_18b4e0 *c, unsigned int g, float t);
};

struct Loader_18b4e0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Anim_18b4e0 *v3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo, unsigned int hi);
};

struct Mid_18b4e0 {
    Loader_18b4e0 *FUN_00203d70();
};

struct Mgr54_18b4e0 {
    Mid_18b4e0 *FUN_000862a0();
};

struct Game_18b4e0 {
    char pad0[0x54];
    Mgr54_18b4e0 *f54;
};

struct Stats_18b4e0 {
    char pad0[0x128];
    Entity *f128;
    Entity *FUN_00035ef0(int i);
};

struct Spec_18b4e0 {
    char pad00[0x14];
    int index;
    unsigned int keyLo;
    unsigned int keyHi;
    int f20;
    unsigned int f24;
    float f28;
    int kind;
};

struct Owner;
Owner *__fastcall FUN_000592a0(void *p);
Stats_18b4e0 *__fastcall FUN_00059a30(Owner *o);

extern Game_18b4e0 *DAT_004dd700;

class PropAnimationAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    virtual void v4();
    virtual void v5();
    char pad04[0x1c - 4];
    Spec_18b4e0 *spec;
    void *owner;
    Entity *entity;
    Controller_18b4e0 *ctrl;
};

bool PropAnimationAction::vfunc_3(int a, int b)
{
    if (!owner)
        return false;
    Stats_18b4e0 *stats = FUN_00059a30(FUN_000592a0(owner));
    int k = spec->index;
    Entity *e;
    if (stats) {
        if (k < 0)
            e = stats->f128;
        else if (k < 8)
            e = stats->FUN_00035ef0(k);
        else
            e = 0;
    } else {
        e = 0;
    }
    if (e)
        e->AddRef();
    if (entity)
        entity->Release();
    entity = e;
    if (!e)
        return false;

    struct Frame {
        float t;
        content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
        unsigned int g;
    } f;
    Loader_18b4e0 *loader = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70();
    new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
    Anim_18b4e0 *anim = loader->v3(&f.caster, spec->keyLo, spec->keyHi);
    if (!anim)
        return false;
    f.t = spec->f28;
    f.g = spec->f24;
    if (spec->f28 < 0.0f)
        f.t = anim->f10;

    void *mem = FUN_00263ea0(0x150);
    Controller_18b4e0 *c = mem ? ((Controller_18b4e0 *)mem)->FUN_00287860() : 0;
    if (c)
        c->AddRef();
    if (ctrl)
        ctrl->Release();
    ctrl = c;
    unsigned int g = f.g;
    float t = f.t;
    c->v24(anim, g, t);
    ctrl->FUN_00288080(entity->FUN_001d68d0());
    ctrl->FUN_00284ad0(1);
    entity->FUN_0027e650(ctrl, g, t);
    ctrl->v14(g, t);
    ctrl->v12(g);
    ctrl->v8(spec->f20);
    ctrl->v16(2);
    if (spec->kind == 2 || (spec->kind == 0 && anim->flag18))
        ctrl->v18(0);
    else
        ctrl->v18(1);
    return true;
}
