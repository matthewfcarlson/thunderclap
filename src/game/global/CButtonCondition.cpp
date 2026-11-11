// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b0a0..0x0004b1b0 (kind game, layer game, confidence medium), dominant class CButtonCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f300332c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f300332c {} using namespace fn_f300332c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f300332c {
extern void* hulk_at_003f6d50[];
class CControllerCondition_4b0a0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CButtonCondition : public CControllerCondition_4b0a0 {
  public:
    CButtonCondition* vfunc_5(signed char flags);
};


// 0x0004b0a0 CButtonCondition::vfunc_5 (36 B): matches/0x0004b0a0.cpp
// sym: ?vfunc_5@CButtonCondition@fn_f300332c@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CButtonCondition* CButtonCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f300332c

// 0x0004b0d0 CButtonCondition::vfunc_9 (197 B): equivalent/0x0004b0d0.cpp [wrapped: conflict: CButtonCondition]
// sym: ?vfunc_9@CButtonCondition@fn_0004b0d0@@UAE_NPAUInput_4b0d0@2@@Z @c2f4c3b6d7f8 @w8d52beefd895
namespace fn_0004b0d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CButtonCondition::vfunc_9 @ 0x0004b0d0
struct Input_4b0d0 { unsigned int unknown; float value; };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float a, float b, float tolerance);
struct CButtonCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual bool vfunc_9(Input_4b0d0* input);
    virtual bool FUN_00344f51(Input_4b0d0* input, float* value);
    char padding[12];
    unsigned int operation;
    float threshold;
};
bool CButtonCondition::vfunc_9(Input_4b0d0* input) {
    float value = input->value;
    if (!FUN_00344f51(input, &value)) return false;
    switch (operation) {
    case 0: return value < threshold;
    case 1: return value <= threshold;
    case 2: return FUN_00018960(value, threshold, 0.00001f);
    case 3: return !FUN_00018960(value, threshold, 0.00001f);
    case 4: return value >= threshold;
    case 5: return value > threshold;
    default: return false;
    }
}
} // namespace fn_0004b0d0

