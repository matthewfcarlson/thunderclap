// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00171a20..0x00171d10 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc3c0be1 {
#define TREE_TU_END }
namespace fn_fc3c0be1 {} using namespace fn_fc3c0be1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fc3c0be1 {
struct Table_171a20 { char pad[0xc]; unsigned int limit; unsigned int FUN_002843a0(unsigned int lo, unsigned int hi); };
struct Layers_171a20 { char pad[0x64]; Table_171a20 *table; };
struct Ctx_171a20 {
    void *FUN_00059a30();
    Layers_171a20 *FUN_00059a40();
};
struct Owner_171a20 {  };
struct Data_171a20 { char pad[0x18]; unsigned int keyLo; unsigned int keyHi; };
struct A_171b80 {
    void* f();
};
struct B_171b80 {
    void* f();
};
struct C_171b80 {
    void f(void*, int);
};
class Actor_171bb0;
class Owner_171bb0 {
    char pad[0x25];

  public:
    unsigned char flag;
    Actor_171bb0* GetActor();
};
class Actor_171bb0 {
    char pad[0x2140];

  public:
    unsigned char field;
    void SetPosition(void*);
};
class Manager_171bb0 {
  public:
};
struct A_171c60 {
};
struct B_171c60 {
    void* FUN_00059a30();
};
struct Vec_171ca0 {
    int x, y, z;
};
class Obj_171ca0 {
  public:
    Obj_171ca0* next();
    void set(Vec_171ca0*);
};

} // namespace fn_fc3c0be1

// 0x00171a20 hulkfight::motion::PushOutAction::vfunc_3 (108 B): equivalent/0x00171a20.cpp
// sym: ?vfunc_3@PushOutAction@motion@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PushOutAction::vfunc_3 @ 0x00171a20
bool hulkfight::motion::PushOutAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Ctx_171a20 *ctx = ((Ctx_171a20 *)((owners::Object_592a0 *)((*(Owner_171a20 * *)&this->f_20)))->FUN_000592a0());
    if (ctx == 0)
        return false;
    if (ctx->FUN_00059a30() == 0)
        return false;
    Layers_171a20 *layers = ctx->FUN_00059a40();
    if (layers == 0)
        return false;
    Table_171a20 *t = layers->table;
    unsigned int lo = (*(Data_171a20 * *)&this->f_1c)->keyLo;
    unsigned int hi = (*(Data_171a20 * *)&this->f_1c)->keyHi;
    if ((lo | hi) != 0) {
        (*(unsigned int *)&this->f_24) = t->FUN_002843a0(lo, hi);
        if ((*(unsigned int *)&this->f_24) == 0xffff)
            (*(unsigned int *)&this->f_24) = 0;
    }
    return (*(unsigned int *)&this->f_24) < t->limit;
}


// 0x00171a90 hulkfight::motion::FootPivotAction::vfunc_3 (230 B): equivalent/0x00171a90.cpp [wrapped: conflict: hulkfight::motion::FootPivotAction]
// sym: ?vfunc_3@FootPivotAction@motion@hulkfight@fn_00171a90@@UAE_NHH@Z
namespace fn_00171a90 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 14/14)
// hulkfight::motion::FootPivotAction::vfunc_3 @ 0x00171a90
struct Rig_171a90 { char pad[12]; unsigned count; unsigned FUN_002843a0(unsigned,unsigned); };
struct Label_171a90 { void FUN_0027b040(const char*); };
struct JointDriver_171a90 { virtual void vfunc_0(); int unused; Label_171a90 label; int pad; int field10; int field14; JointDriver_171a90* FUN_002248a0(); };
struct Actor_171a90 { char pad[0x64]; Rig_171a90* rig; void FUN_00222890(JointDriver_171a90*,float,float,float,float,float,float); };
struct Handle_171a90 { int FUN_00059a30(); Actor_171a90* FUN_00059a40(); };
struct Owner_171a90 { Handle_171a90* FUN_000592a0(); };
struct Settings_171a90 { char pad[0x18]; unsigned key1,key2; char pad2[0x18]; float a,b,c; };
extern void* __cdecl FUN_00263ea0(unsigned);
namespace hulkfight { namespace motion {
struct FootPivotAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); char pad[0x18]; Settings_171a90* settings; Owner_171a90* owner; unsigned index; JointDriver_171a90* anim; };
bool FootPivotAction::vfunc_3(int,int) {
 Handle_171a90* h=owner->FUN_000592a0();
 if (!h || !h->FUN_00059a30()) return false;
 Actor_171a90* actor=h->FUN_00059a40();
 if (!actor) return false;
 Rig_171a90* rig=actor->rig;
 unsigned k1=settings->key1,k2=settings->key2;
 if(k1|k2) { index=rig->FUN_002843a0(k1,k2); if(index==0xffff) index=0; }
 if(index>=rig->count) return false;
 JointDriver_171a90* a=(JointDriver_171a90*)FUN_00263ea0(0x70);
 if(a) a=a->FUN_002248a0();
 anim=a;
 a->label.FUN_0027b040("footPivot");
 anim->vfunc_0();
 anim->field10=0;
 anim->field14=2;
 actor->FUN_00222890(anim,-1.0f,settings->a,1.0f,settings->b,settings->c,-1.0f);
 return true;
}
}}
} // namespace fn_00171a90


