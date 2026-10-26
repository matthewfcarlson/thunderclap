#include "decls/data/engine/physics.h"

extern "C" void thunk_FUN_00267090(void*);
void FUN_002f2cf0() {
    void* p = (*(void**)&DAT_00554c30);
    if (p)
        thunk_FUN_00267090(p);
    (*(void**)&DAT_00554c30) = 0;
}
