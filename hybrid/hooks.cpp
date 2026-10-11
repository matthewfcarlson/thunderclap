// Determinism and test hooks for the hybrid build (docs/tasks/10-hybrid-test-plan.md, docs/hybrid-build.md).
// Compiled with MSVC 7.1 like everything else and linked into the .hybrid section by tools/patch_xbe.py,
// which also redirects the original call sites listed in HOOK_SITES there:
//
//   GameClock::Update 0x86450:  call GetMicroseconds64 @0x8646e -> hybrid_clock_tick  (fixed dt, frame counter,
//                                                                                     checkpoints)
//   GameClock ctor    0x87e30:  call GetMicroseconds64 @0x87e40 -> hybrid_clock_now
//   ControllerXBox::vfunc_17:   call XInputGetState     @0x2685d9 -> hybrid_xinput_get_state (replay / record)
//   0x86630 (new-game reseed):  call GetMicroseconds    @0x8668e -> mov eax, seed       (byte patch, no code)
//
// All state lives in one struct, g_hybrid, whose address is in the build manifest. The host reads the
// checkpoint ring and the record buffer through QMP memsave (tools/hybrid_test.py) and writes the replay
// into the XBE at build time. Every field is a 32-bit word so tools/patch_xbe.py can address them by index.

#define HYBRID_MAGIC 0x48594231      /* 'HYB1' */
#define CKPT_RING 4096
#define INPUT_MAX 8192
#define REGION_MAX 8

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
    unsigned int size;
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
    unsigned int record_count;        // 10 entries in record[]
    unsigned int polls;               // 11 XInputGetState calls seen
    unsigned int nregions;            // 12
    unsigned int base_us_lo;          // 13 virtual clock start (from the first real reading)
    unsigned int base_us_hi;          // 14
    unsigned int frozen_polls;        // 15 polls since the frame counter last moved (loading screens)
    Region regions[REGION_MAX];       // 16..31
    Ckpt ckpt[CKPT_RING];
    Pad replay[INPUT_MAX];
    Pad record[INPUT_MAX];
};

#define HF_FIXED_DT 1
#define HF_REPLAY   2
#define HF_RECORD   4
#define HF_CKPT     8
#define HF_AUTOSTART 16               // pulse START while the game loop is stalled (loading-screen "Press START")

static unsigned int s_last_frame;

extern "C" HybridCtl g_hybrid = {
    HYBRID_MAGIC, HF_FIXED_DT | HF_CKPT, 33333, 0, 0, 0, 30, 0, 0, 0, 0, 0,
    2, 0, 0, 0,
    {
        {0x004E5AD0, 8},              // global MWC random generator state (seeded at 0x8669b)
        {0x0049FB40, 4},              // g_BootSequenceStep
    },
};

typedef unsigned __int64 (__cdecl *ClockFn)();
typedef unsigned long (__stdcall *XInputGetStateFn)(void* device, void* state);
#define GetMicroseconds64 ((ClockFn)0x00267F40)
#define XInputGetState ((XInputGetStateFn)0x003EB91F)

static unsigned int fnv(unsigned int h, const unsigned char* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        h = (h ^ p[i]) * 16777619u;
    return h;
}

static void checkpoint()
{
    unsigned int h = 2166136261u;
    h = fnv(h, (const unsigned char*)&g_hybrid.frame, 4);
    for (unsigned int i = 0; i < g_hybrid.nregions && i < REGION_MAX; i++) {
        unsigned int a = g_hybrid.regions[i].addr;
        if (a & 0x80000000) {
            a = *(unsigned int*)(a & 0x7FFFFFFF);
            if (a == 0) continue;
        }
        h = fnv(h, (const unsigned char*)a, g_hybrid.regions[i].size);
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

// GameClock ctor: the clock's first timestamp.
extern "C" unsigned __int64 __cdecl hybrid_clock_now()
{
    if (!(g_hybrid.flags & HF_FIXED_DT))
        return GetMicroseconds64();
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
    if ((g_hybrid.flags & HF_CKPT) && g_hybrid.ckpt_interval && g_hybrid.frame % g_hybrid.ckpt_interval == 0)
        checkpoint();
    g_hybrid.frame++;
    if (!(g_hybrid.flags & HF_FIXED_DT))
        return GetMicroseconds64();
    return virtual_now();
}

// core::ControllerXBox::vfunc_17's pad read. Replay overrides the gamepad; record logs changes.
extern "C" unsigned long __stdcall hybrid_xinput_get_state(void* device, unsigned char* state)
{
    unsigned long r = XInputGetState(device, state);
    g_hybrid.polls++;
    unsigned char* pad = state + 4;          // XINPUT_STATE.Gamepad (22 bytes total, 18 of pad)
    if (g_hybrid.flags & HF_REPLAY) {
        unsigned int pos = g_hybrid.replay_pos;
        while (pos + 1 < g_hybrid.replay_count && g_hybrid.replay[pos + 1].frame <= g_hybrid.frame)
            pos++;
        g_hybrid.replay_pos = pos;
        const unsigned char* src = 0;
        if (pos < g_hybrid.replay_count && g_hybrid.replay[pos].frame <= g_hybrid.frame)
            src = (const unsigned char*)&g_hybrid.replay[pos].buttons;
        for (int i = 0; i < 18; i++)
            pad[i] = src ? src[i] : 0;
        if (g_hybrid.frame != s_last_frame) {
            s_last_frame = g_hybrid.frame;
            g_hybrid.frozen_polls = 0;
        } else if (++g_hybrid.frozen_polls > 60 && (g_hybrid.flags & HF_AUTOSTART)) {
            if ((g_hybrid.frozen_polls >> 3) & 1)
                pad[0] |= 0x10;               // XINPUT_GAMEPAD_START
            else
                pad[0] &= ~0x10;
        }
        return 0;
    }
    if ((g_hybrid.flags & HF_RECORD) && r == 0 && g_hybrid.record_count < INPUT_MAX) {
        Pad* last = g_hybrid.record_count ? &g_hybrid.record[g_hybrid.record_count - 1] : 0;
        bool same = last != 0;
        for (int i = 0; same && i < 18; i++)
            same = ((unsigned char*)&last->buttons)[i] == pad[i];
        if (!same) {
            Pad* p = &g_hybrid.record[g_hybrid.record_count++];
            p->frame = g_hybrid.frame;
            for (int i = 0; i < 18; i++)
                ((unsigned char*)&p->buttons)[i] = pad[i];
        }
    }
    return r;
}
