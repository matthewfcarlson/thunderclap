#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_127f20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetVelocityYCondition_127f20 {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004a85e8;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004a85e8, 0) != 0;
}
