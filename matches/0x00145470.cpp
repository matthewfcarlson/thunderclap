#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class MotionBlurTrack_145470 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004ae1a0;
namespace fight {
class TrackFactoryCaster_145470 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ae1a0, 0) != 0;
}
