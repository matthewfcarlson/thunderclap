#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_154c00 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class InterruptPriorityTrack_154c00 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b30e0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::InterruptPriorityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b30e0, 0) != 0;
}
