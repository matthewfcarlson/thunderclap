#include "gen/fight.h"

struct Allocated_6f100 {
    int Finish();
};
extern void* Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<CClearHitRecordsTrack>::vfunc_5() {
    Allocated_6f100* p = (Allocated_6f100*)Allocate(0x10);
    if (p)
        return (void*)(p->Finish());
    return (void*)(0);
}
