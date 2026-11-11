// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0013be40 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_10 (70 B): matches/0x0013be40.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@AnimationPhaseMatchedTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13be40;
extern int TypeA_13be40;
extern int TypeB_13be40;
struct AnimationPhaseMatchedAction_nv_13be40 {
    u32_13be40 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationPhaseMatchedAction* Alloc(int);

hulk_intptr hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13be40 a = (u32_13be40)__p0; u32_13be40 b = (u32_13be40)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13be40, &TypeB_13be40, 0)) {
        hulkfight::motion::AnimationPhaseMatchedAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationPhaseMatchedAction_nv_13be40*)(((hulkfight::motion::AnimationPhaseMatchedAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}

