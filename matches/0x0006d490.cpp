#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_6d490 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CCameraHintTrack_6d490;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_00498760;
template <> bool fight::TrackFactoryCasterTemplate<CCameraHintTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_00498760, 0) != 0;
}
