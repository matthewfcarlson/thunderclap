// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0014ad70 hulkfight::motion::GrappleThrowTrack::vfunc_10 (58 B): matches/0x0014ad70.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@GrappleThrowTrack@motion@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

struct GrappleThrowAction_nv_14ad70 {
    int Init_00148a60(hulkfight::motion::GrappleThrowTrack*, int);
};
extern int __cdecl GetThing_0005a470(int);
extern void* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::GrappleThrowTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int x = GetThing_0005a470(c);
    if (x) {
        hulkfight::motion::GrappleThrowAction* p = (hulkfight::motion::GrappleThrowAction*)Alloc_0008d690(0x54);
        if (p)
            return ((GrappleThrowAction_nv_14ad70*)(((hulkfight::motion::GrappleThrowAction*)(p))))->Init_00148a60(this, x);
    }
    return 0;
}

