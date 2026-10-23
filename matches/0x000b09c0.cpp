#include "compat/ptr.h"
extern "C" unsigned char* FUN_000b09c0(int a, hulk_intptr b);
struct Entry_b09c0 {
    int count;
    hulk_uintptr ptr;
};
extern Entry_b09c0 DAT_004dda48[13];
extern unsigned char DAT_003f335c;
unsigned char* FUN_000b09c0(int a, hulk_intptr b) {
    if (a >= 0 && a < 13 && b >= 0 && b < DAT_004dda48[a].count)
        return (unsigned char*)(DAT_004dda48[a].ptr + (b << 5));
    return &DAT_003f335c;
}