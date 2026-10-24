#include "gen/fight.h"

class Condition_154840 {};
namespace fight {
class ConditionFactoryCaster_154840 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionSourceNameCondition_154840 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b2c00;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2c00, 0) != 0;
}
