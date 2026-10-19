// Determinism and test hooks for the hybrid build (docs/tasks/10-hybrid-test-plan.md, docs/hybrid-build.md).
// Compiled with MSVC 7.1 like everything else and linked into the .hybrid section by tools/patch_xbe.py,
// which also redirects the original call sites listed in HOOK_SITES there:
//
//   GameClock::Update 0x86450:  call GetMicroseconds64 @0x8646e -> hybrid_clock_tick  (fixed dt, frame counter,
//                                                                                     checkpoints)
//   GameClock ctor    0x87e30:  call GetMicroseconds64 @0x87e40 -> hybrid_clock_now
//   ControllerXBox::vfunc_17:   call XInputGetState     @0x2685d9 -> hybrid_xinput_get_state (replay / record)
//   CGame::Tick 0x87630:        call GameClock::Update @0x876e5 -> hybrid_game_tick (notes CGame for the state)
//   0x86630 (new-game reseed):  call GetMicroseconds    @0x8668e -> mov eax, seed       (byte patch, no code)
//   with vpad:  ControllerSystemXBox/ControllerXBox device calls (patch_xbe.py VPAD_CALLS) -> hybrid_get_device_changes,
//               hybrid_xinput_open/_close/_set_state/_get_state_init (one virtual pad; docs/tasks/record-replay.md)
//   with vdate: core 0x267ad0's call GetLocalTime @0x267ad7 -> hybrid_get_local_time
//   with seq-rng: the audio sequencer's `mov ecx, [0x4e5acc]` (patch_xbe.py SEQ_RNG_SITES) -> &seq_rng_ptr
//
// All state lives in one struct, g_hybrid, whose address is in the build manifest. The host reads the
// checkpoint ring and the record buffer through QMP memsave (tools/hybrid_test.py) and writes the replay
// into the XBE at build time. Every field is a 32-bit word so tools/patch_xbe.py can address them by index.

#define HYBRID_MAGIC 0x48594231      /* 'HYB1' */
#define CKPT_RING 4096
#define INPUT_MAX 8192             // pad entries per ring (24 bytes each; keep in sync with tools/patch_xbe.py)
#define REGION_MAX 8
#define WIDE_PAGES 256
#define SKIP_MAX 32
#define RNGLOG_MAX 2048

struct Pad {                          // XINPUT_GAMEPAD plus the frame it applies from
    unsigned int frame;
    unsigned short buttons;
    unsigned char analog[8];
    short thumbs[4];
    unsigned short pad;
};

struct Ckpt {
    unsigned int frame;
    unsigned int hash;
};

struct Region {
    unsigned int addr;                // hashed every checkpoint; addr | 0x80000000 = dereference addr first
    unsigned int size;                // with a dereference, the high 16 bits are an offset into the object
};

struct HybridCtl {
    unsigned int magic;               // 0
    unsigned int flags;               // 1  HF_* below
    unsigned int dt_us;               // 2  fixed frame time in microseconds
    unsigned int frame;               // 3  GameClock updates so far
    unsigned int now_lo;              // 4  virtual clock (us)
    unsigned int now_hi;              // 5
    unsigned int ckpt_interval;       // 6  frames between checkpoints
    unsigned int ckpt_count;          // 7  checkpoints written (ring index = count % CKPT_RING)
    unsigned int replay_count;        // 8  entries in replay[]
    unsigned int replay_pos;          // 9
    unsigned int record_count;        // 10 entries recorded (record[] is a ring of INPUT_MAX)
    unsigned int polls;               // 11 XInputGetState calls seen
    unsigned int nregions;            // 12
    unsigned int base_us_lo;          // 13 virtual clock start (from the first real reading)
    unsigned int base_us_hi;          // 14
    unsigned int frozen_polls;        // 15 polls since the frame counter last moved (loading screens)
    Region regions[REGION_MAX];       // 16..31
    Ckpt ckpt[CKPT_RING];
    Pad replay[INPUT_MAX];
    Pad record[INPUT_MAX];
    // HF_WIDE: per-page hashes of [wide_lo, wide_hi) (.data + .bss by default), folded into each checkpoint
    // unless masked; a copy is kept at snap_frame so two runs can be compared page by page.
    unsigned int wide_lo, wide_hi, snap_frame, snap_taken;
    unsigned int mask[WIDE_PAGES / 32];
    unsigned int pages[WIDE_PAGES];
    unsigned int snap[WIDE_PAGES];
    // Extension (appended so the word indices above stay put; tools/patch_xbe.py CTL_EXT)
    unsigned int cgame;               // CGame (esi at CGame::Tick's call to GameClock::Update)
    unsigned int main_thread;         // KTHREAD (fs:[28h]) of the first pinned time read (HF_VCLOCK)
    unsigned int game_state;          // *(*(CGame+4)) at the last update
    unsigned int vt_lo, vt_hi;        // HF_VCLOCK: the virtual clock (us) every pinned time read returns
    unsigned int step_us;             // HF_VCLOCK: each main-thread time read between updates advances it this much
    unsigned int extra_us;            // reads x step_us since the last update
    unsigned int max_extra_us;        // the most any one frame saw (> dt_us: a loop outside the game loop ran long)
    unsigned int vreads;              // pinned time reads so far
    unsigned int pre_step_us;         // HF_VCLOCK: the same before the first update (default 4 ms)
    unsigned int pre_us;              // the clock at the first update (diagnostic; 0xffffffff: wrong main thread)
    unsigned int halt_frame;          // nonzero: the game loop waits at the start of this frame until the host
    unsigned int halted;              // clears halt_frame (for memory dumps at an exact frame); set while waiting
    unsigned int ndrives;             // core::DriveThread objects seen starting (hybrid_drive_thread_start)
    unsigned int drives[4];
    unsigned int io_waits;            // HF_IOSYNC: frames that waited for the drive threads
    unsigned int io_timeouts;         // ... and gave up after io_timeout_ms (the requests were still pending)
    unsigned int io_timeout_ms;
    unsigned int replay_avail;        // replay entries written so far (the host refills the ring past INPUT_MAX)
    unsigned int replay_starved;      // polls that waited for the host to refill it
    unsigned int snd_rng[4];          // HF_SOUND_RNG: the sound code's own MWC state (the game's is 0x4e5ad0)
    unsigned int snd_rand;            // HF_SOUND_RNG: and its own CRT rand() state
    unsigned int snd_rng_calls;       // diagnostic
    unsigned int nskip;               // HF_WIDE: byte ranges hashed as zeros (host-dependent words, wide-mask.json)
    Region skip[SKIP_MAX];
    // Second extension (tools/patch_xbe.py CTL_EXT2, EXT2_FIELDS): pad diagnostics and the virtual pad
    unsigned int poll_errors;         // polls where the real XInputGetState failed (the game was told so)
    unsigned int last_error;          // ... and the last such result
    unsigned int nhandles;            // distinct device handles the game polled (> 1: several pads, interleaved)
    unsigned int handles[4];
    unsigned int vpad_given;          // HF_VPAD: the virtual pad's insertion has been reported
    unsigned int real_pads[4];        // HF_VPAD, recording: the real pads the hooks opened, per port
    unsigned int real_errors;         // HF_VPAD, recording: failed reads of a real pad
    unsigned int real_active;         // HF_VPAD, recording: bit p = port p's pad has given input
    unsigned int vpad_count;          // HF_VPAD: virtual pads (ports 1..n; 0 = 1). Only port 1 plays when recording;
                                      // more replay the old recordings made with several pads bound
    unsigned int rumble[4][18];       // HF_VPAD, recording: XINPUT_FEEDBACK per real pad (rumble is forwarded)
    unsigned int seq_rng_ptr;         // seq-rng (a build-time patch, tools/patch_xbe.py SEQ_RNG_SITES): the audio
                                      // sequencer's random actions read their generator through this, = &snd_rng
    unsigned int rnglog_count;        // rng-log (diagnostic build patch): calls of the game's RNG accessors
    unsigned int rnglog[RNGLOG_MAX][2];   // ring of (return address | 0x80000000 for 0x964e0, frame)
};

