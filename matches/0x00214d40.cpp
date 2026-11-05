#include "compat/ptr.h"
extern "C" void * __cdecl FUN_00217600(void *, void *);
extern "C" void __cdecl FUN_00214c90(void *, const void *, const char *);
void __cdecl FUN_00214d40(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    char local[8];
    int r = ((int)(hulk_uintptr)FUN_00217600((void *)(hulk_uintptr)(int)b, local));
    int v;
    if (r == 0) {
        v = b;
    } else {
        v = c;
    }
    FUN_00214c90((void *)(hulk_uintptr)(int)a, (const void *)(hulk_uintptr)(int)v, "perform arithmetic on");
}
