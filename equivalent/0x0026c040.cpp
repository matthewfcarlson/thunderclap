// STATUS: equivalent (tools/equiv.py level 3: 680 inputs, branch coverage 93/94, incomplete)
// FUN_0026c040 @ 0x0026c040
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

typedef DlHeapChunk Chunk;
typedef DlHeapState MState;

extern "C" void __cdecl FUN_0026b970(void *);
// equiv-conv: FUN_0026be70 eax stack
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