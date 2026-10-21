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
extern "C" hulk_u32 hulk_native_frame_no;    // (startup.cpp: the probes' frame number)
static void hulk_io_frame_sync(void);
static void hulk_ls_log_stats(void);
extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    hulk_io_frame_sync();
    hulk_native_frame_no++;
    HulkCkptState st;
    st.rng = DAT_004e5ad0;
    st.boot_step = DAT_0049fb40;
    st.camera_ptr = (const void* const*)DAT_004e231c;
    st.clock = clock;
    st.clock_at_entry = 1;
    // native16: HULK_CKPT_EVERY=<from>-<to>: the RNG and the camera position at every frame in that range (before the
    // frame's update, as the checkpoint sees them), to bracket a divergence between two checkpoints
    {
        static int ev = -1;
        static hulk_u32 ev_from, ev_to;
        if (ev < 0) {
            const char* v = hulk_host_getenv("HULK_CKPT_EVERY");
            ev = 0;
            if (v && *v) {
                for (; *v >= '0' && *v <= '9'; v++)
                    ev_from = ev_from * 10 + (hulk_u32)(*v - '0');
                if (*v == '-')
                    v++;
                for (; *v >= '0' && *v <= '9'; v++)
                    ev_to = ev_to * 10 + (hulk_u32)(*v - '0');
                ev = 1;
            }
        }
        hulk_u32 fno = hulk_native_frame_no - 1;
        if (ev && fno >= ev_from && fno <= ev_to) {
            const hulk_u32* r = (const hulk_u32*)st.rng;
            const void* cam = *st.camera_ptr;
            const hulk_u32* p = cam ? (const hulk_u32*)((const char*)cam + 0x4c) : 0;
            char line[160];
            hulk_host__snprintf(line, sizeof(line), "ckpt every f=%u rng %08x %08x camera %08x %08x %08x", fno, r[0], r[1],
                                p ? p[0] : 0, p ? p[1] : 0, p ? p[2] : 0);
            hulk_native_log(line);
        }
    }
    int r = hulk_ckpt_update(&st);
    static unsigned logged, bad;
    HulkCkptStats s;
    if (r >= 0)
        hulk_ckpt_stats(&s);
    // the first 64 checkpoints in the trace too (HULK_CKPT; SDL_Log has them all), then the first 16 divergences and
    // every 50th checkpoint
    // (native17: HULK_CKPT_ALL=1 logs every checkpoint: comparing two runs' hashes)
    static int log_all = -1;
    if (log_all < 0) {
        const char* v = hulk_host_getenv("HULK_CKPT_ALL");
        log_all = v && *v == '1';
    }
    if (r >= 0 && (log_all || logged < 64 || (r == 0 && bad < 16) || (s.frame - 1) % 1500 == 0)) {
        int first_bad = r == 0 && bad++ == 0;
        unsigned want = 0;
        int have = hulk_replay_expected_hash(s.frame - 1, &want);
        char line[160];
        hulk_host__snprintf(line, sizeof(line), "ckpt frame %u hash %08x recording %s%08x %s (io posts %u waits %u timeouts %u, sound rng %u)",
                     s.frame - 1, s.last_hash, have ? "" : "(none) ", want, r ? "ok" : "DIVERGED", hulk_io_posts, hulk_io_waits,
                     hulk_io_timeouts, hulk_snd_calls);
        hulk_native_log(line);
        // (native13) HULK_CKPT_REGIONS=1: the regions of every logged checkpoint (brute-forcing which one differs)
        static int all_regions = -1;
        if (all_regions < 0) {
            const char* v = hulk_host_getenv("HULK_CKPT_REGIONS");
            all_regions = v && *v == '1';
        }
        if (logged == 0 || first_bad || all_regions) {   // the inputs of the first checkpoint and of the first divergence
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
        hulk_ls_log_stats();
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
// native15: without a wait, which frame a request's result lands in follows the host's thread timing (the same image
// and replay saw 0x00203a80's first call at frame 914 in one run and 915 in the next: play3, docs/native-replay.md).
// Guest-time models, per request (the posted node, the wrapper's third argument), not per drive: every request of
// the game goes through one DriveThread, which also carries the audio stream's persistent read.
//   HULK_SYNCIO=3: a request completes before the next frame (the main thread waits at GameClock::Update's entry
//                  for every request posted before it);
//   HULK_SYNCIO=4: a request completes at once (the main thread waits right after the post).
// A request is done when it is no longer queued and the drive runs nothing else (count = queued). A request still
// pending after 300 ms is a persistent stream (its class, the node's vftable, is logged and not waited on again).
// HULK_SYNCIO_LOG=1: one `io` line per post (frame, node class, queue count before).
static int hulk_syncio = -1, hulk_io_log = -1;
static hulk_u32 hulk_io_idle_env = 4;
struct HulkIoLock {
    virtual void enter();
    virtual void leave();
};
struct HulkIoPending {
    hulk_u32 drive, node, vt;
};
static HulkIoPending hulk_io_pending[256];
static hulk_u32 hulk_io_npending, hulk_io_persistent[16], hulk_io_npersistent;
static void hulk_io_settings(void) {
    const char* e = hulk_host_getenv("HULK_SYNCIO");
    hulk_syncio = e && *e ? e[0] - '0' : replay_open(0) ? 5 : 0;    // (native17: lockstep by default in a replay)
    e = hulk_host_getenv("HULK_SYNCIO_LOG");
    hulk_io_log = e && *e == '1';
    e = hulk_host_getenv("HULK_IO_IDLE");
    if (e && *e >= '1' && *e <= '9')
        hulk_io_idle_env = (hulk_u32)(*e - '0');
}
// 1: done; 0: still queued or something is running
static int hulk_io_done(hulk_u32 drive, hulk_u32 node) {
    HulkIoLock* lock = (HulkIoLock*)(drive + 0xc);
    lock->enter();
    hulk_u32 queued = 0;
    int found = 0;
    for (int i = 0; i < 3; i++)
        for (hulk_u32 p = *(hulk_u32*)(drive + 0x6c + 4 * i); p && queued < 100000; p = *(hulk_u32*)(p + 4)) {
            queued++;
            found |= p == node;
        }
    hulk_u32 count = *(volatile hulk_u32*)(drive + 0x8c);
    lock->leave();
    return !found && count <= queued;
}
static void hulk_io_wait(const HulkIoPending& r) {
    for (hulk_u32 i = 0; i < hulk_io_npersistent; i++)
        if (hulk_io_persistent[i] == r.vt)
            return;
    for (int n = 0; !hulk_io_done(r.drive, r.node); n++) {
        if (n == 300 + 64) {
            hulk_io_timeouts++;
            if (hulk_io_npersistent < 16)
                hulk_io_persistent[hulk_io_npersistent++] = r.vt;
            char line[128];
            hulk_host__snprintf(line, sizeof(line), "io frame %u: request class %08x still pending after 300 ms: a stream, "
                                "not waited on", hulk_native_frame_no, r.vt);
            hulk_native_log(line);
            return;
        }
        hulk_host_Sleep(n < 64 ? 0 : 1);
        hulk_io_waits++;
    }
}
// ---------------------------------------------------------------------------------------------------------------
// native17: HULK_SYNCIO=5, the drive in lockstep with the main thread (the default with a recording open). The
// hybrid capture on play3 (native16: 1,089 posts to frame 1,000) saw every request retired in the frame that posted
// it; natively the drive thread ran beside the main thread, so which frame a result landed in followed the host
// (0x00203a80's first call at 914 or 915, docs/native-replay.md). Here a drive thread (core::DriveThread's routine
// 0x002731d0, started through 0x0026dc50 / CreateThread with the worker whose +8 is the routine and +0xc the drive)
// runs one request step at a time, and only while the main thread hands it a turn and waits for it:
//   - after each post of the main thread (0x00272fc0's exit hook): the drive runs until its queue is empty or
//     HULK_IO_IDLE (default 4) steps in a row retire nothing (a request that waits for later main-thread work,
//     e.g. the audio stream's persistent read, is re-queued by the routine and tried again at the next turn);
//   - at each GameClock::Update entry, and when the main thread sleeps (a loader polling for a result): the same;
//   - when the main thread waits on a handle: one step at a time while the handle is unsignalled and the drive has
//     work, then the real wait.
// A step boundary is the routine's wait on its `ready` semaphore (drive +0x68; threads.cpp's WaitForSingleObject
// calls hulk_io_drive_wait for it): the drive thread reports its arrival and blocks until granted the next step. So
// the order of every drive step relative to the main thread's work is fixed, whatever the host's speed. A step that
// blocks on something else for more than 5 s (it needs the main thread) is logged and left to finish on its own.
// Host time is not read anywhere in the scheme, except for that guard.
struct HulkLsDrive {
    hulk_u32 drive, ready, tid;
    void* arrive;          // the drive thread releases it at each step boundary
    void* grant;           // the main thread releases it to start a step
    int need_arrival;      // a step was granted (or the thread started) and its arrival not yet seen
    hulk_u32 done;         // the drive's error semaphore (+0x84): the routine waits on it for the main thread
    int in_done;           // the drive thread is paused in that wait
};
static HulkLsDrive hulk_ls[4];
static int hulk_nls;
static hulk_u32 hulk_ls_steps, hulk_ls_blocked;
extern "C" void HULK_CDECL FUN_002731d0(void);    // core::DriveThread's thread routine
extern "C" void HULK_CDECL FUN_0026db70(void);    // the thread trampoline 0x0026dc50 passes to CreateThread
static int hulk_ls_on(void) {
    if (hulk_syncio < 0)
        hulk_io_settings();
    return hulk_syncio == 5;
}
extern "C" void HULK_CDECL hulk_io_thread_created(hulk_u32 start, hulk_u32 param) {
    if (start != (hulk_u32)(__SIZE_TYPE__)&FUN_0026db70 || !param || !hulk_ls_on())
        return;
    if (*(hulk_u32*)(param + 8) != (hulk_u32)(__SIZE_TYPE__)&FUN_002731d0 || hulk_nls == 4)
        return;
    HulkLsDrive& d = hulk_ls[hulk_nls];
    d.drive = *(hulk_u32*)(param + 0xc);
    d.ready = *(hulk_u32*)(d.drive + 0x68);
    d.done = *(hulk_u32*)(d.drive + 0x84);
    d.arrive = hulk_host_CreateSemaphoreA(0, 0, 0x7fffffff, 0);
    d.grant = hulk_host_CreateSemaphoreA(0, 0, 0x7fffffff, 0);
    d.need_arrival = 1;
    hulk_nls++;
    char line[96];
    hulk_host__snprintf(line, sizeof(line), "io lockstep: drive %d at %08x (ready semaphore %08x)", hulk_nls - 1,
                        d.drive, d.ready);
    hulk_native_log(line);
}
// the drive thread at a step boundary (its wait on `ready`): 1 = handled, *result = the wait's result
extern "C" int HULK_CDECL hulk_io_drive_wait(hulk_u32 handle, hulk_u32 ms, hulk_u32* result) {
    if (hulk_syncio != 5 || ms != 0xffffffffu || hulk_host_GetCurrentThreadId() == hulk_main_tid)
        return 0;
    for (int i = 0; i < hulk_nls; i++) {
        HulkLsDrive& d = hulk_ls[i];
        if (d.done == handle && d.tid == hulk_host_GetCurrentThreadId()) {
            // a request failed (FUN_00272aa0 told the main thread) and the routine waits until the main thread's
            // drive pump has handled it: the step pauses here; the main thread resumes it once `done` is
            // signalled (it consumes the signal for the drive, hulk_ls_step)
            d.in_done = 1;
            hulk_host_ReleaseSemaphore(d.arrive, 1, 0);
            hulk_host_WaitForSingleObject(d.grant, 0xffffffffu);
            d.in_done = 0;
            *result = 0;
            return 1;
        }
        if (d.ready != handle)
            continue;
        if (!d.tid) {
            d.tid = hulk_host_GetCurrentThreadId();
            char line[64];
            hulk_host__snprintf(line, sizeof(line), "io lockstep: drive %d thread %u", i, d.tid);
            hulk_native_log(line);
        }
        hulk_host_ReleaseSemaphore(d.arrive, 1, 0);
        hulk_host_WaitForSingleObject(d.grant, 0xffffffffu);
        *result = hulk_host_WaitForSingleObject((void*)handle, 0xffffffffu);
        return 1;
    }
    return 0;
}
static hulk_u32 hulk_ls_count(const HulkLsDrive& d) {
    return *(volatile hulk_u32*)(d.drive + 0x8c);
}
// one step of drive d (main thread): 1 = the step ran and the drive is back at its boundary
static int hulk_ls_step(HulkLsDrive& d) {
    if (d.need_arrival) {
        if (hulk_host_WaitForSingleObject(d.arrive, 5000) != 0)
            return 0;
        d.need_arrival = 0;
    }
    if (d.in_done) {      // paused in the error wait: resumes only when the main thread has signalled `done`
        if (hulk_host_WaitForSingleObject((void*)d.done, 0) != 0)
            return 0;
    } else if (!hulk_ls_count(d))
        return 0;
    hulk_u32 vt = 0;
    for (int i = 0; i < 3 && !vt; i++) {
        hulk_u32 p = *(volatile hulk_u32*)(d.drive + 0x6c + 4 * i);
        if (p)
            vt = *(hulk_u32*)p;
    }
    hulk_host_ReleaseSemaphore(d.grant, 1, 0);
    d.need_arrival = 1;
    hulk_ls_steps++;
    if (hulk_host_WaitForSingleObject(d.arrive, 5000) != 0) {
        hulk_ls_blocked++;
        char line[128];
        hulk_host__snprintf(line, sizeof(line), "io lockstep frame %u: a step of request class %08x still running after "
                            "5 s (it waits for the main thread); left to finish on its own", hulk_native_frame_no, vt);
        hulk_native_log(line);
        return 0;
    }
    d.need_arrival = 0;
    if (hulk_io_log) {
        char line[96];
        hulk_host__snprintf(line, sizeof(line), "io step frame %u class %08x count after %u", hulk_native_frame_no, vt,
                            hulk_ls_count(d));
        hulk_native_log(line);
    }
    return 1;
}
// run every drive until its queue is empty or HULK_IO_IDLE steps in a row retire nothing (main thread)
static void hulk_ls_settle(void) {
    for (int i = 0; i < hulk_nls; i++) {
        HulkLsDrive& d = hulk_ls[i];
        hulk_u32 idle = 0;
        for (int n = 0; n < 100000; n++) {
            hulk_u32 before = hulk_ls_count(d);
            if (!before || !hulk_ls_step(d))
                break;
            if (hulk_ls_count(d) < before)
                idle = 0;
            else if (++idle >= hulk_io_idle_env)
                break;
        }
    }
}
extern "C" void HULK_CDECL hulk_io_main_sleep(void) {
    if (hulk_nls && hulk_ls_on() && hulk_host_GetCurrentThreadId() == hulk_main_tid)
        hulk_ls_settle();
}
// A post's turn: right after it, as the hybrid's drive thread starts on it at once, but only once the main thread
// holds no critical section (library.cpp counts them: the post's caller may hold a lock the step takes, e.g. the
// file's); until then the turn is pending and runs at the main thread's last leave
static hulk_u32 hulk_ls_cs_depth, hulk_ls_now, hulk_ls_later;
static int hulk_ls_post_pending;
extern "C" void HULK_CDECL hulk_io_cs_enter(void) {
    if (hulk_main_tid && hulk_host_GetCurrentThreadId() == hulk_main_tid)
        hulk_ls_cs_depth++;
}
extern "C" void HULK_CDECL hulk_io_cs_leave(void) {
    if (!hulk_main_tid || hulk_host_GetCurrentThreadId() != hulk_main_tid)
        return;
    if (hulk_ls_cs_depth)
        hulk_ls_cs_depth--;
    if (!hulk_ls_cs_depth && hulk_ls_post_pending) {
        hulk_ls_post_pending = 0;
        hulk_ls_settle();
    }
}
static void hulk_ls_log_stats(void) {    // (HULK_SYNCIO_LOG=1, at each logged checkpoint)
    if (hulk_syncio != 5 || !hulk_io_log)
        return;
    char line[128];
    hulk_host__snprintf(line, sizeof(line), "io lockstep: %u steps, %u blocked, post turns %u at once %u deferred",
                        hulk_ls_steps, hulk_ls_blocked, hulk_ls_now, hulk_ls_later);
    hulk_native_log(line);
}
static void hulk_ls_post(void) {
    if (hulk_ls_cs_depth) {
        hulk_ls_post_pending = 1;
        hulk_ls_later++;
    } else {
        hulk_ls_now++;
        hulk_ls_settle();
    }
}
// core::Drive::vfunc_3 0x00272df0 entry (tools/native_link.py ENTRY_HOOKS): the main thread's drive pump
extern "C" int HULK_CDECL hulk_hook_drive_pump(hulk_u32* regs) {
    (void)regs;
    hulk_io_main_sleep();
    return 0;
}
// the main thread about to wait on `handle`: drive steps while it is unsignalled and a drive has work. 1 = the
// handle was signalled meanwhile (the zero-time wait that saw it consumed it, as the real wait would): *result
extern "C" int HULK_CDECL hulk_io_main_wait(hulk_u32 handle, hulk_u32* result) {
    if (!hulk_nls || !hulk_ls_on() || hulk_host_GetCurrentThreadId() != hulk_main_tid)
        return 0;
    for (int n = 0; n < 100000; n++) {
        hulk_u32 r = hulk_host_WaitForSingleObject((void*)handle, 0);
        if (r != 0x102u) {
            *result = r;
            return 1;
        }
        int stepped = 0;
        for (int i = 0; i < hulk_nls && !stepped; i++)
            if (hulk_ls_count(hulk_ls[i]))
                stepped = hulk_ls_step(hulk_ls[i]);
        if (!stepped)
            return 0;
    }
    return 0;
}

static void hulk_io_frame_sync(void) {
    if (hulk_syncio < 0)
        hulk_io_settings();
    if (hulk_syncio == 5) {
        hulk_ls_settle();
        return;
    }
    for (hulk_u32 i = 0; i < hulk_io_npending; i++)
        hulk_io_wait(hulk_io_pending[i]);
    hulk_io_npending = 0;
}

extern "C" void HULK_CDECL hulk_hook_drive_post(hulk_u32 drive, hulk_u32 before, hulk_u32 node) {
    if (hulk_syncio < 0)
        hulk_io_settings();
    hulk_io_posts++;
    if (!drive || !node || hulk_host_GetCurrentThreadId() != hulk_main_tid)
        return;
    HulkIoPending r = {drive, node, *(hulk_u32*)node};
    if (hulk_io_log) {
        char line[96];
        hulk_host__snprintf(line, sizeof(line), "io post frame %u class %08x count before %u", hulk_native_frame_no, r.vt,
                            before);
        hulk_native_log(line);
    }
    if (hulk_syncio == 5) {
        hulk_ls_post();
    } else if (hulk_syncio == 1) {    // the hybrid's syncio: the whole queue
        for (int n = 0; *(volatile hulk_u32*)(drive + 0x8c) != 0; n++) {
            if (n == 2000) {
                hulk_io_timeouts++;
                return;
            }
            hulk_host_Sleep(1);
            hulk_io_waits++;
        }
    } else if (hulk_syncio == 4) {
        hulk_io_wait(r);
    } else if (hulk_syncio == 3) {
        if (hulk_io_npending == sizeof(hulk_io_pending) / sizeof(hulk_io_pending[0]))
            hulk_io_frame_sync();
        hulk_io_pending[hulk_io_npending++] = r;
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
extern "C" void HULK_CDECL hulk_hook_drive_post(hulk_u32 drive, hulk_u32 before, hulk_u32 node) {
    (void)drive;
    (void)before;
    (void)node;
}
extern "C" void HULK_CDECL hulk_io_thread_created(hulk_u32 start, hulk_u32 param) {
    (void)start;
    (void)param;
}
extern "C" int HULK_CDECL hulk_io_drive_wait(hulk_u32 handle, hulk_u32 ms, hulk_u32* result) {
    (void)handle;
    (void)ms;
    (void)result;
    return 0;
}
extern "C" void HULK_CDECL hulk_io_main_sleep(void) {}
extern "C" void HULK_CDECL hulk_io_cs_enter(void) {}
extern "C" void HULK_CDECL hulk_io_cs_leave(void) {}
extern "C" int HULK_CDECL hulk_hook_drive_pump(hulk_u32* regs) {
    (void)regs;
    return 0;
}
extern "C" int HULK_CDECL hulk_io_main_wait(hulk_u32 handle, hulk_u32* result) {
    (void)handle;
    (void)result;
    return 0;
}
extern "C" int HULK_CDECL hulk_hook_fmv_queue(hulk_u32* regs) {
    (void)regs;
    return 0;
}
extern "C" int HULK_CDECL hulk_hook_fmv_render(hulk_u32* regs) {
    (void)regs;
    return 0;
}

extern "C" hulk_u32 hulk_native_frame_no;    // (startup.cpp: the probes' frame number)
extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    hulk_native_frame_no++;
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
