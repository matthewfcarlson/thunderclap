// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_77ca0;
struct CGrabTrack_77ca0 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CJointTrack>::vfunc_5() {
    CGrabTrack_77ca0* p = (CGrabTrack_77ca0*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
