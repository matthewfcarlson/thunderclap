#include "gen/owners.h"
unsigned char owners::Thing_1f8740::FUN_001f8740(hulk_intptr index) {
    unsigned char result = 0;
    if (((int)index) >= 0 && ((int)index) < 6)
        result = bytes[((int)index)];
    return result;
}