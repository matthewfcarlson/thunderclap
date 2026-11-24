/* The app's movies, the runner's half (wmov1; docs/wasm-port.md "The macOS app"): the `hulk` imports mov_* of a
 * HULK_WASM_GFX=1 module (src/platform/wasm/gfx/movie.c). The decoder is the SDL layer's (src/platform/sdl/movies/
 * movie.c, included below: FFmpeg's bink demuxer and decoders, no RAD code) on FFmpeg's own shared libraries, loaded
 * at run time from the user's installation (Homebrew's by default; HULK_FFMPEG_DIR): nothing of FFmpeg is linked into
 * or shipped with the app. Without them (or with libraries of another major version than the headers the app was
 * built with) every movie plays black with its timing unchanged, and one log line says why.
 *
 * Nothing here is read by the game. The movie's bytes come straight from the disc's archive (the name the game opened
 * hashed as the game's file system does: docs/formats/rcf.md), never through the game's I/O callbacks, so decoding
 * moves no game state. The picture of the frame the handle's frame number names is written into the game's lock at
 * BinkCopyToBufferRect (decoded forward on demand; a frame behind the decoder reopens the movie and decodes up to it:
 * a restore). The sound tracks play on the app's mixer as streaming voices (hulk_audio_stream_*) that start and stop
 * with the movie's pause state and are topped up just before every slice the mixer renders (hulk_app_movie_tick, from
 * run/app/audio.cpp's aud_tick), so they advance with the same 48 kHz of game time as the DirectSound model (D222).
 * After a restore (mov_resync) the movies the restored state doesn't hold are closed and the sound of the others is
 * re-seeked to the movie's time. HULK_MOVIE_LOG=1 logs opens, pauses, closes and restores. */
#include <dirent.h>
#include <math.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>

#include "audio/hulk_audio.h"
#include "../disc.h"

typedef uint32_t u32;
struct w2c_hulk;
uint8_t* hulk_run_memory(void);             /* run/native.c */
uint64_t hulk_run_memory_size(void);

