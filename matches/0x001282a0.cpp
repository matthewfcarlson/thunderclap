#include "gen/fight.h"

extern "C" int FUN_00344e74(int, int, int, int, int);
extern int g1;
extern int g2;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0(void* __p0) { int x = (int)__p0;

    return FUN_00344e74(x, 0, (int)&g2, (int)&g1, 0) != 0;
}
