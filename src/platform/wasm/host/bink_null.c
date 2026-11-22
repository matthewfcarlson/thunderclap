/* Bink by address (the shapes: src/platform/sdl/xdk/movies_bink.cpp's notes, read off the game's call sites). No
 * decoder here: a movie opens through the game's own I/O callbacks (its header gives the size and the frame count),
 * keeps time on the virtual clock and "decodes" nothing, so the game's movie logic runs as with a picture (a replay's
 * no-fmv stops a movie the first time the FMV manager renders it, which needs it opened). The handle (width, height,
 * frames, frame number, then this file's words) lives in the arena: game state. */
#include "hulk_host.h"
#include "sim.h"

typedef struct {
    uint32_t width, height, frames, frame_num;   /* the words the game reads */
    uint32_t reserved[12];
    uint32_t block;                              /* the I/O block the game's open callback filled */
    uint32_t fps_num, fps_den, paused;
    uint64_t acc_ms, resume_ms;
} hbink;

static uint32_t open_cb;                        /* (BinkSetIO: a game function, set once at start-up) */
int ff_replay_active(void);     /* replay.cpp */
static uint64_t now_ms(void) { return SIM->clock / (HULK_TSC_HZ / 1000); }

FFG(00364da0) { UNUSED; open_cb = ARG(0); RET(1); }           /* BinkSetIO(open callback) */
FFG(00364dc0) { UNUSED; RET(1); }                            /* BinkSetSoundTrack */
FFG(00364fe0) {                                               /* BinkOpen(name, flags) -> handle, 0: failed */
    UNUSED;
    if (!open_cb) { RET(0); return; }
    uint32_t* block = ff_arena_alloc(512, 16);
    uint32_t state = (uint32_t)(uintptr_t)block;
    if (!ff_call(open_cb, 3, state, ARG(0), ARG(1))) { ff_arena_free(block); RET(0); return; }
    uint8_t* hdr = ff_arena_alloc(64, 16);
    uint32_t got = block[0] ? ff_call(block[0], 4, state, 0, (uint32_t)(uintptr_t)hdr, 44) : 0;
    uint32_t w = 0, h = 0, frames = 0, num = 0, den = 0;
    if (got == 44 && hdr[0] == 'B' && hdr[1] == 'I' && hdr[2] == 'K') {
        memcpy(&frames, hdr + 8, 4);
        memcpy(&w, hdr + 20, 4);
        memcpy(&h, hdr + 24, 4);
        memcpy(&num, hdr + 28, 4);
        memcpy(&den, hdr + 32, 4);
    }
    ff_arena_free(hdr);
    if (!frames || !num || !den) {
        if (block[5]) ff_call(block[5], 1, state);
        ff_arena_free(block);
        RET(0);
        return;
    }
    hbink* b = ff_arena_alloc(sizeof *b, 16);
    b->width = w, b->height = h, b->frames = frames, b->frame_num = 0;
    b->block = state, b->fps_num = num, b->fps_den = den, b->paused = 1;
    RET((uint32_t)(uintptr_t)b);
}
FFG(00367610) { UNUSED; RET(0); }                            /* BinkSetVolume */
FFG(00367660) { UNUSED; RET(0); }                            /* BinkSetMixBins */
FFG(00366b40) {                                               /* BinkPause(handle, paused) */
    UNUSED;
    hbink* b = PTR(ARG(0));
    uint32_t p = ARG(1) != 0;
    if (b && p != b->paused) {
        if (p) b->acc_ms += now_ms() - b->resume_ms;
        else b->resume_ms = now_ms();
        b->paused = p;
    }
    RET(0);
}
FFG(00366940) {                                               /* BinkWait(handle) -> non-zero: not yet time */
    UNUSED;
    hbink* b = PTR(ARG(0));
    if (!b || b->paused) { RET(1); return; }
    uint64_t t = b->acc_ms + now_ms() - b->resume_ms;
    uint64_t due = ((uint64_t)b->frame_num * 1000ull * b->fps_den + b->fps_num - 1) / b->fps_num;   /* (ms) */
    if (due > t && !ff_replay_active()) {
        /* no replay: the game spins on BinkWait until the frame is due, and the clock moves only a microsecond a
         * QueryPerformanceCounter: the wait takes the time it would on the console (the clock jumps to the due
         * frame), or a movie shows a frame per ~30,000 polls */
        SIM->clock += (due - t) * (HULK_TSC_HZ / 1000);
        t = due;
    }
    RET(due > t);
}
FFG(00367bc0) { UNUSED; RET(ARG(0) ? 0 : 1); }               /* BinkDoFrame -> 0: decoded */
FFG(00365f30) { UNUSED; RET(ARG(0) ? 1 : 0); }               /* BinkCopyToBufferRect: no picture */
FFG(003681d0) {                                               /* BinkNextFrame */
    UNUSED;
    hbink* b = PTR(ARG(0));
    if (b && b->frame_num + 1 < b->frames) b->frame_num++;
    RET(0);
}
FFG(00368530) {                                               /* BinkClose */
    UNUSED;
    hbink* b = PTR(ARG(0));
    if (b) {
        uint32_t* block = PTR(b->block);
        if (block[5]) ff_call(block[5], 1, b->block);
        ff_arena_free(block);
        ff_arena_free(b);
    }
    RET(0);
}
FFG(00368660) { UNUSED; RET((uint32_t)now_ms()); }           /* the millisecond tick */
FFG(0033eb70) { UNUSED; }                                    /* BinkSetMemory */
