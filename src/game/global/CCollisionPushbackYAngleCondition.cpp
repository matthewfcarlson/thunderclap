// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004c400..0x0004c550 (kind game, layer game, confidence medium), dominant class CCollisionPushbackYAngleCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fed636a2 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fed636a2 {} using namespace fn_fed636a2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fed636a2 {
extern void* hulk_at_003f6d50[];
class CCondition_4c400 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CCollisionPushbackYAngleCondition : public CCondition_4c400 {
  public:
    CCollisionPushbackYAngleCondition* vfunc_5(signed char flags);
};


// 0x0004c400 CCollisionPushbackYAngleCondition::vfunc_5 (36 B): matches/0x0004c400.cpp
// sym: ?vfunc_5@CCollisionPushbackYAngleCondition@fn_fed636a2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCollisionPushbackYAngleCondition* CCollisionPushbackYAngleCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fed636a2

// 0x0004c430 CCollisionPushbackYAngleCondition::vfunc_7 (254 B): equivalent/0x0004c430.cpp [wrapped: conflict: CCollisionPushbackYAngleCondition]
// sym: ?vfunc_7@CCollisionPushbackYAngleCondition@fn_0004c430@@UAE_NPAUContext@2@@Z
namespace fn_0004c430 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackYAngleCondition::vfunc_7 @ 0x0004c430
struct Vec_4c430 { float x,y,z; hulk_freg FUN_0022d110(); };
struct State_4c430 { char pad[0x28]; Vec_4c430 direction; };
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_4c430* slot3(); };
hulk_freg __cdecl FUN_000189c0(float);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float,float,float);
class CCollisionPushbackYAngleCondition {
public:
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CCollisionPushbackYAngleCondition::vfunc_7(Context* c) {
 State_4c430* s=c->slot3(); if(!s) return false;
 Vec_4c430 v=s->direction; v.FUN_0022d110();
 float angle=FUN_000189c0(v.y);
 switch(operation) {
 case 0: return angle < threshold;
 case 1: return angle <= threshold;
 case 2: return FUN_00018960(angle,threshold,0.00001f);
 case 3: return !FUN_00018960(angle,threshold,0.00001f);
 case 4: return angle >= threshold;
 case 5: return angle > threshold;
 }
 return false;
}
} // namespace fn_0004c430

