#include "compat/ptr.h"
#include "gen/fight.h"

class CGrappleDamageTrack_6d950;
class TrackFactoryCaster_6d950 {
  public:
    virtual bool vfunc_0(int owner);
    virtual bool vfunc_1(int owner);
};
int FUN_00344e74(int owner, int a, int b, int c, int d);

template <> bool fight::TrackFactoryCasterTemplate<CGrappleDamageTrack>::vfunc_0(void* __p0) { hulk_intptr owner = (hulk_intptr)__p0;

    return FUN_00344e74(owner, 0, 0x49850c, 0x499170, 0) != 0;
}
