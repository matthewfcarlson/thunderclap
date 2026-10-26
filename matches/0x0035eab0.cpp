#include "decls/address.h"
#include "decls/data/game/global.h"
// data: g_mass_multiplier_hi = DAT_004e243c, g_mass_multiplier_lo = DAT_004e2438

void __cdecl FUN_0035eab0() {
    unsigned long long result = FUN_0027b020("mass_multiplier");
    (*(unsigned int*)&DAT_004e2438) = (unsigned int)result;
    (*(unsigned int*)((char*)&DAT_004e2438 + 4)) = (unsigned int)(result >> 32);
}
