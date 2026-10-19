// The SDL3 window and the one event pump with sa1's gamepad backend alive in the same process (tools/native_gfx.py
// window-test, host and i686 under Wine): a window exists, events go through hulk_platform_pump while the input
// backend polls pads, a close request and a focus change arrive, the fullscreen toggle runs, and the pad backend
// still reports its state (no pads on the test machine is fine: the checks are that nothing breaks or is consumed
// wrongly). Links the real backends: src/platform/sdl/input/hulk_input.cpp.
#include "../../platform_events.h"
#include "../../input/hulk_input.h"

#include <SDL3/SDL.h>
#include <stdio.h>
#include <string.h>

static int g_fail, g_checks;
#define CHECK(c, ...) \
    do { \
        g_checks++; \
        if (!(c)) { \
            g_fail++; \
            printf("FAIL %s:%d: ", __FILE__, __LINE__); \
            printf(__VA_ARGS__); \
            printf("\n"); \
        } \
    } while (0)

static int s_seen, s_resizes;
static void listener(const void* ev, void* user)
{
    (void)user;
    const SDL_Event* e = (const SDL_Event*)ev;
    if (e->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED || e->type == SDL_EVENT_WINDOW_FOCUS_GAINED)
        s_seen++;
}
static void onResize(int w, int h, void*)
{
    (void)w;
    (void)h;
    s_resizes++;
}

static void spin(int n)
{
    for (int i = 0; i < n; i++) {
        hulk_platform_pump();
        hulk_input_devices();              // sa1's source: SDL_UpdateGamepads (also flushes the joystick range)
        SDL_Delay(5);
    }
}

int test_main(void)
{
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI, "0");         // only our virtual pad (no host pads in the way)
    SDL_SetHint(SDL_HINT_JOYSTICK_RAWINPUT, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_DIRECTINPUT, "0");
    SDL_SetHint(SDL_HINT_XINPUT_ENABLED, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_MFI, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT, "0");
    CHECK(hulk_platform_video_init() == 1, "video init: %s", hulk_platform_error());
    void* w = hulk_platform_create_window("window test", 320, 240, 0, 1);
    CHECK(w != 0, "window: %s", hulk_platform_error());
    if (!w)
        return 1;
    void *nwh, *ndt;
    int wayland;
    CHECK(hulk_platform_native_handles(w, &nwh, &ndt, &wayland) && nwh != 0, "native handle");
    hulk_platform_add_listener(listener, 0);
    hulk_platform_set_resize_handler(onResize, 0);

    // the gamepad backend starts while the window exists and polls between pumps
    hulk_input_init();
    unsigned ins = 0, rem = 0;
    hulk_input_changes(&ins, &rem);
    spin(20);
    CHECK(!hulk_platform_quit_requested(), "no quit yet");

    // a virtual gamepad plugged in while the window's events are pumped: it appears in port 0 and its state arrives
    SDL_VirtualJoystickDesc vd;
    SDL_INIT_INTERFACE(&vd);
    vd.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    vd.naxes = SDL_GAMEPAD_AXIS_COUNT;
    vd.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    vd.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
    vd.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
    vd.name = "window test pad";
    SDL_JoystickID jid = SDL_AttachVirtualJoystick(&vd);
    CHECK(jid != 0, "virtual pad: %s", SDL_GetError());
    SDL_Joystick* joy = SDL_OpenJoystick(jid);
    spin(5);
    int any = hulk_input_changes(&ins, &rem);
    CHECK(any && ins == 1, "pad inserted into port 0 while the window pumps: %d %x", any, ins);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_SOUTH, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_START, true);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFTX, 32767);
    spin(5);
    HulkPadState st;
    memset(&st, 0, sizeof(st));
    CHECK(hulk_input_read(0, &st) == 1, "read port 0");
    CHECK(st.analog[HULK_PAD_A] == 255 && (st.buttons & HULK_PAD_START) && st.thumb[HULK_THUMB_LX] == 32767,
          "pad state with a window: A %u buttons %x LX %d", st.analog[0], st.buttons, st.thumb[0]);

    // a close request reaches the hub (and the listener) even though the pad backend runs
    SDL_Event e;
    memset(&e, 0, sizeof(e));
    e.type = SDL_EVENT_WINDOW_CLOSE_REQUESTED;
    e.window.windowID = SDL_GetWindowID((SDL_Window*)w);
    int before = s_seen;
    SDL_PushEvent(&e);
    spin(3);
    CHECK(hulk_platform_quit_requested() == 1, "close request seen");
    CHECK(s_seen > before, "listener saw the close request");

    // a joystick event pushed into the queue doesn't stop the window events behind it
    memset(&e, 0, sizeof(e));
    e.type = SDL_EVENT_JOYSTICK_AXIS_MOTION;
    SDL_PushEvent(&e);
    memset(&e, 0, sizeof(e));
    e.type = SDL_EVENT_WINDOW_FOCUS_LOST;
    e.window.windowID = SDL_GetWindowID((SDL_Window*)w);
    SDL_PushEvent(&e);
    spin(3);
    CHECK(hulk_platform_has_focus() == 0, "focus lost seen after a joystick event");
    e.type = SDL_EVENT_WINDOW_FOCUS_GAINED;
    SDL_PushEvent(&e);
    spin(3);
    CHECK(hulk_platform_has_focus() == 1, "focus regained");

    // fullscreen toggles (desktop-size; the window manager may take a moment) and back; the resize handler is
    // called for the size changes it brings
    int fs0 = hulk_platform_is_fullscreen();
    int req = hulk_platform_toggle_fullscreen();
    spin(200);
    int fs1 = hulk_platform_is_fullscreen();
    printf("window-test: fullscreen request %d: %d -> %d, %d resize callbacks (%s)\n", req, fs0, fs1, s_resizes,
           req ? "" : hulk_platform_error());
    // (a request to the window manager: macOS animates a Space change and a headless session may refuse it, so the
    // outcome is reported, not checked; what is checked is that the pump survives the size-change events)
    hulk_platform_toggle_fullscreen();
    spin(200);
    printf("window-test: fullscreen back %d\n", hulk_platform_is_fullscreen());

    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_START, false);
    spin(3);
    CHECK(hulk_input_read(0, &st) == 1 && !(st.buttons & HULK_PAD_START), "pad state still updates after the toggles");
    SDL_CloseJoystick(joy);
    SDL_DetachVirtualJoystick(jid);
    hulk_input_shutdown();
    hulk_platform_video_quit();
    printf("window-test: %d checks, %d failed -> %s\n", g_checks, g_fail, g_fail ? "FAIL" : "PASS");
    return g_fail ? 1 : 0;
}

#ifndef _WIN32
int main()
{
    return test_main();
}
#endif
