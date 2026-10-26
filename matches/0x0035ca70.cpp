#include "decls/data/game/global.h"

extern "C" unsigned long long __cdecl GetHash(const char*);

void FUN_0035ca70() {
    unsigned long long h = GetHash("punching");
    (*(unsigned int*)&DAT_004dcef8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dcefc) = (unsigned int)(h >> 32);
}
