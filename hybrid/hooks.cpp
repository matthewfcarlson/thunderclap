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
//
// All state lives in one struct, g_hybrid, whose address is in the build manifest. The host reads the
// checkpoint ring and the record buffer through QMP memsave (tools/hybrid_test.py) and writes the replay
// into the XBE at build time. Every field is a 32-bit word so tools/patch_xbe.py can address them by index.

#define HYBRID_MAGIC 0x48594231      /* 'HYB1' */
#define CKPT_RING 4096
#define INPUT_MAX 8192
#define REGION_MAX 8
#define WIDE_PAGES 256
#define SKIP_MAX 32

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
#define HF_POLLKEY  64               // replay entries are keyed by pad polls instead of frames (tools/trace_capture.py:
                                     // after the new-game load the frame counter races, polls stay ~1 per frame)

static unsigned int s_last_frame;

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

// core::ControllerXBox::vfunc_17's pad read. Replay overrides the gamepad; record logs changes.
extern "C" unsigned long __stdcall hybrid_xinput_get_state(void* device, unsigned char* state)
{
    unsigned long r = XInputGetState(device, state);
    g_hybrid.polls++;
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
