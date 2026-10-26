#include "decls/data/game/unknown.h"
// data: gBias = DAT_003f3f18, gValue_1e87c0 = DAT_004e36a8

void __stdcall FUN_001e87c0(int param_1) {
    if (param_1 < 0) {
        (*(float*)&DAT_004e36a8) -= (float)param_1 + DAT_003f3f18;
    } else {
        (*(float*)&DAT_004e36a8) -= (float)param_1;
    }
}