static int s_log = -1;
static void mvlog(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void mvlog(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fputs("movies: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
}
#define VLOG(...) do { if (s_log < 0) s_log = getenv("HULK_MOVIE_LOG") && getenv("HULK_MOVIE_LOG")[0] == '1'; \
                       if (s_log) mvlog(__VA_ARGS__); } while (0)

/* ------------------------------------------------------------------------------------ FFmpeg, loaded at run time */
#if defined(HULK_HAVE_FFMPEG)
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/error.h>
#include <libavutil/log.h>
#include <libavutil/mem.h>

#define FF_FUNCS(X)                                                                                                   \
    X(avutil, av_frame_alloc) X(avutil, av_frame_free) X(avutil, av_frame_unref) X(avutil, av_free)                   \
    X(avutil, av_freep) X(avutil, av_log_set_level) X(avutil, av_malloc) X(avutil, av_strerror)                       \
    X(avutil, avutil_version) X(avcodec, av_packet_alloc) X(avcodec, av_packet_free) X(avcodec, av_packet_move_ref)   \
    X(avcodec, av_packet_unref) X(avcodec, avcodec_find_decoder) X(avcodec, avcodec_free_context)                    \
    X(avcodec, avcodec_alloc_context3) X(avcodec, avcodec_open2) X(avcodec, avcodec_parameters_to_context)            \
    X(avcodec, avcodec_receive_frame) X(avcodec, avcodec_send_packet) X(avcodec, avcodec_version)                     \
    X(avformat, av_find_input_format) X(avformat, av_read_frame) X(avformat, avformat_alloc_context)                  \
    X(avformat, avformat_close_input) X(avformat, avformat_open_input) X(avformat, avformat_version)                  \
    X(avformat, avio_alloc_context) X(avformat, avio_context_free)

static struct {
#define X(lib, n) __typeof__(&n) n;
    FF_FUNCS(X)
#undef X
} ff;


static void* ff_lib(const char* name, int major) {
    char path[1024];
    const char* dirs[] = {getenv("HULK_FFMPEG_DIR"), HULK_FFMPEG_LIBDIR, "/opt/homebrew/lib", "/usr/local/lib"};
    for (unsigned i = 0; i < sizeof dirs / sizeof dirs[0]; i++) {
        if (!dirs[i] || !*dirs[i]) continue;
#if defined(__APPLE__)
        snprintf(path, sizeof path, "%s/lib%s.%d.dylib", dirs[i], name, major);
#elif defined(__ANDROID__)   /* (FFmpeg's android target gives plain sonames; HULK_FFMPEG_DIR from GameActivity: wand1) */
        snprintf(path, sizeof path, "%s/lib%s.so", dirs[i], name);
        (void)major;
#else   /* (Linux: the versioned soname; wlinux1) */
        snprintf(path, sizeof path, "%s/lib%s.so.%d", dirs[i], name, major);
#endif
        void* h = dlopen(path, RTLD_NOW | RTLD_LOCAL);
        if (h) return h;
    }
#if defined(__linux__) && !defined(__ANDROID__)
    /* (wlinux1) the soname alone: the runner's RUNPATH ($ORIGIN/lib, a bundle's own copies), then the system's
       libraries (a distribution's FFmpeg of the same major versions) */
    snprintf(path, sizeof path, "lib%s.so.%d", name, major);
    return dlopen(path, RTLD_NOW | RTLD_LOCAL);
#else
    return 0;
#endif
}

/* 1: the decoder is there */
static int ff_up(void) {
    static int state;
    if (state) return state > 0;
    state = -1;
    const char* e = getenv("HULK_MOVIES");
    if (e && *e == '0') return 0;
    void* avutil = ff_lib("avutil", LIBAVUTIL_VERSION_MAJOR);
    void* avcodec = avutil ? ff_lib("avcodec", LIBAVCODEC_VERSION_MAJOR) : 0;
    void* avformat = avcodec ? ff_lib("avformat", LIBAVFORMAT_VERSION_MAJOR) : 0;
    if (!avformat) {
        mvlog("FFmpeg's libavutil.%d / libavcodec.%d / libavformat.%d are not installed (Homebrew: `brew install "
             "ffmpeg`; or HULK_FFMPEG_DIR): movies play black", LIBAVUTIL_VERSION_MAJOR, LIBAVCODEC_VERSION_MAJOR,
             LIBAVFORMAT_VERSION_MAJOR);
        return 0;
    }
#define X(lib, n) if (!(ff.n = (__typeof__(&n))dlsym(lib, #n))) { mvlog("FFmpeg: no %s: movies play black", #n); return 0; }
    FF_FUNCS(X)
#undef X
    if (ff.avcodec_version() >> 16 != LIBAVCODEC_VERSION_MAJOR ||
        ff.avformat_version() >> 16 != LIBAVFORMAT_VERSION_MAJOR || ff.avutil_version() >> 16 != LIBAVUTIL_VERSION_MAJOR) {
        mvlog("FFmpeg's libraries are not the version the app was built with: movies play black");
        return 0;
    }
    state = 1;
    VLOG("FFmpeg libavcodec %u.%u loaded", ff.avcodec_version() >> 16, ff.avcodec_version() >> 8 & 0xff);
    return 1;
}
/* movie.c calls FFmpeg by name: those names are the table's entries in this file */
#define av_frame_alloc ff.av_frame_alloc
#define av_frame_free ff.av_frame_free
#define av_frame_unref ff.av_frame_unref
#define av_free ff.av_free
#define av_freep ff.av_freep
#define av_log_set_level ff.av_log_set_level
#define av_malloc ff.av_malloc
#define av_strerror ff.av_strerror
#define av_packet_alloc ff.av_packet_alloc
#define av_packet_free ff.av_packet_free
#define av_packet_move_ref ff.av_packet_move_ref
#define av_packet_unref ff.av_packet_unref
#define avcodec_find_decoder ff.avcodec_find_decoder
#define avcodec_free_context ff.avcodec_free_context
#define avcodec_alloc_context3 ff.avcodec_alloc_context3
#define avcodec_open2 ff.avcodec_open2
#define avcodec_parameters_to_context ff.avcodec_parameters_to_context
#define avcodec_receive_frame ff.avcodec_receive_frame
#define avcodec_send_packet ff.avcodec_send_packet
/* (a disc pack's AV1 movie opens as Matroska: movie.c asks for the bink demuxer by name) */
static const char* s_fmt_override;
#define av_find_input_format(n) ff.av_find_input_format(s_fmt_override ? s_fmt_override : (n))
#define av_read_frame ff.av_read_frame
#define avformat_alloc_context ff.avformat_alloc_context
#define avformat_close_input ff.avformat_close_input
#define avformat_open_input ff.avformat_open_input
#define avio_alloc_context ff.avio_alloc_context
#define avio_context_free ff.avio_context_free
#include "../../../sdl/movies/movie.c"
#else
#include "../../../sdl/movies/movie.h"
typedef struct HulkMovie HulkMovie;
static int ff_up(void) {
    static int said;
    if (!said++) mvlog("the app was built without FFmpeg's headers (brew install ffmpeg, then rebuild): movies play black");
    return 0;
}
/* (never called without the decoder) */
HulkMovie* hulk_movie_open(const HulkMovieIO* io) { (void)io; return 0; }
void hulk_movie_close(HulkMovie* m) { (void)m; }
const HulkMovieInfo* hulk_movie_info(const HulkMovie* m) { (void)m; return 0; }
int hulk_movie_track(const HulkMovie* m, int i, HulkMovieTrack* o) { (void)m, (void)i, (void)o; return 0; }
void hulk_movie_select_tracks(HulkMovie* m, const int* ids, int n) { (void)m, (void)ids, (void)n; }
int hulk_movie_decode_video(HulkMovie* m, HulkMovieFrame* f) { (void)m, (void)f; return -1; }
unsigned hulk_movie_audio_queued(const HulkMovie* m, int id) { (void)m, (void)id; return 0; }
unsigned hulk_movie_audio_read(HulkMovie* m, int id, short* o, unsigned n) { (void)m, (void)id, (void)o, (void)n; return 0; }
void hulk_movie_to_bgra(const HulkMovieFrame* f, unsigned char* d, int p, int x, int y, int w, int h) {
    (void)f, (void)d, (void)p, (void)x, (void)y, (void)w, (void)h;
}
static int read_one(HulkMovie* m) { (void)m; return 0; }
static void drop_video(HulkMovie* m) { (void)m; }
#endif

#if defined(HULK_HAVE_FFMPEG)
/* the audio decoder's demuxer reads video packets too: they are dropped (the picture has its own decoder) */
static void drop_video(HulkMovie* m) {
    while (m->vq_count) {
        av_packet_free(&m->vq[m->vq_head]);
        m->vq_head = (m->vq_head + 1) % MAX_VPACKETS;
        m->vq_count--;
    }
}
#endif

/* ------------------------------------------------------------------------------------ the disc's archives */
typedef struct { u32 hash, off, size; int file; } rcf_ent;
static rcf_ent* s_ents;
static unsigned s_nents;
static int s_fds[32];
static char* s_rcf_names[32];       /* the archives' names in the disc's root */
static int s_nfds;

static void rcf_add(const char* path) {
    if (s_nfds >= 32) return;
    int fd = hdisc_open(path);          /* (the disc may be an image: run/disc.h) */
    if (fd < 0) return;
    uint8_t h[0x3c];
    u32 dir_off, dir_size, count;
    if (hdisc_pread(fd, h, sizeof h, 0) != (ssize_t)sizeof h || memcmp(h, "ATG CORE CEMENT LIBRARY", 23)) {
        hdisc_close(fd);
        return;
    }
    memcpy(&dir_off, h + 0x24, 4);
    memcpy(&dir_size, h + 0x28, 4);
    memcpy(&count, h + 0x38, 4);
    if (dir_size != 12 * count || count > 100000) { hdisc_close(fd); return; }
    u32* dir = malloc(dir_size ? dir_size : 1);
    if (hdisc_pread(fd, dir, dir_size, dir_off) != (ssize_t)dir_size) { free(dir); hdisc_close(fd); return; }
    s_ents = realloc(s_ents, (s_nents + count) * sizeof *s_ents);
    for (u32 i = 0; i < count; i++)
        s_ents[s_nents++] = (rcf_ent){dir[3 * i], dir[3 * i + 1], dir[3 * i + 2], s_nfds};
    free(dir);
    const char* slash = strrchr(path, '/');
    s_rcf_names[s_nfds] = strdup(slash ? slash + 1 : path);
    s_fds[s_nfds++] = fd;
}

static void rcf_one(void* ud, const char* name) {
    size_t n = strlen(name);
    if (n > 4 && !strcasecmp(name + n - 4, ".rcf")) {
        char p[1024];
        snprintf(p, sizeof p, "%s/%s", (const char*)ud, name);
        rcf_add(p);
    }
}

static void rcf_scan(void) {
    static int done;
    if (done++) return;
    const char* d = getenv("HULK_DATA_DIR");
    if (!d) return;
    hdisc_list(d, rcf_one, (void*)d);
}

static const rcf_ent* rcf_find(u32 hash) {
    rcf_scan();
    for (unsigned i = 0; i < s_nents; i++)
        if (s_ents[i].hash == hash) return &s_ents[i];
    return 0;
}

/* ------------------------------------------------------------------------------------ the movies */
#define MOV_TRACKS 6
#define VOICE_FRAMES 96000          /* a track's ring: 2 s at 48 kHz */
#define AHEAD_FRAMES 4800           /* source frames queued beyond a slice's need (~100 ms) */
typedef struct {
    int id, rate, channels, selected;
    HulkVoice* voice;
    unsigned long long consumed;    /* frames taken from the decoder (into the voice or dropped) */
    HulkMixBin bins[HULK_AUDIO_MAX_BINS];
    unsigned nbins;
    int mixed;
    unsigned volume;                /* 0..65536 */
} mtrack;

typedef struct mov {
    struct mov* next;
    u32 h, hash;
    unsigned long long stamp;
    const rcf_ent* ent;
    HulkMovie* v;                   /* the picture's decoder */
    HulkMovieFrame cur;
    int cur_idx, vnext, vend;       /* the frame in `cur` (-1: none), the next one the decoder gives, the end */
    HulkMovie* a;                   /* the sound's decoder (0: no track selected) */
    mtrack tr[MOV_TRACKS];
    int ntr, playing, failed, seen;
    unsigned copies, decoded;
    double anchor;                  /* the wall clock (ms) at the movie's time 0, or 0: not anchored */
} mov;
static mov* s_movs;
static u32 s_ring;                  /* the hold-to-skip ring: thousandths of the hold (0: no ring) */

static int rcf_read(void* ctx, unsigned long long pos, void* buf, int n) {
    const rcf_ent* e = ctx;
    if (pos >= e->size) return 0;
    if (pos + (unsigned)n > e->size) n = (int)(e->size - pos);
    int64_t r = hdisc_pread(s_fds[e->file], buf, (size_t)n, e->off + pos);
    return r < 0 ? -1 : (int)r;
}

#if defined(HULK_HAVE_FFMPEG)
/* A disc pack may hold the movie's picture as AV1 (tools/disc_av1.py; the pack keeps only the Bink file's head, the
 * rest is zeros): .hulk/av1/<archive>/<hash>.mkv, AV1 and the Bink file's sound tracks as Opus, in its track order.
 * The frame count, the rate and the tracks' ids come from the Bink header the game reads too. 1: opened (*out),
 * 0: the pack has it but it does not open (no AV1 / Opus decoder in this FFmpeg), -1: none. */
typedef struct { int fd; unsigned long long size; } av1_io;
static int av1_read(void* ctx, unsigned long long pos, void* buf, int n) {
    av1_io* a = ctx;
    if (pos >= a->size) return 0;
    if (pos + (unsigned)n > a->size) n = (int)(a->size - pos);
    int64_t r = hdisc_pread(a->fd, buf, (size_t)n, pos);
    return r < 0 ? -1 : (int)r;
}
static void av1_close(void* ctx) {
    av1_io* a = ctx;
    hdisc_close(a->fd);
    free(a);
}
static int open_av1(mov* m, HulkMovie** out) {
    const char* d = getenv("HULK_DATA_DIR");
    char p[1200];
    if (!d || !s_rcf_names[m->ent->file]) return -1;
    snprintf(p, sizeof p, "%s/.hulk/av1/%s/%08x.mkv", d, s_rcf_names[m->ent->file], m->hash);
    int fd = hdisc_open(p);
    if (fd < 0) return -1;
    uint8_t hd[0x200];
    u32 frames, num, den, tracks;
    if (rcf_read((void*)m->ent, 0, hd, sizeof hd) != (int)sizeof hd || memcmp(hd, "BIK", 3)) { hdisc_close(fd); return 0; }
    memcpy(&frames, hd + 8, 4), memcpy(&num, hd + 28, 4), memcpy(&den, hd + 32, 4), memcpy(&tracks, hd + 40, 4);
    av1_io* a = malloc(sizeof *a);
    a->fd = fd, a->size = hdisc_size(fd);
    HulkMovieIO io = {a, av1_read, av1_close, a->size};
    s_fmt_override = "matroska";
    HulkMovie* v = hulk_movie_open(&io);
    s_fmt_override = 0;
    if (!v) {
        static int said;
        if (!said++) mvlog("the disc pack's movies are AV1 and this FFmpeg cannot decode them (it needs libdav1d and "
                           "Opus): movies play black");
        return 0;
    }
    v->info.frames = frames, v->info.fps_num = (int)num, v->info.fps_den = (int)den;
    for (int i = 0; i < v->ntracks && i < (int)tracks && tracks <= 16; i++) {
        u32 id;
        memcpy(&id, hd + 44 + 8 * tracks + 4 * i, 4);
        v->tracks[i].id = (int)id;
    }
    *out = v;
    return 1;
}
#endif

static HulkMovie* open_dec(mov* m) {
#if defined(HULK_HAVE_FFMPEG)
    HulkMovie* v = 0;
    int r = open_av1(m, &v);
    if (r >= 0) return v;           /* (0: the pack's Bink pictures are zeros: black, not the Bink decoder on them) */
#endif
    HulkMovieIO io = {(void*)m->ent, rcf_read, 0, m->ent->size};
    return hulk_movie_open(&io);
}

static u32 rd(u32 a, u32 i) {
    u32 v;
    memcpy(&v, hulk_run_memory() + a + 4 * i, 4);
    return v;
}
#define HW(m, i) rd((m)->h, i)                          /* the handle's words: 0..3 the game's, 4.. reserved */
static unsigned long long stamp_of(u32 h) { return rd(h, 4 + 2) | (unsigned long long)rd(h, 4 + 3) << 32; }

static mov* find(u32 h) {
    for (mov* m = s_movs; m; m = m->next)
        if (m->h == h) return m;
    return 0;
}

static int volume_mb(unsigned v) {
    if (v == 0) return HULK_AUDIO_MIN_MB;
    if (v >= 65536) return 0;
    int mb = (int)(2000.0 * log10((double)v / 65536.0));
    return mb < HULK_AUDIO_MIN_MB ? HULK_AUDIO_MIN_MB : mb;
}

static void close_mov(mov* m) {
    for (int i = 0; i < m->ntr; i++)
        if (m->tr[i].voice) hulk_audio_voice_release(m->tr[i].voice);
    if (m->v) hulk_movie_close(m->v);
    if (m->a) hulk_movie_close(m->a);
    for (mov** p = &s_movs; *p; p = &(*p)->next)
        if (*p == m) { *p = m->next; break; }
    free(m);
}

/* the app quits (start.cpp hulk_app_quit): every movie closed, its voices released before the mixer goes */
void hulk_app_movie_quit(void) {
    while (s_movs) close_mov(s_movs);
}

/* the movie the handle holds now (its identity from the handle's reserved words) */
static mov* make(u32 h) {
    mov* old = find(h);
    if (old) close_mov(old);
    mov* m = calloc(1, sizeof *m);
    m->h = h;
    m->hash = rd(h, 4 + 1);
    m->stamp = stamp_of(h);
    m->cur_idx = -1;
    m->vend = 1 << 30;
    m->next = s_movs;
    s_movs = m;
    if (!ff_up() || !(m->ent = rcf_find(m->hash)) || !(m->v = open_dec(m))) {
        if (ff_up()) mvlog("movie %08x: %s: plays black", m->hash, m->ent ? "not a playable Bink file" : "not on the disc");
        m->failed = 1;
        return m;
    }
    const HulkMovieInfo* info = hulk_movie_info(m->v);
    u32 nsel = rd(h, 4 + 4);
    int ids[MOV_TRACKS], n = 0;
    for (int i = 0; i < info->tracks && m->ntr < MOV_TRACKS; i++) {
        HulkMovieTrack t;
        if (!hulk_movie_track(m->v, i, &t)) continue;
        mtrack* r = &m->tr[m->ntr++];
        r->id = t.id, r->rate = t.rate, r->channels = t.channels, r->volume = 65536;
        for (u32 k = 0; k < nsel && k < MOV_TRACKS; k++)
            if ((int)rd(h, 4 + 5 + k) == t.id) r->selected = 1;
        if (r->selected) ids[n++] = t.id;
    }
    if (n && (m->a = open_dec(m))) hulk_movie_select_tracks(m->a, ids, n);
    VLOG("movie %08x (handle %08x): %dx%d, %u frames at %d/%d fps, %d sound tracks (%d selected)", m->hash, h,
         info->width, info->height, info->frames, info->fps_num, info->fps_den, info->tracks, n);
    return m;
}

/* the handle's movie, made again when the handle holds another one than the runner's (after a restore) */
static mov* get(u32 h) {
    if (rd(h, 4) != 0x31564f4du) return 0;
    mov* m = find(h);
    if (!m || m->stamp != stamp_of(h) || m->hash != rd(h, 4 + 1)) m = make(h);
    return m;
}

/* -------------------------------------------------------------- sound */
static void make_voices(mov* m) {
    for (int i = 0; i < m->ntr; i++) {
        mtrack* t = &m->tr[i];
        if (!t->selected || t->voice || !m->a) continue;
        HulkAudioFormat f = {HULK_CODEC_PCM, t->channels, 16, (unsigned)t->rate};
        HulkMixBin def[2] = {{HULK_BIN_FRONT_LEFT, 0}, {HULK_BIN_FRONT_RIGHT, 0}};
        t->voice = hulk_audio_stream_create(&f, t->mixed ? t->bins : def, t->mixed ? t->nbins : 2, VOICE_FRAMES);
        if (t->voice) hulk_audio_voice_set_volume(t->voice, volume_mb(t->volume));
    }
}

/* decodes until track t has `want` frames waiting (or the movie's sound ends) */
static void pump(mov* m, mtrack* t, unsigned want) {
    while (hulk_movie_audio_queued(m->a, t->id) < want) {
        int r = read_one(m->a);
        drop_video(m->a);
        if (r <= 0) break;
    }
}

/* each playing voice holds what the next `frames` of 48 kHz output take, and some */
static void top_up(mov* m, unsigned frames) {
    static short buf[4096 * 2];
    for (int i = 0; i < m->ntr; i++) {
        mtrack* t = &m->tr[i];
        if (!t->voice) continue;
        unsigned want = (unsigned)((unsigned long long)frames * (unsigned)t->rate / HULK_AUDIO_RATE) + AHEAD_FRAMES;
        if (want > VOICE_FRAMES) want = VOICE_FRAMES;
        for (;;) {
            unsigned q = hulk_audio_stream_queued(t->voice);
            if (q >= want) break;
            unsigned n = want - q;
            if (n > 4096) n = 4096;
            pump(m, t, n);
            n = hulk_movie_audio_read(m->a, t->id, buf, n);
            if (!n) break;
            t->consumed += n;
            hulk_audio_stream_write(t->voice, buf, n);
        }
    }
}

/* the sound at the movie's time `ms`: the queues dropped, the decoder at that frame (reopened if it is past it) */
static void seek_audio(mov* m, u32 ms) {
    if (!m->a) return;
    static short buf[4096 * 2];
    int reopen = 0;
    for (int i = 0; i < m->ntr; i++) {
        mtrack* t = &m->tr[i];
        if (t->selected && t->consumed > (unsigned long long)ms * (unsigned)t->rate / 1000) reopen = 1;
    }
    if (reopen) {
        int ids[MOV_TRACKS], n = 0;
        for (int i = 0; i < m->ntr; i++)
            if (m->tr[i].selected) ids[n++] = m->tr[i].id, m->tr[i].consumed = 0;
        hulk_movie_close(m->a);
        m->a = open_dec(m);
        if (!m->a) return;
        hulk_movie_select_tracks(m->a, ids, n);
    }
    for (int i = 0; i < m->ntr; i++) {
        mtrack* t = &m->tr[i];
        if (!t->selected) continue;
        if (t->voice) hulk_audio_stream_flush(t->voice);
        unsigned long long target = (unsigned long long)ms * (unsigned)t->rate / 1000;
        while (t->consumed < target) {
            unsigned n = target - t->consumed > 4096 ? 4096 : (unsigned)(target - t->consumed);
            pump(m, t, n);
            n = hulk_movie_audio_read(m->a, t->id, buf, n);
            if (!n) break;
            t->consumed += n;
        }
    }
}

static void set_playing(mov* m, int on) {
    if (on) {
        make_voices(m);
        top_up(m, 1024);
    }
    for (int i = 0; i < m->ntr; i++)
        if (m->tr[i].voice) {
            if (on) hulk_audio_voice_play(m->tr[i].voice, 0);
            else hulk_audio_voice_stop(m->tr[i].voice);
        }
    m->playing = on;
}

/* run/app/audio.cpp: the mixer is about to render `frames` (48 kHz) */
void hulk_app_movie_tick(unsigned frames) {
    for (mov* m = s_movs; m; m = m->next)
        if (m->playing && !m->failed) top_up(m, frames);
}

/* -------------------------------------------------------------- real time */
static double now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e3 + ts.tv_nsec / 1e6;
}

