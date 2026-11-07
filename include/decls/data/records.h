// Record types of data items that several sources index (hand-written, unlike the rest of include/decls/data/).
// tools/data_gen.py defines each item declared here with this declaration (its data TU includes this header) and
// leaves it out of the generated headers, so every source and the data TU see one type: pointer fields are 4 bytes
// on the 32-bit builds (the XBE's layout, which data_gen's size check asserts) and 8 on 64-bit. Only .bss items
// (no initializers). docs/data.md "Typed records". Declare no namespaces or other names here: gen_tree keeps every
// top-level name of include/ global in the tree, so a new one (`namespace core`) changes how TUs are namespaced.
#ifndef HULK_DECLS_DATA_RECORDS_H
#define HULK_DECLS_DATA_RECORDS_H

#include "compat/ptr.h"

// The memory allocator registry (core, 0x00266e00-0x00267280): one slot per heap id; the slots also form a tree
// under the root 0x00527f40 (first child, next sibling, parent), which 0x00266f50 / 0x00266f90 walk to find the
// allocator that owns an address. 0x00267280 points every slot at the static malloc allocator 0x00527f50,
// 0x002670b0 installs an allocator as the first child of a slot (45, or a slot without a parent: the root),
// 0x00267110 unlinks it again. 0x00266e00 / 0x00266eb0 / 0x00266f00 / 0x00266f20 / 0x00266f40 call or return
// the slot's allocator.
struct MemoryHeapSlot {
    void* allocator;                     // a core::IMemoryAllocator (each caller casts it to its view)
    MemoryHeapSlot* child;
    MemoryHeapSlot* next;
    MemoryHeapSlot* parent;
};

extern "C" MemoryHeapSlot DAT_00527c60[46];  // the slots, by heap id
extern "C" MemoryHeapSlot DAT_00527f40;      // the root of the tree

// The dl allocator's heap (core::MemoryDlAllocator, 0x0026b910-0x0026cfa0). Every word of a chunk header and of the
// heap state is pointer-sized, so the 32-bit layout is the XBE's (8-byte headers, 16-byte minimum chunks, 8-byte
// alignment, a 0x474-byte state: the 285 words 0x0026ce90 clears) and the 64-bit one scales with it (16-byte headers
// and alignment, 32-byte minimum chunks). A chunk's size word holds its size | 1 (the previous chunk is in use) | 2
// (not carved from the heap); the user's memory starts after the two header words (kHeader); a free chunk links
// itself into a bin with the next two words.
struct DlHeapChunk {
    enum {
        kWord = sizeof(hulk_uintptr),       // 4 / 8
        kHeader = 2 * sizeof(hulk_uintptr), // header bytes before the user's memory, and the bin links' offset
        kAlign = 2 * sizeof(hulk_uintptr),  // chunk and memory alignment (8 / 16)
        kAlignMask = kAlign - 1,
        kMinSize = 4 * sizeof(hulk_uintptr) // the smallest chunk (16 / 32): a header and two links
    };
    hulk_uintptr previousSize;              // the previous chunk's size, while that chunk is free
    hulk_uintptr size;
    DlHeapChunk* next;
    DlHeapChunk* previous;
};

