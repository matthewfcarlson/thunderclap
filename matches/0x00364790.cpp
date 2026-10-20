#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"

extern "C" char DAT_0042c1b4[];
extern "C" void __cdecl thunk_FUN_00267090(int);
extern void* PTR_vftable_004ce400;
void FUN_00364790(void) {
    PTR_vftable_004ce400 = (void*)((hulk_intptr)DAT_0042c1b4);
    if (DAT_004ce410)
        thunk_FUN_00267090(DAT_004ce410);
}