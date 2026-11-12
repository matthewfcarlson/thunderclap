// Record types of data items that several sources index (hand-written, unlike the rest of include/decls/data/).
// tools/data_gen.py defines each item declared here with this declaration (its data TU includes this header) and
// leaves it out of the generated headers, so every source and the data TU see one type: pointer fields are 4 bytes
// on the 32-bit builds (the XBE's layout, which data_gen's size check asserts) and 8 on 64-bit. Only .bss items
// (no initializers). docs/data.md "Typed records". Declare no namespaces or other names here: gen_tree keeps every
// top-level name of include/ global in the tree, so a new one (`namespace core`) changes how TUs are namespaced.
#ifndef HULK_DECLS_DATA_RECORDS_H
#define HULK_DECLS_DATA_RECORDS_H

#include "compat/ptr.h"

// HULK_SIZE32(T, n), at block scope: a compile error on the 32-bit builds unless sizeof(T) is n, the XBE's size
// that a source replaced by sizeof(T) (an allocation or an om type's instance size: docs/native-build.md "Instance
// sizes"); nothing on 64-bit, where the class is larger. It emits no code.
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]

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

// om::Type (0x002584d0 constructs one, 0x002580e0 resets its vftable): an om object type. Types are nodes of the
// red-black tree of types by key (0x004cd1a8, a .data OmTree without a count: om::Type::vfunc_0 0x002588d0 inserts
// with 0x00258530, vfunc_1 0x002588f0 removes with 0x00258730, 0x00258950 finds with 0x00258870); the type's pool
// (0x00247530 / 0x00247550, the allocator 0x004cc200: 0x002474c0) hands out instances of size / align. Many types
// are static .bss objects that the start-up initializers construct (0x0035f300-0x00361700); the leaf types derive
// from om::EntityType (0x00243310, OmEntityType), audio::SeqEventType (0x002605e0, SeqEventTypeHead) or are
// om::TypeT<> instances of om::Type's own size. The body is a record of its own so that the classes that derive from
// om::Type (`virtual ...; unsigned int reserved04; OmTypeBody body;`) have the record's layout on both builds; its
// keys are word pairs (an __int64 member would make MSVC align the vftable pointer's slot to 8).
struct OmKey {
    unsigned int lo;                        // 0x002672f0's 64-bit hash of a name
    unsigned int hi;
};

struct OmTypeBody {
    OmTreeNode node;                        // +0x08 the node in the tree of types (its key is `key`)
    unsigned int reserved18[4];             // +0x18 (no reference found)
    OmKey baseKey;                          // +0x28 the key of the type's data kind ("Data_Mix")
    OmKey key;                              // +0x30 the type's own key ("Mix"), the tree's key
    int size;                               // +0x38 an instance's bytes (0x002474c0 allocates them)
    int align;                              // +0x3c
    unsigned int reserved40[2];             // +0x40
};

struct OmType {
    const void* vftable;                    // +0x00 om::Type's (0x0042a6ac) or the derived type's
    unsigned int reserved04;                // +0x04 (no reference found)
    OmTypeBody body;                        // +0x08
};

// om::EntityType (0x00243310; om::MetaEntityType 0x0025e6c0 adds nothing): om::Type, then the entity flags. The
// static objects are 8-aligned (their .bss items keep the 4 bytes after the class).
struct __declspec(align(8)) OmEntityType {
    OmType type;
    unsigned int reserved48[8];             // +0x48 (no reference found)
    int flags;                              // +0x68 (0x01000002 audio::MixType, 0x01000100 the listener effects)
};

// audio::SeqEventType (0x002605e0 constructs one, 0x00260680 / 0x00260950 destroy it): an om::Type, then its node
// in the tree of sequence event types by name (0x004e7a18, an OmTree; 0x004cd380 points at it; 0x002601d0 inserts,
// 0x002603e0 removes, 0x0025fca0 compares a name with an entry's).
struct OmString {
    char* data;                             // +0x00 the text (0x0023fc40 sets it, 0x00240060 releases it)
    unsigned short capacity;                // +0x04
    unsigned short pad;                     // +0x06
    unsigned short length;                  // +0x08
};

struct __declspec(align(8)) SeqEventTypeHead {  // (8-aligned as OmEntityType)
    OmType type;                            // +0x00 (the derived type's vftable)
    OmTreeNode node;                        // +0x48
    OmString name;                          // +0x58 the key
};

extern "C" OmTree DAT_004e7a18;             // the sequence event types by name (count: the number constructed)

// The static om types of the audio start-up (initializers 0x0035f300-0x00361700 construct them, the exit handlers
// 0x00364150-0x00364760 destroy them; their pools hand out the instances). The .bss items that held several of them
// are one item per object here (an id word 0x002673a0 returns, then 4 bytes of padding, before three of them).
extern "C" OmEntityType DAT_004e5cf8[1];
extern "C" OmType DAT_004e5d68[1];
extern "C" OmType DAT_004e5df8[1];
extern "C" OmType DAT_004e5e40[1];
extern "C" OmType DAT_004e5ff0[1];
extern "C" OmType DAT_004e6038[1];
extern "C" OmType DAT_004e6110[1];
extern "C" OmType DAT_004e6158[1];
extern "C" OmType DAT_004e6208[1];
extern "C" OmType DAT_004e6250[1];
extern "C" SeqEventTypeHead DAT_004e6750[1];
extern "C" OmType DAT_004e6800[1];
extern "C" SeqEventTypeHead DAT_004e6848[1];
extern "C" SeqEventTypeHead DAT_004e68f8[1];
extern "C" OmType DAT_004e6960[1];
extern "C" SeqEventTypeHead DAT_004e6a68[1];
extern "C" SeqEventTypeHead DAT_004e6bc8[1];
extern "C" OmType DAT_004e6c30[1];
extern "C" SeqEventTypeHead DAT_004e6c78[1];
extern "C" SeqEventTypeHead DAT_004e6d30[1];
extern "C" OmType DAT_004e6de0[1];
extern "C" SeqEventTypeHead DAT_004e6e28[1];
extern "C" SeqEventTypeHead DAT_004e6ed8[1];
extern "C" OmType DAT_004e6f40[1];
extern "C" OmType DAT_004e6ff0[1];
extern "C" SeqEventTypeHead DAT_004e7038[1];
extern "C" SeqEventTypeHead DAT_004e70e8[1];
extern "C" OmType DAT_004e7150[1];
extern "C" SeqEventTypeHead DAT_004e7200[1];
extern "C" OmType DAT_004e7268[1];
extern "C" SeqEventTypeHead DAT_004e72f8[1];
extern "C" OmType DAT_004e7360[1];
extern "C" OmType DAT_004e7410[1];
extern "C" SeqEventTypeHead DAT_004e7458[1];
extern "C" SeqEventTypeHead DAT_004e7508[1];
extern "C" OmType DAT_004e7570[1];
extern "C" SeqEventTypeHead DAT_004e75b8[1];
extern "C" OmEntityType DAT_004e7620[1];
extern "C" OmType DAT_004e76e8[1];
extern "C" OmType DAT_004e7730[1];
extern "C" OmType DAT_004e7778[1];
extern "C" OmType DAT_004e7808[1];
extern "C" OmType DAT_004e7850[1];
extern "C" OmType DAT_004e78e0[1];
extern "C" OmType DAT_004e7928[1];
extern "C" OmType DAT_004e7970[1];
extern "C" OmType DAT_004e7b08[1];
extern "C" OmType DAT_004e7b50[1];
extern "C" OmType DAT_004e7be0[1];
// (the types that have an item of their own)
extern "C" OmType DAT_004e5db0[1];
extern "C" OmType DAT_004e5e88[1];
extern "C" OmEntityType DAT_004e5f18[1];
extern "C" OmType DAT_004e5fa8[1];
extern "C" OmType DAT_004e6080[1];
extern "C" OmType DAT_004e60c8[1];
extern "C" OmType DAT_004e61a0[1];
extern "C" OmType DAT_004e62d8[1];
extern "C" OmEntityType DAT_004e6468[1];
extern "C" OmEntityType DAT_004e64d8[1];
extern "C" OmEntityType DAT_004e6548[1];
extern "C" OmEntityType DAT_004e65b8[1];
extern "C" OmEntityType DAT_004e6628[1];
extern "C" SeqEventTypeHead DAT_004e6698[1];
extern "C" OmType DAT_004e6700[1];
extern "C" OmType DAT_004e67b8[1];
extern "C" OmType DAT_004e68b0[1];
extern "C" SeqEventTypeHead DAT_004e69b0[1];
extern "C" OmType DAT_004e6a18[1];
extern "C" OmType DAT_004e6ad0[1];
extern "C" SeqEventTypeHead DAT_004e6b18[1];
extern "C" OmType DAT_004e6b80[1];
extern "C" OmType DAT_004e6ce0[1];
extern "C" OmType DAT_004e6d98[1];
extern "C" OmType DAT_004e6e90[1];
extern "C" SeqEventTypeHead DAT_004e6f88[1];
extern "C" OmType DAT_004e70a0[1];
extern "C" SeqEventTypeHead DAT_004e7198[1];
extern "C" OmType DAT_004e72b0[1];
extern "C" SeqEventTypeHead DAT_004e73a8[1];
extern "C" OmType DAT_004e74c0[1];
extern "C" OmType DAT_004e7690[1];
extern "C" OmType DAT_004e77c0[1];
extern "C" OmType DAT_004e7898[1];
extern "C" OmType DAT_004e79d0[1];
extern "C" OmType DAT_004e7a30[1];
extern "C" OmType DAT_004e7a78[1];
extern "C" OmType DAT_004e7ac0[1];
extern "C" OmType DAT_004e7b98[1];

// ---- Instance records (reg5): the classes whose instances the om types' pools hand out (the types pass
// sizeof / __alignof of these as the instance size and alignment: docs/native-build.md "Instance sizes").

// audio::SeqEvent (vftable 0x0042aa60, 6 slots; 0x0025fd00 constructs, 0x0025fd10 destroys): the head of every
// sequence event. The events of a container are an intrusive singly linked list through `link` (the list points
// at an event's +0x04, and the walkers subtract 4: 0x002607c0 appends, 0x00260840 / 0x00260910 walk it).
// The audio::SeqEvent* instance records below are what the types' pools (audio::SeqEventType 0x002605e0's
// size / align) hand out; `name` hashes are 0x002673a0's 32-bit hash of a layer name ("stitched").
struct AudioSeqEventLink {
    AudioSeqEventLink* next;                // the next event's link (0 at the end)
};

struct AudioSeqEvent {
    const void* vftable;                    // +0x00 the event class's vftable
    AudioSeqEventLink link;                 // +0x04 0x002607c0 stores it, 0x00260910 follows it
};

// audio::SeqEventContainer (vftable 0x00429b1c): an event with child events. 0x002607c0 reads the children
// (count, then appends each at `last`), 0x00260840 / 0x00260910 walk them from `first`.
struct AudioSeqEventContainer {
    AudioSeqEvent event;                    // +0x00
    unsigned int count;                     // +0x08 0x002607c0 increments it
    AudioSeqEventLink* first;               // +0x0c 0x002607c0 / 0x00260840
    AudioSeqEventLink* last;                // +0x10 0x002607c0 appends after it
};

// audio::SeqEventNestTrack (0x0024e6f0 constructs, 0x0024e730 destroys): the nested track's name.
struct AudioSeqEventNestTrack {
    AudioSeqEvent event;                    // +0x00
    OmString trackName;                     // +0x08 0x0024e6f0 sets it (0x0023fc40), 0x0024e730 releases it
};

// audio::SeqEventChannelSendVolumes (0x0024f540 constructs).
struct AudioSeqEventChannelSendVolumes {
    AudioSeqEvent event;                    // +0x00
    unsigned char sendVolumes[64];          // +0x08 0x0024f4a0 reads 64 bytes, 0x0024f540 zeroes them
    unsigned int fadeTime;                  // +0x48 "mFadeTime" (0x0024f600 reads, 0x0024f540 sets 100)
    int layerName;                          // +0x4c hash of the layer name (0x0024f540, 0x0024f6a0 looks it up)
};

// audio::SeqEventChannelSends (0x0024fa90 constructs).
struct AudioSeqEventChannelSends {
    AudioSeqEvent event;                    // +0x00
    unsigned int sends[64];                 // +0x08 0x0025c7c0 reads 64 words, 0x0024fa90 zeroes them
    int layerName;                          // +0x108 hash of "mLayerName" (0x0024fb30 reads, 0x0024fa90 sets)
};

// audio::SeqEventCondition (0x00250030 constructs, 0x0024fee0 destroys): a container and an expression.
struct AudioSeqEventCondition {
    AudioSeqEventContainer container;       // +0x00
    OmString expression;                    // +0x14 "mExpression" (0x0024fc60 reads, 0x0024fee0 releases)
};

