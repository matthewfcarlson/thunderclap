#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_127b20 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