/* the game waits for the movie's frame due at `due` ms of movie time: so does the wall clock (anchored at the first
 * wait after a start, a pause or a restore; re-anchored when more than 250 ms late: a stall, a load) */
void w2c_hulk_mov_wait(struct w2c_hulk* w, u32 h, u32 due) {
    (void)w;
    mov* m = get(h);
    if (!m) return;
    double now = now_ms();
    if (!m->anchor || now - (m->anchor + due) > 250) m->anchor = now - due + 1;
    double left = m->anchor + due - now;
    if (left > 0 && left < 1000) usleep((useconds_t)(left * 1000));
}

/* -------------------------------------------------------------- the imports */
void w2c_hulk_mov_open(struct w2c_hulk* w, u32 h, u32 name) {
    (void)w;
    mov* m = make(h);
    (void)m;
    VLOG("open %s -> handle %08x", (const char*)hulk_run_memory() + name, h);
}

void w2c_hulk_mov_close(struct w2c_hulk* w, u32 h) {
    (void)w;
    mov* m = find(h);
    if (m) {
        s_ring = 0;
        VLOG("close %08x at frame %u of %u (%u frames decoded, %u copies)", m->hash, rd(h, 3), rd(h, 2), m->decoded,
             m->copies);
        close_mov(m);
    }
}

