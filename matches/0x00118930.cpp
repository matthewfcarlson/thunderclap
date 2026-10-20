#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" int FUN_00344e74(hulk_intptr, int, void*, void*, int);
class ConditionFactoryCaster_118930 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return FUN_00344e74(a, 0, (void*)0x491ca8, (void*)0x4a5570, 0) != 0;
}
