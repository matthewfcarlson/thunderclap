#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);

class TrackFactoryCaster_6d590 {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};

class CClimbingTrack_6d590;

template <> bool fight::TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (bool)((int)(FUN_00344e74((void*)a, 0, 0x49850c, 0x498994, 0) != 0));
}
