#include "gen/fight.h"

class ConditionFactoryCaster_1547e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* g1;
extern void* g2;
class CollisionInterruptPriorityCondition_1547e0 {};

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}
