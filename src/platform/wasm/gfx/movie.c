/* The app's movies, the module's half (wmov1; docs/wasm-port.md "The macOS app"). bink_null.c stays the one model of
 * what the game reads from Bink (the handle's words, BinkWait on the virtual clock, frame numbers: a function of the
 * game's calls alone); these hooks only observe its calls and hand them to the runner (run/app/movie.c: `hulk` imports
 * mov_*), which decodes the movie with FFmpeg's Bink decoder (src/platform/sdl/movies/movie.c, FFmpeg loaded at run
 * time) and writes the picture into the game's own lock (BinkCopyToBufferRect: the frame the handle's frame number
 * names) and plays the sound tracks through the app's mixer (streaming voices clocked by the same 48 kHz of game time
 * as the DirectSound model's: D222). Nothing flows back.
 *
 * Game state: the movie's identity (the archive name's hash, the virtual clock at the open, the sound tracks) is in the
 * handle's reserved words, and the live handles in g_live (the tree's snapshotted section), so after a restore
 * (ff_movie_restored) the runner drops what the restored state doesn't hold and re-seeks the rest lazily: the picture
 * by frame number at the next copy, the sound to the movie's time. On only with a renderer outside replays (as the
 * audio: HULK_MOVIES=0 or HULK_GFX_RENDERER=null|noop turns it off, and with it every write of these hooks), so the
 * app run headless and the headless build run the same model. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "../host/hulk_bink.h"

#define GI(name) __attribute__((import_module("hulk"), import_name(#name)))
GI(mov_open) void gm_open(uint32_t h, const char* name);
GI(mov_close) void gm_close(uint32_t h);
GI(mov_pause) void gm_pause(uint32_t h, uint32_t paused, uint32_t time_ms);
GI(mov_copy) void gm_copy(uint32_t h, const uint32_t* args11);
GI(mov_mix) void gm_mix(uint32_t h, uint32_t fn, const uint32_t* args4);
GI(mov_wait) void gm_wait(uint32_t h, uint32_t due_ms);
GI(mov_ring) void gm_ring(uint32_t h, uint32_t permille);
GI(mov_resync) void gm_resync(uint32_t phase, uint32_t h, uint32_t time_ms);

#define GAME_STATE __attribute__((section("hulk_game_state")))
#define MAX_LIVE 16
static uint32_t g_live[MAX_LIVE] GAME_STATE;             /* the open handles (0: a free slot) */
static uint32_t g_tracks[1 + MOV_MAX_TRACKS] GAME_STATE; /* BinkSetSoundTrack: the count, then the ids */
/* hold to skip (D231): the virtual clock when B went down during a movie (0: up; ~0: held since before the movie
 * opened, so it counts only after a release) */
static uint64_t g_hold_since GAME_STATE;

int hulk_wasm_gfx_on(void);
int ff_replay_active(void);

static int movies_on(void) {
    static int on = -1;
    if (on < 0) {
        const char* r = getenv("HULK_GFX_RENDERER");
        const char* e = getenv("HULK_MOVIES");
        on = hulk_wasm_gfx_on() && !ff_replay_active() && !(r && !strcmp(r, "noop")) && !(e && *e == '0');
    }
    return on;
}
static uint32_t H(hbink* b) { return (uint32_t)(uintptr_t)b; }
static int ours(hbink* b) { return b && b->reserved[MOV_W_MAGIC] == MOV_MAGIC; }

/* the movie's time (ms), as bink_null.c's BinkWait reckons it */
static uint32_t time_ms(const hbink* b) {
    uint64_t now = SIM->clock / (HULK_TSC_HZ / 1000);
    return (uint32_t)(b->acc_ms + (b->paused ? 0 : now - b->resume_ms));
}

/* pad 0's B (XINPUT_GAMEPAD: the buttons word, then the analog buttons A, B, ...; the keyboard's F): as the game reads
 * it this frame (the sim block's pads: the frame's input, recorded and replayed with it) */
static int b_down(void) { return SIM->pads[0][3] > 30; }

/* the archive's name hash (docs/formats/rcf.md: the game's FUN_002673d0) */
static uint32_t rcf_hash(const char* s) {
    uint32_t h = 0;
    for (; *s; s++) {
        int c = (signed char)*s;
        if (c < 'a') c += 0x20;
        h = h * 31 + (uint32_t)c;
    }
    return h;
}

void ff_movie_tracks(uint32_t count, uint32_t ids) {
    if (!movies_on()) return;
    if (!ids) count = 0;
    if (count > MOV_MAX_TRACKS) count = MOV_MAX_TRACKS;
    g_tracks[0] = count;
    for (uint32_t i = 0; i < count; i++) g_tracks[1 + i] = ((const uint32_t*)PTR(ids))[i];
}

