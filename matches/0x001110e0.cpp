#include "compat/ptr.h"
extern "C" int FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);

class ConditionFactoryCasterTemplate {
  public:
    virtual int vfunc_0(int a);
};

int ConditionFactoryCasterTemplate::vfunc_0(int a) {
    return (FUN_00344e74(a, 0, 0x491ca8, 0x4a3ce0, 0) != 0);
}
