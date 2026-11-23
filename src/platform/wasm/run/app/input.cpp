// The app's pad (docs/wasm-port.md "The macOS app"): the SDL layer's input backend (src/platform/sdl/input/), SDL3
// gamepads as Xbox controllers and the keyboard as pad 0, merged with a gamepad there (docs/native-play.md's map;
// HULK_KEYMAP, HULK_KEY_SCRIPT for unattended runs). The module asks once a presented frame (gfx.c), outside replays
// and HULK_INPUT runs (those never reach this file).
//
// macOS (wpad1): SDL's gamepad subsystem lives on its own thread ("hulk-pad"), never on the main thread. Its init
// creates the HID devices (HIDAPI's IOHIDManagerSetDeviceMatching -> IOHIDDeviceCreate -> IOServiceOpen), which
// blocks forever in the kernel while macOS's gamecontrollerd is deadlocked (seen with Chrome's "Gamepad polling
// thread"), and SDL holds its joystick lock meanwhile: then no main-thread SDL joystick call may happen (the event
// pump's SDL_UpdateJoysticks, SDL_Quit's SDL_QuitJoysticks, and GameController's connect notifications, which SDL's
// MFi driver handles on the main thread under that lock). So the pad thread first makes the same IOHIDManager call
// itself, outside SDL (pt_probe): a stall stays there, holding nothing of SDL's. Once it returns the thread
// initializes SDL's gamepads, updates them (hot-plug), reads and rumbles; the main thread reads its last snapshot
// under a mutex and keeps the keyboard as pad 0 until a gamepad attaches. Quitting stops the thread when it can and
// otherwise leaves SDL to the process exit (hulk_app_pad_stop, start.cpp). HULK_PAD_INIT_DELAY=S (tests only) sleeps
// S seconds in the probe: the stall, simulated where it happens. Android keeps the main-thread path (its joysticks
// come through SDL's Java layer).
#include <stdint.h>
#include <string.h>

#include "input/hulk_input.cpp"

typedef uint32_t u32;

#if defined(__APPLE__)
#define HULK_APP_PAD_THREAD 1
#else
#define HULK_APP_PAD_THREAD 0
#endif

static int app_kb_env(void)
{
    static int kb_env = -1;
    if (kb_env < 0) {
        const char* e = SDL_getenv("HULK_KEYBOARD");
        const char* h = SDL_getenv("HULK_GFX_HIDDEN");
        kb_env = !((e && *e == '0') || (h && *h && *h != '0'));     // (kb_active's switches)
    }
    return kb_env;
}

#if HULK_APP_PAD_THREAD
#include <IOKit/hid/IOHIDManager.h>

enum { PT_OFF, PT_PROBE, PT_INIT, PT_UP, PT_FAILED, PT_DONE };
#define PT_WARN_MS 3000u

static struct {
    SDL_AtomicInt phase;        // PT_*
    SDL_AtomicInt quit;         // the main thread asks the pad thread to stop
    SDL_Mutex* mu;
    unsigned delay_ms;          // HULK_PAD_INIT_DELAY
    Uint64 t0;
    // published by the pad thread (under mu)
    SDL_JoystickID id[HULK_INPUT_PORTS];
    unsigned gen[HULK_INPUT_PORTS];
    int has[HULK_INPUT_PORTS];
    HulkPadState st[HULK_INPUT_PORTS];
    // the main thread's rumble requests (under mu)
    unsigned short rl[HULK_INPUT_PORTS], rr[HULK_INPUT_PORTS];
    unsigned rdirty;
    // the main thread's copy (main thread only)
    SDL_JoystickID mid[HULK_INPUT_PORTS];
    unsigned mgen[HULK_INPUT_PORTS];
    int mhas[HULK_INPUT_PORTS];
    HulkPadState mst[HULK_INPUT_PORTS];
    int warned;
    char* title;                // the window's title while the notice is in it
} g_pt;

