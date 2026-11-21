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
    void* method_00133c20();   // (decl2) the constructor 0x00133c20 returns this
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl2) the allocator as defined (unk_08ceb0.cpp)

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_5() {
    hulkfight::motion::AirToGroundTargetTrack* p = (hulkfight::motion::AirToGroundTargetTrack*)FUN_0008d690((unsigned int)sizeof(::hulkfight::motion::AirToGroundTargetTrack));   // (decl2) gen's record (0x38 on 32-bit)
    if (p)
        return ((AirToGroundTargetTrack_nv_139710*)(((hulkfight::motion::AirToGroundTargetTrack*)(p))))->method_00133c20();
    return (void*)(0);
}

