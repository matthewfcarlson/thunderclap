// Replay hooks of the native image (docs/native-replay.md; build/rp1/for-native9.md B): the per-frame checkpoint.
// tools/native_link.py --gfx wraps GameClock::Update 0x00086450 (`_hulk_clock_update`): before the draw log's frame
// tick it calls hulk_native_frame with the clock (Update's `this`). The hashed regions are the image's own data
// items, named by their XBE addresses (bound by address like the tree's names): the gameplay RNG 0x4e5ad0,
// g_BootSequenceStep 0x49fb40, the camera singleton pointer 0x4e231c. Native builds only.
#include "imports.h"
#include "../crt/host_crt.h"

#if defined(HULK_NATIVE_SDL)
#include "../replay/hulk_replay.h"
#define HULK_RF_SEQ_RNG (1u << 13)          // the .hrp's seq-rng bit (tools/replay_pack.py HF)

extern "C" char DAT_004e5ad0[];         // the gameplay RNG's two MWC words
extern "C" char DAT_0049fb40[];         // g_BootSequenceStep
extern "C" char DAT_004e231c[];         // the camera singleton pointer
extern "C" void HULK_CDECL hulk_native_log(const char* line);

static hulk_u32 hulk_io_posts, hulk_io_waits, hulk_io_timeouts, hulk_snd_calls;
extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    HulkCkptState st;
    st.rng = DAT_004e5ad0;
    st.boot_step = DAT_0049fb40;
    st.camera_ptr = (const void* const*)DAT_004e231c;
    st.clock = clock;
    st.clock_at_entry = 1;
    int r = hulk_ckpt_update(&st);
    static unsigned logged, bad;
    HulkCkptStats s;
    if (r >= 0)
        hulk_ckpt_stats(&s);
    // the first 64 checkpoints in the trace too (HULK_CKPT; SDL_Log has them all), then the first 16 divergences and
    // every 50th checkpoint
    if (r >= 0 && (logged < 64 || (r == 0 && bad < 16) || (s.frame - 1) % 1500 == 0)) {
        int first_bad = r == 0 && bad++ == 0;
        unsigned want = 0;
        int have = hulk_replay_expected_hash(s.frame - 1, &want);
        char line[160];
        hulk_host__snprintf(line, sizeof(line), "ckpt frame %u hash %08x recording %s%08x %s (io posts %u waits %u timeouts %u, sound rng %u)",
                     s.frame - 1, s.last_hash, have ? "" : "(none) ", want, r ? "ok" : "DIVERGED", hulk_io_posts, hulk_io_waits,
                     hulk_io_timeouts, hulk_snd_calls);
        hulk_native_log(line);
        if (logged == 0 || first_bad) {   // the inputs of the first checkpoint and of the first divergence
            const hulk_u32* r = (const hulk_u32*)st.rng;
            const hulk_u32* c = (const hulk_u32*)((const char*)clock + 0x10);
            const void* cam = *st.camera_ptr;
            hulk_host__snprintf(line, sizeof(line), "ckpt regions: rng %08x %08x boot %u camera %08x",
                                r[0], r[1], *(const hulk_u32*)st.boot_step, (hulk_u32)(__SIZE_TYPE__)cam);
            hulk_native_log(line);
            if (cam) {
                const hulk_u32* p = (const hulk_u32*)((const char*)cam + 0x4c);
                hulk_host__snprintf(line, sizeof(line), "ckpt camera+0x4c: %08x %08x %08x", p[0], p[1], p[2]);
                hulk_native_log(line);
            }
            hulk_host__snprintf(line, sizeof(line), "ckpt clock+0x10: %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x",
                                c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11]);
            hulk_native_log(line);
        }
        logged++;
    }
}

static int replay_open(HulkReplayInfo* ri) {
    static int known = -1;
    static HulkReplayInfo info;
    if (known < 0)
        known = hulk_replay_info(&info) ? 1 : 0;
    if (ri)
        *ri = info;
    return known;
}

// After the C++ initializers, before main (startup.cpp): with HULK_INPUT_SOURCE=replay:<file> the recording is
// opened now (hulk_input_init is idempotent; XInitDevices calls it again) and its tweaks applied as the hybrid
// build's load-time patches did: skip-intro (bit 0) = g_BootSequenceStep 6.
extern "C" char DAT_004e5acc[];         // the game's pointer to its RNG state (0x4e5ad0)
static hulk_u32 hulk_main_tid;
static hulk_u32 hulk_snd_rng[4] = {0x2F6B6F2Au, 0x1F123BB5u, 0, 0};    // hybrid/hooks.cpp / patch_xbe.py: the
static hulk_u32 hulk_snd_rand = 0x5EEDu;                               // sound code's own initial states
// seq-rng: the audio sequencer's `mov ecx, [0x4e5acc]` sites read this pointer instead (tools/native_link.py
// SITE_REBIND, data): the game's state, or the sound code's with a recording whose flags include seq-rng
extern "C" { hulk_u32 hulk_seq_rng_ptr; }
static void startup_common(void);

