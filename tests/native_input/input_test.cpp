// Input backend smoke test (docs/native-audio-input.md): SDL3 virtual gamepads -> the Xbox controller state the
// game reads (buttons, analog buttons, thumbs, triggers), hot-plug through XGetDeviceChanges' semantics, rumble.
// Host: the typed API (src/platform/sdl/input/hulk_input.h). HULK_TEST_XDK (i686 under Wine): the same through the
// hulk_xdk_* stand-ins with the game's 22-byte XINPUT_STATE and feedback block (src/platform/sdl/xdk/input_xpp.cpp).
#include "input/hulk_input.h"
#include "../native_audio/test_common.h"

#ifdef HULK_TEST_XDK
#include "xdk/imports.h"
extern "C" hulk_u32 hulk_lib_xpp_gamepad_type[1];
extern "C" hulk_u32 hulk_lib_xpp_mu_type[1];
#endif

// ---------------------------------------------------------------------------------------------
// virtual pads
struct Rumble {
    int calls;
    Uint16 low, high;
};
static Rumble g_rumble[2];

static bool SDLCALL rumble_cb(void* user, Uint16 low, Uint16 high)
{
    Rumble* r = (Rumble*)user;
    r->calls++;
    r->low = low;
    r->high = high;
    return true;
}

static SDL_JoystickID attach(int which)
{
    SDL_VirtualJoystickDesc d;
    SDL_INIT_INTERFACE(&d);
    d.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    d.naxes = SDL_GAMEPAD_AXIS_COUNT;
    d.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    d.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
    d.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
    d.name = which ? "hulk virtual pad 2" : "hulk virtual pad 1";
    d.userdata = &g_rumble[which];
    d.Rumble = rumble_cb;
    SDL_JoystickID id = SDL_AttachVirtualJoystick(&d);
    CHECK(id != 0, "attach virtual pad: %s", SDL_GetError());
    return id;
}

// ---------------------------------------------------------------------------------------------
// the API under test (the gamepad state as the game sees it: 22 bytes, packet number first)
#ifdef HULK_TEST_XDK
typedef hulk_u32 H;
static hulk_u32 pad_type() { return TEST_PTR(hulk_lib_xpp_gamepad_type); }
static void api_init() { hulk_xdk_XInitDevices(0, 0); }
static int changes(unsigned* ins, unsigned* rem)
{
    hulk_u32 i = 0xdead, r = 0xdead;
    int any = (int)hulk_xdk_XGetDeviceChanges(pad_type(), TEST_PTR(&i), TEST_PTR(&r));
    *ins = i;
    *rem = r;
    return any;
}
static unsigned devices() { return hulk_xdk_XGetDevices(pad_type()); }
static H open_port(unsigned port) { return hulk_xdk_XInputOpen(pad_type(), port, 0, 0); }
static void close_h(H h) { hulk_xdk_XInputClose(h); }
static unsigned get_state(H h, unsigned* packet, HulkPadState* s)
{
    unsigned char st[22];
    SDL_memset(st, 0xcc, sizeof(st));
    unsigned rc = hulk_xdk_XInputGetState(h, TEST_PTR(st));
    SDL_memcpy(packet, st, 4);
    SDL_memcpy(&s->buttons, st + 4, 2);
    SDL_memcpy(s->analog, st + 6, 8);
    SDL_memcpy(s->thumb, st + 14, 8);
    return rc;
}
static unsigned set_rumble(H h, unsigned short l, unsigned short r)
{
    // the game's feedback block (ControllerXBox +0x458): status, ..., motors at +0x42
    unsigned char fb[0x46];
    SDL_memset(fb, 0, sizeof(fb));
    hulk_u32 pending = 997;                            // ERROR_IO_PENDING, as the game leaves it
    SDL_memcpy(fb, &pending, 4);
    SDL_memcpy(fb + 0x42, &l, 2);
    SDL_memcpy(fb + 0x44, &r, 2);
    hulk_xdk_XInputSetState(h, TEST_PTR(fb));
    hulk_u32 status;
    SDL_memcpy(&status, fb, 4);
    return status;
}
#else
typedef int H;                                         // the port + 1 (0: none), and the generation it was opened at
static unsigned g_open_gen[8];
static void api_init() { hulk_input_init(); }
static int changes(unsigned* ins, unsigned* rem) { return hulk_input_changes(ins, rem); }
static unsigned devices() { return hulk_input_devices(); }
static H open_port(unsigned port)
{
    if (!(hulk_input_devices() & (1u << port)))
        return 0;
    g_open_gen[port] = hulk_input_generation(port);
    return (H)port + 1;
}
static void close_h(H) {}
static unsigned g_packet[4];
static HulkPadState g_last[4];
static unsigned get_state(H h, unsigned* packet, HulkPadState* s)
{
    unsigned port = (unsigned)h - 1;
    if (!h || hulk_input_generation(port) != g_open_gen[port] || !hulk_input_read(port, s))
        return 1167;
    if (SDL_memcmp(s, &g_last[port], sizeof(*s)) != 0)
        g_packet[port]++;
    g_last[port] = *s;
    *packet = g_packet[port];
    return 0;
}
static unsigned set_rumble(H h, unsigned short l, unsigned short r)
{
    hulk_input_rumble((unsigned)h - 1, l, r);
    return 0;
}
#endif

