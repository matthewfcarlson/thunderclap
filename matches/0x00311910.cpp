#include "compat/ptr.h"
extern "C" void __cdecl FUN_00311740(unsigned int *, int, int, unsigned int);
void __cdecl FUN_00311910(int* first, int* last) {
    hulk_intptr n = last - first;
    hulk_intptr i = n / 2;
    while (i > 0) {
        FUN_00311740((unsigned int *)(int *)first, (hulk_intptr)(--i), (hulk_intptr)n, (int)(first[i]));
    }
}