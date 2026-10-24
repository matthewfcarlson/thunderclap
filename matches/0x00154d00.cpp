#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_154d00 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitFloatTrack_154d00 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b3248;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitFloatTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b3248, 0) != 0;
}
