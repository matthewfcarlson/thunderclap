// Test of src/platform/sdl/host/crt_posix.cpp (the native builds' C runtime glue):
//   xcrun clang++ -std=c++17 -O1 tests/native_host/crt_test.cpp src/platform/sdl/host/crt_posix.cpp \
//       src/platform/sdl/crt/softx87.cpp -o build/x64-3/crt_test && build/x64-3/crt_test
// (without softx87: -DHULK_NO_SOFT_X87, the host libm)
#include <math.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
void hulk_native_missing(const char* name) { printf("missing %s\n", name); exit(3); }
int hulk_ncrt_rand(void);
void hulk_ncrt_srand(unsigned);
int hulk_ncrt_snprintf_ms(char*, size_t, const char*, ...);
char* hulk_ncrt_strtok(char*, const char*);
size_t hulk_ncrt_wcslen16(const unsigned short*);
int hulk_ncrt_strtol(const char*, char**, int);
unsigned hulk_ncrt_strtoul(const char*, char**, int);
int hulk_ncrt_labs(int);
char* hulk_ncrt_strlwr(char*);
long long hulk_ncrt_ftol(double);
int hulk_ncrt_setjmp3(void* buf, int count, ...);
void hulk_ncrt_longjmp(void* buf, int value);
extern unsigned char hulk_ncrt_iob_proxy[96];
int hulk_ncrt_fprintf(void* f, const char* fmt, ...);
char* hulk_ncrt_host_path(const char* p, char* buf, size_t size);
void* hulk_ncrt_malloc(size_t);
int hulk_ncrt_atexit(void (*)(void));
void hulk_crt_run_atexit(void);
double hulk_ncrt_sin(double), hulk_ncrt_atan2(double, double), hulk_ncrt_pow(double, double), hulk_ncrt_fmod(double, double);
float hulk_ncrt_sinf(float);
int hulk_ncrt_soft_x87(void);
}

static int g_fail;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); g_fail++; } } while (0)

struct LuaJmp { void* prev; unsigned char env[64]; };   // (the game's record: a 64-byte jmp_buf)
__attribute__((noinline)) static void thrower(LuaJmp* j, int v) {
    volatile char pad[512];
    pad[0] = (char)v;
    if (pad[0] >= 0)
        hulk_ncrt_longjmp(j->env, v);
}
__attribute__((noinline)) static int protected_call(int depth, int throw_at) {
    LuaJmp j;
    volatile int local = depth * 3;
    double keep = depth * 0.5;
    int r = hulk_ncrt_setjmp3(j.env, 0);
    if (r) {
        CHECK(local == depth * 3 && keep == depth * 0.5);
        return r;
    }
    if (depth == throw_at)
        thrower(&j, depth == 2 ? 0 : 100 + depth);
    int inner = depth < 5 ? protected_call(depth + 1, throw_at) : 0;
    return inner;
}

static void* rand_thread(void*) {
    hulk_ncrt_rand();   // (another thread's sequence starts at seed 1 too)
    return (void*)(intptr_t)hulk_ncrt_rand();
}

static int g_exit_order[3], g_exit_n;
static void ex1() { g_exit_order[g_exit_n++] = 1; }
static void ex2() { g_exit_order[g_exit_n++] = 2; }

