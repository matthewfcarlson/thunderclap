// Common definitions of the XDK import shim (src/platform/sdl/xdk/, docs/native-build.md "Platform shim").
//
// The first native image keeps the tree's own Xbox layer (src/platform/xbox: pddi on D3D8, the radcore Xbox
// drive and controller code, the radsound HAL, the Bink player) and links this directory in place of
// Microsoft's XDK libraries, XAPI and Bink, which are never shipped. Each import is a stand-in that counts its
// calls; real implementations on SDL3 replace them one at a time. Later, src/platform/sdl implements the seams
// directly (include/seams/) and the Xbox layer and this shim drop out of the native build.
//
// Freestanding on purpose: no system or CRT headers (the native link has no host libraries yet).
#ifndef HULK_PLATFORM_SDL_XDK_SHIM_H
#define HULK_PLATFORM_SDL_XDK_SHIM_H

typedef unsigned int hulk_u32;
typedef unsigned long long hulk_u64;

#if defined(_M_IX86) || defined(__i386__)
#define HULK_STDCALL __stdcall
#define HULK_FASTCALL __fastcall
#define HULK_CDECL __cdecl
#else
#define HULK_STDCALL
#define HULK_FASTCALL
#define HULK_CDECL
#endif

extern "C" {
// Called on an import's 1st, 2nd, 4th, 8th, ... call when set (a backend points it at SDL_Log); null: count only.
typedef void (*hulk_xdk_log_fn)(const char* name, hulk_u32 calls);
extern hulk_xdk_log_fn hulk_xdk_log_sink;
void hulk_xdk_trace(const char* name, hulk_u32* calls);
// Every import called so far, in first-call order (for a start-up trace from a debugger or the backend).
hulk_u32 hulk_xdk_called(const char** names, hulk_u32* calls, hulk_u32 max);
}

#define HULK_XDK_TRACE(name)              \
    do {                                  \
        static hulk_u32 hulk_xdk_calls_;  \
        hulk_xdk_trace(name, &hulk_xdk_calls_); \
    } while (0)

#endif
