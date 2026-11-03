#include "decls/data/game/unknown.h"
#include "gen/owners.h"

unsigned char owners::Obj_16ebc0::FUN_0016ebc0(const volatile float* p) {
    float a = p[0] * (*(float*)&DAT_003f32b8);
    float b = p[1] * (*(float*)&DAT_003f32b8);
    volatile float c[3];
    c[2] = p[2] * (*(float*)&DAT_003f32b8);
    z = c[2];
    x = a;
    y = b;
    return 1;
}