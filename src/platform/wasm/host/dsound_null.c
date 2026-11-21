/* A null DirectSound (Xbox) by address (src/platform/sdl/xdk/imports.h): silent, but a buffer plays on the virtual
 * clock (after the owner's fusion-frenzy port), so GetStatus and GetCurrentPosition answer as a playing buffer would
 * and sounds end when their data does: the game waits for some of them. A buffer's state is in the game arena. */
#include <stdio.h>
#include "hulk_host.h"
#include "sim.h"

typedef struct {
    uint32_t magic, refs, flags, bytes, data;
    uint32_t avg_bytes, rate, freq;          /* WAVEFORMATEX's bytes a second and sample rate; SetFrequency's */
    uint32_t playing, looping, pos;          /* pos: the play cursor in bytes (as of tick) */
    uint32_t tick_lo, tick_hi;               /* the clock when pos was last brought up to date */
} buf;
#define MAGIC 0x46554244u                    /* "DBUF" */

static buf* B(uint32_t p) { buf* b = PTR(p); return b && b->magic == MAGIC ? b : 0; }

/* bring the play cursor up to the clock */
static void advance(buf* b) {
    uint64_t now = SIM->clock, then = (uint64_t)b->tick_hi << 32 | b->tick_lo;
    if (b->playing && b->bytes && now > then) {
        uint64_t rate = b->avg_bytes;
        if (b->freq && b->rate) rate = rate * b->freq / b->rate;
        uint64_t moved = (now - then) * rate / HULK_TSC_HZ;
        uint64_t p = b->pos + moved;
        if (b->looping) p %= b->bytes;
        else if (p >= b->bytes) { p = 0; b->playing = 0; }
        b->pos = (uint32_t)p;
    }
    b->tick_lo = (uint32_t)now;
    b->tick_hi = (uint32_t)(now >> 32);
}

FFG(003ca1f5) {         /* DirectSoundCreate(guid, ds**, unk) */
    UNUSED;
    if (!SIM->ds_object) SIM->ds_object = (uint32_t)(uintptr_t)ff_arena_alloc(64, 16);
    *(uint32_t*)PTR(ARG(1)) = SIM->ds_object;
    RET(0);
}
FFG(003c4701) { UNUSED; RET(0); }                                               /* IDirectSound_Release */
FFG(003c4789) { UNUSED; RET(0); }                                               /* DirectSoundUseFullHRTF */
FFG(003c696c) { UNUSED; if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = 0; RET(0); }      /* DownloadEffectsImage */
FFG(003c6e34) { UNUSED; RET(0); }                                               /* DirectSoundDoWork */
FFG(003c98ca) { UNUSED; RET(0); }                                               /* CommitDeferredSettings */
FFG(003ca02f) { UNUSED; RET(0); }                                               /* SetI3DL2Listener */
FFG(003c9ea7) {         /* IDirectSound_CreateSoundBuffer(ds, DSBUFFERDESC*, buffer**, unk) */
    UNUSED;
    const uint32_t* d = PTR(ARG(1));
    buf* b = ff_arena_alloc(sizeof *b, 16);
    b->magic = MAGIC;
    b->refs = 1;
    b->flags = d[1];
    b->bytes = d[2];
    if (d[3]) {
        const uint8_t* w = PTR(d[3]);
        b->rate = *(const uint32_t*)(w + 4);
        b->avg_bytes = *(const uint32_t*)(w + 8);
    }
    if (b->bytes) b->data = (uint32_t)(uintptr_t)ff_arena_alloc(b->bytes, 16);
    *(uint32_t*)PTR(ARG(2)) = (uint32_t)(uintptr_t)b;
    RET(0);
}
FFG(003c4737) {                                                                 /* IDirectSoundBuffer_Release */
    UNUSED;
    buf* b = B(ARG(0));
    if (!b) { RET(0); return; }
    uint32_t left = b->refs ? --b->refs : 0;
    if (!left) b->magic = 0;
    RET(left);
}
FFG(003c93c9) {         /* SetBufferData(buffer, data, bytes): the game's memory */
    UNUSED;
    buf* b = B(ARG(0));
    if (b) { advance(b); b->data = ARG(1); b->bytes = ARG(2); b->pos = 0; }
    RET(0);
}
FFG(003c6bbe) {         /* Play(buffer, r1, r2, flags) */
    UNUSED;
    buf* b = B(ARG(0));
    if (b) { advance(b); b->playing = 1; b->looping = ARG(3) & 1; }
    RET(0);
}
FFG(003c6c06) { UNUSED; buf* b = B(ARG(0)); if (b) { advance(b); b->playing = 0; } RET(0); }     /* Stop */
FFG(003c6ca2) {         /* GetStatus(buffer, status*) */
    UNUSED;
    buf* b = B(ARG(0));
    uint32_t s = 0;
    if (b) {
        advance(b);
        s = b->playing ? (1u | (b->looping ? 4u : 0u)) : 0;
    }
    *(uint32_t*)PTR(ARG(1)) = s;
    RET(0);
}
FFG(003c6cbe) {         /* GetCurrentPosition(buffer, play*, write*) */
    UNUSED;
    buf* b = B(ARG(0));
    uint32_t p = 0;
    if (b) { advance(b); p = b->pos; }
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = p;
    if (ARG(2)) *(uint32_t*)PTR(ARG(2)) = b && b->bytes ? (p + b->avg_bytes / 60) % b->bytes : 0;
    RET(0);
}
FFG(003c6cde) { UNUSED; buf* b = B(ARG(0)); if (b) { advance(b); b->pos = ARG(1); } RET(0); }   /* SetCurrentPosition */
FFG(003c89b1) { UNUSED; buf* b = B(ARG(0)); if (b) { advance(b); b->freq = ARG(1); } RET(0); }  /* SetFrequency */
FFG(003c6b86) { UNUSED; RET(0); }                                               /* SetHeadroom */
FFG(003c6ba2) { UNUSED; RET(0); }                                               /* SetMixBinVolumes */
