#include "decls/data/game/global.h"
// data: zero_963c0 = DAT_003f32e0

#include "compat/ptr.h"
hulk_freg FUN_000963c0(float a, float b, float c, float d, float e) {
    if (!(e <= a)) {
        if (e >= c)
            return d;
        if (c - a > DAT_003f32e0)
            return (d - b) * ((e - a) / (c - a)) + b;
    }
    return b;
}
