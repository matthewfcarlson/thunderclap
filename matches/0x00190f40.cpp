#include "gen/fight.h"

extern const char gName1[];
extern const char gName2[];
extern "C" void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
namespace fight {
class TrackFactoryCaster_190f40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class ImpulseVelocityTrack_190f40 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, gName1, gName2, 0) != 0;
}
