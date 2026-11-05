#include "decls/data/engine/fight.h"

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
long long FUN_0035f1d0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca28c), 0, 0);
    (*(unsigned int*)&DAT_004e5ba0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5ba4) = (unsigned int)(r >> 32);
    return r;
}
