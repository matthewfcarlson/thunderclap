#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_51300 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* DAT_00491ca8;
extern void* DAT_00494128;

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropGrabbableNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00494128, 0) != 0;
}
