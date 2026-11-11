// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001222c0 hulkfight::ai::StrafeLateralHBTrack::vfunc_10 (70 B): matches/0x001222c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@StrafeLateralHBTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1222c0;
extern int TypeA_1222c0;
extern int TypeB_1222c0;
struct StrafeLateralHBAction_nv_1222c0 {
    u32_1222c0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::ai::StrafeLateralHBAction* Alloc(int);

hulk_intptr hulkfight::ai::StrafeLateralHBTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1222c0 a = (u32_1222c0)__p0; u32_1222c0 b = (u32_1222c0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_1222c0, &TypeB_1222c0, 0)) {
        hulkfight::ai::StrafeLateralHBAction* q = Alloc(0x28);
        if (q)
            return (int)(((StrafeLateralHBAction_nv_1222c0*)(((hulkfight::ai::StrafeLateralHBAction*)(q))))->Init(this, p));
    }
    return (int)(0);
}

