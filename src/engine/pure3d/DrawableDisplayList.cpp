// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029c050..0x0029c240 (kind game, layer engine, confidence medium), dominant class pure3d::DrawableDisplayList
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff20f16b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff20f16b {} using namespace fn_ff20f16b;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff20f16b {
extern void* DisplayList_29c050_vftable[];
class DisplayList_29c050 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class DrawableDisplayList_29c050 : public DisplayList_29c050 {
  public:
    DrawableDisplayList_29c050* vfunc_5(signed char flags);
};


// 0x0029c050 pure3d::DrawableDisplayList::vfunc_2 (36 B): matches/0x0029c050.cpp
// sym: ?vfunc_5@DrawableDisplayList_29c050@fn_ff20f16b@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
DrawableDisplayList_29c050* DrawableDisplayList_29c050::vfunc_5(signed char flags) {
    *(void***)this = DisplayList_29c050_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_ff20f16b
