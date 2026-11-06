// The movie decoder's interface (movies/movie.h) without FFmpeg: every open fails, as movie.c's does for a file FFmpeg
// cannot read, so the Bink stand-in (movies/bink_player.cpp) reports the movie as unplayable and the game goes on.
// Native ELF images link this when no FFmpeg is configured for the target (tools/native_elf.py, HULK_LINUX_FFMPEG);
// a headless replay that skips the intro needs no movie. Not a Wine build input.
#include "movies/movie.h"

#include <stddef.h>

hulk_movie_log_fn hulk_movie_log_sink = 0;

HulkMovie* hulk_movie_open(const HulkMovieIO* io)
{
    if (hulk_movie_log_sink)
        hulk_movie_log_sink("movie: no FFmpeg in this image (src/platform/sdl/host/movie_none.c)");
    if (io && io->close)
        io->close(io->ctx);
    return NULL;
}

void hulk_movie_close(HulkMovie* m) { (void)m; }
const HulkMovieInfo* hulk_movie_info(const HulkMovie* m) { (void)m; return NULL; }
int hulk_movie_track(const HulkMovie* m, int index, HulkMovieTrack* out) { (void)m; (void)index; (void)out; return 0; }
void hulk_movie_select_tracks(HulkMovie* m, const int* ids, int count) { (void)m; (void)ids; (void)count; }
int hulk_movie_decode_video(HulkMovie* m, HulkMovieFrame* out) { (void)m; (void)out; return 0; }
void hulk_movie_pump_audio(HulkMovie* m, unsigned frames) { (void)m; (void)frames; }
unsigned hulk_movie_audio_queued(const HulkMovie* m, int track_id) { (void)m; (void)track_id; return 0; }
unsigned hulk_movie_audio_read(HulkMovie* m, int track_id, short* out, unsigned frames)
{
    (void)m; (void)track_id; (void)out; (void)frames;
    return 0;
}
int hulk_movie_at_end(const HulkMovie* m) { (void)m; return 1; }
int hulk_movie_demux_done(const HulkMovie* m) { (void)m; return 1; }
void hulk_movie_to_bgra(const HulkMovieFrame* f, unsigned char* dst, int pitch, int sx, int sy, int w, int h)
{
    (void)f; (void)dst; (void)pitch; (void)sx; (void)sy; (void)w; (void)h;
}
