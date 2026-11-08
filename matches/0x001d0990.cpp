#include "decls/data/game/global.h"
// data: g_heap = DAT_004c5cfc

extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* FUN_00266e00(int heap, int size);
extern "C" void FUN_00267090(void*);
void* Realloc(int unused, void* p, unsigned oldSize, unsigned newSize) {
    if (newSize == 0) {
        if (p)
            FUN_00267090(p);
        return 0;
    }
    void* n = FUN_00266e00(DAT_004c5cfc, (int)newSize);
    if (!n)
        return 0;
    if (p) {
        if (oldSize > newSize)
            oldSize = newSize;
        memcpy(n, p, oldSize);
        FUN_00267090(p);
    }
    return n;
}
