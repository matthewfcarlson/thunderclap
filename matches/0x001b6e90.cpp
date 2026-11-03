#include "gen/owners.h"
bool owners::X_1b6e90::FUN_001b6e90(hulk_intptr v) {
    for (int i = 0; i < 3; ++i) {
        if (*((int*)((char*)this + i * 8)) == ((int)v))
            return true;
    }
    return false;
}