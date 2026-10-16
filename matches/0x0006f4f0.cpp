#include "gen/fight.h"

struct Thing_6f4f0 {
    int init();
};
void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CGrappleDetachTrack>::vfunc_5() {
    Thing_6f4f0* p = (Thing_6f4f0*)operator new(0x14);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
