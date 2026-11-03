#include "gen/owners.h"
bool owners::Thing_1c9700::FUN_001c9700(int index, int value) {
    if (index >= 0 && index < 3) {
        ((int*)this)[2 + index] = value;
        return true;
    }
    return false;
}