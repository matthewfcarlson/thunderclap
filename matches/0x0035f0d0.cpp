#include "decls/data/engine/fight.h"
// data: input = DAT_004ca26c, output = DAT_004e5b90

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void __cdecl FUN_0035f0d0() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca26c), 0, 0);
    (*(unsigned int*)&DAT_004e5b90) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b94) = (unsigned int)(r >> 32);
}
