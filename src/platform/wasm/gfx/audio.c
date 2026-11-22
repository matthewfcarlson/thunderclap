/* The app's audio, the module's half (docs/wasm-port.md "The macOS app"): dsound_null.c is the one model of the voices
 * the game reads (status, positions on the virtual clock: D222); this observer hands each DirectSound call, once done,
 * and each advance of the voices, before it happens, to the runner's mixer (src/platform/sdl/audio/hulk_audio.cpp in
 * run/app/audio.cpp: `hulk` imports aud_*). The mixer keeps a mirror of the voices that the same calls and the same
 * advances drive (the same cursor arithmetic), renders the frames of each advance (aud_tick) and queues them to the
 * device: it produces the samples the model played and nothing flows back. HULK_AUDIO_CHECK=1 compares the mirror
 * with the model before every advance and logs (and repairs) a difference.
 *
 * The shapes are audio_dsound.cpp's (the radsound HAL's call sites): DSBUFFERDESC {size, flags, bytes, format*,
 * mixbins*}, WAVEFORMATEX {u16 tag (1 PCM, 0x69 Xbox ADPCM), u16 channels, u32 rate, ..., u16 bits at +14}, mixbins
 * {u32 count, pairs*}, pair {u32 bin, s32 volume (mB)}, the I3DL2 listener as 12 words. A voice is named by the
 * buffer's handle (its address in the arena). On only with the pddi front end and outside replays (HULK_AUDIO=0:
 * off; =1: on without a renderer too, e.g. HULK_GFX_RENDERER=null). */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

#define GI(name) __attribute__((import_module("hulk"), import_name(#name)))
GI(aud_create) void ga_create(uint32_t voice, int32_t codec, int32_t channels, int32_t bits, uint32_t rate,
                              const uint32_t* bins, uint32_t nbins);
GI(aud_release) void ga_release(uint32_t voice);
GI(aud_data) void ga_data(uint32_t voice, const void* data, uint32_t bytes);
GI(aud_play) void ga_play(uint32_t voice, int32_t loop);
GI(aud_stop) void ga_stop(uint32_t voice);
GI(aud_position) void ga_position(uint32_t voice, uint32_t bytes);
GI(aud_frequency) void ga_frequency(uint32_t voice, uint32_t hz);
GI(aud_headroom) void ga_headroom(uint32_t voice, uint32_t mb);
GI(aud_bins) void ga_bins(uint32_t voice, const uint32_t* bins, uint32_t nbins);
GI(aud_listener) void ga_listener(const uint32_t* words12);
GI(aud_tick) void ga_tick(uint32_t frames);
GI(aud_status) uint32_t ga_status(uint32_t voice);
GI(aud_resync) void ga_resync(uint32_t phase, uint32_t voice, const uint32_t* words9);
GI(aud_where) uint32_t ga_where(uint32_t voice);

int hulk_wasm_gfx_on(void);
int ff_replay_active(void);

static uint32_t rd32(uint32_t a, uint32_t off) {
    uint32_t v;
    memcpy(&v, (const uint8_t*)PTR(a) + off, 4);
    return v;
}
static uint32_t rd16(uint32_t a, uint32_t off) {
    uint16_t v;
    memcpy(&v, (const uint8_t*)PTR(a) + off, 2);
    return v;
}
/* mixbins -> {bin, volume} pairs (at most 16) */
static uint32_t bins(uint32_t mixbins, uint32_t* out) {
    if (!mixbins) return 0;
    uint32_t n = rd32(mixbins, 0), pairs = rd32(mixbins, 4);
    if (!pairs) return 0;
    if (n > 16) n = 16;
    for (uint32_t i = 0; i < n; i++) {
        out[2 * i] = rd32(pairs, 8 * i) & 15;
        out[2 * i + 1] = rd32(pairs, 8 * i + 4);
    }
    return n;
}

