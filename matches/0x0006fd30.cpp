// Same code shape as 0x0006f4f0 (propagated; names are from that function)
#include "gen/fight.h"

struct Thing_6fd30 {
    int init();
};
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CPropActorSetStateTrack>::vfunc_5() {
    Thing_6fd30* p = (Thing_6fd30*)operator new(0x14);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
