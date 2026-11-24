/* A null DirectSound (Xbox) by address (src/platform/sdl/xdk/imports.h): silent, but a buffer plays, so GetStatus
 * and GetCurrentPosition answer as a playing buffer would and sounds end when their data does: the game waits for
 * some of them. A buffer's state is in the game arena and the clock's in the sim block: everything the game can read
 * about its voices is game state (a snapshot carries it) and a function of the game's own calls and of the virtual
 * clock, never of the host (D222, docs/wasm-port.md "Audio"). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hulk_host.h"
#include "sim.h"

/* A buffer is a voice of the Wine build's mixer (src/platform/sdl/audio/hulk_audio.cpp): every playing voice's cursor
 * (frames, 32.32 fixed point) moves on by its frequency / 48000 an output frame of 48 kHz; a one-shot voice that
 * reaches its end stops at frame 0, a looping one wraps. Positions are frames converted to bytes (Xbox ADPCM: 36-byte
 * blocks of 65 samples a channel). The output frames pass on one of two clocks (SIM->ds_clock, fixed at
 * DirectSoundCreate):
 *   0 (replays): 800 frames a DirectSoundDoWork, as the Wine build's HULK_AUDIO_CLOCK=frame (HULK_AUDIO_NOMIX), so
 *     GetStatus and GetCurrentPosition answer as the Wine build's do, frame for frame (the game calls DoWork about
 *     three times a frame: the voices run ~1.5x fast, which the recordings were checked with);
 *   1 (every other run): the virtual clock's 48 kHz, as the console's APU: at every DirectSound call the voices move
 *     on to SIM->clock (SIM->ds_frames: the frames reached), so they play in game time, which free play paces to
 *     real time.
 *   N > 1 (a playthrough's live segments, replay.cpp "Playthroughs"): N frames a DoWork, from the segment's start on
 *     (533: about the console's rate at three DoWorks an update), so the player's sound keeps to real time while
 *     the run stays a function of its recording.
 * HULK_DS_CLOCK=work|time overrides the choice. The app's mixer (gfx/audio.c) only listens: it hears each call and
 * each advance (ff_audio_tick: the frames the voices moved) and renders exactly what the model played. */
#define AUDIO_RATE 48000u
#define FRAMES_PER_WORK (AUDIO_RATE / 60)
#define XADPCM_BLOCK 36u
#define XADPCM_SAMPLES 65u
typedef struct {
    uint32_t magic, refs, next;                  /* next: the list of live buffers (SIM->ds_voices) */
    uint32_t data, bytes;
    uint32_t xadpcm, channels, bits, rate, freq;
    uint32_t frame_bytes, playing, looping;
    uint64_t frames, cursor;
} buf;
#define MAGIC 0x46554244u                    /* "DBUF" */

/* The app's mixer (src/platform/wasm/gfx/audio.c, HULK_WASM_GFX=1 builds; docs/wasm-port.md "The macOS app") hears
 * each call once it is done, by the function's address and its stack arguments, and each advance of the voices
 * before it happens (ff_audio_tick); it changes nothing the game reads. Elsewhere it is not linked (weak: null). */
void ff_audio_obs(uint32_t fn, const uint32_t* args) __attribute__((weak));
void ff_audio_tick(uint32_t frames) __attribute__((weak));
#define OBS(fn) do { if (ff_audio_obs) ff_audio_obs(0x##fn##u, (const uint32_t*)st); } while (0)

static buf* B(uint32_t p) { buf* b = PTR(p); return b && b->magic == MAGIC ? b : 0; }

static void voice_length(buf* b) {
    if (b->xadpcm) {
        b->frame_bytes = XADPCM_BLOCK * b->channels;
        b->frames = (uint64_t)(b->bytes / b->frame_bytes) * XADPCM_SAMPLES;
    } else {
        b->frame_bytes = b->bits / 8 * b->channels;
        if (!b->frame_bytes) b->frame_bytes = 1;
        b->frames = b->bytes / b->frame_bytes;
    }
    if (!b->frames || (b->cursor >> 32) >= b->frames) b->cursor = 0;
}
static uint32_t frame_to_bytes(const buf* b, uint64_t frame) {
    if (b->xadpcm)
        return (uint32_t)(frame / XADPCM_SAMPLES * b->frame_bytes + frame % XADPCM_SAMPLES * b->frame_bytes / XADPCM_SAMPLES);
    return (uint32_t)(frame * b->frame_bytes);
}
static void advance(buf* b, uint32_t n) {
    if (!b->playing || !b->data || !b->frames) return;
    uint64_t step = ((uint64_t)b->freq << 32) / AUDIO_RATE, end = b->frames << 32;
    if (b->looping) {
        b->cursor = (b->cursor + step * n) % end;   /* (the same as wrapping at every frame) */
    } else if (b->cursor + step * n >= end) {
        b->cursor = 0;
        b->playing = 0;
    } else {
        b->cursor += step * n;
    }
}