// 0x00171b80 hulkfight::motion::FootPivotAction::vfunc_4 (37 B): matches/0x00171b80.cpp
// sym: ?vfunc_4@FootPivotAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::FootPivotAction::vfunc_4() {
    void* a = (*(A_171b80 * *)&this->f_20)->f();
    void* b = ((B_171b80*)a)->f();
    if (b)
        ((C_171b80*)b)->f((*(void * *)&this->f_28), 0);
}


// 0x00171bb0 hulkfight::motion::DriftToPositionAction::vfunc_4 (82 B): matches/0x00171bb0.cpp
// sym: ?vfunc_4@DriftToPositionAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::DriftToPositionAction::vfunc_4() {
    Owner_171bb0* o = ((Owner_171bb0 *)((owners::Object_592a0 *)((*(Manager_171bb0 * *)&this->f_20)))->FUN_000592a0());
    if (o) {
        Actor_171bb0* a = o->GetActor();
        if (a) {
            if ((*(Owner_171bb0 * *)&this->f_1c)->flag && this->f_52)
                a->SetPosition((char*)this + 0x40);
            a->field = this->f_51;
            ((owners::Target_35ce0 *)a)->FUN_00035ce0(this->f_50);
        }
    }
}


// 0x00171c10 hulkfight::motion::DriftToHulkAction::vfunc_3 (78 B): equivalent/0x00171c10.cpp [wrapped: conflict: hulkfight::motion::DriftToHulkAction]
// sym: ?vfunc_3@DriftToHulkAction@motion@hulkfight@fn_00171c10@@UAE_NHH@Z
namespace fn_00171c10 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// hulkfight::motion::DriftToHulkAction::vfunc_3 @ 0x00171c10
struct HulkState { char pad[0x2140]; unsigned char active; };
struct Actor { HulkState* FUN_00059a30(); };
struct Handle { Actor* FUN_000592a0(); };
struct Motion { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual float vfunc_7(); };
namespace hulkfight { namespace motion {
struct DriftToHulkAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int a, int b); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Motion* motion; Handle* handle; char rest[0xc]; float speed; unsigned char previous;
};
bool DriftToHulkAction::vfunc_3(int a, int b) {
 Actor* actor = handle->FUN_000592a0();
 if (!actor) return false;
 HulkState* state = actor->FUN_00059a30();
 if (!state) return false;
 previous = state->active;
 state->active = 1;
 float value = motion->vfunc_7();
 speed = value;
 return !(value <= 0.0f);
}
}}
} // namespace fn_00171c10


// 0x00171c60 hulkfight::motion::DriftToHulkAction::vfunc_4 (37 B): matches/0x00171c60.cpp
// sym: ?vfunc_4@DriftToHulkAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::DriftToHulkAction::vfunc_4() {
    void* p = ((void *)((owners::Object_592a0 *)((*(A_171c60 * *)&this->f_20)))->FUN_000592a0());
    if (p) {
        p = ((B_171c60*)p)->FUN_00059a30();
        if (p)
            *(unsigned char*)((char*)p + 0x2140) = this->f_34;
    }
}


// 0x00171c90 hulkfight::motion::TeleportAction::vfunc_3 (11 B): matches/0x00171c90.cpp
// sym: ?vfunc_3@TeleportAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::TeleportAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    return (*(volatile int *)&this->f_20);
}


// 0x00171ca0 hulkfight::motion::TeleportAction::vfunc_5 (89 B): matches/0x00171ca0.cpp
// sym: ?vfunc_5@TeleportAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::TeleportAction::vfunc_5(hulk_intptr a, int b) {
    if (!a) {
        if (!(*(Obj_171ca0 * *)&this->f_20))
            return (bool)(0);
        Obj_171ca0* p = ((Obj_171ca0 *)((owners::Object_592a0 *)((*(Obj_171ca0 * *)&this->f_20)))->FUN_000592a0())->next();
        Vec_171ca0 v = *(Vec_171ca0*)((*(char * *)&this->f_1c) + 0x10);
        p->set(&v);
    }
    return (bool)(1);
}

namespace fn_fc3c0be1 {

// 0x00171d00 hulkfight::motion::TeleportAction::vfunc_4 (1 B): matches/0x00171d00.cpp
// sym: ?FUN_00171d00@fn_fc3c0be1@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00171d00() {}

} // namespace fn_fc3c0be1
