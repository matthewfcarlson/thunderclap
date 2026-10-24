#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_51240 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CSmartPropAttachedCondition_51240 {};
extern char DAT_00491ca8;
extern char DAT_00493f28;
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropAttachedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493f28, 0) != 0;
}
