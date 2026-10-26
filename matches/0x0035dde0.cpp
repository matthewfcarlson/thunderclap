#include "decls/data/game/global.h"
// data: gA_35dde0 = DAT_004de978, gB_35dde0 = DAT_004de97c, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
extern "C" unsigned long long __cdecl Alloc(hulk_uintptr x);
void __cdecl FUN_0035dde0() {
    unsigned long long p = Alloc(((hulk_intptr)((char*)&DAT_0040048c)));
    (*(unsigned int*)&DAT_004de978) = (unsigned int)p;
    (*(unsigned int*)&DAT_004de97c) = (unsigned int)((unsigned long long)p >> 32);
}