// The heap state, at +0x1c of the allocator (offsets are the 32-bit ones). 0x0026b910 initializes it, 0x0026b970
// consolidates the fast bins (the game sets no fast-bin size: maxFast is 8, below the minimum chunk), 0x0026c040
// allocates, 0x0026bd80 frees, 0x0026be70 grows the top chunk from the arena, 0x0026bac0 reports.
struct DlHeapState {
    hulk_uintptr maxFast;                   // 0x000 the fast-bin limit | 1 (no fast chunks) | 2 (has chunks)
    DlHeapChunk* fastBins[10];              // 0x004
    DlHeapChunk* top;                       // 0x02c the chunk at the arena's break
    DlHeapChunk* lastRemainder;             // 0x030
    DlHeapChunk* bins[256];                 // 0x034 bin i: a chunk kHeader before bins[2i] (its links bins[2i], bins[2i + 1]); 1 unsorted
    hulk_uintptr binmap[4];                 // 0x434 one bit per bin, 32 bins a word
    hulk_uintptr trimThreshold;             // 0x444
    hulk_uintptr topPad;                    // 0x448 extra bytes asked of the arena
    hulk_uintptr mmapThreshold;             // 0x44c
    hulk_uintptr mmapCount;                 // 0x450
    hulk_uintptr mmapMax;                   // 0x454 0x0026c840 saves and zeroes it around its allocation
    hulk_uintptr mmapPeak;                  // 0x458
    hulk_uintptr pageSize;                  // 0x45c the arena's growth granule
    hulk_uintptr mmappedBytes;              // 0x460
    hulk_uintptr systemBytes;               // 0x464 bytes taken from the arena
    hulk_uintptr systemPeak;                // 0x468
    hulk_uintptr mmappedPeak;               // 0x46c
    hulk_uintptr totalPeak;                 // 0x470
};

// The heap the dl functions work on: the allocator methods (0x0026cc90 / 0x0026cd10 / 0x0026cd90 / 0x0026ce10) set
// these before each call. 0x0052839c is the DlHeapState* and 0x005283ac points at the allocator's break (+0x18):
// both are void* items. 0x005283a4 is the arena size (unsigned int).
extern "C" hulk_uintptr DAT_005283a0;       // the arena start
extern "C" hulk_uintptr DAT_005283a8;       // the arena end: 0x0026be70's limit for the break

// The game's heap set (0x004dd780, built by 0x0008d480 on the first allocation: 0x0008d660 / 0x0008d690 /
// 0x0008d6d0 / 0x0008d710 / 0x0008d750; 0x0008ceb0 returns it). One allocator per heap id of the table 0x00400520
// (19 rows: 0 the malloc allocator, 1 the "Temporary Heap", 3-18 0x0008d3a0's dl heaps), which 0x0035d090 clears
// and 0x0008d0a0 reports; the Temporary Heap's arena (0x20800 bytes of heap 0) at +0x54.
struct HeapSet {
    int size;                               // +0x00 the physical memory in use at start-up (0x0008d480)
    void* heaps[19];                        // +0x04 core::IMemoryAllocator*, by heap id
    void* spare;                            // +0x50 (a 20th slot: no reference)
    void* temporaryArena;                   // +0x54
    void* tail[2];                          // +0x58 (no reference)
};

extern "C" HeapSet DAT_004dd780;

// The thread and fiber records of the core scheduler (0x0026d7a0-0x0026dd70). A thread is on the thread list
// (0x0052a180 first, 0x0052a17c last: 0x0026d8f0 appends, 0x0026d940 unlinks, 0x0026dbb0 finds the caller's by its
// id) and runs fibers: its own (`main`, which 0x0026d990 converts the calling thread to and 0x0026dc50 starts a new
// thread with) and the ones 0x0026dd10 creates, linked from `first` to `last`; `current` is the fiber running
// (0x0026dc00 switches). 0x0052a130 is the main thread's record.
struct CoreThread;
struct CoreFiber {
    int(__cdecl* entry)(hulk_intptr);       // +0x00 (0x0026dc20 runs entry(argument))
    hulk_intptr argument;                   // +0x04 (the content loader's: its object)
    CoreThread* thread;                     // +0x08
    CoreFiber* next;                        // +0x0c
    CoreFiber* previous;                    // +0x10
    void* fiber;                            // +0x14 the XAPI fiber
    int state[3];                           // +0x18
};

