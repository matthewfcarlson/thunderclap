#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b6aa8;
namespace fight {
class ConditionFactoryCaster_16a3b0 {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TurningVelocityCondition_16a3b0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_00491ca8, &DAT_004b6aa8, 0) != 0;
}
