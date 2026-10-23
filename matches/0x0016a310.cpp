#include "gen/fight.h"

extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b69e0;
namespace fight {
class ConditionFactoryCaster_16a310 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class RayCastTargetCondition_16a310 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastTargetCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b69e0, 0) != 0;
}
