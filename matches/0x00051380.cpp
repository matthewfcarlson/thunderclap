#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster_51380 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CSmartPropStateCondition_51380 {};
extern char DAT_00491ca8;
extern char DAT_00494278;
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00494278, 0) != 0;
}
