#include "gen/owners.h"
hulk_intptr owners::Obj_1dc0d0::FUN_001dc0d0(hulk_intptr i) {
    if (((int)i) >= 0 && ((int)i) < 0x800)
        return vals[((int)i)][0];
    return 0;
}