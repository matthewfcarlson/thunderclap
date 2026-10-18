// Common definitions of the XDK import shim (src/platform/sdl/xdk/, docs/native-build.md "Platform shim").
//
// The first native image keeps the tree's own Xbox layer (src/platform/xbox: pddi on D3D8, the radcore Xbox
// drive and controller code, the radsound HAL, the Bink player) and links this directory in place of
// Microsoft's XDK libraries, XAPI and Bink, which are never shipped. Each import is a stand-in that counts its
// calls; real implementations on SDL3 replace them one at a time. Later, src/platform/sdl implements the seams
// directly (include/seams/) and the Xbox layer and this shim drop out of the native build.
//
// Freestanding on purpose: no system or CRT headers. What the stand-ins need from the host (memory, files, time)
// comes through src/platform/sdl/crt/host_crt.h, the native build's own declarations of the host C runtime.
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
// Called once per import, on its first call, with the caller's return address (the start-up trace: startup.cpp).
typedef void (*hulk_xdk_first_fn)(const char* name, const void* caller);
extern hulk_xdk_first_fn hulk_xdk_first_call_sink;
void hulk_xdk_trace(const char* name, hulk_u32* calls);
void hulk_xdk_trace_from(const char* name, hulk_u32* calls, const void* caller);
// Every import called so far, in first-call order (for a start-up trace from a debugger or the backend).
hulk_u32 hulk_xdk_called(const char** names, hulk_u32* calls, hulk_u32 max);
}

#if defined(__clang__) || defined(__GNUC__)
#define HULK_XDK_CALLER() __builtin_return_address(0)
#else
#define HULK_XDK_CALLER() ((const void*)0)
#endif

// (in a stand-in's body: the caller is the game code that called the import)
#define HULK_XDK_TRACE(name)              \
    do {                                  \
        static hulk_u32 hulk_xdk_calls_;  \
        hulk_xdk_trace_from(name, &hulk_xdk_calls_, HULK_XDK_CALLER()); \
    } while (0)

#endif
