#include "compat/ptr.h"
int __fastcall FUN_002043e0(hulk_intptr param_1) {
    int count = 0;
    unsigned char* p = (unsigned char*)(param_1 + 0x5a5);
    int n = 0x100;
    do {
        if (p[-1] == 1)
            ++count;
        if (p[0] == 1)
            ++count;
        if (p[1] == 1)
            ++count;
        if (p[2] == 1)
            ++count;
        p += 4;
        --n;
    } while (n != 0);
    return count;
}