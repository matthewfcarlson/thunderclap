#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class LocomotionStateTrack_179160;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004ba200;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_179160 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotionStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba200, 0) != 0;
}
