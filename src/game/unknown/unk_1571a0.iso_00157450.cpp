// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001571a0..0x001575f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00157450 hulkfight::motion::HitOrientToPushbackTrack::vfunc_10 (70 B): matches/0x00157450.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HitOrientToPushbackTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_157450;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct HitOrientToPushbackAction_nv_157450 {
    u32_157450 Init_00152480(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern hulkfight::motion::HitOrientToPushbackAction* Alloc_0008d690(int);

hulk_intptr hulkfight::motion::HitOrientToPushbackTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_157450 a = (u32_157450)__p0; u32_157450 b = (u32_157450)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::HitOrientToPushbackAction* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(((HitOrientToPushbackAction_nv_157450*)(((hulkfight::motion::HitOrientToPushbackAction*)(q))))->Init_00152480(this, p));
    }
    return (int)(0);
}

