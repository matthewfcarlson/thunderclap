// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000627a0 CSmartPropSetStateTrack::vfunc_12 (40 B): matches/0x000627a0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropSetStateTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropSetStateAction_nv_627a0 {
    int invoke(CSmartPropSetStateTrack*, hulk_intptr);
};
extern CSmartPropSetStateAction* FUN_0008d690(int);

hulk_intptr CSmartPropSetStateTrack::vfunc_12(hulk_intptr param) {
    CSmartPropSetStateAction* p = FUN_0008d690((int)sizeof(CSmartPropSetStateAction));
    if (p)
        return ((CSmartPropSetStateAction_nv_627a0*)(((CSmartPropSetStateAction*)(p))))->invoke(this, param);
    return 0;
}