extern "C" void HULK_CDECL hulk_replay_startup(void) {
    startup_common();
    const char* src = hulk_host_getenv("HULK_INPUT_SOURCE");
    if (!src || src[0] != 'r')
        return;
    hulk_input_init();
    HulkReplayInfo ri;
    if (!replay_open(&ri))
        return;
    if (ri.tweaks & 1)
        *(hulk_u32*)DAT_0049fb40 = 6;
    if (ri.flags & HULK_RF_SEQ_RNG)
        hulk_seq_rng_ptr = (hulk_u32)(__SIZE_TYPE__)hulk_snd_rng;
    char line[160];
    hulk_host__snprintf(line, sizeof(line), "replay: flags 0x%x tweaks 0x%x seed 0x%x, %u entries, %u checkpoints",
                        ri.flags, ri.tweaks, ri.seed, ri.entries, ri.checkpoints);
    hulk_native_log(line);
}

// ControllerSystemXBox::vfunc_12 0x00269170 entry (tools/native_link.py ENTRY_HOOKS; request C): with a recording
// open the poll's rate limit goes (the hybrid build nops its `jb`): the last poll time at +0x12a4 is set to
// `now - interval` (+0x12a0), so `now - last >= interval` holds; `now` is core::GetMilliseconds 0x00267f80, the
// function's own read (the virtual clock stands still between updates; real time only moves forward). The
// interval itself stays (ControllerXBox::vfunc_20 divides by it). regs: eax, ecx (`this`), edx, the return
// address, the arguments.
extern "C" unsigned HULK_CDECL FUN_00267f80();
extern "C" int HULK_CDECL hulk_hook_pad_poll(hulk_u32* regs) {
    if (replay_open(0) && regs[1])
        *(hulk_u32*)(regs[1] + 0x12a4) = FUN_00267f80() - *(hulk_u32*)(regs[1] + 0x12a0);
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------
// G: sound RNG isolation (docs/native-replay.md items 6 and 7; hybrid/hooks.cpp hybrid_sound_rng, hybrid_sound_rand,
// hybrid_seq_randint; tools/patch_xbe.py HOOK_CALLS, SEQ_RNG_SITES, SEQ_RANDINT_CALLS). With a recording whose flags
// include sound-rng (512) the sound code's calls of the RNG accessor 0x000964d0 (0x1ef2a0, 0x1efe20, 0x1f7320) get a
// private MWC state and audio sequencing's rand() (0x260ae0) a private LCG; with seq-rng (.hrp bit 13) the
// sequencer's inline steps read hulk_seq_rng_ptr and its RandInt (0x113e0) calls step the same private state.
// Without a recording: the game's own generators. tools/native_link.py SITE_REBIND binds the call sites.
static void startup_common(void) {
    if (!hulk_main_tid)
        hulk_main_tid = hulk_host_GetCurrentThreadId();
    if (!hulk_seq_rng_ptr)
        hulk_seq_rng_ptr = *(hulk_u32*)DAT_004e5acc;
}

extern "C" void* HULK_CDECL FUN_000964d0();
extern "C" void* HULK_CDECL hulk_sound_rng(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & 512u)) {
        hulk_snd_calls++;
        return hulk_snd_rng;
    }
    return FUN_000964d0();
}

extern "C" int HULK_HOST_CDECL hulk_host_rand(void);
extern "C" int HULK_CDECL hulk_sound_rand(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & 512u)) {
        hulk_snd_rand = hulk_snd_rand * 214013u + 2531011u;
        return (int)((hulk_snd_rand >> 16) & 0x7fffu);
    }
    return hulk_host_rand();
}

extern "C" int HULK_CDECL FUN_000113e0(int lo, int hi);
extern "C" int HULK_CDECL hulk_seq_randint(int lo, int hi) {
    HulkReplayInfo ri;
    if (!(replay_open(&ri) && (ri.flags & HULK_RF_SEQ_RNG)))
        return FUN_000113e0(lo, hi);
    hulk_u32* st = hulk_snd_rng;
    st[0] = 36969u * (st[0] & 0xFFFFu) + (st[0] >> 16);
    st[1] = 18000u * (st[1] & 0xFFFFu) + (st[1] >> 16);
    hulk_u32 r = (st[0] << 16) + (st[1] & 0xFFFFu);
    return (int)(r % (hulk_u32)(hi - lo + 1) + (hulk_u32)lo);
}

