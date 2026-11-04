// The replay driver of the native builds (docs/native-android.md section 14, A2): what the Wine build's bridge
// src/platform/sdl/xdk/replay_hooks.cpp does, for the 64-bit images (arm64 macOS first; the ELF targets compile the
// same file). Host side (system headers, the host's ABI), C linkage; the link puts these functions between the game's
// (src/platform/sdl/host/native_hooks.h, tools/native_bind.py). Not part of the Wine build.
//
//   * the per-frame checkpoint: hulk_nhook_clock_update is GameClock::Update's entry hook; it hashes the frame
//     (hulk_ckpt_update, src/platform/sdl/replay/hulk_replay.cpp: the same FNV-1a over the same 76 bytes as the Wine
//     build and the hybrid recordings), then calls the update. The hashed regions are read from the 64-bit objects
//     and laid out as the 32-bit image the recordings hash (hulk_nreplay_ckpt_image), so a checkpoint is comparable
//     with the Wine build's and the Xbox's;
//   * the trace lines of replay_hooks.cpp ("ckpt frame %u hash %08x recording ... ok|DIVERGED", the regions of the
//     first checkpoint and of the first divergence), through entry_posix.cpp's hulk_native_log, so the tools that
//     read the Wine build's checkpoints read these;
//   * the replay's start-up (after the initializers, before main: entry_posix.cpp calls hulk_replay_startup): the
//     recording opened, skip-intro (g_BootSequenceStep 6), seq-rng's pointer;
//   * the hooks that need no game object layout: the new-game seed, sound-rng, seq-rng (native_hooks.h `ready` rows).
// The syncio interface the shim's threads.cpp calls is shim_posix.cpp's (no lockstep I/O on the native builds yet).
//
// The game's data the checkpoint reads is named by XBE address (the data TUs' names, as replay_hooks.cpp): the
// gameplay RNG 0x4e5ad0 (two 32-bit words), g_BootSequenceStep 0x49fb40 (32-bit), the logic-view singleton pointer
// 0x4e231c (pointer-sized on 64-bit) and the RNG pointer 0x4e5acc (pointer-sized).
#if !defined(_WIN32)
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../replay/hulk_replay.h"
#include "native_hooks.h"

typedef unsigned int hulk_u32;

extern "C" {
// the game's data (named by XBE address)
extern unsigned char DAT_004e5ad0[];   // the gameplay RNG's two MWC words
extern unsigned char DAT_0049fb40[];   // g_BootSequenceStep
extern unsigned char DAT_004e231c[];   // the logic view singleton pointer (camera position at +0x4c)
extern unsigned char DAT_004e5acc[];   // the game's pointer to its RNG state
// the game's functions, through the link's thunks to the tree's definitions (native_bind.py)
void hulk_orig_00086450(void* clock);           // GameClock::Update
void* hulk_orig_000964d0(void);                 // the gameplay RNG accessor
int hulk_orig_000113e0(int lo, int hi);         // RandInt
unsigned long long hulk_orig_00267f00(void);    // core::GetMicroseconds (the seed's source)
int hulk_ncrt_rand(void);                       // the game's rand() (crt_posix.cpp)
void hulk_native_log(const char* line);         // entry_posix.cpp: a trace line

}

// ---------------------------------------------------------------------------------------------------------------
// The checkpoint's input in the 32-bit layout (hulk_replay.h HulkCkptState): the fields' offsets in the 64-bit objects.
// The logic view (0x001c34c0's class: seven ints, 0x40 bytes, four floats; no pointer before +0x5c) and the GameClock
// (0x00086450's Timer: eight 64-bit fields from +0, no vfptr) have the same offsets on both builds; a class that gains
// a pointer before these fields changes them here, and tests/native_host/replay_native_test.py checks them against
// the real GameClock::Update.
struct HulkCkptLayout64 {
    unsigned camera_pos;      // the logic view's position: 12 bytes (32-bit +0x4c)
    unsigned clock_block;     // the GameClock's total..rate: 48 bytes (32-bit +0x10)
};
static const HulkCkptLayout64 kLayout = {0x4c, 0x10};

