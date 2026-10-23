#include "gen/fight.h"

extern int g1;
extern int g2;
extern "C" int __cdecl compare(void*, int, int*, int*, int);
namespace fight {
class ConditionFactoryCaster_118a30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class HasGroundPointExtendedCondition_118a30;
}
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return compare(p, 0, &g1, &g2, 0) != 0;
}
