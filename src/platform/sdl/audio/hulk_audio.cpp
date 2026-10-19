// The native audio backend: our own mixer on SDL3 audio (hulk_audio.h, docs/native-audio-input.md).
//
// No C++ dynamic initializers here (the native image's start-up runs only the game's own initializer table):
// all state is plain zero-initialized data, set up by hulk_audio_init.
#include "audio_internal.h"

#include <SDL3/SDL.h>

hulk_audio_log_fn hulk_audio_log_sink;

static void alog(const char* fmt, ...)
{
    char line[256];
    va_list ap;
    va_start(ap, fmt);
    SDL_vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    if (hulk_audio_log_sink)
        hulk_audio_log_sink(line);
    else
        SDL_Log("audio: %s", line);
}

float hulk_audio_mb_gain(int mb)
{
    if (mb <= HULK_AUDIO_MIN_MB)
        return 0.0f;
    if (mb >= 0)
        return 1.0f;
    return SDL_powf(10.0f, (float)mb / 2000.0f);
}

struct HulkVoice {
    HulkVoice* next;
    HulkAudioFormat fmt;
    const unsigned char* data;
    unsigned bytes;
    unsigned frame_bytes;           // PCM: bytes per frame; ADPCM: bytes per block (36 x channels)
    unsigned long long frames;      // length in frames
    unsigned long long cursor;      // 32.32 fixed point, frames
    unsigned freq;
    unsigned headroom;
    int volume;
    int playing, looping;
    unsigned nbins;
    HulkMixBin bins[HULK_AUDIO_MAX_BINS];
    float gain_l[2], gain_r[2], gain_send[2];   // per source channel, recomputed when a volume changes
    long long block_index[2];       // ADPCM: two decoded blocks
    short block[2][HULK_XADPCM_SAMPLES * 2];
    unsigned char block_next;
    // streaming voices (hulk_audio_stream_*): a ring of 16-bit PCM the caller appends to; the mixer consumes it
    int stream;
    short* sring;
    unsigned scap, shead, scount;   // ring capacity, first queued frame, queued frames
    unsigned long long splayed;     // frames consumed so far
};

static struct {
    int initialized;
    SDL_Mutex* lock;
    SDL_AudioStream* stream;        // the device stream (0 without a device)
    int clock_mode, clock_set;
    unsigned frames_per_work;
    HulkVoice* voices;
    unsigned nvoices;
    HulkReverb reverb;
    HulkI3DL2 listener;
    unsigned long long rendered;
    unsigned long long wall_ns;     // without a device: last do_work's time
    // capture
    SDL_IOStream* cap;
    unsigned long long cap_frames;
    int cap_set;
    float* scratch;                 // render buffer for the frame clock / wall clock (stereo)
    float* send;                    // the bin-10 send, mono
    unsigned scratch_frames;
    int warned_bins;
    float sendbuf[1024];            // render_locked's bin-10 send (lock held)
    float devbuf[2 * 512];          // the device callback's buffer (its thread only)
} g_audio;

static void lock()
{
    if (g_audio.lock)
        SDL_LockMutex(g_audio.lock);
}

static void unlock()
{
    if (g_audio.lock)
        SDL_UnlockMutex(g_audio.lock);
}

// ---------------------------------------------------------------------------------------------
// capture: a 16-bit stereo 48 kHz WAV; the header is rewritten every second and at close
static void wav_header(SDL_IOStream* f, unsigned long long frames)
{
    unsigned data = (unsigned)(frames * 4);
    unsigned char h[44];
    SDL_memcpy(h, "RIFF", 4);
    unsigned riff = 36 + data;
    SDL_memcpy(h + 4, &riff, 4);
    SDL_memcpy(h + 8, "WAVEfmt ", 8);
    unsigned fmt_len = 16, rate = HULK_AUDIO_RATE, bps = HULK_AUDIO_RATE * 4;
    unsigned short tag = 1, ch = 2, align = 4, bits = 16;
    SDL_memcpy(h + 16, &fmt_len, 4);
    SDL_memcpy(h + 20, &tag, 2);
    SDL_memcpy(h + 22, &ch, 2);
    SDL_memcpy(h + 24, &rate, 4);
    SDL_memcpy(h + 28, &bps, 4);
    SDL_memcpy(h + 32, &align, 2);
    SDL_memcpy(h + 34, &bits, 2);
    SDL_memcpy(h + 36, "data", 4);
    SDL_memcpy(h + 40, &data, 4);
    Sint64 here = SDL_TellIO(f);
    SDL_SeekIO(f, 0, SDL_IO_SEEK_SET);
    SDL_WriteIO(f, h, 44);
    if (here > 44)
        SDL_SeekIO(f, here, SDL_IO_SEEK_SET);
}

