// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026b910..0x0026cf60 (kind game, layer engine, confidence high), dominant class core::MemoryDlAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f2ae9c07 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2ae9c07 {} using namespace fn_f2ae9c07;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f2ae9c07 {
extern "C" void __cdecl FUN_0026b910(void *);
struct HeapStats {
    int f464;
    int chunks;
    int bucketCount;
    int f450;
    int f460;
    int f470;
    int bucketBytes;
    int freeBytes;
    int totalBytes;
    unsigned int firstSize;
};
extern "C" void __cdecl FUN_0026b970(void *);
struct MemoryStats { unsigned int systemBytes; char pad04[12]; unsigned int inUseBytes; unsigned int maxSystemBytes; char pad18[4]; unsigned int otherBytes; char pad20[8]; };
extern MemoryStats* __cdecl FUN_0026bac0(MemoryStats* stats);
extern int __cdecl _fwprintf(void* stream, const char* format, ...);
extern "C" void __cdecl FUN_0026bd80(void *);
typedef DlHeapChunk Chunk;
typedef DlHeapState MState;
extern "C" void * __cdecl FUN_0026be70(void *, unsigned int);
static inline Chunk* bin_at(MState* av, unsigned index) {
    return (Chunk*)((char*)&av->bins[index * 2] - Chunk::kHeader);
}
static inline Chunk* chunk_at(Chunk* chunk, hulk_uintptr offset) {
    return (Chunk*)((char*)chunk + offset);
}
static inline unsigned largebin_index(hulk_uintptr size) {
    if ((size >> 6) <= 32)
        return (unsigned)(56 + (size >> 6));
    if ((size >> 9) <= 20)
        return (unsigned)(91 + (size >> 9));
    if ((size >> 12) <= 10)
        return (unsigned)(110 + (size >> 12));
    if ((size >> 15) <= 4)
        return (unsigned)(119 + (size >> 15));
    if ((size >> 18) <= 2)
        return (unsigned)(124 + (size >> 18));
    return 126;
}
typedef unsigned int uint32_26c6a0;
extern "C" void* __cdecl FUN_0026c040(uint32_26c6a0 size);
typedef unsigned int uint_26c840;
void * __cdecl FUN_0026c040(uint_26c840);
static inline hulk_uintptr chunk_size_26c840(hulk_uintptr request) {
    hulk_uintptr n = request + DlHeapChunk::kWord + DlHeapChunk::kAlignMask;
    return n < DlHeapChunk::kMinSize ? DlHeapChunk::kMinSize : n & ~(hulk_uintptr)DlHeapChunk::kAlignMask;
}
extern "C" char DAT_0042aef4[];
extern "C" char DAT_0042b36c[];
extern "C" char DAT_0042b364[];
extern "C" int* FUN_002705f0();
extern "C" void* FUN_00266e00(int, hulk_intptr);
struct MemoryDlAllocator_26ca80 {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08 core::Object: the heap the allocator itself came from
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    int size;                       // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    int count;                      // +0x490 allocations
    int total;                      // +0x494 bytes in use
    int peak;                       // +0x498
    unsigned char ownsArena;        // +0x49c the arena came from heapId's allocator (0x0026cc40 frees it)
    unsigned char inPlace;          // +0x49d the allocator sits in memory it does not own (0x0026cc40 only destroys it)
    char pad[2];
    int refs;                       // +0x4a0
    MemoryDlAllocator_26ca80* FUN_0026ca80(int bytes, int heapFrom, const char* name);
};
} // namespace fn_f2ae9c07
namespace core {
class IMemoryAllocator_26cb10 {
  public:
    virtual void vfunc_0();
};
}
namespace core {
class IRefCount_26cb10 {
  public:
    virtual void r0();
};
}
namespace core {
class Object_26cb10 {
  public:
    virtual void o0();
};
}
namespace core {
class BaseObject_26cb10 {
  public:
    virtual void b0();
};
}
namespace fn_f2ae9c07 {
typedef unsigned char u8_26cbd0;
extern "C" void __cdecl FUN_00266f00(int, void*);
class MemoryDlAllocator_26cbd0 {
  public:
    void FUN_0026cc00(); // the destructor body
    virtual void f0();
    virtual void f1();
    virtual MemoryDlAllocator_26cbd0* f2(u8_26cbd0);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
extern "C" char DAT_003f6098[];
typedef unsigned int u32_26cc00;
struct MemoryDlAllocator_26cc00 {
    volatile hulk_uintptr vptr;
    volatile hulk_uintptr vptr2;
    volatile u32_26cc00 member;
    void FUN_0026cc00();
};
struct Slots_26cc40 {
    virtual void s0();
    virtual void s1();
    virtual void destroy(int flags);
};
extern "C" int FUN_00267090(hulk_intptr);
struct MemoryDlAllocator_26ce90 {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08 core::Object: the heap the allocator itself came from
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    int size;                       // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    int count;                      // +0x490 allocations
    int total;                      // +0x494 bytes in use
    int peak;                       // +0x498
    unsigned char ownsArena;        // +0x49c the arena came from heapId's allocator (0x0026cc40 frees it)
    unsigned char inPlace;          // +0x49d the allocator sits in memory it does not own (0x0026cc40 only destroys it)
    char pad[2];
    int refs;                       // +0x4a0
    MemoryDlAllocator_26ce90* FUN_0026ce90(unsigned char inPlace, void* base, int size, const char* name);
};
struct MemoryDlAllocator_nv_26cf20 {
    void* FUN_0026ca80(int, int, const char*);
};


// 0x0026b910 FUN_0026b910 (84 B): equivalent/0x0026b910.cpp
// sym: _FUN_0026b910 @14a6019ab8d0 @wf9ca3d33696e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0026b910 @ 0x0026b910
// equiv-conv: FUN_0026b910 eax
extern "C" void FUN_0026b910(void * state_) {
    DlHeapState * state = (DlHeapState *)state_;
    for (int i = 0; i < 127; ++i) {
        DlHeapChunk * bin = (DlHeapChunk *)((char *)&state->bins[2 * i + 2] - DlHeapChunk::kHeader);
        bin->next = bin;
        bin->previous = bin;
    }
    state->topPad = 0;
    state->mmapMax = 0;
    state->mmapThreshold = 0x20000;
    state->trimThreshold = 0x20000;
    state->maxFast = (state->maxFast & 2) | 9;
    state->top = (DlHeapChunk *)&state->bins[0];
    state->pageSize = 0x1000;
}


// 0x0026b970 FUN_0026b970 (243 B): equivalent/0x0026b970.cpp
// sym: _FUN_0026b970 @ba5ad2b52aa8 @wf03cac719989
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_0026b970 @ 0x0026b970
// equiv-conv: FUN_0026b910 eax
extern "C" void __cdecl FUN_0026b970(void * heap_) {
 DlHeapState * heap = (DlHeapState *)heap_;
 hulk_uintptr count = heap->maxFast;
 if (!count) {
  FUN_0026b910(heap); // malloc_init_state: heap arrives in eax
  return;
 }
 heap->maxFast = count | 1;
 DlHeapChunk** end = &heap->fastBins[((count | 1) >> 3) - 2];
 for (DlHeapChunk** slot = heap->fastBins; ; ++slot) {
  DlHeapChunk* block = *slot;
  if (block) {
   *slot = 0;
   do {
    hulk_uintptr size = block->size;
    DlHeapChunk* next = block->next;
    hulk_uintptr actual = size & ~(hulk_uintptr)1;
    DlHeapChunk* following = (DlHeapChunk*)((char*)block + actual);
    hulk_uintptr followingSize = following->size & ~(hulk_uintptr)3;
    if (!(size & 1)) {
     hulk_uintptr previousSize = block->previousSize;
     actual += previousSize;
     block = (DlHeapChunk*)((char*)block - previousSize);
     DlHeapChunk* back = block->previous;
     DlHeapChunk* forward = block->next;
     forward->previous = back;
     back->next = forward;
    }
    if (following != heap->top) {
     hulk_uintptr used = ((DlHeapChunk*)((char*)following + followingSize))->size & 1;
     following->size = followingSize;
     if (!used) {
      actual += followingSize;
      DlHeapChunk* forward = following->next;
      DlHeapChunk* back = following->previous;
      forward->previous = back;
      back->next = forward;
     }
     DlHeapChunk* sentinel = (DlHeapChunk*)((char*)&heap->bins[2] - DlHeapChunk::kHeader);
     DlHeapChunk* old = sentinel->next;
     sentinel->next = block;
     old->previous = block;
     block->size = actual | 1;
     block->previous = sentinel;
     block->next = old;
     ((DlHeapChunk*)((char*)block + actual))->previousSize = actual;
    } else {
     block->size = (followingSize + actual) | 1;
     heap->top = block;
    }
    block = next;
   } while (block);
  }
  if (slot == end) break;
 }
}


// 0x0026bac0 FUN_0026bac0 (281 B): equivalent/0x0026bac0.cpp
// sym: ?FUN_0026bac0@fn_f2ae9c07@@YA?AUHeapStats@1@XZ @1146fb595f45 @w6e2c50b78595
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 14/14)
// FUN_0026bac0 @ 0x0026bac0
HeapStats FUN_0026bac0()
{
    DlHeapState *heap = (*(DlHeapState**)&DAT_0052839c);
    if (!heap->top)
        FUN_0026b970((DlHeapState *)heap);
    unsigned int firstSize = (unsigned int)(heap->top->size & ~(hulk_uintptr)3);

    int bucketCount = 0;
    int bucketBytes = 0;
    for (int i = 0; i < 10; i++) {
        for (DlHeapChunk *b = heap->fastBins[i]; b; b = b->next) {
            bucketCount++;
            bucketBytes += (int)(b->size & ~(hulk_uintptr)3);
        }
    }
    int total = firstSize + bucketBytes;
    int chunks = 1;
    for (int i = 0; i < 0x7f; i++) {
        DlHeapChunk *bin = (DlHeapChunk *)((char *)&heap->bins[2 * i + 2] - DlHeapChunk::kHeader);
        for (DlHeapChunk *c = bin->previous; c != bin; c = c->previous) {
            chunks++;
            total += (int)(c->size & ~(hulk_uintptr)3);
        }
    }
    HeapStats stats;
    stats.f464 = (int)heap->systemBytes;
    stats.freeBytes = stats.f464 - total;
    stats.f450 = (int)heap->mmapCount;
    stats.totalBytes = total;
    stats.f460 = (int)heap->mmappedBytes;
    stats.f470 = (int)heap->totalPeak;
    stats.bucketBytes = bucketBytes;
    stats.bucketCount = bucketCount;
    stats.chunks = chunks;
    stats.firstSize = firstSize;
    return stats;
}


// 0x0026bbe0 FUN_0026bbe0 (106 B): matches/0x0026bbe0.cpp
// sym: ?FUN_0026bbe0@fn_f2ae9c07@@YAXXZ
// FUN_0026bbe0 @ 0x0026bbe0
// FUN_0026bbe0 @ 0x0026bbe0
void __cdecl FUN_0026bbe0()
{
    MemoryStats output;
    MemoryStats stats = *FUN_0026bac0(&output);
    _fwprintf(((char*)&DAT_004d9a30), "max system bytes = %10u\n", stats.maxSystemBytes);
    _fwprintf(((char*)&DAT_004d9a30), "system bytes     = %10u\n", stats.systemBytes + stats.inUseBytes);
    _fwprintf(((char*)&DAT_004d9a30), "in use bytes     = %10u\n", stats.otherBytes + stats.inUseBytes);
}


// 0x0026bd80 FUN_0026bd80 (214 B): equivalent/0x0026bd80.cpp
// sym: _FUN_0026bd80 @9bd95a3d2610 @w99f0d057924d
// STATUS: equivalent (tools/equiv.py level 3: 2747 inputs, branch coverage 16/16)
// FUN_0026bd80 @ 0x0026bd80
extern "C" void __cdecl FUN_0026bd80(void* memory) {
    if (!memory) return;
    DlHeapChunk* block = (DlHeapChunk*)((char*)memory - DlHeapChunk::kHeader);
    hulk_uintptr originalSize = block->size;
    hulk_uintptr size = originalSize & ~(hulk_uintptr)3;
    DlHeapState* heap = (*(DlHeapState**)&DAT_0052839c);
    if (size <= heap->maxFast) {
        heap->maxFast &= ~(hulk_uintptr)1;
        DlHeapChunk** slot = &heap->fastBins[(size >> 3) - 2];
        block->next = *slot;
        *slot = block;
        return;
    }
    if (originalSize & 2) return;
    DlHeapChunk* next = (DlHeapChunk*)((char*)block + size);
    hulk_uintptr nextSize = next->size & ~(hulk_uintptr)3;
    if (!(originalSize & 1)) {
        size += block->previousSize;
        block = (DlHeapChunk*)((char*)block - block->previousSize);
        block->next->previous = block->previous;
        block->previous->next = block->next;
    }
    if (next == heap->top) {
        size += nextSize;
        block->size = size | 1;
        heap->top = block;
    } else {
        hulk_uintptr followingFlag = ((DlHeapChunk*)((char*)next + nextSize))->size & 1;
        next->size = nextSize;
        if (!followingFlag) {
            next->next->previous = next->previous;
            next->previous->next = next->next;
            size += nextSize;
        }
        DlHeapChunk* sentinel = (DlHeapChunk*)((char*)&heap->bins[2] - DlHeapChunk::kHeader);
        DlHeapChunk* first = sentinel->next;
        block->previous = sentinel;
        block->next = first;
        sentinel->next = block;
        first->previous = block;
        block->size = size | 1;
        ((DlHeapChunk*)((char*)block + size))->previousSize = size;
    }
    if (size >= 0x10000 && !(heap->maxFast & 1)) FUN_0026b970((DlHeapState *)heap);
}


// 0x0026be70 FUN_0026be70 (454 B): equivalent/0x0026be70.cpp
// sym: _FUN_0026be70 @7aa3f6c49e66 @wea782fdd4e2c
// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 30/34, incomplete)
// FUN_0026be70 @ 0x0026be70
// equiv-conv: FUN_0026be70 eax stack
// The break: 0x005283ac points at the allocator's break word (+0x18), an address in the arena.
extern "C" void *__cdecl FUN_0026be70(void * self_, unsigned int amount) {
    DlHeapState * self = (DlHeapState *)self_;
 DlHeapChunk *old = self->top;
 hulk_uintptr oldSize = old->size & ~(hulk_uintptr)3;
 hulk_uintptr mask = self->pageSize - 1;
 hulk_uintptr wanted = self->topPad + amount + DlHeapChunk::kMinSize;
 if (!(self->maxFast & 2)) wanted -= oldSize;
 hulk_uintptr bytes = (wanted + mask) & ~mask;
 if ((hulk_intptr)bytes <= 0) return 0;
 hulk_uintptr start = (*(*(hulk_uintptr**)&DAT_005283ac));
 (*(*(hulk_uintptr**)&DAT_005283ac)) = start + bytes;
 if ((*(*(hulk_uintptr**)&DAT_005283ac)) >= DAT_005283a8 || start == ~(hulk_uintptr)0) return 0;
 self->systemBytes += bytes;
 if (start == (hulk_uintptr)old + oldSize) {
  old->size = (bytes + oldSize) | 1;
 } else {
  hulk_uintptr extra = 0;
  hulk_uintptr base = start;
  hulk_uintptr cursor;
  bool valid;
  if (!(self->maxFast & 2)) {
   if (base & DlHeapChunk::kAlignMask) { extra = DlHeapChunk::kAlign - (base & DlHeapChunk::kAlignMask); base += extra; }
   extra += oldSize;
   hulk_uintptr end = start + extra + bytes;
   extra += ((end + mask) & ~mask) - end;
   cursor = (*(*(hulk_uintptr**)&DAT_005283ac));
   (*(*(hulk_uintptr**)&DAT_005283ac)) = cursor + extra;
   hulk_uintptr finish = (*(*(hulk_uintptr**)&DAT_005283ac));
   hulk_uintptr limit = DAT_005283a8;
   valid = finish < limit;
   if (!valid || cursor == ~(hulk_uintptr)0) {
    extra = 0;
    cursor = finish;
    valid = valid && cursor != ~(hulk_uintptr)0;
   }
  } else {
   cursor = (*(*(hulk_uintptr**)&DAT_005283ac));
   valid = cursor < DAT_005283a8 && cursor != ~(hulk_uintptr)0;
  }
  if (valid) {
   DlHeapChunk *newBlock = (DlHeapChunk *)base;
   self->top = newBlock;
   newBlock->size = (extra - base + cursor) | 1;
   self->systemBytes += extra;
   if (oldSize) {
    // the old top keeps a free chunk and two fence words (each size kWord, previous in use)
    hulk_uintptr freeSize = (oldSize - 3 * DlHeapChunk::kWord) & ~(hulk_uintptr)DlHeapChunk::kAlignMask;
    old->size = freeSize | 1;
    hulk_uintptr *fence = (hulk_uintptr *)((char *)old + freeSize);
    fence[1] = DlHeapChunk::kWord | 1;
    fence[2] = DlHeapChunk::kWord | 1;
    if (freeSize >= DlHeapChunk::kMinSize) FUN_0026bd80((char *)old + DlHeapChunk::kHeader);
   }
  }
 }
 hulk_uintptr used = self->systemBytes;
 if (used > self->systemPeak) self->systemPeak = used;
 hulk_uintptr total = used + self->mmappedBytes;
 if (total > self->totalPeak) self->totalPeak = total;
 DlHeapChunk *current = self->top;
 hulk_uintptr size = current->size & ~(hulk_uintptr)3;
 if (size < amount + DlHeapChunk::kMinSize) return 0;
 DlHeapChunk *remainder = (DlHeapChunk *)((char *)current + amount);
 self->top = remainder;
 current->size = amount | 1;
 remainder->size = (size - amount) | 1;
 return (char *)current + DlHeapChunk::kHeader;
}


// 0x0026c040 FUN_0026c040 (1152 B): equivalent/0x0026c040.cpp
// sym: _FUN_0026c040 @6ba743526083 @w3bfccb6467a3
// STATUS: equivalent (tools/equiv.py level 3: 680 inputs, branch coverage 93/94, incomplete)
// FUN_0026c040 @ 0x0026c040
// equiv-conv: FUN_0026be70 eax stack
void* __cdecl FUN_0026c040(unsigned bytes) {
    if ((hulk_uintptr)bytes >= (hulk_uintptr)-(hulk_intptr)(2 * Chunk::kMinSize))
        return 0;

    hulk_uintptr padded = (hulk_uintptr)bytes + Chunk::kWord + Chunk::kAlignMask;
    hulk_uintptr requested = padded < Chunk::kMinSize ? Chunk::kMinSize : padded & ~(hulk_uintptr)Chunk::kAlignMask;
    MState* state = *(MState**)&DAT_0052839c;
    Chunk* victim;
    Chunk* back;
    Chunk* front;
    Chunk* remainder;
    Chunk* bin;
    unsigned index;
    hulk_uintptr size;
    hulk_uintptr remainderSize;

    if (requested <= state->maxFast) {
        Chunk** fastbin = &state->fastBins[(requested >> 3) - 2];
        victim = *fastbin;
        if (victim) {
            *fastbin = victim->next;
            return (char*)victim + Chunk::kHeader;
        }
    }

    if (requested < 0x200) {
        index = (unsigned)(requested >> 3);
        bin = bin_at(state, index);
        victim = bin->previous;
        if (victim != bin) {
            if (!victim) {
                FUN_0026b970((MState *)state);
            } else {
                back = victim->previous;
                chunk_at(victim, requested)->size |= 1;
                bin->previous = back;
                back->next = bin;
                return (char*)victim + Chunk::kHeader;
            }
        }
    } else {
        index = largebin_index(requested);
        if (!(state->maxFast & 1))
            FUN_0026b970((MState *)state);
    }

    for (;;) {
        Chunk* unsorted = bin_at(state, 1);
        while ((victim = unsorted->previous) != unsorted) {
            back = victim->previous;
            size = victim->size & ~(hulk_uintptr)3;
            if (requested < 0x200 && back == unsorted && victim == state->lastRemainder &&
                size > requested + Chunk::kMinSize) {
                remainderSize = size - requested;
                remainder = chunk_at(victim, requested);
                unsorted->previous = unsorted->next = remainder;
                state->lastRemainder = remainder;
                remainder->previous = remainder->next = unsorted;
                victim->size = requested | 1;
                remainder->size = remainderSize | 1;
                chunk_at(remainder, remainderSize)->previousSize = remainderSize;
                return (char*)victim + Chunk::kHeader;
            }

            unsorted->previous = back;
            back->next = unsorted;
            if (size == requested) {
                chunk_at(victim, size)->size |= 1;
                return (char*)victim + Chunk::kHeader;
            }

            unsigned destinationIndex;
            if (size < 0x200) {
                destinationIndex = (unsigned)(size >> 3);
                back = bin_at(state, destinationIndex);
                front = back->next;
            } else {
                destinationIndex = largebin_index(size);
                back = bin_at(state, destinationIndex);
                front = back->next;
                if (front != back) {
                    size |= 1;
                    if (size <= back->previous->size) {
                        front = back;
                        back = back->previous;
                    } else {
                        while (size < front->size)
                            front = front->next;
                        back = front->previous;
                    }
                }
            }
            state->binmap[destinationIndex >> 5] |= 1u << (destinationIndex & 31);
            victim->previous = back;
            victim->next = front;
            front->previous = victim;
            back->next = victim;
        }

        if (requested >= 0x200) {
            bin = bin_at(state, index);
            victim = bin->previous;
            if (victim != bin && bin->next->size >= requested) {
                while ((size = victim->size & ~(hulk_uintptr)3) < requested)
                    victim = victim->previous;
                remainderSize = size - requested;
                front = victim->next;
                back = victim->previous;
                front->previous = back;
                back->next = front;
                if (remainderSize < Chunk::kMinSize) {
                    chunk_at(victim, size)->size |= 1;
                    return (char*)victim + Chunk::kHeader;
                }
                remainder = chunk_at(victim, requested);
                unsorted->previous = unsorted->next = remainder;
                remainder->previous = remainder->next = unsorted;
                victim->size = requested | 1;
                remainder->size = remainderSize | 1;
                chunk_at(remainder, remainderSize)->previousSize = remainderSize;
                return (char*)victim + Chunk::kHeader;
            }
        }

        ++index;
        bin = bin_at(state, index);
        unsigned block = index >> 5;
        unsigned map = (unsigned)state->binmap[block];
        unsigned bit = 1u << (index & 31);
        bool exhausted = false;
        for (;;) {
            if (bit > map || bit == 0) {
                do {
                    if (++block >= 4) {
                        exhausted = true;
                        break;
                    }
                } while ((map = (unsigned)state->binmap[block]) == 0);
                if (exhausted)
                    break;
                bin = bin_at(state, block << 5);
                bit = 1;
            }
            while ((bit & map) == 0) {
                bin = chunk_at(bin, Chunk::kHeader);
                bit <<= 1;
            }
            victim = bin->previous;
            if (victim == bin) {
                map &= ~bit;
                state->binmap[block] = map;
                bin = chunk_at(bin, Chunk::kHeader);
                bit <<= 1;
                continue;
            }

            size = victim->size & ~(hulk_uintptr)3;
            remainderSize = size - requested;
            back = victim->previous;
            bin->previous = back;
            back->next = bin;
            if (remainderSize < Chunk::kMinSize) {
                chunk_at(victim, size)->size |= 1;
                return (char*)victim + Chunk::kHeader;
            }
            remainder = chunk_at(victim, requested);
            unsorted->previous = unsorted->next = remainder;
            remainder->previous = remainder->next = unsorted;
            if (requested < 0x200)
                state->lastRemainder = remainder;
            victim->size = requested | 1;
            remainder->size = remainderSize | 1;
            chunk_at(remainder, remainderSize)->previousSize = remainderSize;
            return (char*)victim + Chunk::kHeader;
        }

        victim = state->top;
        size = victim->size & ~(hulk_uintptr)3;
        if (size >= requested + Chunk::kMinSize) {
            remainderSize = size - requested;
            remainder = chunk_at(victim, requested);
            state->top = remainder;
            victim->size = requested | 1;
            remainder->size = remainderSize | 1;
            return (char*)victim + Chunk::kHeader;
        }
        if (state->maxFast & 1)
            return FUN_0026be70((MState *)state, (unsigned)requested);
        FUN_0026b970((MState *)state);
        index = (unsigned)(requested >> 3);
    }
}


// 0x0026c6a0 FUN_0026c6a0 (287 B): equivalent/0x0026c6a0.cpp
// sym: _FUN_0026c6a0 @c37886df9ec0 @wf51b7c929c81
// STATUS: equivalent (tools/equiv.py level 3: 2575 inputs, branch coverage 25/26, incomplete)
// FUN_0026c6a0 @ 0x0026c6a0
extern "C" void* __cdecl FUN_0026c6a0(unsigned int alignment, unsigned int size)
{
    if (alignment <= DlHeapChunk::kAlign)
        return FUN_0026c040(size);
    if (alignment < DlHeapChunk::kMinSize)
        alignment = DlHeapChunk::kMinSize;
    if (alignment & (alignment - 1)) {
        uint32_26c6a0 power = DlHeapChunk::kMinSize;
        while (power < alignment)
            power <<= 1;
        alignment = power;
    }
    if ((hulk_uintptr)size >= (hulk_uintptr)-(hulk_intptr)(2 * DlHeapChunk::kMinSize))
        return 0;
    hulk_uintptr rounded = (hulk_uintptr)size + DlHeapChunk::kWord + DlHeapChunk::kAlignMask;
    if (rounded < DlHeapChunk::kMinSize)
        rounded = DlHeapChunk::kMinSize;
    else
        rounded &= ~(hulk_uintptr)DlHeapChunk::kAlignMask;
    char* allocation = (char*)FUN_0026c040((uint32_26c6a0)(alignment + rounded + DlHeapChunk::kMinSize));
    if (!allocation)
        return 0;
    DlHeapChunk* initial = (DlHeapChunk*)(allocation - DlHeapChunk::kHeader);
    DlHeapChunk* chunk = initial;
    if (((hulk_uintptr)allocation % alignment) != 0) {
        chunk = (DlHeapChunk*)((((hulk_uintptr)allocation + alignment - 1) & ~(hulk_uintptr)(alignment - 1)) - DlHeapChunk::kHeader);
        if ((hulk_uintptr)((char*)chunk - (char*)initial) < DlHeapChunk::kMinSize)
            chunk = (DlHeapChunk*)((char*)chunk + alignment);
        hulk_uintptr distance = (hulk_uintptr)((char*)chunk - (char*)initial);
        hulk_uintptr remainder = (initial->size & ~(hulk_uintptr)3) - distance;
        if (initial->size & 2) {
            chunk->size = remainder | 2;
            chunk->previousSize = initial->previousSize + distance;
            return (char*)chunk + DlHeapChunk::kHeader;
        }
        chunk->size = remainder | 1;
        ((DlHeapChunk*)((char*)chunk + remainder))->size |= 1;
        initial->size = (initial->size & 1) | distance;
        FUN_0026bd80((char*)initial + DlHeapChunk::kHeader);
    }
    if (!(chunk->size & 2)) {
        hulk_uintptr chunkSize = chunk->size & ~(hulk_uintptr)3;
        if (chunkSize > rounded + DlHeapChunk::kMinSize) {
            ((DlHeapChunk*)((char*)chunk + rounded))->size = (chunkSize - rounded) | 1;
            chunk->size = (chunk->size & 1) | rounded;
            FUN_0026bd80((char*)chunk + rounded + DlHeapChunk::kHeader);
        }
    }
    return (char*)chunk + DlHeapChunk::kHeader;
}


// 0x0026c840 FUN_0026c840 (456 B): equivalent/0x0026c840.cpp
// sym: ?FUN_0026c840@fn_f2ae9c07@@YAPAPAXPAPAXIPBII@Z @81a7aedfd837 @w39f31da5b948
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 32/32)
// FUN_0026c840 @ 0x0026c840
// equiv-conv: FUN_0026c840 eax stack stack stack
void ** __cdecl FUN_0026c840(void **result, uint_26c840 count, const uint_26c840 *sizes, uint_26c840 flags)
{
    DlHeapState *state = (*(DlHeapState**)&DAT_0052839c);
    if (!(state->maxFast & 1)) FUN_0026b970((DlHeapState *)state);
    if (!count) {
        if (result) return result;
        return (void **)FUN_0026c040(0);
    }
    hulk_uintptr arraySize = 0;
    if (!result)
        arraySize = chunk_size_26c840((hulk_uintptr)count * sizeof(void *));
    hulk_uintptr uniform = 0, total = 0;
    if (flags & 1) {
        uniform = chunk_size_26c840(sizes[0]);
        total = uniform * count;
    } else {
        for (uint_26c840 i = 0; i != count; ++i)
            total += chunk_size_26c840(sizes[i]);
    }
    hulk_uintptr saved = state->mmapMax;
    state->mmapMax = 0;
    char *memory = (char *)FUN_0026c040((uint_26c840)(arraySize + total - DlHeapChunk::kAlignMask));
    (*(DlHeapState**)&DAT_0052839c)->mmapMax = saved;
    if (!memory) return 0;
    DlHeapChunk *block = (DlHeapChunk *)(memory - DlHeapChunk::kHeader);
    hulk_uintptr remaining = block->size & ~(hulk_uintptr)3;
    if (flags & 2) {
        hulk_uintptr len = remaining - arraySize - DlHeapChunk::kWord;
        for (hulk_uintptr j = 0; j != len; ++j) memory[j] = 0;
    }
    if (!result) {
        DlHeapChunk *arrayChunk = (DlHeapChunk *)((char *)block + total);
        arrayChunk->size = (remaining - total) | 1;
        result = (void **)((char *)arrayChunk + DlHeapChunk::kHeader);
        remaining = total;
    }
    result[0] = (char *)block + DlHeapChunk::kHeader;
    for (uint_26c840 k = 1; k != count; ++k) {
        hulk_uintptr n = uniform;
        if (!n)
            n = chunk_size_26c840(sizes[k-1]);
        block->size = n | 1;
        block = (DlHeapChunk *)((char *)block + n);
        remaining -= n;
        result[k] = (char *)block + DlHeapChunk::kHeader;
    }
    block->size = remaining | 1;
    return result;
}


