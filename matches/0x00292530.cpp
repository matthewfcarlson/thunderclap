#include "decls/data/engine/unknown.h"
// data: g_obj = DAT_0052c2c4

extern void* __cdecl thunk_FUN_00267090(void*);
extern void __cdecl FUN_0027b1d0();

void FUN_00292530() {
    FUN_0027b1d0();
    if ((*(void**)&DAT_0052c2c4)) {
        thunk_FUN_00267090((*(void**)&DAT_0052c2c4));
    }
    (*(void**)&DAT_0052c2c4) = 0;
}