int ff_replay_active(void);     /* replay.cpp */
/* the virtual clock in 48 kHz frames */
static uint64_t clock_frames(void) {
    uint64_t c = SIM->clock;
    return c / HULK_TSC_HZ * AUDIO_RATE + c % HULK_TSC_HZ * AUDIO_RATE / HULK_TSC_HZ;
}
/* the voices move on by N output frames (the mixer first renders them from the voices as they are) */
static void advance_all(uint32_t n) {
    if (!n) return;
    if (ff_audio_tick) ff_audio_tick(n);
    for (buf* b = PTR(SIM->ds_voices); b; b = PTR(b->next)) advance(b, n);
}
/* clock 1: the voices move on to the virtual clock (at every DirectSound call, before it acts) */
static void sync(void) {
    if (SIM->ds_clock != 1) return;
    uint64_t to = clock_frames();
    while (to > SIM->ds_frames) {
        uint64_t n = to - SIM->ds_frames;
        if (n > AUDIO_RATE) n = AUDIO_RATE;           /* (a long jump of the clock: a second at a time) */
        advance_all((uint32_t)n);
        SIM->ds_frames += n;
    }
}
/* the model's view of a buffer (gfx/audio.c's HULK_AUDIO_CHECK): 1 and its status / position bytes, 0 without one */
int ff_ds_peek(uint32_t buffer, uint32_t* status, uint32_t* pos) {
    buf* b = B(buffer);
    if (!b) return 0;
    *status = b->playing ? (1u | (b->looping ? 4u : 0u)) : 0;
    *pos = frame_to_bytes(b, b->cursor >> 32);
    return 1;
}
/* a buffer as the mixer needs it to make its mirror again after a restore (gfx/audio.c ff_audio_restored): W = {Xbox
 * ADPCM, channels, bits, rate, data, bytes, frequency, status, position bytes} */
int ff_ds_describe(uint32_t buffer, uint32_t* w) {
    buf* b = B(buffer);
    if (!b) return 0;
    w[0] = b->xadpcm, w[1] = b->channels, w[2] = b->bits, w[3] = b->rate, w[4] = b->data, w[5] = b->bytes;
    w[6] = b->freq;
    return ff_ds_peek(buffer, &w[7], &w[8]);
}

