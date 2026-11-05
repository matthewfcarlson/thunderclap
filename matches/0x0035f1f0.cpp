#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca290, gResult = DAT_004e5b78

typedef __int64 I64;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f1f0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca290), 0, 0);
    (*(unsigned int*)&DAT_004e5b78) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b7c) = (unsigned int)(r >> 32);
}