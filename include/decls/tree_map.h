// (recs1, find2 G20) The game's red-black tree map (0x00230800 .. 0x00231070: 0x00230b60 sets one up, 0x00230ba0 /
// 0x00230be0 find, 0x00230c30 inserts, 0x00230de0 removes, 0x00230f50 clears): the root, the nil node every leaf link
// points at, the count and the node pool (reference-counted; its slot 3 allocates a node, slot 4 releases one). A node
// starts with the same links. 0x1c bytes on the 32-bit builds; natively the links are pointers and the nil node is
// 8-aligned, so the count sits at +0x28 and the pool at +0x30: every view of a map uses this record. Only the TUs that
// use it include this header (D74). Declare no namespaces here.
#ifndef HULK_DECLS_TREE_MAP_H
#define HULK_DECLS_TREE_MAP_H

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

struct HulkTreeMapLinks {
    void* left;                 // +0x00
    void* right;                // +0x04
    void* parent;               // +0x08
    int color;                  // +0x0c (the low byte)
};
struct HulkTreeMap {
    void* root;                 // +0x00 (&nil when empty)
    HulkTreeMapLinks nil;       // +0x04
    int count;                  // +0x14
    void* pool;                 // +0x18
};
HULK_SIZE32(HulkTreeMap, 0x1c);

#endif
