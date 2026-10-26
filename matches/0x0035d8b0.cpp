#include "decls/address.h"
#include "decls/data/game/global.h"

void __cdecl FUN_0035d8b0() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned int*)&DAT_004de6d0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004de6d4) = (unsigned int)(r >> 32);
}
