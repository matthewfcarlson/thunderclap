// (x64t20, D106) The cursor of fight's 64-bit-keyed hash table (src/engine/fight/unk_2310a0.cpp; the table is a
// content::LoadInventory's pool, decls/load_inventory.h, or one of fight::Context's tables): the table and the index
// of the slot it reached. 0x002314a0 sets the table (index 0), 0x00231640 rewinds (index -1) and returns the first
// item, 0x002314c0 the next (0 past the end), 0x00231530 the current entry's 64-bit key. 8 bytes on the 32-bit builds,
// 0x10 natively: its users kept it as an 8-byte pad or an unsigned word and passed the table as an unsigned word, so
// natively the table pointer was cut to 32 bits (start-up crashed in 0x002314c0). A user's iterator derives from it
// and adds its own words after (the inventory it walks). Only the TUs that iterate the tables include this header (D74).
#ifndef HULK_DECLS_TABLE_CURSOR_H
#define HULK_DECLS_TABLE_CURSOR_H

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

struct HulkTableCursor {
    void* table;
    int index;
};
HULK_SIZE32(HulkTableCursor, 8);

#endif
