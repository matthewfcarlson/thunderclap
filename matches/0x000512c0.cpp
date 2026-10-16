// Same code shape as 0x000508c0 (propagated; names are from that function)
#include "gen/fight.h"

extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int gTypeA_512c0;
extern int gTypeB;

template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropDistanceCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((int)p, 0, (int)&gTypeA_512c0, (int)&gTypeB, 0) != 0;
}
