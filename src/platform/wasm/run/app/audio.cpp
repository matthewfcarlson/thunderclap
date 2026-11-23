// The app's audio, the runner's half (docs/wasm-port.md "The macOS app"): the `hulk` imports aud_* of a
// HULK_WASM_GFX=1 module (src/platform/wasm/gfx/audio.c) on the SDL layer's mixer (src/platform/sdl/audio/: Xbox
// ADPCM, mix bins folded to stereo, the I3DL2 reverb), clocked by the game (D222): the mixer's voices are a mirror of
// the module's model (dsound_null.c), driven by the same calls, and aud_tick renders the frames the model's voices
// just played (HULK_CLOCK_MANUAL: the mixer never advances on its own). The rendered frames go to SDL's playback
// device through a queue; the game's clock is paced to real time, and what is left between the two clocks (the
// device's crystal, a frame that took longer) is taken up by the queue: its fill steers the device stream's rate
// within +-0.5% (inaudible); past MAX_QUEUE (a jump of the game's clock: a load, a movie's waits) frames are dropped
// until the device has played the queue down to TARGET_QUEUE. A voice
// plays the game's buffer in the module's linear memory where the game wrote it (the memory never moves: no growth).
// Nothing here flows back into the game: its voices' status and positions are the model's.
#include <stdint.h>
#include <string.h>

#include <unordered_map>

#include "audio/hulk_audio.cpp"
#include "audio/reverb.cpp"
#include "audio/xadpcm.cpp"

typedef uint32_t u32;
struct w2c_hulk;
extern "C" uint8_t* hulk_run_memory(void);    // run/native.c
extern "C" void hulk_app_movie_tick(unsigned frames);     // run/app/movie.c: the movies' voices hold the slice

static std::unordered_map<u32, HulkVoice*> s_voices;
static bool s_up;
static SDL_AudioStream* s_dev;              // the playback device's stream (0 without one: rendering still happens)

static void up()
{
    if (s_up)
        return;
    s_up = true;
    hulk_audio_set_clock(HULK_CLOCK_MANUAL, 0);
    hulk_audio_init();
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        SDL_Log("audio: SDL audio init failed (%s): no output", SDL_GetError());
        return;
    }
    SDL_AudioSpec spec;
    spec.format = SDL_AUDIO_F32;
    spec.channels = 2;
    spec.freq = HULK_AUDIO_RATE;
    s_dev = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, nullptr, nullptr);
    if (!s_dev)
        SDL_Log("audio: no playback device (%s): no output", SDL_GetError());
    else
        SDL_ResumeAudioStreamDevice(s_dev);
}

// the queue between the game's clock and the device's (frames of 48 kHz stereo float)
#define TARGET_QUEUE (HULK_AUDIO_RATE / 15)          // ~67 ms: two 30 Hz frames of production
#define MAX_QUEUE (HULK_AUDIO_RATE * 3 / 10)         // past 300 ms the newest frames are dropped
static struct {
    unsigned long long produced, dropped, starved;
    double avg;                 // the queue's fill, smoothed over ~0.5 s of production
    float ratio;
    unsigned long long next_steer, next_log;
    uint64_t t0_ns;
    int log, dropping;
} s_q = {0, 0, 0, 0.0, 1.0f, 0, 0, 0, -1, 0};

static void queue_out(const float* buf, unsigned n)
{
    s_q.produced += n;
    if (!s_dev)
        return;
    unsigned q = (unsigned)SDL_GetAudioStreamQueued(s_dev) / 8;
    if (q == 0 && s_q.produced > (unsigned long long)n)
        s_q.starved++;
    if (q + n > MAX_QUEUE)
        s_q.dropping = 1;
    else if (q <= TARGET_QUEUE)
        s_q.dropping = 0;
    if (s_q.dropping) {
        s_q.dropped += n;
        return;
    }
    SDL_PutAudioStreamData(s_dev, buf, (int)(n * 8));
    double a = (double)n / (HULK_AUDIO_RATE / 2);
    if (a > 1)
        a = 1;
    s_q.avg += (q + n - s_q.avg) * a;
    if (s_q.produced >= s_q.next_steer) {           // ten times a second: the rate follows the fill
        s_q.next_steer = s_q.produced + HULK_AUDIO_RATE / 10;
        float r = 1.0f + 0.005f * (float)((s_q.avg - TARGET_QUEUE) / TARGET_QUEUE);
        r = r < 0.995f ? 0.995f : r > 1.005f ? 1.005f : r;
        if (r != s_q.ratio) {
            s_q.ratio = r;
            SDL_SetAudioStreamFrequencyRatio(s_dev, r);
        }
    }
}

