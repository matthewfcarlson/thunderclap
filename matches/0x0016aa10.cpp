#include "gen/fight.h"

class Condition_16aa10 {
  public:
    virtual void f();
};
class ConditionFactoryCasterTemplate_16aa10 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
