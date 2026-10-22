// The native input backend: SDL3 gamepads as Xbox controllers (hulk_input.h, docs/native-audio-input.md).
//
// No C++ dynamic initializers (the native image runs only the game's initializer table): plain static data.
#include "hulk_input.h"

#include <SDL3/SDL.h>

// the recorded-input source and checkpoint hashing are in this translation unit (replay/hulk_replay.cpp)
#include "../replay/hulk_replay.h"

// ---------------------------------------------------------------------------------------------
// conversions
unsigned char hulk_input_trigger(short v)
{
    if (v <= 0)
        return 0;
    return (unsigned char)(((int)v * 255 + 16383) / 32767);
}

short hulk_input_thumb_y(short v)
{
    // SDL: -32768 up .. 32767 down; Xbox (XInput): positive up. A sign convention, not an invert option.
    return v == -32768 ? (short)32767 : (short)-v;
}

// ---------------------------------------------------------------------------------------------
// the SDL3 gamepad source
struct SdlPort {
    SDL_JoystickID id;
    SDL_Gamepad* pad;
    unsigned gen;
    unsigned short rumble_l, rumble_r;
    Uint64 rumble_at;
};

static struct {
    int up;                     // SDL's gamepad subsystem initialized
    int failed;
    SdlPort port[HULK_INPUT_PORTS];
    unsigned gen;
} g_sdl;

static void sdl_up()
{
    if (g_sdl.up || g_sdl.failed)
        return;
    // the game's window is not SDL's: read pads whatever has focus
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD)) {
        SDL_Log("input: SDL gamepad init failed: %s (no pads)", SDL_GetError());
        g_sdl.failed = 1;
        return;
    }
    g_sdl.up = 1;
}

// ---------------------------------------------------------------------------------------------
// play1: the keyboard as a virtual pad on port 0 while no real gamepad is connected (and a window exists).
// HULK_KEYBOARD=0 turns it off; it is also off for a hidden window (unattended runs). Mapping (docs/native-play.md):
//   WASD left stick, IJKL right stick, arrows D-pad, Space A, F B, R X, G Y, Z White, X Black,
//   Left Shift left trigger, Left Ctrl right trigger, Enter Start, Esc Back, Tab L3, V R3.
#define KB_GEN 0x4b42u
static int kb_active(void)
{
    static int env = -1;
    if (env < 0) {
        const char* e = SDL_getenv("HULK_KEYBOARD");
        const char* h = SDL_getenv("HULK_GFX_HIDDEN");
        env = !((e && *e == '0') || (h && *h && *h != '0'));
    }
    if (!env || !SDL_WasInit(SDL_INIT_VIDEO))
        return 0;
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_sdl.port[p].id)
            return 0;
    static int logged;
    if (!logged) {
        logged = 1;
        SDL_Log("input: no gamepad: the keyboard is pad 0 (WASD IJKL arrows Space F R G Enter Esc; docs/native-play.md)");
    }
    return 1;
}

// HULK_KEY_SCRIPT="from-to:Key[+Key],...": hold keys (SDL key names, e.g. Return, Space, W) while the time since the first
// pad poll, in tenths of a second, is in [from, to). For unattended runs of the live path (tools/play.py --script).
struct KbScript { unsigned from, to; SDL_Scancode code[4]; int n; };
static KbScript g_script[64];
static int g_script_n = -1;
static unsigned g_polls;
static void kb_script_load()
{
    g_script_n = 0;
    const char* e = SDL_getenv("HULK_KEY_SCRIPT");
    while (e && *e && g_script_n < 64) {
        KbScript* sc = &g_script[g_script_n];
        SDL_memset(sc, 0, sizeof(*sc));
        char* end;
        sc->from = (unsigned)SDL_strtoul(e, &end, 10);
        if (*end != '-')
            break;
        sc->to = (unsigned)SDL_strtoul(end + 1, &end, 10);
        if (*end != ':')
            break;
        e = end + 1;
        while (*e && *e != ',' && sc->n < 4) {
            char name[24];
            int l = 0;
            while (*e && *e != '+' && *e != ',' && l < 23)
                name[l++] = *e++;
            name[l] = 0;
            SDL_Scancode c = SDL_GetScancodeFromName(name);
            if (c != SDL_SCANCODE_UNKNOWN)
                sc->code[sc->n++] = c;
            if (*e == '+')
                e++;
        }
        g_script_n++;
        if (*e == ',')
            e++;
    }
}

