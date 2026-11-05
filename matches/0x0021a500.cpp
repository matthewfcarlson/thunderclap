#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

typedef unsigned int U_21a500;
extern U_21a500 __cdecl FUN_00219e50(U_21a500, U_21a500);
extern "C" int * __cdecl FUN_0021a3e0(void *, void *, void *);
hulk_uintptr __cdecl target(hulk_uintptr a, hulk_uintptr b, hulk_uintptr c) {
    U_21a500 local[2];
    U_21a500 r = FUN_00219e50(b, c);
    if (r == ((hulk_intptr)((char*)&DAT_00426824))) {
        local[1] = c;
        local[0] = 4;
        return ((unsigned int)(hulk_uintptr)FUN_0021a3e0((void *)(hulk_uintptr)(hulk_uintptr)a, (void *)(hulk_uintptr)(unsigned int)b, (unsigned int *)local));
    }
    return r;
}