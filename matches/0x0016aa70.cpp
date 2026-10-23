#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_16aa70 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class VelocityXZCondition_16aa70 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004b7640;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004b7640, 0) != 0;
}
