// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00138bd0 hulkfight::motion::GrappleHoverTrack::vfunc_10 (61 B): matches/0x00138bd0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@GrappleHoverTrack@motion@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

struct HoverAction_nv_138bd0 {
    hulk_intptr build_00134db0(int, hulk_intptr);   // (decl1) passes as defined
};
extern "C" int __cdecl FUN_0005a470(hulk_intptr);   // (decl1) as defined (CFightParamsCollision.cpp)
extern hulkfight::motion::HoverAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::GrappleHoverTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int x = FUN_0005a470(c);
    if (x) {
        hulkfight::motion::HoverAction* p = Alloc_0008d690((int)sizeof(::hulkfight::motion::HoverAction));   // (allocsize1) the size by gen's record
        if (p) {
            int f = this->groundFixup;
            return ((HoverAction_nv_138bd0*)(((hulkfight::motion::HoverAction*)(p))))->build_00134db0(f, x);
        }
    }
    return 0;
}

