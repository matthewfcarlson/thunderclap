#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
// data: negone = DAT_003f3388, one = DAT_003f32dc, zero_83d90 = DAT_003f32e0

float FUN_00083d90(float* p) {
    if (*p < DAT_003f32e0)
        return DAT_003f3388;
    if (*p > DAT_003f32e0)
        return DAT_003f32dc;
    return DAT_003f32e0;
}