// 0x0026ca80 FUN_0026ca80 (141 B): equivalent/0x0026ca80.cpp
// sym: ?FUN_0026ca80@MemoryDlAllocator_26ca80@fn_f2ae9c07@@QAEPAU12@HHPBD@Z @3cbbcb94e2ef @wc01ebda0bf70
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0026ca80 @ 0x0026ca80
// The dl allocator's constructor with an arena of `bytes` from heap `heapFrom` (0x0026cf20), which it owns. As
// 0x0026ce90: a member named by its address, the vftable stores spelled out.
// the vftables (slot 0 labels): core::IMemoryAllocator, core::Object, then core::MemoryDlAllocator's two
MemoryDlAllocator_26ca80* MemoryDlAllocator_26ca80::FUN_0026ca80(int bytes, int heapFrom, const char*) {
    vtable = DAT_0042aef4;
    vtableObject = DAT_0042afa8;
    heapId = DAT_004cdbb0;
    FUN_002705f0();
    vtable = DAT_0042b36c;
    vtableObject = DAT_0042b364;
    count = total = peak = 0;
    ownsArena = 1;
    inPlace = 0;
    refs = 0;
    FUN_002705f0();
    size = bytes;
    hulk_intptr arena = (hulk_intptr)FUN_00266e00(heapFrom, bytes);
    start = arena;
    brk = arena;
    end = size + arena;
    for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i)
        ((hulk_uintptr*)&heap)[i] = 0;
    return this;
}

} // namespace fn_f2ae9c07

