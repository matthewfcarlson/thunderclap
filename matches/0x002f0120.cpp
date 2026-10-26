#include "decls/data/game/global.h"
// data: kZero_2f0120 = DAT_003f32e0

void F(float a, float b, float* out, char* ok) {
    if (a < -b) {
        *out = -b;
        *ok = 0;
        return;
    }
    if (a < DAT_003f32e0) {
        *out = a;
        *ok = 1;
        return;
    }
    if (a < b) {
        *out = a;
        *ok = 1;
        return;
    }
    *out = b;
    *ok = 0;
}
