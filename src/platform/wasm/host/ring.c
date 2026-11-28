/* The rollback ring (wroll2, D253; docs/multiplayer.md §21): keyframes of the whole game state in memory, cheap
 * enough to keep 30 frames of rollback.
 *
 * A keyframe is the state sched.c's snapshots copy (state_copy: the image's data, the main stack and the sim block,
 * the module's hulk_game_state and, with a renderer, hulk_pddi_state, the arena up to its top) plus the host state
 * outside those ranges that the game reads (the replay's and lockstep I/O's blobs, the fiber to run next), taken at a
 * frame end where every fiber is suspended (sched.c ff_frame_checkpoint). The state is cut into 4 KB pages. A page
 * that is the same as in the previous keyframe is shared with it (a reference to the same stored page), so a
 * keyframe costs one pass comparing the state with the previous keyframe plus a copy of the pages that changed; an
 * all-zero page is stored as nothing. A restore copies the keyframe's pages back (the whole state: no tracking of
 * what changed since). The ring keeps a keyframe every K frames (HULK_RING_EVERY or the caller's choice), and a
 * rollback to frame F restores the newest keyframe at or before F and resimulates from it with the frames' inputs:
 * at most K-1 frames more than a keyframe every frame would, for a fraction of the copies.
 *
 * The pages live in the module's own heap (above 1 GB; host memory, outside the game state). Pages are kept in fixed
 * order: the fixed ranges first, the arena last (its length moves with its top), so page i is the same address in
 * every keyframe.
 *
 * Measurement and tests, all off unless named:
 *   HULK_RINGSTAT=1          a keyframe every frame, no restores: per frame the pages and bytes that changed since 1,
 *                            3, 5, 10 and 30 frames ago, by region (image data, stacks live/dead, sim block, module and
 *                            pddi sections, the dl heaps, audio voices, the rest of the arena), the save's time and the
 *                            ring's memory; a summary at the end of the run (or at HULK_RINGSTAT_UNTIL)
 *   HULK_RINGSTAT_DUMP=P:A:B  (with RINGSTAT) the changed pages of frames A..B XORed with their previous version, to
 *                            P.F (offline compression measurements: build/ only, game-derived)
 *   HULK_ROLLDEEP=A:B:D[:K]  from frame A to B, at every frame's end roll back D frames (to the newest keyframe at or
 *                            before F-D; keyframes every K frames, default 5) and resimulate to F: the game, module and
 *                            pddi hashes at F must be the first pass's ("rolldeep: ... identical"; a difference exits 3).
 *                            While resimulating, replay records and log lines are not written again (ff_ring_resim). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hulk_host.h"
#include "sim.h"
#include "hulk_io.h"

#define PAGE 4096u
#define ZERO_PAGE 0xffffffffu
#define MAIN_STACK_LO 0x00E00000u
#define MAIN_STACK_HI 0x00F00000u
#define DATA_LO 0x0048ca80u

/* sched.c */
uint32_t ff_sched_next(void);
void ff_sched_set_next(uint32_t f);
int ff_stack_ranges(uint32_t* out, int cap);
uint32_t ff_sched_dead_ranges(uint32_t* out, int cap);
uint32_t ff_module_state(uint32_t* lo);
uint32_t ff_gfx_state(uint32_t* lo) __attribute__((weak));
uint32_t ff_replay_blob(void* buf, int restore);
uint32_t ff_io_blob(void* buf, int restore);
void ff_files_flush(void);
void ff_audio_restored(void) __attribute__((weak));
void ff_movie_restored(void) __attribute__((weak));
void ff_gfx_restored(void) __attribute__((weak));
uint64_t ff_gfx_hash(void) __attribute__((weak));
uint64_t ff_module_hash(void);
uint32_t ff_replay_frame(void);         /* replay.cpp: GameClock::Update calls so far */

