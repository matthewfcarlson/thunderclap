// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00181cc0..0x00181f70 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropActorThinkingAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f945e56f {
#define TREE_TU_END }
namespace fn_f945e56f {} using namespace fn_f945e56f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f945e56f {
extern char DAT_00494b44;
extern char DAT_00494b60;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Actor;
struct Owner { Actor* FUN_00059a30(); };
struct Input {  };
struct Object { char pad[0x1c9]; unsigned char state; };
struct Entry { char pad[8]; Object* object; int kind; };
struct Actor { char pad[0x3a4]; Entry* entry; };
struct PropGrabbableIsThrownCondition_181cc0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual int vfunc_6(int, Input*, int); char pad[8]; unsigned char state; };
struct Vec3_181d30 {
    float x, y, z;
};
struct Actor_181d30;
struct Obj70_181d30 {
    void FUN_002f5a20(Vec3_181d30 *v);
};
struct Node70 {
    char pad00[0x70];
    Obj70_181d30 *f70;
};
struct Holder_181d30 {
    char pad00[8];
    Entity *target;
    int kind;
};
struct Obj284 {
    void FUN_002845a0();
};
struct Obj5e80 {
    int FUN_001d5e80(int v);
};
struct Ptr11c {
    char pad00[0x18];
    Obj284 *f18;
};
struct Entity {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0x40 - 4];
    int f40;
    char pad44[0xec - 0x44];
    Obj5e80 *fec;
    char padf0[0x11c - 0xf0];
    Ptr11c *f11c;
    char pad120[0x148 - 0x120];
    Actor_181d30 *f148;
    void FUN_001d6cc0(float v);
    void FUN_001d7510();
    void FUN_001d7e70();
};
struct Actor_181d30 {
    char pad00[0x128];
    Entity *f128;
    void *f12c;
    char pad130[0x3a4 - 0x130];
    Holder_181d30 *f3a4;
    char pad3a8[0x22e8 - 0x3a8];
    char b22e8;
    void FUN_0003a570();
    char FUN_00035660(Vec3_181d30 *out);
    void FUN_00037420(int v);
    void FUN_000385a0(void *a, int v);
};
struct Param1c {
    char pad00[0x10];
    int idx;
    char b14;
};
struct Res_181d30 {
    char pad00[0x10];
    Actor_181d30 *actor;
    Actor_181d30 *FUN_00059a30();
};
struct T20 {
};
struct Target_181d30 {
    char pad00[0x328];
    void *f328;
    void FUN_0003ffa0(Node70 *n, int v);
};
struct Mgr0c {
    void FUN_001dcd30(int v);
    void FUN_001dc170(Entity *e, int v);
};
struct Ctx20_181d30 {
    char pad00[0x124];
    Target_181d30 *f124;
};
} // namespace fn_f945e56f
struct World {
    char pad00[0xc];
    Mgr0c *f0c;
    char pad10[0x20 - 0x10];
    Ctx20_181d30 *f20;
};
namespace fn_f945e56f {
class Thing_181d30 {
public:
    char pad00[0x1c];
    Param1c *f1c;
    T20 *f20;
    char FUN_00181d30();
};
class Model_181ed0 {
  public:
    char pad[0x128];
    void* field;
    void Apply(void*, void*);
};
class Actor_181ed0 {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    Model_181ed0* ModelFor();
};
struct Vec_181ed0 {
    int a, b, c;
};


// 0x00181cc0 hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_6 (98 B): equivalent/0x00181cc0.cpp
// sym: ?vfunc_6@PropGrabbableIsThrownCondition_181cc0@fn_f945e56f@@UAEHHPAUInput@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_6 @ 0x00181cc0
int PropGrabbableIsThrownCondition_181cc0::vfunc_6(int, Input* input, int) {
    if (!FUN_00344e74(input, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    Actor* actor = ((Owner *)((owners::Object_592a0 *)input)->FUN_000592a0())->FUN_00059a30();
    Entry* entry = actor->entry;
    if (!entry) return 0;
    if (entry->kind != 5) return (hulk_uintptr)entry & ~255u;
    Object* object = entry->object;
    if (!object) return 0;
    return object->state == state;
}


// 0x00181d30 FUN_00181d30 (415 B): equivalent/0x00181d30.cpp
// sym: ?FUN_00181d30@Thing_181d30@fn_f945e56f@@QAEDXZ
// STATUS: equivalent (tools/equiv.py level 3: 3055 inputs, branch coverage 34/34)
// FUN_00181d30 @ 0x00181d30
char Thing_181d30::FUN_00181d30()
{
    Actor_181d30 *ebp = ((Res_181d30 *)((owners::Object_592a0 *)f20)->FUN_000592a0())->FUN_00059a30();
    int idx = f1c->idx;
    Entity *e = 0;

    if (ebp) {
        if (idx < 0)
            e = ebp->f128;
        else if (idx < 8)
            e = ((Entity *)((owners::C_35ef0 *)ebp)->FUN_00035ef0((hulk_intptr)idx));
    }
    if (!e) {
        Holder_181d30 *h = ebp->f3a4;
        if (!h || h->kind != 5)
            return 0;
        e = h->target;
        if (!e)
            return 0;
    }
    if (!e->f148)
        return 0;

    e->vfunc_0();
    Actor_181d30 *a = e->f148;
    a->FUN_0003a570();
    int f40 = e->f40;
    e->f148 = 0;
    if (e->fec->FUN_001d5e80(f40) == 4 && a)
        a->b22e8 = 1;
    e->f11c->f18->FUN_002845a0();
    if (f1c->b14) {
        Vec3_181d30 v;
        e->FUN_001d7e70();
        e->FUN_001d7510();
        a->FUN_00035660(&v);
        ((Node70 *)((owners::C_1d72e0 *)e)->FUN_001d72e0())->f70->FUN_002f5a20(&v);
        e->FUN_001d6cc0(3.0f);
    }
    Mgr0c *m = DAT_004dd700->f0c;
    m->FUN_001dcd30(((owners::C_1d6c70 *)e)->FUN_001d6c70());
    DAT_004dd700->f0c->FUN_001dc170(e, 0);
    Target_181d30 *t = DAT_004dd700->f20->f124;
    if (t && t->f328 && t->f328 == a->f12c)
        t->FUN_0003ffa0(((Node70 *)((owners::C_1d72e0 *)e)->FUN_001d72e0()), 0);
    if (a) {
        if (a != ebp && ebp->f12c)
            a->FUN_000385a0(ebp->f12c, 0);
        a->FUN_00037420(1);
    }
    e->vfunc_1();
    return 1;
}

} // namespace fn_f945e56f

// 0x00181ed0 hulkfight::motion::PropActorThinkingAction::vfunc_3 (123 B): matches/0x00181ed0.cpp
// sym: ?vfunc_3@PropActorThinkingAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::PropActorThinkingAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Actor_181ed0* x = (*(Actor_181ed0 * *)&this->f_20);
    Actor_181ed0* y = ((Actor_181ed0 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    Model_181ed0* m = y->ModelFor();
    unsigned char v = *((unsigned char*)(*(Actor_181ed0 * *)&this->f_1c) + 0x10);
    ((owners::Obj_373c0 *)m)->FUN_000373c0(v);
    if (!v) {
        void* p = *((void**)((char*)m + 0x128));
        if (p) {
            void* q = (*(Actor_181ed0 * *)&this->f_20)->D();
            if (q) {
                Vec_181ed0 t = *((Vec_181ed0*)((char*)q + 0x38));
                ((Model_181ed0*)p)->Apply(&t, (char*)q + 8);
            }
        }
    }
    return true;
}

