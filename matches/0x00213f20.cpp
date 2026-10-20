#include "compat/ptr.h"
typedef unsigned char uchar;
int __fastcall FUN_00213f20(void* a, int* p) {
    int* s;
    int n;
    if (*(int*)(*p - 8) != 6)
        return -1;
    s = (int*)*(hulk_intptr*)(*p - 4);
    if (*(uchar*)((char*)s + 6) != 0)
        return -1;
    s = (int*)*(hulk_intptr*)((char*)s + 0xc);
    n = (p[2] - *(int*)((char*)s + 0xc)) >> 2;
    --n;
    if (n < 0)
        return -1;
    s = (int*)*(hulk_intptr*)((char*)s + 0x14);
    return s ? s[n] : 0;
}