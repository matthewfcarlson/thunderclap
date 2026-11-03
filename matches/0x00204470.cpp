#include "gen/owners.h"
bool owners::C_204470::FUN_00204470(hulk_intptr i) {
    if (((int)i) < 0)
        return false;
    if (((int)i) >= 0x400)
        return false;
    return a[((int)i)] == 2;
}
