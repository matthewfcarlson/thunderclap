#include "decls/data/game/hulkfight.h"
// data: negativeOne = DAT_003f3388
#include "gen/owners.h"

void owners::Obj_e0100::FUN_000e0100() {
    if (a > DAT_003f3388 && b > DAT_003f3388) {
        flag = a <= b ? 1 : 0;
    }
}