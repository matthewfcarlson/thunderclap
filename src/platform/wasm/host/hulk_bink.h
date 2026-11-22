/* The Bink handle of bink_null.c (in the arena: game state). The game reads the first four words; `reserved` stays
 * zero except in the app with a renderer, where gfx/movie.c keeps the movie's identity there for the runner's decoder
 * (wmov1): MOV_MAGIC, the archive name's hash, the virtual clock at the open (two words), the sound tracks, and 1 in
 * MOV_W_SKIP once the player held B to skip it (D231). */
#ifndef HULK_WASM_BINK_H
#define HULK_WASM_BINK_H
#include <stdint.h>

typedef struct {
    uint32_t width, height, frames, frame_num;   /* the words the game reads */
    uint32_t reserved[12];
    uint32_t block;                              /* the I/O block the game's open callback filled */
    uint32_t fps_num, fps_den, paused;
    uint64_t acc_ms, resume_ms;
} hbink;

enum { MOV_MAGIC = 0x31564f4du /* "MOV1" */, MOV_W_MAGIC = 0, MOV_W_HASH, MOV_W_STAMP_LO, MOV_W_STAMP_HI,
       MOV_W_NTRACKS, MOV_W_TRACK0, MOV_MAX_TRACKS = 6, MOV_W_SKIP = 11 };

#endif
