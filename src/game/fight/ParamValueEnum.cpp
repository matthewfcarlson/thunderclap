// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004ded0..0x0004df40 (kind game, layer game, confidence medium), dominant class fight::ParamValueEnum
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9e0b99b {
#define TREE_TU_END }
namespace fn_f9e0b99b {} using namespace fn_f9e0b99b;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f9e0b99b {
extern void* hulk_at_003f6d50[];
class CCondition_4ded0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9e0b99b
class CIsHelicopterCondition : public CCondition_4ded0 {
  public:
    CIsHelicopterCondition* vfunc_5(signed char flags);
};


// 0x0004ded0 CIsHelicopterCondition::vfunc_5 (36 B): matches/0x0004ded0.cpp
// sym: ?vfunc_5@CIsHelicopterCondition@@QAEPAV1@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIsHelicopterCondition* CIsHelicopterCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004df30 fight::ParamValueEnum::vfunc_1 (6 B): matches/0x0004df30.cpp
// sym: ?vfunc_1@ParamValueEnum@fight@@UAEHXZ
int fight::ParamValueEnum::vfunc_1() {
    return 6;
}

