#include "compat/ptr.h"
#include "gen/owners.h"
int* owners::X_c8190::FUN_000c8190(int i) {
    if (i < 0 || i >= 128)
        return 0;
    int* p = (int*)((char*)this + 0x258 + i * 64);
    return (int*)((hulk_uintptr)p & ((*p == -1) - 1));
}