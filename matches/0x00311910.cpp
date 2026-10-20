#include "compat/ptr.h"
extern "C" void __cdecl FUN_00311740(int*, int, int, int);
void __cdecl FUN_00311910(int* first, int* last) {
    hulk_intptr n = last - first;
    hulk_intptr i = n / 2;
    while (i > 0) {
        FUN_00311740(first, --i, n, first[i]);
    }
}