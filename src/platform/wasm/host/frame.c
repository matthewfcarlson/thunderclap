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
    /* HULK_INPUT="FROM-TO:BUTTONS,...": pad 0's digital buttons (XINPUT_GAMEPAD wButtons, hex) over those frames */
    const char* in = getenv("HULK_INPUT");
    uint16_t buttons = 0;
    for (const char* p = in; p && *p;) {
        unsigned a = 0, b = 0, v = 0;
        if (sscanf(p, "%u-%u:%x", &a, &b, &v) == 3 && SIM->frame >= a && SIM->frame <= b) buttons = (uint16_t)v;
        p = strchr(p, ',');
        if (p) p++;
    }
    memcpy(SIM->pads[0], &buttons, 2);
    if (getenv("HULK_STACK_AT") && SIM->frame == (uint32_t)atol(getenv("HULK_STACK_AT")))
        ff_fatal("stack at frame %u (HULK_STACK_AT)", SIM->frame);
    SIM->clock += HULK_TSC_HZ / 60;
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
