// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 16/16)
// hulkfight::motion::AnimationChargeAction::vfunc_3 @ 0x0013de80
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

inline void *operator new(unsigned int, void *p) { return p; }
extern void *__cdecl FUN_00263ea0(unsigned int size);

struct Name {
    unsigned int lo, hi;
    void FUN_0027af70(const Name *other);
};

struct Handle {
    char pad0[8];
    Name name;
};

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct Holder44 { Factory *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };
struct Manager { char pad0[0x54]; Holder28 *holder; };
extern Manager *DAT_004dd700;

struct Sub {
    void *FUN_0027b670(int lo, int hi);
};

class Anim {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Name name;
    char pad10[0x224 - 0x10];
    char flag224;
    char flag225;
    char pad226[2];
    int i228;
    float f22c;
    float f230;
    Anim *FUN_00225950(Sub *skel, Handle *h);
    void FUN_00225e00(float a, int b, int c, int d);
    void FUN_00225cf0(float t);
    void FUN_002224a0(void *p);
    float FUN_00225b30();
};

struct Body {
    Sub *FUN_002226b0();
    void FUN_00222890(Anim *a, float t, int c30, float one, int c34, int c38, float m1);
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);

struct Stats {
    char pad0[0x1e58];
    float time;
};
Stats *__fastcall FUN_00059a30(Fighter *f);
Body *__fastcall FUN_00059a40(Fighter *f);

float __cdecl FUN_000186b0(float *value, float *lo, float *hi);

struct Config {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};

class AnimationChargeAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int a, int b);
    char pad04[0x18];
    Config *cfg;
    void *owner;
    Anim *anim;
};

struct Frame {
    char slot0[4];
    Sub *skel;
    union {
        Stats *stats;
        float time;
    } u;
    float one;
    float zero;
};

char AnimationChargeAction::vfunc_3(int a, int b)
{
    Frame fr;
    if (!owner)
        return 0;
    Fighter *fighter = FUN_000592a0(owner);
    fr.u.stats = FUN_00059a30(fighter);
    Body *body = FUN_00059a40(fighter);
    if (!body)
        return 0;
    fr.skel = body->FUN_002226b0();
    int c18 = cfg->f18;
    int c1c = cfg->f1c;
    Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
        new (fr.slot0) content::LoadInventory::DynamicCaster<pure3d::Animation>;
    Handle *handle = factory->f3(caster, c18, c1c);
    if (!handle)
        return 0;
    Anim *created;
    void *mem = FUN_00263ea0(0x240);
    if (mem)
        created = ((Anim *)mem)->FUN_00225950(fr.skel, handle);
    else
        created = 0;
    if (created)
        created->AddRef();
    if (anim)
        anim->Release();
    anim = created;
    created->name.FUN_0027af70(&handle->name);
    anim->flag224 = 0;
    anim->flag225 = 1;
    anim->FUN_00225e00(-1.0f, 0, cfg->f20, cfg->f24);
    anim->i228 = 0;
    Anim *a2 = anim;
    float *lo = (float *)fr.slot0;
    *lo = a2->f22c;
    fr.u.time = fr.u.stats->time;
    fr.one = 1.0f;
    fr.zero = 0.0f;
    float r = FUN_000186b0(&fr.u.time, &fr.zero, &fr.one);
    a2->FUN_00225cf0((a2->f230 - *lo) * r + *lo);
    int c28 = cfg->f28;
    int c2c = cfg->f2c;
    if ((c28 | c2c) != 0) {
        void *p = fr.skel->FUN_0027b670(c28, c2c);
        if (p)
            anim->FUN_002224a0(p);
    }
    Config *c = cfg;
    int c30 = c->f30;
    int c34 = c->f34;
    int c38 = c->f38;
    body->FUN_00222890(anim, anim->FUN_00225b30(), c30, 1.0f, c34, c38, -1.0f);
    return 1;
}
