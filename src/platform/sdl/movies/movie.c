// The native movie decoder on FFmpeg's libavformat / libavcodec (movie.h, docs/native-movies.md). Plain C against
// FFmpeg's public headers (an LGPL shared library, built by tools/native_ffmpeg.py); no RAD code.
#include "movie.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/channel_layout.h>
#include <libavutil/error.h>
#include <libavutil/log.h>
#include <libavutil/mem.h>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

hulk_movie_log_fn hulk_movie_log_sink = 0;

#define MAX_TRACKS 8
#define MAX_VPACKETS 128
#define IO_BUFFER 65536

typedef struct Track {
    int id;
    int stream;                     // index in the demuxer
    int rate, channels;
    int selected;
    AVCodecContext* ctx;
    short* pcm;                     // interleaved queue: [head, tail) frames
    unsigned cap, head, tail;       // in frames
} Track;

struct HulkMovie {
    HulkMovieIO io;
    unsigned long long pos;
    AVFormatContext* fmt;
    AVIOContext* avio;
    AVCodecContext* vctx;
    AVFrame* vframe;
    AVFrame* aframe;
    AVPacket* pkt;
    HulkMovieInfo info;
    Track tracks[MAX_TRACKS];
    int ntracks;
    AVPacket* vq[MAX_VPACKETS];     // read-ahead video packets (ring)
    int vq_head, vq_count;
    int eof;                        // the demuxer is exhausted
    unsigned decoded;               // video frames decoded
    int tracks_opened;
};

static void mlog(const char* what, int err)
{
    if (!hulk_movie_log_sink)
        return;
    char line[160], msg[64];
    av_strerror(err, msg, sizeof(msg));
    line[0] = 0;
    strncat(line, "movie: ", sizeof(line) - 1);
    strncat(line, what, sizeof(line) - 1 - strlen(line));
    strncat(line, ": ", sizeof(line) - 1 - strlen(line));
    strncat(line, msg, sizeof(line) - 1 - strlen(line));
    hulk_movie_log_sink(line);
}

static int io_read(void* opaque, uint8_t* buf, int n)
{
    HulkMovie* m = (HulkMovie*)opaque;
    if (m->io.size) {               // never ask the stream for bytes past the file's end
        if (m->pos >= m->io.size)
            return AVERROR_EOF;
        if (m->pos + (unsigned)n > m->io.size)
            n = (int)(m->io.size - m->pos);
    }
    int got = m->io.read(m->io.ctx, m->pos, buf, n);
    if (got < 0)
        return AVERROR(EIO);
    if (got == 0)
        return AVERROR_EOF;
    m->pos += (unsigned)got;
    return got;
}

static int64_t io_seek(void* opaque, int64_t off, int whence)
{
    HulkMovie* m = (HulkMovie*)opaque;
    if (whence & AVSEEK_SIZE)
        return m->io.size ? (int64_t)m->io.size : -1;
    switch (whence) {
    case SEEK_SET:
        break;
    case SEEK_CUR:
        off += (int64_t)m->pos;
        break;
    case SEEK_END:
        if (!m->io.size)
            return -1;
        off += (int64_t)m->io.size;
        break;
    default:
        return -1;
    }
    if (off < 0)
        return -1;
    m->pos = (unsigned long long)off;
    return off;
}

void hulk_movie_close(HulkMovie* m)
{
    if (!m)
        return;
    for (int i = 0; i < m->ntracks; i++) {
        avcodec_free_context(&m->tracks[i].ctx);
        free(m->tracks[i].pcm);
    }
    for (int i = 0; i < m->vq_count; i++)
        av_packet_free(&m->vq[(m->vq_head + i) % MAX_VPACKETS]);
    avcodec_free_context(&m->vctx);
    av_frame_free(&m->vframe);
    av_frame_free(&m->aframe);
    av_packet_free(&m->pkt);
    if (m->fmt)
        avformat_close_input(&m->fmt);     // (the AVIO context stays ours: custom IO)
    if (m->avio) {
        av_freep(&m->avio->buffer);
        avio_context_free(&m->avio);
    }
    if (m->io.close)
        m->io.close(m->io.ctx);
    free(m);
}