// audio::SeqEventWait (0x00250310 constructs, 0x00250350 destroys).
struct AudioSeqEventWait {
    AudioSeqEvent event;                    // +0x00
    OmString expression;                    // +0x08 "mExpression" (0x00250110 reads, 0x00250380 writes)
};

// audio::SeqEventExpression (0x00250ba0 constructs, 0x00250be0 destroys).
struct AudioSeqEventExpression {
    AudioSeqEvent event;                    // +0x00
    OmString expression;                    // +0x08 0x002509f0 reads, 0x00250c10 writes, 0x00250be0 releases
};

// audio::SeqEventPlayTrack (0x00251590 constructs, 0x002515e0 destroys).
struct AudioSeqEventPlayTrack {
    AudioSeqEvent event;                    // +0x00
    unsigned int fadeTimeMs;                // +0x08 "mFadeTimeMs" (0x00251400, 0x00251610)
    unsigned int delayTimeMs;               // +0x0c "mDelayTimeMs"
    unsigned char targetResume;             // +0x10 "mTargetResume" (byte store in 0x00251590, 0x0025aa80 reads)
    unsigned char pad11[3];                 // +0x11
    OmString seqTrackName;                  // +0x14 "mSeqTrackNameBuf" (0x00251590 sets "MySeqTrack")
};

// audio::SeqEventChannelVolumes (0x00252070 constructs).
struct AudioSeqEventChannelVolumes {
    AudioSeqEvent event;                    // +0x00
    unsigned char volumes[16];              // +0x08 0x00252030 reads 16 bytes, 0x00252070 zeroes them
    unsigned int fadeTime;                  // +0x18 "mFadeTime" (0x00252130 reads, 0x00252070 sets 1000)
    int layerName;                          // +0x1c hash of the layer name (0x00252070, 0x00252130)
};

// audio::SeqEventVarVolumeRand (0x00252560 constructs).
struct AudioSeqEventVarVolumeRand {
    AudioSeqEvent event;                    // +0x00
    float minVolume;                        // +0x08 "mMinVolume" (0x00252560 sets 0.5)
    float maxVolume;                        // +0x0c "mMaxVolume" (1.0)
};

// audio::SeqEventVarVolume (0x00252930 constructs).
struct AudioSeqEventVarVolume {
    AudioSeqEvent event;                    // +0x00
    float volume;                           // +0x08 0x002527d0 reads, 0x00252930 sets 1.0
};

// audio::SeqEventVarTempo (0x00252d80 constructs).
struct AudioSeqEventVarTempo {
    AudioSeqEvent event;                    // +0x00
    unsigned int timeSignature[2];          // +0x08 "mTimeSignature" (0x00261a80 reads both, 0x00252d80 sets 4/4)
    float tempo;                            // +0x10 "mTempo" (0x00252d80 sets 120.0)
};

// audio::SeqEventVarPosDist (0x002531a0 constructs).
struct AudioSeqEventVarPosDist {
    AudioSeqEvent event;                    // +0x00
    float distance[2];                      // +0x08 0x0025c000 reads both, 0x002531a0 sets 1.0 / 100.0
};

// audio::SeqEventVarPitchRand (0x00253530 constructs).
struct AudioSeqEventVarPitchRand {
    AudioSeqEvent event;                    // +0x00
    float minPitch;                         // +0x08 "mMinPitch" (0x00253530 sets 0.8)
    float maxPitch;                         // +0x0c "mMaxPitch" (1.2)
};

// An RSD stream file reference of audio::SeqEventStream / audio::SeqEventClip (0x00253a90 sets the key from the
// file name, 0x0025cda0 reads the rest). The key is a 64-bit value (0x002672f0), which makes the events 8-aligned
// (their types pass align 8); a word pair here with the alignment explicit, as OmKey elsewhere.
struct __declspec(align(8)) AudioSeqStreamFile {
    OmKey key;                              // +0x00 0x00253a90 stores 0x002672f0's hash of "MyRsdFile"
    unsigned char flags;                    // +0x08 bit 0 enabled (0x0025cda0, 0x00254520 clears it)
    unsigned char pad09[3];                 // +0x09
    unsigned int idBits;                    // +0x0c low 31 bits an id (0x0025cda0; 0x00254520 keeps bit 31)
    unsigned int range[2];                  // +0x10 0x0025c490 reads both, 0x00254520 zeroes the first
};

// audio::SeqEventStream (0x00254520 constructs).
struct AudioSeqEventStream {
    AudioSeqEvent event;                    // +0x00
    AudioSeqStreamFile file;                // +0x08 0x00253c70 reads it (0x0025cda0), 0x00254190 writes it
};

// audio::SeqEventSilence (0x002547e0 constructs).
struct AudioSeqEventSilence {
    AudioSeqEvent event;                    // +0x00
    unsigned int minTimeMs;                 // +0x08 "mMinTimeMs" (0x002547e0 sets 500, 0x002549a0 reads)
    unsigned int maxTimeMs;                 // +0x0c "mMaxTimeMs" (1000)
};

// audio::SeqEventLogicRepeat (0x00254d80 constructs): a container repeated min..max times.
struct AudioSeqEventLogicRepeat {
    AudioSeqEventContainer container;       // +0x00
    unsigned int minTimes;                  // +0x14 "mMinTimes" (0x00254a80 reads, 0x00254d80 sets 1)
    unsigned int maxTimes;                  // +0x18 "mMaxTimes" (1)
};

// audio::SeqEventLogicOr (0x00255350 constructs).
struct AudioSeqEventLogicOr {
    AudioSeqEventContainer container;       // +0x00
    float spread;                           // +0x14 "mSpread" (0x00254e80 reads, 0x00255350 sets 0.5)
};

// The beat set of audio::SeqEventCrossFade: a list of pool items {unsigned int beat; AudioSeqEventLink link}
// (0x00261ef0 reads and appends them from the pool 0x004e7a30, 0x00261d10 frees them).
struct AudioSeqBeatSet {
    AudioSeqEventLink* head;                // +0x00 0x00261ef0 / 0x00261d10
    AudioSeqEventLink* tail;                // +0x04 0x00261ef0 appends after it
};

// audio::SeqEventCrossFade (0x00255690 constructs, 0x002556f0 destroys).
struct AudioSeqEventCrossFade {
    AudioSeqEvent event;                    // +0x00
    unsigned int fadeInStartMs;             // +0x08 "mFadeInStartMs" (0x00255870 reads, 0x00255690 sets 0)
    unsigned int fadeInMs;                  // +0x0c "mFadeInMs" (1000)
    unsigned int fadeOutStartMs;            // +0x10 "mFadeOutStartMs" (0)
    unsigned int fadeOutMs;                 // +0x14 "mFadeOutMs" (1000)
    unsigned char targetResume;             // +0x18 "mTargetResume" (byte stores in 0x00255690)
    unsigned char isSynchronous;            // +0x19 "mIsSynchronous"
    unsigned char pad1a[2];                 // +0x1a
    OmString seqTrackName;                  // +0x1c "mSeqTrackName" (0x00255690 sets, 0x002556f0 releases)
    int beatLayerName;                      // +0x28 hash of "mBeatLayerNameBuf" (0x00255690 sets "stitched")
    AudioSeqBeatSet beatSet;                // +0x2c "mBeatSet" (0x00261ef0 reads, 0x002556f0 frees it)
};

// audio::SeqEventClip (0x002562c0 constructs).
struct AudioSeqEventClip {
    AudioSeqEvent event;                    // +0x00
    unsigned char isLooping;                // +0x08 "mIsLooping" (0x00255d30 reads a byte, 0x002562c0 clears it)
    unsigned char pad09[7];                 // +0x09 (the file is 8-aligned)
    AudioSeqStreamFile rsdFile;             // +0x10 "mRsdFile" (0x00255d30 reads it with 0x0025cda0)
};

// core::Drive's file-system drives and their worker thread (reg5 g4). Offsets are the 32-bit ones; the XBE sizes
// are the literals the allocation sites pass to 0x00266e00 (0x1e4 XboxDrive, 0x910 XboxSaveDrive, 0x94 DriveThread).
// Handles of the XDK (semaphores, find and file handles) are hulk_uintptr: the platform shims return them
// pointer-sized (src/platform/sdl/xdk/imports.h), the game compares them with -1.

// core::Drive's list of cement libraries (the member at +0x14 of a drive; 0x00277a40 constructs it, 0x00277540
// releases every library on it). Libraries are linked through their +0x64 word, by the bucket in their +0x68 word:
// 0x00277570 appends, 0x002775b0 unlinks, 0x002775f0 / 0x00277600 iterate. The shared buffer (0x00277630 allocates
// it on the first use with 0x00266eb0, 0x00277670 frees it with the last) is what 0x00272bc0 returns.
struct CoreDriveLibraryList {
    void* heads[2];                         // +0x00 core::CementLibrary*, by bucket
    void* tails[2];                         // +0x08
    void* cursor;                           // +0x10 (0x002775f0 sets it to heads[i], 0x00277600 advances it)
    void* buffer;                           // +0x14 0x00266eb0's result (0x00277630), freed with 0x00266f20 (0x002776c0)
    unsigned int size;                      // +0x18 the buffer's size (0x0026fd50's result)
    int refs;                               // +0x1c users of the buffer
    int heap;                               // +0x20 the heap id the buffer came from
};

// The label: a pointer to a constant name (0x0026f570, drive D:), the name in place ("Xbox Hard Disk", 0x0026f570)
// or the memory unit's name (0x00278b50 converts 0x41 bytes into it; 0x00278500 clears its first byte).
union CoreDriveLabel {
    const char* text;                       // +0x00
    char buffer[0x44];                      // +0x00 (0x41 bytes written, then 3 unused)
};

// core::Drive (0x00272d00 constructs it, 0x00272840 / 0x00272d90 destroy it; vftables 0x0042b884 / +4 0x0042b87c /
// +0xc 0x0042b86c). Bases IRefCount (+0), Object/BaseObject (+4: the heap id), SafeRefCount/IMutable (+0xc: the
// reference count). 0x00272880-0x00272b80 are its accessors (each under the IMutable lock at +0xc).
struct CoreDrive {
    const void* vftable;                    // +0x00 core::IRefCount / core::Drive
    const void* vftableObject;              // +0x04 core::BaseObject
    int heap;                               // +0x08 the heap id (DAT_004cdbb0 at construction; restored by the destructor)
    const void* vftableMutable;             // +0x0c core::SafeRefCount / core::IMutable
    int refs;                               // +0x10 (1 at construction; 0x0026f130 increments under the lock)
    CoreDriveLibraryList libraries;         // +0x14 (0x00277a40, 0x00277540, 0x00272ba0 / 0x00272bb0 / 0x00272bc0)
    void* requests;                         // +0x38 the pending request list (vfunc_3 0x00272df0 walks it, next at +4; 0x002728e0 appends)
    void* lastRequest;                      // +0x3c (0x002728e0, 0x00272df0)
    int state;                              // +0x40 (0x00272920 / 0x00272990 set 2, 0x002729c0 clears; 0x00272a20 reads)
    hulk_uintptr* signal;                   // +0x44 a semaphore handle's address: 0x00272aa0 releases *signal with 0x0026d8a0
    void* thread;                           // +0x48 a CoreThread*: 0x00272920 stores 0x0026dbb0's result; vfunc_3 compares it
    void* callback;                         // +0x4c a callback object: vfunc_3 calls its slot 0 (0x00272920 sets it)
    unsigned int argument;                  // +0x50 passed to the request's slot 5 (vfunc_3; 0x00272920 sets it)
    unsigned char active;                   // +0x54 (0x00272aa0 sets 1, 0x00272a40 clears; 0x00272a80 reads)
    char pad55[3];                          // +0x55
    void* request;                          // +0x58 the completed request: 0x00272aa0 stores the thread's item, vfunc_3 / 0x00272ae0 call its slots 5/6
    unsigned char flag5c;                   // +0x5c (1 at construction; 0x00272b50 returns it)
    unsigned char busy;                     // +0x5d vfunc_3's re-entry guard
    char pad5e[2];                          // +0x5e
    unsigned int result;                    // +0x60 (0x00278b50 / XboxSaveDrive::vfunc_7; 0x0026f570 clears; 0x002728d0 returns its address)
    unsigned int size;                      // +0x64 the medium's size (0x0026f290, 0x00278b50)
    unsigned int count;                     // +0x68 size / sectorSize
    unsigned int sectorSize;                // +0x6c (0x200 by default)
    CoreDriveLabel label;                   // +0x70
    int error;                              // +0xb4 the last error (3 at construction; every XboxDrive / XboxSaveDrive operation sets it; 0x00272880 reads)
    void* driveThread;                      // +0xb8 the CoreDriveThread (0x0026f570 / 0x00278500; 0x00272b60 / 0x00272b70 / 0x00272b80 call through it)
};

