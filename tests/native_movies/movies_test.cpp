// Movie decoder test (docs/native-movies.md): the first frames of a real game movie decoded through our wrapper and
// through the Bink-shaped player, checked against an independent decode (the ffmpeg command line, a different build
// of FFmpeg: tools/native_ffmpeg.py writes its output), and the movie's audio played into the mixer's capture.
// Host: the typed API (src/platform/sdl/movies/*.h). HULK_TEST_XDK (i686 under Wine): the player through the
// hulk_xdk_Bink_* stand-ins with 32-bit handles and a stand-in for the game's own I/O callbacks.
//
// Inputs (environment; tools/native_ffmpeg.py test sets them; a movie is read in place from the game's archive):
//   HULK_TEST_MOVIE   "<archive>|<offset>|<size>"   a movie with six mono tracks (the 5.1 layout)
//   HULK_TEST_MOVIE2  same, a stereo single-track movie (optional)
//   HULK_TEST_REF     directory with the ffmpeg CLI's output: m.yuv (yuv420p), m.bgra, m.f32 (track 0, mono floats) and for
//                     MOVIE2: s.yuv, s.bgra, s.f32 (stereo, interleaved floats)
//   HULK_TEST_FRAMES  frames to check (default 60)
//   HULK_TEST_OUT     directory for the capture WAVs
#include "audio/hulk_audio.h"
#include "movies/bink_player.h"
#include "movies/movie.h"
#include "test_common.h"

#ifdef HULK_TEST_XDK
#include "xdk/imports.h"
#include "xdk/library.h"
#endif

// ---------------------------------------------------------------------------------------------
// the movie in its archive
struct Source {
    SDL_IOStream* f;
    unsigned long long base, size;
    int closed;
};

static bool parse_source(const char* spec, Source* s)
{
    if (!spec)
        return false;
    char path[512];
    int n = 0;
    while (spec[n] && spec[n] != '|' && n < 511) {
        path[n] = spec[n];
        n++;
    }
    path[n] = 0;
    if (spec[n] != '|')
        return false;
    const char* p = spec + n + 1;
    unsigned long long v[2] = {0, 0};
    for (int k = 0; k < 2; k++) {
        while (*p >= '0' && *p <= '9')
            v[k] = v[k] * 10 + (unsigned)(*p++ - '0');
        if (k == 0 && *p == '|')
            p++;
    }
    s->base = v[0];
    s->size = v[1];
    s->closed = 0;
    s->f = SDL_IOFromFile(path, "rb");
    return s->f != 0;
}

static int src_read(void* ctx, unsigned long long pos, void* buf, int n)
{
    Source* s = (Source*)ctx;
    if (pos >= s->size)
        return 0;
    if (pos + (unsigned)n > s->size)
        n = (int)(s->size - pos);
    if (SDL_SeekIO(s->f, (Sint64)(s->base + pos), SDL_IO_SEEK_SET) < 0)
        return -1;
    return (int)SDL_ReadIO(s->f, buf, (size_t)n);
}

// the device under the game's stream: the whole archive, so a read rounded up to the block size at the end of a movie
// lands in the archive's padding (the movies sit on 2 KB boundaries), as the original's ring reads do
#ifdef HULK_TEST_XDK
static int src_read_device(Source* s, unsigned long long pos, void* buf, int n)
{
    if (SDL_SeekIO(s->f, (Sint64)(s->base + pos), SDL_IO_SEEK_SET) < 0)
        return -1;
    return (int)SDL_ReadIO(s->f, buf, (size_t)n);
}
#endif

static void src_close(void* ctx)
{
    ((Source*)ctx)->closed++;
}

static HulkMovieIO make_io(Source* s)
{
    HulkMovieIO io;
    SDL_memset(&io, 0, sizeof(io));
    io.ctx = s;
    io.read = src_read;
    io.close = src_close;
    io.size = 0;                    // the Bink header says
    return io;
}

static unsigned char* load(const char* dir, const char* name, unsigned long long* size)
{
    char path[512];
    SDL_snprintf(path, sizeof(path), "%s/%s", dir, name);
    SDL_IOStream* f = SDL_IOFromFile(path, "rb");
    if (!f)
        return 0;
    unsigned char* buf = 0;
    unsigned long long cap = 0, n = 0;
    for (;;) {
        if (n + (1 << 20) > cap) {
            cap = cap ? cap * 2 : (4u << 20);
            buf = (unsigned char*)SDL_realloc(buf, (size_t)cap);
        }
        unsigned long long got = SDL_ReadIO(f, buf + n, 1 << 20);
        n += got;
        if (got < (1u << 20))
            break;
    }
    SDL_CloseIO(f);
    *size = n;
    return buf;
}

static unsigned crc32(unsigned crc, const unsigned char* p, unsigned long long n)
{
    static unsigned table[256];
    if (!table[1]) {
        for (unsigned i = 0; i < 256; i++) {
            unsigned c = i;
            for (int k = 0; k < 8; k++)
                c = (c & 1) ? 0xedb88320u ^ (c >> 1) : c >> 1;
            table[i] = c;
        }
    }
    crc = ~crc;
    for (unsigned long long i = 0; i < n; i++)
        crc = table[(crc ^ p[i]) & 0xff] ^ (crc >> 8);
    return ~crc;
}

static double psnr(const unsigned char* a, const unsigned char* b, unsigned long long n)
{
    double sum = 0;
    for (unsigned long long i = 0; i < n; i++) {
        if ((i & 3) == 3)
            continue;               // alpha
        double d = (double)a[i] - (double)b[i];
        sum += d * d;
    }
    double mse = sum / (double)(n / 4 * 3);
    return mse <= 0 ? 99.0 : 10.0 * SDL_log10(255.0 * 255.0 / mse);
}