/* ------------------------------------------------------------------------------------------- the ranges */
typedef struct { uint32_t lo, n; } range;
/* the fixed ranges, then the arena; returns their count (5) */
static int state_ranges(range r[5], uint32_t top) {
    uint32_t lo;
    r[0].lo = DATA_LO, r[0].n = XBE_END - DATA_LO;
    r[1].lo = MAIN_STACK_LO, r[1].n = MAIN_STACK_HI - MAIN_STACK_LO + (uint32_t)sizeof(hulk_sim);
    r[2].n = ff_gfx_state ? ff_gfx_state(&lo) : 0, r[2].lo = r[2].n ? lo : 0;
    r[3].n = ff_module_state(&lo), r[3].lo = lo;
    r[4].lo = ARENA_LO, r[4].n = top - ARENA_LO;
    return 5;
}
static uint32_t pages_of(uint32_t n) { return (n + PAGE - 1) / PAGE; }

/* ------------------------------------------------------------------------------------------- the page store */
static uint8_t** slabs;                 /* 256 pages a slab */
static uint32_t* refs;                  /* by page handle */
static uint32_t n_handles, free_head = ZERO_PAGE, *free_next, pages_used, pages_peak;
static uint8_t* page_mem(uint32_t h) { return slabs[h >> 8] + (size_t)(h & 255) * PAGE; }
static uint32_t page_new(void) {
    if (free_head == ZERO_PAGE) {
        uint32_t s = n_handles >> 8;
        slabs = realloc(slabs, (s + 1) * sizeof *slabs);
        refs = realloc(refs, (n_handles + 256) * sizeof *refs);
        free_next = realloc(free_next, (n_handles + 256) * sizeof *free_next);
        slabs[s] = malloc(256 * PAGE);
        if (!slabs[s] || !refs || !free_next) ff_fatal("ring: out of memory (%u pages)", pages_used);
        for (uint32_t i = 0; i < 256; i++) free_next[n_handles + i] = i + 1 < 256 ? n_handles + i + 1 : ZERO_PAGE;
        free_head = n_handles;
        n_handles += 256;
    }
    uint32_t h = free_head;
    free_head = free_next[h];
    refs[h] = 1;
    if (++pages_used > pages_peak) pages_peak = pages_used;
    return h;
}
static void page_unref(uint32_t h) {
    if (h == ZERO_PAGE || --refs[h]) return;
    free_next[h] = free_head;
    free_head = h;
    pages_used--;
}
/* (word compares: the C library's memcmp is a byte loop in the module) */
static int same(const uint8_t* a, const uint8_t* b, uint32_t n) {
    if (n == PAGE) {
        const uint64_t *x = (const uint64_t*)a, *y = (const uint64_t*)b;
        for (uint32_t i = 0; i < PAGE / 8; i += 8) {
            uint64_t d = (x[i] ^ y[i]) | (x[i + 1] ^ y[i + 1]) | (x[i + 2] ^ y[i + 2]) | (x[i + 3] ^ y[i + 3]) |
                         (x[i + 4] ^ y[i + 4]) | (x[i + 5] ^ y[i + 5]) | (x[i + 6] ^ y[i + 6]) | (x[i + 7] ^ y[i + 7]);
            if (d) return 0;
        }
        return 1;
    }
    return !memcmp(a, b, n);
}
static int all_zero(const uint8_t* a, uint32_t n) {
    if (n == PAGE) {
        const uint64_t* x = (const uint64_t*)a;
        for (uint32_t i = 0; i < PAGE / 8; i += 8)
            if (x[i] | x[i + 1] | x[i + 2] | x[i + 3] | x[i + 4] | x[i + 5] | x[i + 6] | x[i + 7]) return 0;
        return 1;
    }
    for (uint32_t i = 0; i < n; i++)
        if (a[i]) return 0;
    return 1;
}

/* ------------------------------------------------------------------------------------------- keyframes */
#define BLOB 8192
typedef struct {
    int valid;
    uint32_t frame, top, next, npages;
    uint32_t* page;                     /* handles, in range order */
    uint32_t blob_n[2];
    uint8_t blob[2][BLOB];
    uint32_t changed;                   /* pages stored new at the save (statistics) */
} keyframe;
static keyframe* ring;
static int ring_n;
static int resim;
int ff_ring_resim(void) { return resim; }