// core::DriveThread (0x002733c0 constructs it; vftables 0x0042b8f8 / +4 0x0042b8f0 / +0xc 0x0042b8e0): the worker
// that runs a drive's requests (0x002731d0 is its thread's entry). Each drive class shares one per device
// (DAT_00528408 / DAT_0052840c for XboxDrive, DAT_0052c26c for XboxSaveDrive), allocated with 0x94 bytes.
struct CoreDriveThread {
    const void* vftable;                    // +0x00 core::IRefCount / core::DriveThread
    const void* vftableObject;              // +0x04 core::BaseObject
    int heap;                               // +0x08 the heap id
    const void* vftableMutable;             // +0x0c core::SafeRefCount / core::IMutable
    int refs;                               // +0x10 (1; 0x00272f70)
    void* lock;                             // +0x14 the device's critical section (DAT_005283e8 ...): 0x00272fa0 / 0x00272fb0 enter / leave it
    CoreThread worker;                      // +0x18 started by 0x0026dce0 (entry 0x002731d0, this, priority 4, 0x2000 stack)
    unsigned char stopped;                  // +0x64 the entry's loop condition (0x00272f00 sets 1)
    char pad65[3];                          // +0x65
    hulk_uintptr ready;                     // +0x68 a semaphore (0x0026d860 creates it, 0x0026d890 waits, 0x0026d8a0 releases)
    void* heads[3];                         // +0x6c the request queues, by priority (0x00273140 pops, 0x00272fc0 / 0x002731d0 push)
    void* tails[3];                         // +0x78
    hulk_uintptr done;                      // +0x84 a semaphore (0x0026d860; 0x002731d0 waits on it)
    unsigned char requeue;                  // +0x88 (0x00273120 sets it)
    char pad89[3];                          // +0x89
    int count;                              // +0x8c queued requests (0x00272fc0, 0x002730c0, 0x002731d0)
    unsigned int unknown90;                 // +0x90 (0 at construction; no other reference found)
};

// One of an XboxSaveDrive's four save-game enumeration slots (vfunc_18 0x00279220 opens one, vfunc_19 0x002793b0
// reads the next entry, 0x00278300 / vfunc_20 0x00278700 close it).
struct CoreXboxSaveDriveSlot {
    char path[0x204];                       // +0x000 the search path (0x00279220 copies 0x202 bytes into it)
    hulk_uintptr handle;                    // +0x204 the find handle (0x003564c0's result; -1 closed, 0x00356611 closes it)
};

// core::XboxDrive (0x0026f570 constructs it; vftables 0x0042b52c / +4 0x0042b524 / +0xc 0x0042b514). 0x0026fcf0
// allocates 0x1e4 bytes.
struct CoreXboxDrive {
    CoreDrive drive;                        // +0x000
    unsigned int type;                      // +0x0bc 0x22 D:, 0x3b Z:, 0x20 W:, 0x33 other (vfunc_6 0x0026f1b0 returns it)
    int openFiles;                          // +0x0c0 (vfunc_10 0x0026f1d0 decrements it)
    char name[0x11];                        // +0x0c4 the drive's name (0x0026f570 copies 16 bytes and ends it; vfunc_4 0x0026f1c0 returns it)
    char pathBuffer[0x103];                 // +0x0d5 the source directory (vfunc_21 0x0026f210 fills it)
    char* path;                             // +0x1d8 into pathBuffer (vfunc_21; 0x0026f330 prefixes names with it)
    int pathLength;                         // +0x1dc
    void* lock;                             // +0x1e0 the device's critical section (DAT_005283e8 / DAT_005283cc): 0x0026f190 / 0x0026f1a0
};

// core::XboxSaveDrive (0x00278500 constructs it; vftables 0x0042c064 / +4 0x0042c058 / +0xc 0x0042c048 /
// +0xbc 0x0042c038 / +0xc0 0x0042c028). 0x00278a40 allocates 0x910 bytes.
struct CoreXboxSaveDrive {
    CoreDrive drive;                        // +0x000
    const void* vftableReader;              // +0x0bc core::SignedReader
    const void* vftableWriter;              // +0x0c0 core::SignedWriter
    unsigned int type;                      // +0x0c4 0xc3 (the memory unit name of DAT_004004f8) or 0xc7 (vfunc_6 0x00278260)
    int openFiles;                          // +0x0c8 (vfunc_10 0x00278280 decrements; 0x002788c0 / vfunc_7 read)
    char name[16];                          // +0x0cc the drive's name (vfunc_4 0x00278270 returns it; bytes +0xd3 / +0xd4 the port digit and slot letter)
    unsigned char terminator;               // +0x0dc
    unsigned char mounted;                  // +0x0dd (0x002788c0 sets 1, 0x00278410 clears)
    unsigned char driveLetter;              // +0x0de ('U' the hard disk; 0x00279220 builds paths from it)
    char padDF;                             // +0x0df
    hulk_uintptr files[4];                  // +0x0e0 open file handles (-1 free; vfunc_11 0x00279af0)
    CoreXboxSaveDriveSlot slots[4];         // +0x0f0 (handles at +0x2f4 + i * 0x208)
};

// ---- audio HAL instance records (the Runtime_Hal / Transient om types, initializers 0x0035f870-0x00361630) ----

// HalRsdFileHeader: the 0x1a4-byte on-disk header of an .rsd stream. audio::HalRsdFileStream::vfunc_11 0x00263330
// allocates one from the type's pool, zeroes 0x69 words and reads 0x1a4 bytes from the file into it; the
// OmHalStream constructor 0x0025cbc0 reads one into its own +0x10. 0x00263480 reads +0x04..+0x10 (the format),
// OmHalStream::vfunc_9 0x0025c2b0 hands out 16-byte entries at +0xa4. On-disk data: stays 32-bit, no pointers.
struct AudioHalRsdFileHeader {
    unsigned int words[0x69];               // +0x000 file bytes (0x00263330 reads 0x1a4 bytes)
};

// audio::OmHalStream (vftable 0x0042a850, 13 slots; 0x0025cbc0 constructs, 0x0025cc70 / vfunc_12 0x0025ce80
// destroy): a HalStream over an om content stream. The gen class's 0x1b8 is only the matched prefix: the name
// string at +0x1bc (0x0025cc70 / 0x0025ce80 release it, vfunc_10 0x0025c080 reads it) ends at 0x1c8.
struct AudioOmHalStream {
    const void* vftable;                    // +0x000 0x0042a850
    void* source;                           // +0x004 content stream: vfunc_5 0x0025c2e0 calls its vftable,
                                            //        vfunc_6/7 read through it (0x00246f00)
    unsigned int remaining;                 // +0x008 bytes left (0x0025cbc0, vfunc_8 0x0025c280 subtracts)
    unsigned int format;                    // +0x00c 0x00263480 fills it; vfunc_2 returns its address,
                                            //        vfunc_3 0x0025c310 decodes it
    AudioHalRsdFileHeader header;           // +0x010 0x0025cbc0 reads 0x1a4 bytes into it
    unsigned int pending;                   // +0x1b4 vfunc_6/7 store the count, vfunc_8 returns it
    void (*wait)();                         // +0x1b8 vfunc_6 0x0025c190 calls it while a job runs
    OmString name;                          // +0x1bc 0x0025cbc0 sets it (0x00240190), 0x0025cc70 releases it
};

// HalBuffer (0x0025d340 allocates and constructs, 0x0025d300 / 0x0025d2d0 destroy): a sample buffer in the
// audio device's list of buffers (0x00257e80 appends to DAT_004e5ce0+0x14, 0x00257f00 unlinks). HalVoice's
// `buffer` (+0x60) and HalStreamPlayer's `buffer` (+0x0c) point at one.
struct AudioHalBuffer {
    AudioHalBuffer* next;                   // +0x00 0x00257e80 / 0x00257f00
    AudioHalBuffer* prev;                   // +0x04
    unsigned char flag;                     // +0x08 0x0025d340
    unsigned char pad09[3];
    unsigned int bytes;                     // +0x0c the size 0x0025d340 allocates (0x0025d040 reads it)
    void* data;                             // +0x10 0x00240c20's allocation (XMemAlloc); 0x00240c60 frees it,
                                            //       0x00259610 reads samples from it
    unsigned int format;                    // +0x14 packed format word (0x00259610 / 0x00259b40 decode it)
    unsigned int reserved18;                // +0x18 0x0025d340 zeroes it
    OmString name;                          // +0x1c 0x0023fac0 constructs it, 0x00240060 releases it
};

// The DirectSound mix bins of a voice channel: the count and a pointer to the (bin, volume) pairs, the shape
// DSBUFFERDESC's mix-bin member points at (0x00259610 passes &count to IDirectSound_CreateSoundBuffer).
struct AudioHalMixBinPair {
    unsigned int bin;                       // +0x00 0x00259610
    int volume;                             // +0x04 0x00259610 zeroes it
};

// HalVoiceChannel (0x00259610 allocates and fills one per channel, 0x00259b40 frees them).
struct AudioHalVoiceChannel {
    unsigned int types[4];                  // +0x00 0x00259610
    float volumes[4];                       // +0x10 0x00259610 sets 1.0
    float volume;                           // +0x20 0x00259610 sets 1.0
    unsigned int mixBinCount;               // +0x24 0x00259610 (its address goes to CreateSoundBuffer)
    AudioHalMixBinPair* mixBins;            // +0x28 0x00259610 points it at `pairs`
    AudioHalMixBinPair pairs[6];            // +0x2c 0x00259610
    void* mapping[7];                       // +0x5c 0x00259610 stores &DAT_004e76d8 or &pairs[n]
    void* context;                          // +0x78 0x00259610 stores its argument
    void* soundBuffer;                      // +0x7c IDirectSoundBuffer (0x00259610 creates, 0x00259b40 releases)
};

// HalPositionalInfo: the 3D parameters of a voice. 0x0024c810 initialises all 25 words to float constants
// (1.0, 360.0, 20.0, 120.0, 0.01 and zeros); no word holds an address.
struct AudioHalPositionalInfo {
    float values[25];                       // +0x00 0x0024c810
};

// HalVoice (0x00259610 allocates and constructs, 0x00259b40 destroys): a voice in the audio device's list
// (0x00257e80 appends to DAT_004e5ce0+0x1c, 0x00257f00 unlinks).
struct AudioHalVoice {
    AudioHalVoice* next;                    // +0x00 0x00257e80 / 0x00257f00
    AudioHalVoice* prev;                    // +0x04
    unsigned int reserved08;                // +0x08 0x00259610 sets 0
    unsigned int reserved0c;                // +0x0c 0x00259610 sets 5
    float gain[2];                          // +0x10 0x00259610 sets 1.0
    unsigned int state;                     // +0x18 0x00259610
    unsigned char enabled;                  // +0x1c 0x00259610
    unsigned char pad1d[3];
    AudioHalVoiceChannel* channels[16];     // +0x20 0x00259610 allocates, 0x00259b40 frees
    AudioHalBuffer* buffer;                 // +0x60 0x00259610's third argument; 0x00259b40 reads +0x14
    AudioHalPositionalInfo* positional[8];  // +0x64 0x00259610 allocates (0x0024c740 pool), 0x00259b40 frees
    void (*callback)();                     // +0x84 0x00259610 stores 0x0024d140
};

// CircBuf::GarbageRegion (0x0025e450 allocates one, 0x0025e350 / 0x0025e230 free them): a region of a circular
// buffer still in use. The CircBuf's list links the regions through `link` (head/tail point at a region's +0x08;
// the walkers subtract 8).
struct AudioCircBufLink {
    AudioCircBufLink* next;                 // 0x0025e230 / 0x0025e350 follow it
};

struct AudioCircBufGarbageRegion {
    unsigned int start;                     // +0x00 0x0025e450
    unsigned int length;                    // +0x04 0x0025e450; 0x0025e2b0 sums them
    AudioCircBufLink link;                  // +0x08 0x0025e450 appends it
};

// CircBuf (0x0025e550 initialises one, 0x0025e290 resets it, 0x0025e280 / 0x0025e230 drop its regions): the
// ring a stream player reads into. Positions are offsets from `base`.
struct AudioCircBuf {
    hulk_uintptr base;                      // +0x00 0x0025e550's first argument; 0x0024b920 / 0x0024b550 add a
                                            //       position to it and pass the result on as an address
    unsigned int capacity;                  // +0x04 0x0025e550; 0x0025e0b0 / 0x0025e450 wrap at it
    unsigned int chunk;                     // +0x08 0x0025e550; 0x0024b920 passes it to the sink's write
    float threshold;                        // +0x0c 0x0025e550 sets 0.5 (0x0024b550 scales the capacity)
    unsigned char full;                     // +0x10 0x0025e0b0 / 0x0025e450
    unsigned char pad11[3];
    unsigned int writePos;                  // +0x14 0x0025e0b0 / 0x0025e450 advance it
    unsigned int readPos;                   // +0x18 0x0025e350 advances it
    unsigned int readCount;                 // +0x1c 0x0025e0b0
    unsigned int writeCount;                // +0x20 0x0025e0b0
    unsigned int wraps;                     // +0x24 0x0025e0b0 / 0x0025e350 / 0x0025e450
    AudioCircBufLink* head;                 // +0x28 the first region's link (0x0025e230, 0x0025e310)
    AudioCircBufLink* tail;                 // +0x2c the last region's link (0x0025e450 appends after it)
};