// The decoders' audio is floating point, so its last bit depends on the build: the host build of FFmpeg here matches
// the reference (another arm64 build) to the bit, an i686 build (SSE2, no hand-written assembly) can round a few
// samples the other way. Video is integer and always exact.
#ifdef HULK_TEST_XDK
static const int kAudioTol = 1;
#else
static const int kAudioTol = 0;
#endif

struct Ref {
    unsigned char *yuv, *bgra, *pcm;
    unsigned long long yuv_size, bgra_size, pcm_size;
};

static bool load_ref(const char* dir, const char* stem, Ref* r)
{
    char nm[32];
    SDL_snprintf(nm, sizeof(nm), "%s.yuv", stem);
    r->yuv = load(dir, nm, &r->yuv_size);
    SDL_snprintf(nm, sizeof(nm), "%s.bgra", stem);
    r->bgra = load(dir, nm, &r->bgra_size);
    SDL_snprintf(nm, sizeof(nm), "%s.f32", stem);
    unsigned char* raw = load(dir, nm, &r->pcm_size);          // ffmpeg's decoded floats
    r->pcm_size /= 2;                                          // as 16-bit samples, converted the way movie.c does
    r->pcm = raw;
    if (raw) {
        const float* f = (const float*)raw;
        short* o = (short*)raw;
        for (unsigned long long i = 0; i < r->pcm_size / 2; i++) {
            float v = f[i] * 32768.0f;
            int s = (int)(v < 0 ? v - 0.5f : v + 0.5f);
            o[i] = (short)(s > 32767 ? 32767 : s < -32768 ? -32768 : s);
        }
    }
    return r->yuv && r->bgra && r->pcm;
}

struct Case {
    const char* name;
    Source* src;
    const Ref* ref;
    int frames;
    int track_id;
    int channels;
    int width, height;
    int tracks;                     // audio tracks in the file
    int rate;
};

// ---------------------------------------------------------------------------------------------
// 1. the wrapper alone: planes against the independent decode (exact), the colour conversion (PSNR), the audio
static void test_wrapper(const Case& c)
{
    printf("-- wrapper: %s\n", c.name);
    HulkMovieIO io = make_io(c.src);
    HulkMovie* m = hulk_movie_open(&io);
    CHECK(m != 0, "%s: open", c.name);
    if (!m)
        return;
    const HulkMovieInfo* in = hulk_movie_info(m);
    CHECK(in->width == c.width && in->height == c.height, "%s: size %dx%d", c.name, in->width, in->height);
    CHECK(in->tracks == c.tracks, "%s: %d audio tracks", c.name, in->tracks);
    CHECK(in->fps_num > 0 && in->fps_den > 0 && in->frames > (unsigned)c.frames, "%s: %u frames at %d/%d", c.name,
          in->frames, in->fps_num, in->fps_den);
    printf("   %dx%d, %u frames, %d/%d fps, %d tracks\n", in->width, in->height, in->frames, in->fps_num, in->fps_den,
           in->tracks);
    HulkMovieTrack tr;
    bool found = false;
    for (int i = 0; hulk_movie_track(m, i, &tr); i++)
        if (tr.id == c.track_id) {
            found = true;
            CHECK(tr.channels == c.channels && tr.rate == c.rate, "%s: track %d is %d ch at %d Hz", c.name, tr.id,
                  tr.channels, tr.rate);
        }
    CHECK(found, "%s: track id %d exists", c.name, c.track_id);
    int ids[1] = {c.track_id};
    hulk_movie_select_tracks(m, ids, 1);

    int w = c.width, h = c.height, cw = (w + 1) / 2, ch = (h + 1) / 2;
    unsigned long long fbytes = (unsigned long long)w * h + 2ull * cw * ch;
    CHECK(c.ref->yuv_size >= fbytes * (unsigned)c.frames, "%s: reference has %llu frames of yuv", c.name,
          c.ref->yuv_size / fbytes);
    unsigned char* bg = (unsigned char*)SDL_malloc((size_t)w * h * 4);
    int plane_bad = 0, decoded = 0;
    double pmin = 99, psum = 0;
    unsigned first_crc = 0, last_crc = 0;
    for (int k = 0; k < c.frames; k++) {
        HulkMovieFrame f;
        int r = hulk_movie_decode_video(m, &f);
        CHECK(r == 1, "%s: decode frame %d -> %d", c.name, k, r);
        if (r != 1)
            break;
        decoded++;
        const unsigned char* ref = c.ref->yuv + fbytes * (unsigned)k;
        unsigned crc = 0;
        bool bad = false;
        const unsigned char* rp[3] = {ref, ref + (size_t)w * h, ref + (size_t)w * h + (size_t)cw * ch};
        int pw[3] = {w, cw, cw}, ph[3] = {h, ch, ch};
        for (int p = 0; p < 3; p++)
            for (int y = 0; y < ph[p]; y++) {
                const unsigned char* a = f.plane[p] + (size_t)y * f.stride[p];
                const unsigned char* b = rp[p] + (size_t)y * pw[p];
                if (SDL_memcmp(a, b, (size_t)pw[p]))
                    bad = true;
                crc = crc32(crc, a, (unsigned long long)pw[p]);
            }
        if (k == 0)
            first_crc = crc;
        last_crc = crc;
        plane_bad += bad;
        CHECK(f.index == (unsigned)k, "%s: frame index %u", c.name, f.index);
        hulk_movie_to_bgra(&f, bg, w * 4, 0, 0, w, h);
        double p = psnr(bg, c.ref->bgra + (unsigned long long)w * h * 4 * (unsigned)k, (unsigned long long)w * h * 4);
        psum += p;
        if (p < pmin)
            pmin = p;
    }
    CHECK(decoded == c.frames && plane_bad == 0, "%s: %d of %d frames differ from the ffmpeg decode (YUV planes)", c.name,
          plane_bad, decoded);
    printf("   YUV planes: %d/%d frames identical to ffmpeg's (crc32 of frame 0 %08x, of the last %08x)\n",
           decoded - plane_bad, decoded, first_crc, last_crc);
    CHECK(pmin > 38.0, "%s: BGRA conversion PSNR min %.2f dB", c.name, pmin);
    printf("   BGRA vs ffmpeg's swscale: PSNR min %.2f dB, mean %.2f dB\n", pmin, psum / (decoded ? decoded : 1));

    // audio: what the demuxer read ahead while decoding the frames, against the independent decode
    unsigned queued = hulk_movie_audio_queued(m, c.track_id);
    unsigned min_expect = (unsigned)((long long)c.frames * c.rate * in->fps_den / in->fps_num) - (unsigned)c.rate / 4;
    CHECK(queued >= min_expect, "%s: %u audio frames queued after %d video frames (>= %u)", c.name, queued, c.frames,
          min_expect);
    short* pcm = (short*)SDL_malloc((size_t)queued * c.channels * sizeof(short));
    unsigned got = hulk_movie_audio_read(m, c.track_id, pcm, queued);
    CHECK(got == queued, "%s: audio read %u of %u", c.name, got, queued);
    unsigned long long refn = c.ref->pcm_size / (2u * (unsigned)c.channels);
    unsigned n = got < refn ? got : (unsigned)refn;
    unsigned off = 0, big = 0;
    const short* rs = (const short*)c.ref->pcm;
    for (unsigned i = 0; i < n * (unsigned)c.channels; i++) {
        int d = pcm[i] - rs[i];
        if (d != 0)
            big++;
        if (d < -kAudioTol || d > kAudioTol)
            off++;
    }
    CHECK(off == 0, "%s: %u of %u audio samples differ from ffmpeg's decode by more than %d", c.name, off, n * c.channels,
          kAudioTol);
    printf("   audio: %u frames (%.3f s) of track %d match ffmpeg's decode within %d LSB (%u not bit-identical)\n", n,
           (double)n / c.rate, c.track_id, kAudioTol, big);
    // the other tracks were dropped
    HulkMovieTrack other;
    for (int i = 0; hulk_movie_track(m, i, &other); i++)
        if (other.id != c.track_id)
            CHECK(hulk_movie_audio_queued(m, other.id) == 0, "%s: unselected track %d queued audio", c.name, other.id);
    SDL_free(pcm);
    SDL_free(bg);
    hulk_movie_close(m);
    CHECK(c.src->closed == 1, "%s: the I/O closed once (%d)", c.name, c.src->closed);
    c.src->closed = 0;
}

