// The C-runtime half of src/platform/sdl/crt/host_crt.h on POSIX (macOS, Linux, Android) for the native builds
// (docs/native-android.md section 14): the `hulk_host_<name>` functions the XDK shim (src/platform/sdl/xdk/) calls for
// memory, the environment, formatting and stdio, which the Wine build imports from msvcrt.dll, and
// hulk_crt_host_path (the Wine build's crt_glue.cpp) on the CRT glue's path mapping. win32_posix.cpp has the kernel32
// half. Host side (system headers, the host's ABI), C linkage. Not part of the Wine build.
//
// Left out on purpose: the start-up and crash-report functions only src/platform/sdl/xdk/startup.cpp calls
// (SetUnhandledExceptionFilter, VirtualQuery, CreateProcessA, ...: entry_posix.cpp replaces that file), and
// hulk_host__vsnprintf / hulk_host_vfprintf, which take an x86 `char*` argument list no host-compiled shim has.
#if !defined(_WIN32)
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__APPLE__)
#include <malloc/malloc.h>
#else
#include <malloc.h>
#endif

#include "../crt/host_crt.h"

extern "C" {
char* hulk_ncrt_host_path(const char* p, char* buf, size_t size);   // crt_posix.cpp

void* hulk_host_malloc(hulk_u32 size) { return malloc(size); }
void* hulk_host_calloc(hulk_u32 n, hulk_u32 size) { return calloc(n, size); }
void* hulk_host_realloc(void* p, hulk_u32 size) { return realloc(p, size); }
void hulk_host_free(void* p) { free(p); }
hulk_u32 hulk_host__msize(void* p) {
#if defined(__APPLE__)
    return p ? (hulk_u32)malloc_size(p) : 0;
#else
    return p ? (hulk_u32)malloc_usable_size(p) : 0;
#endif
}
void* hulk_host_memset(void* p, int c, hulk_u32 n) { return memset(p, c, n); }
void* hulk_host_memcpy(void* d, const void* s, hulk_u32 n) { return memcpy(d, s, n); }
hulk_u32 hulk_host_strlen(const char* s) { return (hulk_u32)strlen(s); }
int hulk_host_strcmp(const char* a, const char* b) { return strcmp(a, b); }
char* hulk_host_getenv(const char* name) { return getenv(name); }

// msvcrt's _snprintf: at most n characters, a NUL only if there is room, -1 when the output did not fit
int hulk_host__snprintf(char* buf, hulk_u32 n, const char* fmt, ...) {
    va_list ap, ap2;
    va_start(ap, fmt);
    va_copy(ap2, ap);
    int need = vsnprintf(0, 0, fmt, ap2);
    va_end(ap2);
    int r;
    if (need < 0) {
        r = -1;
    } else if ((hulk_u32)need < n) {
        r = vsnprintf(buf, n, fmt, ap);
    } else {
        if (n) {
            char* tmp = (char*)malloc((size_t)need + 1);
            if (tmp) {
                vsnprintf(tmp, (size_t)need + 1, fmt, ap);
                memcpy(buf, tmp, n);
                free(tmp);
            }
        }
        r = (hulk_u32)need == n ? need : -1;
    }
    va_end(ap);
    return r;
}

// stdio on the host's FILE (hulk_host_file is opaque to the shims); paths are host paths here
hulk_host_file* hulk_host_fopen(const char* path, const char* mode) { return (hulk_host_file*)fopen(path, mode); }
int hulk_host_fclose(hulk_host_file* f) { return fclose((FILE*)f); }
hulk_u32 hulk_host_fread(void* p, hulk_u32 size, hulk_u32 n, hulk_host_file* f) {
    return (hulk_u32)fread(p, size, n, (FILE*)f);
}
hulk_u32 hulk_host_fwrite(const void* p, hulk_u32 size, hulk_u32 n, hulk_host_file* f) {
    return (hulk_u32)fwrite(p, size, n, (FILE*)f);
}
int hulk_host_fseek(hulk_host_file* f, long off, int whence) { return fseek((FILE*)f, off, whence); }
long hulk_host_ftell(hulk_host_file* f) { return ftell((FILE*)f); }
int hulk_host_fflush(hulk_host_file* f) { return fflush((FILE*)f); }
int hulk_host_fputs(const char* s, hulk_host_file* f) { return fputs(s, (FILE*)f); }
char* hulk_host_fgets(char* s, int n, hulk_host_file* f) { return fgets(s, n, (FILE*)f); }
int hulk_host_getc(hulk_host_file* f) { return getc((FILE*)f); }
int hulk_host_ungetc(int c, hulk_host_file* f) { return ungetc(c, (FILE*)f); }
void hulk_host_exit(int code) { exit(code); }

// The game's path (`D:\data\x.rcf`, `T:\...`, `\x`) -> a host path under HULK_DATA_DIR / HULK_TDATA_DIR /
// HULK_SAVE_DIR, as the Wine build's crt_glue.cpp: the CRT glue's mapping (crt_posix.cpp), so the shim's files and
// the game's fopen agree
char* hulk_crt_host_path(const char* game_path, char* buf, hulk_u32 size) {
    return hulk_ncrt_host_path(game_path, buf, size);
}
}
#endif
