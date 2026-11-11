// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00062c70 CSmartPropRemoveInstanceTrack::vfunc_12 (43 B): matches/0x00062c70.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropRemoveInstanceTrack@@UAEHH@Z
#include "gen/global.h"

struct CSmartPropRemoveInstanceAction_nv_62c70 {
    int run_0001f460(hulk_intptr, int);
};
extern CSmartPropRemoveInstanceAction* __cdecl FUN_0008d690(int);

hulk_intptr CSmartPropRemoveInstanceTrack::vfunc_12(hulk_intptr arg) {
    CSmartPropRemoveInstanceAction* p = FUN_0008d690((int)sizeof(CSmartPropRemoveInstanceAction));
    if (p)
        return ((CSmartPropRemoveInstanceAction_nv_62c70*)(((CSmartPropRemoveInstanceAction*)(p))))->run_0001f460(arg, this->f_0c);
    return 0;
}

