#include "gen/owners.h"
int owners::X_1fd360::FUN_001fd360(int value) {
    int r = -1;
    int i = 0;
    do {
        if (items[i] == value) {
            r = i;
            break;
        }
        ++i;
    } while (i < 0x14);
    return r;
}
