#include "compat/ptr.h"
#include "gen/global.h"

extern void** gTable_6a200;

int CIntangibleToActorsTrack::vfunc_0(int i) {
    return (hulk_intptr)(gTable_6a200[i]);
}