static void capture_close()
{
    if (g_audio.cap) {
        wav_header(g_audio.cap, g_audio.cap_frames);
        SDL_CloseIO(g_audio.cap);
        g_audio.cap = 0;
    }
}

int hulk_audio_set_capture(const char* path)
{
    lock();
    capture_close();
    g_audio.cap_set = 1;
    g_audio.cap_frames = 0;
    if (path && *path) {
        g_audio.cap = SDL_IOFromFile(path, "wb");
        if (g_audio.cap)
            wav_header(g_audio.cap, 0);
        else
            alog("capture: can't open %s: %s", path, SDL_GetError());
    }
    unlock();
    return g_audio.cap != 0;
}

static void capture_write(const float* buf, unsigned frames)
{
    short tmp[512];
    unsigned done = 0;
    while (done < frames) {
        unsigned n = frames - done > 256 ? 256 : frames - done;
        for (unsigned i = 0; i < 2 * n; i++) {
            float v = buf[2 * done + i] * 32767.0f;
            tmp[i] = (short)(v > 32767.0f ? 32767 : v < -32768.0f ? -32768 : (int)SDL_lroundf(v));
        }
        SDL_WriteIO(g_audio.cap, tmp, n * 4);
        done += n;
    }
    unsigned long long before = g_audio.cap_frames;
    g_audio.cap_frames += frames;
    if (before / HULK_AUDIO_RATE != g_audio.cap_frames / HULK_AUDIO_RATE)
        wav_header(g_audio.cap, g_audio.cap_frames);
}

// ---------------------------------------------------------------------------------------------
// voices
static void voice_gains(HulkVoice* v)
{
    float head = hulk_audio_mb_gain(-(int)v->headroom);
    float vol = hulk_audio_mb_gain(v->volume) * head;
    for (int c = 0; c < 2; c++)
        v->gain_l[c] = v->gain_r[c] = v->gain_send[c] = 0.0f;
    const float k3db = 0.70710678f;
    for (unsigned i = 0; i < v->nbins; i++) {
        // a mono voice sends every bin; a stereo one sends bin i from channel i % 2
        int c = v->fmt.channels > 1 ? (int)(i & 1) : 0;
        float g = hulk_audio_mb_gain(v->bins[i].volume) * vol;
        switch (v->bins[i].bin) {
        case HULK_BIN_FRONT_LEFT:
        case HULK_BIN_BACK_LEFT:
            v->gain_l[c] += g;
            break;
        case HULK_BIN_FRONT_RIGHT:
        case HULK_BIN_BACK_RIGHT:
            v->gain_r[c] += g;
            break;
        case HULK_BIN_CENTER:
        case HULK_BIN_LFE:
            v->gain_l[c] += g * k3db;
            v->gain_r[c] += g * k3db;
            break;
        case HULK_BIN_I3DL2:
            v->gain_send[c] += g;
            break;
        default:
            if (!g_audio.warned_bins) {
                g_audio.warned_bins = 1;
                alog("mix bin %u not mixed (crosstalk / FX sends)", v->bins[i].bin);
            }
            break;
        }
    }
}

