// Same code shape as 0x0006f4f0 (propagated; names are from that function)
#include "gen/fight.h"

struct Thing_70150 {
    int init();
};
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropRemoveInstanceTrack>::vfunc_5() {
    Thing_70150* p = (Thing_70150*)operator new(0x14);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
