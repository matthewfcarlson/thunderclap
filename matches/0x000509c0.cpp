#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_509c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00492920;
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionHeightCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492920, 0) != 0;
}
