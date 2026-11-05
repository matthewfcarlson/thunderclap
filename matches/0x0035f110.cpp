#include "decls/data/engine/fight.h"
// data: gLoader = DAT_004ca274, gResult = DAT_004e5b38

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
unsigned __int64 __cdecl FUN_0035f110() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca274), 0, 0);
    (*(unsigned int*)&DAT_004e5b38) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b3c) = (unsigned int)(r >> 32);
    return r;
}
