#include "decls/address.h"
#include "decls/data/game/unknown.h"
// data: gGlobal2 = DAT_004dc04c, gGlobal_35c800 = DAT_004dc048
void FUN_0035c800() {
    unsigned long long v = FUN_0027b020("commanche");
    *(unsigned int*)((char*)&DAT_004dc048) = (unsigned int)v;
    *(unsigned int*)((char*)&DAT_004dc04c) = (unsigned int)(v >> 32);
}
