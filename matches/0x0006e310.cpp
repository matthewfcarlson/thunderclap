#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_6e310 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CHapticTrack_6e310;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049a764;
template <> bool fight::TrackFactoryCasterTemplate<CHapticTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a764, 0) != 0;
}
