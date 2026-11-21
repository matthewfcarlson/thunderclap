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
extern unsigned char DAT_004dd700[];   // the world pointer (pointer-sized on 64-bit)
// the particle generators (pure3d; the Wine build's hulk_prng_bytes reads the same six items)
extern unsigned char DAT_00554be4[], DAT_00554bec[], DAT_00554bf0[], DAT_00554bf8[], DAT_00554bfc[], DAT_00554c04[];
// the game's functions, through the link's thunks to the tree's definitions (native_bind.py)
void hulk_orig_00086450(void* clock);           // GameClock::Update
void hulk_orig_00269170(void* system);          // core::ControllerSystemXBox::vfunc_12, the pad poll
unsigned hulk_orig_00267f80(void);              // core::GetMilliseconds (the poll's own time)
void hulk_orig_001b7310(void* fmv, const char* name, unsigned param, unsigned flag);   // CFMVManager::QueueMovie
void hulk_orig_001b7d10(void* fmv, void* pads, void* voices);                          // the FMV render
void hulk_orig_001b7970(void* fmv);             // the FMV manager's stop
void hulk_orig_00333ef0(void);                  // the movie player's finish
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

extern "C" hulk_u32 hulk_native_frame_no;   // (shim_posix.cpp: the frame number xdk/snapshot.cpp reads)
static hulk_u32 g_snd_calls;   // sound-rng draws served from the private state (the Wine build's "sound rng" count)
static hulk_u32 g_snd_rng[4] = {0x2F6B6F2Au, 0x1F123BB5u, 0, 0};   // hybrid/hooks.cpp: the sound code's own states
static hulk_u32 g_snd_rand = 0x5EEDu;

static void prng_bytes(unsigned char* b) {    // (replay_hooks.cpp hulk_prng_bytes)
    memcpy(b, DAT_00554be4, 8);
    memcpy(b + 8, DAT_00554bec, 4);
    memcpy(b + 12, DAT_00554bf0, 8);
    memcpy(b + 20, DAT_00554bf8, 4);
    memcpy(b + 24, DAT_00554bfc, 8);
    memcpy(b + 32, DAT_00554c04, 8);
}

// ckpt1 (docs/checkpoints.md) natively (render1, D187): HULK_CKREF=1 writes the semantic probe's records to
// HULK_TRACE_FILE + ".ckref" in replay_hooks.cpp's format (tools/ckpt_ref.py reads both). The probe is the same source;
// on 64-bit it reads the world's and the scenario manager's words at their native offsets (flow, mission), reports the
// actor tags (hulk, actors: CCharacter's words, which the game's own views still read at 32-bit pads) unavailable, and
// hashes clock, rng, camera, sound and particle as the Wine build does.
// (render1) the native offsets of the world's and the scenario manager's words the flow and mission tags read
// (ckpt_probe.cpp HULK_PROBE_LAYOUT64): decls/managers.h HulkWorld parts[7] / parts[10], gen CScenarioManager
// f_0c / f_1194 / f_1198 / f_119c. tools/native_replay.py layout checks them against those headers with the native
// front end (the native link runs it).
// #define HULK_PROBE_LAYOUT64 1   (render1: off: the World words natively crash the probe)
#include "../ckpt/ckpt_probe.cpp"
#ifdef HULK_PROBE_LAYOUT64
extern "C" const HulkProbeLayout64 hulk_probe_layout64 = {0x40, 0x58, 0x10, 0x1198, 0x119c, 0x11a0};
#endif
static void ckref_dump(void*, int tag, const char* name, unsigned index, unsigned bits, int is_float) {
    log_line("ckdump f=%u t=%d %s[%u] %08x%s", hulk_native_frame_no - 1, tag, name, index, bits, is_float ? " f" : "");
}
static int frame_range(const char* v, hulk_u32* from, hulk_u32* to) {
    if (!v || !*v)
        return 0;
    char* e;
    *from = *to = (hulk_u32)strtoul(v, &e, 10);
    if (*e == '-')
        *to = (hulk_u32)strtoul(e + 1, 0, 10);
    return 1;
}
static void ckref_frame(hulk_u32 fno, const HulkCkptState* st, const unsigned char* pb) {
    static int on = -1;
    static FILE* f;
    static int dump_on;
    static hulk_u32 dump_from, dump_to;
    if (on < 0) {
        on = env_flag("HULK_CKREF");
        if (on) {
            const char* tp = getenv("HULK_TRACE_FILE");
            char path[600];
            snprintf(path, sizeof(path), "%s.ckref", tp && *tp ? tp : "hulk-startup-trace.txt");
            f = fopen(path, "wb");
            hulk_u32 hdr[3] = {0x524b4348u /* "HCKR" */, 1, HULK_PROBE_VERSION};
            if (f)
                fwrite(hdr, 4, 3, f);
            dump_on = frame_range(getenv("HULK_CKREF_DUMP"), &dump_from, &dump_to);
        }
    }
    if (!on || !f)
        return;
    HulkProbeInputs in;
    memset(&in, 0, sizeof(in));
    in.rng = st->rng;
    in.boot_step = st->boot_step;
    in.view_ptr = (const void* const*)DAT_004e231c;   // (the probe reads the view at +0x4c: the same on both builds)
    in.clock = st->clock;                              // (the 32-bit image of the clock block: hulk_nreplay_ckpt_image)
    in.clock_at_entry = st->clock_at_entry;
    in.prng = pb;
    in.snd_rng = g_snd_rng;
    in.snd_rand = &g_snd_rand;
    in.world_ptr = (const void* const*)DAT_004dd700;
    unsigned mask = HULK_PROBE_CHEAP_MASK | (fno % HULK_PROBE_FULL_EVERY == 0 ? HULK_PROBE_FULL_MASK : 0);
    HulkProbeRecord rec;
    int dumping = dump_on && fno >= dump_from && fno <= dump_to;
    hulk_probe_frame(fno, &in, mask, &rec, dumping ? ckref_dump : 0, 0);
    rec.mask |= 1u << HULK_PT_LEGACY;
    rec.exact[HULK_PT_LEGACY] = rec.quant[HULK_PT_LEGACY] = hulk_ckpt_hash(fno, st);
    hulk_u32 out[3 + 2 * HULK_PT_COUNT];
    hulk_u32 n = 0;
    out[n++] = rec.frame;
    out[n++] = rec.mask;
    out[n++] = rec.unavailable;
    for (int t = 0; t < HULK_PT_COUNT; t++)
        if (rec.mask & (1u << t)) {
            out[n++] = rec.exact[t];
            out[n++] = rec.quant[t];
        }
    fwrite(out, 4, n, f);
    if (fno % 300 == 0)
        fflush(f);
}

