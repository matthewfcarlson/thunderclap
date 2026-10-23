#include "gen/fight.h"

extern int __cdecl check(void*, int, void*, void*, int);
extern int a, b;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &a, &b, 0) != 0;
}