struct HulkCkptImage {
    unsigned char camera[0x4c + 12];   // the hashed 12 bytes at +0x4c (the rest unused)
    unsigned char clock[0x10 + 0x30];  // the hashed 48 bytes at +0x10
    const void* camera_ptr;            // &camera, or null while the singleton does not exist
};

// The 32-bit image of the checkpoint's regions from the 64-bit state: `rng` 8 bytes, `boot` 4 bytes, `*view` the logic
// view (or null), `clock` the GameClock. The result's HulkCkptState is what hulk_ckpt_hash / hulk_ckpt_update read.
extern "C" void hulk_nreplay_ckpt_image(const void* rng, const void* boot, const void* view, const void* clock,
                                        HulkCkptImage* img, HulkCkptState* st) {
    memset(img, 0, sizeof(*img));
    if (view) {
        memcpy(img->camera + 0x4c, (const unsigned char*)view + kLayout.camera_pos, 12);
        img->camera_ptr = img->camera;
    }
    if (clock)
        memcpy(img->clock + 0x10, (const unsigned char*)clock + kLayout.clock_block, 0x30);
    st->rng = rng;
    st->boot_step = boot;
    st->camera_ptr = &img->camera_ptr;
    st->clock = clock ? img->clock : 0;
    st->clock_at_entry = 1;
}

static int env_flag(const char* name) {
    const char* v = getenv(name);
    return v && *v == '1';
}

static void log_line(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void log_line(const char* fmt, ...) {
    char line[256];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    hulk_native_log(line);
}

static hulk_u32 g_snd_calls;   // sound-rng draws served from the private state (the Wine build's "sound rng" count)

// One frame: the checkpoint (when this frame is one) and its trace lines, as replay_hooks.cpp's hulk_native_frame.
extern "C" void hulk_nreplay_frame(const void* clock) {
    HulkCkptImage img;
    HulkCkptState st;
    const void* view = *(const void* const*)DAT_004e231c;
    hulk_nreplay_ckpt_image(DAT_004e5ad0, DAT_0049fb40, view, clock, &img, &st);
    int r = hulk_ckpt_update(&st);
    if (r < 0)
        return;
    static unsigned logged, bad;
    static int all = -1, regions = -1;
    if (all < 0) {
        all = env_flag("HULK_CKPT_ALL");
        regions = env_flag("HULK_CKPT_REGIONS");
    }
    HulkCkptStats s;
    hulk_ckpt_stats(&s);
    if (!(all || logged < 64 || (r == 0 && bad < 16) || (s.frame - 1) % 1500 == 0))
        return;
    int first_bad = r == 0 && bad++ == 0;
    unsigned want = 0;
    int have = hulk_replay_expected_hash(s.frame - 1, &want);
    log_line("ckpt frame %u hash %08x recording %s%08x %s (io posts %u waits %u timeouts %u, sound rng %u)", s.frame - 1,
             s.last_hash, have ? "" : "(none) ", want, r ? "ok" : "DIVERGED", 0u, 0u, 0u, g_snd_calls);
    if (logged == 0 || first_bad || regions) {
        const hulk_u32* g = (const hulk_u32*)DAT_004e5ad0;
        hulk_u32 boot;
        memcpy(&boot, DAT_0049fb40, 4);
        log_line("ckpt regions: rng %08x %08x boot %u camera %p", g[0], g[1], boot, view);
        if (view) {
            const hulk_u32* p = (const hulk_u32*)(img.camera + 0x4c);
            log_line("ckpt camera+0x4c: %08x %08x %08x", p[0], p[1], p[2]);
        }
        if (clock) {
            const hulk_u32* c = (const hulk_u32*)(img.clock + 0x10);
            log_line("ckpt clock+0x10: %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x", c[0], c[1], c[2],
                     c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11]);
        }
    }
    logged++;
}

