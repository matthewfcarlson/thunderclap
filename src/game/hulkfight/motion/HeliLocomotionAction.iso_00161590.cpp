// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015cd10..0x00161c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::HeliLocomotionAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00161590 hulkfight::motion::LocomotionSteerTrack::vfunc_10 (40 B): matches/0x00161590.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@LocomotionSteerTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00161500 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct LocomotionSteerAction_nv_161590 {
    int Init(hulkfight::motion::LocomotionSteerTrack*, hulk_intptr);
};
extern hulkfight::motion::LocomotionSteerAction* Alloc(unsigned int);

hulk_intptr hulkfight::motion::LocomotionSteerTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    hulkfight::motion::LocomotionSteerAction* p = Alloc(0x30);
    if (p)
        return ((LocomotionSteerAction_nv_161590*)(((hulkfight::motion::LocomotionSteerAction*)(p))))->Init(this, c);
    return 0;
}

