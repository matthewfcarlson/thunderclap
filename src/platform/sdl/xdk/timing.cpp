// Stand-ins for timing (xdk_shim.h counts and logs each call). Native builds only.
//
// The game assumes the Xbox's performance-counter frequency, 733,333,333 Hz, in places (docs/platform-boundary.md),
// so the stand-ins keep that frequency and scale the host's counter to it.
#include "imports.h"
#include "../crt/host_crt.h"

static const unsigned long long hulk_xbox_hz = 733333333ull;

// ---------------------------------------------------------------------------------------------
// Replay pins (docs/native-replay.md items 2 and 8; build/rp1/for-native9.md D): the hybrid build's virtual clock
// (hybrid/hooks.cpp hybrid_qpc, hybrid_clock_tick, hybrid_clock_now, hybrid_get_local_time) on the shim's own choke
// points. Every QueryPerformanceCounter of the image is a game read (Bink and the mixer are SDL-side and keep real
// time), so with vclock the counter is the virtual clock: 1 s at the first read, each main-thread read before the
// first GameClock::Update advances it 4 ms, the first Update sets it to 300 s, each later one by one step (33,333
// us); between updates it stands still. HULK_VCLOCK=1 turns it on, as does a replay whose flags include vclock
// (fixed-dt alone: Update's time is base + frame * dt, the counter stays real). vdate: GetLocalTime is
// 2006-01-02 12:00 plus the virtual clock.
#define HULK_HF_FIXED_DT 1u
#define HULK_HF_VCLOCK 128u
#define HULK_HF_VDATE 4096u
static const unsigned long long hulk_vstart_us = 1000000ull, hulk_vbase_us = 300000000ull, hulk_pre_step_us = 4000ull;
// the fixed step: 33,333 us (30 fps), or HULK_VDT_US (e.g. 16667 for a 60 fps replay; see docs/wine-widescreen-60fps.md)
static unsigned long long hulk_dt_us = 33333ull;
static int hulk_vflags = -1;
static unsigned long long hulk_vt, hulk_vextra, hulk_fixed_base;
static hulk_u32 hulk_vmain, hulk_vframe;

#if defined(HULK_NATIVE_SDL)
#include "../replay/hulk_replay.h"
#endif

static unsigned hulk_vclock_flags(void) {
    if (hulk_vflags < 0) {
        unsigned f = 0;
        const char* dt = hulk_host_getenv("HULK_VDT_US");
        if (dt && dt[0] >= '1' && dt[0] <= '9') {
            unsigned long long v = 0;
            for (; *dt >= '0' && *dt <= '9'; dt++)
                v = v * 10 + (unsigned)(*dt - '0');
            if (v >= 1000 && v <= 66666)
                hulk_dt_us = v;
        }
        const char* e = hulk_host_getenv("HULK_VCLOCK");
        if (e && e[0] == '1')
            f = HULK_HF_FIXED_DT | HULK_HF_VCLOCK | HULK_HF_VDATE;
#if defined(HULK_NATIVE_SDL)
        HulkReplayInfo ri;
        if (hulk_replay_info(&ri))
            f |= ri.flags & (HULK_HF_FIXED_DT | HULK_HF_VCLOCK | HULK_HF_VDATE);
#endif
        if (f & HULK_HF_VCLOCK)
            f |= HULK_HF_FIXED_DT;
        hulk_vflags = (int)f;
    }
    return (unsigned)hulk_vflags;
}

static unsigned long long hulk_real_us(void) {
    unsigned long long c = 0, f = 1;
    hulk_host_QueryPerformanceCounter(&c);
    hulk_host_QueryPerformanceFrequency(&f);
    if (!f)
        f = 1;
    return c / f * 1000000ull + c % f * 1000000ull / f;
}

