#include "decls/data/game/global.h"
// data: threshold_fc800 = DAT_003f5d00
#include "gen/owners.h"

typedef unsigned char u8;
bool owners::Obj_fc800::FUN_000fc800() {
    if (flag12)
        return true;
    if (!(value < DAT_003f5d00) && !flag10)
        return false;
    return true;
}