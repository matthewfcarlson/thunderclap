#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_000b0ff0();
extern void __stdcall FUN_00013420(void*, int, int, void*);
void target() {
    char* p = (char*)((hulk_intptr)DAT_004ddbc8);
    int i = 2;
    do {
        FUN_00013420(p, ((p -= 0x30), 8), 6, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_000b0ff0));
    } while (--i);
}