static void settle()
{
    SDL_Delay(5);                                      // past the backend's 2 ms poll interval
}

int test_main(void)
{
    // units: SDL's ranges -> the Xbox's
    CHECK(hulk_input_trigger(0) == 0 && hulk_input_trigger(32767) == 255 && hulk_input_trigger(16384) == 128 &&
              hulk_input_trigger(-5) == 0,
          "trigger mapping %d %d %d", hulk_input_trigger(0), hulk_input_trigger(32767), hulk_input_trigger(16384));
    CHECK(hulk_input_thumb_y(-32768) == 32767 && hulk_input_thumb_y(32767) == -32767 && hulk_input_thumb_y(0) == 0 &&
              hulk_input_thumb_y(1000) == -1000,
          "thumb y");

    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI, "0");         // only our virtual pads (no host pads in the way)
    SDL_SetHint(SDL_HINT_JOYSTICK_RAWINPUT, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_DIRECTINPUT, "0");
    SDL_SetHint(SDL_HINT_XINPUT_ENABLED, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_MFI, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT, "0");
    api_init();
    unsigned ins = 0, rem = 0;
    int any = changes(&ins, &rem);
    CHECK(!any && ins == 0 && rem == 0 && devices() == 0, "no pads at start: %d %x %x %x", any, ins, rem, devices());
    CHECK(open_port(0) == 0, "open without a pad");

    // plug in: the next device check reports port 0 inserted (the game opens pads only from it)
    SDL_JoystickID id = attach(0);
    SDL_Joystick* joy = SDL_OpenJoystick(id);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 0 && devices() == 1, "insert: %d %x %x %x", any, ins, rem, devices());
    any = changes(&ins, &rem);
    CHECK(!any && ins == 0 && rem == 0, "reported once: %x %x", ins, rem);
    H h = open_port(0);
    CHECK(h != 0, "open port 0");

    unsigned packet = 0, p0;
    HulkPadState s;
    CHECK(get_state(h, &p0, &s) == 0 && s.buttons == 0 && s.thumb[0] == 0, "idle pad: buttons %x", s.buttons);

    // every input of the Xbox pad
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_SOUTH, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_NORTH, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, true);      // Black
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_DPAD_UP, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_DPAD_RIGHT, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_START, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_RIGHT_STICK, true);
    // (a virtual pad's trigger axes span -32768..32767, which SDL's gamepad layer maps to 0..32767: 0 is 16383, 127 of 255)
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFT_TRIGGER, 0);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER, 32767);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFTX, 32767);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFTY, -32768);     // stick pushed up
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHTX, -12345);    // right stick left: stays negative
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHTY, 1000);      // slightly down
    settle();
    unsigned rc = get_state(h, &packet, &s);
    printf("state: rc %u packet %u buttons 0x%02x analog %u %u %u %u %u %u %u %u thumbs %d %d %d %d\n", rc, packet,
           s.buttons, s.analog[0], s.analog[1], s.analog[2], s.analog[3], s.analog[4], s.analog[5], s.analog[6],
           s.analog[7], s.thumb[0], s.thumb[1], s.thumb[2], s.thumb[3]);
    CHECK(rc == 0 && packet == p0 + 1, "packet %u -> %u", p0, packet);
    CHECK(s.buttons == (HULK_PAD_DPAD_UP | HULK_PAD_DPAD_RIGHT | HULK_PAD_START | HULK_PAD_RIGHT_THUMB),
          "buttons 0x%x", s.buttons);
    CHECK(s.analog[HULK_PAD_A] == 255 && s.analog[HULK_PAD_B] == 0 && s.analog[HULK_PAD_X] == 0 &&
              s.analog[HULK_PAD_Y] == 255 && s.analog[HULK_PAD_BLACK] == 255 && s.analog[HULK_PAD_WHITE] == 0,
          "analog buttons");
    CHECK(s.analog[HULK_PAD_LEFT_TRIGGER] == 127 && s.analog[HULK_PAD_RIGHT_TRIGGER] == 255, "triggers %u %u",
          s.analog[6], s.analog[7]);
    CHECK(s.thumb[HULK_THUMB_LX] == 32767 && s.thumb[HULK_THUMB_LY] == 32767 && s.thumb[HULK_THUMB_RX] == -12345 &&
              s.thumb[HULK_THUMB_RY] == -1000,
          "thumbs %d %d %d %d", s.thumb[0], s.thumb[1], s.thumb[2], s.thumb[3]);

    // the packet number moves only when the state does
    settle();
    unsigned packet2;
    get_state(h, &packet2, &s);
    CHECK(packet2 == packet, "packet moved without a change: %u -> %u", packet, packet2);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_SOUTH, false);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, true);       // White
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_BACK, true);
    settle();
    get_state(h, &packet2, &s);
    CHECK(packet2 == packet + 1 && s.analog[HULK_PAD_A] == 0 && s.analog[HULK_PAD_WHITE] == 255 &&
              (s.buttons & HULK_PAD_BACK),
          "change: packet %u A %u White %u buttons %x", packet2, s.analog[0], s.analog[5], s.buttons);

    // rumble: the game's motor words reach the pad (left = low frequency); the request completes at once
    unsigned status = set_rumble(h, 0x8000, 0x4000);
    settle();
    SDL_UpdateGamepads();
    printf("rumble: %d calls, low 0x%04x high 0x%04x, feedback status %u\n", g_rumble[0].calls, g_rumble[0].low,
           g_rumble[0].high, status);
    CHECK(g_rumble[0].calls >= 1 && g_rumble[0].low == 0x8000 && g_rumble[0].high == 0x4000, "rumble %d %x %x",
          g_rumble[0].calls, g_rumble[0].low, g_rumble[0].high);
    CHECK(status == 0, "feedback status %u (the game waits while it reads 997)", status);
    set_rumble(h, 0, 0);
    CHECK(g_rumble[0].low == 0 && g_rumble[0].high == 0, "rumble off");

    // a second pad takes port 1
    SDL_JoystickID id2 = attach(1);
    any = changes(&ins, &rem);
    CHECK(any && ins == 2 && rem == 0 && devices() == 3, "second pad: %x %x %x", ins, rem, devices());

    // unplug pad 1: removed, its handle fails; plug it back: inserted again, a new handle works
    SDL_CloseJoystick(joy);
    SDL_DetachVirtualJoystick(id);
    any = changes(&ins, &rem);
    CHECK(any && ins == 0 && rem == 1 && devices() == 2, "unplug: %x %x %x", ins, rem, devices());
    CHECK(get_state(h, &packet, &s) == 1167, "a removed pad reads ERROR_DEVICE_NOT_CONNECTED");
    close_h(h);
    id = attach(0);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 0 && devices() == 3, "replug: %x %x %x", ins, rem, devices());
    H h2 = open_port(0);
    CHECK(h2 != 0 && get_state(h2, &packet, &s) == 0, "the replugged pad reads");

    // unplug and replug between two device checks: reported as removed and inserted (a new pad in that port)
    SDL_DetachVirtualJoystick(id);
    SDL_UpdateGamepads();
    id = attach(0);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 1, "swap between checks: %x %x", ins, rem);
    CHECK(get_state(h2, &packet, &s) == 1167, "the old handle of a swapped port fails");
    close_h(h2);

#ifdef HULK_TEST_XDK
    // memory units: none
    hulk_u32 mi = 0xdead, mr = 0xdead;
    CHECK(hulk_xdk_XGetDevices(TEST_PTR(hulk_lib_xpp_mu_type)) == 0 && hulk_xdk_XGetDeviceChanges(0x3ea820, TEST_PTR(&mi), TEST_PTR(&mr)) == 0 &&
              mi == 0 && mr == 0,
          "memory units");
    CHECK(hulk_xdk_XGetDevices(0x3ea774) == 3, "the gamepad type by its XBE address");
#endif
    SDL_DetachVirtualJoystick(id);
    SDL_DetachVirtualJoystick(id2);
    hulk_input_shutdown();
#ifdef HULK_TEST_XDK
    return test_done("native_input (xdk, i686)");
#else
    return test_done("native_input (host)");
#endif
}
