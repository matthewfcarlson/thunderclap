#include "gen/fight.h"

extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &a, &b, 0) != 0;
}
