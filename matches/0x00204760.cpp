#include "gen/owners.h"
void owners::Thing_204760::FUN_00204760(int value) {
    for (int i = 0; i < 2; ++i) {
        if (slots[i] == value) {
            slots[i] = 0;
            return;
        }
    }
}