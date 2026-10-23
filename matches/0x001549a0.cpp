#include "gen/fight.h"

struct TrackFactoryCaster_1549a0 {
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitReactionFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