static void kf_clear(keyframe* k) {
    for (uint32_t i = 0; i < k->npages; i++) page_unref(k->page[i]);
    free(k->page);
    k->page = 0;
    k->npages = 0;
    k->valid = 0;
}
/* the newest valid keyframe before FRAME (the base a save compares with) */
static keyframe* kf_before(uint32_t frame) {
    keyframe* b = 0;
    for (int i = 0; i < ring_n; i++)
        if (ring[i].valid && ring[i].frame < frame && (!b || ring[i].frame > b->frame)) b = &ring[i];
    return b;
}
static keyframe* kf_at_or_before(uint32_t frame) {
    keyframe* b = 0;
    for (int i = 0; i < ring_n; i++)
        if (ring[i].valid && ring[i].frame <= frame && (!b || ring[i].frame > b->frame)) b = &ring[i];
    return b;
}

void ff_ring_config(int slots) {
    for (int i = 0; i < ring_n; i++) kf_clear(&ring[i]);
    free(ring);
    ring = 0;
    ring_n = slots > 0 ? slots : 0;
    if (!ring_n) return;
    ring = calloc((size_t)ring_n, sizeof *ring);
    if (!ring) ff_fatal("ring: out of memory");
}
/* the keyframes after FRAME are another timeline's (after a rollback to FRAME) */
void ff_ring_forget_after(uint32_t frame) {
    for (int i = 0; i < ring_n; i++)
        if (ring[i].valid && ring[i].frame > frame) kf_clear(&ring[i]);
}

/* per-page statistics of the last save (RINGSTAT): the page's byte changes against the base */
static uint8_t* stat_bytes_on;
static uint64_t stat_bytes;
static uint32_t* stat_changed_idx;
static uint32_t stat_nchanged, stat_cap;
static const char* dump_prefix;
static uint32_t dump_a, dump_b;

/* a keyframe of the current state at SIM->frame (a frame-end switch: sched.c's next fiber is set) */
int ff_ring_save(void) {
    if (!ring_n || !ff_sched_next()) return 0;
    uint32_t frame = SIM->frame;
    keyframe* base = kf_before(frame);
    keyframe* k = 0;
    for (int i = 0; i < ring_n; i++)
        if (ring[i].valid && ring[i].frame == frame) k = &ring[i];
    if (!k)
        for (int i = 0; i < ring_n; i++)
            if (!ring[i].valid) { k = &ring[i]; break; }
    if (!k) {                           /* the oldest */
        k = &ring[0];
        for (int i = 1; i < ring_n; i++)
            if (ring[i].frame < k->frame) k = &ring[i];
    }
    if (k == base) base = 0;
    range r[5];
    uint32_t top = ff_arena_top();
    state_ranges(r, top);
    uint32_t np = 0;
    for (int i = 0; i < 5; i++) np += pages_of(r[i].n);
    uint32_t* old = k->valid ? k->page : 0;
    uint32_t old_n = k->valid ? k->npages : 0;
    uint32_t* pg = malloc((size_t)np * sizeof *pg);
    if (!pg) ff_fatal("ring: out of memory");
    uint32_t idx = 0, changed = 0;
    stat_nchanged = 0;
    int32_t dump = -1;
    uint32_t dump_off = 0;
    if (dump_prefix && frame >= dump_a && frame <= dump_b && base) {
        char path[512];
        snprintf(path, sizeof path, "%s.%u", dump_prefix, frame);
        dump = hio_open(path, HIO_CREATE);
    }
    for (int i = 0; i < 5; i++)
        for (uint32_t off = 0; off < r[i].n; off += PAGE, idx++) {
            uint32_t n = r[i].n - off < PAGE ? r[i].n - off : PAGE;
            const uint8_t* live = PTR(r[i].lo + off);
            uint32_t b = base && idx < base->npages ? base->page[idx] : ZERO_PAGE - 1;
            uint32_t h;
            if (b == ZERO_PAGE && all_zero(live, n)) h = ZERO_PAGE;
            else if (b != ZERO_PAGE && b != ZERO_PAGE - 1 && same(live, page_mem(b), n)) {
                h = b;
                refs[h]++;
            } else if (b == ZERO_PAGE - 1 && all_zero(live, n)) {
                h = ZERO_PAGE;
                changed++;
            } else {
                h = page_new();
                memcpy(page_mem(h), live, n);
                changed++;
                if (stat_bytes_on || dump >= 0) {
                    static const uint8_t zero[PAGE];
                    const uint8_t* was = b == ZERO_PAGE || b == ZERO_PAGE - 1 ? zero : page_mem(b);
                    if (stat_bytes_on)
                        for (uint32_t j = 0; j < n; j++) stat_bytes += live[j] != was[j];
                    if (dump >= 0) {
                        uint8_t x[PAGE];
                        memset(x, 0, sizeof x);
                        for (uint32_t j = 0; j < n; j++) x[j] = live[j] ^ was[j];
                        dump_off += (uint32_t)hio_write(dump, &idx, 4, dump_off);
                        dump_off += (uint32_t)hio_write(dump, x, PAGE, dump_off);
                    }
                }
                if (stat_bytes_on) {
                    if (stat_nchanged == stat_cap)
                        stat_cap = stat_cap ? 2 * stat_cap : 4096,
                        stat_changed_idx = realloc(stat_changed_idx, stat_cap * sizeof *stat_changed_idx);
                    stat_changed_idx[stat_nchanged++] = idx;
                }
            }
            pg[idx] = h;
        }
    if (dump >= 0) hio_close(dump);
    for (uint32_t i = 0; i < old_n; i++) page_unref(old[i]);
    free(old);
    k->page = pg;
    k->npages = np;
    k->valid = 1;
    k->frame = frame;
    k->top = top;
    k->next = ff_sched_next();
    k->blob_n[0] = ff_replay_blob(k->blob[0], 0);
    k->blob_n[1] = ff_io_blob(k->blob[1], 0);
    k->changed = changed;
    return 1;
}

