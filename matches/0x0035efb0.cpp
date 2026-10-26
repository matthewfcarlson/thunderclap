#include "decls/data/engine/fight.h"

extern "C" unsigned long long __cdecl FUN_002672f0(const void* p, int a, int b);

void FUN_0035efb0() {
    unsigned long long r = FUN_002672f0((*(const void**)&DAT_004ca248), 0, 0);
    (*(unsigned int*)&DAT_004e5b68) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b6c) = (unsigned int)(r >> 32);
}
