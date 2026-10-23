#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004ba810;
extern "C" int __cdecl cast_check(void*, int, const void*, const void*, int);
namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack_179640;
}
} // namespace hulkfight
namespace fight {
class TrackFactoryCaster_179640 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast_check(p, 0, &DAT_0049850c, &DAT_004ba810, 0) != 0;
}
