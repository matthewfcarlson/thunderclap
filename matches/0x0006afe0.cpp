// cl-flags: /O2 /GR /GX
#include "compat/ptr.h"
#include "gen/global.h"

extern "C" int* g_table_6afe0;

hulk_intptr CClearCollisionStun::vfunc_0(int x) {
    return g_table_6afe0[x];
}
