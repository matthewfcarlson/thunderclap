#include "compat/ptr.h"
extern "C" void __cdecl FUN_002f46a0(unsigned short *, unsigned short *, int);
void wrapper(hulk_intptr a, hulk_intptr b) {
    FUN_002f46a0((unsigned short *)(hulk_uintptr)(int)a, (unsigned short *)(hulk_uintptr)(int)b, (b - a) >> 1);
}