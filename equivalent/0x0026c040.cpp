// STATUS: equivalent (tools/equiv.py level 3: 447 inputs, branch coverage 90/94, incomplete)
// FUN_0026c040 @ 0x0026c040
#include "decls/data/engine/core.h"

struct Chunk {
    unsigned prev_size;
    unsigned size;
    Chunk* fd;
    Chunk* bk;
};

struct MState {
    unsigned max_fast;
    Chunk* fastbins[10];
    Chunk* top;
    Chunk* last_remainder;
    Chunk* bins[256];
    unsigned binmap[4];
};

extern void __cdecl FUN_0026b970(MState* av);
// equiv-conv: FUN_0026be70 eax stack
extern void* FUN_0026be70(MState* av, unsigned nb);

static inline Chunk* bin_at(MState* av, unsigned index) {
    return (Chunk*)((char*)&av->bins[index * 2] - 8);
}

static inline Chunk* chunk_at(Chunk* chunk, unsigned offset) {
    return (Chunk*)((char*)chunk + offset);
}

static inline unsigned largebin_index(unsigned size) {
    if ((size >> 6) <= 32)
        return 56 + (size >> 6);
    if ((size >> 9) <= 20)
        return 91 + (size >> 9);
    if ((size >> 12) <= 10)
        return 110 + (size >> 12);
    if ((size >> 15) <= 4)
        return 119 + (size >> 15);
    if ((size >> 18) <= 2)
        return 124 + (size >> 18);
    return 126;
}

void* __cdecl FUN_0026c040(unsigned bytes) {
    if (bytes >= 0xffffffe0u)
        return 0;

    unsigned requested = bytes + 11 < 16 ? 16 : (bytes + 11) & ~7u;
    MState* state = *(MState**)&DAT_0052839c;
    Chunk* victim;
    Chunk* back;
    Chunk* front;
    Chunk* remainder;
    Chunk* bin;
    unsigned index;
    unsigned size;
    unsigned remainderSize;

    if (requested <= state->max_fast) {
        Chunk** fastbin = &state->fastbins[(requested >> 3) - 2];
        victim = *fastbin;
        if (victim) {
            *fastbin = victim->fd;
            return (char*)victim + 8;
        }
    }

    if (requested < 0x200) {
        index = requested >> 3;
        bin = bin_at(state, index);
        victim = bin->bk;
        if (victim != bin) {
            if (!victim) {
                FUN_0026b970(state);
            } else {
                back = victim->bk;
                chunk_at(victim, requested)->size |= 1;
                bin->bk = back;
                back->fd = bin;
                return (char*)victim + 8;
            }
        }
    } else {
        index = largebin_index(requested);
        if (!(state->max_fast & 1))
            FUN_0026b970(state);
    }

    for (;;) {
        Chunk* unsorted = bin_at(state, 1);
        while ((victim = unsorted->bk) != unsorted) {
            back = victim->bk;
            size = victim->size & ~3u;
            if (requested < 0x200 && back == unsorted && victim == state->last_remainder &&
                size > requested + 16) {
                remainderSize = size - requested;
                remainder = chunk_at(victim, requested);
                unsorted->bk = unsorted->fd = remainder;
                state->last_remainder = remainder;
                remainder->bk = remainder->fd = unsorted;
                victim->size = requested | 1;
                remainder->size = remainderSize | 1;
                chunk_at(remainder, remainderSize)->prev_size = remainderSize;
                return (char*)victim + 8;
            }

            unsorted->bk = back;
            back->fd = unsorted;
            if (size == requested) {
                chunk_at(victim, size)->size |= 1;
                return (char*)victim + 8;
            }

            unsigned destinationIndex;
            if (size < 0x200) {
                destinationIndex = size >> 3;
                back = bin_at(state, destinationIndex);
                front = back->fd;
            } else {
                destinationIndex = largebin_index(size);
                back = bin_at(state, destinationIndex);
                front = back->fd;
                if (front != back) {
                    size |= 1;
                    if (size <= back->bk->size) {
                        front = back;
                        back = back->bk;
                    } else {
                        while (size < front->size)
                            front = front->fd;
                        back = front->bk;
                    }
                }
            }
            state->binmap[destinationIndex >> 5] |= 1u << (destinationIndex & 31);
            victim->bk = back;
            victim->fd = front;
            front->bk = victim;
            back->fd = victim;
        }

        if (requested >= 0x200) {
            bin = bin_at(state, index);
            victim = bin->bk;
            if (victim != bin && bin->fd->size >= requested) {
                while ((size = victim->size & ~3u) < requested)
                    victim = victim->bk;
                remainderSize = size - requested;
                front = victim->fd;
                back = victim->bk;
                front->bk = back;
                back->fd = front;
                if (remainderSize < 16) {
                    chunk_at(victim, size)->size |= 1;
                    return (char*)victim + 8;
                }
                remainder = chunk_at(victim, requested);
                unsorted->bk = unsorted->fd = remainder;
                remainder->bk = remainder->fd = unsorted;
                victim->size = requested | 1;
                remainder->size = remainderSize | 1;
                chunk_at(remainder, remainderSize)->prev_size = remainderSize;
                return (char*)victim + 8;
            }
        }

        ++index;
        bin = bin_at(state, index);
        unsigned block = index >> 5;
        unsigned map = state->binmap[block];
        unsigned bit = 1u << (index & 31);
        bool exhausted = false;
        for (;;) {
            if (bit > map || bit == 0) {
                do {
                    if (++block >= 4) {
                        exhausted = true;
                        break;
                    }
                } while ((map = state->binmap[block]) == 0);
                if (exhausted)
                    break;
                bin = bin_at(state, block << 5);
                bit = 1;
            }
            while ((bit & map) == 0) {
                bin = chunk_at(bin, 8);
                bit <<= 1;
            }
            victim = bin->bk;
            if (victim == bin) {
                map &= ~bit;
                state->binmap[block] = map;
                bin = chunk_at(bin, 8);
                bit <<= 1;
                continue;
            }

            size = victim->size & ~3u;
            remainderSize = size - requested;
            back = victim->bk;
            bin->bk = back;
            back->fd = bin;
            if (remainderSize < 16) {
                chunk_at(victim, size)->size |= 1;
                return (char*)victim + 8;
            }
            remainder = chunk_at(victim, requested);
            unsorted->bk = unsorted->fd = remainder;
            remainder->bk = remainder->fd = unsorted;
            if (requested < 0x200)
                state->last_remainder = remainder;
            victim->size = requested | 1;
            remainder->size = remainderSize | 1;
            chunk_at(remainder, remainderSize)->prev_size = remainderSize;
            return (char*)victim + 8;
        }

        victim = state->top;
        size = victim->size & ~3u;
        if (size >= requested + 16) {
            remainderSize = size - requested;
            remainder = chunk_at(victim, requested);
            state->top = remainder;
            victim->size = requested | 1;
            remainder->size = remainderSize | 1;
            return (char*)victim + 8;
        }
        if (state->max_fast & 1)
            return FUN_0026be70(state, requested);
        FUN_0026b970(state);
        index = requested >> 3;
    }
}