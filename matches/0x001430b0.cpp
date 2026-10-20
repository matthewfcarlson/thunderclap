// Same code shape as 0x0006f220 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_1430b0;
extern void* __cdecl Alloc(hulk_uintptr);
struct InitObj_1430b0 {
    hulk_uintptr Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WallRunTrack>::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return (void*)(((InitObj_1430b0*)p)->Init());
    return (void*)(0);
}
