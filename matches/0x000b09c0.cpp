#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
extern "C" unsigned char* FUN_000b09c0(int a, hulk_intptr b);
struct Entry_b09c0 {
    int count;
    hulk_uintptr ptr;
};
unsigned char* FUN_000b09c0(int a, hulk_intptr b) {
    if (a >= 0 && a < 13 && b >= 0 && b < ((Entry_b09c0*)&DAT_004dda48)[a].count)
        return (unsigned char*)(((Entry_b09c0*)&DAT_004dda48)[a].ptr + (b << 5));
    return ((unsigned char*)&DAT_003f335c);
}