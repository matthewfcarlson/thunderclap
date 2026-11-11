// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001131c0 hulkfight::ai::TokenSupressTrack::vfunc_10 (70 B): matches/0x001131c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TokenSupressTrack@ai@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

typedef unsigned int u32_1131c0;
extern int TypeA_1131c0;
extern int TypeB_1131c0;
struct TokenSupressAction_nv_1131c0 {
    u32_1131c0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::TokenSupressAction* Alloc(int);

hulk_intptr hulkfight::ai::TokenSupressTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1131c0 a = (u32_1131c0)__p0; u32_1131c0 b = (u32_1131c0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1131c0, &TypeB_1131c0, 0)) {
        hulkfight::ai::TokenSupressAction* q = Alloc(0x28);
        if (q)
            return (int)(((TokenSupressAction_nv_1131c0*)(((hulkfight::ai::TokenSupressAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}

