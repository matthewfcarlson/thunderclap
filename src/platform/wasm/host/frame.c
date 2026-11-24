/* The end of a frame (D3D Swap): the virtual clock moves on one 60 Hz field, the next frame's input is applied, and
 * the run's statistics are kept (HULK_FRAMES ends the run; the frame rate is reported every HULK_REPORT frames). */
#include <stdio.h>
#include <stdlib.h>
#include "hulk_host.h"
#include "sim.h"

static double t0, t_last;

/* the game state: the image's data (.data and the sections after it, .bss included), the game stack, the sim block
 * and the arena up to its top (docs/wasm-port.md "State") */
#define STATE_DATA_LO 0x0048ca80u
static uint64_t fnv(const uint8_t* p, uint32_t n, uint64_t h) {
    for (uint32_t i = 0; i < n; i++) h = (h ^ p[i]) * 0x100000001b3ull;
    return h;
}
uint64_t ff_state_hash(void) {
    uint64_t h = 0xcbf29ce484222325ull;
    h = fnv(PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO, h);
    h = fnv(PTR(0x00E00000u), 0x00100000u + sizeof(hulk_sim), h);
    h = fnv(PTR(ARENA_LO), ff_arena_top() - ARENA_LO, h);
    return h;
}
/* the game's part of the state: the state without the stacks and Asyncify buffers (the main thread's stack, the
 * fibers' and the continuations' in the arena), whose dead bytes depend on how the code was compiled: two builds of
 * the same game (-O0 and -O1) give the same game hash */
int ff_stack_ranges(uint32_t* out, int cap);
static int by_lo(const void* a, const void* b) {
    uint32_t x = *(const uint32_t*)a, y = *(const uint32_t*)b;
    return (x > y) - (x < y);
}
uint64_t ff_game_hash(void) {
    static uint32_t r[2 * 512];
    int n = ff_stack_ranges(r, 512);
    qsort(r, n, 8, by_lo);
    uint64_t h = 0xcbf29ce484222325ull;
    h = fnv(PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO, h);
    h = fnv(PTR(0x00F00000u), sizeof(hulk_sim), h);
    uint32_t at = ARENA_LO, top = ff_arena_top();
    for (int i = 0; i < n; i++) {
        if (r[2 * i] > at) h = fnv(PTR(at), (r[2 * i] < top ? r[2 * i] : top) - at, h);
        if (r[2 * i + 1] > at) at = r[2 * i + 1];
    }
    if (top > at) h = fnv(PTR(at), top - at, h);
    return h;
}
/* the tree's own mutable globals (tools/wasm_port.py GAME_STATE_SECTION, wroll1): game state in module data, carried
 * by snapshots; hashed apart from the game hash (their words include vftable pointers into module data, which move
 * with the build) */
extern char __start_hulk_game_state[] __attribute__((weak)), __stop_hulk_game_state[] __attribute__((weak));
uint32_t ff_module_state(uint32_t* lo) {
    *lo = (uint32_t)(uintptr_t)__start_hulk_game_state;
    return (uint32_t)(__stop_hulk_game_state - __start_hulk_game_state);
}
uint64_t ff_module_hash(void) {
    uint32_t lo, n = ff_module_state(&lo);
    return fnv(PTR(lo), n, 0xcbf29ce484222325ull);
}
uint32_t ff_state_bytes(void) { return (XBE_END - STATE_DATA_LO) + 0x00100000u + sizeof(hulk_sim) + (ff_arena_top() - ARENA_LO); }
/* HULK_DUMP=PATH: the state's bytes at the end of the run, in hash order (finding what differs between runs) */
#include "hulk_io.h"
static void dump_state(const char* path) {
    int32_t f = hio_open(path, HIO_CREATE);
    if (f < 0) return;
    uint32_t off = 0;
    off += (uint32_t)hio_write(f, PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO, off);
    off += (uint32_t)hio_write(f, PTR(0x00E00000u), 0x00100000u + sizeof(hulk_sim), off);
    hio_write(f, PTR(ARENA_LO), ff_arena_top() - ARENA_LO, off);
    hio_close(f);
}
/* HULK_GAMEDUMP=PATH: the game's part of the state (ff_game_hash's bytes, the left-out ranges as zeros): the image's
 * data from 0x48ca80, the sim block, then the arena from 16 MB */
