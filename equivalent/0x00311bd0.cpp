// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00311bd0 @ 0x00311bd0
#include "compat/ptr.h"
extern "C" void __cdecl FUN_00311740(unsigned int *, int, int, unsigned int);
extern "C" void __cdecl FUN_00311bd0(int* first, int* last) {
    hulk_intptr count = last - first;
    while (count > 1) {
        int value = first[count - 1];
        first[count - 1] = first[0];
        FUN_00311740((unsigned int *)(int *)first, 0, (hulk_intptr)(count - 1), (int)value);
        --count;
    }
}