#include "compat/ptr.h"
extern "C" void* malloc(unsigned);

// aligned allocate: the block malloc returned is kept in the pointer-sized word below the aligned address
extern "C" void* FUN_00270570(int size, unsigned alignment) {
    if (alignment < sizeof(void*))
        alignment = sizeof(void*);
    unsigned total = size + alignment;
    if (total == 0)
        total = 1;
    void* p = malloc(total);
    unsigned rem = (hulk_uintptr)p % alignment;
    hulk_uintptr q = (hulk_uintptr)p - rem + alignment;
    *(void**)(q - sizeof(void*)) = p;
    return (void*)q;
}
