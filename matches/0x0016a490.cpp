#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b6c38;
namespace fight {
class ConditionFactoryCaster_16a490 {
  public:
    virtual int Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class LocomotionMotionStateCondition_16a490 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6c38, 0) != 0;
}