HulkMovie* hulk_movie_open(const HulkMovieIO* io)
{
    HulkMovie* m = (HulkMovie*)calloc(1, sizeof(HulkMovie));
    if (!m) {
        if (io->close)
            io->close(io->ctx);
        return 0;
    }
    m->io = *io;
    av_log_set_level(AV_LOG_ERROR);
    if (!m->io.size) {              // a Bink file's header: "BIK?" then the size - 8
        unsigned char h[8];
        if (m->io.read(m->io.ctx, 0, h, 8) == 8 && h[0] == 'B' && h[1] == 'I' && h[2] == 'K')
            m->io.size = (unsigned long long)(h[4] | (h[5] << 8) | (h[6] << 16) | ((unsigned)h[7] << 24)) + 8;
    }
    uint8_t* buf = (uint8_t*)av_malloc(IO_BUFFER);
    m->avio = buf ? avio_alloc_context(buf, IO_BUFFER, 0, m, io_read, 0, io_seek) : 0;
    m->fmt = avformat_alloc_context();
    if (!m->avio || !m->fmt) {
        if (!m->avio)
            av_free(buf);
        goto fail;
    }
    m->fmt->pb = m->avio;
    m->fmt->flags |= AVFMT_FLAG_CUSTOM_IO;
    const AVInputFormat* bink = av_find_input_format("bink");
    int r = avformat_open_input(&m->fmt, "", bink, 0);
    if (r < 0) {
        mlog("avformat_open_input", r);
        m->fmt = 0;                 // freed by the failed open
        goto fail;
    }
    // the streams: 0 is the video, the rest are audio tracks (the demuxer's header states everything)
    AVStream* vs = 0;
    for (unsigned i = 0; i < m->fmt->nb_streams; i++) {
        AVStream* s = m->fmt->streams[i];
        if (s->codecpar->codec_type == AVMEDIA_TYPE_VIDEO && !vs)
            vs = s;
        else if (s->codecpar->codec_type == AVMEDIA_TYPE_AUDIO && m->ntracks < MAX_TRACKS) {
            Track* t = &m->tracks[m->ntracks++];
            t->id = s->id;
            t->stream = (int)i;
            t->rate = s->codecpar->sample_rate;
            t->channels = s->codecpar->ch_layout.nb_channels;
        }
    }
    if (!vs)
        goto fail;
    const AVCodec* vc = avcodec_find_decoder(vs->codecpar->codec_id);
    m->vctx = vc ? avcodec_alloc_context3(vc) : 0;
    if (!m->vctx || avcodec_parameters_to_context(m->vctx, vs->codecpar) < 0)
        goto fail;
    m->vctx->thread_count = 1;
    if ((r = avcodec_open2(m->vctx, vc, 0)) < 0) {
        mlog("video decoder", r);
        goto fail;
    }
    m->info.width = vs->codecpar->width;
    m->info.height = vs->codecpar->height;
    m->info.frames = (unsigned)vs->duration;
    m->info.fps_num = vs->avg_frame_rate.num;
    m->info.fps_den = vs->avg_frame_rate.den;
    m->info.tracks = m->ntracks;
    m->info.alpha = 0;
    m->vframe = av_frame_alloc();
    m->aframe = av_frame_alloc();
    m->pkt = av_packet_alloc();
    if (!m->vframe || !m->aframe || !m->pkt)
        goto fail;
    return m;
fail:
    hulk_movie_close(m);
    return 0;
}

const HulkMovieInfo* hulk_movie_info(const HulkMovie* m)
{
    return &m->info;
}

int hulk_movie_track(const HulkMovie* m, int index, HulkMovieTrack* out)
{
    if (index < 0 || index >= m->ntracks)
        return 0;
    out->id = m->tracks[index].id;
    out->rate = m->tracks[index].rate;
    out->channels = m->tracks[index].channels;
    return 1;
}

void hulk_movie_select_tracks(HulkMovie* m, const int* ids, int count)
{
    for (int i = 0; i < m->ntracks; i++) {
        Track* t = &m->tracks[i];
        int want = 0;
        for (int k = 0; k < count; k++)
            if (ids[k] == t->id)
                want = 1;
        if (want && !t->ctx) {
            AVStream* s = m->fmt->streams[t->stream];
            const AVCodec* c = avcodec_find_decoder(s->codecpar->codec_id);
            t->ctx = c ? avcodec_alloc_context3(c) : 0;
            if (t->ctx && (avcodec_parameters_to_context(t->ctx, s->codecpar) < 0 || avcodec_open2(t->ctx, c, 0) < 0))
                avcodec_free_context(&t->ctx);
            want = t->ctx != 0;
        }
        t->selected = want;
    }
}

static Track* track_by_id(const HulkMovie* m, int id)
{
    for (int i = 0; i < m->ntracks; i++)
        if (m->tracks[i].id == id)
            return (Track*)&m->tracks[i];
    return 0;
}

