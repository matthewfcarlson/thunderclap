#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049a910;
namespace fight {
class TrackFactoryCaster_6e3d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CSmartPropDetachTrack_6e3d0;

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropDetachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a910, 0) != 0;
}