// HIDAPI's init, outside SDL: an IOHIDManager matching every HID device creates them all (no device is opened)
static void pt_probe(void)
{
    if (g_pt.delay_ms)          // tests: the stall, simulated
        SDL_Delay(g_pt.delay_ms);
    IOHIDManagerRef m = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
    if (!m)
        return;
    IOHIDManagerSetDeviceMatching(m, NULL);     // (may never return: the gamecontrollerd deadlock)
    CFSetRef devs = IOHIDManagerCopyDevices(m);
    if (devs)
        CFRelease(devs);
    CFRelease(m);
}

static int SDLCALL pad_thread(void*)
{
    Uint64 t0 = SDL_GetTicks();
    pt_probe();
    SDL_LockMutex(g_pt.mu);     // (hulk_app_pad_stop: a quit asked during the probe keeps the thread out of SDL)
    int quit = SDL_GetAtomicInt(&g_pt.quit);
    SDL_SetAtomicInt(&g_pt.phase, quit ? PT_DONE : PT_INIT);
    SDL_UnlockMutex(g_pt.mu);
    if (quit)
        return 0;
    sdl_up();
    if (!g_sdl.up) {
        SDL_SetAtomicInt(&g_pt.phase, PT_FAILED);
        return 0;
    }
    SDL_Log("input: controllers ready after %.1f s", (double)(SDL_GetTicks() - t0) / 1000.0);
    SDL_SetAtomicInt(&g_pt.phase, PT_UP);
    while (!SDL_GetAtomicInt(&g_pt.quit)) {
        sdl_update(0);
        unsigned short rl[HULK_INPUT_PORTS], rr[HULK_INPUT_PORTS];
        SDL_LockMutex(g_pt.mu);
        unsigned rd = g_pt.rdirty;
        g_pt.rdirty = 0;
        memcpy(rl, g_pt.rl, sizeof rl);
        memcpy(rr, g_pt.rr, sizeof rr);
        SDL_UnlockMutex(g_pt.mu);
        for (int p = 0; p < HULK_INPUT_PORTS; p++)
            if (rd & (1u << p))
                sdl_rumble(0, p, rl[p], rr[p]);
        SDL_JoystickID id[HULK_INPUT_PORTS];
        unsigned gen[HULK_INPUT_PORTS];
        int has[HULK_INPUT_PORTS];
        HulkPadState st[HULK_INPUT_PORTS];
        for (int p = 0; p < HULK_INPUT_PORTS; p++) {
            id[p] = g_sdl.port[p].id;
            gen[p] = g_sdl.port[p].gen;
            has[p] = g_sdl.port[p].pad && sdl_read(0, p, &st[p]);  // (a pad there: sdl_read skips the keyboard)
            if (!has[p])
                SDL_memset(&st[p], 0, sizeof st[p]);
        }
        SDL_LockMutex(g_pt.mu);
        memcpy(g_pt.id, id, sizeof id);
        memcpy(g_pt.gen, gen, sizeof gen);
        memcpy(g_pt.has, has, sizeof has);
        memcpy(g_pt.st, st, sizeof st);
        SDL_UnlockMutex(g_pt.mu);
        SDL_Delay(4);
    }
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_sdl.port[p].pad) {
            SDL_CloseGamepad(g_sdl.port[p].pad);
            g_sdl.port[p].pad = 0;
            g_sdl.port[p].id = 0;
        }
    SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
    g_sdl.up = 0;
    SDL_SetAtomicInt(&g_pt.phase, PT_DONE);
    return 0;
}

// the main thread's notice: one log line and the window title, while the init is pending past PT_WARN_MS
static void pt_notice(int on)
{
    int n = 0;
    SDL_Window** ws = SDL_GetWindows(&n);
    SDL_Window* w = (ws && n > 0) ? ws[0] : 0;
    SDL_free(ws);
    if (on && !g_pt.title && w) {
        const char* t = SDL_GetWindowTitle(w);
        g_pt.title = SDL_strdup(t ? t : "");
        char buf[256];
        SDL_snprintf(buf, sizeof buf, "%s (controllers unavailable: macOS's game controller service is not responding)",
                     g_pt.title);
        SDL_SetWindowTitle(w, buf);
    } else if (!on && g_pt.title) {
        if (w)
            SDL_SetWindowTitle(w, g_pt.title);
        SDL_free(g_pt.title);
        g_pt.title = 0;
    }
}

