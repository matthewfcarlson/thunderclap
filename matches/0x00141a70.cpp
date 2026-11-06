#include "gen/fight.h"
extern char DAT_0049850c;
extern char DAT_004ad6d8;

extern "C" int __cdecl FUN_00344e74(void* obj, int a, void* b, void* c, int d);
class TrackFactoryCaster_141a70 {
  public:
    virtual int Cast(void* obj);
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::WallExitTrack>::vfunc_0(void* __p0) { void * obj = (void *)__p0;

    return (FUN_00344e74(obj, 0, &DAT_0049850c, &DAT_004ad6d8, 0) != 0);
}
