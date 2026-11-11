// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0013bfa0 hulkfight::motion::AnimationChargeTrack::vfunc_10 (70 B): matches/0x0013bfa0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@AnimationChargeTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13bfa0;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct AnimationChargeAction_nv_13bfa0 {
    u32_13bfa0 Init_0013b180(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::AnimationChargeAction* Alloc_0008d690(int);

hulk_intptr hulkfight::motion::AnimationChargeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13bfa0 a = (u32_13bfa0)__p0; u32_13bfa0 b = (u32_13bfa0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::AnimationChargeAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((AnimationChargeAction_nv_13bfa0*)(((hulkfight::motion::AnimationChargeAction*)(q))))->Init_0013b180(this, p));
    }
    return (int)(0);
}

