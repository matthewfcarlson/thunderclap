#include "gen/owners.h"
void owners::Thing_1b6e60::FUN_001b6e60(hulk_intptr param) {
    int i = 0;
    do {
        if (a[i * 2] == ((int)param)) {
            a[i * 2 + 1] = 0x3e800000;
            return;
        }
        ++i;
    } while (i < 3);
    fallback(((int)param));
}