#define HF_FIXED_DT 1
#define HF_REPLAY   2
#define HF_RECORD   4
#define HF_CKPT     8
#define HF_WIDE     32               // hash all of .data/.bss per page (see HybridCtl)
#define HF_AUTOSTART 16               // pulse START while the game loop is stalled (loading-screen "Press START")
#define HF_VCLOCK   128              // every core:: / Pure3D timer read returns the virtual clock (hybrid_qpc)
#define HF_IOSYNC   256              // each frame first waits until every DriveThread has no requests pending
#define HF_SOUND_RNG 512             // the sound code draws from its own random generators, not the game's
#define HF_QUANT    1024             // record mode: quantize the analog inputs the game is given (fewer pad changes)
#define HF_VDATE    4096             // the date (GetLocalTime) follows the virtual clock (hybrid_get_local_time)
#define HF_VPAD     2048             // the game sees one virtual pad in port 1 (see hybrid_get_device_changes)
#define HF_SYNCIO   8192             // the main thread waits after each drive-thread post until that drive is idle
#define HF_POLLKEY  64               // replay entries are keyed by pad polls instead of frames (tools/trace_capture.py:
                                     // after the new-game load the frame counter races, polls stay ~1 per frame)

static unsigned int s_last_frame;

// Recording a person: analog sticks and pressure buttons jitter by a few counts on every poll, which would
// log a pad change per frame. HF_QUANT snaps them to coarse steps with hysteresis (a value only moves to a
// new step once the raw reading is a full step away from the current one) and a centre dead zone, and the
// game is given the snapped values, so a replay of the recording is still exact. Steps are well below what
// the game can distinguish in play: 1/32 of stick travel, 1/8 of button pressure.
#define QUANT_STICK 1024
#define QUANT_DEAD  3072
#define QUANT_PRESS 32
static short s_q_thumb[4];
static unsigned char s_q_press[8];
static short quant_thumb(int i, short v)
{
    int cur = s_q_thumb[i];
    int raw = (v > -QUANT_DEAD && v < QUANT_DEAD) ? 0 : v;
    int d = raw - cur;
    if (d < 0) d = -d;
    if (d >= QUANT_STICK || raw == 0) {
        int q = raw >= 0 ? (raw + QUANT_STICK / 2) / QUANT_STICK * QUANT_STICK
                         : -((-raw + QUANT_STICK / 2) / QUANT_STICK * QUANT_STICK);
        if (q > 32767) q = 32767;
        if (q < -32768) q = -32768;
        s_q_thumb[i] = (short)q;
    }
    return s_q_thumb[i];
}
static unsigned char quant_press(int i, unsigned char v)
{
    int cur = s_q_press[i];
    int d = (int)v - cur;
    if (d < 0) d = -d;
    if (v < QUANT_PRESS / 2) s_q_press[i] = 0;
    else if (v > 255 - QUANT_PRESS / 2) s_q_press[i] = 255;
    else if (d >= QUANT_PRESS) s_q_press[i] = (unsigned char)((v + QUANT_PRESS / 2) / QUANT_PRESS * QUANT_PRESS);
    return s_q_press[i];
}

extern "C" HybridCtl g_hybrid = {
    HYBRID_MAGIC, HF_FIXED_DT | HF_CKPT, 33333, 0, 0, 0, 30, 0, 0, 0, 0, 0,
    3, 0, 0, 0,
    {
        {0x004E5AD0, 8},              // global MWC random generator state (seeded at 0x8669b)
        {0x0049FB40, 4},              // g_BootSequenceStep
        {0x804E231C, 0x4C000C},       // the camera (singleton 0x1c3d90): its position, 3 floats at +0x4c, is what
                                      // rm_GetCameraPosition (0x1b9260) returns; it follows the player
    },
    {0}, {0}, {0},
    0x0048CA80, 0x0056F8E0, 0, 0,     // .data (with its bss tail) of the original image
};

#define GS_PRESSSTART 3

static unsigned int game_state()
{
    if (!g_hybrid.cgame)
        return 0xFFFFFFFF;
    unsigned int st = *(unsigned int*)(g_hybrid.cgame + 4);
    return st ? *(unsigned int*)st : 0xFFFFFFFF;
}

typedef unsigned __int64 (__cdecl *ClockFn)();
typedef int (__stdcall *QpcFn)(unsigned int* out);
#define QueryPerformanceCounter ((QpcFn)0x00354CD1)
typedef void (__stdcall *SleepFn)(unsigned int ms);
#define XSleep ((SleepFn)0x0020C723)                       // XAPI Sleep (KeDelayExecutionThread)          // rdtsc; QueryPerformanceFrequency is 733,333,333
typedef unsigned long (__stdcall *XInputGetStateFn)(void* device, void* state);
#define GetMicroseconds64 ((ClockFn)0x00267F40)
#define XInputGetState ((XInputGetStateFn)0x003EB91F)

static unsigned int fnv(unsigned int h, const unsigned char* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        h = (h ^ p[i]) * 16777619u;
    return h;
}

