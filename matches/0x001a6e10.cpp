#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004a15cc[];
extern int FUN_00344e74(void*, int, void*, void*, int);
void* owners::Owner_1a6e10::FUN_001a6e10() {
    void* p = Get();
    while (p != 0 && FUN_00344e74(p, 0, (void*)((hulk_intptr)DAT_0048d5bc), (void*)((hulk_intptr)DAT_004a15cc), 0) == 0) {
        p = Get();
    }
    return p;
}