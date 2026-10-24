// Test of src/platform/sdl/host/win32_posix.cpp (the POSIX Win32 host functions of the native builds):
//   xcrun clang++ -std=c++17 -O1 -Isrc/platform/sdl tests/native_host/host_test.cpp src/platform/sdl/host/win32_posix.cpp \
//       -o build/x64-3/host_test && build/x64-3/host_test /tmp/dir
// Threads (suspended start, exit codes, waits), semaphores (counts, limits, timeouts), events, critical sections,
// fibers (ping-pong, deep recursion on a fiber stack, a fiber that switches back from a nested call, fibers on a
// second thread), files (dispositions, read/write, seek, size, truncate, overlapped offsets, attributes, dirs).
#include "host/win32_posix.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>

static int g_fail;
#define CHECK(c)                                                          \
    do {                                                                  \
        if (!(c)) {                                                       \
            printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #c);           \
            g_fail++;                                                     \
        }                                                                 \
    } while (0)

static hulk_u32 add_thread(void* p) {
    int* v = (int*)p;
    for (int i = 0; i < 1000; i++)
        (*v)++;
    return 42;
}

static void* g_sem;
static int g_shared;
static unsigned char g_cs[64];
static hulk_u32 cs_thread(void*) {
    for (int i = 0; i < 100000; i++) {
        hulk_host_EnterCriticalSection(g_cs);
        hulk_host_EnterCriticalSection(g_cs);   // recursive
        g_shared++;
        hulk_host_LeaveCriticalSection(g_cs);
        hulk_host_LeaveCriticalSection(g_cs);
    }
    hulk_host_ReleaseSemaphore(g_sem, 1, 0);
    return 0;
}

static void* g_main_fiber;
static void* g_fiber_a;
static int g_trace[64], g_ntrace;
static int deep(int n) {
    volatile char buf[256];
    buf[0] = (char)n;
    return n ? deep(n - 1) + buf[0] - (char)n + 1 : 0;
}
static void nested_switch(int k) {
    g_trace[g_ntrace++] = 100 + k;
    hulk_host_SwitchToFiber(g_main_fiber);
}
static void fiber_a(void* param) {
    CHECK(param == (void*)0x1234);
    CHECK(hulk_host_GetFiberData() == (void*)0x1234);
    for (int k = 0; k < 3; k++) {
        double d = 1.5 * k;   // callee-saved FP registers must survive the switches
        nested_switch(k);
        CHECK(d == 1.5 * k);
    }
    g_trace[g_ntrace++] = deep(500);   // ~150 KB of stack frames
    hulk_host_SwitchToFiber(g_main_fiber);
    CHECK(!"fiber resumed after its last switch");
}

static hulk_u32 fiber_thread(void*) {
    void* me = hulk_host_ConvertThreadToFiber(0);
    void* f = hulk_host_CreateFiber(0, (void*)+[](void* m) {
        for (int i = 0; i < 1000; i++)
            hulk_host_SwitchToFiber(m);
    }, me);
    int n = 0;
    for (int i = 0; i < 1000; i++) {
        hulk_host_SwitchToFiber(f);
        n++;
    }
    hulk_host_DeleteFiber(f);
    return (hulk_u32)n;
}

