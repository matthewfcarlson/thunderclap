#include "compat/ptr.h"
extern "C" int __cdecl iscntrl(int);
extern int __cdecl FUN_00216320(int, const char*, ...);
extern int DAT_004267ec[];
int __cdecl FUN_0021af00(hulk_intptr a, int b) {
    int r;
    if (b < 0x101) {
        if (iscntrl(b))
            r = FUN_00216320(*(int*)(a + 0x20), "char(%d)", b);
        else
            r = FUN_00216320(*(int*)(a + 0x20), "%c", b);
    } else {
        r = DAT_004267ec[b];
    }
    return r;
}