#include "gen/owners.h"
int owners::C_f8c00::FUN_000f8c00(hulk_intptr x) {
    int i = 0;
    do {
        if (a[i] == 0)
            break;
        if (i == 128)
            return 0;
        ++i;
    } while (i < 128);
    a[i] = ((int)x);
    return ((int)x);
}