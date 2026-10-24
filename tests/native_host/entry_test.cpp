// Test of src/platform/sdl/host/entry_posix.cpp (the native builds' entry point) with a stand-in game:
//   xcrun clang++ -std=c++17 -g -O1 -fno-omit-frame-pointer -rdynamic tests/native_host/entry_test.cpp \
//       src/platform/sdl/host/entry_posix.cpp -o build/x64-3/entry_test
//   HULK_ENTRY_TEST=ok|missing|crash|hang HULK_TRACE_FILE=t.txt build/x64-3/entry_test   (exit 0 / 3 / 4 / 6)
// tests/native_host/entry_test.sh runs the four and checks the traces.
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned int hulk_u32;
extern "C" {
typedef void (*hulk_init_fn)(void);
typedef void (*hulk_xdk_first_fn)(const char* name, const void* caller);
hulk_xdk_first_fn hulk_xdk_first_call_sink;
void hulk_native_missing(const char* name);

static int g_order[4], g_n;
static void init_a() { g_order[g_n++] = 1; }
static void init_b() { g_order[g_n++] = 2; }
hulk_init_fn hulk_game_initializers[] = {init_a, 0, init_b};
extern const hulk_u32 hulk_game_initializer_addrs[];
const hulk_u32 hulk_game_initializer_addrs[] = {0x00011000, 0x00349000, 0x00012000};
extern const hulk_u32 hulk_game_initializer_count;
const hulk_u32 hulk_game_initializer_count = 3;

static hulk_u32 g_calls = 1;
hulk_u32 hulk_xdk_called(const char** names, hulk_u32* calls, hulk_u32 max) {
    if (max) {
        names[0] = "CreateFileA";
        calls[0] = g_calls;
    }
    return 1;
}
static int g_atexit_ran;
void hulk_crt_run_atexit(void) { g_atexit_ran = 1; }

__attribute__((noinline)) static void game_crash(volatile int* p) { *p = 1; }
__attribute__((noinline)) static void game_missing() { hulk_native_missing("?FUN_00123456@@YAXXZ"); }

int hulk_game_main(void) {
    if (g_n != 2 || g_order[0] != 1 || g_order[1] != 2)
        return 7;
    if (hulk_xdk_first_call_sink)
        hulk_xdk_first_call_sink("CreateFileA", (const void*)&hulk_game_main);
    const char* t = getenv("HULK_ENTRY_TEST");
    if (t && !strcmp(t, "missing"))
        game_missing();
    if (t && !strcmp(t, "crash"))
        game_crash((volatile int*)16);
    if (t && !strcmp(t, "hang"))
        for (;;)
            usleep(1000);
    return 0;
}
}
