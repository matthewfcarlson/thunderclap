#include "decls/data/game/global.h"
// data: gOne_3ebb0 = DAT_003f32dc, gZero_3ebb0 = DAT_003f32e0
#include "gen/owners.h"


float owners::ClampOwner_3ebb0::FUN_0003ebb0(int key) {
    float value = mValue;
    if (key != mKey)
        return DAT_003f32e0;
    if (value >= DAT_003f32e0 && value <= DAT_003f32dc)
        return value;
    if (value > DAT_003f32dc)
        return DAT_003f32dc;
    return DAT_003f32e0;
}
