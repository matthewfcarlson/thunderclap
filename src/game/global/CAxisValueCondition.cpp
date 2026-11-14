// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b4f0..0x0004b600 (kind game, layer game, confidence medium), dominant class CAxisValueCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f271ea75 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f271ea75 {} using namespace fn_f271ea75;
namespace fn_f271ea75 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f271ea75 {
extern void* hulk_at_003f6d50[];
class CAxisTimeCondition_4b4f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CAxisValueCondition : public CAxisTimeCondition_4b4f0 {
  public:
    CAxisValueCondition* vfunc_5(signed char flags);
};


// 0x0004b4f0 CAxisValueCondition::vfunc_5 (36 B): matches/0x0004b4f0.cpp
// sym: ?vfunc_5@CAxisValueCondition@fn_f271ea75@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAxisValueCondition* CAxisValueCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f271ea75

// 0x0004b520 CAxisValueCondition::vfunc_9 (189 B): equivalent/0x0004b520.cpp [wrapped: conflict: CAxisValueCondition]
// sym: ?vfunc_9@CAxisValueCondition@fn_0004b520@@UAE_NPAXPAUAxisState@2@@Z @4a911dc69ebd @w687b5ca973ca
namespace fn_0004b520 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CAxisValueCondition::vfunc_9 @ 0x0004b520
struct AxisState { char pad[16]; float value; };
extern "C++" bool __cdecl FUN_00018960(float, float, float);
struct CAxisTimeCondition {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual bool vfunc_9(void*, AxisState*);
 char pad[20];
 unsigned comparison;
 float threshold;
};
struct CAxisValueCondition : CAxisTimeCondition { virtual bool vfunc_9(void*, AxisState*); };
bool CAxisValueCondition::vfunc_9(void* arg, AxisState* state) {
 if (!CAxisTimeCondition::vfunc_9(arg,state)) return false;
 switch(comparison) {
 case 0: return state->value < threshold;
 case 1: return state->value <= threshold;
 case 2: return FUN_00018960(state->value,threshold,0.00001f);
 case 3: return !FUN_00018960(state->value,threshold,0.00001f);
 case 4: return state->value >= threshold;
 case 5: return state->value > threshold;
 default: return false;
 }
}
} // namespace fn_0004b520

