// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/hulkfight.h"

struct AirToGroundTargetTrack_nv_139710 {
    int method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_5() {
    hulkfight::motion::AirToGroundTargetTrack* p = (hulkfight::motion::AirToGroundTargetTrack*)operator_new(0x38);
    if (p)
        return (void*)(((AirToGroundTargetTrack_nv_139710*)(p))->method());
    return (void*)(0);
}
