// STATUS: equivalent (tools/equiv.py level 3: 714 inputs, branch coverage 92/94, incomplete)
// FUN_0026c040 @ 0x0026c040
// FUN_0026c040 @ 0x0026c040
// dlmalloc 2.7.0 malloc (mALLOc): the allocator's public entry
#include "decls/data/engine/core.h"

struct Chunk {
    unsigned prev_size;
    unsigned size;
    Chunk *fd;
    Chunk *bk;
};

struct MState {
    unsigned max_fast;       // 0x00, bit 0 set = no fast chunks
    Chunk *fastbins[10];     // 0x04
    Chunk *top;              // 0x2c
    Chunk *last_remainder;   // 0x30
    Chunk *bins[256];        // 0x34
    unsigned binmap[4];      // 0x434
};

extern void __cdecl FUN_0026b970(MState *av);
// equiv-conv: FUN_0026be70 eax stack
extern void *FUN_0026be70(MState *av, unsigned nb);

static inline Chunk *bin_at(MState *av, unsigned i)
{
    return (Chunk *)((char *)&av->bins[i * 2] - 8);
}

static inline Chunk *chunk_at(Chunk *p, unsigned off)
{
    return (Chunk *)((char *)p + off);
}

static inline unsigned largebin_index(unsigned sz)
{
    if ((sz >> 6) <= 32)
        return 56 + (sz >> 6);
    if ((sz >> 9) <= 20)
        return 91 + (sz >> 9);
    if ((sz >> 12) <= 10)
        return 110 + (sz >> 12);
    if ((sz >> 15) <= 4)
        return 119 + (sz >> 15);
    if ((sz >> 18) <= 2)
        return 124 + (sz >> 18);
    return 126;
}

void *__cdecl FUN_0026c040(unsigned bytes)
{
    MState *av;
    unsigned nb, idx, size, remainder_size, block, bit, map, victim_index;
    Chunk *victim, *bck, *fwd, *remainder, *bin;

    if (bytes >= 0xffffffe0u)
        return 0;
    nb = (bytes + 11 < 16) ? 16 : ((bytes + 11) & ~7u);
    av = (*(MState**)&DAT_0052839c);

    if (nb <= av->max_fast) {
        Chunk **fb = &av->fastbins[(nb >> 3) - 2];
        victim = *fb;
        if (victim != 0) {
            *fb = victim->fd;
            return (char *)victim + 8;
        }
    }

    if (nb < 0x200) {
        idx = nb >> 3;
        bin = bin_at(av, idx);
        victim = bin->bk;
        if (victim != bin) {
            if (victim == 0) {
                FUN_0026b970(av);
            } else {
                bck = victim->bk;
                chunk_at(victim, nb)->size |= 1;
                bin->bk = bck;
                bck->fd = bin;
                return (char *)victim + 8;
            }
        }
    } else {
        idx = largebin_index(nb);
        if (!(av->max_fast & 1))
            FUN_0026b970(av);
    }

    for (;;) {
        Chunk *unsorted = bin_at(av, 1);
        while ((victim = unsorted->bk) != unsorted) {
            bck = victim->bk;
            size = victim->size & ~3u;

            if (nb < 0x200 && bck == unsorted && victim == av->last_remainder && size > nb + 16) {
                remainder_size = size - nb;
                remainder = chunk_at(victim, nb);
                unsorted->bk = unsorted->fd = remainder;
                av->last_remainder = remainder;
                remainder->bk = remainder->fd = unsorted;
                victim->size = nb | 1;
                remainder->size = remainder_size | 1;
                chunk_at(remainder, remainder_size)->prev_size = remainder_size;
                return (char *)victim + 8;
            }

            unsorted->bk = bck;
            bck->fd = unsorted;

            if (size == nb) {
                chunk_at(victim, size)->size |= 1;
                return (char *)victim + 8;
            }

            if (size < 0x200) {
                victim_index = size >> 3;
                bck = bin_at(av, victim_index);
                fwd = bck->fd;
            } else {
                victim_index = largebin_index(size);
                bck = bin_at(av, victim_index);
                fwd = bck->fd;
                if (fwd != bck) {
                    size |= 1;
                    if (size <= bck->bk->size) {
                        fwd = bck;
                        bck = bck->bk;
                    } else {
                        while (size < fwd->size)
                            fwd = fwd->fd;
                        bck = fwd->bk;
                    }
                }
            }

            av->binmap[victim_index >> 5] |= 1u << (victim_index & 31);
            victim->bk = bck;
            victim->fd = fwd;
            fwd->bk = victim;
            bck->fd = victim;
        }

        if (nb >= 0x200) {
            bin = bin_at(av, idx);
            victim = bin->bk;
            if (victim != bin && bin->fd->size >= nb) {
                while ((size = victim->size & ~3u) < nb)
                    victim = victim->bk;
                remainder_size = size - nb;
                fwd = victim->fd;
                bck = victim->bk;
                fwd->bk = bck;
                bck->fd = fwd;
                if (remainder_size < 16) {
                    chunk_at(victim, size)->size |= 1;
                    return (char *)victim + 8;
                }
                remainder = chunk_at(victim, nb);
                unsorted->bk = unsorted->fd = remainder;
                remainder->bk = remainder->fd = unsorted;
                victim->size = nb | 1;
                remainder->size = remainder_size | 1;
                chunk_at(remainder, remainder_size)->prev_size = remainder_size;
                return (char *)victim + 8;
            }
        }

        ++idx;
        bin = bin_at(av, idx);
        block = idx >> 5;
        map = av->binmap[block];
        bit = 1u << (idx & 31);

        for (;;) {
            if (bit > map || bit == 0) {
                do {
                    if (++block >= 4)
                        goto use_top;
                } while ((map = av->binmap[block]) == 0);
                bin = bin_at(av, block << 5);
                bit = 1;
            }
            while ((bit & map) == 0) {
                bin = chunk_at(bin, 8);
                bit <<= 1;
            }
            victim = bin->bk;
            if (victim == bin) {
                map &= ~bit;
                av->binmap[block] = map;
                bin = chunk_at(bin, 8);
                bit <<= 1;
            } else {
                size = victim->size & ~3u;
                remainder_size = size - nb;
                bck = victim->bk;
                bin->bk = bck;
                bck->fd = bin;
                if (remainder_size < 16) {
                    chunk_at(victim, size)->size |= 1;
                    return (char *)victim + 8;
                }
                remainder = chunk_at(victim, nb);
                unsorted->bk = unsorted->fd = remainder;
                remainder->bk = remainder->fd = unsorted;
                if (nb < 0x200)
                    av->last_remainder = remainder;
                victim->size = nb | 1;
                remainder->size = remainder_size | 1;
                chunk_at(remainder, remainder_size)->prev_size = remainder_size;
                return (char *)victim + 8;
            }
        }

    use_top:
        victim = av->top;
        size = victim->size & ~3u;
        if (size >= nb + 16) {
            remainder_size = size - nb;
            remainder = chunk_at(victim, nb);
            av->top = remainder;
            victim->size = nb | 1;
            remainder->size = remainder_size | 1;
            return (char *)victim + 8;
        }
        if (av->max_fast & 1)
            return FUN_0026be70(av, nb);
        FUN_0026b970(av);
        idx = nb >> 3;
    }
}
