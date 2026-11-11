// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001571a0..0x001575f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001573a0 hulkfight::motion::HitThrowTrack::vfunc_10 (70 B): matches/0x001573a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HitThrowTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00138d00 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct HitThrowAction_nv_1573a0 {
    int Init_00151f20(hulkfight::motion::HitThrowTrack*, hulk_intptr);
};
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
extern void* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::HitThrowTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        hulkfight::motion::HitThrowAction* p = (hulkfight::motion::HitThrowAction*)Alloc_0008d690(0x40);
        if (p)
            return ((HitThrowAction_nv_1573a0*)(((hulkfight::motion::HitThrowAction*)(p))))->Init_00151f20(this, c);
    }
    return 0;
}