// play2: the keyboard map. Each control has up to two keys; HULK_KEYMAP=FILE (Windows path under Wine) overrides the
// defaults. File format (config/keymap.example.txt): "#" comments, one "Control = Key[, Key]" line each, SDL key names
// (Space, Return, Left Shift, W, Up, ...), control names as in the example file. Unknown lines are logged and skipped.
enum { KC_LUP, KC_LDOWN, KC_LLEFT, KC_LRIGHT, KC_RUP, KC_RDOWN, KC_RLEFT, KC_RRIGHT, KC_DUP, KC_DDOWN, KC_DLEFT,
       KC_DRIGHT, KC_A, KC_B, KC_X, KC_Y, KC_WHITE, KC_BLACK, KC_LTRIG, KC_RTRIG, KC_START, KC_BACK, KC_L3, KC_R3, KC_N };
struct KbCtl { const char* name; SDL_Scancode def; SDL_Scancode code[2]; };
#define KC(n, c) {n, c, {SDL_SCANCODE_UNKNOWN, SDL_SCANCODE_UNKNOWN}}
static KbCtl g_kc[KC_N] = {
    KC("LeftStickUp", SDL_SCANCODE_W), KC("LeftStickDown", SDL_SCANCODE_S), KC("LeftStickLeft", SDL_SCANCODE_A),
    KC("LeftStickRight", SDL_SCANCODE_D), KC("RightStickUp", SDL_SCANCODE_I), KC("RightStickDown", SDL_SCANCODE_K),
    KC("RightStickLeft", SDL_SCANCODE_J), KC("RightStickRight", SDL_SCANCODE_L), KC("DpadUp", SDL_SCANCODE_UP),
    KC("DpadDown", SDL_SCANCODE_DOWN), KC("DpadLeft", SDL_SCANCODE_LEFT), KC("DpadRight", SDL_SCANCODE_RIGHT),
    KC("A", SDL_SCANCODE_SPACE), KC("B", SDL_SCANCODE_F), KC("X", SDL_SCANCODE_R), KC("Y", SDL_SCANCODE_G),
    KC("White", SDL_SCANCODE_Z), KC("Black", SDL_SCANCODE_X), KC("LeftTrigger", SDL_SCANCODE_LSHIFT),
    KC("RightTrigger", SDL_SCANCODE_LCTRL), KC("Start", SDL_SCANCODE_RETURN), KC("Back", SDL_SCANCODE_ESCAPE),
    KC("LeftStickClick", SDL_SCANCODE_TAB), KC("RightStickClick", SDL_SCANCODE_V),
};
static int g_kc_loaded;

static SDL_Scancode kc_scancode(const char* name)
{
    static const struct { const char* a; const char* real; } kAlias[] = {
        {"Enter", "Return"}, {"Esc", "Escape"}, {"Shift", "Left Shift"}, {"Ctrl", "Left Ctrl"}, {"Alt", "Left Alt"},
        {"Control", "Left Ctrl"}, {"Backspace", "Backspace"}, {"Del", "Delete"},
    };
    for (unsigned i = 0; i < sizeof(kAlias) / sizeof(kAlias[0]); i++)
        if (SDL_strcasecmp(name, kAlias[i].a) == 0)
            name = kAlias[i].real;
    return SDL_GetScancodeFromName(name);
}

static char* kc_trim(char* p)
{
    while (*p == ' ' || *p == '\t' || *p == '\r')
        p++;
    char* e = p + SDL_strlen(p);
    while (e > p && (e[-1] == ' ' || e[-1] == '\t' || e[-1] == '\r'))
        *--e = 0;
    return p;
}

