// Same code shape as 0x0006f340 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6fe80;
struct Helper_6fe80 {
    hulk_uintptr run();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CHapticTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6fe80*)p)->run());
    return (void*)(0);
}
