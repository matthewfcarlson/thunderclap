#include "decls/data/game/global.h"

unsigned __int64 FUN_0027b020(const char* s);

void FUN_0035ca70() {
    unsigned long long h = FUN_0027b020("punching");
    (*(unsigned int*)&DAT_004dcef8) = (unsigned int)h;
    (*(unsigned int*)&DAT_004dcefc) = (unsigned int)(h >> 32);
}
