#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
extern "C" unsigned long long FUN_0027b020(const void*);
extern "C" unsigned long long g_4e0a48;
void FUN_0035e0e0() {
    g_4e0a48 = FUN_0027b020((const void*)((hulk_intptr)hulk_at_00400488));
}