// FNV-1a of [a, a + len), with the bytes in g_hybrid.skip read as zero
static unsigned int hash_page(unsigned int a, unsigned int len)
{
    bool any = false;
    for (unsigned int k = 0; k < g_hybrid.nskip && k < SKIP_MAX; k++)
        if (g_hybrid.skip[k].addr < a + len && a < g_hybrid.skip[k].addr + g_hybrid.skip[k].size)
            any = true;
    if (!any)
        return fnv(2166136261u, (const unsigned char*)a, len);
    unsigned int h = 2166136261u;
    for (unsigned int i = 0; i < len; i++) {
        unsigned int b = a + i;
        unsigned char c = *(const unsigned char*)b;
        for (unsigned int k = 0; k < g_hybrid.nskip && k < SKIP_MAX; k++)
            if (b - g_hybrid.skip[k].addr < g_hybrid.skip[k].size)
                c = 0;
        h = (h ^ c) * 16777619u;
    }
    return h;
}

static void checkpoint()
{
    unsigned int h = 2166136261u;
    h = fnv(h, (const unsigned char*)&g_hybrid.frame, 4);
    for (unsigned int i = 0; i < g_hybrid.nregions && i < REGION_MAX; i++) {
        unsigned int a = g_hybrid.regions[i].addr;
        unsigned int n = g_hybrid.regions[i].size;
        if (a & 0x80000000) {
            a = *(unsigned int*)(a & 0x7FFFFFFF);
            if (a == 0) continue;
            a += n >> 16;                         // pointers inside objects differ with the heap layout
            n &= 0xFFFF;
        }
        h = fnv(h, (const unsigned char*)a, n);
    }
    if (g_hybrid.flags & HF_WIDE) {
        unsigned int n = 0;
        for (unsigned int a = g_hybrid.wide_lo; a < g_hybrid.wide_hi && n < WIDE_PAGES; a += 0x1000, n++) {
            unsigned int len = g_hybrid.wide_hi - a < 0x1000 ? g_hybrid.wide_hi - a : 0x1000;
            unsigned int ph = hash_page(a, len);
            g_hybrid.pages[n] = ph;
            if (!(g_hybrid.mask[n >> 5] & (1u << (n & 31))))
                h = fnv(h, (const unsigned char*)&ph, 4);
        }
        if (g_hybrid.snap_frame && !g_hybrid.snap_taken && g_hybrid.frame >= g_hybrid.snap_frame) {
            for (unsigned int i = 0; i < n; i++)
                g_hybrid.snap[i] = g_hybrid.pages[i];
            g_hybrid.snap_taken = g_hybrid.frame;
        }
    }
    Ckpt& c = g_hybrid.ckpt[g_hybrid.ckpt_count % CKPT_RING];
    c.frame = g_hybrid.frame;
    c.hash = h;
    g_hybrid.ckpt_count++;
}

static unsigned __int64 virtual_now()
{
    if (g_hybrid.base_us_lo == 0 && g_hybrid.base_us_hi == 0) {
        unsigned __int64 t = GetMicroseconds64();
        g_hybrid.base_us_lo = (unsigned int)t | 1;
        g_hybrid.base_us_hi = (unsigned int)(t >> 32);
    }
    unsigned __int64 base = ((unsigned __int64)g_hybrid.base_us_hi << 32) | g_hybrid.base_us_lo;
    return base + (unsigned __int64)g_hybrid.frame * g_hybrid.dt_us;
}

#define VCLOCK_START_US 1000000u          // the virtual clock at the first read (1 s after "boot")
#define VCLOCK_BASE_US 300000000u         // and at the first game-loop update (300 s)

static unsigned __int64 vt()
{
    return ((unsigned __int64)g_hybrid.vt_hi << 32) | g_hybrid.vt_lo;
}

static void set_vt(unsigned __int64 t)
{
    g_hybrid.vt_lo = (unsigned int)t;
    g_hybrid.vt_hi = (unsigned int)(t >> 32);
}

static unsigned int current_thread()
{
    unsigned int t;
    __asm mov eax, fs:[28h]
    __asm mov t, eax
    return t;
}

// QueryPerformanceCounter at the call sites in core::GetMilliseconds/GetMicroseconds/GetMicroseconds64, 0x267aa0,
// core::TimerList, the Pure3D timer and d3dContext (tools/patch_xbe.py VCLOCK_SITES). With HF_VCLOCK, after the
// first GameClock update, they all read the virtual clock: the controller poll rate limit, script and sound
// timers, loading-screen pacing and every per-frame time budget then depend on frames, not on the host. Between
// updates the clock stands still: loops outside the game loop (the loading screens) run a host-dependent number
// of times, so time that advanced per read there would not replay (step_us > 0 makes every main-thread read
// advance it anyway, for experiments). Bink and DirectSound keep the real counter.
extern "C" int __stdcall hybrid_qpc(unsigned int* out)
{
    if (!(g_hybrid.flags & HF_VCLOCK))
        return QueryPerformanceCounter(out);
    if (!g_hybrid.main_thread) {                  // the first read: the game's own init, on the main thread
        g_hybrid.main_thread = current_thread();
        set_vt(VCLOCK_START_US);
    }
    if (current_thread() == g_hybrid.main_thread) {
        if (g_hybrid.frame == 0) {                // before the game loop: the copyright screen waits 3 s
            set_vt(vt() + g_hybrid.pre_step_us);
        } else {
            set_vt(vt() + g_hybrid.step_us);
            g_hybrid.extra_us += g_hybrid.step_us;
        }
    }
    g_hybrid.vreads++;
    // ticks = us * 733.333... = us * 733 + us / 3 (64-bit, no CRT helpers)
    unsigned int lo = g_hybrid.vt_lo, hi = g_hybrid.vt_hi, rlo, rhi;
    __asm {
        mov eax, lo
        mov ecx, 733
        mul ecx
        mov rlo, eax
        mov rhi, edx
        mov eax, hi
        imul eax, eax, 733
        add rhi, eax
        mov ecx, 3
        xor edx, edx
        mov eax, hi
        div ecx
        add rhi, eax
        mov eax, lo
        div ecx
        add rlo, eax
        adc rhi, 0
    }
    out[0] = rlo;
    out[1] = rhi;
    return 1;
}

// GameClock ctor: the clock's first timestamp.
extern "C" unsigned __int64 __cdecl hybrid_clock_now()
{
    if (!(g_hybrid.flags & HF_FIXED_DT))
        return GetMicroseconds64();
    if (g_hybrid.flags & HF_VCLOCK)
        return VCLOCK_BASE_US - g_hybrid.dt_us;
    return virtual_now();
}

