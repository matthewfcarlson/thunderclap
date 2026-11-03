#include "gen/owners.h"
bool owners::C_35f20::FUN_00035f20() {
    int i = 0;
    do {
        if (a[i][0] != 0)
            return true;
        ++i;
    } while (i < 8);
    return false;
}