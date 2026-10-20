#include "compat/ptr.h"
extern "C" void __cdecl FUN_0033cdb0();
typedef unsigned int u32_33ce80;
extern void __cdecl F1(void*, int, int);
extern void __cdecl F2(void*, int);
extern void __cdecl F3(void*, int);
extern void __cdecl F4(void*, const void*, int);
int __cdecl Target(void* p) {
    F1(p, 1, 0);
    F1(p, 2, 0);
    F2(p, 2);
    F3(p, 0);
    F4(p, (const void*)((hulk_intptr)(void (__cdecl*)())&FUN_0033cdb0), 3);
    return 1;
}