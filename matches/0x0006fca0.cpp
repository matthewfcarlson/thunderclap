// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_6fca0;
struct CGrabTrack_6fca0 {
    u32_6fca0 init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<COpportunityBallTrack>::vfunc_5() {
    CGrabTrack_6fca0* p = (CGrabTrack_6fca0*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