int main(int argc, char** argv) {
    std::string dir = argc > 1 ? argv[1] : "/tmp";
    // threads
    int v = 0;
    hulk_u32 tid = 0;
    void* t = hulk_host_CreateThread(0, 0, (void*)add_thread, &v, HULK_CREATE_SUSPENDED, &tid);
    CHECK(t && tid && tid != hulk_host_GetCurrentThreadId());
    CHECK(hulk_host_WaitForSingleObject(t, 50) == HULK_WAIT_TIMEOUT);
    CHECK(v == 0);
    CHECK(hulk_host_ResumeThread(t) == 1);
    CHECK(hulk_host_WaitForSingleObject(t, HULK_INFINITE) == HULK_WAIT_OBJECT_0);
    CHECK(v == 1000);
    CHECK(hulk_host_WaitForSingleObject(t, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_CloseHandle(t));
    // semaphores
    void* s = hulk_host_CreateSemaphoreA(0, 1, 2, 0);
    int prev = -1;
    CHECK(hulk_host_WaitForSingleObject(s, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_WaitForSingleObject(s, 10) == HULK_WAIT_TIMEOUT);
    CHECK(hulk_host_ReleaseSemaphore(s, 2, &prev) && prev == 0);
    CHECK(!hulk_host_ReleaseSemaphore(s, 1, 0) && hulk_host_GetLastError() == HULK_ERROR_TOO_MANY_POSTS);
    CHECK(hulk_host_WaitForSingleObject(s, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_WaitForSingleObject(s, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_WaitForSingleObject(s, 0) == HULK_WAIT_TIMEOUT);
    CHECK(hulk_host_CloseHandle(s));
    CHECK(hulk_host_WaitForSingleObject((void*)&v, 0) == HULK_WAIT_FAILED);
    // events
    void* ea = hulk_host_CreateEventA(0, 0, 1, 0);
    void* em = hulk_host_CreateEventA(0, 1, 0, 0);
    CHECK(hulk_host_WaitForSingleObject(ea, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_WaitForSingleObject(ea, 0) == HULK_WAIT_TIMEOUT);   // auto-reset
    CHECK(hulk_host_SetEvent(em));
    CHECK(hulk_host_WaitForSingleObject(em, 0) == HULK_WAIT_OBJECT_0);
    CHECK(hulk_host_WaitForSingleObject(em, 0) == HULK_WAIT_OBJECT_0);  // manual: stays signaled
    CHECK(hulk_host_ResetEvent(em));
    CHECK(hulk_host_WaitForSingleObject(em, 5) == HULK_WAIT_TIMEOUT);
    hulk_host_CloseHandle(ea);
    hulk_host_CloseHandle(em);
    // critical sections, from 4 threads
    hulk_host_InitializeCriticalSection(g_cs);
    g_sem = hulk_host_CreateSemaphoreA(0, 0, 4, 0);
    for (int i = 0; i < 4; i++)
        hulk_host_CloseHandle(hulk_host_CreateThread(0, 0, (void*)cs_thread, 0, 0, 0));
    for (int i = 0; i < 4; i++)
        CHECK(hulk_host_WaitForSingleObject(g_sem, 10000) == HULK_WAIT_OBJECT_0);
    CHECK(g_shared == 400000);
    hulk_host_DeleteCriticalSection(g_cs);
    // fibers
    g_main_fiber = hulk_host_ConvertThreadToFiber((void*)0x99);
    CHECK(g_main_fiber && hulk_host_GetCurrentFiber() == g_main_fiber && hulk_host_GetFiberData() == (void*)0x99);
    g_fiber_a = hulk_host_CreateFiber(0x40000, (void*)fiber_a, (void*)0x1234);
    for (int k = 0; k < 4; k++) {
        double keep = 2.25 * k;
        hulk_host_SwitchToFiber(g_fiber_a);
        CHECK(keep == 2.25 * k);
        CHECK(hulk_host_GetCurrentFiber() == g_main_fiber);
    }
    CHECK(g_ntrace == 4 && g_trace[0] == 100 && g_trace[1] == 101 && g_trace[2] == 102 && g_trace[3] == 500);
    hulk_host_DeleteFiber(g_fiber_a);
    void* ft = hulk_host_CreateThread(0, 0, (void*)fiber_thread, 0, 0, 0);
    CHECK(hulk_host_WaitForSingleObject(ft, 10000) == HULK_WAIT_OBJECT_0);
    hulk_host_CloseHandle(ft);
    // files
    std::string p = dir + "/hulk_host_test.bin", sub = dir + "/hulk_host_test_dir";
    unlink(p.c_str());
    rmdir(sub.c_str());
    CHECK(hulk_host_CreateFileA(p.c_str(), HULK_GENERIC_READ, 1, 0, HULK_OPEN_EXISTING, 0x80, 0) == HULK_INVALID_HANDLE_VALUE);
    CHECK(hulk_host_GetLastError() == HULK_ERROR_FILE_NOT_FOUND);
    void* f = hulk_host_CreateFileA(p.c_str(), HULK_GENERIC_READ | HULK_GENERIC_WRITE, 0, 0, HULK_CREATE_NEW, 0x80, 0);
    CHECK(f != HULK_INVALID_HANDLE_VALUE);
    CHECK(hulk_host_CreateFileA(p.c_str(), HULK_GENERIC_WRITE, 0, 0, HULK_CREATE_NEW, 0x80, 0) == HULK_INVALID_HANDLE_VALUE &&
          hulk_host_GetLastError() == HULK_ERROR_FILE_EXISTS);
    hulk_u32 n = 0;
    CHECK(hulk_host_WriteFile(f, "hello world", 11, &n, 0) && n == 11);
    CHECK(hulk_host_SetFilePointer(f, 6, 0, HULK_FILE_BEGIN) == 6);
    char buf[32] = {0};
    CHECK(hulk_host_ReadFile(f, buf, 32, &n, 0) && n == 5 && !memcmp(buf, "world", 5));
    CHECK(hulk_host_ReadFile(f, buf, 32, &n, 0) && n == 0);     // at the end: success, 0 bytes
    hulk_u32 hi = 7;
    CHECK(hulk_host_GetFileSize(f, &hi) == 11 && hi == 0);
    CHECK(hulk_host_SetFilePointer(f, 5, 0, HULK_FILE_BEGIN) == 5 && hulk_host_SetEndOfFile(f));
    CHECK(hulk_host_GetFileSize(f, 0) == 5);
    struct { uintptr_t internal, internal_high; hulk_u32 offset, offset_high; void* event; } ov = {0, 0, 1, 0, 0};
    memset(buf, 0, sizeof(buf));
    CHECK(hulk_host_ReadFile(f, buf, 3, &n, &ov) && n == 3 && !memcmp(buf, "ell", 3) && ov.internal_high == 3);
    int hi2 = -1;   // (with a high word the distance is 64-bit: -2 is lo 0xfffffffe, hi -1)
    CHECK(hulk_host_SetFilePointer(f, -2, &hi2, HULK_FILE_END) == 3 && hi2 == 0);
    CHECK(hulk_host_SetFilePointer(f, -10, 0, HULK_FILE_BEGIN) == HULK_INVALID_SET_FILE_POINTER);
    CHECK(hulk_host_CloseHandle(f));
    f = hulk_host_CreateFileA(p.c_str(), HULK_GENERIC_WRITE, 0, 0, HULK_CREATE_ALWAYS, 0x80, 0);
    CHECK(f != HULK_INVALID_HANDLE_VALUE && hulk_host_GetLastError() == HULK_ERROR_ALREADY_EXISTS);
    CHECK(hulk_host_GetFileSize(f, 0) == 0);
    hulk_host_CloseHandle(f);
    CHECK(hulk_host_GetFileAttributesA(p.c_str()) == HULK_FILE_ATTRIBUTE_NORMAL);
    CHECK(hulk_host_GetFileAttributesA((p + ".no").c_str()) == HULK_INVALID_FILE_ATTRIBUTES);
    CHECK(hulk_host_CreateDirectoryA(sub.c_str(), 0));
    CHECK(!hulk_host_CreateDirectoryA(sub.c_str(), 0) && hulk_host_GetLastError() == HULK_ERROR_ALREADY_EXISTS);
    CHECK(hulk_host_GetFileAttributesA(sub.c_str()) == HULK_FILE_ATTRIBUTE_DIRECTORY);
    unsigned long long a = 0, tot = 0, fr = 0;
    CHECK(hulk_host_GetDiskFreeSpaceExA(dir.c_str(), &a, &tot, &fr) && tot >= fr && fr >= a && tot > 0);
    unlink(p.c_str());
    rmdir(sub.c_str());
    // time
    unsigned long long q0, q1, fq;
    hulk_host_QueryPerformanceFrequency(&fq);
    hulk_host_QueryPerformanceCounter(&q0);
    hulk_host_Sleep(20);
    hulk_host_QueryPerformanceCounter(&q1);
    CHECK(fq == 1000000000ull && q1 - q0 >= 19000000ull);
    unsigned short st[8];
    hulk_host_GetLocalTime(st);
    CHECK(st[0] >= 2024 && st[1] >= 1 && st[1] <= 12 && st[3] >= 1 && st[3] <= 31);
    void* mem = hulk_host_VirtualAlloc(0, 1 << 20, 0x3000, 4);
    CHECK(mem != 0);
    if (mem)
        memset(mem, 1, 1 << 20);
    printf("%s (%d failed)\n", g_fail ? "FAILED" : "ok", g_fail);
    return g_fail != 0;
}