static void pt_start(void)
{
    g_pt.mu = SDL_CreateMutex();
    const char* d = SDL_getenv("HULK_PAD_INIT_DELAY");
    g_pt.delay_ms = d ? (unsigned)(SDL_atof(d) * 1000.0) : 0;
    // the main thread's event pump must not update joysticks: SDL_UpdateJoysticks takes the lock a stuck init holds
    SDL_SetHint(SDL_HINT_AUTO_UPDATE_JOYSTICKS, "0");
    g_pt.t0 = SDL_GetTicks();
    SDL_SetAtomicInt(&g_pt.phase, PT_PROBE);
    SDL_Thread* t = g_pt.mu ? SDL_CreateThread(pad_thread, "hulk-pad", 0) : 0;
    if (!t) {
        SDL_Log("input: no controller thread: %s (keyboard only)", SDL_GetError());
        SDL_SetAtomicInt(&g_pt.phase, PT_FAILED);
        return;
    }
    SDL_DetachThread(t);        // never joined: a stuck init must not hold anyone up
}

static void app_update(void*)
{
    int ph = SDL_GetAtomicInt(&g_pt.phase);
    if (ph == PT_OFF) {
        pt_start();
        ph = SDL_GetAtomicInt(&g_pt.phase);
    }
    if ((ph == PT_PROBE || ph == PT_INIT) && !g_pt.warned && SDL_GetTicks() - g_pt.t0 > PT_WARN_MS) {
        g_pt.warned = 1;
        SDL_Log("input: controllers unavailable: macOS's game controller service is not responding (gamepad init "
                "pending for %u s); the keyboard works. Quit apps that poll gamepads (e.g. Chrome) or restart "
                "gamecontrollerd; a controller attaches when the init completes", PT_WARN_MS / 1000);
        pt_notice(1);
    }
    if (ph != PT_PROBE && ph != PT_INIT && g_pt.title)
        pt_notice(0);
    if (ph != PT_UP)
        return;
    SDL_LockMutex(g_pt.mu);
    memcpy(g_pt.mid, g_pt.id, sizeof g_pt.mid);
    memcpy(g_pt.mgen, g_pt.gen, sizeof g_pt.mgen);
    memcpy(g_pt.mhas, g_pt.has, sizeof g_pt.mhas);
    memcpy(g_pt.mst, g_pt.st, sizeof g_pt.mst);
    SDL_UnlockMutex(g_pt.mu);
}

// kb_active's rule on the main thread's copy: the keyboard is pad 0 while no gamepad is attached
static int app_kb_active(void)
{
    if (!app_kb_env() || !SDL_WasInit(SDL_INIT_VIDEO))
        return 0;
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_pt.mid[p])
            return 0;
    static int logged;
    if (!logged) {
        logged = 1;
        SDL_Log("input: no gamepad: the keyboard is pad 0 (WASD IJKL arrows Space F R G Enter Esc; docs/native-play.md)");
    }
    return 1;
}

static unsigned app_connected(void*)
{
    unsigned m = app_kb_active() ? 1u : 0u;
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_pt.mid[p])
            m |= 1u << p;
    return m;
}

static unsigned app_generation(void*, unsigned port)
{
    if (port == 0 && app_kb_active())
        return KB_GEN;
    return port < HULK_INPUT_PORTS ? g_pt.mgen[port] : 0;
}

static int app_read(void*, unsigned port, HulkPadState* s)
{
    if (port == 0 && app_kb_active())
        return kb_read(s);
    if (port >= HULK_INPUT_PORTS || !g_pt.mhas[port])
        return 0;
    *s = g_pt.mst[port];
    return 1;
}

static void app_rumble(void*, unsigned port, unsigned short left, unsigned short right)
{
    if (port >= HULK_INPUT_PORTS || !g_pt.mu)
        return;
    SDL_LockMutex(g_pt.mu);
    g_pt.rl[port] = left;
    g_pt.rr[port] = right;
    g_pt.rdirty |= 1u << port;
    SDL_UnlockMutex(g_pt.mu);
}

