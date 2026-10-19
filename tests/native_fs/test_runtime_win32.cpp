// The i686 test executable's runtime (tools/native_fs.py wine-test): an entry point and the few symbols the xdk
// stand-ins take from the native image (trace hooks, the host's last-error and CloseHandle), so file_io.cpp and
// saves.cpp can be tested outside the game image. Linked with SDL3.lib and msvcrt/kernel32 import libraries.
extern "C" int printf(const char*, ...);
extern "C" __declspec(dllimport) void __stdcall ExitProcess(unsigned);
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned);
extern "C" __declspec(dllimport) unsigned __stdcall GetLastError(void);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

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

// src/platform/sdl/crt (host kernel32 under an image-private name)
void __stdcall hulk_host_SetLastError(hulk_u32 code)
{
    SetLastError(code);
}
hulk_u32 __stdcall hulk_host_GetLastError(void)
{
    return GetLastError();
}
int __stdcall hulk_host_CloseHandle(void* h)
{
    return CloseHandle(h);
}

unsigned test_last_error(void)
{
    return GetLastError();
}
void test_set_last_error(unsigned e)
{
    SetLastError(e);
}

int __cdecl hulk_test_entry(void)
{
    int rc = test_main();
    ExitProcess((unsigned)rc);
    return rc;
}
}