/* the newest keyframe at or before FRAME back in place; returns its frame, or -1 when the ring has none */
long ff_ring_restore(uint32_t frame) {
    keyframe* k = kf_at_or_before(frame);
    if (!k) return -1;
    range r[5];
    state_ranges(r, k->top);
    uint32_t idx = 0;
    for (int i = 0; i < 5; i++)
        for (uint32_t off = 0; off < r[i].n; off += PAGE, idx++) {
            uint32_t n = r[i].n - off < PAGE ? r[i].n - off : PAGE;
            uint8_t* live = PTR(r[i].lo + off);
            uint32_t h = k->page[idx];
            if (h == ZERO_PAGE) memset(live, 0, n);
            else memcpy(live, page_mem(h), n);
        }
    ff_replay_blob(k->blob[0], 1);
    ff_io_blob(k->blob[1], 1);
    ff_sched_set_next(k->next);
    ff_files_flush();
    if (ff_audio_restored) ff_audio_restored();
    if (ff_movie_restored) ff_movie_restored();
    if (ff_gfx_restored) ff_gfx_restored();
    return k->frame;
}
uint64_t ff_ring_bytes(void) { return (uint64_t)pages_used * PAGE; }

/* ------------------------------------------------------------------------------------------- hashes */
/* the game hash's bytes (frame.c ff_game_hash: the state without the stacks and Asyncify buffers), hashed by words */
static uint64_t mix(uint64_t h, uint64_t v) {
    h ^= v * 0x9e3779b97f4a7c15ull;
    return (h << 27 | h >> 37) * 0xff51afd7ed558ccdull;
}
static uint64_t hash_bytes(uint64_t h, uint32_t lo, uint32_t hi) {
    while (lo < hi && (lo & 7)) h = mix(h, *(uint8_t*)PTR(lo)), lo++;
    for (; lo + 8 <= hi; lo += 8) h = mix(h, *(uint64_t*)PTR(lo));
    while (lo < hi) h = mix(h, *(uint8_t*)PTR(lo)), lo++;
    return h;
}
static int by_lo(const void* a, const void* b) {
    uint32_t x = *(const uint32_t*)a, y = *(const uint32_t*)b;
    return (x > y) - (x < y);
}
static uint64_t fast_game_hash(void) {
    static uint32_t r[2 * 512];
    int n = ff_stack_ranges(r, 512);
    qsort(r, n, 8, by_lo);
    uint64_t h = hash_bytes(1, DATA_LO, XBE_END);
    h = hash_bytes(h, SIM_ADDR, SIM_ADDR + (uint32_t)sizeof(hulk_sim));
    uint32_t at = ARENA_LO, top = ff_arena_top();
    for (int i = 0; i < n; i++) {
        uint32_t lo = r[2 * i] < top ? r[2 * i] : top;
        if (lo > at) h = hash_bytes(h, at, lo);
        if (r[2 * i + 1] > at) at = r[2 * i + 1];
    }
    if (top > at) h = hash_bytes(h, at, top);
    return h;
}