void ff_movie_open(hbink* b, uint32_t name) {
    if (!movies_on() || !name) return;
    uint32_t slot = MAX_LIVE;
    for (uint32_t i = 0; i < MAX_LIVE; i++)
        if (!g_live[i]) { slot = i; break; }
    if (slot == MAX_LIVE) return;                       /* (more than 16 open movies: this one plays black) */
    const char* n = PTR(name);
    b->reserved[MOV_W_MAGIC] = MOV_MAGIC;
    b->reserved[MOV_W_HASH] = rcf_hash(n);
    b->reserved[MOV_W_STAMP_LO] = (uint32_t)SIM->clock;
    b->reserved[MOV_W_STAMP_HI] = (uint32_t)(SIM->clock >> 32);
    b->reserved[MOV_W_NTRACKS] = g_tracks[0];
    for (uint32_t i = 0; i < g_tracks[0]; i++) b->reserved[MOV_W_TRACK0 + i] = g_tracks[1 + i];
    g_live[slot] = H(b);
    g_hold_since = b_down() ? ~0ull : 0;
    gm_open(H(b), n);
}

void ff_movie_pause(hbink* b) {
    if (ours(b)) gm_pause(H(b), b->paused, time_ms(b));
}

/* 1: the frame counts as copied (the game then renders and presents it), whether or not the runner had a picture:
 * what the game does never depends on the decoder */
int ff_movie_copy(hbink* b, const uint32_t* a) {
    if (!ours(b)) return 0;
    gm_copy(H(b), a);
    return 1;
}

/* BinkWait moves the virtual clock on to a frame that isn't due yet (bink_null.c); in free play the runner waits in
 * real time until the frame is due on the movie's own wall clock (anchored at its start), so the movie and its sound
 * (on the game's clock) keep to real time. Output only: the game's clock is the virtual one either way. */
void ff_movie_wait(hbink* b, uint64_t due_ms) {
    if (ours(b)) gm_wait(H(b), (uint32_t)due_ms);
}

/* Hold B for a second to skip any movie (D231; the console lets only some be skipped). Called by BinkWait while the
 * movie plays: the hold is timed on the virtual clock from the frame's pad state, both game state, so a replayed or
 * re-simulated run skips at the same point. The skip goes through the game's own end of a movie: the handle's frame
 * number becomes the last one and the movie's clock its due time, so the next BinkWait / DoFrame / copy and the
 * player's end test (0x333de0: frame number == frames - 1) close the movie as if it had played out. The runner draws
 * the ring (mov_ring: thousandths held). */
#define HOLD_MS 1000u
void ff_movie_poll(hbink* b) {
    if (!ours(b)) return;
    if (!b_down()) {
        if (g_hold_since) gm_ring(H(b), 0);
        g_hold_since = 0;
        return;
    }
    if (g_hold_since == ~0ull || b->reserved[MOV_W_SKIP]) return;
    if (!g_hold_since) g_hold_since = SIM->clock ? SIM->clock : 1;
    uint64_t held = (SIM->clock - g_hold_since) / (HULK_TSC_HZ / 1000);
    gm_ring(H(b), held >= HOLD_MS ? 1000 : (uint32_t)(held * 1000 / HOLD_MS) + 1);
    if (held < HOLD_MS || b->frames < 1) return;
    b->reserved[MOV_W_SKIP] = 1;
    b->frame_num = b->frames - 1;
    uint64_t t = time_ms(b);
    uint64_t due = ((uint64_t)b->frame_num * 1000ull * b->fps_den + b->fps_num - 1) / b->fps_num;
    if (due > t) b->acc_ms += due - t;
    g_hold_since = ~0ull;                   /* (the next movie counts from a new press) */
    gm_ring(H(b), 0);
}

void ff_movie_mix(hbink* b, uint32_t fn, const uint32_t* a) {
    if (ours(b)) gm_mix(H(b), fn, a);
}

void ff_movie_close(hbink* b) {
    if (!ours(b)) return;
    for (uint32_t i = 0; i < MAX_LIVE; i++)
        if (g_live[i] == H(b)) g_live[i] = 0;
    gm_close(H(b));
}

/* a snapshot was put back (sched.c): 0 begins, 1 names each live movie with its time, 2 ends (the runner's movies the
 * restored state doesn't name are closed) */
void ff_movie_restored(void) {
    if (!movies_on()) return;
    gm_resync(0, 0, 0);
    for (uint32_t i = 0; i < MAX_LIVE; i++) {
        hbink* b = PTR(g_live[i]);
        if (ours(b)) gm_resync(1, g_live[i], time_ms(b));
    }
    gm_resync(2, 0, 0);
}
