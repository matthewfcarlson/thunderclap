#include "decls/data/game/unknown.h"
// data: hulk_at_004c83e8 = DAT_004c83e8

#include "compat/ptr.h"
extern "C" unsigned int __stdcall FUN_001fd4c0(unsigned int x) {
    *(unsigned int*)((hulk_intptr)((char*)&DAT_004c83e8)) = x;
    return x;
}