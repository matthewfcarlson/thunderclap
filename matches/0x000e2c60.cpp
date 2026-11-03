#include "gen/owners.h"
void owners::C_e2c60::FUN_000e2c60(hulk_intptr x) {
    int i = 0;
    while (i < 10 && slots[i] != 0)
        ++i;
    if (i != 10)
        slots[i] = ((int)x);
}