#include "compat/ptr.h"
extern "C" void* malloc(unsigned);

extern "C" hulk_uintptr FUN_00270570(int size, unsigned alignment) {
    if (alignment < 4)
        alignment = 4;
    unsigned total = size + alignment;
    if (total == 0)
        total = 1;
    void* p = malloc(total);
    unsigned rem = (hulk_uintptr)p % alignment;
    hulk_uintptr q = (hulk_uintptr)p - rem + alignment;
    *(hulk_intptr*)(q - 4) = (hulk_intptr)p;
    return q;
}
