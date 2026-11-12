// content::LoadInventory's words (x64t5), as its constructor 0x00266480 (src/engine/content/LoadInventory.cpp) writes
// them: the vftable, a word, two flags, the hash-table pool (a pointer) and a last word. 0x14 bytes on the 32-bit
// builds (the size every caller allocates), 0x20 natively, where the 0x14-byte block was 0xc short (the canary
// allocator's find in CPlatformManager's set-up 0x0008e880). Callers allocate HULK_LOADINVENTORY_SIZE.
#ifndef HULK_DECLS_LOAD_INVENTORY_H
#define HULK_DECLS_LOAD_INVENTORY_H

struct HulkLoadInventory {
    void* vftable;
    int f04;
    char f08, f09;
    void* pool;
    int f10;
};
#define HULK_LOADINVENTORY_SIZE ((int)sizeof(HulkLoadInventory))

#endif