/* ------------------------------------------------------------------------------------------- RINGSTAT */
enum { C_DATA, C_STACK_LIVE, C_STACK_DEAD, C_SIM, C_PDDI, C_MODULE, C_HEAP, C_AUDIO, C_ARENA, NC };
static const char* cname[NC] = {"image", "stack", "deadstk", "sim", "pddi", "module", "heaps", "audio", "arena"};
#define NDEP 5
static const int depth[NDEP] = {1, 3, 5, 10, 30};
#define HEAP_SLOTS 0x00527c60u
#define DL_VFTABLE 0x0042b36cu
static uint8_t* cls;
static uint32_t cls_cap;
static uint64_t sum_pages[NDEP][NC], sum_frames, sum_bytes1, max_pages[NDEP];
static uint32_t max_frame[NDEP];
static double sum_save_ms, max_save_ms;
static uint32_t hist1[16];              /* pages changed in one frame: <64, <128, ... by 64 */
static uint32_t rd(uint32_t a) { return *(uint32_t*)PTR(a); }
static void mark(uint32_t lo, uint32_t hi, int c, uint32_t np, uint32_t arena_page0) {
    if (hi <= lo || lo < ARENA_LO) return;
    uint32_t a = arena_page0 + (lo - ARENA_LO) / PAGE, b = arena_page0 + (hi - ARENA_LO + PAGE - 1) / PAGE;
    for (uint32_t i = a; i < b && i < np; i++) cls[i] = (uint8_t)c;
}
static void classify(uint32_t np) {
    if (np > cls_cap) cls = realloc(cls, np), cls_cap = np;
    range r[5];
    state_ranges(r, ff_arena_top());
    uint32_t idx = 0, arena0 = 0;
    for (int i = 0; i < 5; i++) {
        int c = i == 0 ? C_DATA : i == 1 ? C_STACK_LIVE : i == 2 ? C_PDDI : i == 3 ? C_MODULE : C_ARENA;
        if (i == 4) arena0 = idx;
        for (uint32_t off = 0; off < r[i].n; off += PAGE, idx++) {
            int cc = c;
            if (i == 1 && off >= MAIN_STACK_HI - MAIN_STACK_LO) cc = C_SIM;
            cls[idx] = (uint8_t)cc;
        }
    }
    /* the dl heaps (stream.c's table of MemoryHeapSlot), the voices (dsound_null.c's buf: 72 bytes), the fibers' stacks */
    for (uint32_t id = 0; id < 46; id++) {
        uint32_t a = rd(HEAP_SLOTS + 16 * id);
        if (!a || a < ARENA_LO || rd(a) != DL_VFTABLE) continue;
        mark(rd(a + 0x0c), rd(a + 0x0c) + rd(a + 0x14), C_HEAP, np, arena0);
    }
    for (uint32_t v = SIM->ds_voices, n = 0; v && n < 4096; v = rd(v + 8), n++) mark(v, v + 72, C_AUDIO, np, arena0);
    static uint32_t s[2 * 512];
    int n = ff_stack_ranges(s, 512);
    for (int i = 0; i < n; i++) mark(s[2 * i], s[2 * i + 1], C_STACK_LIVE, np, arena0);
    /* dead stack: below each suspended fiber's stack pointer, past its Asyncify data (the main thread's at 0xE00000) */
    static uint32_t d[2 * 256];
    int nd = (int)ff_sched_dead_ranges(d, 256);
    for (int i = 0; i < nd; i++) {
        uint32_t lo = d[2 * i], hi = d[2 * i + 1];
        if (lo >= MAIN_STACK_LO && hi <= MAIN_STACK_HI) {
            for (uint32_t a = (lo + PAGE - 1) & ~(PAGE - 1); a + PAGE <= hi; a += PAGE)
                cls[pages_of(XBE_END - DATA_LO) + (a - MAIN_STACK_LO) / PAGE] = C_STACK_DEAD;
        } else {
            mark((lo + PAGE - 1) & ~(PAGE - 1), hi & ~(PAGE - 1), C_STACK_DEAD, np, arena0);
        }
    }
}
static int stat_on = -1;
static uint32_t stat_until;
static void stat_summary(void) {
    if (!sum_frames) return;
    fprintf(stderr, "ringstat: %llu frames; ring peak %.1f MB (%u pages); save mean %.3f ms max %.3f ms; bytes changed a "
            "frame %.0f\n", (unsigned long long)sum_frames, pages_peak * (double)PAGE / 1048576.0, pages_peak,
            sum_save_ms / (double)sum_frames, max_save_ms, sum_bytes1 / (double)sum_frames);
    for (int d = 0; d < NDEP; d++) {
        char line[1024];
        uint64_t t = 0;
        int n = snprintf(line, sizeof line, "ringstat: over %2d: mean pages", depth[d]);
        for (int c = 0; c < NC; c++) {
            n += snprintf(line + n, sizeof line - (size_t)n, " %s %.1f", cname[c], sum_pages[d][c] / (double)sum_frames);
            t += sum_pages[d][c];
        }
        fprintf(stderr, "%s; all %.1f (%.2f MB); max %llu at frame %u\n", line, t / (double)sum_frames,
                t / (double)sum_frames * PAGE / 1048576.0, (unsigned long long)max_pages[d], max_frame[d]);
    }
    char line[512];
    int n = snprintf(line, sizeof line, "ringstat: pages changed in one frame, by 64:");
    for (int i = 0; i < 16; i++) n += snprintf(line + n, sizeof line - (size_t)n, " %u", hist1[i]);
    fprintf(stderr, "%s\n", line);
    fflush(stderr);
}
static void stat_frame(void) {
    if (stat_on < 0) {
        const char* e = getenv("HULK_RINGSTAT");
        stat_on = e && *e && *e != '0';
        if (!stat_on) return;
        stat_until = getenv("HULK_RINGSTAT_UNTIL") ? (uint32_t)atol(getenv("HULK_RINGSTAT_UNTIL")) : 0;
        ff_ring_config(depth[NDEP - 1] + 1);
        stat_bytes_on = (uint8_t*)1;
        const char* dp = getenv("HULK_RINGSTAT_DUMP");
        static char pre[400];
        if (dp && sscanf(dp, "%399[^:]:%u:%u", pre, &dump_a, &dump_b) == 3) dump_prefix = pre;
        atexit(stat_summary);
    }
    if (!stat_on || (stat_until && SIM->frame > stat_until)) return;
    stat_bytes = 0;
    double t0 = ff_now_ms();
    ff_ring_save();
    double t1 = ff_now_ms() - t0;
    keyframe* now = kf_at_or_before(SIM->frame);
    if (!now || now->frame != SIM->frame) return;
    classify(now->npages);
    uint32_t per[NDEP][NC];
    memset(per, 0, sizeof per);
    for (int d = 0; d < NDEP; d++) {
        keyframe* then = 0;
        for (int i = 0; i < ring_n; i++)
            if (ring[i].valid && ring[i].frame + (uint32_t)depth[d] == SIM->frame) then = &ring[i];
        if (!then) return;      /* (the first 30 frames: not counted) */
        for (uint32_t i = 0; i < now->npages; i++)
            if (i >= then->npages || now->page[i] != then->page[i]) per[d][cls[i]]++;
    }
    sum_frames++;
    sum_save_ms += t1;
    if (t1 > max_save_ms) max_save_ms = t1;
    sum_bytes1 += stat_bytes;
    char line[1024];
    int n = snprintf(line, sizeof line, "ring f=%u u=%u save %.3f ms ring %u pages bytes %llu", SIM->frame,
                     ff_replay_frame(), t1, pages_used, (unsigned long long)stat_bytes);
    for (int d = 0; d < NDEP; d++) {
        uint64_t t = 0;
        for (int c = 0; c < NC; c++) sum_pages[d][c] += per[d][c], t += per[d][c];
        if (t > max_pages[d]) max_pages[d] = t, max_frame[d] = SIM->frame;
        if (d == 0) hist1[t / 64 < 15 ? t / 64 : 15]++;
        n += snprintf(line + n, sizeof line - (size_t)n, " | %d:", depth[d]);
        for (int c = 0; c < NC; c++) n += snprintf(line + n, sizeof line - (size_t)n, " %u", per[d][c]);
    }
    fprintf(stderr, "%s\n", line);
    if (stat_until && SIM->frame == stat_until) stat_summary(), sum_frames = 0;
}

