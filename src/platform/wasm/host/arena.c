/* The game's memory outside its image: a fixed region of linear memory with its own allocator (after the owner's
 * fusion-frenzy port, port/host/arena.c).
 *
 * Everything the game is handed and keeps a pointer to comes from here. The region's place doesn't depend on the
 * host's code (Emscripten's own data, stack and heap are above it: GLOBAL_BASE), and the allocator is first fit in
 * address order, so the same calls give the same addresses whatever the host's own allocations do. Its state is in
 * the sim block (sim.h). Blocks: a 16-byte header { size (with the header), flags, the previous block's size, 0 }
 * before each payload; free blocks merge with free neighbours; an aligned payload gets a second header just before
 * it that points back to the real one. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hulk_host.h"
#include "sim.h"

#define NK 64                           /* sizes 16..1024 have exact bounds (arena_lbn) */

#define BASE ARENA_LO
#define END ARENA_HI
#define USED 0x55534544u                /* "USED" */
#define FREE 0x46524545u                /* "FREE" */
#define ALIAS 0x414c4941u               /* an aligned payload's back pointer */

typedef struct { uint32_t size, flags, prev, back; } hdr;

static hdr* at(uint32_t a) { return (hdr*)(uintptr_t)a; }

/* the allocator's own state (whether the region is set up, its top) is in the sim block (sim.h): a snapshot is the
 * region up to the top, which is where memory the game's timeline has touched ends */
static void init(void) {
    hdr* h = at(BASE);
    h->size = END - BASE;
    h->flags = FREE;
    h->prev = 0;
    h->back = 0;
    SIM->arena_ready = 1;
    SIM->arena_top = BASE + 16;
    for (int k = 0; k < 32; k++) SIM->arena_lb[k] = BASE;
    for (int k = 0; k <= NK; k++) SIM->arena_lbn[k] = BASE;
}

/* the size class of a block size: its bit length less one (2^k <= size) */
static int size_class(uint32_t size) { return 31 - __builtin_clz(size); }

/* a free block of SIZE bytes at A: it lowers the bound of every class it belongs to */
static void lower_bounds(uint32_t a, uint32_t size) {
    for (int k = size_class(size); k >= 0; k--)
        if (SIM->arena_lb[k] > a) SIM->arena_lb[k] = a;
    for (int k = size >> 4 < NK ? size >> 4 : NK; k >= 1; k--)
        if (SIM->arena_lbn[k] > a) SIM->arena_lbn[k] = a;
}

/* the block at FROM merges into the one at INTO: a bound on FROM moves there (a bound is a block's start) */
static void move_bounds(uint32_t from, uint32_t into) {
    for (int k = 0; k < 32; k++)
        if (SIM->arena_lb[k] == from) SIM->arena_lb[k] = into;
    for (int k = 1; k <= NK; k++)
        if (SIM->arena_lbn[k] == from) SIM->arena_lbn[k] = into;
}

uint32_t ff_arena_base(void) { return BASE; }
uint32_t ff_arena_top(void) { return SIM->arena_top ? SIM->arena_top : BASE; }

static uint32_t real_block(void* p) {
    hdr* h = (hdr*)p - 1;
    if (h->flags == ALIAS) return h->back;
    return (uint32_t)(uintptr_t)h;
}

