// (recs1, find2 G13) The front end's callback tables (FEThingsBase's poolA: 0x000f3000 allocates it, 0x000df690 clears
// it, 0x000df700 frees the names): four tables of 64 {name, handler} entries, filled by 0x000df7b0 / 0x000df820 /
// 0x000df890 / 0x000df900 (a copy of the name, 0x000f6610) and searched by 0x000df970 / 0x000df9e0 / 0x000dfa60. The
// name copy and the handler are pointers (8 bytes natively): every view of the tables uses this record, and the
// allocation is sizeof(HulkFECallbacks) (0x800 on the 32-bit builds). Only the TUs that use it include this header
// (D74). Declare no namespaces here.
#ifndef HULK_DECLS_FE_CALLBACKS_H
#define HULK_DECLS_FE_CALLBACKS_H

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

struct HulkFECallback {
    char* name;                 // +0x00 0x000f6610's copy of the name (0: a free entry)
    void* handler;              // +0x04
};
struct HulkFECallbacks {
    HulkFECallback tables[4][64];   // +0x000, +0x200, +0x400, +0x600 (32-bit offsets)
};
HULK_SIZE32(HulkFECallbacks, 0x800);

#endif