static void voice_length(HulkVoice* v)
{
    if (v->fmt.codec == HULK_CODEC_XADPCM) {
        v->frame_bytes = HULK_XADPCM_BLOCK * v->fmt.channels;
        v->frames = (unsigned long long)(v->bytes / v->frame_bytes) * HULK_XADPCM_SAMPLES;
    } else {
        v->frame_bytes = (unsigned)(v->fmt.bits / 8) * v->fmt.channels;
        if (v->frame_bytes == 0)
            v->frame_bytes = 1;
        v->frames = v->bytes / v->frame_bytes;
    }
    v->block_index[0] = v->block_index[1] = -1;
    if (v->frames == 0 || (v->cursor >> 32) >= v->frames)
        v->cursor = 0;
}

static HulkVoice* voice_create(const HulkAudioFormat* format, const HulkMixBin* bins, unsigned count,
                               unsigned stream_frames)
{
    hulk_audio_init();
    HulkVoice* v = (HulkVoice*)SDL_calloc(1, sizeof(HulkVoice));
    if (!v)
        return 0;
    if (stream_frames) {
        v->stream = 1;
        v->scap = stream_frames;
    }
    v->fmt = *format;
    if (v->fmt.channels < 1)
        v->fmt.channels = 1;
    if (v->fmt.channels > 2)
        v->fmt.channels = 2;
    if (v->fmt.codec == HULK_CODEC_PCM && v->fmt.bits != 8 && v->fmt.bits != 16)
        v->fmt.bits = 16;
    if (v->fmt.rate == 0)
        v->fmt.rate = HULK_AUDIO_RATE;
    v->freq = v->fmt.rate;
    v->nbins = count > HULK_AUDIO_MAX_BINS ? HULK_AUDIO_MAX_BINS : count;
    for (unsigned i = 0; i < v->nbins; i++)
        v->bins[i] = bins[i];
    if (count == 0 && bins == 0) {          // no mix bins given: front left and right at 0 dB
        v->nbins = 2;
        v->bins[0].bin = HULK_BIN_FRONT_LEFT;
        v->bins[1].bin = HULK_BIN_FRONT_RIGHT;
    }
    if (v->stream) {
        v->fmt.codec = HULK_CODEC_PCM;
        v->fmt.bits = 16;
        v->sring = (short*)SDL_calloc((size_t)v->scap * v->fmt.channels, sizeof(short));
        if (!v->sring) {
            SDL_free(v);
            return 0;
        }
    }
    voice_length(v);
    voice_gains(v);
    lock();
    v->next = g_audio.voices;
    g_audio.voices = v;
    g_audio.nvoices++;
    unlock();
    return v;
}

HulkVoice* hulk_audio_voice_create(const HulkAudioFormat* format, const HulkMixBin* bins, unsigned count)
{
    return voice_create(format, bins, count, 0);
}

HulkVoice* hulk_audio_stream_create(const HulkAudioFormat* format, const HulkMixBin* bins, unsigned count,
                                    unsigned capacity_frames)
{
    return voice_create(format, bins, count, capacity_frames ? capacity_frames : 1);
}

unsigned hulk_audio_stream_write(HulkVoice* v, const short* pcm, unsigned frames)
{
    if (!v || !v->stream)
        return 0;
    lock();
    unsigned room = v->scap - v->scount;
    if (frames > room)
        frames = room;
    unsigned ch = (unsigned)v->fmt.channels;
    unsigned tail = (v->shead + v->scount) % v->scap;
    unsigned first = v->scap - tail < frames ? v->scap - tail : frames;
    SDL_memcpy(v->sring + (size_t)tail * ch, pcm, (size_t)first * ch * sizeof(short));
    if (frames > first)
        SDL_memcpy(v->sring, pcm + (size_t)first * ch, (size_t)(frames - first) * ch * sizeof(short));
    v->scount += frames;
    unlock();
    return frames;
}

unsigned hulk_audio_stream_queued(HulkVoice* v)
{
    lock();
    unsigned n = v->stream ? v->scount : 0;
    unlock();
    return n;
}

unsigned long long hulk_audio_stream_played(HulkVoice* v)
{
    lock();
    unsigned long long n = v->splayed;
    unlock();
    return n;
}

void hulk_audio_stream_flush(HulkVoice* v)
{
    lock();
    if (v->stream) {
        v->splayed += v->scount;
        v->shead = v->scount = 0;
        v->cursor = 0;
    }
    unlock();
}

