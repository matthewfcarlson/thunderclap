#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca270, gOutput = DAT_004e5b58

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f0f0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca270), 0, 0);
    (*(unsigned int*)&DAT_004e5b58) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b5c) = (unsigned int)(r >> 32);
}