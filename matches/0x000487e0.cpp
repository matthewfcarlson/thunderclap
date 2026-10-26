// Same code shape as 0x00048570 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

bool CAxisPressCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 1;
}