static void kc_load()
{
    g_kc_loaded = 1;
    for (int i = 0; i < KC_N; i++) {
        g_kc[i].code[0] = g_kc[i].def;
        g_kc[i].code[1] = SDL_SCANCODE_UNKNOWN;
    }
    const char* path = SDL_getenv("HULK_KEYMAP");
    if (!path || !*path)
        return;
    size_t len = 0;
    char* text = (char*)SDL_LoadFile(path, &len);
    if (!text) {
        SDL_Log("input: HULK_KEYMAP %s: %s (default keys)", path, SDL_GetError());
        return;
    }
    char* nl = (char*)SDL_malloc(len + 1);
    SDL_memcpy(nl, text, len);
    nl[len] = 0;
    SDL_free(text);
    int set = 0;
    for (char* line = nl; line && *line;) {
        char* next = SDL_strchr(line, '\n');
        if (next)
            *next++ = 0;
        char* hash = SDL_strchr(line, '#');
        if (hash)
            *hash = 0;
        line = kc_trim(line);
        char* eq = SDL_strchr(line, '=');
        if (*line && eq) {
            *eq = 0;
            char* key = kc_trim(line);
            int ctl = -1;
            for (int i = 0; i < KC_N; i++)
                if (SDL_strcasecmp(key, g_kc[i].name) == 0)
                    ctl = i;
            if (ctl < 0)
                SDL_Log("input: HULK_KEYMAP: unknown control '%s'", key);
            else {
                SDL_Scancode got[2] = {SDL_SCANCODE_UNKNOWN, SDL_SCANCODE_UNKNOWN};
                int n = 0;
                for (char* v = eq + 1; v && n < 2;) {
                    char* comma = SDL_strchr(v, ',');
                    if (comma)
                        *comma = 0;
                    char* nm = kc_trim(v);
                    if (*nm) {
                        SDL_Scancode c = kc_scancode(nm);
                        if (c == SDL_SCANCODE_UNKNOWN)
                            SDL_Log("input: HULK_KEYMAP: unknown key '%s' for %s", nm, g_kc[ctl].name);
                        else
                            got[n++] = c;
                    }
                    v = comma ? comma + 1 : 0;
                }
                if (n) {                       // an empty value keeps the default
                    g_kc[ctl].code[0] = got[0];
                    g_kc[ctl].code[1] = got[1];
                    set++;
                }
            }
        }
        line = next;
    }
    SDL_free(nl);
    SDL_Log("input: key map %s: %d controls set", path, set);
}

static bool kc_down(const bool* k, int c)
{
    return k[g_kc[c].code[0]] || (g_kc[c].code[1] != SDL_SCANCODE_UNKNOWN && k[g_kc[c].code[1]]);
}

static int kb_read(HulkPadState* s)
{
    const bool* real = SDL_GetKeyboardState(0);
    bool ks[SDL_SCANCODE_COUNT];
    SDL_memset(s, 0, sizeof(*s));
    SDL_memset(ks, 0, sizeof(ks));
    if (real)
        for (int i = 0; i < SDL_SCANCODE_COUNT; i++)
            ks[i] = real[i];
    if (g_script_n < 0)
        kb_script_load();
    if (!g_kc_loaded)
        kc_load();
    g_polls++;
    if (g_polls == 1 || g_polls % 5000 == 0)
        SDL_Log("input: keyboard pad poll %u", g_polls);
    static Uint64 t0;
    if (!t0)
        t0 = SDL_GetTicks();
    unsigned dsec = (unsigned)((SDL_GetTicks() - t0) / 100);       // tenths of a second since the first poll
    for (int i = 0; i < g_script_n; i++)
        if (dsec >= g_script[i].from && dsec < g_script[i].to)
            for (int j = 0; j < g_script[i].n; j++)
                ks[g_script[i].code[j]] = true;
    const bool* k = ks;
    static const struct { int c; unsigned short bit; } kDig[] = {
        {KC_DUP, HULK_PAD_DPAD_UP}, {KC_DDOWN, HULK_PAD_DPAD_DOWN}, {KC_DLEFT, HULK_PAD_DPAD_LEFT},
        {KC_DRIGHT, HULK_PAD_DPAD_RIGHT}, {KC_START, HULK_PAD_START}, {KC_BACK, HULK_PAD_BACK},
        {KC_L3, HULK_PAD_LEFT_THUMB}, {KC_R3, HULK_PAD_RIGHT_THUMB},
    };
    for (unsigned i = 0; i < sizeof(kDig) / sizeof(kDig[0]); i++)
        if (kc_down(k, kDig[i].c))
            s->buttons |= kDig[i].bit;
    static const struct { int c; int slot; } kAn[] = {
        {KC_A, HULK_PAD_A}, {KC_B, HULK_PAD_B}, {KC_X, HULK_PAD_X}, {KC_Y, HULK_PAD_Y}, {KC_BLACK, HULK_PAD_BLACK},
        {KC_WHITE, HULK_PAD_WHITE}, {KC_LTRIG, HULK_PAD_LEFT_TRIGGER}, {KC_RTRIG, HULK_PAD_RIGHT_TRIGGER},
    };
    for (unsigned i = 0; i < sizeof(kAn) / sizeof(kAn[0]); i++)
        if (kc_down(k, kAn[i].c))
            s->analog[kAn[i].slot] = 255;
    s->thumb[HULK_THUMB_LX] = (short)((kc_down(k, KC_LRIGHT) ? 32767 : 0) - (kc_down(k, KC_LLEFT) ? 32767 : 0));
    s->thumb[HULK_THUMB_LY] = (short)((kc_down(k, KC_LUP) ? 32767 : 0) - (kc_down(k, KC_LDOWN) ? 32767 : 0));
    s->thumb[HULK_THUMB_RX] = (short)((kc_down(k, KC_RRIGHT) ? 32767 : 0) - (kc_down(k, KC_RLEFT) ? 32767 : 0));
    s->thumb[HULK_THUMB_RY] = (short)((kc_down(k, KC_RUP) ? 32767 : 0) - (kc_down(k, KC_RDOWN) ? 32767 : 0));
    return 1;
}

