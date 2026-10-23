#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_1797a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetIconDistanceTrack_1797a0;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004ba968;
extern "C" void* castTrack(void*, void*, void*, void*, void*);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return castTrack(p, 0, &DAT_0049850c, &DAT_004ba968, 0) != 0;
}