// One queued write of a stream player (0x0024ba70 pushes one, 0x0024bae0 pops and releases them).
struct AudioHalStreamSlot {
    void* sink;                             // +0x00 an object with a vftable (0x0024b920 / 0x0024bae0 call it)
    unsigned int size;                      // +0x04 0x0024ba70
    unsigned int total;                     // +0x08 0x0024ba70 (the running total before the push)
};

// HalStreamPlayer (0x0024be00 allocates and constructs, 0x0024bf90 destroys): a streamed sound in the list at
// DAT_004e61e8 (first) / DAT_004e61ec (last).
struct AudioHalStreamPlayer {
    AudioHalStreamPlayer* next;             // +0x00 0x0024be00 / 0x0024bf90 / 0x0024c060 walks it
    AudioHalStreamPlayer* prev;             // +0x04
    AudioHalVoice* voice;                   // +0x08 0x00259610's result (0x0024bf90 frees it with 0x00259b40)
    AudioHalBuffer* buffer;                 // +0x0c 0x0025d340's result (0x0024bf90 frees it with 0x0025d300)
    AudioCircBuf* ring;                     // +0x10 from the CircBuf pool (0x0025e070); 0x0024b170 / 0x0024b920
    AudioCircBuf* ring2;                    // +0x14 a second one when 0x0024be00's fifth argument is set
    unsigned int stats[10];                 // +0x18 times and counters (0x0024b550 / 0x0024b920 store them)
    AudioHalStreamSlot slots[10];           // +0x40 ring of queued writes (0x0024ba70, 0x0024b2d0, 0x0024b310)
    unsigned char slotHead;                 // +0xb8
    unsigned char slotCount;                // +0xb9
    unsigned char slotCapacity;             // +0xba 0x0024be00 sets 10
    unsigned char padbb;
    unsigned int slotTotal;                 // +0xbc 0x0024ba70 / 0x0024bae0
    int mode;                               // +0xc0 0x0024c090 / 0x0024b550
    int state;                              // +0xc4 0x0024bc70 and its callers
    int started;                            // +0xc8 0x0024b920
    unsigned int position;                  // +0xcc 0x0024b550
    unsigned int pendingBytes;              // +0xd0 0x0024b920
    void* job;                              // +0xd4 0x002703c0's result (0x0024b550 calls its vftable)
};

// ---- om meta records ----

// om::MetaTypeAttribBase (vftable 0x00429420; 0x0025fba0 constructs): a named attribute of a meta type, a node of
// the meta type's tree of attributes (0x0025f450 inserts it into the OmMetaType's `children` by name).
struct OmMetaTypeAttribBase {
    const void* vftable;                    // +0x00
    OmTreeNode node;                        // +0x04 0x0025f450
    int offset;                             // +0x14 the member's offset (0x0025fba0; vfunc_3 0x0024ddf0 adds it)
    const char* name;                       // +0x18 the tree key (0x0025fba0: "mHalListenerEffect.room")
};

// om::MetaTypeAttribScalar<int> / <float> (vftables 0x00429610 / 0x0042962c; constructed in place by 0x0024df00):
// the scalar attributes of the listener effects. The gen classes' 44 is only the proven prefix: `limit` at +0x2c
// (vfunc_5 0x0024dde0 returns it) makes 0x30.
struct OmMetaTypeAttribScalarInt {
    OmMetaTypeAttribBase base;              // +0x00
    int minimum;                            // +0x1c 0x0024df00
    int defaultValue;                       // +0x20 0x0024df00
    int current;                            // +0x24 0x0024df00; vfunc_3 0x0024ddf0 stores it into the object
    const char* label;                      // +0x28 "Room" (vfunc_4 0x0024ddd0 returns it)
    const void* limit;                      // +0x2c &DAT_003f335c (vfunc_5 0x0024dde0 returns it)
};

struct OmMetaTypeAttribScalarFloat {
    OmMetaTypeAttribBase base;              // +0x00
    float minimum;                          // +0x1c 0x0024df00
    float defaultValue;                     // +0x20 0x0024df00
    float current;                          // +0x24 0x0024df00; vfunc_3 0x0024de70 stores it into the object
    const char* label;                      // +0x28 (vfunc_4 returns it)
    const void* limit;                      // +0x2c (vfunc_5 returns it)
};

// om::DynAttr (vftable 0x0042aac8) / om::DynAttrT<om::String> (vftable 0x0042aadc; 0x00261120 constructs one
// in place, 0x00260e60 destroys it): a dynamic attribute, a node of a registry's red-black tree keyed by an id
// (0x00260f10 inserts `node`, comparing the word after it).
struct OmDynAttr {
    const void* vftable;                    // +0x00
    OmTreeNode node;                        // +0x04 0x00260f10
    unsigned int key;                       // +0x14 0x00261120 stores *key; 0x00260f10 compares it
};

struct OmDynAttrString {
    OmDynAttr attr;                         // +0x00
    OmString value;                         // +0x18 0x00261120 sets it (0x00240190), 0x00260e60 releases it
};

// Property (0x0025b7d0 / 0x0025b850 remove one from its tree with 0x0025b5b0, release its 12 strings and free
// it): a node of a red-black tree of properties, then twelve strings.
struct OmMetaProperty {
    OmTreeNode node;                        // +0x00 0x0025b5b0 unlinks it
    OmString strings[12];                   // +0x10 0x0025b850 releases them (0x00240060)
};

// ---- reg5 group g1: the audio mixer, sequence player and entity instance records ----
// Uses OmTreeNode, OmKey (records.h). Offsets are the 32-bit ones.

// A red-black tree whose nil node doubles as the end marker, without OmTree's separate count (the nil node's
// color word is what the constructors zero; 0x00242bd0, 0x0024a5d0, 0x0024a510, 0x00257980, 0x0025df40 set
// root = left = right = parent = &nil). Inserts: 0x002422e0, 0x00242a00, 0x00249ce0, 0x00249ff0, 0x00257780.
struct AudioTree {
    OmTreeNode* root;                       // +0x00 (&nil when empty)
    OmTreeNode nil;                         // +0x04
};

// A doubly linked list link and its head (0x00257e80 appends, 0x00257f00 removes, 0x00256d40 / 0x00242ec0 walk).
struct AudioLink {
    AudioLink* next;                        // +0x00
    AudioLink* prev;                        // +0x04
};

struct AudioList {
    AudioLink* first;                       // +0x00
    AudioLink* last;                        // +0x04
};

// A singly linked list link (the queues 0x0025dba0 / 0x0025dc20 / 0x0025dc60 and the beat lists 0x00261ef0 /
// 0x00261d10 link items through it; owners subtract 4 to get the item).
struct AudioSlistLink {
    AudioSlistLink* next;                   // +0x00
};

// om::Entity (0x00244ea0 constructs, 0x00245270 destroys; vftable 0x00429158): the head of every entity. The
// classes that derive from it keep their own fields from +0x28 (audio::Mix 0x0025a2c0, audio::Clip 0x00245640,
// audio::Sequence 0x00257980 all leave +0x24 to the base).
struct OmEntity {
    const void* vftable;                    // +0x00 0x00244ea0 stores 0x00429158; derived ctors their own
    OmTreeNode node;                        // +0x04 the node in the entity index (*0x004cc08c; 0x002448b0 inserts
                                            //       &entity->node, 0x00244b20 removes it)
    unsigned int reserved14;                // +0x14 (no reference found)
    OmKey key;                              // +0x18 0x002672f0 hash ("MyEntity"); 0x002448b0 compares it
    unsigned short flags20;                 // +0x20 0x00244ea0 zeroes it
    unsigned short refs;                    // +0x22 0x00244ea0 zeroes it; 0x0024a5d0 increments a Sequence's,
                                            //       0x0024ad20 decrements it
    unsigned int reserved24;                // +0x24 (inside the base's 0x24 bytes of 0x0025a2c0 / 0x00245720)
};

// audio::Mix (0x0025a2c0 constructs, 0x0025a8c0 destroys; vftable 0x0042a6e4). Entity type audio::MixType (the
// .bss object 0x004e5cf8; 0x00242070 allocates). Alignment 8 is the entity types' (OmKey is a 64-bit key at an
// 8-aligned offset; the record keeps word pairs, so its own alignment is 4 and the literal stays the align).
struct AudioMix {
    OmEntity entity;                        // +0x00
    AudioList mixerMixes;                   // +0x28 0x00257dd0 inits; 0x00242c30 appends AudioMixerMix.mixLink
    int value30;                            // +0x30 0x0025a2c0: 1000
    int value34;                            // +0x34 0x0025a2c0: 1000
    AudioTree busses;                       // +0x38 the mix's MixBuss entries (0x00242da0 walks; 0x0025a220 clears)
    unsigned int reserved4c;                // +0x4c (no reference found)
};

// audio::Clip (0x00245640 / 0x00245720 construct, 0x00245340 destroys; vftable 0x0042918c).
struct AudioClip {
    OmEntity entity;                        // +0x00
    void* data;                             // +0x28 0x00245390's result (0x00245680 / 0x00245720); 0x00245340
                                            //       frees it with 0x0025d300
    unsigned int reserved2c;                // +0x2c (no reference found)
};

// audio::Sequence (0x00257980 constructs, 0x002579f0 / 0x00257c90 destroy; vftable 0x0042a640). The layout of
// gen audio::Sequence, with its ints at +0x38/+0x54 being the trees' nil colors and +0x3c/+0x40 a list head.
struct AudioSequence {
    OmEntity entity;                        // +0x00
    AudioTree channels;                     // +0x28 0x00257980 sets it empty; 0x00257b00 / 0x00257c90 reset root
                                            //       (gen f_28..f_38); 0x00257250 / 0x00257270 iterate entries keyed at
                                            //       +0x10 (0x0024a5d0 hands those keys to 0x00242ce0)
    AudioList tracks;                       // +0x3c the tracks (item link at +0x14; 0x00256d40 frees them, 0x0024a5d0
                                            //       walks `first`) (gen f_3c, f_40)
    AudioTree busses;                       // +0x44 the AudioSeqBuss nodes (0x00257b30 inserts with 0x00257780,
                                            //       0x00257730 frees them) (gen f_44..f_54)
};

// audio::Mixer (0x00242bd0 creates one from the pool 0x004e5db0, 0x00242c10 releases it; the global 0x004e5cac).
struct AudioMixer {
    AudioTree busses;                       // +0x00 AudioMixerBuss by key (0x00242ce0 finds or inserts)
    AudioTree mixes;                        // +0x14 AudioMixerMix by Mix* (0x00242c30 inserts with 0x002422e0,
                                            //       0x00242ca0 removes, 0x00242f90 walks)
    unsigned int reserved28[2];             // +0x28 (no reference found)
};

// A mix applied to a mixer (0x00242c30 creates one from the pool 0x004e5df8, 0x00242ca0 releases it).
struct AudioMixerMix {
    OmTreeNode node;                        // +0x00 in AudioMixer.mixes (0x002422e0, key `mix`)
    AudioLink mixLink;                      // +0x10 in AudioMix.mixerMixes (0x00242c30 0x00257e80, 0x00242ca0 0x00257f00)
    AudioSlistLink* firstFader;             // +0x18 AudioMixerFader.groupLink list (0x00242da0 appends, 0x00242ec0 frees)
    AudioSlistLink* lastFader;              // +0x1c
    struct AudioMix* mix;                   // +0x20 the tree key; 0x00242c30 appends at mix+0x28, 0x00242da0 walks
                                            //       mix+0x38
    AudioMixer* mixer;                      // +0x24 0x00242c30 inserts into mixer+0x14
    float duration;                         // +0x28 0x00242f60 sets it; 0x00242f90 reads it
    float progress;                         // +0x2c 0x00242f90 ramps it; 0x00242860 reads it
    float gain;                             // +0x30 0x00242c30: 1.0f; 0x00242860 reads it
    int state;                              // +0x34 0..3 (0x00242f60, 0x00242f90)
};

// A mixer buss (0x00242ce0 finds or creates one from the pool 0x004e5e88; 0x00242d70 / 0x00242ec0 release it).
struct AudioMixerBuss {
    OmTreeNode node;                        // +0x00 in AudioMixer.busses (0x00242a00)
    AudioLink* firstFader;                  // +0x10 AudioMixerFader.bussLink list (0x00242da0, 0x00242ec0)
    AudioLink* lastFader;                   // +0x14
    unsigned int key;                       // +0x18 a buss name hash (an entry's key, 0x00242ce0 compares unsigned)
    unsigned int refs;                      // +0x1c 0x00242ce0 / 0x00242d70 / 0x00242ec0
    float volume20;                         // +0x20 0x00242ce0: 1.0f; 0x00242860 writes the products
    float volume24;                         // +0x24 0x00242ce0: 1.0f
};

