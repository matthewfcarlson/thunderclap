#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049ae78;
namespace fight {
class TrackFactoryCaster_6e610 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CSnapToWallTrack_6e610 {};
template <> bool fight::TrackFactoryCasterTemplate<CSnapToWallTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049ae78, 0) != 0;
}
