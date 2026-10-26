// cl-flags: /O2 /GR /GX
#include "compat/ptr.h"
#include "gen/global.h"

extern int* g_table_68fb0;

hulk_intptr CJumpTrack::vfunc_0(int index) {
    return g_table_68fb0[index];
}
