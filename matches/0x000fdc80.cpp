#include "gen/owners.h"
int owners::C_fdc80::FUN_000fdc80() {
    int i = index;
    if (i >= 0 && i < count)
        return *(int*)((char*)this + 0xc + i * 4);
    return 0;
}