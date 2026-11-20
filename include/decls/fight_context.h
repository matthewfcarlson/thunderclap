// fight::Context's words (decl1), as its constructor 0x00236840 and destructor 0x002368d0 (src/engine/fight/Context.cpp)
// write them: pure3d::Entity's words (the vftable, the count, the name), the context's object at +0x10 (AddRef'd;
// fight's list links read it as `next`, unk_232780.cpp 0x00232a80), two hash tables (0x00231550 builds each:
// src/engine/fight/unk_2310a0.cpp, whose slot and entry arrays are pointers) and the node 0x0023c620 builds. 0x60 bytes
// on the 32-bit builds (the size every caller allocates); natively the pointers widen the record.
#ifndef HULK_DECLS_FIGHT_CONTEXT_H
#define HULK_DECLS_FIGHT_CONTEXT_H

struct HulkHashTableWords {
    int x0, x4, x8;
    char xc;
    char pad_[3];
    int x10, x14;
    void* slots;
    void* entries;
    int x20;
};

struct HulkFightContext {
    void* vftable;
    int entityWords[3];      // pure3d::Entity: the count and the name's two words (CLAUDE.md)
    void* object;            // +0x10
    HulkHashTableWords tableA;   // +0x14
    HulkHashTableWords tableB;   // +0x38
    void* node;              // +0x5c
};
#define HULK_FIGHT_CONTEXT_SIZE ((int)sizeof(HulkFightContext))

#endif