static void sdl_update(void*)
{
    sdl_up();
    if (!g_sdl.up)
        return;
    SDL_UpdateGamepads();          // also runs the joystick drivers' device detection (hot-plug)
    // nobody reads SDL's event queue in the image: drop the joystick / gamepad events it collects
    SDL_FlushEvents(SDL_EVENT_JOYSTICK_AXIS_MOTION, SDL_EVENT_JOYSTICK_AXIS_MOTION + 0xff);
    int n = 0;
    SDL_JoystickID* ids = SDL_GetGamepads(&n);
    // play2: say what SDL sees whenever the numbers change (a pad that shows as a joystick but not a gamepad has no
    // mapping; neither listed means the host (Wine's HID layer) did not hand the device over): docs/native-play.md
    static int seen_j = -1, seen_g = -1;
    int nj = 0;
    SDL_JoystickID* js = SDL_GetJoysticks(&nj);
    if (nj != seen_j || n != seen_g) {
        seen_j = nj;
        seen_g = n;
        SDL_Log("input: SDL sees %d joystick(s), %d gamepad(s)", nj, n);
        for (int i = 0; i < nj; i++)
            SDL_Log("input:   joystick %d: %s%s", i, SDL_GetJoystickNameForID(js[i]) ? SDL_GetJoystickNameForID(js[i]) : "?",
                    SDL_IsGamepad(js[i]) ? " (gamepad)" : " (no gamepad mapping)");
    }
    SDL_free(js);
    // gone
    for (int p = 0; p < HULK_INPUT_PORTS; p++) {
        SdlPort* sp = &g_sdl.port[p];
        if (!sp->id)
            continue;
        bool present = false;
        for (int i = 0; i < n; i++)
            present = present || ids[i] == sp->id;
        if (!present || !SDL_GamepadConnected(sp->pad)) {
            SDL_CloseGamepad(sp->pad);
            sp->pad = 0;
            sp->id = 0;
        }
    }
    // new: the first free port
    for (int i = 0; i < n; i++) {
        bool known = false;
        for (int p = 0; p < HULK_INPUT_PORTS; p++)
            known = known || g_sdl.port[p].id == ids[i];
        if (known)
            continue;
        for (int p = 0; p < HULK_INPUT_PORTS; p++) {
            SdlPort* sp = &g_sdl.port[p];
            if (sp->id)
                continue;
            sp->pad = SDL_OpenGamepad(ids[i]);
            if (sp->pad) {
                sp->id = ids[i];
                sp->gen = ++g_sdl.gen;
                sp->rumble_l = sp->rumble_r = 0;
                SDL_SetGamepadPlayerIndex(sp->pad, p);
            }
            break;
        }
    }
    SDL_free(ids);
    // SDL rumble lasts at most 65 s per call; the game sends only changes, so long rumbles are renewed here
    Uint64 now = SDL_GetTicks();
    for (int p = 0; p < HULK_INPUT_PORTS; p++) {
        SdlPort* sp = &g_sdl.port[p];
        if (sp->pad && (sp->rumble_l || sp->rumble_r) && now - sp->rumble_at > 30000) {
            SDL_RumbleGamepad(sp->pad, sp->rumble_l, sp->rumble_r, 0xffff);
            sp->rumble_at = now;
        }
    }
}

static unsigned sdl_connected(void*)
{
    unsigned m = kb_active() ? 1u : 0u;
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_sdl.port[p].id)
            m |= 1u << p;
    return m;
}

static unsigned sdl_generation(void*, unsigned port)
{
    if (port == 0 && kb_active())
        return KB_GEN;
    return port < HULK_INPUT_PORTS ? g_sdl.port[port].gen : 0;
}

