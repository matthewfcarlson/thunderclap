// cl-flags: /O2 /GR /GX
#include "gen/global.h"

extern "C" int* g_table_6afe0;

int CClearCollisionStun::vfunc_0(int x) {
    return g_table_6afe0[x];
}
