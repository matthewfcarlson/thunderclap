#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_16a5f0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetingCondition_16a5f0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004b6e80;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6e80, 0) != 0;
}
