// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001133a0 hulkfight::ai::SemaphoreWaitTrack::vfunc_10 (70 B): matches/0x001133a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SemaphoreWaitTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1133a0;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct SemaphoreWaitAction_nv_1133a0 {
    u32_1133a0 Init_0010f940(void*, void*);
};
extern hulkfight::ai::SemaphoreWaitAction* Alloc_0008d690(int);

hulk_intptr hulkfight::ai::SemaphoreWaitTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1133a0 a = (u32_1133a0)__p0; u32_1133a0 b = (u32_1133a0)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::ai::SemaphoreWaitAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((SemaphoreWaitAction_nv_1133a0*)(((hulkfight::ai::SemaphoreWaitAction*)(q))))->Init_0010f940(this, p));
    }
    return (int)(0);
}

