#include "compat/ptr.h"
extern "C" unsigned char* FUN_000b09c0(int a, hulk_intptr b);
struct Entry_b09c0 {
    int count;
    hulk_uintptr ptr;
};
extern Entry_b09c0 g_entries[13];
extern unsigned char g_zero_b09c0;
unsigned char* FUN_000b09c0(int a, hulk_intptr b) {
    if (a >= 0 && a < 13 && b >= 0 && b < g_entries[a].count)
        return (unsigned char*)(g_entries[a].ptr + (b << 5));
    return &g_zero_b09c0;
}