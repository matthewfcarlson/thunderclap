// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004d680..0x0004d860 (kind game, layer game, confidence medium), dominant class CGrappleTimerCondition
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_fc1bb4c1 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc1bb4c1 {} using namespace fn_fc1bb4c1;
namespace fn_fc1bb4c1 { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc1bb4c1 {
extern void* hulk_at_003f6d50[];
class CCondition_4d680 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAlertStatusCondition : public CCondition_4d680 {
  public:
    CAlertStatusCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4d6b0_vftable[];
class CCondition_4d6b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CRageModeCondition : public CCondition_4d6b0 {
  public:
    CRageModeCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4d6e0_vftable[];
class CCondition_4d6e0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CGrappleTimerCondition : public CCondition_4d6e0 {
  public:
    CGrappleTimerCondition* vfunc_5(signed char flags);
};


// 0x0004d680 CAlertStatusCondition::vfunc_5 (36 B): matches/0x0004d680.cpp
// sym: ?vfunc_5@CAlertStatusCondition@fn_fc1bb4c1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAlertStatusCondition* CAlertStatusCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004d6b0 CRageModeCondition::vfunc_5 (36 B): matches/0x0004d6b0.cpp
// sym: ?vfunc_5@CRageModeCondition@fn_fc1bb4c1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CRageModeCondition* CRageModeCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004d6e0 CGrappleTimerCondition::vfunc_5 (36 B): matches/0x0004d6e0.cpp
// sym: ?vfunc_5@CGrappleTimerCondition@fn_fc1bb4c1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CGrappleTimerCondition* CGrappleTimerCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc1bb4c1

// 0x0004d710 CGrappleTimerCondition::vfunc_7 (299 B): equivalent/0x0004d710.cpp [wrapped: conflict: CGrappleTimerCondition]
// sym: ?vfunc_7@CGrappleTimerCondition@fn_0004d710@@UAE_NPAUContext@2@@Z @16a5038232ac @wa55e4b4b53b8
namespace fn_0004d710 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CGrappleTimerCondition::vfunc_7 @ 0x0004d710

struct TimerSource { float FUN_0003eca0(void*); };
struct Fighter_4d710 { char pad[0x330]; TimerSource* primary; TimerSource* secondary; char pad2[0x54]; float timer; };
struct Intermediate_4d710 { Fighter_4d710* FUN_00059a30(); };
struct Context { Intermediate_4d710* FUN_000592a0(); };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float,float,float);
struct CGrappleTimerCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold; unsigned char dynamic; char pad2[3]; unsigned index;
};
bool CGrappleTimerCondition::vfunc_7(Context* context) {
 Fighter_4d710* fighter=context->FUN_000592a0()->FUN_00059a30();
 float value=threshold;
 if(dynamic) {
 TimerSource* source=fighter->secondary;
 if(!source) source=fighter->primary;
 if(source) { float result=source->FUN_0003eca0(((void**)&DAT_0048f9d4)[index]); value=(result==0.0f)?3.402823466e38f:result; }
 }
 switch(operation) {
 case 0: return fighter->timer < value;
 case 1: return fighter->timer <= value;
 case 2: return FUN_00018960(fighter->timer,value,0.00001f);
 case 3: return !FUN_00018960(fighter->timer,value,0.00001f);
 case 4: return fighter->timer >= value;
 case 5: return fighter->timer > value;
 default: return false;
 }
}
} // namespace fn_0004d710

