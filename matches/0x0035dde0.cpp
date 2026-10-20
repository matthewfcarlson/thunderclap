#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
extern "C" unsigned long long __cdecl Alloc(unsigned int x);
extern unsigned int gA_35dde0;
extern unsigned int gB_35dde0;
void __cdecl FUN_0035dde0() {
    unsigned long long p = Alloc(((hulk_intptr)hulk_at_0040048c));
    gA_35dde0 = (unsigned int)p;
    gB_35dde0 = (unsigned int)((unsigned long long)p >> 32);
}