int main() {
    // rand: seed 1's sequence, srand, per thread
    int first[5];
    for (int i = 0; i < 5; i++) first[i] = hulk_ncrt_rand();
    CHECK(first[0] == 41 && first[1] == 18467 && first[2] == 6334 && first[3] == 26500 && first[4] == 19169);
    pthread_t th;
    void* r2;
    pthread_create(&th, 0, rand_thread, 0);
    pthread_join(th, &r2);
    CHECK((intptr_t)r2 == 18467);
    hulk_ncrt_srand(1);
    CHECK(hulk_ncrt_rand() == 41);
    // _snprintf
    char b[8];
    memset(b, 'x', 8);
    CHECK(hulk_ncrt_snprintf_ms(b, 8, "%d", 1234) == 4 && !strcmp(b, "1234"));
    memset(b, 'x', 8);
    CHECK(hulk_ncrt_snprintf_ms(b, 4, "%s", "abcd") == 4 && !memcmp(b, "abcdx", 5));    // exactly full: no NUL
    memset(b, 'x', 8);
    CHECK(hulk_ncrt_snprintf_ms(b, 4, "%s", "abc") == 3 && !strcmp(b, "abc"));
    memset(b, 'x', 8);
    CHECK(hulk_ncrt_snprintf_ms(b, 4, "%s", "abcdef") == -1 && !memcmp(b, "abcdx", 5));
    // strings, numbers
    char s[] = "a,b,,c";
    CHECK(!strcmp(hulk_ncrt_strtok(s, ","), "a") && !strcmp(hulk_ncrt_strtok(0, ","), "b") &&
          !strcmp(hulk_ncrt_strtok(0, ","), "c") && !hulk_ncrt_strtok(0, ","));
    const unsigned short w[] = {'h', 'u', 'l', 'k', 0};
    CHECK(hulk_ncrt_wcslen16(w) == 4);
    CHECK(hulk_ncrt_strtol("99999999999", 0, 10) == 2147483647 && hulk_ncrt_strtol("-99999999999", 0, 10) == (int)0x80000000);
    CHECK(hulk_ncrt_strtol("0x7f", 0, 16) == 127 && hulk_ncrt_strtoul("4294967295", 0, 10) == 4294967295u);
    CHECK(hulk_ncrt_strtoul("99999999999", 0, 10) == 4294967295u);
    CHECK(hulk_ncrt_labs(-5) == 5);
    char up[] = "RcF\\Data.RCF";
    CHECK(!strcmp(hulk_ncrt_strlwr(up), "rcf\\data.rcf"));
    CHECK(hulk_ncrt_ftol(-2.9) == -2 && hulk_ncrt_ftol(3e10) == 30000000000ll);
    // setjmp / longjmp through nested frames, value 0 -> 1
    for (int at = 0; at <= 5; at++) {
        int r = protected_call(0, at);
        CHECK(r == (at == 2 ? 1 : 100 + at));
    }
    for (int i = 0; i < 20000; i++)   // many buffers at one address (the table reuses the entry)
        CHECK(protected_call(4, 5) == 105);
    // stdio proxy, paths
    CHECK(hulk_ncrt_fprintf(hulk_ncrt_iob_proxy + 32, "crt_test: stdout through the proxy\n") > 0);
    setenv("HULK_DATA_DIR", "/data", 1);
    setenv("HULK_SAVE_DIR", "/saves", 1);
    char pb[256];
    CHECK(hulk_ncrt_host_path("D:\\sound\\x.rsd", pb, sizeof pb) && !strcmp(pb, "/data/sound/x.rsd"));
    CHECK(hulk_ncrt_host_path("u:\\gamesave", pb, sizeof pb) && !strcmp(pb, "/saves/gamesave"));
    CHECK(!hulk_ncrt_host_path("c:\\x", pb, sizeof pb));
    unsigned char* m = (unsigned char*)hulk_ncrt_malloc(64);
    int zero = 1;
    for (int i = 0; i < 64; i++) zero &= m[i] == 0;
    CHECK(zero);
    hulk_ncrt_atexit(ex1);
    hulk_ncrt_atexit(ex2);
    hulk_crt_run_atexit();
    CHECK(g_exit_n == 2 && g_exit_order[0] == 2 && g_exit_order[1] == 1);
    // math
    CHECK(fabs(hulk_ncrt_sin(1.0) - sin(1.0)) < 1e-15 && fabs(hulk_ncrt_atan2(1.0, -1.0) - atan2(1.0, -1.0)) < 1e-15);
    CHECK(hulk_ncrt_pow(2.0, 10.0) == 1024.0 && hulk_ncrt_fmod(7.5, 2.0) == 1.5 && fabsf(hulk_ncrt_sinf(0.5f) - sinf(0.5f)) < 1e-7f);
    printf("math: %s\n", hulk_ncrt_soft_x87() ? "soft-intrinsics (softx87)" : "host libm");
    printf("%s (%d failed)\n", g_fail ? "FAILED" : "ok", g_fail);
    return g_fail != 0;
}