// ---------------------------------------------------------------------------------------------
// 2. the Bink-shaped player, on the mixer's manual clock
#ifdef HULK_TEST_XDK
typedef hulk_u32 BH;
// The game's own I/O callbacks, compiled in from the verified sources (the game's code, not Bink's):
//   equivalent/0x00334960.cpp  ReadHeader: stdcall (state, offset, dst, bytes) -> bytes, over state->stream
//   matches/0x00334f60.cpp     Close: stdcall (state): waits for pending requests, releases the stream (slot 1)
//   matches/0x0026fd50.cpp, 0x0026fd80.cpp  the align-up / align-down helpers ReadHeader uses
// and a stand-in for the radfile stream behind them (state word 0x13): seek, read, tell and the block size, with the
// device's alignment rule enforced (reads start and end on block boundaries).
struct State_334960;
unsigned __stdcall FUN_00334960(State_334960*, unsigned, unsigned char*, unsigned);
class Thing;
void __stdcall Run(Thing*);
void thunk() {}                                   // (the wait loop's service call: nothing is ever pending)

class FakeStream {
  public:
    virtual void s0() {}
    virtual void release() { released++; }        // slot 1
    virtual void s2() {}
    virtual void s3() {}
    virtual void s4() {}
    virtual void s5() {}
    virtual void s6() {}
    virtual void s7() {}
    virtual void s8() {}
    virtual void read(void* buf, unsigned n, unsigned) // slot 9
    {
        reads++;
        if (pos % kBlock || n % kBlock)
            misaligned++;
        int got = src_read_device(src, pos, buf, (int)n);
        pos += got < 0 ? 0 : (unsigned)got;
        bytes += got < 0 ? 0 : (unsigned)got;
    }
    virtual void s10() {}
    virtual void seek(unsigned p) { pos = p; }     // slot 11
    virtual void tell(unsigned* out) { *out = pos; } // slot 12
    virtual void s13() {}
    virtual void s14() {}
    virtual void s15() {}
    virtual unsigned block() { return kBlock; }    // slot 16
    enum { kBlock = 1024 };
    Source* src;
    unsigned pos, reads, misaligned, released;
    unsigned long long bytes;
};

static FakeStream g_stream;
static int g_fake_opened;
enum { kBlockWords = 79 };

