// The replay driver of the wasm32 port (docs/wasm-port.md "Replays"; wasm3, D202 Q3/Q4): what the Wine build's
// src/platform/sdl/xdk/replay_hooks.cpp and the native builds' src/platform/sdl/host/replay_native.cpp do, for the wasm
// host. wasm32 has the Xbox's 4-byte pointers and the game's data sits at its XBE addresses, so every read here is at
// the original's 32-bit offsets, as on the Wine build.
//
//   * the recording (src/platform/sdl/replay/hulk_replay.cpp, included: the .hrp reader, the pad stream, the narrow
//     checkpoint hash) and the semantic probe (src/platform/sdl/ckpt/ckpt_probe.cpp, included: HULK_CKREF records);
//   * the hooks of src/platform/sdl/host/native_hooks.h, placed by tools/wasm_port.py (wasm_hooks(): renaming at
//     bind time, never by editing a replay-pin function's source). Each is `ffh_<hook>`, a generic entry's shape;
//   * the virtual clock of a recording whose flags include vclock (xdk/timing.cpp's model: QueryPerformanceCounter and
//     GameClock::Update's time), and the pad's XInputGetState from the recording (input.c asks here first).
//
// Trace lines (HULK_TRACE_FILE: "ckpt frame ..." as replay_hooks.cpp writes them, which tools/native_replay.py reads)
// and the records (HULK_TRACE_FILE + ".ckref") are written through the host's file imports. The replay's own state
// (the recording's position, the sound code's private generators) is host state, outside the game state for now.
extern "C" {
#include "hulk_host.h"
#include "hulk_io.h"
#include "sim.h"
}
#include <stdio.h>
#include <stdlib.h>

#include "../../sdl/replay/hulk_replay.cpp"
#include "../../sdl/ckpt/ckpt_probe.cpp"

#define FFH(name) extern "C" void ffh_##name(uint32_t ecx, uint32_t edx, void* st, void* rb)
#define HOOK_UNUSED (void)ecx, (void)edx, (void)st, (void)rb

typedef uint32_t u32;
typedef uint64_t u64;

extern "C" {
// the definitions behind the entry hooks (tools/wasm_port.py: the original's generic entry)
void ffgo_00086450(uint32_t, uint32_t, void*, void*);   // GameClock::Update
void ffgo_00269170(uint32_t, uint32_t, void*, void*);   // core::ControllerSystemXBox::vfunc_12, the pad poll
void ffgo_001b7310(uint32_t, uint32_t, void*, void*);   // CFMVManager::QueueMovie
void ffgo_001b7d10(uint32_t, uint32_t, void*, void*);   // the FMV render
}

void* hulk_wasm_load_file(const char* path, size_t* size) {
    int32_t f = hio_open(path, HIO_READ);
    if (f < 0)
        return 0;
    uint32_t n = hio_size(f);
    char* d = (char*)malloc(n + 1);
    if (d && hio_read(f, d, n, 0) != (int32_t)n) {
        free(d);
        d = 0;
    }
    hio_close(f);
    if (d) {
        d[n] = 0;
        *size = n;
    }
    return d;
}

