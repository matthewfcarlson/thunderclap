// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00156d90 hulkfight::motion::HitWaitTrack::vfunc_10 (70 B): matches/0x00156d90.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HitWaitTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_156d90;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct HitWaitAction_nv_156d90 {
    u32_156d90 Init_001510f0(void*, void*);
};
extern hulkfight::motion::HitWaitAction* Alloc_0008d690(int);

hulk_intptr hulkfight::motion::HitWaitTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_156d90 a = (u32_156d90)__p0; u32_156d90 b = (u32_156d90)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::motion::HitWaitAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((HitWaitAction_nv_156d90*)(((hulkfight::motion::HitWaitAction*)(q))))->Init_001510f0(this, p));
    }
    return (int)(0);
}

