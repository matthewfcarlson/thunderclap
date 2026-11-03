#include "decls/data/game/global.h"
// data: gZero_1c05d0 = DAT_003f32e0
#include "gen/owners.h"

void owners::Obj_1c05d0::FUN_001c05d0(float a, float b) {
    if (!active || !ptr)
        return;
    if (value < DAT_003f32e0)
        value = 0.0f;
    else
        value = a / b;
    Tick();
    if (up) {
        if (amount >= 255)
            return;
        amount += 10;
        if (amount <= 255)
            return;
        amount = 255;
    } else {
        if (amount <= 0)
            return;
        amount -= 10;
        if (amount >= 0)
            return;
        amount = 0;
    }
}
