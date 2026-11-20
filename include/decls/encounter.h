// (recs1, find2 G20) CEncounterGenerator (RTTI .?AVCEncounterGenerator@@, 0xc70 bytes on the 32-bit builds; the
// constructor 0x001fa630, the destructor 0x001fa8b0, the reset 0x001fa040; CTriggerVolumeManager 0x001ff580 builds
// eight) and the records it holds:
// - a pure3d::Entity head (the vftable, the count, the name's two words: 0x14 bytes natively),
// - 256 entries (pointers to objects with a pure3d name: 0x001f85f0 compares it), their count, a title and the
//   script references and state words (ints and chars),
// - 16 tracker slots of 0x28 bytes (ints and a float),
// - 16 CEncounterGenerator::CEncounter objects of 0x58 bytes (0x6e8: a vftable, the owning table, a name, the
//   encounter's key name and flags; 0x001f9710 fills one),
// - the count of encounters and the encounter map (0xc68 / 0xc6c): a red-black tree of HulkEncounterMapNode keyed by
//   the encounter key (0x00230800 .. 0x00231070 walk it), with its node pool (0x002702a0's pool).
// Natively the vftables and pointers are 8 bytes, so the encounters, the map and its nodes move: every view derives
// from these records or pads to them (HULK_ENC_PAD). Only the TUs that use it include this header (D74). Declare no
// namespaces here.
#ifndef HULK_DECLS_ENCOUNTER_H
#define HULK_DECLS_ENCOUNTER_H

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

#include "compat/ptr.h"
#include "decls/tree_map.h"

#ifndef HULK_RANGE   // (as records.h defines it: the values the game stores in an index field; only the 64-bit check sees it)
#if defined(HULK_EQ64_PARSE)
#define HULK_RANGE(lo, hi) __attribute__((annotate("hulk_range " #lo " " #hi)))
#else
#define HULK_RANGE(lo, hi)
#endif
#endif

// The encounter key: a name (pure3d's two-word hash) and two bytes (0x001f92f0 compares them)
struct HulkEncounterKey {
    unsigned int name[2];       // +0x00
    unsigned char a;            // +0x08
    unsigned char b;            // +0x09
    char pad0a[6];              // +0x0a
};

// A node of the encounter map: the tree links, then the key and the value (0x001f9630 reads the value)
struct HulkEncounterMapNode {
    HulkTreeMapLinks links;     // +0x00
    HulkEncounterKey key;       // +0x10
    unsigned short value;       // +0x20
    char pad22[6];              // (0x001f9530 allocates 0x28)
};
HULK_SIZE32(HulkEncounterMapNode, 0x28);

// The encounter map: decls/tree_map.h HulkTreeMap (the pool hands out HulkEncounterMapNode)
typedef HulkTreeMap HulkEncounterMap;

// CEncounterGenerator::CEncounter (vftable 0x00424f04): 0x58 bytes
struct HulkEncounter {
    void* vftable;              // +0x00
    int f04;                    // +0x04
    void* table;                // +0x08 the generator (0x001f9710)
    char name[0x20];            // +0x0c
    int f2c;                    // +0x2c
    HulkEncounterKey key;       // +0x30 the name and the two bytes (b38 / b39)
    int f40, f44, f48, f4c;     // +0x40
    unsigned char b50, b51;     // +0x50
    unsigned short w52;         // +0x52
    int f54;                    // +0x54
};
HULK_SIZE32(HulkEncounter, 0x58);

// A tracker slot (0x28 bytes, 0x001f9130 fills it): the object it tracks (a pointer: 0x001f9810 reads its names), six
// words, the radius (a float: 0x001f8890 takes the largest, 0x001f8aa0 tests against it), a script reference (an int:
// 0x001d1900 releases it, 0x001f8a80 replaces it) and the active flag (0x001fa1c0 / 0x001fa3a0)
struct HulkEncounterSlot {
    void* obj;                  // +0x00
    int w[6];                   // +0x04
    float radius;               // +0x1c
    int tracker;                // +0x20
    unsigned char active;       // +0x24
    char pad25[3];
};

struct HulkEncounterGenerator {
    void* vftable;              // +0x000 pure3d::Entity: the vftable, the count, the name
    int refs;                   // +0x004
    unsigned int entityName[2]; // +0x008
    void* items[256];           // +0x010 the entries (0x001f85f0 reads each one's name at +8)
    int count HULK_RANGE(0, 256);       // +0x410 (0x001f8fe0 / 0x001f8f70 append, at most 256)
    int firstActive;            // +0x414 (0x001f8670)
    int activeCount;            // +0x418
    char title[0x20];           // +0x41c
    int f43c;                   // +0x43c (0x001f8710)
    unsigned char flags440[6];  // +0x440 (0x001f8720 / 0x001f8740)
    short pad446;
    int f448, f44c;             // +0x448 script references (0x001f8760 replaces one; 0x001d1900 releases them)
    unsigned char enabled;      // +0x450
    char pad451[3];
    int f454;                   // +0x454 (0x001f87d0)
    int state;                  // +0x458
    int f45c;                   // +0x45c
    HulkEncounterSlot slots[16];        // +0x460
    int slotCount HULK_RANGE(0, 16);    // +0x6e0 (0x001f93e0 appends below 16)
    int f6e4;                   // +0x6e4
    HulkEncounter encounters[16];       // +0x6e8
    int encounterCount HULK_RANGE(0, 16);   // +0xc68 (0x001fa1c0 appends below 16)
    HulkEncounterMap* map;      // +0xc6c
};
HULK_SIZE32(HulkEncounterGenerator, 0xc70);

// HULK_ENC_PAD(member, k, start): a TU's pad up to the record's member (the 32-bit literal k on the MSVC build, the
// native distance on clang), from `start` (where the pad begins)
#if defined(__clang__)
#define HULK_ENC_PAD(f, k, b) (__builtin_offsetof(HulkEncounterGenerator, f) - (b))
#define HULK_ENC_AT(f, k) (__builtin_offsetof(HulkEncounterGenerator, f))
#else
#define HULK_ENC_PAD(f, k, b) ((k) - (b))
#define HULK_ENC_AT(f, k) (k)
#endif
#if defined(__clang__)
#define HULK_ENCR_PAD(f, k, b) (__builtin_offsetof(HulkEncounter, f) - (b))
#else
#define HULK_ENCR_PAD(f, k, b) ((k) - (b))
#endif

#endif
