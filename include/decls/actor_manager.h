// (gfx3) CActorManager (no RTTI class of its own, no vftable; constructor 0x00025a90, destructor 0x0002b690, 0xd40
// bytes, allocated by the World's set-up 0x00088670 and stored at World+0x20, HulkWorld::parts[7]). The words, from
// every function that holds the manager (build/gfx3 census, 2026-11-21): six pointers (the world 0x000243f0 stores,
// the character template manager and the 0x908-byte object the constructor allocates, the main actor 0x00025e50
// stores, two reference-counted objects 0x00029b50 stores) and otherwise ints, floats, chars and tUIDs, so natively
// only the head and the words after +0x124 / +0x344 move. The ~70 `this` views of its methods (unk_0240b0*.cpp; the
// census: 0x000243f0 stores the world through an `int`, the views pad the two sub-objects as `char pad[8]`) are to be
// converted onto this record together, since a record only some of them use moves the words the others still read; the
// world's handle table is HulkWorld::parts[16] (World+0x44). Only the TUs that use it include this header (D74).
// Declare no namespaces here.
#ifndef HULK_DECLS_ACTOR_MANAGER_H
#define HULK_DECLS_ACTOR_MANAGER_H

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

// A pure3d tUID (two words) the manager keeps by value
struct HulkActorTuid {
    unsigned int lo, hi;
};

// 0x380: 32 entries of 16 bytes (0x00027730 / 0x00027850 / 0x00027930 / 0x00027a50)
struct HulkActorManagerEntry {
    HulkActorTuid id;           // +0x00
    unsigned char flag;         // +0x08
    char pad09[7];
};
HULK_SIZE32(HulkActorManagerEntry, 0x10);

// 0x590: 16 effects of 0x68 bytes (0x00025590 / 0x00025720 / 0x00025750; the destructor walks them)
struct HulkActorManagerEffect {
    float mat[16];              // +0x00
    HulkActorTuid nameA;        // +0x40
    HulkActorTuid nameB;        // +0x48
    int key;                    // +0x50
    unsigned int stamp;         // +0x54
    int f58, f5c;               // +0x58
    float remaining;            // +0x60
    unsigned char fixed;        // +0x64
    char pad65[3];
};
HULK_SIZE32(HulkActorManagerEffect, 0x68);

struct HulkActorManager {
    void* world;                // +0x000 the World (0x000243f0)
    void* templates;            // +0x004 CCharacterTemplateManager (0x00047890)
    void* f008;                 // +0x008 the 0x908-byte object (0x00067ea0)
    int count;                  // +0x00c the handles in ids
    int ids[16];                // +0x010 character handles (0x00059ba0 / 0x00059c10 keys)
    unsigned char enabled;      // +0x050
    char pad051[3];
    int flags[16];              // +0x054
    float score[16];            // +0x094
    int lim1, lim2, lim3;       // +0x0d4 (4, 3, 1)
    int blocked[16];            // +0x0e0
    int f120;                   // +0x120 (nothing reads or writes it)
    void* actor;                // +0x124 the main actor, a CCharacter (0x00025e50)
    char name[0x100];           // +0x128
    HulkActorTuid pairs[32];    // +0x228
    int pairCount;              // +0x328
    int f32c;                   // +0x32c (9)
    float center[3];            // +0x330
    float radius;               // +0x33c (5.0)
    float timer;                // +0x340
    void* ref344;               // +0x344 reference counted (0x00029b50: slot 0 AddRef, slot 1 Release)
    void* ref348;               // +0x348 reference counted
    float f34c;                 // +0x34c
    unsigned char f350, f351, f352, f353;   // +0x350
    float from[3];              // +0x354
    float to[3];                // +0x360
    unsigned char hit;          // +0x36c
    char pad36d[3];
    float hitPoint[3];          // +0x370
    int f37c;                   // +0x37c (nothing reads or writes it)
    HulkActorManagerEntry entries[32];      // +0x380
    int entryCount;             // +0x580
    int f584;                   // +0x584 (0x7fffffff)
    unsigned char f588;         // +0x588
    char pad589[3];
    int effectCount;            // +0x58c
    HulkActorManagerEffect effects[16];     // +0x590
    char names[9][0x20];        // +0xc10
    unsigned int colors[4];     // +0xd30
};
HULK_SIZE32(HulkActorManager, 0xd40);

#endif
