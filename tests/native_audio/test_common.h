// Shared by tests/native_audio and tests/native_input (built by tools/native_sdl.py test / wine-test).
// No C runtime headers: the i686 build links only msvcrt.dll imports and SDL3.dll.
#ifndef HULK_TEST_COMMON_H
#define HULK_TEST_COMMON_H

#include <SDL3/SDL.h>

extern "C" int printf(const char*, ...);

static int g_fail, g_pass;

#define CHECK(cond, ...)                                       \
    do {                                                       \
        if (cond) {                                            \
            g_pass++;                                          \
        } else {                                               \
            g_fail++;                                          \
            printf("FAIL %s:%d: ", __FILE__, __LINE__);        \
            printf(__VA_ARGS__);                               \
            printf("\n");                                      \
        }                                                      \
    } while (0)

static inline bool near(double a, double b, double tol)
{
    double d = a - b;
    return d <= tol && d >= -tol;
}

static inline int test_done(const char* name)
{
    printf("%s: %d checks passed, %d failed\n", name, g_pass, g_fail);
    return g_fail ? 1 : 0;
}

#ifdef HULK_TEST_XDK
typedef unsigned int hulk_u32;
#define TEST_PTR(p) ((hulk_u32)(__SIZE_TYPE__)(p))
#endif

int test_main(void);
#ifndef HULK_TEST_XDK
int main()
{
    return test_main();
}
#endif

#endif
