// cl-flags: /O2
#include "decls/data/engine/fight.h"
// data: gValue = DAT_004ca298 (a name pointer; the data inventory still types it int), result = DAT_004e5b98

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035f230() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca298), 0, 0);
    (*(unsigned int*)&DAT_004e5b98) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b9c) = (unsigned int)(r >> 32);
}
