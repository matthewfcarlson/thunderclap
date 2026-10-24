#include "gen/fight.h"

class CollisionChargeCondition_1545e0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1545e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_00491ca8;
extern char DAT_004b27f0;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b27f0, 0) != 0;
}
