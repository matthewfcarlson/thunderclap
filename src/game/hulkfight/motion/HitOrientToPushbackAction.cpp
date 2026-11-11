// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014fe00..0x0014ff20 (kind game, layer game, confidence medium), dominant class hulkfight::motion::HitOrientToPushbackAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f9683e92 {
#define TREE_TU_END }
namespace fn_f9683e92 {} using namespace fn_f9683e92;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9683e92 {
struct Two_14fef0 {
    void* Fnf_00059a40();
};

} // namespace fn_f9683e92

// 0x0014fe00 hulkfight::motion::HitOrientToPushbackAction::vfunc_3 (233 B): equivalent/0x0014fe00.cpp [wrapped: conflict: hulkfight::motion::HitOrientToPushbackAction]
// sym: ?vfunc_3@HitOrientToPushbackAction@motion@hulkfight@fn_0014fe00@@UAE_NHH@Z @c511d38e17f5 @w6c89b921661a
namespace fn_0014fe00 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// hulkfight::motion::HitOrientToPushbackAction::vfunc_3 @ 0x0014fe00
struct ActorInfo_14fe00 { hulk_freg FUN_000354c0(); };
struct JointDriver_14fe00;
struct Motion_14fe00 { void FUN_00222890(JointDriver_14fe00*, float, float, float, float, float, float); };
struct Actor_14fe00 { ActorInfo_14fe00* FUN_00059a30(); Motion_14fe00* FUN_00059a40(); };
struct Owner_14fe00 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3(); Actor_14fe00* FUN_000592a0(); };
struct HitData_14fe00 { char pad[0x18]; float x,y,z; };
struct Name_14fe00 { void FUN_0027b040(const char*); char bytes[12]; };
struct Parameter_14fe00 { void FUN_00221d20(float); };
struct JointDriver_14fe00 { virtual void slot0(); char pad[4]; Name_14fe00 name; int mode; Parameter_14fe00 parameter; JointDriver_14fe00* FUN_002248f0(int); };
extern void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct HitOrientToPushbackAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5(); char pad[0x18]; HitData_14fe00* hit; Owner_14fe00* owner; JointDriver_14fe00* action; };
bool HitOrientToPushbackAction::vfunc_3(int,int) {
 if (!owner) return false;
 Actor_14fe00* actor=owner->FUN_000592a0();
 ActorInfo_14fe00* info=actor->FUN_00059a30();
 Motion_14fe00* motion=actor->FUN_00059a40();
 if (!motion || !owner->slot3()) return false;
 float x=hit->x, y=hit->y, z=hit->z;
 JointDriver_14fe00* p=(JointDriver_14fe00*)FUN_00263ea0(0x70);
 if(p) p=p->FUN_002248f0(0);
 action=p;
 p->name.FUN_0027b040("hitOrientToPushback");
 action->mode=2;
 action->slot0();
 float value=info->FUN_000354c0();
 action->parameter.FUN_00221d20(value);
 motion->FUN_00222890(action,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
}}
} // namespace fn_0014fe00


// 0x0014fef0 hulkfight::motion::HitOrientToPushbackAction::vfunc_4 (37 B): matches/0x0014fef0.cpp
// sym: ?vfunc_4@HitOrientToPushbackAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::HitOrientToPushbackAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_14fef0*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}

