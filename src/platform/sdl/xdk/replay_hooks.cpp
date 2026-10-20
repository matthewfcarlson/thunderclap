// Replay hooks of the native image (docs/native-replay.md; build/rp1/for-native9.md B): the per-frame checkpoint.
// tools/native_link.py --gfx wraps GameClock::Update 0x00086450 (`_hulk_clock_update`): before the draw log's frame
// tick it calls hulk_native_frame with the clock (Update's `this`). The hashed regions are the image's own data
// items, named by their XBE addresses (bound by address like the tree's names): the gameplay RNG 0x4e5ad0,
// g_BootSequenceStep 0x49fb40, the camera singleton pointer 0x4e231c. Native builds only.
#include "imports.h"
#include "../crt/host_crt.h"

#if defined(HULK_NATIVE_SDL)
#include "../replay/hulk_replay.h"

extern "C" char DAT_004e5ad0[];         // the gameplay RNG's two MWC words
extern "C" char DAT_0049fb40[];         // g_BootSequenceStep
extern "C" char DAT_004e231c[];         // the camera singleton pointer
extern "C" void HULK_CDECL hulk_native_log(const char* line);

extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    HulkCkptState st;
    st.rng = DAT_004e5ad0;
    st.boot_step = DAT_0049fb40;
    st.camera_ptr = (const void* const*)DAT_004e231c;
    st.clock = clock;
    st.clock_at_entry = 1;
    int r = hulk_ckpt_update(&st);
    static unsigned logged;
    if (r >= 0 && logged < 64) {       // the first checkpoints in the trace too (HULK_CKPT; SDL_Log has them all)
        HulkCkptStats s;
        hulk_ckpt_stats(&s);
        unsigned want = 0;
        int have = hulk_replay_expected_hash(s.frame - 1, &want);
        char line[160];
        hulk_host__snprintf(line, sizeof(line), "ckpt frame %u hash %08x recording %s%08x %s", s.frame - 1, s.last_hash,
                     have ? "" : "(none) ", want, r ? "ok" : "DIVERGED");
        hulk_native_log(line);
        if (logged == 0) {        // the first checkpoint's inputs (a frame-0 divergence: which region differs)
            const hulk_u32* r = (const hulk_u32*)st.rng;
            const hulk_u32* c = (const hulk_u32*)((const char*)clock + 0x10);
            const void* cam = *st.camera_ptr;
            hulk_host__snprintf(line, sizeof(line), "ckpt regions: rng %08x %08x boot %u camera %08x",
                                r[0], r[1], *(const hulk_u32*)st.boot_step, (hulk_u32)(__SIZE_TYPE__)cam);
            hulk_native_log(line);
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
extern "C" void HULK_CDECL hulk_replay_startup(void) {
    const char* src = hulk_host_getenv("HULK_INPUT_SOURCE");
    if (!src || src[0] != 'r')
        return;
    hulk_input_init();
    HulkReplayInfo ri;
    if (!replay_open(&ri))
        return;
    if (ri.tweaks & 1)
        *(hulk_u32*)DAT_0049fb40 = 6;
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

extern "C" void HULK_CDECL hulk_native_frame(const void* clock) {
    (void)clock;
}

extern "C" void HULK_CDECL hulk_replay_startup(void) {
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