// 0x0026cb10 core::MemoryDlAllocator::vfunc_0 (7 B): matches/0x0026cb10.cpp
// sym: ?vfunc_0@MemoryDlAllocator@core@@UAEXXZ
 // namespace core
void core::MemoryDlAllocator::vfunc_0() {
    ++this->f_4a0;
}


// 0x0026cb20 core::MemoryDlAllocator::vfunc_5 (28 B): matches/0x0026cb20.cpp
// sym: ?vfunc_5@MemoryDlAllocator@core@@UAE_NPAX@Z
 // namespace core
bool core::MemoryDlAllocator::vfunc_5(void* __p0) { hulk_uintptr p = (hulk_uintptr)__p0;

    if (p >= ((hulk_uintptr)this->f_0c) && p < ((hulk_uintptr)this->f_10) || p == 0)
        return true;
    return false;
}


// 0x0026cb40 core::MemoryDlAllocator::vfunc_8 (28 B): matches/0x0026cb40.cpp
// sym: ?vfunc_8@MemoryDlAllocator@core@@UAE_NPAX@Z
 // namespace core
bool core::MemoryDlAllocator::vfunc_8(void* __p0) { void * p = (void *)__p0;

    hulk_uintptr x = (hulk_uintptr)p;
    if (x < ((hulk_uintptr)this->f_0c) || x >= ((hulk_uintptr)this->f_10)) {
        if (x == 0)
            goto yes;
        return false;
    }
yes:
    return true;
}


