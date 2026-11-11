// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001133a0 hulkfight::ai::SemaphoreWaitTrack::vfunc_10 (70 B): matches/0x001133a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SemaphoreWaitTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1133a0;
extern int TypeA_1133a0;
extern int TypeB_1133a0;
struct SemaphoreWaitAction_nv_1133a0 {
    u32_1133a0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::SemaphoreWaitAction* Alloc(int);

hulk_intptr hulkfight::ai::SemaphoreWaitTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1133a0 a = (u32_1133a0)__p0; u32_1133a0 b = (u32_1133a0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1133a0, &TypeB_1133a0, 0)) {
        hulkfight::ai::SemaphoreWaitAction* q = Alloc(0x28);
        if (q)
            return (int)(((SemaphoreWaitAction_nv_1133a0*)(((hulkfight::ai::SemaphoreWaitAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}

