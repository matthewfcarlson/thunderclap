// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0013be40 hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_10 (70 B): matches/0x0013be40.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@AnimationPhaseMatchedTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_13be40;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct AnimationPhaseMatchedAction_nv_13be40 {
    u32_13be40 Init_0013ae80(void*, void*);
};
extern hulkfight::motion::AnimationPhaseMatchedAction* Alloc_0008d690(int);

hulk_intptr hulkfight::motion::AnimationPhaseMatchedTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_13be40 a = (u32_13be40)__p0; u32_13be40 b = (u32_13be40)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::motion::AnimationPhaseMatchedAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((AnimationPhaseMatchedAction_nv_13be40*)(((hulkfight::motion::AnimationPhaseMatchedAction*)(q))))->Init_0013ae80(this, p));
    }
    return (int)(0);
}

