#include "decls/address.h"
extern "C" unsigned int g_mass_multiplier_lo;
extern "C" unsigned int g_mass_multiplier_hi;

void __cdecl FUN_0035eab0() {
    unsigned long long result = FUN_0027b020("mass_multiplier");
    g_mass_multiplier_lo = (unsigned int)result;
    g_mass_multiplier_hi = (unsigned int)(result >> 32);
}