/* ------------------------------------------------------------------------------------------- ROLLDEEP */
static int deep_on = -1;
#define MAX_WIN 16
static uint32_t deep_win[MAX_WIN][2], deep_nwin, deep_d, deep_k = 5, frontier, target;
static uint64_t* deep_h;                /* the first pass's hashes, by frame % 64 */
static uint64_t deep_rolls, deep_same, deep_resim_frames, deep_bad;
static double deep_resim_ms, deep_save_ms, deep_restore_ms, deep_max_restore, deep_max_save, roll_t0;
static uint32_t deep_saves, deep_max_resim, roll_from;
static double deep_max_roll_ms;
static uint64_t game_g(void) {
    return mix(mix(fast_game_hash(), ff_module_hash()), ff_gfx_hash ? ff_gfx_hash() : 0);
}
static void deep_summary(void) {
    if (!deep_rolls) return;
    static uint64_t printed;
    if (printed == deep_rolls) return;
    printed = deep_rolls;
    range r[5];
    state_ranges(r, ff_arena_top());
    uint32_t np = 0;
    for (int i = 0; i < 5; i++) np += pages_of(r[i].n);
    fprintf(stderr, "rolldeep: state %u pages (%.1f MB); ", np, np * (double)PAGE / 1048576.0);
    fprintf(stderr, "%llu rollbacks of %u frames (keyframe every %u): %llu identical, %llu DIFFERENT; "
            "resimulated %llu frames, %.3f ms a frame; deepest %u frames, slowest rollback %.1f ms; save mean %.3f ms "
            "(%u saves, max %.3f), restore mean %.3f ms (max %.3f); ring peak %.1f MB\n",
            (unsigned long long)deep_rolls, deep_d, deep_k, (unsigned long long)deep_same,
            (unsigned long long)deep_bad, (unsigned long long)deep_resim_frames,
            deep_resim_frames ? deep_resim_ms / (double)deep_resim_frames : 0.0, deep_max_resim, deep_max_roll_ms,
            deep_saves ? deep_save_ms / deep_saves : 0.0, deep_saves, deep_max_save, deep_restore_ms / (double)deep_rolls,
            deep_max_restore, pages_peak * (double)PAGE / 1048576.0);
    fflush(stderr);
}
static void deep_save(void) {
    double t0 = ff_now_ms();
    ff_ring_save();
    double t = ff_now_ms() - t0;
    deep_save_ms += t, deep_saves++;
    if (t > deep_max_save) deep_max_save = t;
}
static void deep_frame(void) {
    if (deep_on < 0) {
        const char* e = getenv("HULK_ROLLDEEP");
        /* A-B[+A-B...]:D[:K] (the old A:B:D[:K] too) */
        deep_on = 0;
        const char* p = e;
        while (p && deep_nwin < MAX_WIN) {
            uint32_t a, b;
            int n = 0;
            if (sscanf(p, "%u-%u%n", &a, &b, &n) == 2 || sscanf(p, "%u:%u%n", &a, &b, &n) == 2) {
                if (b > a) deep_win[deep_nwin][0] = a, deep_win[deep_nwin][1] = b, deep_nwin++;
                p += n;
                if (*p == '+') { p++; continue; }
            }
            break;
        }
        deep_on = p && *p == ':' && sscanf(p, ":%u:%u", &deep_d, &deep_k) >= 1 && deep_nwin && deep_d;
        if (!deep_on) return;
        if (!deep_k) deep_k = 1;
        ff_ring_config((int)((deep_d + deep_k - 1) / deep_k) + 2);
        deep_h = calloc(64, sizeof *deep_h);
        if (deep_d >= 64) ff_fatal("rolldeep: D under 64");
        atexit(deep_summary);
    }
    if (!deep_on) return;
    uint32_t f = SIM->frame;
    int near = 0, in = 0, later = 0;
    for (uint32_t w = 0; w < deep_nwin; w++) {
        if (f + deep_d + deep_k >= deep_win[w][0] && f <= deep_win[w][1]) near = 1;
        if (f >= deep_win[w][0] && f <= deep_win[w][1]) in = 1;
        if (deep_win[w][1] >= f) later = 1;
    }
    if (!resim && !near) {
        ff_ring_forget_after(0);
        deep_summary();         /* (so far: a replay is stopped at its target frame, atexit never runs) */
        if (!later) {
            ff_ring_config(0);
            deep_on = 0;
        }
        return;
    }
    if (!resim && f > frontier) {
        frontier = f;
        if (f % deep_k == 0) deep_save();
        if (in) {
            deep_h[f % 64] = game_g();
            target = f;
            double t0 = ff_now_ms();
            long k = ff_ring_restore(f - deep_d);
            double t = ff_now_ms() - t0;
            if (k < 0) return;
            ff_ring_forget_after((uint32_t)k);
            roll_from = (uint32_t)k;
            deep_restore_ms += t;
            if (t > deep_max_restore) deep_max_restore = t;
            deep_rolls++;
            if (deep_rolls % 500 == 0) deep_summary();
            resim = 1;
            roll_t0 = ff_now_ms();
        }
        return;
    }
    if (!resim) return;
    if (f % deep_k == 0) deep_save();
    if (f < target) return;
    double t = ff_now_ms() - roll_t0;
    deep_resim_ms += t;
    if (t > deep_max_roll_ms) deep_max_roll_ms = t;
    if (f - roll_from > deep_max_resim) deep_max_resim = f - roll_from;
    resim = 0;
    uint64_t h = game_g();
    if (h == deep_h[f % 64]) deep_same++;
    else {
        deep_bad++;
        fprintf(stderr, "rolldeep: frame %u after a rollback of %u: hash 0x%016llx, first pass 0x%016llx: DIFFERENT\n", f,
                deep_d, (unsigned long long)h, (unsigned long long)deep_h[f % 64]);
        deep_summary();
        exit(3);
    }
}
/* frames resimulated: counted at each frame end while resimulating */
static void deep_count(void) {
    if (resim) deep_resim_frames++;
}

/* ------------------------------------------------------------------------------------------- hooks */
/* ff_frame_checkpoint: whether this frame's end needs a fiber switch (every fiber suspended) */
int ff_ring_frame_end(void) {
    if (stat_on < 0 && !(getenv("HULK_RINGSTAT") && *getenv("HULK_RINGSTAT") && *getenv("HULK_RINGSTAT") != '0'))
        stat_on = 0;
    if (deep_on < 0 && !getenv("HULK_ROLLDEEP")) deep_on = 0;
    return stat_on != 0 || deep_on != 0 || ring_n;
}
/* sched.c's driver at a frame-end switch */
void ff_ring_switch(void) {
    if (stat_on) stat_frame();
    if (deep_on) {
        uint32_t f0 = SIM->frame;
        int was = resim;
        deep_frame();
        if (was && SIM->frame == f0) deep_count();
    }
}
