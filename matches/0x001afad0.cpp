#include "decls/data/game/global.h"
// data: gRate = DAT_004c3740, gTime = DAT_004e1810

extern "C" __int64 __cdecl FUN_0027b020(float);
void __cdecl FUN_001afad0(float a, float b) {
    (*(__int64*)&DAT_004e1810) = FUN_0027b020(a);
    (*(float*)&DAT_004c3740) = b;
}