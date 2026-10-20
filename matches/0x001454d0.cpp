#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(hulk_intptr, int, void*, void*, int);

class TrackFactoryCaster_1454d0 {
  public:
    virtual bool vfunc_0(int);
    virtual void vfunc_1();
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack>::vfunc_0(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    return (FUN_00344e74(arg, 0, (void*)0x49850c, (void*)0x4ae250, 0) != 0);
}
