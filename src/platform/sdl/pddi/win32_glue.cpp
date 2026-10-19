// What the i686 Windows build of bgfx (and this directory) needs from the native image's runtime besides import
// libraries (build/g0/LINK.md). Native game builds only.
//
// 1. Static initializers. The native image's start-up runs the game's initializer table, not clang's `.CRT$XCU`
//    entries (src/platform/sdl/xdk/startup.cpp). tools/native_gfx.py renames the `.CRT$XCU` section of every bx,
//    bimg, bgfx and pddi object to `.CRT$XHU`, so these entries sort between our own `.CRT$XHA` / `.CRT$XHZ`
//    markers (lld-link orders `.CRT$X*` by name) and nothing else runs them twice. hulk_pddi_run_initializers runs
//    them once, before the first device is created.
// 2. msvcrt.dll lacks a few CRT functions bx calls at start-up (UCRT/msvcr80+ names): stand-ins that change nothing.
#if HULK_PDDI_GAME && defined(_WIN32)

#include <stdio.h>
#include <stdlib.h>

typedef void(__cdecl* hulk_pddi_init_fn)(void);

#pragma section(".CRT$XHA", read)
#pragma section(".CRT$XHZ", read)
__declspec(allocate(".CRT$XHA")) static hulk_pddi_init_fn s_xh_a = 0;
__declspec(allocate(".CRT$XHZ")) static hulk_pddi_init_fn s_xh_z = 0;

extern "C" void hulk_pddi_run_initializers(void)
{
    static bool done;
    if (done)
        return;
    done = true;
    for (const hulk_pddi_init_fn* p = &s_xh_a + 1; p < &s_xh_z; p++)
        if (*p)
            (*p)();
}

extern "C" {
// mingw-w64's stdio.h spells stdin/stdout/stderr through the UCRT's accessor; msvcrt.dll has __iob_func (32-byte FILEs)
FILE* __cdecl __acrt_iob_func(unsigned index)
{
    return (FILE*)((char*)__iob_func() + 32 * index);
}
unsigned int __cdecl _set_abort_behavior(unsigned int, unsigned int)
{
    return 0;
}
_invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler)
{
    return 0;
}
_invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(_invalid_parameter_handler)
{
    return 0;
}
_purecall_handler __cdecl _set_purecall_handler(_purecall_handler)
{
    return 0;
}
}

#endif
