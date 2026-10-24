#include "gen/fight.h"

class CAxisDoubleTapCondition_50580;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00491ea0;
namespace fight {
class ConditionFactoryCaster_50580 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::ConditionFactoryCasterTemplate<CAxisDoubleTapCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491ea0, 0) != 0;
}
