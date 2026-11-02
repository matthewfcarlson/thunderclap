#include "compat/ptr.h"
#include "gen/fight.h"

struct CHitAnimationTrack_6fb80 {
    unsigned int* vf;
    void init();
};
extern int hit_vftable;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CHitAnimationTrack>::vfunc_5() {
    CHitAnimationTrack_6fb80* p = (CHitAnimationTrack_6fb80*)FUN_0008d690(0x50);
    if (p) {
        p->init();
        p->vf = (unsigned int*)&hit_vftable;
        return (void*)(p);
    }
    return (void*)(0);
}
