// The SDL3 entry points the window and event code (platform_events.cpp, pddi/sdl_platform.cpp, the smoke test) uses,
// as a table. Host builds link SDL directly and fill the table with the real functions. The native Windows image
// resolves them from SDL3.dll at run time (LoadLibrary + GetProcAddress): the image's link renames every host import of
// the graphics objects to hulk_gfx_<name> and binds it to msvcrt/kernel32/user32/gdi32 (tools/native_link.py
// graphics_backend), so a direct `_SDL_CreateWindow` reference would be renamed to a name no DLL exports. SDL3.dll is
// one module in the process, so the table and the audio/input backends' direct imports (tools/native_sdl.py) share one
// SDL: one event queue, one video subsystem.
#ifndef HULK_SDL_API_H
#define HULK_SDL_API_H

#include <SDL3/SDL.h>

#define HULK_SDL_FUNCS(X) \
    X(SDL_InitSubSystem) X(SDL_QuitSubSystem) X(SDL_GetError) X(SDL_CreateWindow) X(SDL_DestroyWindow) \
    X(SDL_GetWindowProperties) X(SDL_GetPointerProperty) X(SDL_GetNumberProperty) X(SDL_PollEvent) \
    X(SDL_SetWindowFullscreen) X(SDL_GetWindowFlags) X(SDL_GetWindowSizeInPixels) X(SDL_GetWindowID) \
    X(SDL_GetCurrentVideoDriver) X(SDL_ShowWindow)

struct HulkSdlApi {
#define X(n) decltype(&::n) n;
    HULK_SDL_FUNCS(X)
#undef X
};

// The table, or null if SDL3 can't be loaded (platform_events.cpp)
const HulkSdlApi* hulk_sdl_api(void);

#endif