// GameClock::Update's time (tools/native_link.py SITE_REBIND: 0x00086450's call of GetMicroseconds64 0x00267f40)
extern "C" unsigned long long HULK_CDECL FUN_00267f40();
extern "C" unsigned long long HULK_CDECL hulk_clock_tick(void) {
    unsigned f = hulk_vclock_flags();
    if (!(f & HULK_HF_FIXED_DT))
        return FUN_00267f40();
    hulk_vframe++;
    if (!(f & HULK_HF_VCLOCK)) {
        if (!hulk_fixed_base)
            hulk_fixed_base = hulk_real_us() | 1;
        return hulk_fixed_base + (unsigned long long)hulk_vframe * hulk_dt_us;
    }
    unsigned long long t;
    if (hulk_vframe == 1) {
        t = hulk_vbase_us;
        if (hulk_vt >= t)
            t = hulk_vt + 1;
    } else {
        t = hulk_vt - hulk_vextra + hulk_dt_us;
        if (hulk_vextra >= hulk_dt_us)
            t = hulk_vt + 1;
    }
    hulk_vextra = 0;
    hulk_vt = t;
    return t;
}

// The GameClock constructor's first timestamp (SITE_REBIND: 0x00087e30's call of 0x00267f40)
extern "C" unsigned long long HULK_CDECL hulk_clock_now(void) {
    unsigned f = hulk_vclock_flags();
    if (!(f & HULK_HF_FIXED_DT))
        return FUN_00267f40();
    if (f & HULK_HF_VCLOCK)
        return hulk_vbase_us - hulk_dt_us;
    if (!hulk_fixed_base)
        hulk_fixed_base = hulk_real_us() | 1;
    return hulk_fixed_base + (unsigned long long)hulk_vframe * hulk_dt_us;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceCounter(hulk_u32 a0) {
    HULK_XDK_TRACE("QueryPerformanceCounter");
    if (hulk_vclock_flags() & HULK_HF_VCLOCK) {
        hulk_u32 tid = hulk_host_GetCurrentThreadId();
        if (!hulk_vmain) {                  // the first read: the game's own init, on the main thread
            hulk_vmain = tid;
            hulk_vt = hulk_vstart_us;
        }
        if (tid == hulk_vmain && hulk_vframe == 0)
            hulk_vt += hulk_pre_step_us;    // (after the first update: step 0, the clock stands still)
        // ticks = us * 733.333...
        unsigned long long v = hulk_vt * 733ull + hulk_vt / 3ull;
        if (a0)
            *(unsigned long long*)a0 = v;
        return 1;
    }
    unsigned long long c = 0, f = 1;
    hulk_host_QueryPerformanceCounter(&c);
    hulk_host_QueryPerformanceFrequency(&f);
    if (!f)
        f = 1;
    // c * 733333333 / f without overflowing 64 bits for a long uptime
    unsigned long long whole = c / f, part = c % f;
    unsigned long long v = whole * hulk_xbox_hz + part * hulk_xbox_hz / f;
    if (a0)
        *(unsigned long long*)a0 = v;
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceFrequency(hulk_u32 a0) {
    HULK_XDK_TRACE("QueryPerformanceFrequency");
    if (a0)
        *(unsigned long long*)a0 = hulk_xbox_hz;
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetLocalTime(hulk_u32 a0) {
    HULK_XDK_TRACE("GetLocalTime");
    if (a0 && (hulk_vclock_flags() & HULK_HF_VDATE)) {
        // 2006-01-02 (a Monday) 12:00:00 plus the virtual clock's seconds (the day wraps after four weeks)
        unsigned short* t = (unsigned short*)a0;   // year, month, dow, day, hour, minute, second, ms
        unsigned secs = (unsigned)(hulk_vt / 1000000ull), rem = (unsigned)(hulk_vt % 1000000ull);
        unsigned sec = 12u * 3600u + secs, days = sec / 86400u;
        sec %= 86400u;
        t[0] = 2006;
        t[1] = 1;
        t[2] = (unsigned short)((1 + days) % 7);
        t[3] = (unsigned short)(2 + days % 28);
        t[4] = (unsigned short)(sec / 3600);
        t[5] = (unsigned short)(sec / 60 % 60);
        t[6] = (unsigned short)(sec % 60);
        t[7] = (unsigned short)(rem / 1000);
        return 0;
    }
    if (a0)
        hulk_host_GetLocalTime((void*)a0);  // SYSTEMTIME: the same public layout on both
    return 0;
}
