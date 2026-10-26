#include "decls/address.h"
#include "decls/data/game/global.h"
// data: g4dcec8_1 = DAT_004dcecc
void __cdecl FUN_0035cab0() {
    unsigned long long r = FUN_0027b020("throwing");
    (*(unsigned int*)&DAT_004dcec8) = (unsigned int)r;
    (*(unsigned int*)&DAT_004dcecc) = (unsigned int)(r >> 32);
}