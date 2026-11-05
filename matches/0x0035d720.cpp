#include "decls/data/game/global.h"
// data: the hash of "{" = DAT_004ddfb0 (low word) / DAT_004ddfb4 (high word)

unsigned __int64 FUN_0027b020(const char* s);

void FUN_0035d720() {
    unsigned __int64 r = FUN_0027b020("{");
    (*(unsigned int*)&DAT_004ddfb0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004ddfb4) = (unsigned int)(r >> 32);
}