static int sdl_read(void*, unsigned port, HulkPadState* s)
{
    if (port == 0 && kb_active())
        return kb_read(s);
    if (port >= HULK_INPUT_PORTS || !g_sdl.port[port].pad)
        return 0;
    SDL_Gamepad* g = g_sdl.port[port].pad;
    SDL_memset(s, 0, sizeof(*s));
    static const struct { SDL_GamepadButton b; unsigned short bit; } kDigital[] = {
        {SDL_GAMEPAD_BUTTON_DPAD_UP, HULK_PAD_DPAD_UP},       {SDL_GAMEPAD_BUTTON_DPAD_DOWN, HULK_PAD_DPAD_DOWN},
        {SDL_GAMEPAD_BUTTON_DPAD_LEFT, HULK_PAD_DPAD_LEFT},   {SDL_GAMEPAD_BUTTON_DPAD_RIGHT, HULK_PAD_DPAD_RIGHT},
        {SDL_GAMEPAD_BUTTON_START, HULK_PAD_START},           {SDL_GAMEPAD_BUTTON_BACK, HULK_PAD_BACK},
        {SDL_GAMEPAD_BUTTON_LEFT_STICK, HULK_PAD_LEFT_THUMB}, {SDL_GAMEPAD_BUTTON_RIGHT_STICK, HULK_PAD_RIGHT_THUMB},
    };
    for (unsigned i = 0; i < sizeof(kDigital) / sizeof(kDigital[0]); i++)
        if (SDL_GetGamepadButton(g, kDigital[i].b))
            s->buttons |= kDigital[i].bit;
    // analog face buttons: SDL's are digital -> 0 or 255. Black/White sit where a modern pad has its shoulders.
    static const struct { SDL_GamepadButton b; int slot; } kAnalog[] = {
        {SDL_GAMEPAD_BUTTON_SOUTH, HULK_PAD_A},          {SDL_GAMEPAD_BUTTON_EAST, HULK_PAD_B},
        {SDL_GAMEPAD_BUTTON_WEST, HULK_PAD_X},           {SDL_GAMEPAD_BUTTON_NORTH, HULK_PAD_Y},
        {SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, HULK_PAD_BLACK}, {SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, HULK_PAD_WHITE},
    };
    for (unsigned i = 0; i < sizeof(kAnalog) / sizeof(kAnalog[0]); i++)
        s->analog[kAnalog[i].slot] = SDL_GetGamepadButton(g, kAnalog[i].b) ? 255 : 0;
    s->analog[HULK_PAD_LEFT_TRIGGER] = hulk_input_trigger(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFT_TRIGGER));
    s->analog[HULK_PAD_RIGHT_TRIGGER] = hulk_input_trigger(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER));
    s->thumb[HULK_THUMB_LX] = SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFTX);
    s->thumb[HULK_THUMB_LY] = hulk_input_thumb_y(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_LEFTY));
    s->thumb[HULK_THUMB_RX] = SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHTX);
    s->thumb[HULK_THUMB_RY] = hulk_input_thumb_y(SDL_GetGamepadAxis(g, SDL_GAMEPAD_AXIS_RIGHTY));
    return 1;
}

static void sdl_rumble(void*, unsigned port, unsigned short left, unsigned short right)
{
    if (port >= HULK_INPUT_PORTS || !g_sdl.port[port].pad)
        return;
    SdlPort* sp = &g_sdl.port[port];
    sp->rumble_l = left;
    sp->rumble_r = right;
    sp->rumble_at = SDL_GetTicks();
    // the Xbox's left motor is the large, low-frequency one
    SDL_RumbleGamepad(sp->pad, left, right, (left || right) ? 0xffff : 0);
}

static const HulkInputSource kSdlSource = {"sdl", 0, sdl_update, sdl_connected, sdl_generation, sdl_read, sdl_rumble, 0};

// a source with no pads (HULK_INPUT_SOURCE=none)
static void none_update(void*) {}
static unsigned none_connected(void*) { return 0; }
static unsigned none_generation(void*, unsigned) { return 0; }
static int none_read(void*, unsigned, HulkPadState*) { return 0; }
static void none_rumble(void*, unsigned, unsigned short, unsigned short) {}
static const HulkInputSource kNoneSource = {"none", 0, none_update, none_connected, none_generation, none_read,
                                            none_rumble, 0};

const HulkInputSource* hulk_input_sdl_source(void)
{
    return &kSdlSource;
}

