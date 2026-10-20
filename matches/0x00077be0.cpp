// Same code shape as 0x0006f220 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_77be0;
extern void* __cdecl Alloc(hulk_uintptr);
struct InitObj_77be0 {
    hulk_uintptr Init();
};

template <> void* fight::TrackFactoryTemplate<CHeadTrackerTrack>::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return (void*)(((InitObj_77be0*)p)->Init());
    return (void*)(0);
}
