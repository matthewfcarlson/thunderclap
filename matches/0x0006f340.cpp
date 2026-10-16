#include "gen/fight.h"

typedef unsigned int u32_6f340;
struct Helper_6f340 {
    u32_6f340 run();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CExplosionTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x20);
    if (p)
        return (void*)(((Helper_6f340*)p)->run());
    return (void*)(0);
}
