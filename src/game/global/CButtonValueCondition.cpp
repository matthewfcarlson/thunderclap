// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b1b0..0x0004b2b0 (kind game, layer game, confidence medium), dominant class CButtonValueCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f662ff92 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f662ff92 {} using namespace fn_f662ff92;
namespace fn_f662ff92 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f662ff92 {
extern void* hulk_at_003f6d50[];
class CButtonCondition_4b1b0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CButtonValueCondition : public CButtonCondition_4b1b0 {
  public:
    CButtonValueCondition* vfunc_5(signed char flags);
};


// 0x0004b1b0 CButtonValueCondition::vfunc_5 (36 B): matches/0x0004b1b0.cpp
// sym: ?vfunc_5@CButtonValueCondition@fn_f662ff92@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonValueCondition* CButtonValueCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f662ff92

// 0x0004b1e0 CButtonValueCondition::vfunc_9 (184 B): equivalent/0x0004b1e0.cpp [wrapped: conflict: CButtonValueCondition]
// sym: ?vfunc_9@CButtonValueCondition@fn_0004b1e0@@UAE_NPAUInput_4b1e0@2@@Z @46c927b9ce7d @w1d979f55a355
namespace fn_0004b1e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CButtonValueCondition::vfunc_9 @ 0x0004b1e0
struct Input_4b1e0 { char pad[8]; float value; };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct CButtonCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
 virtual bool vfunc_9(Input_4b1e0*);
 char pad[20];
};
struct CButtonValueCondition : CButtonCondition {
 unsigned comparison;
 float threshold;
 virtual bool vfunc_9(Input_4b1e0*);
};
bool CButtonValueCondition::vfunc_9(Input_4b1e0* input) {
 if (!CButtonCondition::vfunc_9(input)) return false;
 switch (comparison) {
 case 0: return input->value < threshold;
 case 1: return input->value <= threshold;
 case 2: return FUN_00018960(input->value, threshold, 0.00001f);
 case 3: return !FUN_00018960(input->value, threshold, 0.00001f);
 case 4: return input->value >= threshold;
 case 5: return input->value > threshold;
 default: return false;
 }
}
} // namespace fn_0004b1e0

