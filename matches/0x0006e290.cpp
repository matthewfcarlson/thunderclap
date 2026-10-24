#include "gen/fight.h"

struct TypeInfo {
    int x;
};
extern char DAT_0049850c;
extern char DAT_0049a650;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6e290 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
class CPushBackAnimationTrack_6e290 {};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CPushBackAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a650, 0) != 0;
}
