#include "compat/ptr.h"
#include "gen/fight.h"

extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int gTypeA_508c0;
extern int gTypeB;

template <> bool fight::ConditionFactoryCasterTemplate<CClimbableCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_508c0, (hulk_intptr)&gTypeB, 0) != 0;
}