// 0x0026cb60 core::MemoryDlAllocator::vfunc_9 (70 B): matches/0x0026cb60.cpp
// sym: ?vfunc_9@MemoryDlAllocator@core@@UAE_NPAX000@Z
bool core::MemoryDlAllocator::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * p1 = (int *)__p0; int * p2 = (int *)__p1; int * p3 = (int *)__p2; int * p4 = (int *)__p3;

    if (p1)
        *p1 = this->f_14 - this->f_494;
    if (p2)
        *p2 = 0;
    if (p3)
        *p3 = this->f_490;
    if (p4)
        *p4 = this->f_498;
    return true;
}


// 0x0026cbb0 core::MemoryDlAllocator::vfunc_10 (11 B): matches/0x0026cbb0.cpp
// sym: ?vfunc_10@MemoryDlAllocator@core@@UAEXXZ
void core::MemoryDlAllocator::vfunc_10() {
    this->f_498 = 0;
}


// 0x0026cbc0 core::MemoryDlAllocator::vfunc_11 (4 B): matches/0x0026cbc0.cpp
// sym: ?vfunc_11@MemoryDlAllocator@core@@UAEHXZ
// the arena size
int core::MemoryDlAllocator::vfunc_11() {
    return this->f_14;
}

namespace fn_f2ae9c07 {

// 0x0026cbd0 core::MemoryDlAllocator::vfunc_2 (36 B): matches/0x0026cbd0.cpp
// sym: ?f2@MemoryDlAllocator_26cbd0@fn_f2ae9c07@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
MemoryDlAllocator_26cbd0* MemoryDlAllocator_26cbd0::f2(u8_26cbd0 flag) {
    FUN_0026cc00();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}


// 0x0026cc00 FUN_0026cc00 (35 B): matches/0x0026cc00.cpp
// sym: ?FUN_0026cc00@MemoryDlAllocator_26cc00@fn_f2ae9c07@@QAEXXZ
void MemoryDlAllocator_26cc00::FUN_0026cc00() {
    vptr = ((hulk_intptr)DAT_0042b36c);
    vptr2 = ((hulk_intptr)DAT_0042b364);
    *(volatile u32_26cc00*)((hulk_intptr)((char*)&DAT_004cdbb0)) = member;
    vptr2 = ((hulk_intptr)DAT_0042af64);
    vptr = ((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f2ae9c07

// 0x0026cc30 core::MemoryDlAllocator::vfunc_0_adj4 (8 B): matches/0x0026cc30.cpp [wrapped: conflict: core::IMemoryAllocator; core::IRefCount; core::MemoryDlAllocator]
// sym: ?vfunc_2@MemoryDlAllocator@core@fn_0026cc30@@W3AEXI@Z
namespace fn_0026cc30 {
namespace core {
struct IMemoryAllocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned);
};
struct IRefCount {
    virtual void vfunc_2(unsigned);
};
struct __declspec(dllexport) MemoryDlAllocator : IMemoryAllocator, IRefCount {
    void vfunc_2(unsigned);
};
void MemoryDlAllocator::vfunc_2(unsigned flags) {
    IMemoryAllocator::vfunc_2(flags);
}
} // namespace core
} // namespace fn_0026cc30


// 0x0026cc40 core::MemoryDlAllocator::vfunc_1 (74 B): matches/0x0026cc40.cpp
// sym: ?vfunc_1@MemoryDlAllocator@core@@UAEXXZ
// Release: the last reference frees the arena if the allocator owns it (+0x49c), then deletes the allocator (slot 2
// with 1) or, when it sits in memory it does not own (+0x49d), only destroys it (slot 2 with 0)
void core::MemoryDlAllocator::vfunc_1() {
    if (f_4a0 == 1) {
        if (f_49c == 1)
            FUN_00267090(f_0c);
        if (f_49d == 0)
            ((Slots_26cc40*)this)->destroy(1);
        else
            ((Slots_26cc40*)this)->destroy(0);
    } else
        --f_4a0;
}


// 0x0026cc90 core::MemoryDlAllocator::vfunc_7 (122 B): equivalent/0x0026cc90.cpp [wrapped: conflict: core::MemoryDlAllocator]
// sym: ?vfunc_7@MemoryDlAllocator@core@fn_0026cc90@@UAEXPAX@Z @53c724b252f3 @w9ae627e2c29a
namespace fn_0026cc90 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_7 @ 0x0026cc90

namespace core {
struct MemoryDlAllocator {
    // +0x00 the vftable pointer (core::IMemoryAllocator)
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    unsigned int size;              // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    unsigned int count;             // +0x490 allocations
    unsigned int total;             // +0x494 bytes in use
    unsigned int peak;              // +0x498
    virtual void vfunc_7(void*);
};
}
extern "C++" __declspec(nothrow) void __cdecl FUN_0026bd80(void*);
void core::MemoryDlAllocator::vfunc_7(void* p) {
    if (!p) return;
    DAT_005283a0 = start;
    DAT_005283a8 = end;
    (*(hulk_intptr**)&DAT_005283ac) = &brk;
    DAT_005283a4 = size;
    (*(DlHeapState**)&DAT_0052839c) = &heap;
    total -= (unsigned int)(((hulk_uintptr*)p)[-1] & ~(hulk_uintptr)3);
    FUN_0026bd80(p);
    --count;
    if (!count) {
        brk = start;
        for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i) ((hulk_uintptr*)&heap)[i] = 0;
    }
}
} // namespace fn_0026cc90