// GameClock::Update's entry hook (native_hooks.h): the checkpoint sees the state before the update, as the Wine
// build's clock wrapper and the hybrid's hash in the middle of Update (step and scaled step zeroed: clock_at_entry)
extern "C" void hulk_nhook_clock_update(void* clock) {
    hulk_nreplay_frame(clock);
    hulk_orig_00086450(clock);
}

// ---------------------------------------------------------------------------------------------------------------
// The recording and its tweaks (replay_hooks.cpp hulk_replay_startup)
#define HULK_RF_SOUND_RNG 512u
#define HULK_RF_SEQ_RNG (1u << 13)

static int replay_open(HulkReplayInfo* ri) {
    static int known = -1;
    static HulkReplayInfo info;
    if (known < 0)
        known = hulk_replay_info(&info) ? 1 : 0;
    if (ri)
        *ri = info;
    return known;
}

static hulk_u32 g_snd_rng[4] = {0x2F6B6F2Au, 0x1F123BB5u, 0, 0};   // hybrid/hooks.cpp: the sound code's own states
static hulk_u32 g_snd_rand = 0x5EEDu;
// seq-rng: the audio sequencer's reads of the RNG pointer (native_hooks.h `data` rows) read this instead: the game's
// pointer, or the sound code's state with a recording whose flags include seq-rng
extern "C" { void* hulk_seq_rng_ptr; }

extern "C" void hulk_replay_startup(void) {
    if (!hulk_seq_rng_ptr)
        hulk_seq_rng_ptr = *(void* const*)DAT_004e5acc;
    const char* src = getenv("HULK_INPUT_SOURCE");
    if (!src || src[0] != 'r')
        return;
    hulk_input_init();
    HulkReplayInfo ri;
    if (!replay_open(&ri))
        return;
    if (ri.tweaks & 1) {
        hulk_u32 six = 6;
        memcpy(DAT_0049fb40, &six, 4);
    }
    if (ri.flags & HULK_RF_SEQ_RNG)
        hulk_seq_rng_ptr = g_snd_rng;
    log_line("replay: flags 0x%x tweaks 0x%x seed 0x%x, %u entries, %u checkpoints", ri.flags, ri.tweaks, ri.seed,
             ri.entries, ri.checkpoints);
}

// ---------------------------------------------------------------------------------------------------------------
// The hooks without a game object layout (native_hooks.h `ready` site rows; replay_hooks.cpp's request E and G)
extern "C" unsigned long long hulk_replay_seed(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri))
        return ri.seed;
    return hulk_orig_00267f00();
}

extern "C" void* hulk_sound_rng(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & HULK_RF_SOUND_RNG)) {
        g_snd_calls++;
        return g_snd_rng;
    }
    return hulk_orig_000964d0();
}

extern "C" int hulk_sound_rand(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & HULK_RF_SOUND_RNG)) {
        g_snd_rand = g_snd_rand * 214013u + 2531011u;
        return (int)((g_snd_rand >> 16) & 0x7fffu);
    }
    return hulk_ncrt_rand();
}

extern "C" int hulk_seq_randint(int lo, int hi) {
    HulkReplayInfo ri;
    if (!(replay_open(&ri) && (ri.flags & HULK_RF_SEQ_RNG)))
        return hulk_orig_000113e0(lo, hi);
    hulk_u32* st = g_snd_rng;
    st[0] = 36969u * (st[0] & 0xFFFFu) + (st[0] >> 16);
    st[1] = 18000u * (st[1] & 0xFFFFu) + (st[1] >> 16);
    hulk_u32 r = (st[0] << 16) + (st[1] & 0xFFFFu);
    return (int)(r % (hulk_u32)(hi - lo + 1) + (hulk_u32)lo);
}

#endif