// appends the decoded frame (planar or packed float / 16-bit) to the track's queue as interleaved 16-bit
static void queue_frame(Track* t, const AVFrame* f)
{
    unsigned n = (unsigned)f->nb_samples;
    int ch = t->channels;
    if (t->head && t->head == t->tail)
        t->head = t->tail = 0;
    if (t->tail + n > t->cap) {
        if (t->head) {              // slide the unread frames down first
            memmove(t->pcm, t->pcm + (size_t)t->head * ch, (size_t)(t->tail - t->head) * ch * sizeof(short));
            t->tail -= t->head;
            t->head = 0;
        }
        if (t->tail + n > t->cap) {
            unsigned cap = t->cap ? t->cap : 8192;
            while (cap < t->tail + n)
                cap *= 2;
            short* p = (short*)realloc(t->pcm, (size_t)cap * ch * sizeof(short));
            if (!p)
                return;
            t->pcm = p;
            t->cap = cap;
        }
    }
    short* out = t->pcm + (size_t)t->tail * ch;
    for (int c = 0; c < ch; c++) {
        if (f->format == AV_SAMPLE_FMT_FLTP) {
            const float* in = (const float*)f->extended_data[c];
            for (unsigned i = 0; i < n; i++) {
                float v = in[i] * 32768.0f;
                int s = (int)(v < 0 ? v - 0.5f : v + 0.5f);
                out[(size_t)i * ch + c] = (short)(s > 32767 ? 32767 : s < -32768 ? -32768 : s);
            }
        } else if (f->format == AV_SAMPLE_FMT_FLT) {          // (the RDFT decoder's: interleaved)
            const float* in = (const float*)f->extended_data[0];
            for (unsigned i = 0; i < n; i++) {
                float v = in[(size_t)i * ch + c] * 32768.0f;
                int s = (int)(v < 0 ? v - 0.5f : v + 0.5f);
                out[(size_t)i * ch + c] = (short)(s > 32767 ? 32767 : s < -32768 ? -32768 : s);
            }
        } else if (f->format == AV_SAMPLE_FMT_S16P) {
            const short* in = (const short*)f->extended_data[c];
            for (unsigned i = 0; i < n; i++)
                out[(size_t)i * ch + c] = in[i];
        } else if (f->format == AV_SAMPLE_FMT_S16) {
            const short* in = (const short*)f->extended_data[0];
            for (unsigned i = 0; i < n; i++)
                out[(size_t)i * ch + c] = in[(size_t)i * ch + c];
        } else {                                                // (no other format comes out of the Bink decoders)
            for (unsigned i = 0; i < n; i++)
                out[(size_t)i * ch + c] = 0;
        }
    }
    t->tail += n;
}

static void decode_audio_packet(HulkMovie* m, Track* t, const AVPacket* pkt)
{
    if (avcodec_send_packet(t->ctx, pkt) < 0)
        return;
    while (avcodec_receive_frame(t->ctx, m->aframe) >= 0) {
        queue_frame(t, m->aframe);
        av_frame_unref(m->aframe);
    }
}

// Reads one packet from the demuxer: a video packet goes to the read-ahead ring (returns 1), an audio packet of a
// selected track is decoded (returns 2), anything else is dropped (returns 2). 0: the end, < 0: an error.
static int read_one(HulkMovie* m)
{
    if (m->eof)
        return 0;
    int r = av_read_frame(m->fmt, m->pkt);
    if (r < 0) {
        if (r == AVERROR_EOF) {
            m->eof = 1;
            return 0;
        }
        mlog("av_read_frame", r);
        m->eof = 1;
        return r;
    }
    int stream = m->pkt->stream_index;
    if (m->fmt->streams[stream]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
        AVPacket* keep = av_packet_alloc();
        if (!keep) {
            av_packet_unref(m->pkt);
            return AVERROR(ENOMEM);
        }
        av_packet_move_ref(keep, m->pkt);
        m->vq[(m->vq_head + m->vq_count) % MAX_VPACKETS] = keep;
        m->vq_count++;
        return 1;
    }
    for (int i = 0; i < m->ntracks; i++)
        if (m->tracks[i].stream == stream && m->tracks[i].selected)
            decode_audio_packet(m, &m->tracks[i], m->pkt);
    av_packet_unref(m->pkt);
    return 2;
}

void hulk_movie_pump_audio(HulkMovie* m, unsigned frames)
{
    for (;;) {
        int need = 0;
        for (int i = 0; i < m->ntracks; i++)
            if (m->tracks[i].selected && m->tracks[i].tail - m->tracks[i].head < frames)
                need = 1;
        if (!need || m->vq_count >= MAX_VPACKETS - 1)
            return;
        if (read_one(m) <= 0)
            return;
    }
}

