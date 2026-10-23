#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004985b8;
namespace fight {
class TrackFactoryCaster_6d3d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CAlertStatusTrack_6d3d0 {};
template <> bool fight::TrackFactoryCasterTemplate<CAlertStatusTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004985b8, 0) != 0;
}
