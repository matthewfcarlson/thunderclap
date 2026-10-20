#include "compat/ptr.h"
#include "gen/fight.h"

struct CMotionHitGroundHeightTrack_77020 {
    hulk_intptr vptr;
    int pad;
    int c;
    int d;
    float e;
    float f;
    void construct();
};
extern int vtable_77020;
extern void* operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CMotionHitGroundHeightTrack>::vfunc_5() {
    CMotionHitGroundHeightTrack_77020* p = (CMotionHitGroundHeightTrack_77020*)operator_new(0x18);
    if (p) {
        p->construct();
        p->vptr = (hulk_intptr)&vtable_77020;
        p->d = 0;
        p->e = -1.0f;
        p->f = 1.0f;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
