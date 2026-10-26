#include "compat/ptr.h"
#include "gen/global.h"

extern int* g_table_6ae50;

hulk_intptr CDeathTrack::vfunc_0(int arg) {
    return g_table_6ae50[arg];
}