void w2c_hulk_mov_pause(struct w2c_hulk* w, u32 h, u32 paused, u32 ms) {
    (void)w;
    mov* m = get(h);
    if (!m || m->failed) return;
    VLOG("%s %08x at %u ms", paused ? "pause" : "play", m->hash, ms);
    m->anchor = 0;
    set_playing(m, !paused);
}

void w2c_hulk_mov_mix(struct w2c_hulk* w, u32 h, u32 fn, u32 args) {
    (void)w;
    mov* m = get(h);
    if (!m || m->failed) return;
    u32 track = rd(args, 1);
    mtrack* t = 0;
    for (int i = 0; i < m->ntr; i++)
        if ((u32)m->tr[i].id == track) t = &m->tr[i];
    if (!t) return;
    if (fn == 0x367610) {                       /* SetVolume(handle, track, volume: 65536 unity) */
        t->volume = rd(args, 2);
        if (t->voice) hulk_audio_voice_set_volume(t->voice, volume_mb(t->volume));
    } else {                                    /* SetMixBins(handle, track, bins*, count) */
        u32 bins = rd(args, 2), n = rd(args, 3);
        if (!bins) return;
        if (n > HULK_AUDIO_MAX_BINS) n = HULK_AUDIO_MAX_BINS;
        for (u32 i = 0; i < n; i++) t->bins[i] = (HulkMixBin){rd(bins, i) & 15, 0};
        t->nbins = n;
        t->mixed = 1;
        if (t->voice) hulk_audio_voice_set_bins(t->voice, t->bins, n);
    }
}

