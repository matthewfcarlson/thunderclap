#include "compat/ptr.h"
#include "gen/global.h"

bool CButtonReleaseCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 3;
}
