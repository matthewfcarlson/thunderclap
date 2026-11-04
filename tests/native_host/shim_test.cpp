// The XDK shim on the native builds (tests/native_host/shim_test.py; docs/native-android.md section 14): the stand-ins
// of src/platform/sdl/xdk/ compiled as host code with the native host layer (host_crt_posix.cpp, win32_posix.cpp,
// crt_posix.cpp, shim_posix.cpp) in place of the Wine build's msvcrt / kernel32 imports. Host side; the calls below
// are the game's (the stand-ins' own signatures, pointers and handles at pointer width).
//   argv[1]: a scratch directory (HULK_DATA_DIR and HULK_SAVE_DIR are set under it here)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "xdk/imports.h"

extern "C" {
void hulk_native_log(const char* line) { printf("trace: gfx %s\n", line); }
void hulk_native_missing(const char* name) {
    printf("missing %s\n", name);
    exit(3);
}
// core::GetMicroseconds64 0x00267f40, which the shim's virtual clock falls back to (the image: the link's thunk to the
// game's definition by address, tools/native_bind.py)
unsigned long long FUN_00267f40(void) { return 42; }
unsigned long long hulk_clock_tick(void);   // xdk/timing.cpp
}

static int g_bad;
#define CHECK(c)                                                         \
    do {                                                                 \
        if (!(c)) {                                                      \
            printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c);           \
            g_bad++;                                                     \
        }                                                                \
    } while (0)

int main(int argc, char** argv) {
    if (argc < 2)
        return 2;
    char data[512], save[512], path[600];
    snprintf(data, sizeof(data), "%s/disc", argv[1]);
    snprintf(save, sizeof(save), "%s/save", argv[1]);
    mkdir(argv[1], 0755);
    mkdir(data, 0755);
    snprintf(path, sizeof(path), "%s/data", data);
    mkdir(path, 0755);
    snprintf(path, sizeof(path), "%s/data/hello.txt", data);
    FILE* f = fopen(path, "wb");
    fputs("hello, hulk", f);
    fclose(f);
    setenv("HULK_DATA_DIR", data, 1);
    setenv("HULK_SAVE_DIR", save, 1);

    // timing: the Xbox's counter frequency, a counter that moves
    unsigned long long hz = 0, c0 = 0, c1 = 0;
    CHECK(hulk_xdk_QueryPerformanceFrequency((hulk_uptr)&hz) == 1 && hz == 733333333ull);
    CHECK(hulk_xdk_QueryPerformanceCounter((hulk_uptr)&c0) == 1);
    for (volatile int i = 0; i < 1000000; i++) {
    }
    CHECK(hulk_xdk_QueryPerformanceCounter((hulk_uptr)&c1) == 1 && c1 > c0);
    CHECK(hulk_clock_tick() == 42);   // no virtual clock: the game's GetMicroseconds64

    // files on D:\ through HULK_DATA_DIR (the stand-ins' handles are pointer-sized)
    hulk_uptr h = hulk_xdk_CreateFileA((hulk_uptr) "D:\\data\\hello.txt", 0x80000000u, 1, 0, 3, 0x80, 0);
    CHECK(h != HULK_INVALID_UPTR);
    if (h != HULK_INVALID_UPTR) {
        CHECK(hulk_xdk_GetFileSize(h, 0) == 11);
        char buf[32] = {0};
        hulk_u32 got = 0;
        CHECK(hulk_xdk_ReadFile(h, (hulk_uptr)buf, sizeof(buf), (hulk_uptr)&got, 0) == 1 && got == 11);
        CHECK(memcmp(buf, "hello, hulk", 11) == 0);
        CHECK(hulk_xdk_SetFilePointer(h, 7, 0, 0) == 7);
        CHECK(hulk_xdk_ReadFile(h, (hulk_uptr)buf, 4, (hulk_uptr)&got, 0) == 1 && got == 4 && memcmp(buf, "hulk", 4) == 0);
        CHECK(hulk_xdk_CloseHandle(h) == 1);
    }
    CHECK(hulk_xdk_CreateFileA((hulk_uptr) "D:\\data\\missing.txt", 0x80000000u, 1, 0, 3, 0x80, 0) == HULK_INVALID_UPTR);
    // a save on T:\ (HULK_SAVE_DIR). The stand-in file_io.cpp (no HULK_NATIVE_SDL) makes a save's directories by
    // splitting the host path at '\\', which a POSIX host path does not have, so the directory is made here first; the
    // native builds' file layer is the SDL3 backend (HULK_NATIVE_SDL: src/platform/sdl/fs/hulk_fs.cpp), which has its
    // own (docs/native-android.md section 14)
    mkdir(save, 0755);
    snprintf(path, sizeof(path), "%s/profiles", save);
    mkdir(path, 0755);
    h = hulk_xdk_CreateFileA((hulk_uptr) "T:\\profiles\\slot0.sav", 0xc0000000u, 0, 0, 2, 0x80, 0);
    CHECK(h != HULK_INVALID_UPTR);
    if (h != HULK_INVALID_UPTR) {
        hulk_u32 put = 0;
        CHECK(hulk_xdk_WriteFile(h, (hulk_uptr) "SAVE", 4, (hulk_uptr)&put, 0) == 1 && put == 4);
        CHECK(hulk_xdk_CloseHandle(h) == 1);
        snprintf(path, sizeof(path), "%s/profiles/slot0.sav", save);
        struct stat st;
        CHECK(stat(path, &st) == 0 && st.st_size == 4);
    }

    // the start-up trace's import list
    const char* names[64];
    hulk_u32 calls[64];
    hulk_u32 n = hulk_xdk_called(names, calls, 64);
    int saw = 0;
    for (hulk_u32 i = 0; i < n; i++)
        saw += !strcmp(names[i], "CreateFileA") || !strcmp(names[i], "ReadFile") || !strcmp(names[i], "QueryPerformanceCounter");
    CHECK(saw == 3);
    printf("shim_test: %u imports called, %d failures\n", n, g_bad);
    return g_bad ? 1 : 0;
}
