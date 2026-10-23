#include "gen/fight.h"

class Base {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* a;
extern void* b;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
