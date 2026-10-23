#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_128140 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetVelocityXZCondition_128140 {};
} // namespace ai
} // namespace hulkfight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a88d0;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a88d0, 0) != 0;
}
