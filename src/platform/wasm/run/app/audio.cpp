// The app's audio, the runner's half (docs/wasm-port.md "The macOS app"): the `hulk` imports aud_* of a
// HULK_WASM_GFX=1 module (src/platform/wasm/gfx/audio.c) on the SDL layer's mixer (src/platform/sdl/audio/: Xbox
// ADPCM, mix bins folded to stereo, the I3DL2 reverb), clocked by SDL's audio device. A voice plays the game's buffer
// in the module's linear memory where the game wrote it (the memory never moves: no growth). The game reads its
// voices' status and positions from the module's own model (dsound_null.c), never from here.
#include <stdint.h>
#include <string.h>

#include <unordered_map>

#include "audio/hulk_audio.cpp"
#include "audio/reverb.cpp"
#include "audio/xadpcm.cpp"

typedef uint32_t u32;
struct w2c_hulk;
extern "C" uint8_t* hulk_run_memory(void);    // run/native.c

static std::unordered_map<u32, HulkVoice*> s_voices;
static bool s_up;

static void up()
{
    if (s_up)
        return;
    s_up = true;
    hulk_audio_set_clock(HULK_CLOCK_DEVICE, 0);
    hulk_audio_init();
}
static HulkVoice* V(u32 h)
{
    auto it = s_voices.find(h);
    return it == s_voices.end() ? nullptr : it->second;
}
static unsigned readBins(u32 at, u32 n, HulkMixBin* out)
{
    const uint8_t* p = hulk_run_memory() + at;
    for (u32 i = 0; i < n && i < HULK_AUDIO_MAX_BINS; i++) {
        uint32_t w[2];
        memcpy(w, p + 8 * i, 8);
        out[i].bin = w[0];
        out[i].volume = (int)w[1];
    }
    return n < HULK_AUDIO_MAX_BINS ? n : HULK_AUDIO_MAX_BINS;
}

extern "C" {

void w2c_hulk_aud_create(struct w2c_hulk*, u32 voice, u32 codec, u32 channels, u32 bits, u32 rate, u32 bins, u32 n)
{
    up();
    HulkAudioFormat f;
    f.codec = codec ? HULK_CODEC_XADPCM : HULK_CODEC_PCM;
    f.channels = (int)channels;
    f.bits = (int)bits;
    f.rate = rate;
    HulkMixBin b[HULK_AUDIO_MAX_BINS];
    unsigned k = bins ? readBins(bins, n, b) : 0;
    if (HulkVoice* old = V(voice))
        hulk_audio_voice_release(old);
    s_voices[voice] = hulk_audio_voice_create(&f, bins ? b : nullptr, k);
}
void w2c_hulk_aud_release(struct w2c_hulk*, u32 voice)
{
    if (HulkVoice* v = V(voice)) {
        hulk_audio_voice_release(v);
        s_voices.erase(voice);
    }
}
void w2c_hulk_aud_data(struct w2c_hulk*, u32 voice, u32 data, u32 bytes)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_set_data(v, data ? hulk_run_memory() + data : nullptr, bytes);
}
void w2c_hulk_aud_play(struct w2c_hulk*, u32 voice, u32 loop)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_play(v, (int)loop);
}
void w2c_hulk_aud_stop(struct w2c_hulk*, u32 voice)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_stop(v);
}
void w2c_hulk_aud_position(struct w2c_hulk*, u32 voice, u32 bytes)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_set_position(v, bytes);
}
void w2c_hulk_aud_frequency(struct w2c_hulk*, u32 voice, u32 hz)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_set_frequency(v, hz);
}
void w2c_hulk_aud_headroom(struct w2c_hulk*, u32 voice, u32 mb)
{
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_set_headroom(v, mb);
}
void w2c_hulk_aud_bins(struct w2c_hulk*, u32 voice, u32 bins, u32 n)
{
    HulkMixBin b[HULK_AUDIO_MAX_BINS];
    unsigned k = readBins(bins, n, b);
    if (HulkVoice* v = V(voice))
        hulk_audio_voice_set_bins(v, b, k);
}
void w2c_hulk_aud_listener(struct w2c_hulk*, u32 words)
{
    up();
    uint32_t w[12];
    memcpy(w, hulk_run_memory() + words, sizeof w);
    HulkI3DL2 l;
    float f[12];
    memcpy(f, w, sizeof f);
    l.room = (int)w[0];
    l.room_hf = (int)w[1];
    l.room_rolloff = f[2];
    l.decay_time = f[3];
    l.decay_hf_ratio = f[4];
    l.reflections = (int)w[5];
    l.reflections_delay = f[6];
    l.reverb = (int)w[7];
    l.reverb_delay = f[8];
    l.diffusion = f[9];
    l.density = f[10];
    l.hf_reference = f[11];
    hulk_audio_set_listener(&l);
}
u32 w2c_hulk_aud_status(struct w2c_hulk*, u32 voice)
{
    HulkVoice* v = V(voice);
    return v ? hulk_audio_voice_status(v) : 0;
}
u32 w2c_hulk_aud_where(struct w2c_hulk*, u32 voice)
{
    HulkVoice* v = V(voice);
    return v ? hulk_audio_voice_position(v) : 0;
}
void w2c_hulk_aud_work(struct w2c_hulk*)
{
    if (s_up)
        hulk_audio_do_work();
}

} // extern "C"