void hulk_audio_voice_release(HulkVoice* v)
{
    if (!v)
        return;
    lock();
    for (HulkVoice** p = &g_audio.voices; *p; p = &(*p)->next)
        if (*p == v) {
            *p = v->next;
            g_audio.nvoices--;
            break;
        }
    unlock();
    SDL_free(v->sring);
    SDL_free(v);
}

void hulk_audio_voice_set_data(HulkVoice* v, const void* data, unsigned bytes)
{
    if (v->stream)
        return;
    lock();
    v->data = (const unsigned char*)data;
    v->bytes = data ? bytes : 0;
    voice_length(v);
    if (v->frames == 0)
        v->playing = 0;
    unlock();
}

int hulk_audio_voice_play(HulkVoice* v, int loop)
{
    lock();
    v->looping = loop != 0;
    v->playing = v->frames != 0 || v->stream;
    unlock();
    return 0;
}

void hulk_audio_voice_stop(HulkVoice* v)
{
    lock();
    v->playing = 0;
    unlock();
}

unsigned hulk_audio_voice_status(HulkVoice* v)
{
    lock();
    unsigned s = (v->playing ? HULK_STATUS_PLAYING : 0) | (v->playing && v->looping ? HULK_STATUS_LOOPING : 0);
    unlock();
    return s;
}

static unsigned frame_to_bytes(const HulkVoice* v, unsigned long long frame)
{
    if (v->fmt.codec == HULK_CODEC_XADPCM) {
        unsigned long long block = frame / HULK_XADPCM_SAMPLES;
        unsigned in = (unsigned)(frame % HULK_XADPCM_SAMPLES);
        return (unsigned)(block * v->frame_bytes + in * v->frame_bytes / HULK_XADPCM_SAMPLES);
    }
    return (unsigned)(frame * v->frame_bytes);
}

unsigned hulk_audio_voice_position(HulkVoice* v)
{
    lock();
    unsigned b = frame_to_bytes(v, v->cursor >> 32);
    unlock();
    return b;
}

void hulk_audio_voice_set_position(HulkVoice* v, unsigned bytes)
{
    lock();
    unsigned long long frame;
    if (v->fmt.codec == HULK_CODEC_XADPCM)
        frame = (unsigned long long)(bytes / v->frame_bytes) * HULK_XADPCM_SAMPLES +
                (bytes % v->frame_bytes) * HULK_XADPCM_SAMPLES / v->frame_bytes;
    else
        frame = bytes / v->frame_bytes;
    if (frame >= v->frames)
        frame = 0;
    v->cursor = frame << 32;
    unlock();
}

void hulk_audio_voice_set_frequency(HulkVoice* v, unsigned hz)
{
    lock();
    v->freq = hz ? hz : v->fmt.rate;
    unlock();
}

void hulk_audio_voice_set_headroom(HulkVoice* v, unsigned mb)
{
    lock();
    v->headroom = mb > 10000 ? 10000 : mb;
    voice_gains(v);
    unlock();
}

void hulk_audio_voice_set_volume(HulkVoice* v, int mb)
{
    lock();
    v->volume = mb > 0 ? 0 : mb;
    voice_gains(v);
    unlock();
}

void hulk_audio_voice_set_bins(HulkVoice* v, const HulkMixBin* bins, unsigned count)
{
    lock();
    for (unsigned i = 0; i < count; i++) {
        unsigned j = 0;
        while (j < v->nbins && v->bins[j].bin != bins[i].bin)
            j++;
        if (j == v->nbins) {
            if (v->nbins == HULK_AUDIO_MAX_BINS)
                continue;
            v->nbins++;
            v->bins[j].bin = bins[i].bin;
        }
        v->bins[j].volume = bins[i].volume > 0 ? 0 : bins[i].volume;
    }
    voice_gains(v);
    unlock();
}

void hulk_audio_set_listener(const HulkI3DL2* l)
{
    lock();
    g_audio.listener = *l;
    hulk_reverb_set(&g_audio.reverb, l);
    unlock();
}

