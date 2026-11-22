/* The app's audio, the module's half (docs/wasm-port.md "The macOS app"): dsound_null.c keeps the game's view of the
 * voices (status, positions on the virtual clock); this observer hands each DirectSound call, once done, to the
 * runner's mixer (src/platform/sdl/audio/hulk_audio.cpp in run/app/audio.cpp: `hulk` imports aud_*), which plays the
 * voices' memory in the game's buffers in real time, and answers the game's status and position reads (as the Wine
 * build's device clock: real time enters the game's state, so only in free play; replays keep dsound_null's model).
 *
 * The shapes are audio_dsound.cpp's (the radsound HAL's call sites): DSBUFFERDESC {size, flags, bytes, format*,
 * mixbins*}, WAVEFORMATEX {u16 tag (1 PCM, 0x69 Xbox ADPCM), u16 channels, u32 rate, ..., u16 bits at +14}, mixbins
 * {u32 count, pairs*}, pair {u32 bin, s32 volume (mB)}, the I3DL2 listener as 12 words. A voice is named by the
 * buffer's handle (its address in the arena). On only with the pddi front end and outside replays (HULK_AUDIO=0:
 * off). */
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"

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
GI(aud_work) void ga_work(void);
GI(aud_status) uint32_t ga_status(uint32_t voice);
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
        on = hulk_wasm_gfx_on() && !ff_replay_active() && !(r && !strcmp(r, "noop")) && !(e && *e == '0');
    }
    return on;
}

/* the game's reads of a voice's status (0x003c6ca2) and position (0x003c6cbe) in free play: the mixer's, which plays
 * in real time (the module's model moves 800 frames a DirectSoundDoWork, which the game calls about three times a
 * frame: streams would be refilled ahead of what was heard) */
int ff_audio_query(uint32_t fn, uint32_t buffer, uint32_t* out) {
    if (!audio_on()) return 0;
    *out = fn == 0x003c6ca2u ? ga_status(buffer) : ga_where(buffer);
    return 1;
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
    case 0x003c6e34: ga_work(); break;
    }
}
