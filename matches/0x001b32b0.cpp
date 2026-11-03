#include "gen/owners.h"
bool owners::X_1b32b0::FUN_001b32b0(hulk_intptr value) {
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (items[i] == ((int)value))
                return true;
            ++i;
        }
    }
    return false;
}