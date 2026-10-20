// Same code shape as 0x00077d00 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_18c940;
void* __cdecl FUN_0008d690(unsigned int);
struct CKeyPoseTrack_18c940 {
    hulk_uintptr init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x78);
    if (p)
        return (void*)(((CKeyPoseTrack_18c940*)p)->init());
    return (void*)(0);
}
