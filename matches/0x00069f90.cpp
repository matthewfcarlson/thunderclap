#include "compat/ptr.h"
#include "gen/global.h"

extern int* gComboTimerValues;

hulk_intptr CComboTimerTrack::vfunc_0(int index) {
    return gComboTimerValues[index];
}