// One binding of a mix's buss to a mixer buss (0x00242da0 creates them from the pool 0x004e5e40, 0x00242ec0 frees).
struct AudioMixerFader {
    AudioLink groupLink;                    // +0x00 in AudioMixerMix.firstFader (0x00242ec0 follows next)
    AudioLink bussLink;                     // +0x08 in AudioMixerBuss.firstFader
    void* entry;                            // +0x10 the Mix's buss entry (0x00242860 reads +0x18/+0x1c/+0x28 of it)
    AudioMixerMix* mixerMix;                // +0x14 0x00242da0; 0x00242860 reads +0x2c / +0x30
    AudioMixerBuss* buss;                   // +0x18 0x00242da0; 0x00242ec0 releases it
};

// audio::StreamPlayerAllocator (vftable 0x00424ac0; 0x00247ba0 / 0x00247bd0 are its slots): embedded in a player.
struct AudioStreamPlayerAllocator {
    const void* vftable;                    // +0x00 0x0024a5d0 stores 0x00424ac0
    unsigned char flags;                    // +0x04 0x0024a5d0 clears bits 0-1; 0x002478d0 / 0x002478f0 / 0x00247900
    unsigned char pad05[3];
};

// A sequence player (0x0024ace0 allocates from the pool 0x004e5fa8 and constructs with 0x0024a5d0; 0x0024ad20
// destroys, 0x0024ae50 / 0x0024af00 free).
struct AudioSeqPlayer {
    AudioLink link;                         // +0x00 in the players list 0x004e5f98 (0x0024a5d0 0x00257e80,
                                            //       0x0024ad20 0x00257f00)
    float volume08;                         // +0x08 1.0f; 0x00247890 sets it
    float volume0c;                         // +0x0c 1.0f; 0x002478b0 sets it
    float value10;                          // +0x10 1.0f
    float value14;                          // +0x14 1.0f
    AudioTree tracks;                       // +0x18 AudioSeqPlayerTrack nodes (0x00249ce0 inserts, 0x0024ad20 frees)
    void* sequence;                         // +0x2c the Sequence (0x0024a5d0 increments its refs; 0x00247810 returns it)
    int state;                              // +0x30 0x00247950 / 0x00247970
    float value34;                          // +0x34 1.0f
    int fadeTime;                           // +0x38 0x00247950 / 0x00247970
    struct AudioSeqPlayerBuss* firstBuss;   // +0x3c 0x0024a5d0 appends, 0x0024ad20 frees
    struct AudioSeqPlayerBuss* lastBuss;    // +0x40
    AudioMixer* mixer;                      // +0x44 0x0024a5d0 passes it to 0x00242ce0; 0x0024ad20 to 0x00242d70
    AudioTree layers;                       // +0x48 AudioSeqPlayerLayer nodes (0x0024a940 / 0x0024a9c0, 0x0024ad20)
    AudioTree tree5c;                       // +0x5c virtual items at +4 (0x0024a4a0 frees; 0x0024a800 0x0024a280)
    AudioTree tree70;                       // +0x70 virtual items at +4 (0x0024a450 frees)
    void* param84;                          // +0x84 0x0024a5d0's 2nd argument (0x001f32b0 passes 0x004e58b8)
    unsigned int param88;                   // +0x88 0x0024a5d0's 1st argument (a manager's +0x518, 0x001f32b0)
    int param8c;                            // +0x8c 0x0024a5d0's 5th argument (0x001f32b0 passes 3000)
    float position[3];                      // +0x90 0x002485c0 copies 3 words (from a matrix row, 0x001f5860)
    float velocity[3];                      // +0x9c 0x002485c0 copies 3 words
    float valueA8;                          // +0xa8 1.0f; 0x002485c0 stores its last argument
    AudioStreamPlayerAllocator* allocator;  // +0xac the 6th argument or &ownAllocator; 0x00247a20 calls it
    AudioStreamPlayerAllocator ownAllocator; // +0xb0
};

// A track of a sequence player (0x0024a5d0 creates them from the pool 0x004e5ff0, 0x0024ad20 frees them).
struct AudioSeqPlayerTrack {
    OmTreeNode node;                        // +0x00 in AudioSeqPlayer.tracks (0x00249ce0, keyed by track->+0x38)
    struct AudioSeqPlayerTrackChannel* firstChannel; // +0x10 0x0024a9c0 pushes, 0x00249750 unlinks
    struct AudioSeqPlayerTrackChannel* lastChannel;  // +0x14
    int channelCount;                       // +0x18 0x0024a9c0 / 0x00249750
    void* track;                            // +0x1c the sequence's track (0x0024a5d0; 0x0024a9c0 reads +0x3c/+0x40)
};

// A playing channel of a track (0x0024a9c0 creates them from the pool 0x004e6038, 0x00249750 frees them).
struct AudioSeqPlayerTrackChannel {
    struct AudioSeqPlayerTrackChannel* next; // +0x00 AudioSeqPlayerTrack's list (0x0024a9c0, 0x00249750)
    AudioSeqPlayerTrack* owner;             // +0x04
    struct AudioSeqTrackPlayer* player;     // +0x08 0x0024a9c0 (0x0025df40); 0x00249750 frees; 0x0024a3c0 calls it
    int state;                              // +0x0c 0x0024a3c0's switch; 0x00247a90 / 0x00247ae0 / 0x00247b30 set it
    unsigned char flag10;                   // +0x10 0x00247ae0 stores a char; 0x00249810 reads a byte
    unsigned char pad11[3];
    int value14;                            // +0x14 0x00247ae0
    int beat18[2];                          // +0x18 a pair copied by 0x00247a90 / 0x00247ae0 / 0x00247b30
    int value20;                            // +0x20 0x00248670 / 0x00248780
    float fade;                             // +0x24 0x00248670 / 0x00248780 ramp it
    int value28;                            // +0x28 0x00248670 / 0x00248780
    unsigned int reserved2c;                // +0x2c (no reference found)
    struct AudioSeqPlayerLayer* layer;      // +0x30 0x0024a9c0; 0x00249810 / 0x00248670 read it
    AudioLink layerLink;                    // +0x34 in AudioSeqPlayerLayer.firstChannel (0x0024a9c0, 0x00249750)
    short state3c;                          // +0x3c 0x0024a9c0 zeroes it; 0x0024a800 reads it
    unsigned short pad3e;
};

// A buss reference of a sequence player (0x0024a5d0 creates them from the pool 0x004e6080, 0x0024ad20 frees).
struct AudioSeqPlayerBuss {
    struct AudioSeqPlayerBuss* next;        // +0x00
    AudioMixerBuss* buss;                   // +0x04 0x00242ce0's result; 0x0024ad20 releases it with 0x00242d70
};

// A layer of a sequence player (0x0024a9c0 / 0x0024a940 create them from the pool 0x004e60c8 and construct with
// 0x0024a510; 0x0024a590 / 0x0024a7a0 destroy).
struct AudioSeqPlayerLayer {
    OmTreeNode node;                        // +0x00 in AudioSeqPlayer.layers (0x00249ff0)
    unsigned int key;                       // +0x10 the layer name hash (0x002673a0; 0x0024a940 compares)
    float scale14;                          // +0x14 1.0f
    float* scaleA;                          // +0x18 0x0024a510: &0x004cc22c
    float* scaleB;                          // +0x1c &0x004cc228
    float scale20;                          // +0x20 1.0f
    float scale24;                          // +0x24 1.0f
    float* limit;                           // +0x28 &0x004cc230
    int value2c;                            // +0x2c 0
    int* mode;                              // +0x30 &0x004cc234
    int* counter;                           // +0x34 &0x004e5fa0
    float* rate;                            // +0x38 &0x004cc23c
    struct AudioChannelVolumeArray* volumes;          // +0x3c 0x00251ad0 allocates; 0x0024a590 frees
    struct AudioChannelSendVolumeArray* sendVolumes;  // +0x40 0x0024f6a0 allocates; 0x0024a590 frees
    int value44;                            // +0x44 0
    AudioLink* firstChannel;                // +0x48 AudioSeqPlayerTrackChannel.layerLink (0x0024a9c0)
    AudioLink* lastChannel;                 // +0x4c
    AudioTree behaviours50;                 // +0x50 virtual items at +4 (0x0024a4a0 frees)
    AudioTree behaviours64;                 // +0x64 virtual items at +4 (0x0024a450 frees)
};

// The 16 channel volumes of a layer (0x00251ad0 allocates from the pool 0x004e6110 and sets 1.0f).
struct AudioChannelVolumeArray {
    float volumes[16];                      // +0x00
};

// The 64 channel send volumes of a layer (0x0024f6a0 allocates from the pool 0x004e6158 and sets 1.0f).
struct AudioChannelSendVolumeArray {
    float volumes[64];                      // +0x00
};

// audio::SeqActionWaitBeat (vftable 0x00429c3c; 0x002508c0 creates it from the pool 0x004e6a18, 0x00250770 frees).
struct AudioSeqActionWaitBeat {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20 links item+4)
    void* event;                            // +0x08 the SeqEventWaitBeat (0x002508c0; 0x002505b0 reads +0x10 of it,
                                            //       0x00250560 passes +8 of it to 0x00261f90)
    int state;                              // +0x0c 0x002505b0 / 0x002505f0 / 0x00250600 / 0x00250610 / 0x00250620
    int previousBeat;                       // +0x10 0x002505b0 / 0x00250560
    void* source;                           // +0x14 0x0024a390's result (0x002505b0); 0x00250560 reads +0x2c of it
};

// audio::SeqCommandLogicRepeat (vftable 0x0042a400; 0x00254dd0 allocates from the pool 0x004e7360 and constructs
// with 0x00254c80; 0x00254ce0 frees).
struct AudioSeqCommandLogicRepeat {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the command queue (0x0025dba0 links item+4)
    void* event;                            // +0x08 the SeqEventLogicRepeat (0x00254c80; 0x00254d10 reads +0x0c)
    unsigned int count;                     // +0x0c 0x00254c80 zeroes it; 0x00254d10 increments it
    unsigned int limit;                     // +0x10 FUN_000113e0's random count or -1 (0x00254c80, 0x00254d10)
    void* current;                          // +0x14 the current child command (its link at +4; 0x00254c80, 0x00254d10)
};

// A buss of a sequence (0x00257b30 creates them from the pool 0x004e7690, 0x00257730 frees them).
struct AudioSeqBuss {
    OmTreeNode node;                        // +0x00 in AudioSequence.busses (0x00257780)
    unsigned int name;                      // +0x10 0x002673a0's hash of the buss name (0x00257b30)
};

// The player of one track channel (0x0024a9c0 allocates from the pool 0x004e78e0 (0x0025d3d0 returns it) and
// constructs with 0x0025df40; 0x0025def0 destroys).
struct AudioSeqTrackPlayer {
    float scale;                            // +0x00 1.0f
    struct AudioSeqPlayerLayer* layer;      // +0x04 0x0025df40's 1st argument; 0x0025d7f0 reads +4 of it
    AudioTree tree08;                       // +0x08 virtual items at +4 (0x0024a4a0 frees)
    AudioTree tree1c;                       // +0x1c virtual items at +4 (0x0024a450 frees)
    void* track;                            // +0x30 0x0025df40's 2nd argument (the track; 0x0024a9c0 passes y->z)
    void* voice;                            // +0x34 a stream voice (0x0024afe0 takes it; 0x0025d3f0 / 0x0025d7f0)
    int value38;                            // +0x38 0
    struct AudioSeqPlayer* seqPlayer;       // +0x3c 0x0025df40's 3rd argument
    AudioSlistLink* firstAction;            // +0x40 the action queue (0x0025dc20 appends; 0x0025dcb0 frees)
    AudioSlistLink* lastAction;             // +0x44
    int actionCount;                        // +0x48 0x0025dc20
    AudioSlistLink* firstCommand;           // +0x4c the command queue (0x0025dba0, 0x0025dbd0, 0x0025db30, 0x0025dc60)
    AudioSlistLink* lastCommand;            // +0x50
    signed char value54;                    // +0x54 0x0025df40: 0xff; 0x0025da00 reads it signed
    unsigned char pad55[3];
    int state;                              // +0x58 2..5 (0x0025d3f0, 0x0025d740, 0x0025d780, 0x0025dd00)
    unsigned char flag5c;                   // +0x5c 0x0025df40 / 0x0025d7f0 / 0x0025da00
    unsigned char pad5d[3];
};

// A beat of a beat set (0x00261ef0 creates them from the pool 0x004e7a30, 0x00261d10 frees them).
struct AudioBeatSetBeat {
    float beat;                             // +0x00 0x00261ef0 stores the read word; 0x00261f90 / 0x00261e60 read a float
    AudioSlistLink link;                    // +0x04 0x00261ef0 appends it
};

