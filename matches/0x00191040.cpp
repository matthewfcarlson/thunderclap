#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004bfb68;
extern "C" void* __cdecl Lookup(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_191040 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TankLocomotionTrack_191040 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Lookup(p, 0, &DAT_0049850c, &DAT_004bfb68, 0) != 0;
}
