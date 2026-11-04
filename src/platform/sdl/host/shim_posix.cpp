// What the XDK shim (src/platform/sdl/xdk/, compiled as host code on the native builds) needs from the native image
// besides the C runtime (host_crt_posix.cpp) and kernel32 (win32_posix.cpp): docs/native-android.md section 14.
// Host side, C linkage. Not part of the Wine build (whose xdk/replay_hooks.cpp and platform_events.cpp define these).
//
//   * the syncio interface threads.cpp calls around the drive threads (replay_hooks.cpp's lockstep I/O, HULK_SYNCIO):
//     the native builds have no lockstep I/O yet (src/platform/sdl/host/native_hooks.h: the drive hooks need the
//     drive's 64-bit layout), so the drive threads run free, as the Wine build without HULK_SYNCIO;
//   * the platform's event pump the shim's main-thread sleeps call: nothing to pump in a headless image (a graphics
//     build links platform_events.cpp, whose definition takes the place of this weak one).
#if !defined(_WIN32)
typedef unsigned int hulk_u32;
typedef __UINTPTR_TYPE__ hulk_uptr;

extern "C" {
void hulk_io_thread_created(hulk_uptr start, hulk_uptr param) {
    (void)start;
    (void)param;
}
int hulk_io_drive_wait(hulk_uptr handle, hulk_u32 ms, hulk_u32* result) {
    (void)handle;
    (void)ms;
    (void)result;
    return 0;   // not handled: threads.cpp waits on the host object itself
}
void hulk_io_main_sleep(void) {}
void hulk_io_cs_enter(void) {}
void hulk_io_cs_leave(void) {}
int hulk_io_main_wait(hulk_uptr handle, hulk_u32* result) {
    (void)handle;
    (void)result;
    return 0;
}
__attribute__((weak)) void hulk_platform_pump(void) {}
}
#endif
