// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017b470 hulkfight::motion::PushOutTrack::vfunc_10 (70 B): matches/0x0017b470.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PushOutTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b470;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct PushOutAction_nv_17b470 {
    u32_17b470 Init_001748b0(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::PushOutAction* Alloc_0008d690(int);

hulk_intptr hulkfight::motion::PushOutTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b470 a = (u32_17b470)__p0; u32_17b470 b = (u32_17b470)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::PushOutAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((PushOutAction_nv_17b470*)(((hulkfight::motion::PushOutAction*)(q))))->Init_001748b0(this, p));
    }
    return (int)(0);
}