static void tick_log()
{
    if (s_q.log < 0) {
        const char* e = SDL_getenv("HULK_AUDIO_LOG");
        s_q.log = e && *e && *e != '0';
        s_q.t0_ns = SDL_GetTicksNS();
    }
    if (!s_q.log || s_q.produced < s_q.next_log)
        return;
    s_q.next_log = s_q.produced + 5ull * HULK_AUDIO_RATE;
    double real = (double)(SDL_GetTicksNS() - s_q.t0_ns) / 1e9, game = (double)s_q.produced / HULK_AUDIO_RATE;
    SDL_Log("audio: game %.2f s, real %.2f s (%.4f), queue %u frames (avg %.0f), rate %.4f, dropped %llu, starved %llu",
            game, real, real > 0 ? game / real : 0.0, s_dev ? (unsigned)SDL_GetAudioStreamQueued(s_dev) / 8 : 0u,
            s_q.avg, s_q.ratio, s_q.dropped, s_q.starved);
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
// the model's voices are about to move on by `frames`: render them from the mirror (which moves on the same)
void w2c_hulk_aud_tick(struct w2c_hulk*, u32 frames)
{
    up();
    static float buf[2 * 1024];
    while (frames) {
        unsigned n = frames > 1024 ? 1024 : frames;
        hulk_app_movie_tick(n);
        hulk_audio_render(buf, n);
        queue_out(buf, n);
        frames -= n;
    }
    tick_log();
}

// a snapshot was put back: phase 0 begins, 1 gives a model voice (w: ADPCM, channels, bits, rate, data, bytes, frequency,
// status, position), 2 ends (the mirror's voices the model didn't name are released)
void w2c_hulk_aud_resync(struct w2c_hulk*, u32 phase, u32 voice, u32 words)
{
    static std::unordered_map<u32, bool> seen;
    if (phase == 0) {
        seen.clear();
        return;
    }
    if (phase == 2) {
        for (auto it = s_voices.begin(); it != s_voices.end();) {
            if (!seen.count(it->first)) {
                hulk_audio_voice_release(it->second);
                it = s_voices.erase(it);
            } else {
                ++it;
            }
        }
        return;
    }
    uint32_t w[9];
    memcpy(w, hulk_run_memory() + words, sizeof w);
    seen[voice] = true;
    HulkVoice* v = V(voice);
    if (!v) {
        up();
        HulkAudioFormat f;
        f.codec = w[0] ? HULK_CODEC_XADPCM : HULK_CODEC_PCM;
        f.channels = (int)w[1];
        f.bits = (int)w[2];
        f.rate = w[3];
        v = s_voices[voice] = hulk_audio_voice_create(&f, nullptr, 0);
        if (!v)
            return;
    }
    hulk_audio_voice_set_data(v, w[4] ? hulk_run_memory() + w[4] : nullptr, w[5]);
    hulk_audio_voice_set_frequency(v, w[6]);
    hulk_audio_voice_set_position(v, w[8]);
    if (w[7] & 1)
        hulk_audio_voice_play(v, (int)(w[7] >> 2 & 1));
    else
        hulk_audio_voice_stop(v);
}

// the app quits (start.cpp hulk_app_quit, after the movies' voices are released): the device stopped, the mixer down
void hulk_app_audio_quit(void)
{
    if (s_dev) {
        SDL_DestroyAudioStream(s_dev);
        s_dev = nullptr;
    }
    s_voices.clear();
    if (s_up)
        hulk_audio_shutdown();
    s_up = false;
}

} // extern "C"
