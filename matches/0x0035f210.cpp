#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca294, gOutput = DAT_004e5b60

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f210() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca294), 0, 0);
    (*(unsigned int*)&DAT_004e5b60) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b64) = (unsigned int)(r >> 32);
}