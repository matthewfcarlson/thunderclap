#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gLower = DAT_004de6a8, gUpper = DAT_004de6ac
void FUN_0035d8d0() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    (*(unsigned int*)&DAT_004de6a8) = (unsigned int)v;
    (*(unsigned int*)&DAT_004de6ac) = (unsigned int)(v >> 32);
}
