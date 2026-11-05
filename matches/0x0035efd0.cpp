#include "decls/data/engine/fight.h"

unsigned __int64 FUN_002672f0(const char* s, int a, int b);

void FUN_0035efd0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca24c), 0, 0);
    (*(unsigned int*)&DAT_004e5b28) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b2c) = (unsigned int)(r >> 32);
}
