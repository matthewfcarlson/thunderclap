// STATUS: equivalent (tools/equiv.py level 3: 552 inputs, branch coverage 12/12)
// FUN_000fb790 @ 0x000fb790
#include "compat/ptr.h"
void FUN_000fb790(short *dst, const char *src, int n)
{
    short *p = dst;
    if (*p != 0) {
        int off = 0;
        do {
            if ((off >> 1) == n - 1)
                break;
            p++;
            off += 2;
        } while (*p != 0);
    }
    if (*src != 0) {
        hulk_intptr off = (hulk_intptr)p - (hulk_intptr)dst;
        do {
            if ((off >> 1) == n - 1)
                break;
            *p = (short)*src;
            p++;
            off += 2;
            src++;
        } while (*src != 0);
    }
    *p = 0;
}
