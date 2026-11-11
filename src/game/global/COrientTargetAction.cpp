// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017370..0x00017570 (kind game, layer game, confidence medium), dominant class COrientTargetAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2f0c168 {
#define TREE_TU_END }
namespace fn_f2f0c168 {} using namespace fn_f2f0c168;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2f0c168 {
struct R_17440 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_17440* __fastcall FUN_00059a40(void*);
struct A_17540 {
    A_17540* valid_00059a40();
    void apply_00222970(void*, int);
};

} // namespace fn_f2f0c168

// 0x00017370 COrientAction::vfunc_6 (195 B): equivalent/0x00017370.cpp [wrapped: conflict: COrientAction]
// sym: ?vfunc_6@COrientAction@fn_00017370@@UAE_NH@Z
namespace fn_00017370 {
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// COrientAction::vfunc_6 @ 0x00017370
struct Actor_17370; struct Controller_17370; struct JointDriver_17370;
struct Source_17370 { Controller_17370* FUN_000592a0(); };
struct Controller_17370 { Actor_17370* FUN_00059a40(); };
struct Angle_17370 { hulk_freg FUN_002220d0(); };
struct Label_17370 { void FUN_0027b040(const char*); };
struct Value_17370 { void FUN_00221d20(float); };
struct JointDriver_17370 { virtual void vfunc_0(); char pad[4]; Label_17370 label; char pad2[11]; int mode; Value_17370 value; JointDriver_17370* FUN_002248f0(int); };
struct Actor_17370 { char pad[16]; Angle_17370 angle; void FUN_00222890(JointDriver_17370*,float,float,float,float,float,float); };
struct Params { char pad[32]; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
struct COrientAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); char pad[24]; Source_17370* source; Params* params; JointDriver_17370* task; };
bool COrientAction::vfunc_6(int) { Actor_17370* actor=source->FUN_000592a0()->FUN_00059a40(); if(!actor) return false; float x=params->x,y=params->y,z=params->z; JointDriver_17370* p=(JointDriver_17370*)FUN_00263ea0(0x70); if(p) p=p->FUN_002248f0(0); task=p; task->label.FUN_0027b040("orient"); task->vfunc_0(); float a=actor->angle.FUN_002220d0(); task->value.FUN_00221d20(a); task->mode=2; actor->FUN_00222890(task,-1.0f,x,1.0f,y,z,-1.0f); return true; }
} // namespace fn_00017370


// 0x00017440 COrientAction::vfunc_4 (37 B): matches/0x00017440.cpp
// sym: ?vfunc_4@COrientAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void COrientAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_17440* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}


// 0x00017470 COrientTargetAction::vfunc_6 (204 B): equivalent/0x00017470.cpp [wrapped: conflict: COrientTargetAction]
// sym: ?vfunc_6@COrientTargetAction@fn_00017470@@QAE_NH@Z
namespace fn_00017470 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// COrientTargetAction::vfunc_6 @ 0x00017470
struct Target_17470;
struct Owner_17470 { Target_17470* FUN_000592a0(); };
struct Angle_17470 { hulk_freg FUN_002220d0(); void FUN_00221d20(float); };
struct Label_17470 { void FUN_0027b040(const char*); };
struct JointDriver_17470 {
 virtual void slot0();
 char pad4[4];
 Label_17470 label;
 char pad9[11];
 int mode;
 Angle_17470 angle;
 JointDriver_17470* FUN_002248f0(int);
};
struct Target_17470 {
 char pad0[16];
 Angle_17470 angle;
 void FUN_00059a30();
 Target_17470* FUN_00059a40();
 void FUN_00222890(JointDriver_17470*,float,float,float,float,float,float);
};
struct Config_17470 { char pad[32]; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
struct COrientTargetAction {
 char pad[28]; Owner_17470* owner; Config_17470* config; int unknown; JointDriver_17470* task;
 bool vfunc_6(int);
};
bool COrientTargetAction::vfunc_6(int) {
 Target_17470* t=owner->FUN_000592a0();
 t->FUN_00059a30();
 t=t->FUN_00059a40();
 if(!t) return false;
 float x=config->x, y=config->y, z=config->z;
 JointDriver_17470* p=(JointDriver_17470*)FUN_00263ea0(0x70);
 if(p) p=p->FUN_002248f0(0);
 task=p;
 task->label.FUN_0027b040("orientTarget");
 task->slot0();
 float a=t->angle.FUN_002220d0();
 task->angle.FUN_00221d20(a);
 task->mode=2;
 t->FUN_00222890(task,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
} // namespace fn_00017470


// 0x00017540 COrientTargetAction::vfunc_4 (37 B): matches/0x00017540.cpp
// sym: ?vfunc_4@COrientTargetAction@@UAEXXZ
void COrientTargetAction::vfunc_4() {
    A_17540* a = ((A_17540 *)((owners::Object_592a0 *)((*(A_17540 * *)&this->f_1c)))->FUN_000592a0());
    a = a->valid_00059a40();
    if (a)
        a->apply_00222970((*(void * *)&this->f_28), 0);
}