// ---------------------------------------------------------------------------------------------
// mixing (lock held)
static float sample_at(HulkVoice* v, unsigned long long frame, int c)
{
    if (frame >= v->frames) {
        if (!v->looping || v->frames == 0)
            return 0.0f;
        frame %= v->frames;
    }
    if (v->fmt.codec == HULK_CODEC_XADPCM) {
        long long blk = (long long)(frame / HULK_XADPCM_SAMPLES);
        int slot = v->block_index[0] == blk ? 0 : v->block_index[1] == blk ? 1 : -1;
        if (slot < 0) {
            slot = v->block_next;
            v->block_next ^= 1;
            hulk_xadpcm_decode_block(v->data + blk * v->frame_bytes, v->fmt.channels, v->block[slot]);
            v->block_index[slot] = blk;
        }
        return v->block[slot][(frame % HULK_XADPCM_SAMPLES) * v->fmt.channels + c] * (1.0f / 32768.0f);
    }
    const unsigned char* p = v->data + frame * v->frame_bytes;
    if (v->fmt.bits == 8)
        return ((int)p[c] - 128) * (1.0f / 128.0f);
    short s = (short)(p[2 * c] | (p[2 * c + 1] << 8));
    return s * (1.0f / 32768.0f);
}

// a streaming voice: the queued frames, resampled to the mixer's rate; no data -> silence, and the voice waits
static void mix_stream(HulkVoice* v, float* out, float* send, unsigned n)
{
    unsigned long long step = ((unsigned long long)v->freq << 32) / HULK_AUDIO_RATE;
    unsigned ch = (unsigned)v->fmt.channels;
    for (unsigned f = 0; f < n; f++) {
        unsigned long long i = v->cursor >> 32;
        if (i >= v->scount)
            break;                  // underrun
        float frac = (float)(unsigned)(v->cursor & 0xffffffffu) * (1.0f / 4294967296.0f);
        const short* a = v->sring + (size_t)((v->shead + i) % v->scap) * ch;
        const short* b = i + 1 < v->scount ? v->sring + (size_t)((v->shead + i + 1) % v->scap) * ch : a;
        for (unsigned c = 0; c < ch; c++) {
            float s = (a[c] + (b[c] - a[c]) * frac) * (1.0f / 32768.0f);
            out[2 * f] += s * v->gain_l[c];
            out[2 * f + 1] += s * v->gain_r[c];
            send[f] += s * v->gain_send[c];
        }
        v->cursor += step;
    }
    unsigned long long used = v->cursor >> 32;
    if (used > v->scount)
        used = v->scount;
    v->shead = (unsigned)((v->shead + used) % v->scap);
    v->scount -= (unsigned)used;
    v->splayed += used;
    v->cursor -= used << 32;
}

static void mix_voice(HulkVoice* v, float* out, float* send, unsigned n)
{
    if (v->stream) {
        if (v->playing)
            mix_stream(v, out, send, n);
        return;
    }
    if (!v->playing || !v->data || v->frames == 0)
        return;
    unsigned long long step = ((unsigned long long)v->freq << 32) / HULK_AUDIO_RATE;
    unsigned long long end = v->frames << 32;
    int chans = v->fmt.channels;
    for (unsigned f = 0; f < n; f++) {
        unsigned long long i = v->cursor >> 32;
        float frac = (float)(unsigned)(v->cursor & 0xffffffffu) * (1.0f / 4294967296.0f);
        for (int c = 0; c < chans; c++) {
            float a = sample_at(v, i, c), b = sample_at(v, i + 1, c);
            float s = a + (b - a) * frac;
            out[2 * f] += s * v->gain_l[c];
            out[2 * f + 1] += s * v->gain_r[c];
            send[f] += s * v->gain_send[c];
        }
        v->cursor += step;
        if (v->cursor >= end) {
            if (v->looping) {
                v->cursor %= end;
            } else {
                // a one-shot buffer stops at its end; its position reads 0 again
                v->cursor = 0;
                v->playing = 0;
                return;
            }
        }
    }
}

