#include "compat/ptr.h"
#include "gen/global.h"

extern int* g_table_6b090;

hulk_intptr CMotionHitGroundHeightTrack::vfunc_0(int index) {
    return g_table_6b090[index];
}
