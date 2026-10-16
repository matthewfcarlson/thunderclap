#include "gen/fight.h"

extern int FUN_00344e74(int, int, int, int, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (int)FUN_00344e74(a, 0, 0x491ca8, 0x4a3f00, 0) ? 1 : 0;
}
