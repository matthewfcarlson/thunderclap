#include "compat/ptr.h"
#include "gen/fight.h"

extern hulk_intptr FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);

template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::KeyWordWaitCondition>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return (int)FUN_00344e74(a, 0, 0x491ca8, 0x4a3f00, 0) ? 1 : 0;
}
