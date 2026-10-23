#include "gen/fight.h"

extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_1541a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionTargetPriorityCondition_1541a0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_00491ca8;
extern char DAT_004b2000;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastCheck(p, 0, &DAT_00491ca8, &DAT_004b2000, 0) != 0;
}
