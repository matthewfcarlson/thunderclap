#include "compat/ptr.h"
extern "C" void __cdecl FUN_0033e8f0();
extern "C" void FUN_0033e950(int);
extern "C" void FUN_002134a0(int, const void*, int);
extern "C" int FUN_0033e9b0(int L) {
    FUN_0033e950(L);
    FUN_002134a0(L, (const void*)((hulk_intptr)(void (__cdecl*)())&FUN_0033e8f0), 1);
    return 1;
}