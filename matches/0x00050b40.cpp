#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_50b40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00492d40;
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionPushbackYAngleCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492d40, 0) != 0;
}
