#include "gen/owners.h"
unsigned char owners::Thing_36fd0::FUN_00036fd0(hulk_intptr arg) {
    int index = FUN_00036f00(((int)arg));
    if (index < 0)
        return 0;
    return *((unsigned char*)this + ((index + 0x226) << 4));
}
