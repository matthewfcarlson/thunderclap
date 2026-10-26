#include "decls/data/game/global.h"
// data: g_hashHi = DAT_004dceec, g_hashLo = DAT_004dcee8

extern "C" unsigned long long __cdecl Hash64(const char*);
void FUN_0035caf0() {
    unsigned long long h = Hash64("climbing");
    (*(unsigned int*)&DAT_004dcee8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dceec) = (unsigned int)(h >> 32);
}
