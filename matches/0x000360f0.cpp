#include "decls/data/game/global.h"
// data: Zero_360f0 = DAT_003f32e0
#include "gen/owners.h"

bool owners::Thing_360f0::FUN_000360f0() {
    if (value > (*(float*)&DAT_003f32e0))
        return true;
    return count > 0;
}