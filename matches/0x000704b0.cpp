#include "gen/fight.h"

typedef unsigned int uint;
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" int __fastcall Construct(void*);

template <> void* fight::TrackFactoryTemplate<CSnapToWallTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}
