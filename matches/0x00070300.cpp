#include "gen/fight.h"

void* __cdecl FUN_0008d690(unsigned int);
struct Thing_70300 {
    unsigned int go();
};

template <> void* fight::TrackFactoryTemplate<CSmartPropThrowTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x44);
    if (p)
        return (void*)(((Thing_70300*)p)->go());
    return (void*)(0);
}
