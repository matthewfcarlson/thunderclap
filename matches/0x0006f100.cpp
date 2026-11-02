#include "compat/ptr.h"
#include "gen/fight.h"

struct Allocated_6f100 {
    hulk_intptr Finish();
};
extern "C" void* FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CClearHitRecordsTrack>::vfunc_5() {
    Allocated_6f100* p = (Allocated_6f100*)FUN_0008d690(0x10);
    if (p)
        return (void*)(p->Finish());
    return (void*)(0);
}
