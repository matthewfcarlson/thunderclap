#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004abb00;
extern "C" void* __cdecl cast(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster_1375e0 {
  public:
    virtual bool check(void*) = 0;
    virtual void other() = 0;
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingBrakeTrack_1375e0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingBrakeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &DAT_0049850c, &DAT_004abb00, 0) != 0;
}
