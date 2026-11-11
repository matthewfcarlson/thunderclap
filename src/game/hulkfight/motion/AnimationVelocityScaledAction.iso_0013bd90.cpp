// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0013bd90 hulkfight::motion::AnimationTrack::vfunc_10 (70 B): matches/0x0013bd90.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@AnimationTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13bd90;
extern int TypeA_13bd90;
extern int TypeB_13bd90;
struct AnimationAction_nv_13bd90 {
    u32_13bd90 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationAction* Alloc(int);

hulk_intptr hulkfight::motion::AnimationTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13bd90 a = (u32_13bd90)__p0; u32_13bd90 b = (u32_13bd90)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_13bd90, &TypeB_13bd90, 0)) {
        hulkfight::motion::AnimationAction* q = Alloc(0x28);
        if (q)
            return (int)(((AnimationAction_nv_13bd90*)(((hulkfight::motion::AnimationAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}

