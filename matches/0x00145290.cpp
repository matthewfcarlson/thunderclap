#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004adf98;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_145290 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SlowMotionTrack_145290;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004adf98, 0) != 0;
}