static void dump_game(const char* path) {
    static const uint8_t zero[65536];
    static uint32_t r[2 * 512];
    int32_t f = hio_open(path, HIO_CREATE);
    if (f < 0) return;
    uint32_t off = 0;
    off += (uint32_t)hio_write(f, PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO, off);
    off += (uint32_t)hio_write(f, PTR(0x00F00000u), sizeof(hulk_sim), off);
    int n = ff_stack_ranges(r, 512);
    qsort(r, n, 8, by_lo);
    uint32_t at = ARENA_LO, top = ff_arena_top();
    for (int i = 0; i <= n; i++) {
        uint32_t lo = i < n ? (r[2 * i] < top ? r[2 * i] : top) : top, hi = i < n ? (r[2 * i + 1] < top ? r[2 * i + 1] : top) : top;
        if (lo > at) off += (uint32_t)hio_write(f, PTR(at), lo - at, off), at = lo;
        while (hi > at) {
            uint32_t k = hi - at < sizeof zero ? hi - at : sizeof zero;
            off += (uint32_t)hio_write(f, zero, k, off);
            at += k;
        }
    }
    hio_close(f);
}
void ff_game_dump(const char* path) { dump_game(path); }
/* a snapshot and a restore of the whole state (timing only: HULK_SNAPTEST) */
static void snap_test(void) {
    uint32_t n = ff_state_bytes();
    uint8_t* buf = malloc(n);
    if (!buf) return;
    double a = ff_now_ms();
    int reps = 20;
    for (int r = 0; r < reps; r++) {
        uint8_t* q = buf;
        memcpy(q, PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO); q += XBE_END - STATE_DATA_LO;
        memcpy(q, PTR(0x00E00000u), 0x00100000u + sizeof(hulk_sim)); q += 0x00100000u + sizeof(hulk_sim);
        memcpy(q, PTR(ARENA_LO), ff_arena_top() - ARENA_LO);
    }
    double b = ff_now_ms();
    for (int r = 0; r < reps; r++) {
        uint8_t* q = buf;
        memcpy(PTR(STATE_DATA_LO), q, XBE_END - STATE_DATA_LO); q += XBE_END - STATE_DATA_LO;
        memcpy(PTR(0x00E00000u), q, 0x00100000u + sizeof(hulk_sim)); q += 0x00100000u + sizeof(hulk_sim);
        memcpy(PTR(ARENA_LO), q, ff_arena_top() - ARENA_LO);
    }
    double c = ff_now_ms();
    fprintf(stderr, "hulk: state %.1f MB: snapshot %.2f ms, restore %.2f ms, hash 0x%016llx\n", n / 1048576.0,
            (b - a) / reps, (c - b) / reps, (unsigned long long)ff_state_hash());
    free(buf);
}
/* (on the host's stack: nothing here leaves bytes on a game stack) */
static void frame_end(void* unused) {
    (void)unused;
    static long limit = -1, every = 0;
    if (limit < 0) {
        limit = getenv("HULK_FRAMES") ? atol(getenv("HULK_FRAMES")) : 0;
        every = getenv("HULK_REPORT") ? atol(getenv("HULK_REPORT")) : 600;
        t0 = t_last = ff_now_ms();
    }
    SIM->frame++;
    /* HULK_INPUT="FROM-TO:BUTTONS[/ANALOG[/LX/LY]],...": pad 0's digital buttons (XINPUT_GAMEPAD wButtons, hex) over
     * those frames, the analog buttons held fully down (a mask, hex: 1 A, 2 B, 4 X, 8 Y, 10 black, 20 white, 40 left
     * trigger, 80 right trigger) and the left stick (decimal, -32768..32767; up is +LY). An item `pK:FROM-TO:...` (K 1..3)
     * is pad K's (co-op tests, wcoop1); pad K is written only when some item names it. */
    const char* in = getenv("HULK_INPUT");
    uint16_t buttons[4] = {0, 0, 0, 0};
    unsigned analog[4] = {0, 0, 0, 0};
    int16_t stick[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    unsigned named = 1;
    for (const char* p = in; p && *p;) {
        unsigned a = 0, b = 0, v = 0, m = 0, port = 0;
        int lx = 0, ly = 0;
        if (p[0] == 'p' && p[1] >= '1' && p[1] <= '3' && p[2] == ':') port = (unsigned)(p[1] - '0'), p += 3;
        named |= 1u << port;
        int n = sscanf(p, "%u-%u:%x/%x/%d/%d", &a, &b, &v, &m, &lx, &ly);
        if (n >= 3 && SIM->frame >= a && SIM->frame <= b) {
            buttons[port] = (uint16_t)v, analog[port] = n >= 4 ? m : 0;
            stick[port][0] = (int16_t)(n == 6 ? lx : 0), stick[port][1] = (int16_t)(n == 6 ? ly : 0);
        }
        p = strchr(p, ',');
        if (p) p++;
    }
    for (unsigned k = 0; k < 4; k++) {
        if (!(named >> k & 1)) continue;
        memcpy(SIM->pads[k], &buttons[k], 2);
        for (int i = 0; i < 8; i++) SIM->pads[k][2 + i] = (analog[k] >> i & 1) ? 0xff : 0;
        if (in) memcpy(SIM->pads[k] + 10, stick[k], 4);
    }
    /* HULK_GS=1: the game-flow state's changes (CGame 0x004dd6ec +4: {current, previous}; 0x000873a0's GS_ names) */
    static int gs_on = -1;
    static uint32_t gs_last = ~0u;
    if (gs_on < 0) gs_on = getenv("HULK_GS") && getenv("HULK_GS")[0] == '1';
    if (gs_on) {
        static const char* names[] = {"NONE", "FRONTEND", "PREGAME", "PRESSSTART", "GAME", "POSTGAME", "PAUSE", "FMV", "QUIT"};
        uint32_t game = *(uint32_t*)PTR(0x004dd6ecu), st = game ? *(uint32_t*)PTR(game + 4) : 0;
        uint32_t gs = st ? *(uint32_t*)PTR(st) : ~1u;
        if (gs != gs_last)
            fprintf(stderr, "hulk: frame %u: GS_%s\n", SIM->frame, gs < 9 ? names[gs] : "?"), gs_last = gs;
    }
    if (getenv("HULK_STACK_AT") && SIM->frame == (uint32_t)atol(getenv("HULK_STACK_AT")))
        ff_fatal("stack at frame %u (HULK_STACK_AT)", SIM->frame);
    SIM->clock += HULK_TSC_HZ / 60;
    /* HULK_HASH_EVERY=N: the game hash every N frames (comparing runs frame by frame: display rates, fps2) */
    static long hash_every = -1;
    if (hash_every < 0) hash_every = getenv("HULK_HASH_EVERY") ? atol(getenv("HULK_HASH_EVERY")) : 0;
    if (hash_every > 0 && SIM->frame % hash_every == 0)
        fprintf(stderr, "hulk: frame %u game hash 0x%016llx\n", SIM->frame, (unsigned long long)ff_game_hash());
    if (every && SIM->frame % every == 0) {
        double now = ff_now_ms();
        fprintf(stderr, "hulk: frame %u (%.0f frames/s over the last %ld, %.1f s in all)\n", SIM->frame,
                every * 1000.0 / (now - t_last), every, (now - t0) / 1000.0);
        t_last = now;
    }
    if (limit && SIM->frame >= (uint32_t)limit) {
        void ff_dump_threads(void);
        void ff_sched_stats(void);
        ff_sched_stats();
        if (getenv("HULK_THREADS")) ff_dump_threads();
        if (getenv("HULK_DUMP")) dump_state(getenv("HULK_DUMP"));
        if (getenv("HULK_GAMEDUMP")) dump_game(getenv("HULK_GAMEDUMP"));
        if (getenv("HULK_SNAPTEST")) snap_test();
        else fprintf(stderr, "hulk: state hash 0x%016llx (%u bytes), game hash 0x%016llx\n",
                     (unsigned long long)ff_state_hash(), ff_state_bytes(), (unsigned long long)ff_game_hash());
        double now = ff_now_ms();
        fprintf(stderr, "hulk: %u frames in %.2f s (%.0f frames/s)\n", SIM->frame, (now - t0) / 1000.0,
                SIM->frame * 1000.0 / (now - t0));
        exit(0);
    }
}
void ff_frame_end(void) { ff_on_host_stack(frame_end, 0); }
