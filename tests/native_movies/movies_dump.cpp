// Host tool for tools/native_ffmpeg.py inventory: decodes a whole movie through the wrapper (movie.h) and prints what
// came out, for comparison with the ffmpeg command line's decode of the same file:
//   movies_dump "<archive>|<offset>|<size>"
//   movie <width> <height> <frames> <fps_num> <fps_den> <alpha> <tracks>
//   track <id> <rate> <channels> <frames> <crc32 of the interleaved 16-bit PCM> <samples compared> <equal> <within 1>
//     <largest difference>       (the last four against refdir/a<index>.f32, ffmpeg's decoded floats, converted the way
//                                 the wrapper does, when a second argument names a directory)
//   F <n> <adler32 of the packed yuv420p frame>          (one line per video frame)
//   done <video frames decoded> <seconds>
#include "movies/movie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Source {
    FILE* f;
    unsigned long long base, size;
};

static int src_read(void* ctx, unsigned long long pos, void* buf, int n)
{
    Source* s = (Source*)ctx;
    if (pos >= s->size)
        return 0;
    if (pos + (unsigned)n > s->size)
        n = (int)(s->size - pos);
    if (fseeko(s->f, (off_t)(s->base + pos), SEEK_SET) != 0)
        return -1;
    return (int)fread(buf, 1, (size_t)n, s->f);
}

static void src_close(void* ctx)
{
    fclose(((Source*)ctx)->f);
}

static unsigned crc32(unsigned crc, const unsigned char* p, size_t n)
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
    for (size_t i = 0; i < n; i++)
        crc = table[(crc ^ p[i]) & 0xff] ^ (crc >> 8);
    return ~crc;
}

int main(int argc, char** argv)
{
    if (argc < 2)
        return 2;
    const char* refdir = argc > 2 ? argv[2] : 0;
    char path[1024];
    unsigned long long base = 0, size = 0;
    if (sscanf(argv[1], "%1023[^|]|%llu|%llu", path, &base, &size) != 3)
        return 2;
    Source s;
    s.f = fopen(path, "rb");
    s.base = base;
    s.size = size;
    if (!s.f)
        return 3;
    HulkMovieIO io = {};
    io.ctx = &s;
    io.read = src_read;
    io.close = src_close;
    HulkMovie* m = hulk_movie_open(&io);
    if (!m)
        return 4;
    const HulkMovieInfo* in = hulk_movie_info(m);
    int ids[16], n = 0;
    for (int i = 0; i < in->tracks && n < 16; i++) {
        HulkMovieTrack t;
        hulk_movie_track(m, i, &t);
        ids[n++] = t.id;
    }
    hulk_movie_select_tracks(m, ids, n);
    short* buf = (short*)malloc(65536 * 2 * sizeof(short));
    struct T {
        HulkMovieTrack info;
        unsigned crc;
        unsigned long long frames;
        FILE* ref;
        unsigned long long cmp, equal, within1;
        int maxdiff;
    } tracks[16];
    for (int i = 0; i < n; i++) {
        hulk_movie_track(m, i, &tracks[i].info);
        tracks[i].crc = 0;
        tracks[i].frames = 0;
        tracks[i].ref = 0;
        tracks[i].cmp = tracks[i].equal = tracks[i].within1 = 0;
        tracks[i].maxdiff = 0;
        if (refdir) {
            char rp[1100];
            snprintf(rp, sizeof(rp), "%s/a%d.f32", refdir, i);
            tracks[i].ref = fopen(rp, "rb");
        }
    }
    auto consume = [&](T& t, unsigned q) {
        t.crc = crc32(t.crc, (const unsigned char*)buf, (size_t)q * t.info.channels * 2);
        t.frames += q;
        if (t.ref) {
            static float rbuf[65536 * 2];
            size_t want = (size_t)q * t.info.channels;
            size_t got = fread(rbuf, 4, want, t.ref);
            for (size_t k = 0; k < got; k++) {
                float v = rbuf[k] * 32768.0f;                       // (movie.c's conversion)
                int r = (int)(v < 0 ? v - 0.5f : v + 0.5f);
                r = r > 32767 ? 32767 : r < -32768 ? -32768 : r;
                int d = buf[k] - r;
                if (d < 0)
                    d = -d;
                t.cmp++;
                t.equal += d == 0;
                t.within1 += d <= 1;
                if (d > t.maxdiff)
                    t.maxdiff = d;
            }
        }
    };
    int alpha = 0;
    unsigned long long decoded = 0;
    clock_t t0 = clock();
    HulkMovieFrame f;
    char line[64];
    (void)line;
    while (hulk_movie_decode_video(m, &f) == 1) {
        unsigned a = 1, b = 0;
        int w = f.width, h = f.height, cw = (w + 1) / 2, ch = (h + 1) / 2;
        int pw[3] = {w, cw, cw}, ph[3] = {h, ch, ch};
        for (int p = 0; p < 3; p++)
            for (int y = 0; y < ph[p]; y++) {
                const unsigned char* r = f.plane[p] + (size_t)y * f.stride[p];
                for (int x = 0; x < pw[p]; x += 5552) {          // (zlib's NMAX: no overflow before the modulo)
                    int e = x + 5552 < pw[p] ? x + 5552 : pw[p];
                    for (int k = x; k < e; k++) {
                        a += r[k];
                        b += a;
                    }
                    a %= 65521;
                    b %= 65521;
                }
            }
        printf("F %llu %08x\n", decoded, (b << 16) | a);
        decoded++;
        alpha |= f.plane[3] != 0;
        for (int i = 0; i < n; i++) {
            unsigned q;
            while ((q = hulk_movie_audio_read(m, tracks[i].info.id, buf, 65536)) > 0)
                consume(tracks[i], q);
        }
    }
    // the demuxer is done: whatever audio is left
    hulk_movie_pump_audio(m, 0x7fffffff);
    for (int i = 0; i < n; i++) {
        unsigned q;
        while ((q = hulk_movie_audio_read(m, tracks[i].info.id, buf, 65536)) > 0)
            consume(tracks[i], q);
    }
    printf("movie %d %d %u %d %d %d %d\n", in->width, in->height, in->frames, in->fps_num, in->fps_den, alpha, in->tracks);
    for (int i = 0; i < n; i++)
        printf("track %d %d %d %llu %08x %llu %llu %llu %d\n", tracks[i].info.id, tracks[i].info.rate,
               tracks[i].info.channels, tracks[i].frames, tracks[i].crc, tracks[i].cmp, tracks[i].equal,
               tracks[i].within1, tracks[i].maxdiff);
    printf("done %llu %.2f\n", decoded, (double)(clock() - t0) / CLOCKS_PER_SEC);
    hulk_movie_close(m);
    free(buf);
    return 0;
}
