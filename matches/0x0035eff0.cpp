#include "decls/data/engine/fight.h"

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035eff0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca250), 0, 0);
    (*(unsigned int*)&DAT_004e5b00) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b04) = (unsigned int)(r >> 32);
}