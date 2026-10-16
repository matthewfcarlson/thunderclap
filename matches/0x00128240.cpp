#include "gen/fight.h"

extern "C" int Check(void*, int, int, int, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetFirstShotCondition>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return Check(a, 0, 0x491ca8, 0x4a8a50, 0) != 0;
}