// GameClock::Update, once per main-loop iteration: one fixed step per call.
extern "C" unsigned __int64 __cdecl hybrid_clock_tick()
{
    unsigned int clock;
    __asm mov clock, ecx                  // GameClock::Update's `this`, still in ecx at the call
    if (g_hybrid.frame == 0 && g_hybrid.nregions < REGION_MAX) {
        // GameClock accumulated real/scaled time, dt and time scale (docs/subsystems.md section 3)
        g_hybrid.regions[g_hybrid.nregions].addr = clock + 0x10;
        g_hybrid.regions[g_hybrid.nregions].size = 0x30;
        g_hybrid.nregions++;
    }
    g_hybrid.game_state = game_state();
    if (g_hybrid.halt_frame && g_hybrid.frame == g_hybrid.halt_frame) {
        *(volatile unsigned int*)&g_hybrid.halted = g_hybrid.frame;
        while (*(volatile unsigned int*)&g_hybrid.halt_frame == g_hybrid.frame)
            ;
        *(volatile unsigned int*)&g_hybrid.halted = 0;
    }
    if ((g_hybrid.flags & HF_CKPT) && g_hybrid.ckpt_interval && g_hybrid.frame % g_hybrid.ckpt_interval == 0)
        checkpoint();
    g_hybrid.frame++;
    if (!(g_hybrid.flags & HF_FIXED_DT))
        return GetMicroseconds64();
    if (g_hybrid.flags & HF_VCLOCK) {
        unsigned __int64 t;
        if (g_hybrid.frame == 1) {
            // Before the game loop, every main-thread read advanced the clock by pre_step_us, and how many reads
            // the loading code makes depends on the host. The loop starts at a fixed time instead.
            g_hybrid.pre_us = g_hybrid.vt_lo;
            if (current_thread() != g_hybrid.main_thread)
                g_hybrid.pre_us = 0xFFFFFFFF;     // the first read wasn't the main thread's: vclock is wrong
            t = VCLOCK_BASE_US;
            if (vt() >= t)
                t = vt() + 1;
        } else {
            // one dt per update, unless the reads since the last update already took the clock further
            t = vt() - g_hybrid.extra_us + g_hybrid.dt_us;
            if (g_hybrid.extra_us >= g_hybrid.dt_us)
                t = vt() + 1;
        }
        if (g_hybrid.extra_us > g_hybrid.max_extra_us)
            g_hybrid.max_extra_us = g_hybrid.extra_us;
        g_hybrid.extra_us = 0;
        set_vt(t);
        return t;
    }
    return virtual_now();
}

// ---------------------------------------------------------------------------------------------
// HF_VPAD: a virtual pad. Without it the game polls every pad xemu has bound, one ControllerXBox::vfunc_17
// call each per round, and the poll counter that recordings are keyed by counts them all. A recording made with
// the keyboard in port 1 and a gamepad auto-bound to port 2 then interleaves the two pads poll by poll, and
// replays on a host with another set of pads (or one that enumerates them later) are off from the first input.
// With HF_VPAD the game sees exactly one pad (vpad_count), in port 1, inserted at its first device check, on every host:
// XGetDeviceChanges/XInputOpen/XInputClose/XInputSetState and the XInputGetState calls are redirected here.
// Recording, the hooks open every real pad themselves and give the game their merged state (any pad plays);
// rumble is forwarded to them. Replaying, no real pad is touched. Every read succeeds.
#define VPAD_BASE 0x56504144u             // 'DAPV': the virtual pads' handles are VPAD_BASE + port
#define VPAD ((void*)VPAD_BASE)
static bool is_vpad(void* h)
{
    return (unsigned int)h - VPAD_BASE < 4;
}

static unsigned int vpad_count()
{
    unsigned int n = g_hybrid.vpad_count;
    return n == 0 ? 1 : n > 4 ? 4 : n;
}
#define XINPUT_STATE_BYTES 22
#define ERROR_IO_PENDING 997
typedef int (__stdcall *XGetDeviceChangesFn)(void* type, unsigned long* ins, unsigned long* rem);
typedef void* (__stdcall *XInputOpenFn)(void* type, unsigned long port, unsigned long slot, void* params);
typedef void (__stdcall *XInputCloseFn)(void* h);
typedef unsigned long (__stdcall *XInputSetStateFn)(void* h, void* feedback);
#define XGetDeviceChanges ((XGetDeviceChangesFn)0x003EBAA3)
#define XInputOpen ((XInputOpenFn)0x003EB6E5)
#define XInputClose ((XInputCloseFn)0x003EB73B)
#define XInputSetState ((XInputSetStateFn)0x003EB992)

static bool vpad_real()                   // recording a person: the hooks read the real pads
{
    return (g_hybrid.flags & (HF_VPAD | HF_REPLAY)) == HF_VPAD;
}

// ControllerSystemXBox (0x2691f0), every pad update: XGetDeviceChanges(XDEVICE_TYPE_GAMEPAD, &ins, &rem)
extern "C" int __stdcall hybrid_get_device_changes(void* type, unsigned long* ins, unsigned long* rem)
{
    if (!(g_hybrid.flags & HF_VPAD))
        return XGetDeviceChanges(type, ins, rem);
    if (vpad_real()) {
        unsigned long ri = 0, rr = 0;
        if (XGetDeviceChanges(type, &ri, &rr)) {
            for (unsigned int p = 0; p < 4; p++) {
                unsigned long bit = 1ul << p;
                if (((ri | rr) & bit) && g_hybrid.real_pads[p]) {
                    XInputClose((void*)g_hybrid.real_pads[p]);
                    g_hybrid.real_pads[p] = 0;
                }
                if (ri & bit) {
                    g_hybrid.real_pads[p] = (unsigned int)XInputOpen(type, p, 0, 0);
                    for (int i = 0; i < 18; i++)
                        g_hybrid.rumble[p][i] = 0;
                }
            }
        }
    }
    *ins = g_hybrid.vpad_given ? 0 : (1ul << vpad_count()) - 1;
    *rem = 0;
    g_hybrid.vpad_given = 1;
    return *ins != 0;
}

extern "C" void* __stdcall hybrid_xinput_open(void* type, unsigned long port, unsigned long slot, void* params)
{
    if (!(g_hybrid.flags & HF_VPAD))
        return XInputOpen(type, port, slot, params);
    return port < vpad_count() ? (void*)(VPAD_BASE + port) : 0;
}

extern "C" void __stdcall hybrid_xinput_close(void* h)
{
    if (!is_vpad(h))
        XInputClose(h);
}

