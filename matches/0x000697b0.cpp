#include "compat/ptr.h"
#include "gen/global.h"

extern int* gValues;

hulk_intptr CComboMessageTrack::vfunc_0(int index) {
    return gValues[index];
}
