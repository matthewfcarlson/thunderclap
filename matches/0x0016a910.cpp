#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b7408;
namespace fight {
class ConditionFactoryCaster_16a910 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class VelocityXZAngleCondition_16a910 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7408, 0) != 0;
}
