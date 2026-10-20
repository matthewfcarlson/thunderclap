#include "gen/global.h"

extern int* gComboTimerValues;

int CComboTimerTrack::vfunc_0(int index) {
    return gComboTimerValues[index];
}
