// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002ffe00 @ 0x002ffe00
#include "compat/ptr.h"
extern "C" void __cdecl FUN_002ff860(unsigned int *, int, int, unsigned int);

void __cdecl FUN_002ffe00(int* begin, int* end)
{
    hulk_intptr count = end - begin;
    hulk_intptr half = (count - (count >> 31)) >> 1;
    while (half > 0) {
        int value = begin[half - 1];
        --half;
        FUN_002ff860((unsigned int *)(int *)begin, (hulk_intptr)half, (hulk_intptr)count, (int)value);
    }
}