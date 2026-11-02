// Same code shape as 0x0006f100 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

struct Allocated_6ffa0 {
    hulk_intptr Finish();
};
extern "C" void* FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropDetachTrack>::vfunc_5() {
    Allocated_6ffa0* p = (Allocated_6ffa0*)FUN_0008d690(0x10);
    if (p)
        return (void*)(p->Finish());
    return (void*)(0);
}
