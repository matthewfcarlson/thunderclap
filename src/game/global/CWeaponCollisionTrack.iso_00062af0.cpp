// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00062af0 CSmartPropDropTrack::vfunc_12 (40 B): matches/0x00062af0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropDropTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropDropAction_nv_62af0 {
    int invoke_0001f360(CSmartPropDropTrack*, hulk_intptr);
};
extern CSmartPropDropAction* FUN_0008d690(int);

hulk_intptr CSmartPropDropTrack::vfunc_12(hulk_intptr param) {
    CSmartPropDropAction* p = FUN_0008d690(0x24);
    if (p)
        return ((CSmartPropDropAction_nv_62af0*)(((CSmartPropDropAction*)(p))))->invoke_0001f360(this, param);
    return 0;
}

