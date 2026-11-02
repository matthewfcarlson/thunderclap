#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

extern void __cdecl FUN_003390d0(int, const char*, const char*, int);
extern "C" int FUN_0033d6c0(int a) {
    FUN_003390d0(a, (const char*)((hulk_intptr)((char*)&DAT_003fd600)), (const char*)((hulk_intptr)((char*)&DAT_00434af8)), 0);
    return 1;
}