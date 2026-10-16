#include "gen/fight.h"

extern "C" int FUN_00344e74(int a, int b, int c, int d, int e);
class TrackFactoryCaster_6df90 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};

template <> bool fight::TrackFactoryCasterTemplate<CJumpTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (bool)((int)(!!FUN_00344e74(a, 0, 0x49850c, 0x499fcc, 0)));
}
