#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b70e0;
namespace fight {
class ConditionFactoryCaster_16a730 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetHealthPercentCondition_16a730 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetHealthPercentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b70e0, 0) != 0;
}
