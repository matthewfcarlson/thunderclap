// The Bink-shaped player (bink_player.h) on movie.h and the audio mixer's streaming voices. Our own code: the
// semantics are what the game's call sites need (docs/native-movies.md), the decoding is FFmpeg's.
#include "bink_player.h"

#include "../audio/hulk_audio.h"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_loadso.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>

#define MAX_TRACKS 8
#define VOICE_FRAMES 96000          // ring depth per track (2 s at 48 kHz)
#define AHEAD_MS 400                // audio kept queued (decoded) ahead of the play position

// the audio backend's log sink (the image routes it to its trace), else SDL_Log
static void mlog(const char* fmt, ...) SDL_PRINTF_VARARG_FUNC(1);
static void mlog(const char* fmt, ...)
{
    char line[256];
    va_list ap;
    va_start(ap, fmt);
    SDL_vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    if (hulk_audio_log_sink) {
        char out[300];
        SDL_snprintf(out, sizeof(out), "movies: %s", line);
        hulk_audio_log_sink(out);
    } else {
        SDL_Log("movies: %s", line);
    }
}

// The decoder is a separate library (LGPL FFmpeg behind movie.c, built as hulkmovie.dll / libhulkmovie.so): loaded
// when the first movie opens, so the game image carries no FFmpeg and runs without it (BinkOpen then fails and the
// game skips the movie, as it does when a movie file is missing). The host tests link movie.c in (HULK_MOVIE_STATIC).
#define MOVIE_FUNCS(X)                                                                              \
    X(open) X(close) X(info) X(track) X(select_tracks) X(decode_video) X(pump_audio) X(audio_queued) \
    X(audio_read) X(demux_done) X(to_bgra)

struct MovieApi {
#define X(n) decltype(&hulk_movie_##n) n;
    MOVIE_FUNCS(X)
#undef X
};
static MovieApi g_api;
static int g_api_state;             // 0 not tried, 1 ready, -1 unavailable

