#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca280 (a name pointer), gResult = DAT_004e5b08

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f170() {
    unsigned __int64 r = FUN_002672f0(DAT_004ca280, 0, 0);
    (*(unsigned int*)&DAT_004e5b08) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b0c) = (unsigned int)(r >> 32);
}
