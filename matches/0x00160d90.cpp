#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_160d90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class LocomotingCondition_160d90 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004b4450;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotingCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b4450, 0) != 0;
}
