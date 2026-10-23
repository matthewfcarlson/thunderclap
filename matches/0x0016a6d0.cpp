#include "gen/fight.h"

extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b7010;
namespace fight {
class ConditionFactoryCaster_16a6d0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetLocomotionMotionStateCondition_16a6d0;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetLocomotionMotionStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b7010, 0) != 0;
}