// ---------------------------------------------------------------------------------------------------------------
// output: the trace (append) and the records
struct OutFile {
    int32_t fd = -2;
    uint32_t off = 0;
};
static OutFile g_trace, g_ckref;
static int out_open(OutFile& o, const char* suffix) {
    if (o.fd == -2) {
        const char* tp = getenv("HULK_TRACE_FILE");
        char path[600];
        snprintf(path, sizeof(path), "%s%s", tp && *tp ? tp : "hulk-trace.txt", suffix);
        o.fd = hio_open(path, HIO_CREATE);
    }
    return o.fd >= 0;
}
static void out_write(OutFile& o, const void* p, uint32_t n) {
    int32_t w = hio_write(o.fd, p, n, o.off);
    if (w > 0)
        o.off += (uint32_t)w;
}
static void log_line(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void log_line(const char* fmt, ...) {
    char line[320];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(line, sizeof(line) - 1, fmt, ap);
    va_end(ap);
    if (n < 0)
        return;
    if (n > (int)sizeof(line) - 2)
        n = (int)sizeof(line) - 2;
    line[n++] = '\n';
    if (out_open(g_trace, ""))
        out_write(g_trace, line, (uint32_t)n);
    else
        fwrite(line, 1, (size_t)n, stderr);
}

static int env_flag(const char* name) {
    const char* v = getenv(name);
    return v && *v == '1';
}

// ---------------------------------------------------------------------------------------------------------------
// the recording
#define HULK_RF_FIXED_DT 1u
#define HULK_RF_VCLOCK 128u
#define HULK_RF_SOUND_RNG 512u
#define HULK_RF_VDATE 4096u
#define HULK_RF_SEQ_RNG (1u << 13)

static int g_open = -1;
static HulkReplayInfo g_info;
static int replay_open(HulkReplayInfo* ri) {
    if (g_open < 0) {
        g_open = 0;
        const char* src = getenv("HULK_INPUT_SOURCE");
        if (src && strncmp(src, "replay:", 7) == 0) {
            if (hulk_replay_open(src + 7))
                g_open = hulk_replay_info(&g_info) ? 1 : 0;
            else
                ff_fatal("%s", hulk_replay_error());
        }
    }
    if (ri)
        *ri = g_info;
    return g_open;
}

extern "C" void ff_io_main_sleep(void);
extern "C" void ff_io_stats(uint32_t* posts, uint32_t* steps, uint32_t* blocked);
static u32 g_frame_no;            // GameClock::Update calls so far (replay_hooks.cpp hulk_native_frame_no)
static u32 g_snd_calls;           // sound-rng draws served from the private state
static u32 g_snd_rng[4] = {0x2F6B6F2Au, 0x1F123BB5u, 0, 0};   // hybrid/hooks.cpp: the sound code's own states
static u32 g_snd_rand = 0x5EEDu;
extern "C" {
u32 hulk_seq_rng_ptr;             // seq-rng: the audio sequencer's reads of the RNG pointer 0x4e5acc read this
}

// After the C++ initializers, before main (boot.c): the recording opened and its tweaks applied as the hybrid build's
// load-time patches did: skip-intro (bit 0) = g_BootSequenceStep 6.
extern "C" void ff_replay_startup(void) {
    if (!hulk_seq_rng_ptr)
        hulk_seq_rng_ptr = *(u32*)PTR(0x004e5accu);
    HulkReplayInfo ri;
    if (!replay_open(&ri))
        return;
    if (ri.tweaks & 1)
        *(u32*)PTR(0x0049fb40u) = 6;
    if (ri.flags & HULK_RF_SEQ_RNG)
        hulk_seq_rng_ptr = (u32)(uintptr_t)g_snd_rng;
    SIM->pads_in = (1u << ri.vpad_count) - 1;
    log_line("replay: flags 0x%x tweaks 0x%x seed 0x%x, %u entries, %u checkpoints", ri.flags, ri.tweaks, ri.seed,
             ri.entries, ri.checkpoints);
}

// ---------------------------------------------------------------------------------------------------------------
// the pad (input.c's XInputGetState asks here first): the recording's state; the packet number counts changes
static u32 g_packet[4];
static uint8_t g_last[4][18];
static void pad_bytes(const HulkPadState& s, uint8_t* b) {
    b[0] = (uint8_t)s.buttons;
    b[1] = (uint8_t)(s.buttons >> 8);
    for (int i = 0; i < 8; i++)
        b[2 + i] = s.analog[i];
    for (int i = 0; i < 4; i++) {
        b[10 + 2 * i] = (uint8_t)s.thumb[i];
        b[11 + 2 * i] = (uint8_t)((uint16_t)s.thumb[i] >> 8);
    }
}
static int get_state(u32 port, uint8_t* out, int init) {
    const HulkInputSource* src = hulk_replay_source();
    HulkPadState s;
    if (!(init ? src->read_init(src->self, port, &s) : src->read(src->self, port, &s)))
        return 1167;                                    // ERROR_DEVICE_NOT_CONNECTED
    uint8_t b[18];
    pad_bytes(s, b);
    if (memcmp(b, g_last[port], 18)) {
        memcpy(g_last[port], b, 18);
        g_packet[port]++;
    }
    memcpy(out, &g_packet[port], 4);
    memcpy(out + 4, b, 18);
    return 0;
}
// -1: no recording (input.c serves the pad); else XInputGetState's result
extern "C" int ff_replay_get_state(u32 port, uint8_t* out) {
    if (!replay_open(0) || port > 3)
        return -1;
    return get_state(port, out, 0);
}
// site 0x002692c0 -> XInputGetState: ControllerSystemXBox's pad constructor reads a new pad 20 times: not polls
FFH(hulk_xdk_XInputGetStateInit) {
    HOOK_UNUSED;
    u32 port = (ARG(0) - 0x7000u) / 16;
    if (!replay_open(0)) {
        RET(ff_call(0x003eb91fu, 2, ARG(0), ARG(1)));
        return;
    }
    RET(port > 3 ? 1167 : get_state(port, (uint8_t*)PTR(ARG(1)), 1));
}

// ---------------------------------------------------------------------------------------------------------------
// the virtual clock (xdk/timing.cpp): 1 s at the first read, each main-thread read before the first GameClock::Update
// advances it 4 ms, the first Update sets it to 300 s, each later one by one step (33,333 us); between updates it
// stands still. A recording's flags turn it on (vclock), or HULK_VCLOCK=1.
static const u64 kVStartUs = 1000000ull, kVBaseUs = 300000000ull, kPreStepUs = 4000ull;
static u64 g_dt_us = 33333ull;
static int g_vflags = -1;
static u64 g_vt, g_vextra;
static u32 g_vmain, g_vframe;
static unsigned vclock_flags(void) {
    if (g_vflags < 0) {
        unsigned f = 0;
        const char* dt = getenv("HULK_VDT_US");
        if (dt) {
            u64 v = strtoull(dt, 0, 10);
            if (v >= 1000 && v <= 66666)
                g_dt_us = v;
        }
        if (env_flag("HULK_VCLOCK"))
            f = HULK_RF_FIXED_DT | HULK_RF_VCLOCK | HULK_RF_VDATE;
        HulkReplayInfo ri;
        if (replay_open(&ri))
            f |= ri.flags & (HULK_RF_FIXED_DT | HULK_RF_VCLOCK | HULK_RF_VDATE);
        if (f & HULK_RF_VCLOCK)
            f |= HULK_RF_FIXED_DT;
        g_vflags = (int)f;
    }
    return (unsigned)g_vflags;
}
// QueryPerformanceCounter (xapi.c): 1 and the virtual clock's ticks when it is on
extern "C" int ff_replay_qpc(u64* ticks) {
    if (!(vclock_flags() & HULK_RF_VCLOCK))
        return 0;
    if (!g_vmain) {                 // the first read: the game's own init, on the main thread
        g_vmain = SIM->cur_thread;
        g_vt = kVStartUs;
    }
    if (SIM->cur_thread == g_vmain && g_vframe == 0)
        g_vt += kPreStepUs;
    *ticks = g_vt * 733ull + g_vt / 3ull;
    return 1;
}
// GetLocalTime (xapi.c): 2006-01-02 (a Monday) 12:00:00 plus the virtual clock's seconds, with vdate
extern "C" int ff_replay_local_time(uint16_t* t) {
    if (!(vclock_flags() & HULK_RF_VDATE))
        return 0;
    unsigned secs = (unsigned)(g_vt / 1000000ull), rem = (unsigned)(g_vt % 1000000ull);
    unsigned sec = 12u * 3600u + secs, days = sec / 86400u;
    sec %= 86400u;
    t[0] = 2006;
    t[1] = 1;
    t[2] = (uint16_t)((1 + days) % 7);
    t[3] = (uint16_t)(2 + days % 28);
    t[4] = (uint16_t)(sec / 3600);
    t[5] = (uint16_t)(sec / 60 % 60);
    t[6] = (uint16_t)(sec % 60);
    t[7] = (uint16_t)(rem / 1000);
    return 1;
}
static u64 game_us(void) {          // core::GetMicroseconds64 0x00267f40, the game's own
    uint32_t st[4] = {0};
    uint64_t rb[2] = {0};
    ff_dispatch(0x00267f40u, 0, 0, st, rb);
    return rb[0];
}
// site 0x00086450 -> 0x00267f40: GameClock::Update's time
FFH(hulk_clock_tick) {
    HOOK_UNUSED;
    unsigned f = vclock_flags();
    if (!(f & HULK_RF_FIXED_DT)) {
        RET64(game_us());
        return;
    }
    g_vframe++;
    u64 t;
    if (!(f & HULK_RF_VCLOCK)) {
        t = kVBaseUs + (u64)g_vframe * g_dt_us;     // (fixed-dt alone: base + frame * dt)
    } else if (g_vframe == 1) {
        t = kVBaseUs;
        if (g_vt >= t)
            t = g_vt + 1;
    } else {
        t = g_vt - g_vextra + g_dt_us;
        if (g_vextra >= g_dt_us)
            t = g_vt + 1;
    }
    g_vextra = 0;
    if (f & HULK_RF_VCLOCK)
        g_vt = t;
    RET64(t);
}
// site 0x00087e30 -> 0x00267f40: the GameClock constructor's first timestamp
FFH(hulk_clock_now) {
    HOOK_UNUSED;
    unsigned f = vclock_flags();
    if (!(f & HULK_RF_FIXED_DT)) {
        RET64(game_us());
        return;
    }
    RET64((f & HULK_RF_VCLOCK) ? kVBaseUs - g_dt_us : kVBaseUs + (u64)g_vframe * g_dt_us);
}

// ---------------------------------------------------------------------------------------------------------------
// the per-frame checkpoint (GameClock::Update's entry): the narrow hash and the probe's record, before the update
static const void* probe_actor_of(const void* table, unsigned handle) {        // 0x00059c10
    return PTR(ff_call_this(0x00059c10u, (u32)(uintptr_t)table, 1, handle));
}
static int probe_position_of(const void* node, unsigned out[3]) {              // 0x00059a50
    return (ff_call_this(0x00059a50u, (u32)(uintptr_t)node, 1, (u32)(uintptr_t)out) & 0xff) != 0;
}
static void ckref_dump(void*, int tag, const char* name, unsigned index, unsigned bits, int is_float) {
    log_line("ckdump f=%u t=%d %s[%u] %08x%s", g_frame_no - 1, tag, name, index, bits, is_float ? " f" : "");
}
static void ckref_frame(u32 fno, const HulkCkptState* st, const unsigned char* pb) {
    static int on = -1, dump_on;
    static u32 dump_from, dump_to;
    if (on < 0) {
        on = env_flag("HULK_CKREF") && out_open(g_ckref, ".ckref");
        if (on) {
            u32 hdr[3] = {0x524b4348u /* "HCKR" */, 1, HULK_PROBE_VERSION};
            out_write(g_ckref, hdr, sizeof(hdr));
            const char* d = getenv("HULK_CKREF_DUMP");
            if (d && *d) {
                char* e;
                dump_from = dump_to = (u32)strtoul(d, &e, 10);
                if (*e == '-')
                    dump_to = (u32)strtoul(e + 1, 0, 10);
                dump_on = 1;
            }
        }
    }
    if (!on)
        return;
    HulkProbeInputs in;
    memset(&in, 0, sizeof(in));
    in.rng = st->rng;
    in.boot_step = st->boot_step;
    in.view_ptr = st->camera_ptr;
    in.clock = st->clock;
    in.clock_at_entry = st->clock_at_entry;
    in.prng = pb;
    in.snd_rng = g_snd_rng;
    in.snd_rand = &g_snd_rand;
    in.world_ptr = (const void* const*)PTR(0x004dd700u);
    in.actor_of = probe_actor_of;
    in.position_of = probe_position_of;
    unsigned mask = HULK_PROBE_CHEAP_MASK | (fno % HULK_PROBE_FULL_EVERY == 0 ? HULK_PROBE_FULL_MASK : 0);
    HulkProbeRecord rec;
    int dumping = dump_on && fno >= dump_from && fno <= dump_to;
    hulk_probe_frame(fno, &in, mask, &rec, dumping ? ckref_dump : 0, 0);
    rec.mask |= 1u << HULK_PT_LEGACY;
    rec.exact[HULK_PT_LEGACY] = rec.quant[HULK_PT_LEGACY] = hulk_ckpt_hash(fno, st);
    u32 out[3 + 2 * HULK_PT_COUNT];
    u32 n = 0;
    out[n++] = rec.frame;
    out[n++] = rec.mask;
    out[n++] = rec.unavailable;
    for (int t = 0; t < HULK_PT_COUNT; t++)
        if (rec.mask & (1u << t)) {
            out[n++] = rec.exact[t];
            out[n++] = rec.quant[t];
        }
    out_write(g_ckref, out, 4 * n);
}

static void frame(u32 clock) {
    g_frame_no++;
    HulkCkptState st;
    st.rng = PTR(0x004e5ad0u);
    st.boot_step = PTR(0x0049fb40u);
    st.camera_ptr = (const void* const*)PTR(0x004e231cu);
    st.clock = PTR(clock);
    st.clock_at_entry = 1;
    unsigned char pb[HULK_PRNG_BYTES];
    memcpy(pb, PTR(0x00554be4u), HULK_PRNG_BYTES);     // (0x554be4..0x554c0b: the six particle generators in a row)
    ckref_frame(g_frame_no - 1, &st, pb);
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
    unsigned ph = hulk_ckpt_prng_hash(s.frame - 1, pb), pwant = 0;
    int phave = hulk_replay_expected_prng(s.frame - 1, &pwant);
    if (!(all || logged < 64 || (r == 0 && bad < 16) || (s.frame - 1) % 1500 == 0))
        return;
    int first_bad = r == 0 && bad++ == 0;
    unsigned want = 0;
    int have = hulk_replay_expected_hash(s.frame - 1, &want);
    u32 posts, steps, blocked;
    ff_io_stats(&posts, &steps, &blocked);
    log_line("ckpt frame %u hash %08x recording %s%08x %s (io posts %u waits %u timeouts %u, sound rng %u)", s.frame - 1,
             s.last_hash, have ? "" : "(none) ", want, r ? "ok" : "DIVERGED", posts, steps, blocked, g_snd_calls);
    log_line("prng frame %u hash %08x recording %s%08x %s", s.frame - 1, ph, phave ? "" : "(none) ", pwant,
             !phave || pwant == ph ? "ok" : "DIVERGED");
    if (logged == 0 || first_bad || regions) {
        const u32* g = (const u32*)st.rng;
        const void* cam = *st.camera_ptr;
        log_line("ckpt regions: rng %08x %08x boot %u camera %08x", g[0], g[1], *(const u32*)st.boot_step,
                 (u32)(uintptr_t)cam);
        if (cam) {
            const u32* p = (const u32*)((const char*)cam + 0x4c);
            log_line("ckpt camera+0x4c: %08x %08x %08x", p[0], p[1], p[2]);
        }
        const u32* c = (const u32*)PTR(clock + 0x10);
        log_line("ckpt clock+0x10: %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x", c[0], c[1], c[2], c[3],
                 c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11]);
    }
    logged++;
}

