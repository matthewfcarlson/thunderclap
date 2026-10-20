#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" int FUN_00344e74(int, int, int, int, int);
extern int g1;
extern int g2;

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetInvincibleCondition>::vfunc_0(void* __p0) { hulk_intptr x = (hulk_intptr)__p0;

    return FUN_00344e74(x, 0, (hulk_intptr)&g2, (hulk_intptr)&g1, 0) != 0;
}