static hulk_u32 HULK_STDCALL fake_unused(hulk_u32 a, hulk_u32 b, hulk_u32 c, hulk_u32 d, hulk_u32 e)
{
    (void)a; (void)b; (void)c; (void)d; (void)e;
    return 0;
}
// the game's open callback (FUN_00334fa0): zero the 79-word block, make the stream, fill the six callbacks
static hulk_u32 HULK_STDCALL fake_open(hulk_u32 state, hulk_u32 name, hulk_u32 flags)
{
    (void)name;
    (void)flags;
    hulk_u32* w = (hulk_u32*)(__SIZE_TYPE__)state;
    for (int i = 0; i < kBlockWords; i++)
        w[i] = 0;
    w[0] = (hulk_u32)(__SIZE_TYPE__)&FUN_00334960;
    for (int i = 1; i < 5; i++)
        w[i] = TEST_PTR(fake_unused);
    w[5] = (hulk_u32)(__SIZE_TYPE__)&Run;
    w[0x13] = TEST_PTR(&g_stream);
    g_fake_opened++;
    return 1;
}
static void b_setup(Source* s, const unsigned* tracks, unsigned n)
{
    g_stream.src = s;
    g_stream.pos = g_stream.reads = g_stream.misaligned = g_stream.released = 0;
    g_stream.bytes = 0;
    hulk_u32 ids[8];
    for (unsigned i = 0; i < n; i++)
        ids[i] = tracks[i];
    hulk_xdk_Bink_364da0(TEST_PTR(fake_open));
    hulk_xdk_Bink_364dc0(n, TEST_PTR(ids));
}
static BH b_open()
{
    return hulk_xdk_Bink_364fe0(TEST_PTR("movies\\test.rmv"), 0xa004000);
}
static HulkBink* hb(BH h)
{
    return (HulkBink*)(__SIZE_TYPE__)h;
}
static void b_bins(BH h, int track, const unsigned* bins, unsigned n)
{
    hulk_u32 b[HULK_AUDIO_MAX_BINS];
    for (unsigned i = 0; i < n; i++)
        b[i] = bins[i];
    hulk_lib_Bink_367660(h, (hulk_u32)track, TEST_PTR(b), n);
}
static void b_volume(BH h, int track, unsigned v)
{
    hulk_lib_Bink_367610(h, (hulk_u32)track, v);
}
static void b_pause(BH h, int p)
{
    hulk_xdk_Bink_366b40(h, (hulk_u32)p);
}
static int b_wait(BH h)
{
    return (int)hulk_xdk_Bink_366940(h);
}
static int b_do_frame(BH h)
{
    return (int)hulk_xdk_Bink_367bc0(h);
}
static int b_copy(BH h, void* dst, int pitch, unsigned dh, int dx, int dy, int sx, int sy, int sw, int sh)
{
    return (int)hulk_xdk_Bink_365f30(h, TEST_PTR(dst), (hulk_u32)pitch, dh, (hulk_u32)dx, (hulk_u32)dy, (hulk_u32)sx,
                                     (hulk_u32)sy, (hulk_u32)sw, (hulk_u32)sh, 3);
}
static void b_next(BH h)
{
    hulk_xdk_Bink_3681d0(h);
}
static void b_close(BH h)
{
    hulk_xdk_Bink_368530(h);
}
static unsigned b_closed_count(Source*)
{
    CHECK(g_stream.misaligned == 0, "the game's ReadHeader made %u unaligned reads", g_stream.misaligned);
    printf("   the game's ReadHeader read %llu KB in %u aligned device reads\n", g_stream.bytes >> 10, g_stream.reads);
    return g_stream.released;
}
#else
typedef HulkBink* BH;
static void b_setup(Source*, const unsigned* tracks, unsigned n)
{
    hulk_bink_set_tracks(tracks, n);
}
static HulkBink* hb(BH h)
{
    return h;
}
static void b_bins(BH h, int track, const unsigned* bins, unsigned n)
{
    hulk_bink_set_mix_bins(h, (unsigned)track, bins, n);
}
static void b_volume(BH h, int track, unsigned v)
{
    hulk_bink_set_volume(h, (unsigned)track, v);
}
static void b_pause(BH h, int p)
{
    hulk_bink_pause(h, p);
}
static int b_wait(BH h)
{
    return hulk_bink_wait(h);
}
static int b_do_frame(BH h)
{
    return hulk_bink_do_frame(h);
}
static int b_copy(BH h, void* dst, int pitch, unsigned dh, int dx, int dy, int sx, int sy, int sw, int sh)
{
    return hulk_bink_copy_rect(h, dst, pitch, dh, dx, dy, sx, sy, sw, sh, 3);
}
static void b_next(BH h)
{
    hulk_bink_next_frame(h);
}
static void b_close(BH h)
{
    hulk_bink_close(h);
}
static unsigned b_closed_count(Source* s)
{
    return (unsigned)s->closed;
}
#endif

static BH open_player(Source* s)
{
#ifdef HULK_TEST_XDK
    (void)s;
    return b_open();
#else
    HulkMovieIO io = make_io(s);
    return hulk_bink_open(&io, 0xa004000);
#endif
}

// the manual clock: the mixer's rendered frames
static unsigned long long clock_ms()
{
    unsigned v, p;
    unsigned long long frames;
    hulk_audio_stats(&v, &p, &frames);
    return frames * 1000ull / HULK_AUDIO_RATE;
}

