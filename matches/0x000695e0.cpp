#include "decls/data/game/hulkfight.h"
// data: minusOne = DAT_003f3388
#include "gen/owners.h"

float owners::A_695e0::FUN_000695e0(int i) {
    if (i >= 0 && i < 8)
        return values[i];
    return DAT_003f3388;
}