#include "decls/data/engine/fight.h"

typedef unsigned int u32;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f190() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca284), 0, 0);
    (*(unsigned int*)&DAT_004e5b80) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b84) = (unsigned int)(r >> 32);
}