void* ff_arena_alloc(uint32_t n, uint32_t align) {
    if (!SIM->arena_ready) init();
    if (align < 16) align = 16;
    uint32_t need = ((n + 15) & ~15u) + 16 + (align > 16 ? align : 0);
    /* first fit in address order (wasm14: the scan from the base was 30% of a play3 run). It starts at the bound of
     * NEED's size class: below it no free block is as large as 2^class, so none fits. The first free block of the
     * class met becomes the class's bound. */
    int c = size_class(need);
    /* (wasm15) a size up to 1 KB starts at its own bound (arena_lbn: exact sizes, not classes), which an allocation
     * moves to the block it takes: still first fit in address order, with fewer used blocks walked over */
    uint32_t kn = need >> 4;
    uint32_t start = kn <= NK ? SIM->arena_lbn[kn] : SIM->arena_lb[c];
    uint32_t first = 0;
    for (uint32_t a = start ? start : BASE; a < END; a += at(a)->size) {
        hdr* h = at(a);
        if (h->size < 16 || (h->flags != FREE && h->flags != USED))
            ff_fatal("game arena corrupt at 0x%08x (size %u, flags %08x)", a, h->size, h->flags);
        if (h->flags == FREE && !first && size_class(h->size) >= c) first = a;
        if (h->flags != FREE || h->size < need) continue;
        if (kn <= NK) {
            for (uint32_t k = kn; k <= NK; k++)     /* below a, no free block of NEED bytes or more */
                if (SIM->arena_lbn[k] < a) SIM->arena_lbn[k] = a;
        } else {
            SIM->arena_lb[c] = first;
        }
        if (h->size >= need + 64) {                 /* split: the rest stays free */
            hdr* r = at(a + need);
            r->size = h->size - need;
            r->flags = FREE;
            r->prev = need;
            r->back = 0;
            if (a + h->size < END) at(a + h->size)->prev = r->size;
            h->size = need;
            if (a + need + 16 > SIM->arena_top) SIM->arena_top = a + need + 16;
        }
        if (a + h->size > SIM->arena_top) SIM->arena_top = a + h->size < END ? a + h->size : END;
        h->flags = USED;
        uint32_t p = a + 16;
        if (align > 16) {
            uint32_t q = (p + 16 + align - 1) & ~(align - 1);     /* room for the alias header before it */
            hdr* alias = at(q) - 1;
            alias->flags = ALIAS;
            alias->back = a;
            p = q;
        }
        memset((void*)(uintptr_t)p, 0, n);
        return (void*)(uintptr_t)p;
    }
    fprintf(stderr, "hulk: game arena out of memory (wanted %u bytes)\n", n);
    static int shown;
    if (!shown++) {
        uint32_t used = 0, nused = 0, big[8] = {0};
        for (uint32_t a = BASE; a < END; a += at(a)->size)
            if (at(a)->flags == USED) {
                used += at(a)->size;
                nused++;
                for (int k = 0; k < 8; k++)
                    if (at(a)->size > big[k]) { memmove(big + k + 1, big + k, (7 - k) * 4); big[k] = at(a)->size; break; }
            }
        fprintf(stderr, "hulk: arena: %u blocks, %u bytes used; largest %u %u %u %u %u %u %u %u\n", nused, used, big[0],
                big[1], big[2], big[3], big[4], big[5], big[6], big[7]);
    }
    return NULL;
}

void ff_arena_free(void* p) {
    if (!p) return;
    uint32_t a = real_block(p);
    hdr* h = at(a);
    if (h->flags != USED) {
        fprintf(stderr, "hulk: arena free of 0x%08x, not an allocation\n", (uint32_t)(uintptr_t)p);
        abort();
    }
    h->flags = FREE;
    uint32_t next = a + h->size;
    if (next < END && at(next)->flags == FREE) {    /* merge the next block */
        move_bounds(next, a);
        h->size += at(next)->size;
        if (a + h->size < END) at(a + h->size)->prev = h->size;
    }
    if (h->prev && at(a - h->prev)->flags == FREE) {     /* merge into the previous one */
        hdr* q = at(a - h->prev);
        move_bounds(a, a - h->prev);
        q->size += h->size;
        if (a - h->prev + q->size < END) at(a - h->prev + q->size)->prev = q->size;
        lower_bounds(a - h->prev, q->size);
        return;
    }
    lower_bounds(a, h->size);
}

uint32_t ff_arena_usable(void* p) {
    uint32_t a = real_block(p);
    return at(a)->size - ((uint32_t)(uintptr_t)p - a);
}

void* ff_arena_realloc(void* p, uint32_t n) {
    if (!p) return ff_arena_alloc(n, 16);
    uint32_t have = ff_arena_usable(p);
    if (n <= have) return p;
    void* q = ff_arena_alloc(n, 16);
    if (q) {
        memcpy(q, p, have);
        ff_arena_free(p);
    }
    return q;
}