// ---------------------------------------------------------------------------------------------------------------
// H: I/O sync (hybrid/hooks.cpp hybrid_syncio_tail, HF_SYNCIO; docs/tasks/record-replay.md "syncio"). An exit hook
// of core::DriveThread's post routine 0x00272fc0 (tools/native_link.py EXIT_HOOKS, `this` = the drive): on the main
// thread, wait until the drive has nothing queued or running (+0x8c = 0), 1 ms at a time, at most 2,000 times, so
// every file request completes in the frame that made it. Off unless HULK_SYNCIO=1: the recordings so far (play3)
// were made without the hybrid's syncio flag, and an .hrp cannot carry it (its bit 13 is seq-rng, the hybrid's
// HF_SYNCIO is 8192 too). Measured on play3 (native11): with the wait, the audio stream drive (HalRsdFileStream)
// keeps a request in flight, the main thread times out 35 times in 30 frames; without it 420+ frames match.
static int hulk_syncio = -1;
extern "C" void HULK_CDECL hulk_hook_drive_post(hulk_u32 drive) {
    if (hulk_syncio < 0) {
        const char* e = hulk_host_getenv("HULK_SYNCIO");
        hulk_syncio = e && *e && e[0] == '1';
    }
    hulk_io_posts++;
    if (!hulk_syncio || !drive || hulk_host_GetCurrentThreadId() != hulk_main_tid)
        return;
    for (int n = 0; *(volatile hulk_u32*)(drive + 0x8c) != 0; n++) {
        if (n == 2000) {
            hulk_io_timeouts++;
            return;
        }
        hulk_host_Sleep(1);
        hulk_io_waits++;
    }
}

// ---------------------------------------------------------------------------------------------------------------
// F no-fmv (tweak bit 1; tools/patch_xbe.py TWEAKS "no-fmv"): entry hooks (tools/native_link.py ENTRY_HOOKS, a nonzero
// result returns at once). CFMVManager::QueueMovie 0x001b7310 queues nothing; the FMV render 0x001b7d10, when it has
// a movie (+0xc) and is not paused (+8), takes its "status 0: finished" path: 0x00333ef0, then the manager's stop
// 0x001b7970, and returns (the hybrid build reads the status call at 0x1b7d38 as 0).
static int no_fmv(void) {
    HulkReplayInfo ri;
    return replay_open(&ri) && (ri.tweaks & 2);
}

extern "C" int HULK_CDECL hulk_hook_fmv_queue(hulk_u32* regs) {
    (void)regs;
    return no_fmv();
}

void FUN_00333ef0();
struct HulkFmvManager {
    void FUN_001b7970();
};
extern "C" int HULK_CDECL hulk_hook_fmv_render(hulk_u32* regs) {
    hulk_u32 self = regs[1];
    if (!no_fmv() || !self || !*(hulk_u32*)(self + 0xc) || *(unsigned char*)(self + 8))
        return 0;
    FUN_00333ef0();
    ((HulkFmvManager*)self)->FUN_001b7970();
    return 1;
}

// The new-game reseed (request E): 0x00086630's call of core::GetMicroseconds 0x00267f00 (SITE_REBIND) returns the
// recording's seed with a recording open.
extern "C" int HULK_CDECL FUN_00267f00();
extern "C" int HULK_CDECL hulk_replay_seed(void) {
    HulkReplayInfo ri;
    if (replay_open(&ri))
        return (int)ri.seed;
    return FUN_00267f00();
}

#else

extern "C" { hulk_u32 hulk_seq_rng_ptr; }
extern "C" char DAT_004e5acc[];
extern "C" void* HULK_CDECL FUN_000964d0();
extern "C" void* HULK_CDECL hulk_sound_rng(void) {
    return FUN_000964d0();
}
extern "C" int HULK_HOST_CDECL hulk_host_rand(void);
extern "C" int HULK_CDECL hulk_sound_rand(void) {
    return hulk_host_rand();
}
extern "C" int HULK_CDECL FUN_000113e0(int lo, int hi);
extern "C" int HULK_CDECL hulk_seq_randint(int lo, int hi) {
    return FUN_000113e0(lo, hi);
}
extern "C" void HULK_CDECL hulk_hook_drive_post(hulk_u32 drive) {
    (void)drive;
}
extern "C" int HULK_CDECL hulk_hook_fmv_queue(hulk_u32* regs) {
    (void)regs;
    return 0;
}
extern "C" int HULK_CDECL hulk_hook_fmv_render(hulk_u32* regs) {
    (void)regs;
    return 0;
}

extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    (void)clock;
}

extern "C" void HULK_CDECL hulk_replay_startup(void) {
    hulk_seq_rng_ptr = *(hulk_u32*)DAT_004e5acc;
}

extern "C" int HULK_CDECL hulk_hook_pad_poll(hulk_u32* regs) {
    (void)regs;
    return 0;
}

extern "C" int HULK_CDECL FUN_00267f00();
extern "C" int HULK_CDECL hulk_replay_seed(void) {
    return FUN_00267f00();
}

#endif
