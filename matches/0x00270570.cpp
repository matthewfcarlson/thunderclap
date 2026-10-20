#include "compat/ptr.h"
extern "C" void* malloc(unsigned);

hulk_uintptr FUN_00270570(int param_1, unsigned param_2) {
    if (param_2 < 4)
        param_2 = 4;
    unsigned total = param_1 + param_2;
    if (total == 0)
        total = 1;
    void* p = malloc(total);
    unsigned rem = (hulk_uintptr)p % param_2;
    hulk_uintptr q = (hulk_uintptr)p - rem + param_2;
    *(hulk_intptr*)(q - 4) = (hulk_intptr)p;
    return q;
}