static void test_player(const Case& c, const char* out_dir)
{
    printf("-- player: %s\n", c.name);
    int w = c.width, h = c.height;
    char wav[512];
    SDL_snprintf(wav, sizeof(wav), "%s/movies_%s.wav", out_dir, c.name);
    hulk_audio_set_capture(wav);
    hulk_bink_set_clock(clock_ms);
    unsigned track_ids[1] = {(unsigned)c.track_id};
    b_setup(c.src, track_ids, 1);
    BH b = open_player(c.src);
    CHECK(b != 0, "%s: open", c.name);
    if (!b)
        return;
    HulkBink* hdr = hb(b);
    CHECK((int)hdr->width == w && (int)hdr->height == h, "%s: handle size %ux%u", c.name, hdr->width, hdr->height);
    CHECK(hdr->frames > (unsigned)c.frames && hdr->frame_num == 0, "%s: handle frames %u, number %u", c.name,
          hdr->frames, hdr->frame_num);
    b_pause(b, 1);
    CHECK(b_wait(b) != 0, "%s: a paused movie waits", c.name);
    unsigned bins[2] = {HULK_BIN_FRONT_LEFT, HULK_BIN_FRONT_RIGHT};
    b_bins(b, c.track_id, bins, 2);
    b_volume(b, c.track_id, 65536);
    long base_ms = (long)clock_ms();   // (the mixer's frame count runs on from the earlier case)
    b_pause(b, 0);

    unsigned max_samples = (unsigned)c.frames * 1700u + 8000u;
    short* cap = (short*)SDL_malloc((size_t)max_samples * 2 * sizeof(short));
    unsigned ncap = 0;
    float out[2 * 800];
    unsigned char* img = (unsigned char*)SDL_malloc((size_t)w * h * 4);
    unsigned char* tmp = (unsigned char*)SDL_malloc((size_t)w * h * 4);
    int shown = 0, bad_frames = 0;
    double pmin = 99, psum = 0;
    long late_max = 0, late_min = 1 << 30;
    unsigned guard = 0;
    bool ok = true;
    while (shown < c.frames && ok && guard++ < (unsigned)c.frames * 3 + 600) {
        hulk_audio_render(out, 800);
        for (int i = 0; i < 800 && ncap < max_samples; i++, ncap++)
            for (int ch = 0; ch < 2; ch++) {
                float v = out[2 * i + ch] * 32768.0f;
                int s = (int)(v < 0 ? v - 0.5f : v + 0.5f);
                cap[2 * ncap + ch] = (short)(s > 32767 ? 32767 : s < -32768 ? -32768 : s);
            }
        while (shown < c.frames && !b_wait(b)) {
            if (b_do_frame(b) != 0) {
                CHECK(false, "%s: DoFrame failed at frame %u", c.name, hdr->frame_num);
                ok = false;
                break;
            }
            // the game's lock: bits = the top row, stride negative; the copy's dst is the lowest address
            SDL_memset(img, 0x55, (size_t)w * h * 4);
            int r = b_copy(b, img, -(w * 4), (unsigned)h, 0, 0, 0, 0, w, h);
            CHECK(r != 0, "%s: copy frame %d", c.name, shown);
            double p = 0;
            if (r) {
                // undo the flip into top-down rows and compare with the independent decode
                for (int y = 0; y < h; y++)
                    SDL_memcpy(tmp + (size_t)y * w * 4, img + (size_t)(h - 1 - y) * w * 4, (size_t)w * 4);
                p = psnr(tmp, c.ref->bgra + (unsigned long long)w * h * 4 * (unsigned)shown,
                         (unsigned long long)w * h * 4);
            }
            if (p < 38.0)
                bad_frames++;
            if (p < pmin)
                pmin = p;
            psum += p;
            long due = (long)((unsigned long long)hdr->frame_num * 1000ull * 1001 / 30000);   // 29.97 fps
            long now = (long)clock_ms() - base_ms;
            long late = now - due;
            if (late > late_max)
                late_max = late;
            if (late < late_min)
                late_min = late;
            CHECK(hdr->frame_num == (unsigned)shown, "%s: frame number %u at the %dth frame", c.name, hdr->frame_num,
                  shown);
            shown++;
            if (shown < c.frames)
                b_next(b);
        }
    }
    CHECK(shown == c.frames, "%s: showed %d of %d frames", c.name, shown, c.frames);
    CHECK(bad_frames == 0 && pmin > 38.0, "%s: %d frames below 38 dB (min %.2f)", c.name, bad_frames, pmin);
    printf("   %d frames through DoFrame / CopyToBuffer (flipped lock): PSNR min %.2f dB, mean %.2f dB vs ffmpeg\n", shown,
           pmin, psum / (shown ? shown : 1));
    // pacing: each frame appears when its time comes on the audio clock, at most one mixer step (16.7 ms) late
    CHECK(late_min >= -1 && late_max <= 18, "%s: frames shown %ld..%ld ms after their time", c.name, late_min, late_max);
    printf("   pacing on the audio clock: frames shown %ld..%ld ms after their due time (steps of 16.7 ms)\n", late_min,
           late_max);

    // a sub-rectangle into an offset, positive pitch (the other lock direction) equals the same rect of the full copy
    {
        int rx = 40, ry = 30, rw = 120, rh = 80;
        SDL_memset(tmp, 0xaa, (size_t)w * h * 4);
        int r = b_copy(b, tmp, w * 4, (unsigned)h, 8, 4, rx, ry, rw, rh);
        CHECK(r != 0, "%s: rect copy", c.name);
        // reference: the whole frame, positive pitch
        int r2 = b_copy(b, img, w * 4, (unsigned)h, 0, 0, 0, 0, w, h);
        CHECK(r2 != 0, "%s: full copy", c.name);
        int diff = 0;
        for (int y = 0; y < rh; y++)
            diff += SDL_memcmp(tmp + ((size_t)(y + 4) * w + 8) * 4, img + ((size_t)(y + ry) * w + rx) * 4, (size_t)rw * 4) != 0;
        CHECK(diff == 0, "%s: %d rows of the rect copy differ", c.name, diff);
        CHECK(((unsigned char*)tmp)[0] == 0xaa && tmp[((size_t)(rh + 4) * w + 8) * 4] == 0xaa,
              "%s: the rect copy stayed inside its rectangle", c.name);
        CHECK(b_copy(b, tmp, w * 4, (unsigned)h, 0, h - 10, 0, 0, 100, 40) == 0, "%s: a rect past the buffer fails", c.name);
    }

    // audio: the mixer's output for the track against the independent decode
    unsigned long long rendered = ncap;
    unsigned exact = 0, off = 0;
    int peak = 0;
    double e_out = 0, e_ref = 0;
    const short* rs = (const short*)c.ref->pcm;
    unsigned long long refn = c.ref->pcm_size / (2u * (unsigned)c.channels);
    unsigned n = ncap < refn ? ncap : (unsigned)refn;
    for (unsigned i = 0; i < n; i++)
        for (int ch = 0; ch < 2; ch++) {
            int refv = rs[i * (unsigned)c.channels + (c.channels == 2 ? ch : 0)];
            int d = cap[2 * i + ch] - refv;
            if (d == 0)
                exact++;
            if (d < -kAudioTol || d > kAudioTol)
                off++;
            int a = cap[2 * i + ch] < 0 ? -cap[2 * i + ch] : cap[2 * i + ch];
            if (a > peak)
                peak = a;
            e_out += (double)cap[2 * i + ch] * cap[2 * i + ch];
            e_ref += (double)refv * refv;
        }
    CHECK(off == 0, "%s: %u of %u mixed samples differ from the track by more than %d", c.name, off, n * 2, kAudioTol);
    double rms_out = SDL_sqrt(e_out / (n * 2.0)), rms_ref = SDL_sqrt(e_ref / (n * 2.0));
    CHECK(peak > 100 && peak < 32768, "%s: peak %d", c.name, peak);
    CHECK(near(rms_out, rms_ref, rms_ref * 0.002 + 1.0), "%s: rms %.1f vs %.1f", c.name, rms_out, rms_ref);
    double dur = (double)rendered / HULK_AUDIO_RATE, want = (double)(c.frames - 1) * 1001 / 30000;   // the last frame's due time
    CHECK(dur >= want - 0.001 && dur <= want + 0.02, "%s: %.3f s of audio until the last frame's time %.3f s", c.name, dur, want);
    printf("   audio into the mixer: %.3f s (last frame due at %.3f s), peak %d, rms %.1f (ffmpeg's %.1f), %u/%u samples exact\n",
           dur, want, peak, rms_out, rms_ref, exact, n * 2);
    SDL_free(cap);
    SDL_free(img);
    SDL_free(tmp);
    b_close(b);
    hulk_audio_set_capture(0);
    CHECK(b_closed_count(c.src) == 1, "%s: the game's I/O closed once (%u)", c.name, b_closed_count(c.src));
    c.src->closed = 0;
#ifdef HULK_TEST_XDK
    g_stream.released = 0;
#endif
}