// 0x0026cd10 core::MemoryDlAllocator::vfunc_4 (122 B): equivalent/0x0026cd10.cpp [wrapped: conflict: core::MemoryDlAllocator]
// sym: ?vfunc_4@MemoryDlAllocator@core@fn_0026cd10@@QAEXPAX@Z @5d073f11260f @w828d5c109f87
namespace fn_0026cd10 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_4 @ 0x0026cd10

namespace core {
struct MemoryDlAllocator {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    unsigned int size;              // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    unsigned int count;             // +0x490 allocations
    unsigned int total;             // +0x494 bytes in use
    unsigned int peak;              // +0x498
    void vfunc_4(void *p);
};
}
extern "C++" __declspec(nothrow) void __cdecl FUN_0026bd80(void *);
void core::MemoryDlAllocator::vfunc_4(void *p) {
    if (!p) return;
    DAT_005283a0 = start;
    DAT_005283a8 = end;
    (*(hulk_intptr**)&DAT_005283ac) = &brk;
    DAT_005283a4 = size;
    unsigned int used = (unsigned int)(((hulk_uintptr *)p)[-1] & ~(hulk_uintptr)3);
    (*(DlHeapState**)&DAT_0052839c) = &heap;
    total -= used;
    FUN_0026bd80(p);
    --count;
    if (count == 0) {
        brk = start;
        for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i) ((hulk_uintptr *)&heap)[i] = 0;
    }
}
} // namespace fn_0026cd10