struct CoreThread {
    CoreThread* next;                       // +0x00 the thread list
    CoreThread* previous;                   // +0x04
    CoreFiber main;                         // +0x08
    CoreFiber* current;                     // +0x2c
    CoreFiber* first;                       // +0x30
    CoreFiber* last;                        // +0x34
    unsigned char active;                   // +0x38 a thread of its own (0x0026dad0 exits it)
    int result;                             // +0x3c main.entry's result (0x0026db70)
    int priority;                           // +0x40 an index into the priority table 0x004cd9d0
    int threadId;                           // +0x44
    void* handle;                           // +0x48 (the main thread's: -2, the current-thread pseudo handle)
};

extern "C" CoreThread DAT_0052a130;
extern "C" CoreFiber DAT_00527c28;          // the content loader's fiber (0x002656b0 starts it, 0x00264d20 yields to it)
// the content loader's other side (pointer-sized words, read and written through casts): the game's fiber that
// started it (a CoreFiber*), and the current heap (0x00266da0's) kept for each side while the other one runs
extern "C" hulk_uintptr DAT_00527c4c;
extern "C" hulk_uintptr DAT_00527c50;
extern "C" hulk_uintptr DAT_00527c54;

// om::MetaType (0x0025fa00 constructs one, 0x0025fa80 / 0x0025fc30 destroy it) and the red-black tree of meta types
// by name (0x004e79b8; 0x004cd360 points at it). The tree is the om trees' layout: the root, then the sentinel node
// `nil` that every leaf link points at (0x0025e900 / 0x0025e950 rotate, 0x0025f170 inserts, 0x0025f390 removes).
// A meta type is a node of the global tree and keeps a tree of its own (set up empty by the constructor); its key is
// the name (0x0025f170 compares names with strcmp). Static meta types live in .bss: 0x004e6360, 0x004e6394,
// 0x004e63c8, 0x004e63fc, 0x004e6430 (the audio listener effects' types, 0x0035fa20-0x0035faa0).
struct OmTreeNode {
    OmTreeNode* left;                       // +0x00
    OmTreeNode* right;                      // +0x04
    OmTreeNode* parent;                     // +0x08
    int color;                              // +0x0c 1 red, 0 black
};

struct OmTree {
    OmTreeNode* root;                       // +0x00 (nil when empty)
    OmTreeNode nil;                         // +0x04
    int count;                              // +0x14
};

struct OmMetaType {
    const void* vftable;                    // +0x00 om::MetaType's (0x0042aa40)
    OmTreeNode node;                        // +0x04 the node in the tree of meta types
    OmTree children;                        // +0x14 (the constructor leaves count alone)
    const char* name;                       // +0x2c the key
    int flags;                              // +0x30
};

extern "C" OmTree DAT_004e79b8;             // the meta types by name (count: the number constructed)
extern "C" OmMetaType DAT_004e6360;
extern "C" OmMetaType DAT_004e6394;
extern "C" OmMetaType DAT_004e63c8;
extern "C" OmMetaType DAT_004e63fc;
extern "C" OmMetaType DAT_004e6430;

// audio::SeqEventType (0x002605e0 constructs one, 0x00260680 / 0x00260950 destroy it): an om::Type, then its node
// in the tree of sequence event types by name (0x004e7a18, an OmTree; 0x004cd380 points at it; 0x002601d0 inserts,
// 0x002603e0 removes, 0x0025fca0 compares a name with an entry's). om::Type's own fields are kept as its 32-bit
// bytes here (its layout is not recovered), so on 64-bit the node follows them at the next 8-byte boundary.
struct OmString {
    char* data;                             // +0x00 the text (0x0023fc40 sets it, 0x00240060 releases it)
    unsigned short capacity;                // +0x04
    unsigned short pad;                     // +0x06
    unsigned short length;                  // +0x08
};

struct SeqEventTypeHead {
    const void* vftable;                    // +0x00 the derived type's
    unsigned char type[0x44];               // +0x04 the rest of om::Type
    OmTreeNode node;                        // +0x48
    OmString name;                          // +0x58 the key
};

extern "C" OmTree DAT_004e7a18;             // the sequence event types by name (count: the number constructed)

#endif
