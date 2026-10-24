#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct CIntangibleTrack_6de50;
class TrackFactoryCaster_6de50 {
  public:
    virtual int vfunc_0(void*);
};

template <> bool fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return (FUN_00344e74(a, 0, (void*)0x49850c, (void*)0x499d20, 0) != 0);
}
