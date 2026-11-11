// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00139710 fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_5 (24 B): matches/0x00139710.cpp [isolated: conflict: operator_new; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAirToGroundTargetTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/hulkfight.h"

struct AirToGroundTargetTrack_nv_139710 {
    hulk_intptr method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_5() {
    hulkfight::motion::AirToGroundTargetTrack* p = (hulkfight::motion::AirToGroundTargetTrack*)operator_new(0x38);
    if (p)
        return (void*)(((AirToGroundTargetTrack_nv_139710*)(((hulkfight::motion::AirToGroundTargetTrack*)(p))))->method());
    return (void*)(0);
}

