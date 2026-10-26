#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
// data: count = DAT_0052c288

extern void __cdecl release(void*);
void FUN_0027b1d0() {
    if (--(*(int*)&DAT_0052c288) == 0) {
        if (DAT_004ce410)
            release(DAT_004ce410);
        DAT_004ce410 = 0;
    }
}