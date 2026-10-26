#include "compat/ptr.h"
#include "gen/global.h"

extern "C" int* g_table_698a0;

hulk_intptr CMoveTrack::vfunc_0(int index) {
    return g_table_698a0[index];
}
