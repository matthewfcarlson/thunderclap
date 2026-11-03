#include "gen/owners.h"

void owners::Thing_8ff00::FUN_0008ff00(hulk_intptr value, int unused) {
    unsigned int index = (((int)value) - base) / divisor;
    bits[index >> 5] &= ~(1u << (index & 31));
    if (index < limit)
        limit = index;
}