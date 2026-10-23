#include "gen/fight.h"

class CHeadTrackerTrack_6dd90;
class TrackFactoryCaster_6dd90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl cast(void*, int, void*, void*, int);
extern int a, b;

template <> bool fight::TrackFactoryCasterTemplate<CHeadTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &a, &b, 0) != 0;
}