/* BinkCopyToBufferRect(handle, dst, pitch, dest height, dx, dy, sx, sy, sw, sh, flags): the frame the handle's
 * frame number names, B, G, R, A into the game's lock (a negative pitch: the lock's bottom-up rows; bink_player.cpp) */
void w2c_hulk_mov_copy(struct w2c_hulk* w, u32 h, u32 args) {
    (void)w;
    mov* m = get(h);
    if (!m || m->failed) return;
    if (rd(h, 4 + 11)) {                        /* skipped (D231): the game ends it; nothing more to show or hear */
        if (m->playing) set_playing(m, 0);
        return;
    }
    int want = (int)rd(h, 3);
    if (m->cur_idx != want) {
        if (want < m->vnext) {                  /* behind the decoder (a restore): from the start again */
            hulk_movie_close(m->v);
            m->v = open_dec(m);
            m->vnext = 0, m->cur_idx = -1;
            if (!m->v) { m->failed = 1; return; }
        }
        if (want >= m->vend) return;
        while (m->cur_idx != want) {
            if (hulk_movie_decode_video(m->v, &m->cur) <= 0) { m->vend = m->vnext; m->cur_idx = -1; return; }
            m->cur_idx = m->vnext++;
            m->decoded++;
        }
    }
    u32 dst = rd(args, 1), dest_h = rd(args, 3);
    int pitch = (int)rd(args, 2), dx = (int)rd(args, 4), dy = (int)rd(args, 5), sx = (int)rd(args, 6),
        sy = (int)rd(args, 7), sw = (int)rd(args, 8), sh = (int)rd(args, 9);
    if (!dst || sw <= 0 || sh <= 0 || dx < 0 || dy < 0 || (unsigned)(dy + sh) > dest_h) return;
    unsigned apitch = (unsigned)(pitch < 0 ? -pitch : pitch);
    if ((unsigned long long)dst + (unsigned long long)dest_h * apitch > hulk_run_memory_size()) return;
    uint8_t* base = hulk_run_memory() + dst;
    m->copies++;
    if (pitch >= 0)
        hulk_movie_to_bgra(&m->cur, base + (size_t)dy * apitch + (size_t)dx * 4, pitch, sx, sy, sw, sh);
    else
        hulk_movie_to_bgra(&m->cur, base + (size_t)(dest_h - 1 - (unsigned)dy) * apitch + (size_t)dx * 4, pitch, sx,
                           sy, sw, sh);
}

