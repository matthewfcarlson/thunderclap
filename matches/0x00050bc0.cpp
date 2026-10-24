#include "gen/fight.h"

#include "compat/ptr.h"
hulk_intptr __cdecl FUN_00344e74(hulk_intptr arg, int a, hulk_intptr b, hulk_intptr c, int d);

class ConditionFactoryCaster_50bc0 {
  public:
    virtual int f0(int arg);
    virtual int f1();
};

template <> bool fight::ConditionFactoryCasterTemplate<CFightNodeCondition>::vfunc_0(void* __p0) { int arg = (int)__p0;

    hulk_intptr r = FUN_00344e74(arg, 0, 0x491ca8, 0x492e90, 0);
    return r != 0;
}
