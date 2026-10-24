#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_50980 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CCollisionFlagCondition_50980;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00492878;
template <> bool fight::ConditionFactoryCasterTemplate<CCollisionFlagCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492878, 0) != 0;
}
