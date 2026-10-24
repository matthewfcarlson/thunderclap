#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b7b88;
namespace fight {
class ConditionFactoryCaster_16ad70 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HealthCondition_16ad70;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7b88, 0) != 0;
}
