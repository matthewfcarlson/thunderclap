#include "compat/ptr.h"
#include "gen/fight.h"
extern char DAT_00491ca8;
extern char DAT_004a8a50;

extern "C" int Check(void*, int, hulk_intptr, hulk_intptr, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return Check(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a8a50, 0) != 0;
}