// A beat set (the type 0x004e7a78's instances; embedded in events: 0x00261ef0 fills it, 0x00261d10 / 0x00262020
// clear it, 0x00261f90 / 0x00261e60 walk it). Same layout as g3's AudioSeqBeatSet.
struct AudioBeatSet {
    AudioSlistLink* head;                   // +0x00
    AudioSlistLink* tail;                   // +0x04
};

// ---- reg5 group g0: the sequence actions / commands / events, the mix busses, fade behaviours, the om entity
// loader, the sequence track and two HAL streams (instance records of the static om types' pools) ----
// Uses OmTreeNode, OmString, AudioSlistLink, AudioLink, AudioSeqEvent, AudioBeatSet, AudioSeqEventLogicRepeat,
// AudioClip, AudioSeqTrackPlayer, AudioChannelVolumeArray, AudioChannelSendVolumeArray (records.h). Offsets are
// the 32-bit ones.

// The head of every audio::SeqAction instance (vftable 0x004298fc is the base's; each SeqEventX::vfunc_2 allocates
// the action from its type's pool, stores the vftable, the event and state 0, and queues it with 0x0025dc20,
// which links item+4). The small actions are exactly this head.
struct AudioSeqActionBase {
    const void* vftable;                    // +0x00 the action class's vftable
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20 links item+4)
    void* event;                            // +0x08 the SeqEventX that created it (vfunc_2 stores `this`;
                                            //       vfunc_1 / vfunc_6 read the event's fields through it)
    int state;                              // +0x0c 0..5 (vfunc_1..4 store 1/3/4/5, vfunc_5 returns it)
};

