#include "gen/owners.h"
bool owners::C_37040::FUN_00037040(hulk_intptr key, int a, int b) {
    int n = Find(((int)key));
    if (n < 0)
        return false;
    ((char*)this)[(n + 0x226) * 16] = (char)a;
    ((char*)this)[n * 16 + 0x2261] = (char)b;
    return true;
}