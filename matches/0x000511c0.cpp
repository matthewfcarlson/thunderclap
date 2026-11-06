#include "gen/fight.h"
extern char DAT_00491ca8;
extern char DAT_00493de0;

extern "C" int FUN_00344e74(void* p, int a, void* b, void* c, int d);

template <> bool fight::ConditionFactoryCasterTemplate<CRageModeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return (int)FUN_00344e74(p, 0, (void*)&DAT_00491ca8, (void*)&DAT_00493de0, 0) != 0;
}