static void render_locked(float* out, unsigned frames)
{
    // the send buffer: reuse scratch space in chunks
    unsigned done = 0;
    while (done < frames) {
        unsigned n = frames - done;
        if (n > 1024)
            n = 1024;
        float* send = g_audio.sendbuf;     // (static: no stack frame over a page, so no __chkstk in the image)
        float* o = out + 2 * done;
        SDL_memset(o, 0, n * 2 * sizeof(float));
        SDL_memset(send, 0, n * sizeof(float));
        for (HulkVoice* v = g_audio.voices; v; v = v->next)
            mix_voice(v, o, send, n);
        hulk_reverb_process(&g_audio.reverb, send, o, n);
        for (unsigned i = 0; i < 2 * n; i++)
            o[i] = o[i] > 1.0f ? 1.0f : o[i] < -1.0f ? -1.0f : o[i];
        done += n;
    }
    g_audio.rendered += frames;
    if (g_audio.cap)
        capture_write(out, frames);
}

void hulk_audio_render(float* out, unsigned frames)
{
    lock();
    render_locked(out, frames);
    unlock();
}

// the device pulls (device clock)
static void SDLCALL device_callback(void* user, SDL_AudioStream* stream, int additional, int total)
{
    (void)user;
    (void)total;
    float* buf = g_audio.devbuf;
    while (additional > 0) {
        unsigned frames = (unsigned)additional / 8;
        if (frames == 0)
            frames = 1;
        if (frames > 512)
            frames = 512;
        hulk_audio_render(buf, frames);
        SDL_PutAudioStreamData(stream, buf, (int)(frames * 8));
        additional -= (int)(frames * 8);
    }
}

// renders `frames` into the scratch buffer and queues them to the device (frame clock, wall clock)
static void render_and_queue(unsigned frames)
{
    while (frames > 0) {
        unsigned n = frames > 4096 ? 4096 : frames;
        if (g_audio.scratch_frames < n) {
            SDL_free(g_audio.scratch);
            g_audio.scratch = (float*)SDL_malloc(n * 2 * sizeof(float));
            g_audio.scratch_frames = g_audio.scratch ? n : 0;
            if (!g_audio.scratch)
                return;
        }
        lock();
        render_locked(g_audio.scratch, n);
        unlock();
        // (a game running faster than real time would grow the queue without bound: past a quarter second the
        // rendered frames are dropped; the voices have advanced all the same, which is what keeps it deterministic)
        if (g_audio.stream && SDL_GetAudioStreamQueued(g_audio.stream) < HULK_AUDIO_RATE * 8 / 4)
            SDL_PutAudioStreamData(g_audio.stream, g_audio.scratch, (int)(n * 8));
        frames -= n;
    }
}

void hulk_audio_do_work(void)
{
    if (!g_audio.initialized)
        return;
    if (g_audio.clock_mode == HULK_CLOCK_FRAME) {
        render_and_queue(g_audio.frames_per_work);
    } else if (g_audio.clock_mode == HULK_CLOCK_DEVICE && !g_audio.stream) {
        // no device: advance by wall time so one-shot sounds still end
        unsigned long long now = SDL_GetTicksNS();
        if (g_audio.wall_ns) {
            unsigned long long frames = (now - g_audio.wall_ns) * HULK_AUDIO_RATE / 1000000000ull;
            if (frames > HULK_AUDIO_RATE / 4)
                frames = HULK_AUDIO_RATE / 4;           // a long stall doesn't fast-forward everything
            render_and_queue((unsigned)frames);
            g_audio.wall_ns += frames * 1000000000ull / HULK_AUDIO_RATE;
            if (now - g_audio.wall_ns > 1000000000ull)
                g_audio.wall_ns = now;
        } else {
            g_audio.wall_ns = now;
        }
    }
}

void hulk_audio_set_clock(int mode, unsigned frames_per_work)
{
    g_audio.clock_mode = mode;
    g_audio.frames_per_work = frames_per_work ? frames_per_work : HULK_AUDIO_RATE / 60;
    g_audio.clock_set = 1;
}

