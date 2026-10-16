// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_17f010;
struct CGrabTrack_17f010 {
    u32_17f010 init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_5() {
    CGrabTrack_17f010* p = (CGrabTrack_17f010*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
