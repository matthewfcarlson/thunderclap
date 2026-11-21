/* The few SDL3 calls src/platform/sdl/replay/hulk_replay.cpp makes, for the wasm host (replay.cpp includes that file):
 * the C library's, and SDL_LoadFile through the host's file imports (hulk_io.h). Not SDL. */
#ifndef HULK_WASM_SDL_SHIM_H
#define HULK_WASM_SDL_SHIM_H
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SDL_free free
#define SDL_realloc realloc
#define SDL_memset memset
#define SDL_memcpy memcpy
#define SDL_snprintf snprintf
#define SDL_strcmp strcmp
#define SDL_strtoul strtoul
#define SDL_atoi atoi
#define SDL_getenv getenv
static inline const char* SDL_GetError(void) { return "no such file"; }
static inline void SDL_Log(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputc('\n', stderr);
}
void* hulk_wasm_load_file(const char* path, size_t* size);   /* replay.cpp */
#define SDL_LoadFile hulk_wasm_load_file
#endif