extern "C" int ff_replay_active(void) { return replay_open(0); }
extern "C" uint32_t ff_replay_frame(void) { return g_frame_no; }
extern "C" void ff_replay_log(const char* line) { log_line("%s", line); }

// entry 0x00086450 GameClock::Update (`this` in ecx): the drives settle (lockstep I/O), then the checkpoint
FFH(hulk_nhook_clock_update) {
    ff_io_main_sleep();
    frame(ecx);
    ffgo_00086450(ecx, edx, st, rb);
}

// ---------------------------------------------------------------------------------------------------------------
// entry 0x00269170 (request C): with a recording open the poll's rate limit goes: the last poll time (+0x12a4) is
// set to `now - interval` (+0x12a0); `now` is core::GetMilliseconds 0x00267f80, the function's own read
FFH(hulk_nhook_pad_poll) {
    if (ecx && replay_open(0)) {
        u32 now = ff_call(0x00267f80u, 0);
        *(u32*)PTR(ecx + 0x12a4) = now - *(u32*)PTR(ecx + 0x12a0);
    }
    ffgo_00269170(ecx, edx, st, rb);
}

// no-fmv (tweak bit 1): CFMVManager::QueueMovie 0x001b7310 queues nothing; the FMV render 0x001b7d10, when it has a
// movie (+0xc) and is not paused (+8), takes its "status 0: finished" path: 0x00333ef0, then the stop 0x001b7970
static int no_fmv(void) {
    HulkReplayInfo ri;
    return replay_open(&ri) && (ri.tweaks & 2);
}
FFH(hulk_nhook_fmv_queue) {
    if (no_fmv())
        return;
    ffgo_001b7310(ecx, edx, st, rb);
}
FFH(hulk_nhook_fmv_render) {
    if (ecx && no_fmv() && *(u32*)PTR(ecx + 0xc) && !*(uint8_t*)PTR(ecx + 8)) {
        ff_call(0x00333ef0u, 0);
        ff_call_this(0x001b7970u, ecx, 0);
        return;
    }
    ffgo_001b7d10(ecx, edx, st, rb);
}

