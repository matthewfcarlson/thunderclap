// The Bink-shaped player (docs/native-movies.md): what the game's movie code asks of "Bink", on the movie decoder
// (movie.h) and the audio mixer's streaming voices (audio/hulk_audio.h). Typed and pointer-sized; the xdk stand-ins
// (src/platform/sdl/xdk/movies_bink.cpp) translate the game's 32-bit calls into these.
//
// The shapes come from the game's own call sites (movie::PlayerBink 0x333cb0 / 0x333de0 / 0x333970 / 0x333fa0):
//   open         BinkOpen(name, flags) -> handle; the game then pauses it, routes each sound track to mix bins and
//                sets its volume, reads width / height / frames / frame number off the handle's first four words
//   per frame    BinkWait (non-zero: not yet time), BinkDoFrame (0: decoded), BinkCopyToBufferRect per tile
//                (non-zero: copied), BinkNextFrame; the game ends the movie after the frame whose number is
//                frames - 1 and never calls NextFrame on it
//   pause        BinkPause(handle, 1 | 0): the movie opens paused; the game unpauses it to start the clock and audio
//   close        BinkClose(handle)
//   setup        BinkSetIO(open callback), BinkSetSoundTrack(count, ids): both before the open
#ifndef HULK_PLATFORM_SDL_BINK_PLAYER_H
#define HULK_PLATFORM_SDL_BINK_PLAYER_H

#include "movie.h"

#ifdef __cplusplus
extern "C" {
#endif

// The handle. The game reads the first four words; the rest is the player's.
typedef struct HulkBink {
    unsigned width, height;
    unsigned frames;                // video frames
    unsigned frame_num;             // 0-based number of the frame DoFrame decodes next / just decoded
    unsigned reserved[12];          // (zero)
    struct HulkBinkPrivate* priv;
} HulkBink;

// Sound tracks to play from the next open on (ids as the movie file numbers them; the game selects by these).
// count 0: no sound. Applies to movies opened afterwards.
void hulk_bink_set_tracks(const unsigned* ids, unsigned count);

// Opens a movie (paused). Takes ownership of io. 0 on failure.
HulkBink* hulk_bink_open(const HulkMovieIO* io, unsigned flags);
void hulk_bink_close(HulkBink* b);

// Where a track's audio goes: mixer bin numbers (hulk_audio.h: 0 FL, 1 FR, 2 C, 3 LFE, 4 BL, 5 BR, 10 reverb send).
// A mono track is sent to every listed bin; a stereo track sends its left channel to the even-numbered entries'
// bins and the right to the odd (the mixer's rule). Takes effect when the track's voice is made (the first
// unpause / wait): call before. Volume: 0..65536 (65536 = unity), applied to the voice.
void hulk_bink_set_mix_bins(HulkBink* b, unsigned track_id, const unsigned* bins, unsigned count);
void hulk_bink_set_volume(HulkBink* b, unsigned track_id, unsigned volume);

void hulk_bink_pause(HulkBink* b, int paused);
int hulk_bink_wait(HulkBink* b);                // 1: not yet time for the current frame (or paused)
int hulk_bink_do_frame(HulkBink* b);            // 0: the frame is decoded; 1: no frame (error / end)
// Copies a rectangle of the decoded frame (sx, sy, sw, sh) to (dx, dy) of a 32-bit B, G, R, A buffer: `dst` is the
// lowest address of a buffer `dest_height` rows high; a negative `pitch` flips the rows (the image's top row goes
// to the highest address, dst + (dest_height - 1) * -pitch), as the game's bottom-up locks want. Returns 1 when
// copied, 0 on failure.
int hulk_bink_copy_rect(HulkBink* b, void* dst, int pitch, unsigned dest_height, int dx, int dy, int sx, int sy,
                        int sw, int sh, unsigned flags);
void hulk_bink_next_frame(HulkBink* b);

// Zeroed memory for the callers that include no SDL headers (the xdk stand-ins: the game's I/O block).
void* hulk_bink_alloc(unsigned bytes);
void hulk_bink_free(void* p);

// The player's clock, milliseconds (the default: SDL's tick count). A test installs its own.
typedef unsigned long long (*HulkBinkClock)(void);
void hulk_bink_set_clock(HulkBinkClock clock);
unsigned hulk_bink_ticks(void);

// Frames of the movie audio that are decoded ahead (diagnostics): the first selected track's queue, in frames.
unsigned hulk_bink_audio_ahead(HulkBink* b);
// Milliseconds of movie time the player is at (the audio clock when sound plays, else the tick clock).
unsigned hulk_bink_time_ms(HulkBink* b);

#ifdef __cplusplus
}
#endif

#endif
