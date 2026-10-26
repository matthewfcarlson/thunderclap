#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable;

hulk_intptr CScrubberTrack::vfunc_0(int i) {
    return gTable[i];
}
