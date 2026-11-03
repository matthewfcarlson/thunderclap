#include "gen/owners.h"

int owners::X_264c70::FUN_00264c70() {
    unsigned int edx = f14;
    unsigned int eax = f18;
    int count;
    if (edx <= eax) {
        count = (int)(eax - edx) >> 3;
    } else {
        count = ((int)(eax - f1c) >> 3) + ((int)(f20 - edx) >> 3);
    }
    if ((unsigned int)count > 0u || f8 != 0)
        return 1;
    return 0;
}
