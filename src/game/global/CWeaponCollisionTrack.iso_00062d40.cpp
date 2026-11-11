// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00062d40 CPropActorSetStateTrack::vfunc_12 (40 B): matches/0x00062d40.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CPropActorSetStateTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
#include "gen/global.h"

struct CPropActorSetStateAction_nv_62d40 {
    int invoke(CPropActorSetStateTrack*, hulk_intptr);
};
extern CPropActorSetStateAction* FUN_0008d690(int);

hulk_intptr CPropActorSetStateTrack::vfunc_12(hulk_intptr param) {
    CPropActorSetStateAction* p = FUN_0008d690((int)sizeof(CPropActorSetStateAction));
    if (p)
        return ((CPropActorSetStateAction_nv_62d40*)(((CPropActorSetStateAction*)(p))))->invoke(this, param);
    return 0;
}

