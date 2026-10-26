#include "decls/data/game/global.h"
// data: kThree = DAT_003f331c, kZero_284a10 = DAT_003f32e0

#include "compat/ptr.h"

hulk_freg FUN_00284a10(float x) {
    if (x <= DAT_003f32e0)
        return DAT_003f32e0;
    if (x >= DAT_003f32dc)
        return DAT_003f32dc;
    return (DAT_003f331c - (x + x)) * x * x;
}
