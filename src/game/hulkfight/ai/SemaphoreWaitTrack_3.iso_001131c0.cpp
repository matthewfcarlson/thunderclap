// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001131c0 hulkfight::ai::TokenSupressTrack::vfunc_10 (70 B): matches/0x001131c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TokenSupressTrack@ai@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

typedef unsigned int u32_1131c0;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct TokenSupressAction_nv_1131c0 {
    u32_1131c0 Init_0010f780(void*, void*);
};
extern hulkfight::ai::TokenSupressAction* Alloc_0008d690(int);

hulk_intptr hulkfight::ai::TokenSupressTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1131c0 a = (u32_1131c0)__p0; u32_1131c0 b = (u32_1131c0)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::ai::TokenSupressAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((TokenSupressAction_nv_1131c0*)(((hulkfight::ai::TokenSupressAction*)(q))))->Init_0010f780(this, p));
    }
    return (int)(0);
}

