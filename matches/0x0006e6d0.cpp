#include "gen/fight.h"

class CStunAnimationTrack_6e6d0;
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049b000;
namespace fight {
class TrackFactoryCaster_6e6d0 {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CStunAnimationTrack>::vfunc_0(void* __p0) { const char * p = (const char *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b000, 0) != 0;
}
