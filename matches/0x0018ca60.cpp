// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_18ca60;
struct CGrabTrack_18ca60 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSpawnTrack>::vfunc_5() {
    CGrabTrack_18ca60* p = (CGrabTrack_18ca60*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
