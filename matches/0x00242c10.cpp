#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl ReleaseThing(void*, int);
void __cdecl FUN_00242c10(int* p) {
    int x = *p;
    *p = 0;
    if (x != 0)
        ReleaseThing((void*)((hulk_intptr)DAT_004e5db0), x);
}