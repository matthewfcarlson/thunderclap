#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_000b0ff0();
extern void __stdcall FUN_00013420(void*, int, int, void*);
void FUN_00363d90() {
    char* p = (char*)((hulk_intptr)((char*)&DAT_004ddb10));
    int i = 2;
    do {
        p -= 0x30;
        FUN_00013420(p, 8, 6, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_000b0ff0));
        --i;
    } while (i);
}