#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00492408;
namespace fight {
class ConditionFactoryCaster_507c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CButtonUpCondition_507c0 {};
template <> bool fight::ConditionFactoryCasterTemplate<CButtonUpCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492408, 0) != 0;
}
