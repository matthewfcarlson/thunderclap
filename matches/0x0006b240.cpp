#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable;

hulk_intptr CTargetTrack::vfunc_0(int i) {
    return gTable[i];
}
