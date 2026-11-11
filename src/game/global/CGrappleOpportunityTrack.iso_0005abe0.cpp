// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005abe0 CGrappleSwapTrack::vfunc_12 (40 B): matches/0x0005abe0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleSwapTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CGrappleSwapAction_nv_5abe0 {
    int invoke(CGrappleSwapTrack*, hulk_intptr);
};
extern CGrappleSwapAction* FUN_0008d690(int);

hulk_intptr CGrappleSwapTrack::vfunc_12(hulk_intptr param) {
    CGrappleSwapAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CGrappleSwapAction_nv_5abe0*)(((CGrappleSwapAction*)(p))))->invoke(this, param);
    return 0;
}

