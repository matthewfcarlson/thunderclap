// The native movie decoder (docs/native-movies.md): the game's movies are Bink 1 files (.rmv in the movie
// archives); FFmpeg's libavformat/libavcodec (LGPL, shared libraries built by tools/native_ffmpeg.py: the bink
// demuxer and the bink video / audio decoders only) decode them. Typed and pointer-sized: the host tests call it
// directly; bink_player.h shapes it like the game's Bink calls and src/platform/sdl/xdk/movies_bink.cpp
// translates the game's 32-bit arguments.
//
// A movie reads its bytes through a HulkMovieIO (the game's own stream layer in the image, a file in tests),
// demuxes forward, decodes video frames on demand and decodes the audio tracks the caller selected into per-track
// 16-bit PCM queues. Not thread safe: one thread drives a movie.
#ifndef HULK_PLATFORM_SDL_MOVIE_H
#define HULK_PLATFORM_SDL_MOVIE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HulkMovie HulkMovie;

// Where the bytes come from. read: up to n bytes at absolute offset pos; returns the count (0 at the end, < 0 on an
// error). size: the file's size, or 0 when unknown (a Bink file's header gives it: bytes 4..8 + 8). close runs
// once from hulk_movie_close.
typedef struct HulkMovieIO {
    void* ctx;
    int (*read)(void* ctx, unsigned long long pos, void* buf, int n);
    void (*close)(void* ctx);
    unsigned long long size;
} HulkMovieIO;

typedef struct HulkMovieInfo {
    int width, height;
    unsigned frames;                // video frames in the file
    int fps_num, fps_den;           // frame rate
    int alpha;                      // the video carries an alpha plane
    int tracks;                     // audio tracks
} HulkMovieInfo;

typedef struct HulkMovieTrack {
    int id;                         // the id the game selects it by (the file's track id)
    int rate;                       // Hz
    int channels;                   // 1 or 2
} HulkMovieTrack;

// A decoded frame: planar YUV 4:2:0 (a pointer into the decoder, valid until the next hulk_movie_decode_video).
typedef struct HulkMovieFrame {
    const unsigned char* plane[4];  // Y, U, V, A (0 without alpha)
    int stride[4];
    int width, height;
    unsigned index;                 // 0-based
} HulkMovieFrame;

// Opens the movie (reads the header). Takes ownership of io on success and on failure (its close runs).
HulkMovie* hulk_movie_open(const HulkMovieIO* io);
void hulk_movie_close(HulkMovie* m);
const HulkMovieInfo* hulk_movie_info(const HulkMovie* m);
int hulk_movie_track(const HulkMovie* m, int index, HulkMovieTrack* out);   // 1 if index < tracks

// Selects the audio tracks to decode (by id; the rest are dropped unread-ahead). Call before the first decode.
void hulk_movie_select_tracks(HulkMovie* m, const int* ids, int count);

// Decodes the next video frame (audio packets met on the way are decoded into the selected tracks' queues).
// Returns 1 with *out set, 0 at the end of the movie, < 0 on an error.
int hulk_movie_decode_video(HulkMovie* m, HulkMovieFrame* out);

// Reads ahead until every selected track queues at least `frames` PCM frames (or the movie ends). Video packets met
// are kept for the next hulk_movie_decode_video calls (up to 128; beyond that the read stops).
void hulk_movie_pump_audio(HulkMovie* m, unsigned frames);

// The selected track's queue: frames waiting, and a pop of up to `frames` (interleaved 16-bit; returns the count).
unsigned hulk_movie_audio_queued(const HulkMovie* m, int track_id);
unsigned hulk_movie_audio_read(HulkMovie* m, int track_id, short* out, unsigned frames);

// 1 once the demuxer has no more packets and every queued video packet was decoded.
int hulk_movie_at_end(const HulkMovie* m);
// 1 once the demuxer has no more packets (video packets read ahead may still wait, and audio may still be queued).
int hulk_movie_demux_done(const HulkMovie* m);

// BT.601 limited-range YUV -> B, G, R, A bytes (A = the alpha plane, or 255), the rectangle (sx, sy, w, h) of the
// frame written to dst at (dx, dy) of a buffer `pitch` bytes a row (pitch may be negative: rows then run toward
// lower addresses, dst pointing at the first row). Chroma is interpolated bilinearly (centred siting).
void hulk_movie_to_bgra(const HulkMovieFrame* f, unsigned char* dst, int pitch, int sx, int sy, int w, int h);

// Log sink (default: SDL_Log)
typedef void (*hulk_movie_log_fn)(const char* line);
extern hulk_movie_log_fn hulk_movie_log_sink;

#ifdef __cplusplus
}
#endif

#endif
