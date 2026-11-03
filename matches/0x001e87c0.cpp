#include "decls/data/game/unknown.h"
// data: gBias = DAT_003f3f18, gValue_1e87c0 = DAT_004e36a8

void __stdcall FUN_001e87c0(int amount) {
    if (amount < 0) {
        (*(float*)&DAT_004e36a8) -= (float)amount + DAT_003f3f18;
    } else {
        (*(float*)&DAT_004e36a8) -= (float)amount;
    }
}