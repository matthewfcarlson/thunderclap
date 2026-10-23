#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00498878;
namespace fight {
class TrackFactoryCaster_6d510 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CClearHitRecordsTrack_6d510 {};
template <> bool fight::TrackFactoryCasterTemplate<CClearHitRecordsTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_00498878, 0) != 0;
}