// the wav the mixer wrote: header and length agree with what was rendered
static void check_wav(const char* out_dir, const char* name, unsigned min_frames)
{
    char path[512];
    SDL_snprintf(path, sizeof(path), "%s/movies_%s.wav", out_dir, name);
    unsigned long long size = 0;
    unsigned char* d = load(out_dir, path + SDL_strlen(out_dir) + 1, &size);
    CHECK(d && size > 44, "%s: wav written", name);
    if (!d || size <= 44)
        return;
    unsigned data = d[40] | (d[41] << 8) | (d[42] << 16) | ((unsigned)d[43] << 24);
    unsigned rate = d[24] | (d[25] << 8) | (d[26] << 16) | ((unsigned)d[27] << 24);
    CHECK(d[0] == 'R' && d[8] == 'W' && rate == 48000 && d[22] == 2 && data == size - 44, "%s: wav header (rate %u, %u data bytes of %llu)",
          name, rate, data, size - 44);
    CHECK(data / 4 >= min_frames, "%s: wav holds %u frames", name, data / 4);
    printf("   wav: %u frames at %u Hz stereo (%.3f s)\n", data / 4, rate, data / 4.0 / rate);
    SDL_free(d);
}

// ---------------------------------------------------------------------------------------------
// 0. the mixer's streaming voice (audio/hulk_audio.h): a ring the caller appends to
static int render_l(short* dst, unsigned n)
{
    float out[2 * 4096];
    int nonzero = 0;
    hulk_audio_render(out, n);
    for (unsigned i = 0; i < n; i++) {
        float v = out[2 * i] * 32768.0f;
        int sv = (int)(v < 0 ? v - 0.5f : v + 0.5f);
        dst[i] = (short)sv;
        nonzero += sv != 0;
    }
    return nonzero;
}