// 0x0026cd90 core::MemoryDlAllocator::vfunc_3 (113 B): equivalent/0x0026cd90.cpp [wrapped: conflict: core::MemoryDlAllocator]
// sym: ?vfunc_3@MemoryDlAllocator@core@fn_0026cd90@@QAEPAXI@Z @36eabe02f459 @we53c7bb1992a
namespace fn_0026cd90 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_3 @ 0x0026cd90

namespace core {
struct MemoryDlAllocator {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    unsigned int size;              // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    unsigned int count;             // +0x490 allocations
    unsigned int total;             // +0x494 bytes in use
    unsigned int peak;              // +0x498
    void* vfunc_3(unsigned int size);
};
}
void* __cdecl FUN_0026c040(unsigned int size);
void* core::MemoryDlAllocator::vfunc_3(unsigned int bytes) {
    DAT_005283a0 = start;
    (*(DlHeapState**)&DAT_0052839c) = &heap;
    DAT_005283a8 = end;
    (*(hulk_intptr**)&DAT_005283ac) = &brk;
    DAT_005283a4 = size;
    void* result = FUN_0026c040(bytes);
    if (result) {
        unsigned int used = (unsigned int)(((hulk_uintptr*)result)[-1] & ~(hulk_uintptr)3);
        total += used;
        if (total > peak) peak = total;
        ++count;
    }
    return result;
}
} // namespace fn_0026cd90