// Rumble (ControllerXBox::vfunc_17). The game waits while a request's status is ERROR_IO_PENDING, which real
// hardware clears in real time; the virtual pad completes at once and passes the motor speeds on to the real
// pads when they are free.
extern "C" unsigned long __stdcall hybrid_xinput_set_state(void* h, unsigned char* feedback)
{
    if (!is_vpad(h))
        return XInputSetState(h, feedback);
    *(unsigned int*)feedback = 0;                     // Header.dwStatus: done
    if (vpad_real() && h == VPAD) {
        for (unsigned int p = 0; p < 4; p++) {
            unsigned int* fb = g_hybrid.rumble[p];
            if (!g_hybrid.real_pads[p] || *(volatile unsigned int*)fb == ERROR_IO_PENDING)
                continue;
            for (int i = 0; i < 18; i++)
                fb[i] = 0;
            unsigned char* b = (unsigned char*)fb;
            for (int i = 0; i < 4; i++)                       // XINPUT_RUMBLE at +66: left, right motor
                b[66 + i] = feedback[66 + i];
            XInputSetState((void*)g_hybrid.real_pads[p], fb);
        }
    }
    return 0;
}

static short abs16(short v)
{
    return v < 0 ? (short)-v : v;
}

// The virtual pad's state: zero when replaying (the replay fills it in), else every real pad merged.
static unsigned long vpad_read(void* device, unsigned char* state)
{
    for (int i = 0; i < XINPUT_STATE_BYTES; i++)
        state[i] = 0;
    if (!vpad_real() || device != VPAD)
        return 0;
    unsigned char* pad = state + 4;
    for (unsigned int p = 0; p < 4; p++) {
        if (!g_hybrid.real_pads[p])
            continue;
        unsigned char s[XINPUT_STATE_BYTES + 2];
        for (int i = 0; i < XINPUT_STATE_BYTES; i++)
            s[i] = 0;
        if (XInputGetState((void*)g_hybrid.real_pads[p], s) != 0) {
            g_hybrid.real_errors++;
            continue;
        }
        unsigned char* q = s + 4;
        bool any = q[0] || q[1];
        *(unsigned short*)pad |= *(unsigned short*)q;
        for (int i = 2; i < 10; i++) {
            if (q[i] > pad[i])
                pad[i] = q[i];
            any = any || q[i] > 32;
        }
        short* th = (short*)(pad + 10);
        short* qt = (short*)(q + 10);
        for (int i = 0; i < 4; i++) {
            if (abs16(qt[i]) > abs16(th[i]))
                th[i] = qt[i];
            any = any || abs16(qt[i]) > 8000;
        }
        if (any)
            g_hybrid.real_active |= 1u << p;
    }
    return 0;
}

// ControllerSystemXBox's pad init (0x2692c0) reads the new pad once
extern "C" unsigned long __stdcall hybrid_xinput_get_state_init(void* device, unsigned char* state)
{
    if (!is_vpad(device))
        return XInputGetState(device, state);
    for (int i = 0; i < XINPUT_STATE_BYTES; i++)
        state[i] = 0;
    return 0;
}

static void note_handle(void* device)
{
    unsigned int h = (unsigned int)device;
    for (unsigned int i = 0; i < g_hybrid.nhandles && i < 4; i++)
        if (g_hybrid.handles[i] == h)
            return;
    if (g_hybrid.nhandles < 4)
        g_hybrid.handles[g_hybrid.nhandles] = h;
    g_hybrid.nhandles++;
}

// core::ControllerXBox::vfunc_17's pad read. Replay overrides the gamepad; record logs changes.
extern "C" unsigned long __stdcall hybrid_xinput_get_state(void* device, unsigned char* state)
{
    unsigned long r = is_vpad(device) ? vpad_read(device, state) : XInputGetState(device, state);
    g_hybrid.polls++;
    note_handle(device);
    if (r != 0) {
        g_hybrid.poll_errors++;
        g_hybrid.last_error = r;
    }
    unsigned char* pad = state + 4;          // XINPUT_STATE.Gamepad (22 bytes total, 18 of pad)
    if (g_hybrid.flags & HF_REPLAY) {
        // replay[] is a ring: entries past INPUT_MAX are written by the host while the game runs
        // (tools/hybrid_test.py replay), up to replay_avail; replay_count is the whole recording
        unsigned int pos = g_hybrid.replay_pos;
        unsigned int key = (g_hybrid.flags & HF_POLLKEY) ? g_hybrid.polls : g_hybrid.frame;
        unsigned int avail = *(volatile unsigned int*)&g_hybrid.replay_avail;
        while (pos + 1 < g_hybrid.replay_count && pos + 1 >= avail) {    // the host is behind: wait for it
            g_hybrid.replay_starved++;
            XSleep(1);
            avail = *(volatile unsigned int*)&g_hybrid.replay_avail;
        }
        while (pos + 1 < g_hybrid.replay_count && pos + 1 < avail && g_hybrid.replay[(pos + 1) % INPUT_MAX].frame <= key)
            pos++;
        g_hybrid.replay_pos = pos;
        const unsigned char* src = 0;
        if (pos < g_hybrid.replay_count && g_hybrid.replay[pos % INPUT_MAX].frame <= key)
            src = (const unsigned char*)&g_hybrid.replay[pos % INPUT_MAX].buttons;
        for (int i = 0; i < 18; i++)
            pad[i] = src ? src[i] : 0;
        if (g_hybrid.frame != s_last_frame) {
            s_last_frame = g_hybrid.frame;
            g_hybrid.frozen_polls = 0;
        } else if (++g_hybrid.frozen_polls > 60 && (g_hybrid.flags & HF_AUTOSTART)
                   && (!g_hybrid.cgame || game_state() == GS_PRESSSTART)) {
            // the game loop is stalled (a loading screen): release everything, then tap START
            for (int i = 0; i < 18; i++)
                pad[i] = 0;
            if ((g_hybrid.frozen_polls >> 3) & 1)
                pad[0] = 0x10;                // XINPUT_GAMEPAD_START
        }
        r = 0;                                // with HF_RECORD too: record what the game was given
    }
    if ((g_hybrid.flags & HF_QUANT) && !(g_hybrid.flags & HF_REPLAY) && r == 0) {
        // pad: buttons (2 bytes), analog[8], thumbs[4] (LX, LY, RX, RY)
        for (int i = 0; i < 8; i++)
            pad[2 + i] = quant_press(i, pad[2 + i]);
        short* th = (short*)(pad + 10);
        for (int i = 0; i < 4; i++)
            th[i] = quant_thumb(i, th[i]);
    }
    if ((g_hybrid.flags & HF_RECORD) && r == 0) {
        // a ring: the host drains it while the game runs (tools/hybrid_test.py record); keyed like replays
        Pad* last = g_hybrid.record_count ? &g_hybrid.record[(g_hybrid.record_count - 1) % INPUT_MAX] : 0;
        bool same = last != 0;
        for (int i = 0; same && i < 18; i++)
            same = ((unsigned char*)&last->buttons)[i] == pad[i];
        if (!same) {
            Pad* p = &g_hybrid.record[g_hybrid.record_count % INPUT_MAX];
            p->frame = (g_hybrid.flags & HF_POLLKEY) ? g_hybrid.polls : g_hybrid.frame;
            for (int i = 0; i < 18; i++)
                ((unsigned char*)&p->buttons)[i] = pad[i];
            g_hybrid.record_count++;
        }
    }
    return r;
}

