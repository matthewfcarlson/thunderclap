// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000624b0 CSmartPropUpdateAttachmentTrack::vfunc_12 (40 B): matches/0x000624b0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CSmartPropUpdateAttachmentTrack@@UAEHH@Z
// Same code shape as 0x00062300 (propagated; names are from that function)
#include "gen/global.h"

struct CSmartPropUpdateAttachmentAction_nv_624b0 {
    int Fnf_0001ec50(CSmartPropUpdateAttachmentTrack*, hulk_intptr);
};
extern "C" CSmartPropUpdateAttachmentAction* __cdecl FUN_0008d690(int);

hulk_intptr CSmartPropUpdateAttachmentTrack::vfunc_12(hulk_intptr a) {
    CSmartPropUpdateAttachmentAction* p = FUN_0008d690(0x2c);
    if (p)
        return ((CSmartPropUpdateAttachmentAction_nv_624b0*)(((CSmartPropUpdateAttachmentAction*)(p))))->Fnf_0001ec50(this, a);
    return 0;
}

