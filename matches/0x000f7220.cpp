#include "gen/owners.h"
hulk_intptr owners::C_f7220::FUN_000f7220(hulk_intptr index) {
    if (((int)index) < 0 || ((int)index) > max)
        return 0;
    return items[((int)index)];
}