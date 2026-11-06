#include "gen/fight.h"

#include "compat/ptr.h"
extern char DAT_0049850c;
extern char DAT_004a5a40;
extern "C" int __cdecl FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class TrackFactoryCaster_118c70 {
  public:
    virtual int vfunc_0(int a);
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return FUN_00344e74(a, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004a5a40, 0) != 0;
}
