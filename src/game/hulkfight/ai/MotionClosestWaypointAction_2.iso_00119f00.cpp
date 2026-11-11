// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00119f00 hulkfight::ai::MotionChaseTrack::vfunc_10 (70 B): matches/0x00119f00.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MotionChaseTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_119f00;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct MotionChaseAction_nv_119f00 {
    u32_119f00 Init_00116c10(void*, void*);
};
extern hulkfight::ai::MotionChaseAction* Alloc_0008d690(int);

hulk_intptr hulkfight::ai::MotionChaseTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_119f00 a = (u32_119f00)__p0; u32_119f00 b = (u32_119f00)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::ai::MotionChaseAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((MotionChaseAction_nv_119f00*)(((hulkfight::ai::MotionChaseAction*)(q))))->Init_00116c10(this, p));
    }
    return (int)(0);
}