// ---------------------------------------------------------------------------------------------------------------
// the new-game reseed (site 0x00086630 -> core::GetMicroseconds 0x00267f00): the recording's seed
FFH(hulk_replay_seed) {
    HOOK_UNUSED;
    HulkReplayInfo ri;
    if (replay_open(&ri)) {
        RET(ri.seed);
        return;
    }
    uint32_t a[4] = {0};
    uint64_t r[2] = {0};
    ff_dispatch(0x00267f00u, 0, 0, a, r);
    RET64(r[0]);
}

// sound-rng: the sound code's calls of the RNG accessor 0x000964d0 get a private MWC state, audio sequencing's rand()
// a private LCG; seq-rng: the sequencer's RandInt (0x000113e0) steps the same private state
FFH(hulk_sound_rng) {
    HOOK_UNUSED;
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & HULK_RF_SOUND_RNG)) {
        g_snd_calls++;
        RET((u32)(uintptr_t)g_snd_rng);
        return;
    }
    RET(ff_call(0x000964d0u, 0));
}
FFH(hulk_sound_rand) {
    HOOK_UNUSED;
    HulkReplayInfo ri;
    if (replay_open(&ri) && (ri.flags & HULK_RF_SOUND_RNG)) {
        g_snd_rand = g_snd_rand * 214013u + 2531011u;
        RET((g_snd_rand >> 16) & 0x7fffu);
        return;
    }
    RET(ff_call(0x0034774cu, 0));
}
FFH(hulk_seq_randint) {
    HOOK_UNUSED;
    int lo = (int)ARG(0), hi = (int)ARG(1);
    HulkReplayInfo ri;
    if (!(replay_open(&ri) && (ri.flags & HULK_RF_SEQ_RNG))) {
        RET(ff_call(0x000113e0u, 2, (u32)lo, (u32)hi));
        return;
    }
    u32* s = g_snd_rng;
    s[0] = 36969u * (s[0] & 0xFFFFu) + (s[0] >> 16);
    s[1] = 18000u * (s[1] & 0xFFFFu) + (s[1] >> 16);
    u32 r = (s[0] << 16) + (s[1] & 0xFFFFu);
    RET(r % (u32)(hi - lo + 1) + (u32)lo);
}
