#include "decls/data/game/global.h"
// data: hulk_at_004c3710 = DAT_004c3710, hulk_at_004c3714 = DAT_004c3714

#include "compat/ptr.h"
extern "C" void __cdecl FUN_001afab0(int b, int a) {
    *(__int32*)((hulk_intptr)((char*)&DAT_004c3714)) = a;
    *(__int32*)((hulk_intptr)((char*)&DAT_004c3710)) = b;
}
