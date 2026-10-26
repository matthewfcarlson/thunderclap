#include "decls/address.h"
#include "decls/data/game/global.h"
void __cdecl FUN_0035dbb0() {
    unsigned long long v = FUN_0027b020(((char*)&DAT_0040048c));
    *(unsigned int*)&v;
    (*(unsigned int*)&DAT_004de758) = (unsigned int)v;
    (*(unsigned int*)&DAT_004de75c) = (unsigned int)(v >> 32);
}