// core::DriveThread ctor 0x2733c0 starting its thread (call 0x26dce0 @0x273465, proc 0x2731d0, param this):
// note the DriveThread. Its +0x8c counts requests queued or being processed.
extern "C" __declspec(naked) void hybrid_drive_thread_start()
{
    __asm {
        mov eax, g_hybrid.ndrives
        cmp eax, 4
        jae full
        mov ecx, [esp + 12]
        mov g_hybrid.drives[eax * 4], ecx
        inc g_hybrid.ndrives
    full:
        mov eax, 0x0026DCE0
        jmp eax
    }
}

// HF_SYNCIO: the tail of core::DriveThread's post routine 0x272fc0 (pop edi; pop esi; ret 0xc at 0x27303f, edi =
// drive + 0xc) jumps here (tools/patch_xbe.py SYNCIO_SITE). With the flag, the main thread sleeps 1 ms at a time
// until that drive has nothing queued or running (+0x8c = 0), so every file request completes in the frame that
// made it, whatever the host's speed (docs/tasks/record-replay.md, "Snapshot resumes that diverged"). Counts the
// sleeps in io_waits and the waits given up after 2000 sleeps in io_timeouts (HF_IOSYNC, which also uses them,
// isn't set in recordings). Other threads and builds without the flag fall straight through to the original tail.
extern "C" __declspec(naked) void hybrid_syncio_tail()
{
    __asm {
        push eax
        push ecx
        push edx
        test g_hybrid.flags, HF_SYNCIO
        jz done
        mov eax, fs:[28h]
        cmp eax, g_hybrid.main_thread
        jne done
        mov ecx, 2000
    again:
        cmp dword ptr [edi + 0x80], 0
        je done
        dec ecx
        jz timeout
        push ecx
        push 1
        mov eax, 0x0020C723
        call eax
        pop ecx
        inc g_hybrid.io_waits
        jmp again
    timeout:
        inc g_hybrid.io_timeouts
    done:
        pop edx
        pop ecx
        pop eax
        pop edi
        pop esi
        ret 0Ch
    }
}

static unsigned int io_pending()
{
    unsigned int n = 0;
    for (unsigned int i = 0; i < g_hybrid.ndrives && i < 4; i++)
        n += *(volatile unsigned int*)(g_hybrid.drives[i] + 0x8c);
    return n;
}

// CGame::Tick's call to PumpPlatformServices (0x8763a), which delivers completed file requests to the game.
// With HF_IOSYNC it first waits for the drive threads, so a request made in one frame completes before the
// next frame's pump on every host (the DVD is emulated at host speed). Gives up after io_timeout_ms of real time.
extern "C" void __stdcall hybrid_pump_services()
{
    unsigned int pump;
    __asm mov pump, ecx
    if ((g_hybrid.flags & HF_IOSYNC) && io_pending()) {
        g_hybrid.io_waits++;
        unsigned int t0[2], t[2];
        QueryPerformanceCounter(t0);
        for (;;) {
            XSleep(0);
            if (!io_pending())
                break;
            QueryPerformanceCounter(t);
            unsigned int dt = t[0] - t0[0];                    // ticks; 733,333 per ms
            if (dt / 733333 >= g_hybrid.io_timeout_ms) {
                g_hybrid.io_timeouts++;
                break;
            }
        }
    }
    __asm {
        mov ecx, pump
        mov eax, 0x0008DB00
        call eax
    }
}

// The sound code (voice selection, variations; 0x1ef2a0 caches the pointer in 0x4e3758) draws from the game's
// global MWC generator (0x964d0 returns it), and audio sequencing (0x260ae0) from CRT rand(), which Lua's
// math.random shares. How many sounds start depends on how many voices are still playing, which the audio
// hardware decides in real time, so every draw shifted the gameplay sequence by a host-dependent amount.
// With HF_SOUND_RNG they get their own generators.
typedef unsigned int (__cdecl *GetRngFn)();
typedef int (__cdecl *RandFn)();
extern "C" unsigned int __cdecl hybrid_sound_rng()
{
    if (!(g_hybrid.flags & HF_SOUND_RNG))
        return ((GetRngFn)0x000964D0)();
    g_hybrid.snd_rng_calls++;
    return (unsigned int)&g_hybrid.snd_rng[0];
}

extern "C" int __cdecl hybrid_sound_rand()
{
    if (!(g_hybrid.flags & HF_SOUND_RNG))
        return ((RandFn)0x0034774C)();
    g_hybrid.snd_rand = g_hybrid.snd_rand * 214013 + 2531011;
    return (g_hybrid.snd_rand >> 16) & 0x7FFF;
}

// HF_VDATE: the wall-clock date. core 0x267ad0 is the game's only GetLocalTime (0x355364) caller: save-slot
// timestamps (0x8b560 via 0x89a60) and the audio sequencer's 64-bit event ids (0x263c90: date bits | microseconds).
// xemu's RTC follows the host, so these differed between a recording and its replays. With the flag the date is
// 2006-01-02 12:00 plus the virtual clock (hybrid_qpc), so a replay sees the same dates as its recording.
struct SystemTime { unsigned short year, month, dow, day, hour, minute, second, ms; };
typedef void (__stdcall *GetLocalTimeFn)(SystemTime* t);
#define GetLocalTime ((GetLocalTimeFn)0x00355364)
extern "C" void __stdcall hybrid_get_local_time(SystemTime* t)
{
    if (!(g_hybrid.flags & HF_VDATE)) {
        GetLocalTime(t);
        return;
    }
    // seconds and milliseconds of the virtual clock (64-bit / 1,000,000 without CRT helpers)
    unsigned int lo = g_hybrid.vt_lo, hi = g_hybrid.vt_hi, secs, rem;
    __asm {
        mov ecx, 1000000
        xor edx, edx
        mov eax, hi
        div ecx
        mov eax, lo
        div ecx
        mov secs, eax
        mov rem, edx
    }
    // 2006-01-02 (a Monday) 12:00:00 plus secs (the day wraps after four weeks of game time)
    unsigned int s = 12 * 3600 + secs;
    unsigned int days = s / 86400;
    s %= 86400;
    t->year = 2006;
    t->month = 1;
    t->day = (unsigned short)(2 + days % 28);
    t->dow = (unsigned short)((1 + days) % 7);
    t->hour = (unsigned short)(s / 3600);
    t->minute = (unsigned short)(s / 60 % 60);
    t->second = (unsigned short)(s % 60);
    t->ms = (unsigned short)(rem / 1000);
}

