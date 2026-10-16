// Same code shape as 0x0006f340 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_6f8e0;
struct Helper_6f8e0 {
    u32_6f8e0 run();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CGrappleSequenceTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6f8e0*)p)->run());
    return (void*)(0);
}
