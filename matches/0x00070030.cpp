// Same code shape as 0x0006f4f0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

struct Thing_70030 {
    hulk_intptr init();
};
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropDropTrack>::vfunc_5() {
    Thing_70030* p = (Thing_70030*)operator new(0x14);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
