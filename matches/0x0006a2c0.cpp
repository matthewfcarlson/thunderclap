#include "compat/ptr.h"
#include "gen/global.h"

extern void* g_table_6a2c0;

int CCameraShakeTrack::vfunc_0(int index) {
    void** p = (void**)g_table_6a2c0;
    return (hulk_intptr)p[index];
}
