#include "decls/address.h"
#include "decls/data/game/global.h"
// data: k_string = DAT_004004a0
extern unsigned int g_result_lo;
extern unsigned int g_result_hi;

void __cdecl FUN_0035e040() {
    unsigned long long r = FUN_0027b020(DAT_004004a0);
    g_result_lo = (unsigned int)r;
    g_result_hi = (unsigned int)(r >> 32);
}
