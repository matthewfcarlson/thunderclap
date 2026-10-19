// The SDL3 window creation and the one event pump (platform_events.h), and the SDL table (hulk_sdl_api.h).
#include "platform_events.h"
#include "hulk_sdl_api.h"

#if defined(_WIN32) && !defined(HULK_SDL_LINKED)
#define HULK_SDL_DYNAMIC 1
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <stdint.h>
#include <string.h>

static HulkSdlApi s_api;
static bool s_apiTried, s_apiOk;
static char s_error[256];

static void setError(const char* msg)
{
    strncpy(s_error, msg, sizeof(s_error) - 1);
    s_error[sizeof(s_error) - 1] = 0;
}

const HulkSdlApi* hulk_sdl_api(void)
{
    if (s_apiTried)
        return s_apiOk ? &s_api : 0;
    s_apiTried = true;
#if HULK_SDL_DYNAMIC
    HMODULE m = LoadLibraryA("SDL3.dll");        // the audio/input backends link the same DLL: one SDL in the process
    if (!m) {
        setError("SDL3.dll not found");
        return 0;
    }
    bool ok = true;
#define X(n) \
    s_api.n = (decltype(s_api.n))GetProcAddress(m, #n); \
    if (!s_api.n) { setError("SDL3.dll lacks " #n); ok = false; }
    HULK_SDL_FUNCS(X)
#undef X
    s_apiOk = ok;
#else
#define X(n) s_api.n = &n;
    HULK_SDL_FUNCS(X)
#undef X
    s_apiOk = true;
#endif
    return s_apiOk ? &s_api : 0;
}

const char* hulk_platform_error(void)
{
    return s_error;
}

// ---- state
static int s_videoRefs;
static SDL_Window* s_window;
static SDL_WindowID s_windowId;
static bool s_quit, s_focus = true;
static int s_lastW, s_lastH;
static hulk_platform_resize_fn s_resizeFn;
static void* s_resizeUser;
static struct { hulk_platform_listener_fn fn; void* user; } s_listeners[8];
static int s_listenerCount;

int hulk_platform_video_init(void)
{
    const HulkSdlApi* a = hulk_sdl_api();
    if (!a)
        return 0;
    if (s_videoRefs == 0 && !a->SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        setError(a->SDL_GetError());
        return 0;
    }
    s_videoRefs++;
    return 1;
}

void hulk_platform_video_quit(void)
{
    const HulkSdlApi* a = hulk_sdl_api();
    if (!a || s_videoRefs == 0)
        return;
    if (--s_videoRefs == 0) {
        if (s_window) {
            a->SDL_DestroyWindow(s_window);
            s_window = 0;
        }
        a->SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

void* hulk_platform_create_window(const char* title, int width, int height, int hidden, int resizable)
{
    const HulkSdlApi* a = hulk_sdl_api();
    if (!a || !s_videoRefs)
        return 0;
    SDL_WindowFlags flags = 0;
    if (hidden)
        flags |= SDL_WINDOW_HIDDEN;
    if (resizable)
        flags |= SDL_WINDOW_RESIZABLE;
    SDL_Window* w = a->SDL_CreateWindow(title, width, height, flags);
    if (!w) {
        setError(a->SDL_GetError());
        return 0;
    }
    s_window = w;
    s_windowId = a->SDL_GetWindowID(w);
    a->SDL_GetWindowSizeInPixels(w, &s_lastW, &s_lastH);
    s_quit = false;
    return w;
}

int hulk_platform_native_handles(void* window, void** nwh, void** ndt, int* wayland)
{
    const HulkSdlApi* a = hulk_sdl_api();
    SDL_Window* w = (SDL_Window*)window;
    *nwh = *ndt = 0;
    *wayland = 0;
    if (!a || !w)
        return 0;
    SDL_PropertiesID p = a->SDL_GetWindowProperties(w);
#if defined(_WIN32)
    *nwh = a->SDL_GetPointerProperty(p, SDL_PROP_WINDOW_WIN32_HWND_POINTER, 0);
#elif defined(__APPLE__)
    *nwh = a->SDL_GetPointerProperty(p, SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, 0);       // bgfx makes the CAMetalLayer
#else
    const char* drv = a->SDL_GetCurrentVideoDriver();
    if (drv && !strcmp(drv, "wayland")) {
        *ndt = a->SDL_GetPointerProperty(p, SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER, 0);
        *nwh = a->SDL_GetPointerProperty(p, SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, 0);
        *wayland = 1;
    } else {
        *ndt = a->SDL_GetPointerProperty(p, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, 0);
        *nwh = (void*)(uintptr_t)a->SDL_GetNumberProperty(p, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
    }
#endif
    return *nwh != 0;
}

int hulk_platform_quit_requested(void) { return s_quit; }
int hulk_platform_has_focus(void) { return s_focus; }

int hulk_platform_is_fullscreen(void)
{
    const HulkSdlApi* a = hulk_sdl_api();
    return a && s_window && (a->SDL_GetWindowFlags(s_window) & SDL_WINDOW_FULLSCREEN) != 0;
}

int hulk_platform_toggle_fullscreen(void)
{
    const HulkSdlApi* a = hulk_sdl_api();
    if (!a || !s_window)
        return 0;
    // desktop-size borderless mode (no display mode change); the window manager completes it later
    if (!a->SDL_SetWindowFullscreen(s_window, !hulk_platform_is_fullscreen())) {
        setError(a->SDL_GetError());
        return 0;
    }
    return 1;
}

void hulk_platform_add_listener(hulk_platform_listener_fn fn, void* user)
{
    if (fn && s_listenerCount < 8) {
        s_listeners[s_listenerCount].fn = fn;
        s_listeners[s_listenerCount].user = user;
        s_listenerCount++;
    }
}

void hulk_platform_set_resize_handler(hulk_platform_resize_fn fn, void* user)
{
    s_resizeFn = fn;
    s_resizeUser = user;
}

void hulk_platform_pump(void)
{
    const HulkSdlApi* a = hulk_sdl_api();
    if (!a || !s_videoRefs)
        return;
    SDL_Event e;
    while (a->SDL_PollEvent(&e)) {
        for (int i = 0; i < s_listenerCount; i++)
            s_listeners[i].fn(&e, s_listeners[i].user);
        switch (e.type) {
        case SDL_EVENT_QUIT:
            s_quit = true;
            break;
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            if (e.window.windowID == s_windowId)
                s_quit = true;
            break;
        case SDL_EVENT_WINDOW_FOCUS_GAINED:
            if (e.window.windowID == s_windowId)
                s_focus = true;
            break;
        case SDL_EVENT_WINDOW_FOCUS_LOST:
            if (e.window.windowID == s_windowId)
                s_focus = false;
            break;
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
            if (e.window.windowID == s_windowId && e.window.data1 > 0 && e.window.data2 > 0 &&
                (e.window.data1 != s_lastW || e.window.data2 != s_lastH)) {
                s_lastW = e.window.data1;
                s_lastH = e.window.data2;
                if (s_resizeFn)
                    s_resizeFn(s_lastW, s_lastH, s_resizeUser);
            }
            break;
        case SDL_EVENT_KEY_DOWN:
            if (!e.key.repeat && (e.key.key == SDLK_F11 || (e.key.key == SDLK_RETURN && (e.key.mod & SDL_KMOD_ALT))))
                hulk_platform_toggle_fullscreen();
            break;
        default:
            break;
        }
    }
}
