#include "compat/ptr.h"
struct Block {
    unsigned size;
    unsigned* next;
};
void __cdecl FUN_00243110(Block* b, unsigned* p, unsigned n) {
    if (!p || !n)
        return;
    unsigned count = n / b->size - 1;
    while (count) {
        *p = (hulk_uintptr)p + b->size;
        p = (unsigned*)*p;
        --count;
    }
    *p = (hulk_uintptr)b->next;
    b->next = p;
}