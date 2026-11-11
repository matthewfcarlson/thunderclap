// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005aca0 CGrappleDetachTrack::vfunc_12 (40 B): matches/0x0005aca0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleDetachTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CGrappleDetachAction_nv_5aca0 {
    int invoke(CGrappleDetachTrack*, hulk_intptr);
};
extern CGrappleDetachAction* FUN_0008d690(int);

hulk_intptr CGrappleDetachTrack::vfunc_12(hulk_intptr param) {
    CGrappleDetachAction* p = FUN_0008d690((int)sizeof(CGrappleDetachAction));
    if (p)
        return ((CGrappleDetachAction_nv_5aca0*)(((CGrappleDetachAction*)(p))))->invoke(this, param);
    return 0;
}