int hulk_movie_decode_video(HulkMovie* m, HulkMovieFrame* out)
{
    while (m->vq_count == 0) {
        int r = read_one(m);
        if (r <= 0)
            return r;
    }
    AVPacket* p = m->vq[m->vq_head];
    m->vq_head = (m->vq_head + 1) % MAX_VPACKETS;
    m->vq_count--;
    int r = avcodec_send_packet(m->vctx, p);
    av_packet_free(&p);
    if (r < 0) {
        mlog("video packet", r);
        return r;
    }
    av_frame_unref(m->vframe);
    r = avcodec_receive_frame(m->vctx, m->vframe);
    if (r < 0) {
        mlog("video frame", r);
        return r;
    }
    AVFrame* f = m->vframe;
    for (int i = 0; i < 4; i++) {
        out->plane[i] = f->data[i];
        out->stride[i] = f->linesize[i];
    }
    if (f->format != AV_PIX_FMT_YUVA420P)
        out->plane[3] = 0;
    else
        m->info.alpha = 1;
    out->width = f->width;
    out->height = f->height;
    out->index = m->decoded++;
    return 1;
}

unsigned hulk_movie_audio_queued(const HulkMovie* m, int track_id)
{
    const Track* t = track_by_id(m, track_id);
    return t ? t->tail - t->head : 0;
}

unsigned hulk_movie_audio_read(HulkMovie* m, int track_id, short* out, unsigned frames)
{
    Track* t = track_by_id(m, track_id);
    if (!t)
        return 0;
    unsigned have = t->tail - t->head;
    if (frames > have)
        frames = have;
    memcpy(out, t->pcm + (size_t)t->head * t->channels, (size_t)frames * t->channels * sizeof(short));
    t->head += frames;
    return frames;
}

int hulk_movie_at_end(const HulkMovie* m)
{
    return m->eof && m->vq_count == 0;
}

int hulk_movie_demux_done(const HulkMovie* m)
{
    return m->eof;
}

// ---------------------------------------------------------------------------------------------------------------
static unsigned char clamp8(int v)
{
    return (unsigned char)(v < 0 ? 0 : v > 255 ? 255 : v);
}

void hulk_movie_to_bgra(const HulkMovieFrame* f, unsigned char* dst, int pitch, int sx, int sy, int w, int h)
{
    if (sx < 0 || sy < 0 || sx >= f->width || sy >= f->height)
        return;
    if (sx + w > f->width)
        w = f->width - sx;
    if (sy + h > f->height)
        h = f->height - sy;
    int cw = (f->width + 1) / 2, ch = (f->height + 1) / 2;
    int* tmp = (int*)malloc((size_t)cw * 2 * sizeof(int));
    if (!tmp)
        return;
    int* tu = tmp;
    int* tv = tmp + cw;
    for (int y = sy; y < sy + h; y++) {
        // vertical chroma blend: 3/4 of the nearer chroma row and 1/4 of the next one toward this luma row
        int cy = y >> 1;
        int cy2 = (y & 1) ? cy + 1 : cy - 1;
        cy2 = cy2 < 0 ? 0 : cy2 >= ch ? ch - 1 : cy2;
        const unsigned char* u0 = f->plane[1] + (size_t)cy * f->stride[1];
        const unsigned char* u1 = f->plane[1] + (size_t)cy2 * f->stride[1];
        const unsigned char* v0 = f->plane[2] + (size_t)cy * f->stride[2];
        const unsigned char* v1 = f->plane[2] + (size_t)cy2 * f->stride[2];
        for (int i = 0; i < cw; i++) {
            tu[i] = 3 * u0[i] + u1[i];      // x4
            tv[i] = 3 * v0[i] + v1[i];
        }
        const unsigned char* Y = f->plane[0] + (size_t)y * f->stride[0];
        const unsigned char* A = f->plane[3] ? f->plane[3] + (size_t)y * f->stride[3] : 0;
        unsigned char* o = dst + (ptrdiff_t)(y - sy) * pitch;
        for (int x = sx; x < sx + w; x++) {
            int cx = x >> 1;
            int cx2 = (x & 1) ? cx + 1 : cx - 1;
            cx2 = cx2 < 0 ? 0 : cx2 >= cw ? cw - 1 : cx2;
            int u = ((3 * tu[cx] + tu[cx2] + 8) >> 4) - 128;     // /16
            int v = ((3 * tv[cx] + tv[cx2] + 8) >> 4) - 128;
            int c = 298 * (Y[x] - 16) + 128;
            o[0] = clamp8((c + 516 * u) >> 8);
            o[1] = clamp8((c - 100 * u - 208 * v) >> 8);
            o[2] = clamp8((c + 409 * v) >> 8);
            o[3] = A ? A[x] : 255;
            o += 4;
        }
    }
    free(tmp);
}
