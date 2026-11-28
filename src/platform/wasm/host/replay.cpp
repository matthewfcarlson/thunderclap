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
extern "C" int ff_ring_resim(void);       // ring.c: frames simulated again after a rollback write nothing (wroll2)
static void out_write(OutFile& o, const void* p, uint32_t n) {
    if (ff_ring_resim())
        return;
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
static void seg_trailer_load(const char* path);
static int replay_open(HulkReplayInfo* ri) {
    if (g_open < 0) {
        g_open = 0;
        const char* src = getenv("HULK_INPUT_SOURCE");
        const char* path = src && strncmp(src, "replay:", 7) == 0 ? src + 7 : 0;
        if (!path && getenv("HULK_RECORD_BASE") && *getenv("HULK_RECORD_BASE"))
            path = getenv("HULK_RECORD_BASE");      // a playthrough session's base (below: "Playthroughs")
        if (path) {
            if (hulk_replay_open(path))
                g_open = hulk_replay_info(&g_info) ? 1 : 0;
            else
                ff_fatal("%s", hulk_replay_error());
            if (g_open)
                seg_trailer_load(path);
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
static void rec_live_pad(uint8_t* b);
static void poll_clock(void);
static void clock_rule_update(void);
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
    if (!init && port == 0)
        rec_live_pad(b);                                // a playthrough's live segment: the player's pad, recorded
    if (!init)
        poll_clock();
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
// playthroughs: the clock rule in waits (0 none: replays of play3; 1 and 2 below), main-thread reads and the
// recording's polls since the last update (or, rule 2's reads, since the last poll or frame end)
static u32 g_pt_clock, g_vreads, g_vpolls0;
static const u32 kStallReads = 20000, kStallPolls = 200, kSpinReads = 100000;
static const u64 kStallStepUs = 1000ull;
static const u32 kClockRule = 2;          // the rule new segments are recorded with
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
    else if (g_pt_clock == 1 && SIM->cur_thread == g_vmain && ++g_vreads > kStallReads) {
        // a playthrough's segments of rule 1 (wplay4 v2, 6b1b2ea4c..): the main thread waiting on the clock between
        // updates (a save's or load's minimum message time) sees it move on 1 ms a read past the first kStallReads;
        // the next update takes the time from there (g_vextra). The reads are not the same count with every
        // renderer (the game's own d3d layer reads the clock at presents; the pddi front end replaces it), so a
        // rule-1 segment replays only with the renderer it was recorded with. Replays of play3 never get here.
        if (g_vreads == kStallReads + 1)
            log_line("playthrough: the clock moves on in a wait at frame %u", g_frame_no);
        g_vt += kStallStepUs;
        g_vextra += kStallStepUs;
    } else if (g_pt_clock == 2 && SIM->cur_thread == g_vmain && ++g_vreads > kSpinReads) {
        // rule 2, a wait that neither polls the pad nor presents: 1 ms a read past kSpinReads (the count restarts at
        // each poll and frame end, so the d3d layer's reads at presents are never in it)
        if (g_vreads == kSpinReads + 1)
            log_line("playthrough: the clock moves on in a spin at frame %u", g_frame_no);
        g_vt += kStallStepUs;
        g_vextra += kStallStepUs;
    }
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
    g_vreads = 0;
    g_vpolls0 = g_rp.polls;
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
    if (dumping)   /* a dump window probes every tag at every frame (the Wine host's replay_hooks does the same for its dumps) */
        mask |= HULK_PROBE_FULL_MASK;
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

// the semantic probe's every tag as one 64-bit digest (wnet1: co-op peers compare it, gfx/netplay.c): what the replay
// records hold (the flow, clock, RNG, the main actor, the logic view, every actor, the mission), not render
// bookkeeping, which differs between co-op peers whose pictures follow other Hulks. At GameClock::Update's entry.
extern "C" uint64_t ff_probe_digest(u32 clock) {
    HulkProbeInputs in;
    memset(&in, 0, sizeof(in));
    unsigned char pb[HULK_PRNG_BYTES];
    memcpy(pb, PTR(0x00554be4u), HULK_PRNG_BYTES);
    in.rng = PTR(0x004e5ad0u);
    in.boot_step = PTR(0x0049fb40u);
    in.view_ptr = (const void* const*)PTR(0x004e231cu);
    in.clock = PTR(clock);
    in.clock_at_entry = 1;
    in.prng = pb;
    in.snd_rng = g_snd_rng;
    in.snd_rand = &g_snd_rand;
    in.world_ptr = (const void* const*)PTR(0x004dd700u);
    in.actor_of = probe_actor_of;
    in.position_of = probe_position_of;
    HulkProbeRecord rec;
    hulk_probe_frame(g_frame_no, &in, HULK_PROBE_CHEAP_MASK | HULK_PROBE_FULL_MASK, &rec, 0, 0);
    u64 h = 0xcbf29ce484222325ull;
    for (int t = 0; t < HULK_PT_COUNT; t++)
        if ((rec.mask >> t & 1) && !(rec.unavailable >> t & 1))
            h = (h ^ ((u64)t << 32 | rec.exact[t])) * 0x100000001b3ull;
    return h;
}

static unsigned logged, bad;     // (frame()'s log counts: kept by playthrough snapshots)
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
extern "C" void ff_coop_update(u32 clock) __attribute__((weak));   // gfx/netplay.c (the app): co-op's label, digest
FFH(hulk_nhook_clock_update) {
    ff_io_main_sleep();
    frame(ecx);
    if (ff_coop_update)
        ff_coop_update(ecx);
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

// ---------------------------------------------------------------------------------------------------------------
// Playthroughs (wplay4, D244; docs/playthrough.md, tools/playthrough.py): a player's session recorded onto the end of
// a recording, so recordings chain into one whole-game replay. Everything stays under replay rules (the virtual
// clock, the sound code's private generators, lockstep I/O, no-fmv, settings pinned), so a session is a function of
// its recording alone; only the pad and the voices' clock change at the hand-off.
//
//   HULK_RECORD_BASE=FILE.hrp  the recording to start from (as HULK_INPUT_SOURCE=replay:FILE.hrp does)
//   HULK_RECORD=PREFIX         a session: at the base's end the player takes over. Pad 0 then comes from the runner
//                              (the sim block's pad, as in free play) and every change is appended to PREFIX.inputs
//                              as .hrp entries keyed by poll; PREFIX.seg holds the segment's start and end (rewritten
//                              every 30 presents and at the end). On a quit request the state is written to
//                              PREFIX.snap at the next frame end and the app exits.
//   HULK_SNAP_AT_HANDOFF=FILE  (no HULK_RECORD) replay the base to its end, write the state there, exit
//   HULK_RESTORE=FILE          put a snapshot back at the first frame end (all fibers suspended, sched.c)
//   HULK_RECORD_FROM=N         hand off at GameClock frame N instead of the base's end (tests: short segments)
//   HULK_RECORD_UNTIL=N        end the session at frame N as a quit would (scripted sessions, tests)
//   HULK_DS_LIVE_WORK=N        output frames a DirectSoundDoWork after the hand-off (default 533; see below)
//
// The base's end: the end of its last segment (its SEG1 trailer, below), or for a plain recording such as play3 the
// first frame end at which its last input is in effect. Boundaries are frame ends, where every fiber is suspended at
// the same point: the first at or after a (GameClock frame, poll); a segment is {start, end} of (present, frame, poll),
// the present kept for information only (its count differs between renderers).
// The voices: replays advance them 800 output frames a DoWork (the Wine mixer's clock the recordings were checked
// with; ~1.5x the console's rate), which would make the player's sound run fast; from the first segment's start they
// advance ds_live_work frames a DoWork (533: the game calls DoWork about three times an update, 1,600 frames of 48 kHz
// at 30 updates a second). The number is in the SEG1 trailer, so a replay of the playthrough does the same.
// .hrp trailer (after PRN1 when present): "SEG1", u32 version 1, u32 n, u32 ds_live_work, n x {u32 start_present,
// start_frame, start_polls, end_present, end_frame, end_polls}.
struct SegInfo {
    u32 start_present, start_frame, start_polls, end_present, end_frame, end_polls, clock_rule;
};
#define MAX_SEGS 256
static SegInfo g_segs[MAX_SEGS];
static u32 g_nsegs, g_seg_ds_work;
static void seg_trailer_load(const char* path) {
    size_t n = 0;
    unsigned char* d = (unsigned char*)hulk_wasm_load_file(path, &n);
    if (!d)
        return;
    if (n >= 36 && !memcmp(d, "HRP1", 4)) {
        size_t at = 36 + (size_t)rd32(d + 28) * 24 + (size_t)rd32(d + 32) * 8;
        if (at + 8 <= n && !memcmp(d + at, "PRN1", 4))
            at += 8 + (size_t)rd32(d + at + 4) * 8;
        u32 ver = at + 16 <= n && !memcmp(d + at, "SEG1", 4) ? rd32(d + at + 4) : 0;
        if (ver == 1 || ver == 2) {                 // (version 1: no clock rule word, every segment rule 1)
            u32 k = rd32(d + at + 8), w = ver == 1 ? 24 : 28;
            g_seg_ds_work = rd32(d + at + 12);
            at += 16;
            for (u32 i = 0; i < k && i < MAX_SEGS && at + w <= n; i++, at += w) {
                const unsigned char* q = d + at;
                g_segs[i] = SegInfo{rd32(q), rd32(q + 4), rd32(q + 8), rd32(q + 12), rd32(q + 16), rd32(q + 20),
                                    ver == 1 ? 1u : rd32(q + 24)};
                g_nsegs = i + 1;
            }
        }
    }
    free(d);
}

// the session's state that is game-facing (kept by snapshots: ff_replay_blob)
static struct {
    u32 live;                      // the player has the pad
    u32 start_present, start_frame, start_polls;   // this segment's start
    u32 entries;                   // entries appended to PREFIX.inputs (this process)
    u32 have_last;
    uint8_t last[18];              // the last appended pad
    u32 ds_switched;               // the voices' clock is the live one
} g_rec;
static int g_rec_mode = -1;        // 1: HULK_RECORD; 2: HULK_SNAP_AT_HANDOFF
static int32_t g_rec_fd = -1, g_seg_fd = -1;
static u32 g_rec_from, g_rec_until;
static int g_quit_pending, g_restore_pending, g_snap_pending, g_restored;
static u32 g_ds_live_work = 533;

extern "C" void hulk_app_live(void) __attribute__((weak));   // gfx/gfx.c: pacing on, the mixer from the model
extern "C" u32 ff_ds_works;                                  // dsound_null.c (statistics)
extern "C" int ff_snap_write(const char* path);              // sched.c
extern "C" int ff_snap_read(const char* path);
extern "C" void ff_audio_restored(void) __attribute__((weak));

static int rec_mode(void) {
    if (g_rec_mode < 0) {
        g_rec_mode = 0;
        const char* r = getenv("HULK_RECORD");
        const char* h = getenv("HULK_SNAP_AT_HANDOFF");
        if (replay_open(0) && r && *r)
            g_rec_mode = 1;
        else if (replay_open(0) && h && *h)
            g_rec_mode = 2;
        const char* f = getenv("HULK_RECORD_FROM");
        if (f && *f)
            g_rec_from = (u32)strtoul(f, 0, 10);
        const char* u = getenv("HULK_RECORD_UNTIL");
        if (u && *u)
            g_rec_until = (u32)strtoul(u, 0, 10);
        const char* w = getenv("HULK_DS_LIVE_WORK");
        if (w && *w && strtoul(w, 0, 10) >= 100 && strtoul(w, 0, 10) <= 2400)
            g_ds_live_work = (u32)strtoul(w, 0, 10);
        if (g_nsegs && g_seg_ds_work)
            g_ds_live_work = g_seg_ds_work;
        const char* rs = getenv("HULK_RESTORE");
        g_restore_pending = rs && *rs && replay_open(0);
    }
    return g_rec_mode;
}
static const char* rec_path(char* out, size_t cap, const char* suffix) {
    snprintf(out, cap, "%s%s", getenv("HULK_RECORD"), suffix);
    return out;
}
static void seg_write(void) {
    if (g_rec_mode != 1 || !g_rec.live)
        return;
    if (g_seg_fd < 0) {
        char p[700];
        g_seg_fd = hio_open(rec_path(p, sizeof p, ".seg"), HIO_CREATE);
        if (g_seg_fd < 0)
            return;
    }
    char line[400];
    static u32 works0, frame0;
    if (!frame0 || g_frame_no < frame0)
        works0 = ff_ds_works, frame0 = g_frame_no;
    int n = snprintf(line, sizeof line,
                     "start present %010u frame %010u polls %010u\nend present %010u frame %010u polls %010u "
                     "entries %010u\nds_live_work %u restored %u dowork_per_frame %6.3f clock_rule %u\n",
                     g_rec.start_present, g_rec.start_frame, g_rec.start_polls, SIM->frame, g_frame_no, g_rp.polls,
                     g_rec.entries, g_ds_live_work, (u32)g_restored,
                     g_frame_no > frame0 ? (double)(ff_ds_works - works0) / (g_frame_no - frame0) : 0.0, kClockRule);
    if (n > 0)
        hio_write(g_seg_fd, line, (uint32_t)n, 0);
}
static void rec_append(const uint8_t* b) {
    if (g_rec_fd < 0) {
        char p[700];
        g_rec_fd = hio_open(rec_path(p, sizeof p, ".inputs"), HIO_CREATE);
        if (g_rec_fd < 0)
            ff_fatal("playthrough: cannot write %s", p);
    }
    unsigned char e[24];
    u32 key = g_rp.polls;
    memcpy(e, &key, 4);
    memcpy(e + 4, b, 18);              // buttons (u16), analog[8], thumb[4] (s16): the .hrp entry's order
    e[22] = e[23] = 0;
    hio_write(g_rec_fd, e, 24, g_rec.entries * 24);
    g_rec.entries++;
    memcpy(g_rec.last, b, 18);
    g_rec.have_last = 1;
}
// the pad the game reads at a poll in a live segment: the sim block's (the runner's, or HULK_INPUT's), recorded
static void rec_live_pad(uint8_t* b) {
    if (!g_rec.live || g_rec_mode != 1)
        return;
    memcpy(b, SIM->pads[0], 18);
    if (!g_rec.have_last || memcmp(b, g_rec.last, 18))
        rec_append(b);
}
static void ds_live(void) {
    if (g_rec.ds_switched)
        return;
    g_rec.ds_switched = 1;
    SIM->ds_clock = g_ds_live_work;    // (dsound_null.c: a value above 1 is the frames a DoWork)
}
static void go_live(void) {
    g_rec.live = 1;
    g_rec.start_present = SIM->frame;
    g_rec.start_frame = g_frame_no;
    g_rec.start_polls = g_rp.polls;
    g_rec.have_last = 0;
    g_rec.entries = 0;
    ds_live();
    clock_rule_update();                // (this build's rule from the hand-off itself, as a replay takes it there)
    log_line("playthrough: live from present %u (frame %u, poll %u)%s", SIM->frame, g_frame_no, g_rp.polls,
             g_restored ? " (restored)" : "");
    fprintf(stderr, "hulk: playthrough: the player has the pad from present %u (frame %u)\n", SIM->frame, g_frame_no);
    seg_write();
    if (hulk_app_live)
        hulk_app_live();
}
// a boundary: the first frame end at or after GameClock frame F and poll P (presents are not the same count with
// every renderer: the pddi front end's and d3d_null's differ in loads; updates and polls are the game's own)
static int at_point(u32 frame, u32 polls) { return g_frame_no >= frame && g_rp.polls >= polls; }
// the base's end reached at this frame end?
static int at_handoff(void) {
    if (g_rec_from)
        return g_frame_no >= g_rec_from;
    if (g_nsegs)
        return at_point(g_segs[g_nsegs - 1].end_frame, g_segs[g_nsegs - 1].end_polls);
    return g_rp.n && g_rp.pos == g_rp.n - 1 && g_rp.e[g_rp.pos].key <= g_rp.polls;
}
// the clock rule in effect (at frame ends): a live session's is this build's; a playthrough's replay takes each
// segment's from its start on; rule 2's spin count restarts at every frame end
static void clock_rule_update(void) {
    u32 r = g_pt_clock;
    if (g_rec.live)
        r = kClockRule;
    else
        for (u32 i = g_nsegs; i-- > 0;)
            if (at_point(g_segs[i].start_frame, g_segs[i].start_polls)) {
                r = g_segs[i].clock_rule;
                break;
            }
    if (r != g_pt_clock)
        log_line("playthrough: clock rule %u from frame %u", r, g_frame_no);
    g_pt_clock = r;
    if (g_pt_clock == 2)
        g_vreads = 0;
}
// rule 2 (wplay4): the recording's polls (renderer-independent: the recording is keyed by them) without an update:
// past kStallPolls, each poll moves the clock on 1 ms (the game's load and save waits poll the pad and read
// core::GetMilliseconds); a poll restarts the spin count
static void poll_clock(void) {
    if (g_pt_clock != 2)
        return;
    g_vreads = 0;
    u32 n = g_rp.polls - g_vpolls0;
    if (n <= kStallPolls)
        return;
    if (n == kStallPolls + 1)
        log_line("playthrough: the clock moves on in a wait at frame %u", g_frame_no);
    g_vt += kStallStepUs;
    g_vextra += kStallStepUs;
}
// gfx.c / d3d_null.c's frame end (sched.c ff_frame_checkpoint): 1 = stop every fiber here (a snapshot or a restore)
extern "C" int ff_playthrough_frame_end(void) {
    if (!replay_open(0))
        return 0;
    int mode = rec_mode();
    if (g_restore_pending)
        return 1;
    if (g_nsegs && !g_rec.ds_switched && at_point(g_segs[0].start_frame, g_segs[0].start_polls))
        ds_live();                                                  // a playthrough's replay: its segments' clock
    clock_rule_update();
    if (mode == 0)
        return 0;
    if (!g_rec.live && at_handoff()) {
        if (mode == 2) {
            g_snap_pending = 1;
            return 1;
        }
        go_live();
    }
    if (g_rec.live && SIM->frame % 30 == 0)
        seg_write();
    if (g_rec.live && g_rec_until && g_frame_no >= g_rec_until && !g_quit_pending)
        g_quit_pending = 1;                                     // (HULK_RECORD_UNTIL: a scripted session's end)
    return g_quit_pending == 1 || g_snap_pending;
}
// gfx.c's quit (the menu, the window, Cmd+Q): 1 = quit now; a live session first writes its snapshot
extern "C" int ff_playthrough_quit(void) {
    if (rec_mode() != 1 || !g_rec.live)
        return 1;
    if (!g_quit_pending) {
        g_quit_pending = 1;
        fprintf(stderr, "hulk: playthrough: saving the session at the next frame end\n");
    }
    return 0;
}
extern "C" int ff_replay_live(void) { return g_rec.live && g_rec_mode == 1; }
// the scheduler with every fiber suspended (sched.c, after each switch)
extern "C" void ff_playthrough_switch(void) {
    if (g_rec_mode <= 0 && !g_restore_pending)
        return;
    if (g_restore_pending) {
        g_restore_pending = 0;
        const char* p = getenv("HULK_RESTORE");
        u32 before = SIM->frame;
        if (!ff_snap_read(p))
            ff_fatal("playthrough: cannot restore %s (a snapshot of another build?)", p);
        g_restored = 1;
        log_line("playthrough: restored %s at present %u: now present %u (frame %u, poll %u)", p, before, SIM->frame,
                 g_frame_no, g_rp.polls);
        fprintf(stderr, "hulk: playthrough: restored present %u (frame %u)\n", SIM->frame, g_frame_no);
        if (g_rec_mode == 1 && !g_rec.live && at_handoff())
            go_live();
        else if (g_rec_mode == 1 && g_rec.live) {          // a new segment from the restored point
            g_rec.live = 0;
            go_live();
        }
        return;
    }
    if (g_snap_pending && g_rec_mode == 2) {
        const char* p = getenv("HULK_SNAP_AT_HANDOFF");
        if (!ff_snap_write(p))
            ff_fatal("playthrough: cannot write %s", p);
        log_line("playthrough: handoff snapshot %s at present %u (frame %u, poll %u)", p, SIM->frame, g_frame_no,
                 g_rp.polls);
        fprintf(stderr, "hulk: playthrough: handoff snapshot at present %u (frame %u, poll %u)\n", SIM->frame,
                g_frame_no, g_rp.polls);
        fflush(stderr);
        exit(0);
    }
    if (g_quit_pending == 1 && g_rec_mode == 1) {
        g_quit_pending = 2;
        char p[700];
        seg_write();
        int ok = ff_snap_write(rec_path(p, sizeof p, ".snap"));
        log_line("playthrough: end present %u (frame %u, poll %u), %u entries; snapshot %s", SIM->frame, g_frame_no,
                 g_rp.polls, g_rec.entries, ok ? "written" : "FAILED");
        fprintf(stderr, "hulk: playthrough: session ends at present %u (frame %u); snapshot %s\n", SIM->frame,
                g_frame_no, ok ? "written" : "FAILED");
        fflush(stderr);
        exit(0);
    }
}
// the replay's game-facing host state, for snapshots: copied out (restore 0) or back (1); returns the size
struct ReplayBlob {
    u32 frame_no, snd_calls, snd_rng[4], snd_rand, seq_rng_ptr, packet[4];
    uint8_t last[4][18];
    u64 dt_us, vt, vextra;
    int vflags;
    u32 vmain, vframe, logged, bad, pt_clock, vreads, vpolls0;
    unsigned rp_pos, rp_polls, rp_frame, rp_last_frame, rp_frozen, rp_rumbles;
    int rp_press_start_ok, rp_frame_seen;
    unsigned ck_interval;
    HulkCkptStats ck_st;
    unsigned char rec[sizeof(g_rec)];
};
extern "C" uint32_t ff_replay_blob(void* buf, int restore) {
    ReplayBlob& b = *(ReplayBlob*)buf;
    if (!restore) {
        memset(&b, 0, sizeof b);
        b.frame_no = g_frame_no, b.snd_calls = g_snd_calls, b.snd_rand = g_snd_rand, b.seq_rng_ptr = hulk_seq_rng_ptr;
        memcpy(b.snd_rng, g_snd_rng, sizeof g_snd_rng);
        memcpy(b.packet, g_packet, sizeof g_packet);
        memcpy(b.last, g_last, sizeof g_last);
        b.dt_us = g_dt_us, b.vt = g_vt, b.vextra = g_vextra, b.vflags = g_vflags, b.vmain = g_vmain;
        b.vframe = g_vframe, b.logged = logged, b.bad = bad, b.pt_clock = g_pt_clock, b.vreads = g_vreads;
        b.vpolls0 = g_vpolls0;
        b.rp_pos = g_rp.pos, b.rp_polls = g_rp.polls, b.rp_frame = g_rp.frame, b.rp_last_frame = g_rp.last_frame;
        b.rp_frozen = g_rp.frozen, b.rp_rumbles = g_rp.rumbles, b.rp_press_start_ok = g_rp.press_start_ok;
        b.rp_frame_seen = g_rp.frame_seen;
        ck_init();
        b.ck_interval = g_ck.interval;
        b.ck_st = g_ck.st;
        memcpy(b.rec, &g_rec, sizeof g_rec);
    } else {
        g_frame_no = b.frame_no, g_snd_calls = b.snd_calls, g_snd_rand = b.snd_rand, hulk_seq_rng_ptr = b.seq_rng_ptr;
        memcpy(g_snd_rng, b.snd_rng, sizeof g_snd_rng);
        memcpy(g_packet, b.packet, sizeof g_packet);
        memcpy(g_last, b.last, sizeof g_last);
        g_dt_us = b.dt_us, g_vt = b.vt, g_vextra = b.vextra, g_vflags = b.vflags, g_vmain = b.vmain;
        g_vframe = b.vframe, logged = b.logged, bad = b.bad, g_pt_clock = b.pt_clock, g_vreads = b.vreads;
        g_vpolls0 = b.vpolls0;
        g_rp.pos = b.rp_pos, g_rp.polls = b.rp_polls, g_rp.frame = b.rp_frame, g_rp.last_frame = b.rp_last_frame;
        g_rp.frozen = b.rp_frozen, g_rp.rumbles = b.rp_rumbles, g_rp.press_start_ok = b.rp_press_start_ok;
        g_rp.frame_seen = b.rp_frame_seen;
        g_ck.inited = 1;
        g_ck.interval = b.ck_interval;
        g_ck.st = b.ck_st;
        memcpy(&g_rec, b.rec, sizeof g_rec);
    }
    return sizeof(ReplayBlob);
}
