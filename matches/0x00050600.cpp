#include "gen/fight.h"

class CAxisPressCondition_50600;
class ConditionFactoryCaster_50600 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_00491ca8;
extern char DAT_00491fd8;

template <> bool fight::ConditionFactoryCasterTemplate<CAxisPressCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491fd8, 0) != 0;
}
