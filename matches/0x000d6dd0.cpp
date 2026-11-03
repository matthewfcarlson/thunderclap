#include "gen/owners.h"
void owners::Slots_d6dd0::FUN_000d6dd0(hulk_intptr value) {
    for (int i = 0; i < 8; ++i) {
        if (values[i] == ((int)value)) {
            values[i] = 0;
            return;
        }
    }
}