static void test_stream()
{
    printf("-- streaming voice\n");
    HulkAudioFormat fmt = {HULK_CODEC_PCM, 1, 16, 48000};
    HulkMixBin bins[1] = {{HULK_BIN_FRONT_LEFT, 0}};
    HulkVoice* v = hulk_audio_stream_create(&fmt, bins, 1, 1000);
    CHECK(v != 0, "stream voice created");
    if (!v)
        return;
    static short ramp[3000], got[4096];
    for (int i = 0; i < 3000; i++)
        ramp[i] = (short)(i * 7 - 9000);
    hulk_audio_voice_play(v, 0);
    CHECK((hulk_audio_voice_status(v) & HULK_STATUS_PLAYING) != 0, "playing with nothing queued");
    CHECK(render_l(got, 100) == 0 && hulk_audio_stream_played(v) == 0, "an empty ring is silence and holds its position");
    CHECK(hulk_audio_stream_write(v, ramp, 800) == 800 && hulk_audio_stream_queued(v) == 800, "800 frames queued");
    render_l(got, 500);
    CHECK(SDL_memcmp(got, ramp, 500 * 2) == 0 && hulk_audio_stream_played(v) == 500 && hulk_audio_stream_queued(v) == 300,
          "the first 500 frames come out in order (played %llu, queued %u)", hulk_audio_stream_played(v),
          hulk_audio_stream_queued(v));
    // the ring wraps: 600 more fit around the end of a 1000-frame ring
    CHECK(hulk_audio_stream_write(v, ramp + 800, 600) == 600 && hulk_audio_stream_queued(v) == 900, "600 more, wrapping");
    render_l(got, 900);
    CHECK(SDL_memcmp(got, ramp + 500, 900 * 2) == 0 && hulk_audio_stream_played(v) == 1400, "frames 500..1399 in order across the wrap");
    // an underrun: silence, the position stays, new data continues where it left off
    CHECK(render_l(got, 200) == 0 && hulk_audio_stream_played(v) == 1400, "underrun is silence and holds the position");
    hulk_audio_stream_write(v, ramp + 1400, 100);
    render_l(got, 100);
    CHECK(SDL_memcmp(got, ramp + 1400, 100 * 2) == 0, "data after an underrun continues the stream");
    // a full ring takes only what fits
    CHECK(hulk_audio_stream_write(v, ramp, 2000) == 1000 && hulk_audio_stream_write(v, ramp, 10) == 0, "a full ring takes what fits");
    hulk_audio_stream_flush(v);
    CHECK(hulk_audio_stream_queued(v) == 0 && hulk_audio_stream_played(v) == 2500, "flush drops the queue (counted as played)");
    // stopped: nothing is consumed
    hulk_audio_stream_write(v, ramp, 300);
    hulk_audio_voice_stop(v);
    CHECK(render_l(got, 200) == 0 && hulk_audio_stream_queued(v) == 300, "a stopped stream keeps its queue");
    hulk_audio_voice_release(v);

    // a 24 kHz stream plays at twice the length
    fmt.rate = 24000;
    v = hulk_audio_stream_create(&fmt, bins, 1, 2000);
    short flat[480];
    for (int i = 0; i < 480; i++)
        flat[i] = 1000;
    hulk_audio_stream_write(v, flat, 480);
    hulk_audio_voice_play(v, 0);
    int nz = render_l(got, 1200);
    CHECK(nz >= 958 && nz <= 962 && hulk_audio_stream_played(v) == 480, "480 frames at 24 kHz fill %d mixer frames", nz);
    // a stereo stream: left channel to the front left bin, right to front right (the mixer's rule for two bins)
    hulk_audio_voice_release(v);
    fmt.rate = 48000;
    fmt.channels = 2;
    HulkMixBin lr[2] = {{HULK_BIN_FRONT_LEFT, 0}, {HULK_BIN_FRONT_RIGHT, 0}};
    v = hulk_audio_stream_create(&fmt, lr, 2, 256);
    short st[2 * 100];
    for (int i = 0; i < 100; i++) {
        st[2 * i] = (short)(1000 + i);
        st[2 * i + 1] = (short)(-2000 - i);
    }
    hulk_audio_stream_write(v, st, 100);
    hulk_audio_voice_play(v, 0);
    float out[2 * 128];
    hulk_audio_render(out, 100);
    int bad = 0;
    for (int i = 0; i < 100; i++)
        bad += (int)SDL_lroundf(out[2 * i] * 32768.0f) != 1000 + i || (int)SDL_lroundf(out[2 * i + 1] * 32768.0f) != -2000 - i;
    CHECK(bad == 0, "stereo stream: %d wrong frames", bad);
    hulk_audio_voice_release(v);
}

// a file that is not a movie: the open fails and the I/O is closed once (the game's PlayerBink then skips the movie)
static int g_junk_closed;
static int junk_read(void*, unsigned long long, void* buf, int n)
{
    SDL_memset(buf, 0x5a, (size_t)n);
    return n;
}
static void junk_close(void*)
{
    g_junk_closed++;
}

static void test_failure()
{
    printf("-- not a movie\n");
    HulkMovieIO io;
    SDL_memset(&io, 0, sizeof(io));
    io.read = junk_read;
    io.close = junk_close;
    CHECK(hulk_bink_open(&io, 0) == 0 && g_junk_closed == 1, "garbage fails to open and its I/O is closed once (%d)", g_junk_closed);
}

