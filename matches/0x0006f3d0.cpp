#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6f3d0;
struct CGrabTrack_6f3d0 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CGrabTrack>::vfunc_5() {
    CGrabTrack_6f3d0* p = (CGrabTrack_6f3d0*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
