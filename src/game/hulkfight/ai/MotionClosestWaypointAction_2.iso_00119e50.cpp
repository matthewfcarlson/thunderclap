// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00119e50 hulkfight::ai::MotionTargetTrack::vfunc_10 (70 B): matches/0x00119e50.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MotionTargetTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_119e50;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct MotionTargetAction_nv_119e50 {
    u32_119e50 Init_00116a30(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::MotionTargetAction* Alloc_0008d690(int);

hulk_intptr hulkfight::ai::MotionTargetTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_119e50 a = (u32_119e50)__p0; u32_119e50 b = (u32_119e50)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::ai::MotionTargetAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((MotionTargetAction_nv_119e50*)(((hulkfight::ai::MotionTargetAction*)(q))))->Init_00116a30(this, p));
    }
    return (int)(0);
}

