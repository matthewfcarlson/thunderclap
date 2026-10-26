#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

#include "compat/ptr.h"
extern "C" void* alloc(hulk_uintptr);
extern "C" void init();
int* target() {
    if ((*(int**)&DAT_0052c2c4) == 0) {
        int* p = (int*)alloc(4);
        if (p != 0)
            *p = 0;
        else
            p = 0;
        (*(int**)&DAT_0052c2c4) = p;
        (*(int**)&DAT_0052c2b0) = p;
        init();
    }
    return (*(int**)&DAT_0052c2c4);
}