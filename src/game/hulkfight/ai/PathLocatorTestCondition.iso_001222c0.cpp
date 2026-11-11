// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001222c0 hulkfight::ai::StrafeLateralHBTrack::vfunc_10 (70 B): matches/0x001222c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@StrafeLateralHBTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_1222c0;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct StrafeLateralHBAction_nv_1222c0 {
    u32_1222c0 Init_0011e100(void*, void*);
};
extern hulkfight::ai::StrafeLateralHBAction* Alloc_0008d690(int);

hulk_intptr hulkfight::ai::StrafeLateralHBTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1222c0 a = (u32_1222c0)__p0; u32_1222c0 b = (u32_1222c0)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::ai::StrafeLateralHBAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((StrafeLateralHBAction_nv_1222c0*)(((hulkfight::ai::StrafeLateralHBAction*)(q))))->Init_0011e100(this, p));
    }
    return (int)(0);
}

