#include "gen/fight.h"

#include "compat/ptr.h"
extern char DAT_00491ca8;
extern char DAT_00492108;
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class ConditionFactoryCaster_50680 {
  public:
    virtual int vfunc_0(int a);
};

template <> bool fight::ConditionFactoryCasterTemplate<CAxisSpeedCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_00492108, 0) != 0;
}
