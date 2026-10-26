#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: limitValue = DAT_004dc0d8, zeroValue = DAT_003f32e0

void __stdcall SetLimit(float v) {
    (*(float*)&DAT_004dc0d8) = v;
    if (v < DAT_003f32e0)
        (*(float*)&DAT_004dc0d8) = 8.0f;
}