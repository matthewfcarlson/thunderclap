// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014c80..0x00014e90 (kind game, layer game, confidence high), dominant class CMoveAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fe68592f {
#define TREE_TU_END }
namespace fn_fe68592f {} using namespace fn_fe68592f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe68592f {
struct R_14e60 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_14e60* __fastcall FUN_00059a40(void*);

} // namespace fn_fe68592f

// 0x00014c80 CMoveAction::vfunc_6 (182 B): equivalent/0x00014c80.cpp [wrapped: conflict: CMoveAction]
// sym: ?vfunc_6@CMoveAction@fn_00014c80@@UAE_NH@Z
namespace fn_00014c80 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// CMoveAction::vfunc_6 @ 0x00014c80
struct Name_14c80 { void FUN_0027b040(const char*); };
struct Transform_14c80 { char data[48]; void FUN_0022be40(const Transform_14c80*); };
struct JointDriver_14c80 { virtual void vfunc_0(); char pad[4]; Name_14c80 name; char pad2[8]; unsigned enabled; Transform_14c80 transform; JointDriver_14c80* FUN_002248f0(int); };
struct Actor_14c80 { char pad[64]; Transform_14c80 transform; void FUN_00222890(JointDriver_14c80*, float, unsigned, float, unsigned, unsigned, float); };
struct Context { Actor_14c80* FUN_00059a40(); };
struct Owner_14c80 { Context* FUN_000592a0(); };
struct Params { char pad[28]; unsigned x,y,z; };
extern JointDriver_14c80* __cdecl FUN_00263ea0(unsigned);
struct CMoveAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); virtual void vfunc_7(); virtual void vfunc_8();
 char pad[24]; Owner_14c80* owner; Params* params; JointDriver_14c80* move;
};
bool CMoveAction::vfunc_6(int) {
 Actor_14c80* actor = owner->FUN_000592a0()->FUN_00059a40();
 if (!actor) return false;
 unsigned y=params->y, z=params->z, x=params->x;
 JointDriver_14c80* allocated=FUN_00263ea0(0x70);
 JointDriver_14c80* created=allocated ? allocated->FUN_002248f0(0) : 0;
 move=created;
 created->name.FUN_0027b040("move");
 move->vfunc_0();
 move->transform.FUN_0022be40(&actor->transform);
 move->enabled=1;
 actor->FUN_00222890(move,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
} // namespace fn_00014c80


// 0x00014d40 CMoveAction::vfunc_7 (282 B): equivalent/0x00014d40.cpp [wrapped: conflict: CMoveAction]
// sym: ?vfunc_7@CMoveAction@fn_00014d40@@UAE_NM@Z
namespace fn_00014d40 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 4/4)
// CMoveAction::vfunc_7 @ 0x00014d40

struct Vec_14d40 { float x,y,z; void FUN_0022be40(const Vec_14d40*); };
struct Heading;
struct Heading { hulk_freg FUN_000354c0(); };
struct Actor_14d40 { Heading* FUN_00059a30(); void FUN_00059a50(Vec_14d40*); };
struct Owner_14d40 { Actor_14d40* FUN_000592a0(); };
struct Motion_14d40 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); char pad[16]; float speed; float angle; };
struct Destination_14d40 { char pad[24]; Vec_14d40 position; };
void __cdecl FUN_00224d70(float,Vec_14d40*);
struct CMoveAction { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual bool vfunc_7(float); virtual void slot8(); char pad[24]; Owner_14d40* owner; Motion_14d40* motion; Destination_14d40* destination; };
bool CMoveAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor_14d40* actor=owner->FUN_000592a0();
 Heading* heading=actor->FUN_00059a30();
 float duration=motion->slot7();
 if (duration<=0.0f) return false;
 Vec_14d40 delta;
 delta.x=(*(float*)&DAT_0048e054); delta.y=(*(float*)((char*)&DAT_0048e054 + 4)); delta.z=(*(float*)((char*)&DAT_0048e054 + 8));
 double scale=((double)motion->speed/duration)*dt;
 delta.x=(float)(delta.x*scale); delta.y=(float)(delta.y*scale); delta.z=(float)(delta.z*scale);
 float angle=motion->angle;
 hulk_freg turn=heading->FUN_000354c0(); /* st0: added unrounded */
 FUN_00224d70((float)((double)turn+angle),&delta);
 Vec_14d40 position; position.x=0;position.y=0;position.z=0;
 actor->FUN_00059a50(&position);
 delta.x=position.x+delta.x; delta.y=position.y+delta.y; delta.z=position.z+delta.z;
 destination->position.FUN_0022be40(&delta);
 return true;
}
} // namespace fn_00014d40


// 0x00014e60 CMoveAction::vfunc_4 (37 B): matches/0x00014e60.cpp
// sym: ?vfunc_4@CMoveAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CMoveAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_14e60* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}