static bool movie_api()
{
    if (g_api_state)
        return g_api_state > 0;
    {
        // play1: HULK_MOVIES=0 skips every movie (the game treats a failed open as "no movie")
        const char* m = SDL_getenv("HULK_MOVIES");
        if (m && *m == '0') {
            g_api_state = -1;
            mlog("HULK_MOVIES=0: movies are skipped");
            return false;
        }
    }
#if defined(HULK_MOVIE_STATIC)
#define X(n) g_api.n = hulk_movie_##n;
    MOVIE_FUNCS(X)
#undef X
    g_api_state = 1;
#else
    const char* env = SDL_getenv("HULK_MOVIE_LIB");
    const char* names[] = {env, "hulkmovie.dll", "libhulkmovie.dylib", "libhulkmovie.so"};
    SDL_SharedObject* so = 0;
    for (unsigned i = 0; i < sizeof(names) / sizeof(names[0]) && !so; i++)
        if (names[i] && names[i][0])
            so = SDL_LoadObject(names[i]);
    g_api_state = so ? 1 : -1;
#define X(n)                                                                    \
    g_api.n = (decltype(&hulk_movie_##n))(so ? (void*)SDL_LoadFunction(so, "hulk_movie_" #n) : 0); \
    if (!g_api.n)                                                               \
        g_api_state = -1;
    MOVIE_FUNCS(X)
#undef X
#endif
    if (g_api_state < 0)
        mlog("the decoder library (hulkmovie.dll / libhulkmovie.so, HULK_MOVIE_LIB) is not available: movies are skipped");
    return g_api_state > 0;
}

struct TrackState {
    HulkMovieTrack info;
    int selected;
    HulkVoice* voice;
    unsigned bins[HULK_AUDIO_MAX_BINS];
    unsigned nbins;
    unsigned volume;                // 0..65536
    int mixed;                      // mix bins set by the game (else the default)
};

struct HulkBinkPrivate {
    HulkMovie* movie;
    const HulkMovieInfo* info;
    HulkMovieFrame cur;
    int have_cur;
    int decoded_for;                // frame number the current frame was decoded for (-1: none)
    int paused;
    unsigned long long resume_tick; // tick of the last unpause
    unsigned long long acc_ms;      // movie time before the last unpause (tick-based part)
    TrackState tracks[MAX_TRACKS];
    int ntracks;
    int audio_ready;                // voices exist
    int audio_playing;
    unsigned ref;                   // index of the reference track (the audio clock), -1: none
    int audio_ended;
    unsigned long long end_ms;      // the audio clock when the audio ran out
    unsigned long long end_tick;
    int warned_flags;
};

static unsigned g_track_ids[MAX_TRACKS];
static unsigned g_track_count;
static HulkBinkClock g_clock;

void hulk_bink_set_tracks(const unsigned* ids, unsigned count)
{
    if (count > MAX_TRACKS)
        count = MAX_TRACKS;
    for (unsigned i = 0; i < count; i++)
        g_track_ids[i] = ids[i];
    g_track_count = count;
}

void* hulk_bink_alloc(unsigned bytes)
{
    return SDL_calloc(1, bytes);
}

void hulk_bink_free(void* p)
{
    SDL_free(p);
}

void hulk_bink_set_clock(HulkBinkClock clock)
{
    g_clock = clock;
}

static unsigned long long now_ms()
{
    return g_clock ? g_clock() : (unsigned long long)SDL_GetTicks();
}

unsigned hulk_bink_ticks(void)
{
    return (unsigned)now_ms();
}

HulkBink* hulk_bink_open(const HulkMovieIO* io, unsigned flags)
{
    (void)flags;
    if (!movie_api()) {             // no decoder library: the movie cannot play
        if (io->close)
            io->close(io->ctx);
        return 0;
    }
    HulkMovie* m = g_api.open(io);
    if (!m) {
        mlog("not a playable Bink file");
        return 0;
    }
    HulkBink* b = (HulkBink*)SDL_calloc(1, sizeof(HulkBink));
    HulkBinkPrivate* p = (HulkBinkPrivate*)SDL_calloc(1, sizeof(HulkBinkPrivate));
    if (!b || !p) {
        SDL_free(b);
        SDL_free(p);
        g_api.close(m);
        return 0;
    }
    b->priv = p;
    p->movie = m;
    p->info = g_api.info(m);
    p->decoded_for = -1;
    p->paused = 1;
    p->ref = (unsigned)-1;
    b->width = (unsigned)p->info->width;
    b->height = (unsigned)p->info->height;
    b->frames = p->info->frames;
    b->frame_num = 0;
    int ids[MAX_TRACKS];
    int nsel = 0;
    for (int i = 0; i < p->info->tracks && p->ntracks < MAX_TRACKS; i++) {
        TrackState* t = &p->tracks[p->ntracks++];
        g_api.track(m, i, &t->info);
        t->volume = 65536;
        for (unsigned k = 0; k < g_track_count; k++)
            if ((int)g_track_ids[k] == t->info.id)
                t->selected = 1;
        if (t->selected && nsel < MAX_TRACKS)
            ids[nsel++] = t->info.id;
    }
    g_api.select_tracks(m, ids, nsel);
    mlog("opened %ux%u, %u frames at %d/%d fps, %d sound tracks (%d selected)", b->width, b->height, b->frames,
         p->info->fps_num, p->info->fps_den, p->info->tracks, nsel);
    return b;
}

static TrackState* find_track(HulkBinkPrivate* p, unsigned id)
{
    for (int i = 0; i < p->ntracks; i++)
        if ((unsigned)p->tracks[i].info.id == id)
            return &p->tracks[i];
    return 0;
}

void hulk_bink_set_mix_bins(HulkBink* b, unsigned track_id, const unsigned* bins, unsigned count)
{
    TrackState* t = find_track(b->priv, track_id);
    if (!t)
        return;
    if (count > HULK_AUDIO_MAX_BINS)
        count = HULK_AUDIO_MAX_BINS;
    for (unsigned i = 0; i < count; i++)
        t->bins[i] = bins[i];
    t->nbins = count;
    t->mixed = 1;
    if (t->voice) {
        HulkMixBin mb[HULK_AUDIO_MAX_BINS];
        for (unsigned i = 0; i < count; i++) {
            mb[i].bin = bins[i];
            mb[i].volume = 0;
        }
        hulk_audio_voice_set_bins(t->voice, mb, count);
    }
}

static int volume_mb(unsigned v)
{
    if (v == 0)
        return HULK_AUDIO_MIN_MB;
    if (v >= 65536)
        return 0;
    int mb = (int)(2000.0f * SDL_log10f((float)v / 65536.0f));
    return mb < HULK_AUDIO_MIN_MB ? HULK_AUDIO_MIN_MB : mb;
}

void hulk_bink_set_volume(HulkBink* b, unsigned track_id, unsigned volume)
{
    TrackState* t = find_track(b->priv, track_id);
    if (!t)
        return;
    t->volume = volume;
    if (t->voice)
        hulk_audio_voice_set_volume(t->voice, volume_mb(volume));
}

// ---------------------------------------------------------------------------------------------
// audio
static void make_voices(HulkBinkPrivate* p)
{
    if (p->audio_ready)
        return;
    p->audio_ready = 1;
    for (int i = 0; i < p->ntracks; i++) {
        TrackState* t = &p->tracks[i];
        if (!t->selected)
            continue;
        HulkAudioFormat fmt;
        fmt.codec = HULK_CODEC_PCM;
        fmt.channels = t->info.channels;
        fmt.bits = 16;
        fmt.rate = (unsigned)t->info.rate;
        HulkMixBin mb[HULK_AUDIO_MAX_BINS];
        unsigned n = 0;
        if (t->mixed) {
            for (; n < t->nbins; n++) {
                mb[n].bin = t->bins[n];
                mb[n].volume = 0;
            }
        } else {                    // unrouted: the front pair
            mb[0].bin = HULK_BIN_FRONT_LEFT;
            mb[0].volume = 0;
            mb[1].bin = HULK_BIN_FRONT_RIGHT;
            mb[1].volume = 0;
            n = 2;
        }
        t->voice = hulk_audio_stream_create(&fmt, mb, n, VOICE_FRAMES);
        if (t->voice) {
            hulk_audio_voice_set_volume(t->voice, volume_mb(t->volume));
            if (p->ref == (unsigned)-1)
                p->ref = (unsigned)i;
        }
    }
}

// moves decoded audio into the voices and reads more from the file: the voices hold AHEAD_MS of sound
static void feed_audio(HulkBinkPrivate* p)
{
    if (!p->audio_ready)
        return;
    static short buf[4096 * 2];     // (static: no stack probe in the image; one thread drives the player)
    for (int i = 0; i < p->ntracks; i++) {
        TrackState* t = &p->tracks[i];
        if (!t->voice)
            continue;
        unsigned want = (unsigned)t->info.rate * AHEAD_MS / 1000;
        unsigned queued = hulk_audio_stream_queued(t->voice);
        if (queued + g_api.audio_queued(p->movie, t->info.id) < want)
            g_api.pump_audio(p->movie, want - queued);
        for (;;) {
            unsigned room = VOICE_FRAMES - hulk_audio_stream_queued(t->voice);
            unsigned avail = g_api.audio_queued(p->movie, t->info.id);
            unsigned n = room < avail ? room : avail;
            if (n > 4096)
                n = 4096;
            if (n == 0)
                break;
            n = g_api.audio_read(p->movie, t->info.id, buf, n);
            hulk_audio_stream_write(t->voice, buf, n);
        }
    }
}

static void start_audio(HulkBinkPrivate* p)
{
    make_voices(p);
    feed_audio(p);
    for (int i = 0; i < p->ntracks; i++)
        if (p->tracks[i].voice)
            hulk_audio_voice_play(p->tracks[i].voice, 0);
    p->audio_playing = 1;
}

static void stop_audio(HulkBinkPrivate* p)
{
    for (int i = 0; i < p->ntracks; i++)
        if (p->tracks[i].voice)
            hulk_audio_voice_stop(p->tracks[i].voice);
    p->audio_playing = 0;
}

// ---------------------------------------------------------------------------------------------
// the clock: the audio's position when sound plays (Bink syncs to it), else the ticks since the unpause
static unsigned long long elapsed_ms(HulkBinkPrivate* p)
{
    unsigned long long tick = p->acc_ms + (p->paused ? 0 : now_ms() - p->resume_tick);
    if (p->ref == (unsigned)-1 || !p->audio_playing)
        return tick;
    TrackState* t = &p->tracks[p->ref];
    unsigned long long audio = hulk_audio_stream_played(t->voice) * 1000ull / (unsigned)t->info.rate;
    if (p->audio_ended)
        return p->end_ms + (tick > p->end_tick ? tick - p->end_tick : 0);
    if (hulk_audio_stream_queued(t->voice) == 0 && g_api.audio_queued(p->movie, t->info.id) == 0 &&
        g_api.demux_done(p->movie)) {
        p->audio_ended = 1;
        p->end_ms = audio;
        p->end_tick = tick;
        return audio;
    }
    // a stalled device (nothing consumed) must not freeze the picture: fall back to the ticks
    if (tick > audio + 750)
        return tick;
    return audio;
}

unsigned hulk_bink_time_ms(HulkBink* b)
{
    return (unsigned)elapsed_ms(b->priv);
}

unsigned hulk_bink_audio_ahead(HulkBink* b)
{
    HulkBinkPrivate* p = b->priv;
    if (p->ref == (unsigned)-1)
        return 0;
    TrackState* t = &p->tracks[p->ref];
    return hulk_audio_stream_queued(t->voice) + g_api.audio_queued(p->movie, t->info.id);
}

void hulk_bink_pause(HulkBink* b, int paused)
{
    HulkBinkPrivate* p = b->priv;
    paused = paused != 0;
    if (paused == p->paused)
        return;
    if (paused) {
        p->acc_ms += now_ms() - p->resume_tick;
        p->paused = 1;
        stop_audio(p);
    } else {
        p->resume_tick = now_ms();
        p->paused = 0;
        start_audio(p);
    }
}

int hulk_bink_wait(HulkBink* b)
{
    HulkBinkPrivate* p = b->priv;
    if (p->paused)
        return 1;
    feed_audio(p);
    unsigned long long t = elapsed_ms(p);
    // frame n is due at n * 1000 * den / num milliseconds
    unsigned long long due = (unsigned long long)b->frame_num * 1000ull * (unsigned)p->info->fps_den;
    return due > t * (unsigned)p->info->fps_num ? 1 : 0;
}

int hulk_bink_do_frame(HulkBink* b)
{
    HulkBinkPrivate* p = b->priv;
    if (p->decoded_for == (int)b->frame_num)
        return p->have_cur ? 0 : 1;
    p->have_cur = 0;
    p->decoded_for = (int)b->frame_num;
    int r = g_api.decode_video(p->movie, &p->cur);
    if (r <= 0)
        return 1;
    p->have_cur = 1;
    feed_audio(p);
    return 0;
}

int hulk_bink_copy_rect(HulkBink* b, void* dst, int pitch, unsigned dest_height, int dx, int dy, int sx, int sy,
                        int sw, int sh, unsigned flags)
{
    HulkBinkPrivate* p = b->priv;
    if (!p->have_cur || !dst || sw <= 0 || sh <= 0 || dx < 0 || dy < 0 || (unsigned)(dy + sh) > dest_height)
        return 0;
    if ((flags & 7) != 3 && !p->warned_flags) {
        p->warned_flags = 1;        // the game asks for 3 (a 32-bit surface); anything else gets the same pixels
    }
    unsigned char* base = (unsigned char*)dst;
    if (pitch >= 0) {
        g_api.to_bgra(&p->cur, base + (size_t)dy * (unsigned)pitch + (size_t)dx * 4, pitch, sx, sy, sw, sh);
    } else {
        // flipped: the rect's first row goes to the buffer row dest_height - 1 - dy, counted from the lowest address
        unsigned pos = (unsigned)-pitch;
        unsigned char* first = base + (size_t)(dest_height - 1 - (unsigned)dy) * pos + (size_t)dx * 4;
        g_api.to_bgra(&p->cur, first, pitch, sx, sy, sw, sh);
    }
    return 1;
}

void hulk_bink_next_frame(HulkBink* b)
{
    if (b->frames && b->frame_num + 1 < b->frames)
        b->frame_num++;
}

void hulk_bink_close(HulkBink* b)
{
    if (!b)
        return;
    HulkBinkPrivate* p = b->priv;
    for (int i = 0; i < p->ntracks; i++)
        if (p->tracks[i].voice)
            hulk_audio_voice_release(p->tracks[i].voice);
    g_api.close(p->movie);
    SDL_free(p);
    SDL_free(b);
}
