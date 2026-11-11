// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0013e4d0 fight::TrackFactoryTemplate<hulkfight::motion::AnimationTrack>::vfunc_5 (24 B): matches/0x0013e4d0.cpp [isolated: conflict: operator_new; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAnimationTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_13e4d0;
struct CGrabTrack_13e4d0 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationTrack>::vfunc_5() {
    CGrabTrack_13e4d0* p = (CGrabTrack_13e4d0*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}

