#include "gen/fight.h"

struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
namespace fight {
class ConditionFactoryCaster_127e20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class ProjectileDistanceCondition_127e20 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
