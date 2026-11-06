#include "gen/fight.h"
extern char DAT_00491ca8;
extern char DAT_00493fd0;

class ConditionFactoryCaster_51280 {
  public:
    virtual int vfunc_0(void* a);
    virtual int vfunc_1(void* a);
};

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropCSMableCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return (FUN_00344e74(a, 0, (void*)&DAT_00491ca8, (void*)&DAT_00493fd0, 0) != 0);
}
