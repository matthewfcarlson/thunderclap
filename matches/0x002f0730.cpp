#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern float Compute(int, int, int);
bool Test(hulk_intptr a, hulk_intptr b, hulk_intptr c, hulk_intptr d, float* out) {
    float x = Compute(a, c, d);
    *out = x;
    if (x >= 0.0f) {
        if (x <= DAT_003f32dc)
            return true;
    }
    return false;
}
