#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_1869e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a;
extern int b;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
