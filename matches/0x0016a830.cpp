#include "gen/fight.h"

extern int __cdecl Check(void*, void*, void*, void*, void*);
extern int a, b;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &a, &b, 0) != 0;
}