static const HulkInputSource kAppSource = {"sdl (pad thread)", 0, app_update, app_connected, app_generation, app_read,
                                           app_rumble, 0};
#define APP_KB_ACTIVE() app_kb_active()
#else
#define APP_KB_ACTIVE() kb_active()
#endif

// The quit path (start.cpp hulk_app_quit): 1 when SDL_Quit may run (the pad thread stopped, or there is none); 0 when
// the pad thread is still inside SDL after wait_ms (a stuck init or hot-plug: SDL_Quit would wait on its lock).
extern "C" int hulk_app_pad_stop(unsigned wait_ms)
{
#if HULK_APP_PAD_THREAD
    int ph = SDL_GetAtomicInt(&g_pt.phase);
    if (ph == PT_OFF || ph == PT_FAILED || ph == PT_DONE)
        return 1;
    SDL_LockMutex(g_pt.mu);
    SDL_SetAtomicInt(&g_pt.quit, 1);
    ph = SDL_GetAtomicInt(&g_pt.phase);
    SDL_UnlockMutex(g_pt.mu);
    if (ph == PT_PROBE) {       // still in the probe, holding nothing of SDL's: it never enters SDL now
        SDL_Log("input: quit with the controller probe still pending (macOS's game controller service not responding)");
        return 1;
    }
    Uint64 t = SDL_GetTicks();
    while (SDL_GetTicks() - t < wait_ms) {
        ph = SDL_GetAtomicInt(&g_pt.phase);
        if (ph == PT_FAILED || ph == PT_DONE)
            return 1;
        SDL_Delay(2);
    }
    SDL_Log("input: the controller thread is still inside SDL (%s): leaving SDL to the process exit",
            ph == PT_INIT ? "gamepad init pending" : "busy");
    return 0;
#else
    (void)wait_ms;
    return 1;
#endif
}

// XINPUT_GAMEPAD's 18 bytes (HulkPadState's layout) for `port`: 1 with a pad there, else 0
extern "C" u32 hulk_app_pad(u32 port, uint8_t* out18)
{
    static_assert(sizeof(HulkPadState) == 18, "HulkPadState is XINPUT_GAMEPAD");
#if HULK_APP_PAD_THREAD
    static int chosen;
    if (!chosen) {
        chosen = 1;
        const char* s = SDL_getenv("HULK_INPUT_SOURCE");      // (none / replay: the SDL layer's own sources)
        if (!s || !*s || SDL_strcmp(s, "sdl") == 0)
            hulk_input_set_source(&kAppSource);
    }
#endif
    HulkPadState s;
    if (!hulk_input_read(port, &s))
        return 0;
    // with a gamepad on port 0 the SDL layer stops reading the keyboard (kb_active); the app keeps both: the
    // keyboard's buttons and triggers add to the pad's, a stick the keyboard pushes overrides the pad's (wapp2)
    if (port == 0 && app_kb_env() && !APP_KB_ACTIVE() && SDL_WasInit(SDL_INIT_VIDEO)) {
        HulkPadState k;
        kb_read(&k);
        s.buttons |= k.buttons;
        for (int i = 0; i < 8; i++)
            if (k.analog[i] > s.analog[i])
                s.analog[i] = k.analog[i];
        if (k.thumb[HULK_THUMB_LX] || k.thumb[HULK_THUMB_LY]) {
            s.thumb[HULK_THUMB_LX] = k.thumb[HULK_THUMB_LX];
            s.thumb[HULK_THUMB_LY] = k.thumb[HULK_THUMB_LY];
        }
        if (k.thumb[HULK_THUMB_RX] || k.thumb[HULK_THUMB_RY]) {
            s.thumb[HULK_THUMB_RX] = k.thumb[HULK_THUMB_RX];
            s.thumb[HULK_THUMB_RY] = k.thumb[HULK_THUMB_RY];
        }
    }
    memcpy(out18, &s, 18);
    return 1;
}
