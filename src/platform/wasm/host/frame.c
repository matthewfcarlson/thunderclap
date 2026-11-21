/* The end of a frame (D3D Swap): the virtual clock moves on one 60 Hz field, the next frame's input is applied, and
 * the run's statistics are kept (HULK_FRAMES ends the run; the frame rate is reported every HULK_REPORT frames). */
#include <emscripten.h>
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
uint32_t ff_state_bytes(void) { return (XBE_END - STATE_DATA_LO) + 0x00100000u + sizeof(hulk_sim) + (ff_arena_top() - ARENA_LO); }
/* a snapshot and a restore of the whole state (timing only: HULK_SNAPTEST) */
static void snap_test(void) {
    uint32_t n = ff_state_bytes();
    uint8_t* buf = malloc(n);
    if (!buf) return;
    double a = emscripten_get_now();
    int reps = 20;
    for (int r = 0; r < reps; r++) {
        uint8_t* q = buf;
        memcpy(q, PTR(STATE_DATA_LO), XBE_END - STATE_DATA_LO); q += XBE_END - STATE_DATA_LO;
        memcpy(q, PTR(0x00E00000u), 0x00100000u + sizeof(hulk_sim)); q += 0x00100000u + sizeof(hulk_sim);
        memcpy(q, PTR(ARENA_LO), ff_arena_top() - ARENA_LO);
    }
    double b = emscripten_get_now();
    for (int r = 0; r < reps; r++) {
        uint8_t* q = buf;
        memcpy(PTR(STATE_DATA_LO), q, XBE_END - STATE_DATA_LO); q += XBE_END - STATE_DATA_LO;
        memcpy(PTR(0x00E00000u), q, 0x00100000u + sizeof(hulk_sim)); q += 0x00100000u + sizeof(hulk_sim);
        memcpy(PTR(ARENA_LO), q, ff_arena_top() - ARENA_LO);
    }
    double c = emscripten_get_now();
    fprintf(stderr, "hulk: state %.1f MB: snapshot %.2f ms, restore %.2f ms, hash 0x%016llx\n", n / 1048576.0,
            (b - a) / reps, (c - b) / reps, (unsigned long long)ff_state_hash());
    free(buf);
}
void ff_frame_end(void) {
    static long limit = -1, every = 0;
    if (limit < 0) {
        limit = getenv("HULK_FRAMES") ? atol(getenv("HULK_FRAMES")) : 0;
        every = getenv("HULK_REPORT") ? atol(getenv("HULK_REPORT")) : 600;
        t0 = t_last = emscripten_get_now();
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
        double now = emscripten_get_now();
        fprintf(stderr, "hulk: frame %u (%.0f frames/s over the last %ld, %.1f s in all)\n", SIM->frame,
                every * 1000.0 / (now - t_last), every, (now - t0) / 1000.0);
        t_last = now;
    }
    if (limit && SIM->frame >= (uint32_t)limit) {
        void ff_dump_threads(void);
        if (getenv("HULK_THREADS")) ff_dump_threads();
        if (getenv("HULK_SNAPTEST")) snap_test();
        else fprintf(stderr, "hulk: state hash 0x%016llx (%u bytes)\n", (unsigned long long)ff_state_hash(), ff_state_bytes());
        double now = emscripten_get_now();
        fprintf(stderr, "hulk: %u frames in %.2f s (%.0f frames/s)\n", SIM->frame, (now - t0) / 1000.0,
                SIM->frame * 1000.0 / (now - t0));
        exit(0);
    }
}
