#include "decls/data/game/global.h"
// data: g_hashHi = DAT_004dceec, g_hashLo = DAT_004dcee8

unsigned __int64 FUN_0027b020(const char* s);
void FUN_0035caf0() {
    unsigned long long h = FUN_0027b020("climbing");
    (*(unsigned int*)&DAT_004dcee8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dceec) = (unsigned int)(h >> 32);
}
