// The program's one SDL event pump (window and input). The window owner (pddi/sdl_platform.cpp in the native image,
// the smoke test on the host) calls hulk_platform_pump() once per frame; nobody else polls SDL's queue. Events reach
// the rest of the program two ways:
//   - the hub handles what it owns: close request / quit (hulk_platform_quit_requested), focus
//     (hulk_platform_has_focus), the attached window's pixel-size changes (the resize handler) and the fullscreen
//     keys (F11, Alt+Enter);
//   - every event is first offered to the registered listeners (a pointer to the SDL_Event). A subsystem that wants
//     events (keyboard, a recorded-input source, hot-plug notices) registers one instead of calling SDL_PollEvent,
//     which would steal the window's events. Everything else is dropped: the gamepad backend (input/hulk_input.cpp)
//     reads pad state with SDL_UpdateGamepads and SDL_GetGamepadAxis, not from the queue, and flushes the joystick
//     range itself.
// All of it runs on the thread that created the window (Windows delivers a window's messages to its thread).
// No SDL types here: callers in the image's XDK layer don't need SDL's headers.
#ifndef HULK_PLATFORM_EVENTS_H
#define HULK_PLATFORM_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

// SDL's video subsystem (reference counted); 1 on success, 0 if SDL3 can't be loaded or video fails (the reason is
// in hulk_platform_error()).
int hulk_platform_video_init(void);
void hulk_platform_video_quit(void);
const char* hulk_platform_error(void);

// Create the program's window (title, client size in pixels, hidden: don't show it, resizable). Returns SDL_Window*
// or 0. It is the window the pump's resize and fullscreen handling applies to.
void* hulk_platform_create_window(const char* title, int width, int height, int hidden, int resizable);

// The handles bgfx wants for the window: nwh/ndt as bgfx::PlatformData / SwapChain take them; *wayland is 1 when
// they are a Wayland surface/display (bgfx::NativeWindowHandleType::Wayland). 0 if the window has none.
int hulk_platform_native_handles(void* window, void** nwh, void** ndt, int* wayland);

void hulk_platform_pump(void);
int hulk_platform_quit_requested(void);
int hulk_platform_has_focus(void);
int hulk_platform_is_fullscreen(void);
int hulk_platform_toggle_fullscreen(void);       // 1: requested (the window manager completes it)

typedef void (*hulk_platform_listener_fn)(const void* sdl_event, void* user);
void hulk_platform_add_listener(hulk_platform_listener_fn fn, void* user);     // up to 8
// Called from the pump when the window's size in pixels changed (and differs from the last reported size)
typedef void (*hulk_platform_resize_fn)(int pixel_width, int pixel_height, void* user);
void hulk_platform_set_resize_handler(hulk_platform_resize_fn fn, void* user);

#ifdef __cplusplus
}
#endif

#endif
