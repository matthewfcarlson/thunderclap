// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 38/38)
// hulkfight::motion::GrappleLocomotionSteerAction::vfunc_3 @ 0x00164690
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
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern char DAT_0048d534[];
extern char DAT_004b3b20[];

struct Name_164690 {
    unsigned int lo, hi;
    void FUN_0027af70(const Name_164690 *other);
};

struct Handle_164690 {
    char pad0[8];
    Name_164690 name;
};

class Factory_164690 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle_164690 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44_164690 { Factory_164690 *FUN_00203d70(); };
struct Holder28_164690 { Holder44_164690 *FUN_000862a0(); };
struct Manager_164690 { char pad0[0x54]; Holder28_164690 *holder; };
extern Manager_164690 *DAT_004dd700;

struct Sub_164690 { char pad[4]; };

struct Cand {
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Name_164690 name;
    char pad10[0x24 - 0x10];
    float value;
};

struct Anims {
    Handle_164690 *a1;
    Handle_164690 *a2;
    Handle_164690 *a3;
};

class Blend_164690 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Name_164690 name;
    Blend_164690 *FUN_00229760(Sub_164690 *skel, int zero, int mode, Anims *anims, int zero2);
    void FUN_00222550(int a, int b);
};

struct Body;
struct Item;

struct Track {
    char pad0[0x68];
    unsigned int count;
    Item *FUN_00222e20(unsigned int index);
    Sub_164690 *FUN_002226b0();
    void FUN_00222890(Blend_164690 *a, float t, int c40, float one, int c44, int c48, float m1);
};

struct Fighter_164690 { char pad[4]; };
Fighter_164690 *__fastcall FUN_000592a0(void *owner);
void *__fastcall FUN_00059a30(Fighter_164690 *f);
Track *__fastcall FUN_00059a40(Fighter_164690 *f);
void __cdecl FUN_0015cfd0(Sub_164690 *skel, Blend_164690 *b);

class Config_164690 {
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
    Name_164690 key;
    Name_164690 id1;
    Name_164690 id2;
    Name_164690 id3;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
};

class GrappleLocomotionSteerAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    Config_164690 *cfg;
    void *owner;
    Blend_164690 *cur;
};

bool GrappleLocomotionSteerAction::vfunc_3(int a, int b)
{
    struct Frame {
        union {
            Cand *found;
            char caster[4];
        } s0;
        union {
            float foundValue;
            Handle_164690 *anim1;
            char caster[4];
        } s1;
        Sub_164690 *skel;
        Name_164690 *keyPtr;
        unsigned int keyHi;
        float tmp;
        Anims anims;
    } fr;

    Fighter_164690 *fighter = FUN_000592a0(owner);
    FUN_00059a30(fighter);
    Track *track = FUN_00059a40(fighter);
    if (!track)
        return false;

    fr.skel = track->FUN_002226b0();
    unsigned int keyLo = cfg->key.lo;
    fr.keyHi = cfg->key.hi;
    fr.s1.foundValue = -1.0f;
    fr.s0.found = 0;

    for (unsigned int i = 0; i < track->count; i++) {
        Cand *c = (Cand *)FUN_00344e74(track->FUN_00222e20(i), 0, DAT_0048d534, DAT_004b3b20, 0);
        if (!c)
            continue;
        if (fr.s1.foundValue < 0.0f)
            fr.s1.foundValue = c->value;
        if ((keyLo | fr.keyHi) != 0 && c->name.lo == keyLo && c->name.hi == fr.keyHi) {
            fr.s0.found = c;
            break;
        }
    }

    if (fr.s0.found)
        fr.s0.found->AddRef();
    if (cur)
        cur->Release();
    cur = (Blend_164690 *)fr.s0.found;

    if (!fr.s0.found) {
        Config_164690 *c0 = cfg;
        fr.keyPtr = &c0->key;
        unsigned int lo1 = c0->id1.lo;
        unsigned int hi1 = c0->id1.hi;
        Factory_164690 *factory;
        if ((lo1 | hi1) == 0) {
            fr.s1.anim1 = 0;
        } else {
            factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (fr.s1.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            fr.s1.anim1 = factory->f3(caster, lo1, hi1);
        }

        unsigned int lo2 = cfg->id2.lo;
        unsigned int hi2 = cfg->id2.hi;
        Handle_164690 *anim2;
        if ((lo2 | hi2) == 0) {
            anim2 = 0;
        } else {
            factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (fr.s0.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            anim2 = factory->f3(caster, lo2, hi2);
        }

        unsigned int lo3 = cfg->id3.lo;
        unsigned int hi3 = cfg->id3.hi;
        Handle_164690 *anim3;
        if ((lo3 | hi3) == 0) {
            anim3 = 0;
        } else {
            factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
            content::LoadInventory::DynamicCaster<pure3d::Animation> *caster =
                new (fr.s0.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            anim3 = factory->f3(caster, lo3, hi3);
        }

        int mode = 3;
        if (!anim2) {
            anim2 = anim3;
            mode = 2;
        } else if (!anim3) {
            mode = 2;
        }

        fr.anims.a1 = fr.s1.anim1;
        fr.anims.a2 = anim2;
        fr.anims.a3 = anim3;
        Blend_164690 *created;
        void *mem = FUN_00263ea0(0x910);
        if (mem)
            created = ((Blend_164690 *)mem)->FUN_00229760(fr.skel, 0, mode, &fr.anims, 0);
        else
            created = 0;
        if (created)
            created->AddRef();
        if (cur)
            cur->Release();
        cur = created;
        created->name.FUN_0027af70(fr.keyPtr);
    }

    cur->FUN_00222550(cfg->f38, cfg->f3c);
    FUN_0015cfd0(fr.skel, cur);
    fr.tmp = cfg->v7();
    Config_164690 *c = cfg;
    track->FUN_00222890(cur, fr.tmp, c->f40, 1.0f, c->f44, c->f48, -1.0f);
    return true;
}
