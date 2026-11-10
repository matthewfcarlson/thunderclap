#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

#include "compat/ptr.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0027b8f0();
// The platform's start-up counter (DAT_0052c2c4 / DAT_0052c2b0 point at one heap word), created once.
int* FUN_00292410() {
    if ((*(int**)&DAT_0052c2c4) == 0) {
        int* p = (int*)FUN_0008d690(4);
        if (p != 0)
            *p = 0;
        else
            p = 0;
        (*(int**)&DAT_0052c2c4) = p;
        (*(int**)&DAT_0052c2b0) = p;
        FUN_0027b8f0();
    }
    return (*(int**)&DAT_0052c2c4);
}