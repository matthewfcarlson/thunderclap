#include "decls/data/game/global.h"
// data: hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
extern "C" unsigned long long __cdecl FUN_0027b020(hulk_uintptr seed);

unsigned int g_hash_low;
unsigned int g_hash_high;

void FUN_0035de60() {
    unsigned long long h = FUN_0027b020(((hulk_intptr)((char*)&DAT_00400488)));
    g_hash_low = (unsigned int)h;
    g_hash_high = (unsigned int)(h >> 32);
}
