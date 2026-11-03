#include "gen/owners.h"
void owners::C_1b6de0::FUN_001b6de0(hulk_intptr x) {
    int i = 0;
    do {
        if (a[i * 2] == ((int)x)) {
            a[i * 2] = 0;
            return;
        }
        ++i;
    } while (i < 3);
}