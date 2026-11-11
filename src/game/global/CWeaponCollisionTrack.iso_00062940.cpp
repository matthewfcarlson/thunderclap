// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00062940 CSmartPropThrowTrack::vfunc_12 (40 B): matches/0x00062940.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropThrowTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropThrowAction_nv_62940 {
    int invoke_0001f260(CSmartPropThrowTrack*, hulk_intptr);
};
extern CSmartPropThrowAction* FUN_0008d690(int);

hulk_intptr CSmartPropThrowTrack::vfunc_12(hulk_intptr param) {
    CSmartPropThrowAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropThrowAction_nv_62940*)(((CSmartPropThrowAction*)(p))))->invoke_0001f260(this, param);
    return 0;
}

