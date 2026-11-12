// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004b040..0x0004b0a0 (kind game, layer game, confidence medium), dominant class CControllerCondition
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f63868ef {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f63868ef {} using namespace fn_f63868ef;
namespace fn_f63868ef { extern "C" char DAT_003f6d50[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f63868ef {
extern void* hulk_at_003f6d50[];
class CCondition_4b040 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CStageCondition : public CCondition_4b040 {
  public:
    CStageCondition* vfunc_5(signed char flags);
};
extern void* CCondition_4b070_vftable[];
class CCondition_4b070 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class CControllerCondition : public CCondition_4b070 {
  public:
    CControllerCondition* vfunc_5(signed char flags);
};


// 0x0004b040 CStageCondition::vfunc_5 (36 B): matches/0x0004b040.cpp
// sym: ?vfunc_5@CStageCondition@fn_f63868ef@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CStageCondition* CStageCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f6d50;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0004b070 CControllerCondition::vfunc_5 (36 B): matches/0x0004b070.cpp
// sym: ?vfunc_5@CControllerCondition@fn_f63868ef@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CControllerCondition* CControllerCondition::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_003f6d50);
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f63868ef