// One frame: the checkpoint (when this frame is one) and its trace lines, as replay_hooks.cpp's hulk_native_frame.
extern "C" hulk_u32 hulk_native_frame_no;   // (shim_posix.cpp: the frame number xdk/snapshot.cpp reads)
extern "C" void hulk_nreplay_frame(const void* clock) {
    hulk_native_frame_no++;                  // (x64t19) as replay_hooks.cpp's hulk_native_frame, at the frame's start
    HulkCkptImage img;
    HulkCkptState st;
    const void* view = *(const void* const*)DAT_004e231c;
    hulk_nreplay_ckpt_image(DAT_004e5ad0, DAT_0049fb40, view, clock, &img, &st);
    unsigned char pb[HULK_PRNG_BYTES];
    prng_bytes(pb);
    ckref_frame(hulk_native_frame_no - 1, &st, pb);
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
// The hooks that read a game object (native_hooks.h `entry` rows; render1, D187/D192). Each reads the words the
// hooked function's own 64-bit code reads (offsets from its native object; tests/native_host checks them).
//
// C (pad poll, 0x00269170 core::ControllerSystemXBox::vfunc_12; replay_hooks.cpp hulk_hook_pad_poll): with a
// recording open the poll's rate limit goes: the last poll time is set to `now - interval`. records.h's
// CoreControllerSystemXBox interval / lastPoll (32-bit +0x12a0 / +0x12a4; natively +0x1c70 / +0x1c74: four
// 0x710-byte controllers from +0x30).
struct HulkPadPollLayout64 {
    unsigned interval, last_poll;
};
static const HulkPadPollLayout64 kPadPoll = {0x1c70, 0x1c74};

extern "C" void hulk_nhook_pad_poll(void* system) {
    if (system && replay_open(0)) {
        unsigned char* p = (unsigned char*)system;
        hulk_u32 interval;
        memcpy(&interval, p + kPadPoll.interval, 4);
        hulk_u32 last = hulk_orig_00267f80() - interval;
        memcpy(p + kPadPoll.last_poll, &last, 4);
    }
    hulk_orig_00269170(system);
}

// F no-fmv (tweak bit 1): CFMVManager::QueueMovie 0x001b7310 queues nothing; the FMV render 0x001b7d10, when it has
// a movie and is not paused, takes its "status 0: finished" path (0x00333ef0, then the stop 0x001b7970). The words
// are those 0x001b7d10's native code tests (its Player_1b7d10 view on CFMVManager: vftable, deadline, the paused byte
// at +0xc, the movie at +0x10; decls/managers.h HulkFMVManager f08 / f0c).
struct HulkFmvLayout64 {
    unsigned movie, paused;
};
static const HulkFmvLayout64 kFmv = {0x10, 0xc};

static int no_fmv(void) {
    HulkReplayInfo ri;
    return replay_open(&ri) && (ri.tweaks & 2);
}

// (the flag is a byte the MS ABI caller does not widen: passed on as the register it came in)
extern "C" void hulk_nhook_fmv_queue(void* fmv, const char* name, unsigned param, unsigned flag) {
    if (no_fmv())
        return;
    hulk_orig_001b7310(fmv, name, param, flag);
}

extern "C" void hulk_nhook_fmv_render(void* fmv, void* pads, void* voices) {
    if (fmv && no_fmv()) {
        const unsigned char* p = (const unsigned char*)fmv;
        void* movie;
        memcpy(&movie, p + kFmv.movie, sizeof(movie));
        if (movie && !p[kFmv.paused]) {
            hulk_orig_00333ef0();
            hulk_orig_001b7970(fmv);
            return;
        }
    }
    hulk_orig_001b7d10(fmv, pads, voices);
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