FFG(003ca1f5) {         /* DirectSoundCreate(guid, ds**, unk) */
    UNUSED;
    if (!SIM->ds_object) {
        SIM->ds_object = (uint32_t)(uintptr_t)ff_arena_alloc(64, 16);
        const char* e = getenv("HULK_DS_CLOCK");
        SIM->ds_clock = e && *e ? !strcmp(e, "time") : !ff_replay_active();
        SIM->ds_frames = clock_frames();
    }
    *(uint32_t*)PTR(ARG(1)) = SIM->ds_object;
    RET(0);
}
FFG(003c4701) { UNUSED; RET(0); }                                               /* IDirectSound_Release */
FFG(003c4789) { UNUSED; RET(0); }                                               /* DirectSoundUseFullHRTF */
FFG(003c696c) { UNUSED; if (ARG(3)) *(uint32_t*)PTR(ARG(3)) = 0; RET(0); }      /* DownloadEffectsImage */
uint32_t ff_ds_works;     /* DoWork calls so far (host statistics: replay.cpp's playthrough log) */
FFG(003c6e34) {                                                                 /* DirectSoundDoWork */
    UNUSED;
    ff_ds_works++;
    if (SIM->ds_clock == 1) sync();
    else advance_all(SIM->ds_clock > 1 ? SIM->ds_clock : FRAMES_PER_WORK);   /* (above 1: a playthrough's live clock) */
    RET(0);
}
FFG(003c98ca) { UNUSED; RET(0); }                                               /* CommitDeferredSettings */
FFG(003ca02f) { UNUSED; sync(); OBS(003ca02f); RET(0); }                                             /* SetI3DL2Listener */
FFG(003c9ea7) {         /* IDirectSound_CreateSoundBuffer(ds, DSBUFFERDESC*, buffer**, unk) */
    UNUSED;
    sync();
    const uint32_t* d = PTR(ARG(1));
    buf* b = ff_arena_alloc(sizeof *b, 16);
    b->magic = MAGIC;
    b->refs = 1;
    b->channels = 1, b->bits = 16, b->rate = AUDIO_RATE;
    if (d[3]) {                                 /* WAVEFORMATEX: tag, channels, rate, ..., bits */
        const uint8_t* w = PTR(d[3]);
        b->xadpcm = *(const uint16_t*)w == 0x69;
        b->channels = *(const uint16_t*)(w + 2);
        b->rate = *(const uint32_t*)(w + 4);
        b->bits = *(const uint16_t*)(w + 14);
    }
    if (b->channels < 1) b->channels = 1;
    if (b->channels > 2) b->channels = 2;
    if (!b->xadpcm && b->bits != 8 && b->bits != 16) b->bits = 16;
    if (!b->rate) b->rate = AUDIO_RATE;
    b->freq = b->rate;
    voice_length(b);
    b->next = SIM->ds_voices;                   /* (the game hands its own memory over with SetBufferData) */
    SIM->ds_voices = (uint32_t)(uintptr_t)b;
    *(uint32_t*)PTR(ARG(2)) = (uint32_t)(uintptr_t)b;
    OBS(003c9ea7);
    RET(0);
}
FFG(003c4737) {                                                                 /* IDirectSoundBuffer_Release */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    if (!b) { RET(0); return; }
    OBS(003c4737);
    for (uint32_t* p = &SIM->ds_voices; *p; p = &((buf*)PTR(*p))->next)
        if (*p == ARG(0)) { *p = b->next; break; }
    b->magic = 0;
    ff_arena_free(b);
    RET(0);
}
FFG(003c93c9) {         /* SetBufferData(buffer, data, bytes): the game's memory */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    if (b) {
        b->data = ARG(1);
        b->bytes = ARG(1) ? ARG(2) : 0;
        voice_length(b);
        if (!b->frames) b->playing = 0;
    }
    OBS(003c93c9);
    RET(0);
}
FFG(003c6bbe) {         /* Play(buffer, r1, r2, flags) */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    if (b) { b->looping = ARG(3) & 1; b->playing = b->frames != 0; }
    OBS(003c6bbe);
    RET(0);
}
FFG(003c6c06) { UNUSED; sync(); buf* b = B(ARG(0)); if (b) b->playing = 0; OBS(003c6c06); RET(0); }   /* Stop */
FFG(003c6ca2) {         /* GetStatus(buffer, status*) */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    uint32_t v = b && b->playing ? (1u | (b->looping ? 4u : 0u)) : 0;
    *(uint32_t*)PTR(ARG(1)) = v;
    RET(0);
}
FFG(003c6cbe) {         /* GetCurrentPosition(buffer, play*, write*) */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    uint32_t p = b ? frame_to_bytes(b, b->cursor >> 32) : 0;
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = p;
    if (ARG(2)) *(uint32_t*)PTR(ARG(2)) = p;
    RET(0);
}
FFG(003c6cde) {         /* SetCurrentPosition(buffer, bytes) */
    UNUSED;
    sync();
    buf* b = B(ARG(0));
    if (b) {
        uint32_t n = ARG(1);
        uint64_t f = b->xadpcm ? (uint64_t)(n / b->frame_bytes) * XADPCM_SAMPLES + n % b->frame_bytes * XADPCM_SAMPLES / b->frame_bytes
                               : n / b->frame_bytes;
        b->cursor = f >= b->frames ? 0 : f << 32;
    }
    OBS(003c6cde);
    RET(0);
}
FFG(003c89b1) { UNUSED; sync(); buf* b = B(ARG(0)); if (b) b->freq = ARG(1) ? ARG(1) : b->rate; OBS(003c89b1); RET(0); }   /* SetFrequency */
FFG(003c6b86) { UNUSED; sync(); OBS(003c6b86); RET(0); }                                             /* SetHeadroom */
FFG(003c6ba2) { UNUSED; sync(); OBS(003c6ba2); RET(0); }                                             /* SetMixBinVolumes */
