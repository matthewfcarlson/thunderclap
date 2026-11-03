#include "compat/ptr.h"
#include "decls/data/platform/xbox/movie.h"

extern "C" void __cdecl FUN_003338a0();
extern "C" void __cdecl FUN_003338c0();
extern "C" void __stdcall FUN_0033eb70(void*, void*);
extern "C" void __cdecl FUN_003351a0(int);
extern "C" void __cdecl FUN_00333b50(int value) {
    FUN_0033eb70((void*)((hulk_intptr)(void (__cdecl*)())&FUN_003338a0), (void*)((hulk_intptr)(void (__cdecl*)())&FUN_003338c0));
    DAT_00555ba0 = value;
    FUN_003351a0(value);
    (*(unsigned char*)&DAT_00555b9c) = 1;
}
