// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00062a00 CSmartPropThrowingTrack::vfunc_12 (40 B): matches/0x00062a00.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropThrowingTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropThrowingAction_nv_62a00 {
    int invoke_0001f2e0(CSmartPropThrowingTrack*, hulk_intptr);
};
extern CSmartPropThrowingAction* FUN_0008d690(int);

hulk_intptr CSmartPropThrowingTrack::vfunc_12(hulk_intptr param) {
    CSmartPropThrowingAction* p = FUN_0008d690((int)sizeof(CSmartPropThrowingAction));
    if (p)
        return ((CSmartPropThrowingAction_nv_62a00*)(((CSmartPropThrowingAction*)(p))))->invoke_0001f2e0(this, param);
    return 0;
}

