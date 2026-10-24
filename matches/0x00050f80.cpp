#include "gen/fight.h"

namespace fight {
class ConditionFactoryCaster_50f80 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CIsGrappledCondition_50f80;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00493858;
template <> bool fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493858, 0) != 0;
}
