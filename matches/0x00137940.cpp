#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_137940 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004abf00;
namespace fight {
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingAttackTrack_137940 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004abf00, 0) != 0;
}
