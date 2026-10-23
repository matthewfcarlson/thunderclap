#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_154900 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitThrowTrack_154900 {};
} // namespace motion
} // namespace hulkfight
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b2d80;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b2d80, 0) != 0;
}
