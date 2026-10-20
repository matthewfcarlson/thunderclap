#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
extern "C" unsigned long long __cdecl FUN_0027b020(hulk_uintptr seed);

unsigned int g_hash_low;
unsigned int g_hash_high;

void FUN_0035de60() {
    unsigned long long h = FUN_0027b020(((hulk_intptr)hulk_at_00400488));
    g_hash_low = (unsigned int)h;
    g_hash_high = (unsigned int)(h >> 32);
}
