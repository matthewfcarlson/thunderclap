#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" int FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class ConditionFactoryCaster_1115c0 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TokenCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74(a, 0, 0x491ca8, 0x4a4348, 0) != 0);
}
