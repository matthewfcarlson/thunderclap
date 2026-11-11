// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00301620..0x00301650 (kind game, layer engine, confidence medium), dominant class physics::CollisionDetector
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f024a6a6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f024a6a6 {} using namespace fn_f024a6a6;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f024a6a6 {
extern void* SubCollisionDetector_301620_vftable[];
class SubCollisionDetector_301620 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionDetector_301620 : public SubCollisionDetector_301620 {
  public:
    CollisionDetector_301620* vfunc_5(signed char flags);
};


// 0x00301620 physics::CollisionDetector::vfunc_0 (36 B): matches/0x00301620.cpp
// sym: ?vfunc_5@CollisionDetector_301620@fn_f024a6a6@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionDetector_301620* CollisionDetector_301620::vfunc_5(signed char flags) {
    *(void***)this = SubCollisionDetector_301620_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f024a6a6
