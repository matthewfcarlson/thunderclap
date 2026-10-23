#include "gen/fight.h"

extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_004b2660;
namespace fight {
class ConditionFactoryCaster_1544e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionExplosionCondition_1544e0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionExplosionCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_00491ca8, &DAT_004b2660, 0) != 0;
}
