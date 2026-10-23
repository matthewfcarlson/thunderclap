#include "gen/fight.h"

class CSmartPropThrowTrack_6e550 {};
class TrackFactoryCaster_6e550 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;

template <> bool fight::TrackFactoryCasterTemplate<CSmartPropThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}
