#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
extern "C" unsigned long long __cdecl FUN_0027b020(const void*);
extern unsigned int hashA;
extern unsigned int hashB;

void FUN_0035d4e0() {
    unsigned long long result = FUN_0027b020((const void*)((hulk_intptr)hulk_at_00400488));
    hashA = (unsigned int)result;
    hashB = (unsigned int)(result >> 32);
}