// 0x0026ce10 core::MemoryDlAllocator::vfunc_6 (118 B): equivalent/0x0026ce10.cpp [wrapped: conflict: core::MemoryDlAllocator]
// sym: ?vfunc_6@MemoryDlAllocator@core@fn_0026ce10@@QAEPAXII@Z @832811b939e1 @wcb697461ce9b
namespace fn_0026ce10 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// core::MemoryDlAllocator::vfunc_6 @ 0x0026ce10

namespace core {
struct MemoryDlAllocator {
    void* vtable;                   // +0x00 core::IMemoryAllocator
    void* vtableObject;             // +0x04 core::Object
    int heapId;                     // +0x08
    hulk_intptr start;              // +0x0c the arena
    hulk_intptr end;                // +0x10
    unsigned int size;              // +0x14
    hulk_intptr brk;                // +0x18 the arena's break
    DlHeapState heap;               // +0x1c
    unsigned int count;             // +0x490 allocations
    unsigned int total;             // +0x494 bytes in use
    unsigned int peak;              // +0x498
    void* vfunc_6(unsigned int a, unsigned int b);
};
}
extern "C++" __declspec(nothrow) void * __cdecl FUN_0026c6a0(unsigned int, unsigned int);
void* core::MemoryDlAllocator::vfunc_6(unsigned int a, unsigned int b) {
    DAT_005283a0 = start;
    DAT_005283a8 = end;
    (*(DlHeapState**)&DAT_0052839c) = &heap;
    (*(hulk_intptr**)&DAT_005283ac) = &brk;
    DAT_005283a4 = size;
    void* p = FUN_0026c6a0(b, a);
    if (p) {
        total += (unsigned int)(((hulk_uintptr*)p)[-1] & ~(hulk_uintptr)3);
        if (total > peak) peak = total;
        ++count;
    }
    return p;
}
} // namespace fn_0026ce10