/* -------------------------------------------------------------- the hold-to-skip ring (D231) */
static unsigned s_ring_version;
void w2c_hulk_mov_ring(struct w2c_hulk* w, u32 h, u32 permille) {
    (void)w, (void)h;
    if (permille > 1000) permille = 1000;
    s_ring = permille;
}

/* 1 while a movie plays (the frames are the movie's: fps2 doesn't interpolate them) */
int hulk_app_movie_playing(void) {
    for (mov* m = s_movs; m; m = m->next)
        if (m->playing) return 1;
    return 0;
}

void hulk_gfx_sink_overlay(const void* bgra, unsigned w, unsigned h, int x, int y, unsigned version);  /* bgfx_sink */
int hulk_app_notice_overlay(unsigned ww, unsigned wh);      /* run/app/input.cpp */

/* before the present (run/app/app.cpp): the ring in the bottom-right corner of a window ww x wh, a tenth of its
 * smaller side across. Our own drawing: a faint full circle and the held part of it from twelve o'clock clockwise. */
void hulk_app_movie_overlay(unsigned ww, unsigned wh) {
    static uint8_t* img;
    static unsigned size, drawn_ring = ~0u, drawn_size;
    if (!s_ring || !s_movs) {
        if (!hulk_app_notice_overlay(ww, wh))          /* (run/app/input.cpp: the controller notice, wpol1) */
            hulk_gfx_sink_overlay(0, 0, 0, 0, 0, s_ring_version);
        return;
    }
    unsigned d = (ww < wh ? ww : wh) / 10;
    if (d < 24) d = 24;
    if (d > 512) d = 512;
    if (d != size) {
        free(img);
        img = malloc((size_t)d * d * 4);
        size = d;
    }
    if (!img) return;
    if (drawn_ring != s_ring || drawn_size != d) {
        float r_out = d * 0.5f - 1.0f, r_in = r_out * 0.72f, c = d * 0.5f;
        float frac = s_ring / 1000.0f;
        for (unsigned y = 0; y < d; y++)
            for (unsigned x = 0; x < d; x++) {
                float dx = x + 0.5f - c, dy = y + 0.5f - c;
                float r = sqrtf(dx * dx + dy * dy);
                /* coverage of the annulus, anti-aliased over a pixel at both edges */
                float cov = fminf(fmaxf(r_out - r + 0.5f, 0.0f), 1.0f) * fminf(fmaxf(r - r_in + 0.5f, 0.0f), 1.0f);
                float ang = atan2f(dx, -dy);                    /* 0 at twelve o'clock, clockwise */
                if (ang < 0) ang += 6.2831853f;
                int lit = ang <= frac * 6.2831853f;
                uint8_t* q = img + ((size_t)y * d + x) * 4;
                q[0] = q[1] = q[2] = 255;
                q[3] = (uint8_t)(cov * (lit ? 230.0f : 70.0f));
            }
        drawn_ring = s_ring, drawn_size = d;
        s_ring_version++;
    }
    unsigned margin = d / 3;
    hulk_gfx_sink_overlay(img, d, d, (int)(ww - d - margin), (int)(wh - d - margin), s_ring_version);
}

/* a snapshot was put back: 0 begins, 1 names a live handle with the movie's time, 2 ends (the rest are closed) */
void w2c_hulk_mov_resync(struct w2c_hulk* w, u32 phase, u32 h, u32 ms) {
    (void)w;
    if (phase == 0) {
        for (mov* m = s_movs; m; m = m->next) m->seen = 0;
        return;
    }
    if (phase == 2) {
        for (mov* m = s_movs, *nx; m; m = nx) {
            nx = m->next;
            if (!m->seen) {
                VLOG("restore: close %08x (handle %08x)", m->hash, m->h);
                close_mov(m);
            }
        }
        return;
    }
    mov* m = get(h);
    if (!m) return;
    m->seen = 1;
    if (m->failed) return;
    int paused = (int)rd(h, 16 + 3);            /* (bink_null.c: block, fps_num, fps_den, paused) */
    VLOG("restore: %08x (handle %08x) at %u ms, frame %u, %s", m->hash, h, ms, rd(h, 3), paused ? "paused" : "playing");
    if (m->playing) set_playing(m, 0);
    m->anchor = 0;
    seek_audio(m, ms);
    if (!paused) set_playing(m, 1);
}