int hulk_audio_has_device(void)
{
    return g_audio.stream != 0;
}

int hulk_audio_init(void)
{
    if (g_audio.initialized)
        return 1;
    g_audio.initialized = 1;
    g_audio.lock = SDL_CreateMutex();
    hulk_reverb_reset(&g_audio.reverb);
    HulkI3DL2 off;                     // reverb off until the game sets a listener
    SDL_memset(&off, 0, sizeof(off));
    off.room = off.room_hf = off.reflections = off.reverb = HULK_AUDIO_MIN_MB;
    off.decay_time = off.decay_hf_ratio = 1.0f;
    off.hf_reference = 5000.0f;
    g_audio.listener = off;
    hulk_reverb_set(&g_audio.reverb, &off);
    if (!g_audio.clock_set) {
        const char* c = SDL_getenv("HULK_AUDIO_CLOCK");
        unsigned n = 0;
        int mode = HULK_CLOCK_DEVICE;
        if (c && SDL_strncmp(c, "frame", 5) == 0) {
            mode = HULK_CLOCK_FRAME;
            if (c[5] == ':')
                n = (unsigned)SDL_atoi(c + 6);
        } else if (c && SDL_strcmp(c, "manual") == 0) {
            mode = HULK_CLOCK_MANUAL;
        }
        hulk_audio_set_clock(mode, n);
    }
    if (!g_audio.cap_set) {
        const char* cap = SDL_getenv("HULK_AUDIO_CAPTURE");
        if (cap && *cap)
            hulk_audio_set_capture(cap);
    }
    if (g_audio.clock_mode != HULK_CLOCK_MANUAL) {
        if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
            alog("SDL audio init failed (%s): mixing without a device", SDL_GetError());
        } else {
            SDL_AudioSpec spec;
            spec.format = SDL_AUDIO_F32;
            spec.channels = 2;
            spec.freq = HULK_AUDIO_RATE;
            g_audio.stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec,
                                                       g_audio.clock_mode == HULK_CLOCK_DEVICE ? device_callback : 0, 0);
            if (!g_audio.stream)
                alog("no playback device (%s): mixing without a device", SDL_GetError());
            else
                SDL_ResumeAudioStreamDevice(g_audio.stream);
        }
    }
    alog("mixer up: clock %s%s, device %s (%s), capture %s",
         g_audio.clock_mode == HULK_CLOCK_FRAME ? "frame" : g_audio.clock_mode == HULK_CLOCK_MANUAL ? "manual" : "device",
         "", g_audio.stream ? "open" : "none", SDL_GetCurrentAudioDriver() ? SDL_GetCurrentAudioDriver() : "-",
         g_audio.cap ? "on" : "off");
    return 1;
}

void hulk_audio_shutdown(void)
{
    if (!g_audio.initialized)
        return;
    if (g_audio.stream) {
        SDL_DestroyAudioStream(g_audio.stream);     // stops the callback before the voices go
        g_audio.stream = 0;
    }
    lock();
    capture_close();
    HulkVoice* v = g_audio.voices;
    g_audio.voices = 0;
    g_audio.nvoices = 0;
    unlock();
    while (v) {
        HulkVoice* n = v->next;
        SDL_free(v);
        v = n;
    }
    SDL_free(g_audio.scratch);
    g_audio.scratch = 0;
    g_audio.scratch_frames = 0;
    if (g_audio.lock)
        SDL_DestroyMutex(g_audio.lock);
    g_audio.lock = 0;
    g_audio.initialized = 0;
    g_audio.clock_set = 0;
    g_audio.cap_set = 0;
    g_audio.rendered = 0;
    g_audio.wall_ns = 0;
}

void hulk_audio_stats(unsigned* voices, unsigned* playing, unsigned long long* frames)
{
    lock();
    unsigned np = 0;
    for (HulkVoice* v = g_audio.voices; v; v = v->next)
        np += v->playing != 0;
    if (voices)
        *voices = g_audio.nvoices;
    if (playing)
        *playing = np;
    if (frames)
        *frames = g_audio.rendered;
    unlock();
}