static int audio_on(void) {
    static int on = -1;
    if (on < 0) {
        const char* r = getenv("HULK_GFX_RENDERER");
        const char* e = getenv("HULK_AUDIO");
        on = (hulk_wasm_gfx_on() || (e && *e == '1')) && !ff_replay_active() && !(r && !strcmp(r, "noop")) &&
             !(e && *e == '0');
    }
    return on;
}

/* HULK_AUDIO_CHECK=1: the mirror against the model before each advance, when both stand at the same time (the
 * model's voices: its live list) */
int ff_ds_peek(uint32_t buffer, uint32_t* status, uint32_t* pos);
static void check(void) {
    static int on = -1;
    static unsigned long long diffs;
    if (on < 0) on = getenv("HULK_AUDIO_CHECK") && getenv("HULK_AUDIO_CHECK")[0] == '1';
    if (!on) return;
    for (uint32_t v = SIM->ds_voices; v; v = *(const uint32_t*)PTR(v + 8)) {
        uint32_t st, pos;
        if (!ff_ds_peek(v, &st, &pos)) continue;
        uint32_t ms = ga_status(v) & 1, mp = ga_where(v);
        if (ms != (st & 1) || mp != pos) {
            if (diffs++ < 20)
                fprintf(stderr, "audio check: voice %08x model %u@%u mirror %u@%u (frame %u)\n", v, st & 1, pos, ms,
                        mp, SIM->frame);
            if (!(st & 1)) ga_stop(v);
            else ga_play(v, (int32_t)(st >> 2 & 1));
            ga_position(v, pos);
        }
    }
}

/* a snapshot was put back (sched.c HULK_ROLLTEST; rollback): the mirror is made again from the model's voices (a
 * voice the mirror lacks is created with the default mix bins; the mirror's voices the model lacks are released) */
int ff_ds_describe(uint32_t buffer, uint32_t* w);
void ff_audio_restored(void) {
    if (!audio_on()) return;
    uint32_t w[9];
    ga_resync(0, 0, w);
    for (uint32_t v = SIM->ds_voices; v; v = *(const uint32_t*)PTR(v + 8))
        if (ff_ds_describe(v, w)) ga_resync(1, v, w);
    ga_resync(2, 0, w);
}

/* the voices are about to move on by FRAMES (dsound_null.c): the mixer renders them from its mirror, which is the
 * model as it is now */
void ff_audio_tick(uint32_t frames) {
    if (!audio_on()) return;
    check();
    ga_tick(frames);
}

void ff_audio_obs(uint32_t fn, const uint32_t* a) {
    if (!audio_on()) return;
    uint32_t pairs[32];
    switch (fn) {
    case 0x003c9ea7: {          /* CreateSoundBuffer(ds, desc, buffer**, unk) */
        uint32_t desc = a[1], fmt = desc ? rd32(desc, 12) : 0, mix = desc ? rd32(desc, 16) : 0;
        int codec = 0, channels = 1, bits = 16;
        uint32_t rate = 48000;
        if (fmt) {
            codec = rd16(fmt, 0) == 0x69;
            channels = (int)rd16(fmt, 2);
            rate = rd32(fmt, 4);
            bits = (int)rd16(fmt, 14);
        }
        uint32_t n = bins(mix, pairs);
        ga_create(rd32(a[2], 0), codec, channels, bits, rate, mix ? pairs : 0, n);
        break;
    }
    case 0x003c4737: ga_release(a[0]); break;
    case 0x003c93c9: ga_data(a[0], PTR(a[1]), a[1] ? a[2] : 0); break;
    case 0x003c6bbe: ga_play(a[0], (int32_t)(a[3] & 1)); break;
    case 0x003c6c06: ga_stop(a[0]); break;
    case 0x003c6cde: ga_position(a[0], a[1]); break;
    case 0x003c89b1: ga_frequency(a[0], a[1]); break;
    case 0x003c6b86: ga_headroom(a[0], a[1]); break;
    case 0x003c6ba2: {
        uint32_t n = bins(a[1], pairs);
        ga_bins(a[0], pairs, n);
        break;
    }
    case 0x003ca02f: if (a[1]) ga_listener(PTR(a[1])); break;
    }
}
