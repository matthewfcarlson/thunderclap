#include "gen/owners.h"
bool owners::C_79950::FUN_00079950(hulk_intptr x) {
    int i = lookup(((int)x));
    if (i == -1)
        return false;
    return *(int*)((char*)arr[i] + 0x10) != 0x13;
}