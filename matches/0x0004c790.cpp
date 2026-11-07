#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
// data: scale = DAT_003f32b8
#include "gen/owners.h"

extern hulk_freg __cdecl FUN_0004af40(float, float, float);
bool owners::Thing_4c790::FUN_0004c790(float x) {
    angle = FUN_0004af40(0.0f, 360.0f, x) * DAT_003f32b8;
    return true;
}