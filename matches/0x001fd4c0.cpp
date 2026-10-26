#include "decls/data/game/unknown.h"
// data: hulk_at_004c83e8 = DAT_004c83e8

#include "compat/ptr.h"
unsigned int __stdcall SetX(unsigned int x) {
    *(unsigned int*)((hulk_intptr)((char*)&DAT_004c83e8)) = x;
    return x;
}