// audio::SeqActionWait (vftable 0x00429bc8; SeqEventWait::vfunc_2 0x00250460 creates it from the pool 0x004e6960;
// vfunc_6 0x00250160 evaluates the event's expression at event+8).
struct AudioSeqActionWait {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionExpression (vftable 0x00429ce8; 0x00250cd0 creates it from the pool 0x004e6ad0).
struct AudioSeqActionExpression {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionChannelSendVolumes (vftable 0x00429968; 0x0024f230 creates it from the pool 0x004e6700;
// vfunc_1 0x0024f6a0 creates or updates the layer's AudioChannelSendVolumeFadeBehaviour).
struct AudioSeqActionChannelSendVolumes {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionChannelSends (vftable 0x00429a84; 0x0024fb80 creates it from the pool 0x004e6800).
struct AudioSeqActionChannelSends {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionPlayTrack (vftable 0x00429e28; 0x002517e0 creates it from the pool 0x004e6c30).
struct AudioSeqActionPlayTrack {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionStopTrack (vftable 0x00429d98; 0x002512e0 creates it from the pool 0x004e6b80).
struct AudioSeqActionStopTrack {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionChannelVolumes (vftable 0x00429eac; 0x00252190 creates it from the pool 0x004e6ce0;
// vfunc_1 0x00252220 creates or updates the layer's AudioChannelVolumeFadeBehaviour).
struct AudioSeqActionChannelVolumes {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarVolume (vftable 0x00429ffc; 0x00252a50 creates it from the pool 0x004e6e90).
struct AudioSeqActionVarVolume {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarVolumeRand (vftable 0x00429f74; 0x002526f0 creates it from the pool 0x004e6de0).
struct AudioSeqActionVarVolumeRand {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarTempo (vftable 0x0042a090; 0x00252ed0 creates it from the pool 0x004e6f40).
struct AudioSeqActionVarTempo {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarPosDist (vftable 0x0042a11c; 0x002532d0 creates it from the pool 0x004e6ff0).
struct AudioSeqActionVarPosDist {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarPitchRand (vftable 0x0042a1b8; 0x002536c0 creates it from the pool 0x004e70a0).
struct AudioSeqActionVarPitchRand {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionVarPitch (vftable 0x0042a244; 0x00253a40 creates it from the pool 0x004e7150; vfunc_1 0x00253830
// points the player's pitch at event+8).
struct AudioSeqActionVarPitch {
    AudioSeqActionBase action;              // +0x00
};

// audio::SeqActionStream (vftable 0x0042a2dc; SeqEventStream::vfunc_2 0x00254580 creates it from the pool
// 0x004e7268: +0x0c/+0x10 -1, the rest 0). States in +0x20; the load sub-state in +0x1c (0x00253cb0).
struct AudioSeqActionStream {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20)
    void* event;                            // +0x08 the SeqEventStream (0x00253cb0 passes event+8, its file)
    int startPosition;                      // +0x0c -1; 0x00253cb0 copies +0x14 into it
    int queued;                             // +0x10 -1; 0x00253cb0 stores 0x0024ba70's result (a queue position)
    int position;                           // +0x14 vfunc_6 0x00254300 computes it, vfunc_2 0x00253e80 zeroes it
    unsigned int priority;                  // +0x18 vfunc_2 sets 100; vfunc_6 compares the player's +0x54 with it
    int loadState;                          // +0x1c 0..4 (0x00253cb0, vfunc_6)
    int state;                              // +0x20 vfunc_1..5 (vfunc_5 0x00253f00 returns it)
    unsigned int format;                    // +0x24 the stream's format word (0x00253cb0: *slot 2's result;
                                            //       0x0025be60 / 0x0024c4d0 decode it)
    unsigned int frames;                    // +0x28 the stream's slot 4 result (0x00253cb0)
};

// audio::SeqActionClip (vftable 0x0042a5d0; SeqEventClip::vfunc_2 0x00256320 creates it from the pool 0x004e7570).
struct AudioSeqActionClip {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20)
    void* event;                            // +0x08 the SeqEventClip (vfunc_1 0x00256370 reads its byte +8)
    unsigned int position;                  // +0x0c 0x00255ed0 stores 0x00258f00's result (a voice position),
                                            //       vfunc_6 0x00256420 passes it to 0x00258ea0; vfunc_2 zeroes it
    AudioClip* clip;                        // +0x10 the entity the player's +0x88 lookup returns (vfunc_6 bumps its
                                            //       refs at +0x22, reads its data at +0x28)
    void* voice;                            // +0x14 0x00259610's result (vfunc_6); 0x00259c50 / 0x00259b40 take it
    int state;                              // +0x18 vfunc_5 0x00255e20 returns it
};

// audio::SeqActionCrossFade (vftable 0x0042a4bc; SeqEventCrossFade::vfunc_2 0x00255930 creates it from its pool).
struct AudioSeqActionCrossFade {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20)
    void* event;                            // +0x08 the SeqEventCrossFade (vfunc_1 reads +0x08..+0x19, +0x2c of it)
    int state;                              // +0x0c vfunc_5 0x00255590 returns it
    AudioSeqTrackPlayer* player;            // +0x10 0x002495f0's / 0x0024a9c0's result (vfunc_2 0x00255a00);
                                            //       0x002497e0 releases it (vfunc_4 0x00255560)
    void* source;                           // +0x14 0x0024a390's result (vfunc_2); vfunc_1 reads +0x2c of it
    int previousBeat;                       // +0x18 the source's +0x2c (vfunc_2, vfunc_1 0x00255b10)
};

// audio::SeqActionSilence (vftable 0x0042a36c; SeqEventSilence::vfunc_2 0x002549a0 creates it from its pool).
struct AudioSeqActionSilence {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the action queue (0x0025dc20)
    void* event;                            // +0x08 the SeqEventSilence (0x002549a0 reads its min/max)
    int elapsed;                            // +0x0c ms waited (vfunc_6 0x00254950 adds the time step)
    float duration;                         // +0x10 the random duration (0x002549a0 fild/fstp)
    unsigned int lastTime;                  // +0x14 0x00267f80's time (vfunc_1 0x002546f0, vfunc_6)
    int state;                              // +0x18 vfunc_5 0x00254730 returns it
};

// audio::SeqCommandCondition (vftable 0x00429b10; SeqEventCondition::vfunc_2 0x0024ff10 creates it from the pool
// 0x004e68b0 and queues it with 0x0025dba0, which links item+4).
struct AudioSeqCommandCondition {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the command queue (0x0025dba0)
    void* event;                            // +0x08 the SeqEventCondition (vfunc_0 0x0024ff60 reads its expression
                                            //       at +0x14 and its first child at +0x0c)
    void* current;                          // +0x0c the current child event (-1 before the test; vfunc_0 calls its
                                            //       slot 2 and follows its link at +4)
};

// audio::SeqCommandLogicOr (vftable 0x0042a450; SeqEventLogicOr::vfunc_2 0x00255210 creates it from the pool
// 0x004e7410 and queues it with 0x0025dba0).
struct AudioSeqCommandLogicOr {
    const void* vftable;                    // +0x00
    AudioSlistLink link;                    // +0x04 the command queue (0x0025dba0)
    void* event;                            // +0x08 the SeqEventLogicOr (vfunc_0 0x00255250 picks a child of it)
};

// audio::SeqEventWaitBeat (vftable 0x00429c5c; 0x002507c0 / SeqEventWaitBeatType::vfunc_3 0x00250910 construct it,
// vfunc_4 0x002507f0 destroys it).
struct AudioSeqEventWaitBeat {
    AudioSeqEvent event;                    // +0x00 (0x0025fd00)
    AudioBeatSet beatSet;                   // +0x08 0x00261ef0 reads it (vfunc_0 0x00250870), 0x00262020 frees it
    int layerName;                          // +0x10 hash of "mLayerNameBuf" (0x002507c0 sets "stitched")
};

// audio::SeqEventStopTrack (vftable 0x00429d1c; 0x00250dc0 constructs, vfunc_4 0x00251030 destroys).
struct AudioSeqEventStopTrack {
    AudioSeqEvent event;                    // +0x00 (0x0025fd00)
    unsigned int fadeTimeMs;                // +0x08 "mFadeTimeMs" (vfunc_0 0x00250e00 reads with 0x0025abd0)
    unsigned int delayTimeMs;               // +0x0c "mDelayTimeMs"
    OmString seqTrackName;                  // +0x10 "mSeqTrackNameBuf" (0x00250dc0 sets "MySeqTrack", vfunc_4 releases)
    unsigned char stopOtherTracks;          // +0x1c "mStopOtherTracks" (byte; 0x0025aa80 reads it)
    unsigned char pad1d[3];                 // +0x1d
};

// audio::SeqEventVarPitch (vftable 0x0042a1f0; 0x00253780 / SeqEventVarPitchType::vfunc_3 0x00253920 construct it).
struct AudioSeqEventVarPitch {
    AudioSeqEvent event;                    // +0x00 (0x0025fd00)
    float pitch;                            // +0x08 1.0f; vfunc_0 0x002537a0 reads it (0x0025ac10)
};

// om::EntityLoader (vftable 0x00429394; 0x0024d360 constructs it; content::ObjectLoader / LoadObject base).
struct OmEntityLoader {
    const void* vftable;                    // +0x00
    int refs;                               // +0x04 LoadObject's count (0x00038290 increments, 0x000382a0 releases)
    void* type;                             // +0x08 the om::EntityType (0x0024d360's argument; vfunc_3 0x0024d220
                                            //       calls its slot 2 and passes +0x30 of it)
};

// audio::MixBuss (vftable 0x0042a6d8; 0x0025a7e0 creates it from the pool 0x00241670 returns and inserts it into
// the Mix's tree at +0x38 by name with 0x0025a610; 0x0025a220 frees them).
struct AudioMixBuss {
    const void* vftable;                    // +0x00
    OmTreeNode node;                        // +0x04 the node in AudioMix's buss tree (0x0025a610; owners subtract 4)
    unsigned int name;                      // +0x14 the buss name hash, the tree key (vfunc_1 0x0025a370 reads it)
    float volume18;                         // +0x18 1.0f (0x0025a7e0; vfunc_1 reads; 0x00242860 reads it)
    float volume1c;                         // +0x1c 1.0f
    float value20;                          // +0x20 0
    float value24;                          // +0x24 0
    unsigned char flag28;                   // +0x28 (byte; vfunc_1 reads it with 0x0025aa80; 0x00242860 reads it)
    unsigned char pad29[3];                 // +0x29
};

// om::DynBehaviour (vftable 0x0042991c): a behaviour on a layer, a node of the layer's tree at +0x64 keyed by a
// behaviour id (0x0024f280 inserts it with &key; the finders compare node+0x10 and subtract 4). Same shape as
// OmDynAttr.
struct OmDynBehaviour {
    const void* vftable;                    // +0x00
    OmTreeNode node;                        // +0x04 0x0024f280
    unsigned int key;                       // +0x14 the behaviour class id (DAT_004e6748 / DAT_004e6d28)
};

// audio::ChannelSendVolumeFadeBehaviour (vftable 0x00429988; SeqActionChannelSendVolumes::vfunc_1 0x0024f6a0
// creates it from the pool 0x004e67b8; vfunc_1 0x0024ee40 fades the 64 volumes toward the targets).
struct AudioChannelSendVolumeFadeBehaviour {
    OmDynBehaviour behaviour;               // +0x00
    unsigned int fadeTime;                  // +0x18 the event's +0x48 (0x0024f6a0)
    const unsigned char* targets;           // +0x1c the event's send volumes (event+8; vfunc_1 reads 64 bytes)
    AudioChannelSendVolumeArray* volumes;   // +0x20 the layer's +0x40 array (vfunc_1 writes 64 floats)
};

// audio::ChannelVolumeFadeBehaviour (vftable 0x00429ecc; SeqActionChannelVolumes::vfunc_1 0x00252220 creates it
// from the pool 0x004e6d98; vfunc_1 0x00251ce0 fades the 16 volumes).
struct AudioChannelVolumeFadeBehaviour {
    OmDynBehaviour behaviour;               // +0x00
    unsigned int fadeTime;                  // +0x18 the event's +0x18 (0x00252220)
    const unsigned char* targets;           // +0x1c the event's volumes (event+8)
    AudioChannelVolumeArray* volumes;       // +0x20 the layer's +0x3c array (0x00251ad0 creates it)
};

// audio::SeqTrack (vftable 0x0042a600; 0x00262090 constructs it in an item of the pool 0x00262030 returns,
// 0x00256c80 / 0x00256d40 destroy it; 0x00257c20 inserts it into the Sequence's tree at +0x28 by name and appends
// it to the Sequence's track list at +0x3c).
struct AudioSeqTrack {
    const void* vftable;                    // +0x00
    OmTreeNode node;                        // +0x04 in AudioSequence's track tree (0x00257560 compares node+0x34)
    AudioLink link;                         // +0x14 in AudioSequence's track list (0x00257c20, 0x00256d40)
    AudioSeqEventLogicRepeat events;        // +0x1c the track's events (0x00254c20 constructs, vftable 0x0042a3e4;
                                            //       vfunc_1 0x002620e0 reads it through its slot 0; 0x002607a0)
    unsigned int name;                      // +0x38 hash of the track name (0x00262090: "MySeqTrack"; the tree key)
    unsigned int layerName;                 // +0x3c hash of the layer name (0x00262090)
    unsigned int bits40;                    // +0x40 two 5-bit fields (vfunc_1), bit 0 set by the constructor
    unsigned char flags44;                  // +0x44 two flag bits (vfunc_1; 0x00262090 clears them)
    unsigned char pad45[3];                 // +0x45
};

// audio::HalRsdFileStream (vftable 0x0042ae24; 0x00263160 constructs it, 0x002631f0 allocates it from the pool
// 0x004e7b98; vfunc_12 0x00263420 destroys it). A HalStream (vftable only) over an RSD file.
struct AudioHalRsdFileStream {
    const void* vftable;                    // +0x00
    OmString fileName;                      // +0x04 0x00263160 copies it (0x00240170); vfunc_0 0x002632c0 opens it
    OmString name;                          // +0x10 0x00263160 sets it (0x00240190); vfunc_10 0x00262fc0 returns it
    int openFlags;                          // +0x1c the constructor's last argument (vfunc_0 passes it to 0x002696d0)
    void* file;                             // +0x20 the open file object (0x002696d0 stores it; vfunc_5/6/7/11 call
                                            //       through its vftable, vfunc_12 releases it)
    AudioHalRsdFileHeader* header;          // +0x24 an item of the pool 0x004e7b50 (vfunc_11 0x00263330 reads 0x1a4
                                            //       bytes into it; vfunc_9 indexes +0xa4 of it; vfunc_12 frees it)
    unsigned int format;                    // +0x28 *the 6th argument, or 0x00263480 decodes it (vfunc_2 returns &)
    unsigned int remaining;                 // +0x2c bytes left (vfunc_4 returns it, vfunc_5 / vfunc_11 update it)
    unsigned int offset;                    // +0x30 the file offset of the data (3rd argument; vfunc_5, vfunc_11)
    unsigned int length;                    // +0x34 4th argument (vfunc_5 / 0x002630c0 read it)
    unsigned int value38;                   // +0x38 5th argument (0x002630c0 reads it)
    unsigned int lastRead;                  // +0x3c bytes of the last read (vfunc_6 / vfunc_7 / vfunc_8 / vfunc_11)
    unsigned char hasFormat;                // +0x40 1 when the format is known (0x00263160, vfunc_11)
    unsigned char pad41[3];                 // +0x41
    int state;                              // +0x44 0..6 (vfunc_1 0x00262f20 maps it)
};

// audio::HalRadicalAdpcmDecodeStream (vftable 0x0042adc0; 0x00262e60 creates it from the pool 0x004e7b08,
// vfunc_13 0x00262e30 destroys it): a HalStream decoding another stream's Radical ADPCM data.
struct AudioHalRadicalAdpcmDecodeStream {
    const void* vftable;                    // +0x00
    void* source;                           // +0x04 the compressed HalStream (0x00262e60's argument; every slot
                                            //       calls through its vftable; vfunc_13 releases it)
    unsigned int format;                    // +0x08 the decoded format (vfunc_2 0x00262cb0 returns &; vfunc_11 sets)
    void* buffer;                           // +0x0c the caller's output buffer (vfunc_6 / vfunc_7's 1st argument;
                                            //       vfunc_11 passes it to the decoder 0x002629a0)
    void* compressed;                       // +0x10 where the compressed bytes are read, inside the buffer
                                            //       (buffer + bytes - compressed size; the source's slot 6/7 reads)
    unsigned int compressedBytes;           // +0x14 vfunc_6 / vfunc_7
    unsigned int framesRead;                // +0x18 the source's read count (vfunc_11; vfunc_8 converts it)
    int state;                              // +0x1c 0..5 (vfunc_1 0x00262c70 maps it; 0x00262e60 zeroes it)
};


// ---- reg6: the remaining 0x00266e00 allocations (core cement library, debug console client, XBox controllers,
// movie::PlayerBink). Offsets are the 32-bit ones; each size is the literal its allocation site passes. ----

// The 0x3c-byte header at the start of a cement library file (on-disk data: stays 32-bit, no pointers). The
// file-completion callback 0x00277810 reads it into the library's +0x24 (the file's slot 3, 0x3c bytes) and
// checks it; 0x002779b0 / 0x002776c0 read the counts.
struct CoreCementLibraryHeader {
    char magic[0x18];                       // +0x00 "ATG CORE CEMENT LIBRARY" (0x00277810 compares 0x18 bytes)
    unsigned int unknown18[2];              // +0x18
    unsigned char version[2];               // +0x20 0x00277810: [0] must be 2, [1] below 2 (0x002779b0 picks the
                                            //       entry layout by [1])
    unsigned char flag22;                   // +0x22 0x00277810 rejects a nonzero one
    unsigned char flag23;                   // +0x23 0x00277810 requires it (with version 2)
    unsigned int tableOffset;               // +0x24 the file position of the entry table (0x00277810 seeks to it)
    unsigned int tableSize;                 // +0x28 its bytes (0x00277810 allocates and reads them)
    unsigned int unknown2c[2];              // +0x2c
    unsigned int dataCount;                 // +0x34 0x00277810 / 0x002776c0 test it (the drive's shared buffer);
                                            //       0x002779b0 passes it to 0x00277c40
    unsigned int entryCount;                // +0x38 0x002779b0 hands it (in eax) to the table search 0x00277310
};

// core::CementLibrary (0x00277a70 constructs it; vftables 0x0042bfac / +4 0x0042bf98 / +8 0x0042bf90 /
// +0x10 0x0042bf80; 0x002776c0 destroys it): a drive's archive of files. 0x00277b70 allocates 0x74 bytes.
struct CoreCementLibrary {
    const void* vftable;                    // +0x00 core::ICementLibrary
    const void* vftableCallback;            // +0x04 core::IFileCompletionCallback (0x00277810 is its slot 3)
    const void* vftableObject;              // +0x08 core::Object / BaseObject
    int heap;                               // +0x0c the heap id (DAT_004cdbb0; 0x002776c0 frees the table on it)
    const void* vftableMutable;             // +0x10 core::SafeRefCount / IMutable
    int refs;                               // +0x14 (1 at construction; vfunc_0 0x00277790 increments it)
    void* drive;                            // +0x18 the core::Drive (1st argument; 0x00277460 / 0x00277810 call it,
                                            //       0x002776c0 takes the library off its list 0x00272bb0)
    void* file;                             // +0x1c the core::File (2nd argument; 0x00277810 reads the header from it)
    int state;                              // +0x20 0 loading, 1 open, 2 failed (vfunc_3 0x002773a0, vfunc_6 0x002773e0,
                                            //       0x00277410 sets it)
    CoreCementLibraryHeader header;         // +0x24
    void* table;                            // +0x60 the entry table (0x00277810 allocates it with 0x00266eb0;
                                            //       0x002779b0 searches it with 0x00277310; 0x002776c0 frees it)
    CoreCementLibrary* next;                // +0x64 the drive's list link (CoreDriveLibraryList: 0x00277570 / 0x002775b0)
    int bucket;                             // +0x68 the list it is on (3rd argument; 0x00277570 indexes by it)
    void* callback;                         // +0x6c the open-completion callback (vfunc_5 0x002773f0 sets it,
                                            //       0x00277410 calls its slot 3 and releases it)
    hulk_uintptr callbackArgument;          // +0x70 vfunc_5's 2nd argument, passed back to the callback's slot 3
                                            //       (its type is the caller's: pointer-sized)
};

// A pending debug-console message (the ConsoleClient's pool of 0x80 items of 0x110 bytes; 0x0026e140 fills one
// and appends it to the queue, 0x0026eab0 sends and frees them).
struct CoreConsoleTxBuffer {
    char data[0x108];                       // +0x000 the message (0x0026e140 copies the caller's bytes)
    unsigned int size;                      // +0x108
    CoreConsoleTxBuffer* next;              // +0x10c the queue link (0x0026e140 walks to the tail)
};

// core::ConsoleClient (0x0026e2a0 constructs it; vftables 0x0042b47c / +4 0x0042b474; 0x0026e360 / 0x0026ea50
// destroy it): the debug console's connection to a host (DAT_005283b0; 0x0026eab0 updates it). The network
// functions it calls are stubs in this build (0x0026eee0-0x0026ef50 return 0). 0x0026e9e0 allocates 0x1d8 bytes.
struct CoreConsoleClient {
    const void* vftable;                    // +0x000 core::IRefCount
    const void* vftableObject;              // +0x004 core::RefCount / Object / BaseObject
    int heap;                               // +0x008 the heap id
    int refs;                               // +0x00c (1; 0x0026e330 increments it)
    unsigned int listener[0x16];            // +0x010 the listening socket's state (0x0026e030 clears 0x16 words and
                                            //        passes it to the stubs; opaque here)
    unsigned int connection[0x16];          // +0x068 the connection's state (0x0026e030, 0x0026e140 / 0x0026eab0 send
                                            //        and receive through it)
    int state;                              // +0x0c0 0 closed, 1 listening, 2 accepting, 3 connected (0x0026e030,
                                            //        0x0026e0e0, 0x0026eab0)
    void* txPool;                           // +0x0c4 the core memory pool 0x002702a0 creates (its slot 3 allocates,
                                            //        slot 4 frees: 0x0026e140, 0x0026eab0)
    CoreConsoleTxBuffer* txQueue;           // +0x0c8 messages to send (0x0026e140 appends, 0x0026eab0 drains)
    char receive[0x108];                    // +0x0cc the received message (0x0026eab0 reads 0x108 bytes into it;
                                            //        +0 its type, +4 the target console)
    void* consoles;                         // +0x1d4 the core::DebugConsole list, linked through their +0x10
                                            //        (0x0026e200 searches it, 0x0026e3c0 unlinks)
};

// core::ControllerInputPointXBox (vftable 0x0042b24c; 0x00268fa0 constructs 20 per pad, 0x002692c0 binds them
// to the XInput state table 0x004cd6a8): one button or axis of a pad.
struct CoreControllerInputPointXBox {
    const void* vftable;                    // +0x00
    int refs;                               // +0x04 (0x00268cd0 / 0x00268ce0)
    float value;                            // +0x08 (0x00268d10 / 0x00268f00 store 0x00268d30's reading)
    float minimum;                          // +0x0c (0x00268ec0 sets, 0x00268ea0 / 0x00268ee0 read)
    float maximum;                          // +0x10 (1.0 at construction)
    float threshold;                        // +0x14 the change threshold (0x00268e10 clamps it to 0..1)
    int heldTime;                           // +0x18 (0x00268f00, 0x00268ea0)
    int changeTime;                         // +0x1c (0x00268cf0, 0x00268f00)
    const char* type;                       // +0x20 the state table's type name (0x00268d30 compares it with
                                            //       DAT_004cd698..DAT_004cd6a4; vfunc 0x00268e00 returns it)
    const char* name;                       // +0x24 (vfunc 0x00268df0 returns it; 0x00268a10 compares names)
    unsigned int field;                     // +0x28 the button mask or the byte offset into the state (0x00268d30)
    void* callback;                         // +0x2c the change callback (0x00268e60 sets, 0x00268e80 clears,
                                            //       0x00268f00 calls its slot 0)
    hulk_uintptr callbackArgument;          // +0x30 0x00268e60's 2nd argument, passed back by 0x00268f00
};

// core::ControllerOutputPointXBox (vftable 0x0042b228): a pad's motor (2 per pad).
struct CoreControllerOutputPointXBox {
    const void* vftable;                    // +0x00
    int refs;                               // +0x04 (0x00268be0 / 0x00268bf0)
    const char* name;                       // +0x08 "LeftMotor" / "RightMotor" (0x002692c0; vfunc 0x00268c00 returns it)
    float value;                            // +0x0c 0..1 (0x00268c30 clamps, 0x00268c20 returns; 0x002685a0 reads)
};

// core::ControllerXBox (vftable 0x0042b14c; 0x00268fa0 constructs it, 0x002692c0 opens it on a port, 0x00268520
// destroys it): one pad of the controller system (4 of them inline, 0x4a0 bytes apart).
struct CoreControllerXBox {
    const void* vftable;                    // +0x000
    int refs;                               // +0x004 (0x00268580 / 0x00268590; 0x002685a0 polls only while > 0)
    hulk_uintptr handle;                    // +0x008 the XInput handle (0x002692c0; 0x002685a0, 0x00268780, 0x00268520)
    int port;                               // +0x00c (0x002692c0)
    int slot;                               // +0x010 (0x002692c0)
    unsigned int inputCount;                // +0x014 20 (0x002692c0; 0x00268b10 returns it)
    CoreControllerInputPointXBox inputs[20];   // +0x018 (0x00268b20)
    CoreControllerOutputPointXBox outputs[2];  // +0x428 (0x00268b50)
    char name[12];                          // +0x448 "Portx\Slotx" with the digits (0x002692c0; 0x00268b00 returns it)
    void* buffer;                           // +0x454 the core::ControllerBuffer (0x002692c0's last argument;
                                            //        0x00268690 / 0x002686d0 / 0x00268760 call it)
    // +0x458 the XInputSetState feedback (0x002692c0 clears 0x46 bytes; 0x002685a0): inline, the next byte is at
    // +0x49e (a nested struct would round to 0x48)
    unsigned int feedbackStatus;            // +0x458 ERROR_IO_PENDING (0x3e5) while a rumble is in flight
    hulk_uintptr feedbackEvent;             // +0x45c the header's event handle (0x002685a0 clears it)
    unsigned char feedbackReserved[0x3a];   // +0x460
    unsigned short leftMotor;               // +0x49a 0..65535 (0x002685a0)
    unsigned short rightMotor;              // +0x49c
    unsigned char connected;                // +0x49e (0x002692c0 sets 1; the system's loops test it)
    unsigned char pad49f;                   // +0x49f
};

// core::ControllerSystemXBox (0x00269030 constructs it; vftables 0x0042b2a4 / +4 0x0042b29c; 0x00269590
// destroys it): the four pads (DAT_00528398). 0x00269640 allocates 0x12a8 bytes.
struct CoreControllerSystemXBox {
    const void* vftable;                    // +0x0000 core::IControllerSystem
    const void* vftableObject;              // +0x0004 core::Object / BaseObject
    int heap;                               // +0x0008 the heap id
    int refs;                               // +0x000c (0x00269150 / 0x00269160)
    unsigned char paused;                   // +0x0010 (0x00268390 sets it; 0x00269170 tests it)
    char pad11[3];                          // +0x0011
    int timeOffset;                         // +0x0014 (0x002683f0; 0x00269170 / 0x002691f0 add it to the time)
    int rate;                               // +0x0018 (10 at construction; 0x00268390)
    void* connectionCallback;               // +0x001c a core::IControllerConnectionChangeCallback (the constructor's
                                            //         1st argument; 0x00268460 sets, 0x00269530 clears,
                                            //         0x002691f0 calls its slot 0)
    CoreControllerXBox controllers[4];      // +0x0020
    unsigned int interval;                  // +0x12a0 the poll interval (10; 0x00268440, 0x00269170)
    unsigned int lastPoll;                  // +0x12a4 the time of the last poll (0x00267f80; 0x00269170)
};

// movie::PlayerBink (0x00333f10 constructs it; vftables 0x004340bc / +4 0x004340b0; 0x00333fa0 destroys it):
// the movie player (DAT_00555ba4). 0x00334010 allocates 0x1dc bytes.
struct MoviePlayerBinkTrack {
    unsigned int count;                     // +0x00 the speaker entries (0x00333ab0 copies them; 0x00333970)
    unsigned int speakers[16];              // +0x04 (0x00333970 passes them to 0x00367660)
};

struct MoviePlayerBink {
    const void* vftable;                    // +0x000 movie::Player2
    const void* vftableObject;              // +0x004 core::RefCount / Object / BaseObject
    int heap;                               // +0x008 the heap id (0x00333cb0 / 0x00333de0 make it the Bink heap)
    int refs;                               // +0x00c (0x00333f70)
    void* listener;                         // +0x010 a reference (0x00333c50 sets it; 0x00333de0 calls its slot 3)
    void* renderer;                         // +0x014 the render strategy (0x00333c50; 0x00333cb0 / 0x00333de0 call it)
    int state;                              // +0x018 0 closed, 1..4 (0x00333cb0, 0x00333d80, 0x00333db0)
    void* bink;                             // +0x01c the open movie (0x00364fe0's result; 0x00333d50 closes it)
    float volume;                           // +0x020 (1.0; 0x003339b0 sets, 0x00333a10 returns)
    unsigned char finished;                 // +0x024 (0x00333ca0, 0x00333cb0 clear; 0x00333de0)
    unsigned char busy;                     // +0x025 0x00333de0's re-entry guard
    char pad26[2];                          // +0x026
    unsigned int trackCount;                // +0x028 (0x00333ab0; 0x00333cb0 passes it with the ids to 0x00364dc0)
    unsigned int trackIds[6];               // +0x02c
    MoviePlayerBinkTrack tracks[6];         // +0x044
};

// core::MemoryPool (0x00270170 constructs it, 0x0026ff90 destroys it; vftables 0x0042b5b4 / +4 0x0042b5ac): a pool
// of equal-sized items. 0x002702a0 allocates one (0x34 bytes) and 0x00270020 sets it up: the items are carved out
// of one block of the heap and linked through their first word; vfunc_13 0x002701d0 pops one (and creates a child
// pool of growCount items when the pool is empty), vfunc_4 0x002700b0 pushes it back (or hands it to the child).
// include/gen/core.h's core::MemoryPool (f_04 .. f_30) and owners::Pool_270020 have this layout on every target.
struct CoreObjectBase {
    const void* vftable;                    // +0x00 core::BaseObject / core::Object / core::RefCount
    int heap;                               // +0x04 DAT_004cdbb0 at construction (the destructors restore it)
};
struct CoreMemoryPool {
    const void* vftable;                    // +0x00 core::IRefCount / core::IMemoryPool / core::MemoryPool
    CoreObjectBase object;                  // +0x04 the core::RefCount base (a base class: on the 64-bit MS ABI the
                                            //       members after it start past its rounded size, as gen's f_0c)
    int refs;                               // +0x0c (vfunc_0 0x0026fff0 increments)
    void* freeHead;                         // +0x10 the first free item (0x00270020 links them, 0x002701d0 / 0x002700b0)
    int heap;                               // +0x14 the heap id the block and the child come from (0x00270020;
                                            //       0x0026ff90 frees the block with 0x00266f20)
    char* blocks;                           // +0x18 the items' block (0x00266eb0's result; 0x002700b0 / 0x002700f0
                                            //       compare an address with it)
    unsigned int stride;                    // +0x1c the item size rounded up to the alignment (0x0026fd50)
    unsigned int count;                     // +0x20 items in the block
    unsigned int growCount;                 // +0x24 items of a child pool (0: the pool does not grow)
    unsigned int live;                      // +0x28 items handed out (0x002701d0 increments, 0x002700b0 decrements)
    unsigned int peak;                      // +0x2c the most items handed out at once
    void* child;                            // +0x30 the child core::MemoryPool (0x002701d0 creates it)
};

// The file system's drive registry (0x002709b0 clears it, 0x00270c10 finds a drive by name, 0x00270c80 / 0x00270d40
// add one, 0x002710d0 opens a file through one, 0x00270f90 / 0x00271070 unmount): 26 entries, the count at
// 0x0052a128, the current drive's name at 0x0052a10c, all under the critical section 0x0052a0f0.
struct CoreDriveRegistryEntry {
    char name[16];                          // +0x000 the drive's name, lower case
    char terminator;                        // +0x010
    char pad11[3];                          // +0x011
    void* drive;                            // +0x014 the core::Drive mounted (0x00277260's result; 0 unmounted)
    char details[0x104];                    // +0x018 the drive's source directory (0x00270d40 copies 0x100 bytes;
                                            //        0x00270e60 returns it; 0x002709b0 clears its first byte)
};
extern "C" CoreDriveRegistryEntry DAT_00528418[26];

// core::File's view of its cement library entry (0x00277c00 clears the first 11 words, 0x00277c40 sets it up with
// the library it references, 0x00277d00 reads through it)
struct CoreFileView {
    void* resource;                         // +0x00 the core::CementLibrary (0x00277c40 adds a reference, slot 0)
    unsigned int words[12];                 // +0x04 offsets, sizes and positions (0x00277c40, 0x00277d00)
};

// core::File (0x002764d0 constructs it; vftables 0x0042bd3c / +4 0x0042bd30): an open file, from the "File" pool
// (0x00275d20 creates it with this item size, 0x00275d50 allocates). include/gen/core.h's core::File has this layout
// on every target (its +0x12c word is the view's pointer: include/gen/evidence-rn.json "fields").
struct CoreFile {
    const void* vftable;                    // +0x000 core::IFile / core::File
    const void* vftableMutable;             // +0x004 core::IMutable
    unsigned int refs;                      // +0x008 (1 at construction)
    void* provider;                         // +0x00c the core::Drive it was opened on
    unsigned int key;                       // +0x010
    unsigned int field14;                   // +0x014
    unsigned int field18;                   // +0x018
    unsigned char flag1c;                   // +0x01c
    unsigned char flag1d;                   // +0x01d the open mode
    char filename[0x101];                   // +0x01e
    char pad11f;                            // +0x11f
    unsigned int field120;                  // +0x120
    unsigned int field124;                  // +0x124
    unsigned int field128;                  // +0x128
    CoreFileView view;                      // +0x12c
    unsigned char field160;                 // +0x160
    char pad161[3];                         // +0x161
    unsigned int field164;                  // +0x164 (0x800 at construction)
};

// core::Request (vftable 0x0042b914): the base of every request a drive thread runs (0x00273560 allocates them from
// the "FileRequest" pool). The drive thread's queues link them through `next` (0x00272fc0, 0x00273140, 0x002731d0);
// core::FileRequest (0x00274e60) adds the core::File it works on (a reference, and one more pending request on it).
struct CoreRequest {
    const void* vftable;                    // +0x00
    void* next;                             // +0x04 the queue link (0 at construction)
    void* file;                             // +0x08 core::FileRequest: the core::File (core::DriveRequest: its drive)
};

// core::CompletionCallbackRequest (vftable 0x0042b9dc) and core::FileCompletionRequest (0x00274ca0 constructs it,
// vftable 0x0042b954): a request that calls back on the thread that queued it, after the requests before it
struct CoreCompletionRequest {
    const void* vftable;                    // +0x00
    void* next;                             // +0x04 the queue link (CoreRequest)
    void* thread;                           // +0x08 the queuing thread's CoreThread (0x0026dbb0's result)
    void* file;                             // +0x0c the core::File (a reference; one more pending request on it)
    void* callback;                         // +0x10 the callback object (a reference, slot 0)
    unsigned int context;                   // +0x14 passed back to the callback
};

// (dg1) The sound-bank path strings the start-up builds ("sound/rsd": 0x0035cea0, 0x0035cf90, 0x0035d7d0; their
// atexit handlers 0x00363c60 / 0x00363c80 / 0x00363e40 free them): owners::String_23fc40's words (the text pointer,
// the capacity, the length), 12 bytes on the 32-bit builds and 16 on 64-bit. 0x004dd260 and 0x004de608 are followed
// by 4 bytes nothing references (config/data.json: pad).
struct StringRecord_23fc40 {
    char* data;
    unsigned short capacity;
    char pad06[2];
    unsigned short extra;
};

extern "C" StringRecord_23fc40 DAT_004dd260[1];
extern "C" StringRecord_23fc40 DAT_004dd6f4[1];
extern "C" StringRecord_23fc40 DAT_004de608[1];

#endif
