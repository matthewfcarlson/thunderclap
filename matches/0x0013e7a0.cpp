// Same code shape as 0x0006fb80 (propagated; names are from that function)
#include "gen/fight.h"

struct CHitAnimationTrack_13e7a0 {
    unsigned int* vf;
    void init();
};
extern int hit_vftable;
extern void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_5() {
    CHitAnimationTrack_13e7a0* p = (CHitAnimationTrack_13e7a0*)alloc(0x50);
    if (p) {
        p->init();
        p->vf = (unsigned int*)&hit_vftable;
        return (void*)(p);
    }
    return (void*)(0);
}
