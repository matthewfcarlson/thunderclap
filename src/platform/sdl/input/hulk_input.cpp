// The native input backend: SDL3 gamepads as Xbox controllers (hulk_input.h, docs/native-audio-input.md).
//
// No C++ dynamic initializers (the native image runs only the game's initializer table): plain static data.
#include "hulk_input.h"

#include <SDL3/SDL.h>

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
    unsigned m = 0;
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_sdl.port[p].id)
            m |= 1u << p;
    return m;
}

static unsigned sdl_generation(void*, unsigned port)
{
    return port < HULK_INPUT_PORTS ? g_sdl.port[port].gen : 0;
}

static int sdl_read(void*, unsigned port, HulkPadState* s)
{
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

static const HulkInputSource kSdlSource = {"sdl", 0, sdl_update, sdl_connected, sdl_generation, sdl_read, sdl_rumble};

// a source with no pads (HULK_INPUT_SOURCE=none)
static void none_update(void*) {}
static unsigned none_connected(void*) { return 0; }
static unsigned none_generation(void*, unsigned) { return 0; }
static int none_read(void*, unsigned, HulkPadState*) { return 0; }
static void none_rumble(void*, unsigned, unsigned short, unsigned short) {}
static const HulkInputSource kNoneSource = {"none", 0, none_update, none_connected, none_generation, none_read,
                                            none_rumble};

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
        else {
            if (s && *s && SDL_strcmp(s, "sdl") != 0)
                SDL_Log("input: source '%s' is not built yet (replay: design only); using SDL gamepads", s);
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
