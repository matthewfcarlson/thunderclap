#include "decls/data/game/hulkfight.h"
// data: gCounter_362f0 = DAT_004dc2a8
#include "gen/owners.h"

void owners::Obj_362f0::FUN_000362f0() {
    if (enabled) {
        int n = ++(*(int*)&DAT_004dc2a8);
        flag = (n % 2 == 0);
        if (n % 3 == 1)
            mode = 0;
        else
            mode = (n % 3 != 2) + 1;
    }
}