// rng-log (a diagnostic build, tools/patch_xbe.py RNGLOG_ENTRIES): the entries of the game's RNG accessors 0x964d0
// (returns the MWC state; callers step it inline) and 0x964e0 (a float in [0,1)) jump here; each call's return
// address and frame go to a ring, then the original runs.
extern "C" __declspec(naked) void hybrid_rnglog_get()
{
    __asm {
        push ecx
        mov eax, g_hybrid.rnglog_count
        and eax, RNGLOG_MAX - 1
        mov ecx, [esp + 4]
        mov dword ptr g_hybrid.rnglog[eax * 8], ecx
        mov ecx, g_hybrid.frame
        mov dword ptr g_hybrid.rnglog[eax * 8 + 4], ecx
        inc g_hybrid.rnglog_count
        pop ecx
        mov eax, dword ptr ds:[0x004E5ACC]
        ret
    }
}

extern "C" __declspec(naked) void hybrid_rnglog_float()
{
    __asm {
        push eax
        push ecx
        mov eax, g_hybrid.rnglog_count
        and eax, RNGLOG_MAX - 1
        mov ecx, [esp + 8]
        or ecx, 0x80000000
        mov dword ptr g_hybrid.rnglog[eax * 8], ecx
        mov ecx, g_hybrid.frame
        mov dword ptr g_hybrid.rnglog[eax * 8 + 4], ecx
        inc g_hybrid.rnglog_count
        pop ecx
        pop eax
        push ecx                              // 0x964e0's first two instructions, then the rest of it
        mov ecx, dword ptr ds:[0x004E5ACC]
        push 0x000964E7
        ret
    }
}

// rng-log: the entry trampolines of the functions that step the game's RNG inline (patch_xbe.py RNGLOG_FUNCS) call
// this with `push id; call`: log (caller's return address, frame | id << 24), drop the id, back to the trampoline.
extern "C" __declspec(naked) void hybrid_rnglog_fn()
{
    __asm {
        push eax
        push ecx
        mov eax, g_hybrid.rnglog_count
        and eax, RNGLOG_MAX - 1
        mov ecx, [esp + 16]
        mov dword ptr g_hybrid.rnglog[eax * 8], ecx
        mov ecx, [esp + 12]
        shl ecx, 24
        or ecx, g_hybrid.frame
        mov dword ptr g_hybrid.rnglog[eax * 8 + 4], ecx
        inc g_hybrid.rnglog_count
        pop ecx
        pop eax
        ret 4
    }
}

// seq-rng: audio::SeqEventSilence (0x254850, 0x2549a0: silence length) and SeqEventLogicRepeat's state (0x254c80:
// repeat count) call the game's RandInt (0x113e0); with the patch they draw from the sound code's generator instead
// (the same MWC step and result).
extern "C" unsigned int __cdecl hybrid_seq_randint(unsigned int lo, unsigned int hi)
{
    unsigned int* st = g_hybrid.snd_rng;
    st[0] = 36969 * (st[0] & 0xFFFF) + (st[0] >> 16);
    st[1] = 18000 * (st[1] & 0xFFFF) + (st[1] >> 16);
    unsigned int r = (st[0] << 16) + (st[1] & 0xFFFF);
    return r % (hi - lo + 1) + lo;
}

// CGame::Tick's call to GameClock::Update (0x876e5): note CGame (esi), then GameClock::Update as before.
extern "C" __declspec(naked) void hybrid_game_tick()
{
    __asm {
        mov g_hybrid.cgame, esi
        mov eax, 0x00086450
        jmp eax
    }
}

// /GS: the original __security_check_cookie (0x34502e) is __fastcall (cookie in ecx). Sources that declare it
// __cdecl pass the cookie on the stack; equiv.py skips the call on both sides, so they verify, but in the game
// ecx holds garbage and the check fails (CGame::Init 0x88020 hung at boot). tools/patch_xbe.py binds every
// non-fastcall reference to the cookie check here instead.
typedef void (__fastcall *CookieFn)(unsigned int);
extern "C" void __cdecl hybrid_check_cookie_cdecl(unsigned int cookie)
{
    ((CookieFn)0x0034502E)(cookie);
}

#ifdef HYBRID_DRAWLOG
// ---------------------------------------------------------------------------------------------
// drawlog (docs/graphics-backend.md "Test strategy" 1; tools/patch_xbe.py --drawlog, DRAWLOG_CALLS): every call the
// pure3d D3D backend makes to D3DDevice_DrawVertices / DrawVerticesUP / DrawIndexedVertices is redirected here, and
// in the selected frames one record per draw goes to g_drawlog.ring: the pddi state at that draw, read from the
// game's own objects. Compiled only into drawlog builds (/DHYBRID_DRAWLOG), so other builds keep their layout.
// The native backend writes the same 24-word record (src/platform/sdl/pddi/pddi.h DrawRecord: keep in sync);
// tools/drawlog_diff.py compares two logs.
#define DRAWLOG_RING 4096
#define DRAWLOG_TEX 1024
#define DL_CONTEXT 0x0052C2A8          // Pure3D's context global (docs/seams.md: device 0x52c2a0, display, context)
#define DL_SHADER 0x005555BC           // the shader last activated (0x327d20 stores it; its +0xc is its id)

struct DrawRec {                       // 24 words
    unsigned int frame;
    unsigned int seq;                  // draw index in the frame | site << 24 (DRAWLOG_CALLS order + 1)
    unsigned int prim;                 // D3D primitive type passed to the draw
    unsigned int count;                // vertex / index count passed to the draw
    unsigned int shader;               // vftable of [0x5555bc] (the shader class)
    unsigned int shader_id;            // its word at +0xc
    unsigned int tex[4];               // stage textures (*(context+0x150))->c[0..3], as first-seen ordinals
    unsigned int state_a[6];           // *(context+0x4c): cull at +4, ...
    unsigned int state_s[6];           // *(context+0x58): stencil
    unsigned int fog;                  // byte at *(context+0x54)+4
    unsigned int mtx;                  // FNV-1a of the top matrix of the context's stacks 0..3 (+0x20..)
};

