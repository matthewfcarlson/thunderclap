#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_154680 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionTargetNameCondition_154680;
}
} // namespace hulkfight
extern int g1, g2;
extern "C" void* cast(void*, int, int*, int*, int);
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &g1, &g2, 0) != 0;
}
