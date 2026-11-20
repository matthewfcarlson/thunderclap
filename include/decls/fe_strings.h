// The front end's string table (gfx1): FEThings' widget (gen FEThings f_2230), 0x120 bytes on the 32-bit builds.
// 0x000ddbf0 allocates it, 0x000f6ef0 constructs it, 0x000f6f60 clears it, 0x000f6ff0 grows its text pool,
// 0x000f7110 resets its counts, 0x000f7220 / 0x000f72c0 / 0x000f7240 look strings and keys up, 0x000f7850 releases its
// items and 0x000f7a80 loads a table file into it. Its pointers are 8 bytes natively: one record for every view (the
// views were 32-bit word arrays and pads).
#ifndef HULK_DECLS_FE_STRINGS_H
#define HULK_DECLS_FE_STRINGS_H

#include "compat/ptr.h"

struct HulkFEStringTable {
    unsigned short* pool;             // +0x00 the UTF-16 text of every string (0x000f6ff0 grows it)
    int poolCapacity;                 // +0x04 in characters
    int used;                         // +0x08
    unsigned short** strings;         // +0x0c each string's start in the pool
    int maxStrings;                   // +0x10
    int count;                        // +0x14 strings loaded
    unsigned long long* hashes;       // +0x18 each string's key
    int maxHashes;                    // +0x1c
    int hashCount;                    // +0x20
    void* items[25];                  // +0x24 reference-counted objects (released by 0x000f6f60 / 0x000f7850)
    int itemCount;                    // +0x88
    char text[0x80];                  // +0x8c (0x000f6ef0 clears its first byte)
    int f10c;                         // +0x10c
    unsigned char f110;               // +0x110
    char pad111[3];
    int f114;                         // +0x114
    int f118;                         // +0x118 1 (DAT_004a1734) after construction
    void* f11c;                       // +0x11c freed by 0x000f6f60
};
#ifndef HULK_SIZE32
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif
HULK_SIZE32(HulkFEStringTable, 0x120);

#endif