struct DrawlogCtl {
    unsigned int magic;                // 'DLG1'
    unsigned int first, every, last;   // frames logged: first <= f <= last and (f - first) % every == 0
    unsigned int count;                // records written (ring index = count % DRAWLOG_RING)
    unsigned int draws;                // every draw seen, logged or not
    unsigned int cur_frame, seq;       // the frame the per-frame counter belongs to
    unsigned int ntex;                 // texture ordinals given out
    unsigned int site_addr[16];        // diagnostics: return address of each site's last draw
    DrawRec ring[DRAWLOG_RING];
    unsigned int tex_key[DRAWLOG_TEX]; // pddiTexture* -> ordinal (open addressing)
    unsigned int tex_val[DRAWLOG_TEX];
};

extern "C" DrawlogCtl g_drawlog = {0x31474C44, 0, 0, 0};

static unsigned int dl_ok(unsigned int p)
{
    return p >= 0x00010000 && p < 0x04000000 && !(p & 3);     // the title's 64 MB, aligned
}

static unsigned int dl_tex(unsigned int t)
{
    if (!t)
        return 0;
    unsigned int h = (t >> 4) % DRAWLOG_TEX;
    for (unsigned int i = 0; i < DRAWLOG_TEX; i++, h = (h + 1) % DRAWLOG_TEX) {
        if (g_drawlog.tex_key[h] == t)
            return g_drawlog.tex_val[h];
        if (!g_drawlog.tex_key[h]) {
            g_drawlog.tex_key[h] = t;
            g_drawlog.tex_val[h] = ++g_drawlog.ntex;
            return g_drawlog.ntex;
        }
    }
    return 0xFFFFFFFF;
}

static void dl_words(unsigned int* out, unsigned int ptr, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        out[i] = dl_ok(ptr) ? ((unsigned int*)ptr)[i] : 0;
}

static void drawlog(unsigned int site, unsigned int prim, unsigned int count)
{
    g_drawlog.draws++;
    unsigned int f = g_hybrid.frame;
    if (f != g_drawlog.cur_frame) {
        g_drawlog.cur_frame = f;
        g_drawlog.seq = 0;
    }
    unsigned int seq = g_drawlog.seq++;
    if (!g_drawlog.every || f < g_drawlog.first || f > g_drawlog.last || (f - g_drawlog.first) % g_drawlog.every)
        return;
    DrawRec& r = g_drawlog.ring[g_drawlog.count % DRAWLOG_RING];
    r.frame = f;
    r.seq = seq | (site << 24);
    r.prim = prim;
    r.count = count;
    unsigned int sh = *(unsigned int*)DL_SHADER;
    r.shader = dl_ok(sh) ? *(unsigned int*)sh : 0;
    r.shader_id = dl_ok(sh) ? ((unsigned int*)sh)[3] : 0;
    unsigned int ctx = *(unsigned int*)DL_CONTEXT;
    unsigned int i;
    for (i = 0; i < 4; i++)
        r.tex[i] = 0;
    for (i = 0; i < 6; i++)
        r.state_a[i] = r.state_s[i] = 0;
    r.fog = 0;
    r.mtx = 2166136261u;
    if (dl_ok(ctx)) {
        unsigned int d = *(unsigned int*)(ctx + 0x150);
        if (dl_ok(d))
            for (i = 0; i < 4; i++)
                r.tex[i] = dl_tex(((unsigned int*)d)[2 + i]);
        dl_words(r.state_a, *(unsigned int*)(ctx + 0x4c), 6);
        dl_words(r.state_s, *(unsigned int*)(ctx + 0x58), 6);
        unsigned int fogp = *(unsigned int*)(ctx + 0x54);
        r.fog = dl_ok(fogp) ? *(unsigned char*)(fogp + 4) : 0;
        for (i = 0; i < 4; i++) {
            unsigned int st = *(unsigned int*)(ctx + 0x20 + 4 * i);     // matrix stack: +8 index, +0xc matrices
            if (!dl_ok(st))
                continue;
            unsigned int idx = ((unsigned int*)st)[2], m = ((unsigned int*)st)[3];
            if (idx < 64 && dl_ok(m))
                r.mtx = fnv(r.mtx, (const unsigned char*)(m + 64 * idx), 64);
        }
    }
    g_drawlog.count++;
}

extern "C" void* _ReturnAddress(void);
#pragma intrinsic(_ReturnAddress)

// the site: which DRAWLOG_CALLS entry called (return address - 5 is the call instruction)
static unsigned int dl_site(unsigned int ret)
{
    static const unsigned int sites[] = {0x0031BB9E, 0x0031C10A, 0x0031FDE3, 0x003236BA, 0x0032388C, 0x003249EA,
                                         0x003259F3, 0x00325B73, 0x00326CB7, 0x0032736C, 0x003273B2};
    for (unsigned int i = 0; i < sizeof(sites) / sizeof(sites[0]); i++)
        if (sites[i] + 5 == ret) {
            g_drawlog.site_addr[i] = ret;
            return i + 1;
        }
    return 0;                          // our copy of a patched function (its call sites move)
}

typedef void (__stdcall *DrawVerticesFn)(unsigned int prim, unsigned int start, unsigned int count);
typedef void (__stdcall *DrawVerticesUPFn)(unsigned int prim, unsigned int count, const void* data, unsigned int stride);
typedef void (__stdcall *DrawIndexedFn)(unsigned int prim, unsigned int count, const void* indices);
#define D3DDevice_DrawVertices ((DrawVerticesFn)0x003834C0)
#define D3DDevice_DrawVerticesUP ((DrawVerticesUPFn)0x00383210)
#define D3DDevice_DrawIndexedVertices ((DrawIndexedFn)0x00383560)

extern "C" void __stdcall hybrid_dl_draw_vertices(unsigned int prim, unsigned int start, unsigned int count)
{
    drawlog(dl_site((unsigned int)_ReturnAddress()), prim, count);
    D3DDevice_DrawVertices(prim, start, count);
}

extern "C" void __stdcall hybrid_dl_draw_vertices_up(unsigned int prim, unsigned int count, const void* data,
                                                     unsigned int stride)
{
    drawlog(dl_site((unsigned int)_ReturnAddress()), prim, count);
    D3DDevice_DrawVerticesUP(prim, count, data, stride);
}

extern "C" void __stdcall hybrid_dl_draw_indexed(unsigned int prim, unsigned int count, const void* indices)
{
    drawlog(dl_site((unsigned int)_ReturnAddress()), prim, count);
    D3DDevice_DrawIndexedVertices(prim, count, indices);
}
#endif // HYBRID_DRAWLOG