// ---------------------------------------------------------------------------------------------
// Xbox semantics
static struct {
    int up;
    const HulkInputSource* src;
    unsigned reported;                       // the ports the game has been told about
    unsigned reported_gen[HULK_INPUT_PORTS];
    Uint64 last_update;
} g_in;

int hulk_input_init(void)
{
    if (g_in.up)
        return 1;
    g_in.up = 1;
    if (!g_in.src) {
        const char* s = SDL_getenv("HULK_INPUT_SOURCE");
        if (s && SDL_strcmp(s, "none") == 0)
            g_in.src = &kNoneSource;
        else if (s && SDL_strncmp(s, "replay:", 7) == 0) {
            // a bad recording must not fall back to live pads: the run would silently not be a replay
            if (hulk_replay_open(s + 7)) {
                g_in.src = hulk_replay_source();
                HulkReplayInfo ri;
                hulk_replay_info(&ri);
                SDL_Log("input: replay %s: %u entries keyed by %s, %u virtual pad(s), %u checkpoints", s + 7,
                        ri.entries, ri.frame_keyed ? "frame" : "poll", ri.vpad_count, ri.checkpoints);
            } else {
                SDL_Log("input: %s (no pads)", hulk_replay_error());
                g_in.src = &kNoneSource;
            }
        } else {
            if (s && *s && SDL_strcmp(s, "sdl") != 0)
                SDL_Log("input: unknown source '%s'; using SDL gamepads", s);
            g_in.src = &kSdlSource;
        }
    }
    g_in.src->update(g_in.src->self);
    SDL_Log("input: source %s, pads 0x%x", g_in.src->name, g_in.src->connected(g_in.src->self));
    return 1;
}

void hulk_input_shutdown(void)
{
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_sdl.port[p].pad) {
            SDL_CloseGamepad(g_sdl.port[p].pad);
            g_sdl.port[p].pad = 0;
            g_sdl.port[p].id = 0;
        }
    if (g_sdl.up)
        SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
    g_sdl.up = 0;
    g_sdl.failed = 0;
    g_in.up = 0;
    g_in.reported = 0;
}

void hulk_input_set_source(const HulkInputSource* src)
{
    g_in.src = src;
    g_in.reported = 0;
}

const HulkInputSource* hulk_input_source(void)
{
    hulk_input_init();
    return g_in.src;
}

unsigned hulk_input_devices(void)
{
    hulk_input_init();
    g_in.src->update(g_in.src->self);
    return g_in.src->connected(g_in.src->self) & 0xf;
}

int hulk_input_changes(unsigned* inserted, unsigned* removed)
{
    hulk_input_init();
    g_in.src->update(g_in.src->self);
    unsigned now = g_in.src->connected(g_in.src->self);
    unsigned ins = 0, rem = 0;
    for (unsigned p = 0; p < HULK_INPUT_PORTS; p++) {
        unsigned bit = 1u << p;
        unsigned gen = (now & bit) ? g_in.src->generation(g_in.src->self, p) : 0;
        bool was = (g_in.reported & bit) != 0, is = (now & bit) != 0;
        if (was && (!is || gen != g_in.reported_gen[p]))
            rem |= bit;                          // gone, or replaced by another pad since the last call
        if (is && (!was || gen != g_in.reported_gen[p]))
            ins |= bit;
        g_in.reported_gen[p] = gen;
    }
    g_in.reported = now & 0xf;
    if (inserted)
        *inserted = ins;
    if (removed)
        *removed = rem;
    return (ins | rem) != 0;
}

int hulk_input_read(unsigned port, HulkPadState* out)
{
    hulk_input_init();
    // fresh state for each round of polls (the game reads every pad once per update)
    Uint64 now = SDL_GetTicksNS();
    if (now - g_in.last_update > 2000000ull) {
        g_in.src->update(g_in.src->self);
        g_in.last_update = now;
    }
    return g_in.src->read(g_in.src->self, port, out);
}

int hulk_input_read_init(unsigned port, HulkPadState* out)
{
    hulk_input_init();
    return g_in.src->read_init ? g_in.src->read_init(g_in.src->self, port, out)
                               : g_in.src->read(g_in.src->self, port, out);
}

void hulk_input_rumble(unsigned port, unsigned short left, unsigned short right)
{
    hulk_input_init();
    g_in.src->rumble(g_in.src->self, port, left, right);
}

unsigned hulk_input_generation(unsigned port)
{
    hulk_input_init();
    return g_in.src->generation(g_in.src->self, port);
}

#include "../replay/hulk_replay.cpp"
