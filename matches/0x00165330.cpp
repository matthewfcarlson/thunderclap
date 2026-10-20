// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_165330;
struct CGrabTrack_165330 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_5() {
    CGrabTrack_165330* p = (CGrabTrack_165330*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
