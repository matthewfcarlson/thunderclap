#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
// data: PTR_vftable_004ce400 = DAT_004ce400

extern "C" char DAT_0042c1b4[];
extern "C" void __cdecl thunk_FUN_00267090(int);
void FUN_00364790(void) {
    (*(void**)&DAT_004ce400) = (void*)((hulk_intptr)DAT_0042c1b4);
    if (DAT_004ce410)
        thunk_FUN_00267090((hulk_intptr)DAT_004ce410);
}