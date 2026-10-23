#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class MotionStateTrack_1793e0;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004ba4b8;
extern "C" void* __cdecl Cast(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster_1793e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Cast(p, 0, &DAT_0049850c, &DAT_004ba4b8, 0) != 0;
}
