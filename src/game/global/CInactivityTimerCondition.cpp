// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004d860..0x0004d970 (kind game, layer game, confidence medium), dominant class CInactivityTimerCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa5db5a6 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa5db5a6 {} using namespace fn_fa5db5a6;
namespace fn_fa5db5a6 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa5db5a6 {
extern void* hulk_at_003f6d50[];
class CCondition_4d860 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CInactivityTimerCondition : public CCondition_4d860 {
  public:
    CInactivityTimerCondition* vfunc_5(signed char flags);
};


// 0x0004d860 CInactivityTimerCondition::vfunc_5 (36 B): matches/0x0004d860.cpp
// sym: ?vfunc_5@CInactivityTimerCondition@fn_fa5db5a6@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CInactivityTimerCondition* CInactivityTimerCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_fa5db5a6

// 0x0004d890 CInactivityTimerCondition::vfunc_7 (193 B): equivalent/0x0004d890.cpp [wrapped: conflict: CInactivityTimerCondition]
// sym: ?vfunc_7@CInactivityTimerCondition@fn_0004d890@@UAE_NPAUContext@2@@Z @2d5328bdcff1 @w68e12e395f2d
namespace fn_0004d890 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CInactivityTimerCondition::vfunc_7 @ 0x0004d890
struct State_4d890 { char pad[0x1e48]; float inactivity; };
struct Actor_4d890 { State_4d890* FUN_00059a30(); };
struct Context { Actor_4d890* FUN_000592a0(); };
extern "C++" bool __cdecl FUN_00018960(float, float, float);
struct CInactivityTimerCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned comparison; float threshold;
};
bool CInactivityTimerCondition::vfunc_7(Context* context) {
 State_4d890* state = context->FUN_000592a0()->FUN_00059a30();
 switch(comparison) {
 case 0: return state->inactivity < threshold;
 case 1: return state->inactivity <= threshold;
 case 2: return FUN_00018960(state->inactivity, threshold, 0.00001f);
 case 3: return !FUN_00018960(state->inactivity, threshold, 0.00001f);
 case 4: return state->inactivity >= threshold;
 case 5: return state->inactivity > threshold;
 default: return false;
 }
}
} // namespace fn_0004d890

