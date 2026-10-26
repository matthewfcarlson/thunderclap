#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gFirst_35d050 = DAT_004dd748, gSecond_35d050 = DAT_004dd74c
void __cdecl FUN_0035d050() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    *(unsigned int*)((char*)&DAT_004dd748) = (unsigned int)v;
    *(unsigned int*)((char*)&DAT_004dd74c) = (unsigned int)(v >> 32);
}
