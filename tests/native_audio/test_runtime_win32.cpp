// The i686 test executables' runtime (tools/native_sdl.py wine-test): an entry point and the few symbols the xdk
// stand-ins take from the native image (trace hooks, the image log, XPP's device-type words, SetLastError), so
// the stand-ins can be tested outside the game image. Linked with SDL3.lib and msvcrt/kernel32 import libraries.
extern "C" int printf(const char*, ...);
extern "C" __declspec(dllimport) void __stdcall ExitProcess(unsigned);
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned);

typedef unsigned int hulk_u32;
int test_main(void);

extern "C" {
int _fltused = 0;

// src/platform/sdl/xdk/trace.cpp's entry (native9's file): count only
void hulk_xdk_trace_from(const char* name, hulk_u32* calls, const void* caller)
{
    (void)name;
    (void)caller;
    ++*calls;
}
void hulk_xdk_trace(const char* name, hulk_u32* calls)
{
    hulk_xdk_trace_from(name, calls, 0);
}

// src/platform/sdl/xdk/startup.cpp's log
void __cdecl hulk_native_log(const char* line)
{
    printf("log: %s\n", line);
}

// src/platform/sdl/crt (host kernel32 under an image-private name)
void __stdcall hulk_host_SetLastError(hulk_u32 code)
{
    SetLastError(code);
}

// src/platform/sdl/xdk/library.cpp: XPP's device-type descriptors (the game passes their addresses)
hulk_u32 hulk_lib_xpp_gamepad_type[1] = {1};
hulk_u32 hulk_lib_xpp_mu_type[1] = {2};

int __cdecl hulk_test_entry(void)
{
    int rc = test_main();
    ExitProcess((unsigned)rc);
    return rc;
}
}