namespace fn_f2ae9c07 {

// 0x0026ce90 FUN_0026ce90 (132 B): equivalent/0x0026ce90.cpp
// sym: ?FUN_0026ce90@MemoryDlAllocator_26ce90@fn_f2ae9c07@@QAEPAU12@EPAXHPBD@Z @d7bfffd3dcdc @w4e65af28edb2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0026ce90 @ 0x0026ce90
// The dl allocator's constructor on memory the caller gives it (0x0026cfa0, 0x0026cf60): the arena is [base,
// base + size). Written as a member named by its address with the vftable stores spelled out, so that the 64-bit
// builds bind the callers' references by address and the object gets the game's vftables (include/gen/core.h's
// core::MemoryDlAllocator has the same layout).
// the vftables (slot 0 labels): core::IMemoryAllocator, core::Object, then core::MemoryDlAllocator's two
MemoryDlAllocator_26ce90* MemoryDlAllocator_26ce90::FUN_0026ce90(unsigned char mode, void* base, int bytes, const char*) {
    vtable = DAT_0042aef4;
    vtableObject = DAT_0042afa8;
    heapId = DAT_004cdbb0;
    FUN_002705f0();
    vtable = DAT_0042b36c;
    vtableObject = DAT_0042b364;
    count = total = peak = 0;
    ownsArena = 0;
    inPlace = mode;
    refs = 0;
    FUN_002705f0();
    start = (hulk_intptr)base;
    end = (hulk_intptr)base + bytes;
    size = bytes;
    brk = (hulk_intptr)base;
    for (unsigned int i = 0; i < sizeof(DlHeapState) / sizeof(hulk_uintptr); ++i)
        ((hulk_uintptr*)&heap)[i] = 0;
    return this;
}


// 0x0026cf20 FUN_0026cf20 (53 B): matches/0x0026cf20.cpp
// sym: _FUN_0026cf20
extern "C" void* __cdecl FUN_0026cf20(int bytes, int id, const char* name) {
    DAT_004cdbb0 = id;
    void* x = FUN_00266e00(id, sizeof(core::MemoryDlAllocator));
    if (x)
        return ((MemoryDlAllocator_nv_26cf20*)x)->FUN_0026ca80(bytes, id, name);
    return 0;
}

} // namespace fn_f2ae9c07
