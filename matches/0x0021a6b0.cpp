#include "compat/ptr.h"
typedef unsigned int uint_21a6b0;
extern "C" void* FUN_0021add0(void* a, void* b, hulk_uintptr c, hulk_uintptr d);
void* FUN_0021a6b0(void* p1, void** p2, hulk_uintptr p3) {
    if (p3 > (hulk_uintptr)p2[2]) {
        if (p3 < 0x20)
            p3 = 0x20;
        p2[0] = FUN_0021add0(p1, p2[0], (hulk_uintptr)p2[2], p3);
        p2[2] = (void*)p3;
    }
    return p2[0];
}