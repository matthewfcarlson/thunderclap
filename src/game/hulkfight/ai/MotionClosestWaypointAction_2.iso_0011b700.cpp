// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0011b700 fight::TrackFactoryTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_5 (24 B): matches/0x0011b700.cpp [isolated: conflict: operator_new; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionClosestWaypointTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x000704b0 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int uint;
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" hulk_intptr __fastcall Construct(void*);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}

