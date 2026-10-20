// Same code shape as 0x0006f100 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

struct Allocated_6ffa0 {
    hulk_intptr Finish();
};
extern void* Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropDetachTrack>::vfunc_5() {
    Allocated_6ffa0* p = (Allocated_6ffa0*)Allocate(0x10);
    if (p)
        return (void*)(p->Finish());
    return (void*)(0);
}