// ---------------------------------------------------------------------------------------------
// 3. a whole short movie as the game plays it: six mono tracks, one per speaker bin, the end of the movie
static void test_surround(Source* src, const char* ref_dir, const char* out_dir)
{
    printf("-- surround: dolby (whole movie, six tracks to six bins)\n");
    float* ref[6];
    unsigned long long refn = 0;
    for (int i = 0; i < 6; i++) {
        char nm[16];
        unsigned long long sz = 0;
        if (i == 0)
            SDL_snprintf(nm, sizeof(nm), "d.f32");
        else
            SDL_snprintf(nm, sizeof(nm), "d%d.f32", i);
        ref[i] = (float*)load(ref_dir, nm, &sz);
        CHECK(ref[i] != 0, "reference track %d", i);
        if (!ref[i])
            return;
        refn = sz / 4;
    }
    char wav[512];
    SDL_snprintf(wav, sizeof(wav), "%s/movies_surround.wav", out_dir);
    hulk_audio_set_capture(wav);
    unsigned tracks[6] = {0, 1, 2, 3, 4, 5};
    b_setup(src, tracks, 6);
    hulk_bink_set_clock(clock_ms);
    BH b = open_player(src);
    CHECK(b != 0, "open");
    if (!b)
        return;
    HulkBink* hdr = hb(b);
    unsigned total = hdr->frames;
    b_pause(b, 1);
    for (unsigned i = 0; i < 6; i++) {                 // the speaker bins FL, FR, C, LFE, BL, BR, one track each
        unsigned bin = i;
        b_bins(b, (int)i, &bin, 1);
    }
    b_volume(b, 3, 32768);                              // the LFE at half gain (-6 dB)
    long base_ms = (long)clock_ms();
    b_pause(b, 0);
    static short cap[2 * 800 * 400];
    unsigned ncap = 0, shown = 0;
    float out[2 * 800];
    unsigned char* img = (unsigned char*)SDL_malloc(640 * 480 * 4);
    bool finished = false;
    for (unsigned guard = 0; !finished && guard < 400; guard++) {
        hulk_audio_render(out, 800);
        for (int i = 0; i < 800; i++, ncap++)
            for (int ch = 0; ch < 2; ch++) {
                float v = out[2 * i + ch] * 32768.0f;
                int sv = (int)(v < 0 ? v - 0.5f : v + 0.5f);
                cap[2 * ncap + ch] = (short)(sv > 32767 ? 32767 : sv < -32768 ? -32768 : sv);
            }
        while (!finished && !b_wait(b)) {
            if (b_do_frame(b) != 0) {
                CHECK(false, "DoFrame failed at frame %u", hdr->frame_num);
                finished = true;
                break;
            }
            b_copy(b, img, -(640 * 4), 480, 0, 0, 0, 0, 640, 480);
            shown++;
            if (hdr->frame_num == total - 1)    // the game's test (0x333de0): the last frame ends the movie
                finished = true;
            else
                b_next(b);
        }
    }
    CHECK(finished && shown == total && total == 120, "played %u of %u frames to the end", shown, total);
    long end_ms = (long)clock_ms() - base_ms;
    double last_due = (total - 1) * 1001.0 / 30.0;
    CHECK(end_ms >= last_due && end_ms <= last_due + 18, "the last frame at %ld ms (due %.1f)", end_ms, last_due);
    // the mixer's fold of the bins: L = FL + BL + 0.707 (C + LFE/2), R = FR + BR + 0.707 (C + LFE/2)
    const double k = 0.70710678;
    unsigned bad = 0, n = ncap < refn ? ncap : (unsigned)refn;
    double pk = 0;
    for (unsigned i = 0; i < n; i++) {
        double l = ref[0][i] + ref[4][i] + k * (ref[2][i] + 0.5 * ref[3][i]);
        double r = ref[1][i] + ref[5][i] + k * (ref[2][i] + 0.5 * ref[3][i]);
        int el = (int)SDL_floor(l * 32768.0 + 0.5), er = (int)SDL_floor(r * 32768.0 + 0.5);
        int dl = cap[2 * i] - (el > 32767 ? 32767 : el < -32768 ? -32768 : el);
        int dr = cap[2 * i + 1] - (er > 32767 ? 32767 : er < -32768 ? -32768 : er);
        if (dl < -2 || dl > 2 || dr < -2 || dr > 2)
            bad++;
        double a = cap[2 * i] < 0 ? -cap[2 * i] : cap[2 * i];
        if (a > pk)
            pk = a;
    }
    CHECK(bad == 0 && pk > 100, "%u of %u mixed frames are not the bins' fold (peak %.0f)", bad, n, pk);
    printf("   6 tracks -> FL FR C LFE BL BR -> stereo: %u frames (%.3f s) match the fold of ffmpeg's six decoded tracks within 2 LSB\n",
           n, (double)n / HULK_AUDIO_RATE);
    for (int i = 0; i < 6; i++)
        SDL_free(ref[i]);
    SDL_free(img);
    b_close(b);
    hulk_audio_set_capture(0);
    CHECK(b_closed_count(src) == 1, "the game's I/O closed once");
    src->closed = 0;
#ifdef HULK_TEST_XDK
    g_stream.released = 0;
#endif
}

int test_main(void)
{
    const char* ref_dir = SDL_getenv("HULK_TEST_REF");
    const char* out_dir = SDL_getenv("HULK_TEST_OUT");
    const char* fr = SDL_getenv("HULK_TEST_FRAMES");
    int frames = fr ? SDL_atoi(fr) : 60;
    Source s1, s2;
    bool have1 = parse_source(SDL_getenv("HULK_TEST_MOVIE"), &s1);
    bool have2 = parse_source(SDL_getenv("HULK_TEST_MOVIE2"), &s2);
    if (!have1 || !ref_dir || !out_dir) {
        printf("movies_test: set HULK_TEST_MOVIE, HULK_TEST_REF and HULK_TEST_OUT (tools/native_ffmpeg.py test)\n");
        return 2;
    }
    Ref r1, r2;
    SDL_memset(&r2, 0, sizeof(r2));
    CHECK(load_ref(ref_dir, "m", &r1), "reference decode of the multi-track movie");
    if (!r1.yuv || !r1.bgra || !r1.pcm)
        return test_done("movies");
    Case c1 = {"multitrack", &s1, &r1, frames, 0, 1, 640, 336, 6, 48000};
    hulk_audio_set_clock(HULK_CLOCK_MANUAL, 0);
    test_stream();
    test_failure();
    test_wrapper(c1);
    test_player(c1, out_dir);
    check_wav(out_dir, "multitrack", (unsigned)((frames - 1) * 1600));
    if (have2 && load_ref(ref_dir, "s", &r2)) {
        Case c2 = {"stereo", &s2, &r2, frames, 0, 2, 640, 480, 1, 48000};
        test_wrapper(c2);
        test_player(c2, out_dir);
        check_wav(out_dir, "stereo", (unsigned)((frames - 1) * 1600));
    }
    Source s3;
    if (parse_source(SDL_getenv("HULK_TEST_MOVIE3"), &s3))
        test_surround(&s3, ref_dir, out_dir);
    hulk_audio_shutdown();
    return test_done("movies");
}
