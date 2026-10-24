#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void* obj, int a, int b, int c, int d);
class TrackFactoryCaster_141a70 {
  public:
    virtual int Cast(void* obj);
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, 0x49850c, 0x4ad6d8, 0) != 0);
}
