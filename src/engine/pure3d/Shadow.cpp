// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002dee20..0x002deeb0 (kind game, layer engine, confidence medium), dominant class pure3d::Shadow
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f524fe64 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f524fe64 {} using namespace fn_f524fe64;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f524fe64 {
extern void* hulk_at_0042f994[];
class DrawableContainer_2dee20 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class Shadow_2dee20 : public DrawableContainer_2dee20 {
  public:
    Shadow_2dee20* vfunc_5(signed char flags);
};


// 0x002dee20 pure3d::Shadow::vfunc_2 (36 B): matches/0x002dee20.cpp
// sym: ?vfunc_5@Shadow_2dee20@fn_f524fe64@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Shadow_2dee20* Shadow_2dee20::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042f994;
    Destroy_002a4ff0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f524fe64
