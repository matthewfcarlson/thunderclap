#include "compat/ptr.h"
hulk_intptr __cdecl FUN_00344e74(hulk_intptr arg, int a, hulk_intptr b, hulk_intptr c, int d);

class ConditionFactoryCaster {
  public:
    virtual int f0(int arg);
    virtual int f1();
};

class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int f0(int arg);
};

int ConditionFactoryCasterTemplate::f0(int arg) {
    hulk_intptr r = FUN_00344e74(arg, 0, 0x491ca8, 0x492e90, 0);
    return r != 0;
}
