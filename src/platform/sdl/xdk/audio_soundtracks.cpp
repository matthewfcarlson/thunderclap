// User soundtracks (XAPI) for the native image: there are none. Each stand-in counts its calls (xdk_shim.h).
//
// What the game's call sites say these three are (core::XboxDrive, equivalent/0x0026f7b0 and 0x0026fa40), which is
// not quite what tools/platform_map.py's names (kept in imports.h for the binding) suggest:
//   0x00355791 "XFindNextSoundtrack": stdcall (soundtrack id, song index, &song id, &length, name, name size) ->
//              BOOL, for "W:\<soundtrack>\<song>" paths (a song-info query)
//   0x003559b9 "XOpenSoundtrackSong": stdcall (song id, async) -> HANDLE (INVALID_HANDLE_VALUE on failure)
//   0x00355ab5 "XFindFirstSoundtrack": stdcall (path, find data*) -> HANDLE; the caller reads the find data's
//              attributes (+0) and name (+44) and treats GetLastError 2 / 18 as "nothing there" - it is the drive's
//              find-first-file (directory listing), not a soundtrack call. Here: nothing found (ERROR_FILE_NOT_FOUND);
//              a real directory listing belongs with file_io.cpp (build/sa1/for-native9.md).
#include "imports.h"
#include "../crt/host_crt.h"

#define HULK_INVALID_HANDLE 0xffffffffu
#define HULK_ERROR_FILE_NOT_FOUND 2u

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSoundtrack(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a4; (void)a5;
    HULK_XDK_TRACE("XFindNextSoundtrack");
    if (a2)
        *(hulk_u32*)(__SIZE_TYPE__)a2 = 0;
    if (a3)
        *(hulk_u32*)(__SIZE_TYPE__)a3 = 0;
    return 0;   // FALSE: no such song
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XOpenSoundtrackSong(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XOpenSoundtrackSong");
    hulk_host_SetLastError(HULK_ERROR_FILE_NOT_FOUND);
    return HULK_INVALID_HANDLE;
}

#if defined(HULK_NATIVE_SDL) && !defined(HULK_NATIVE_NO_FS)
extern "C" hulk_u32 HULK_STDCALL hulk_fs_xdk_FindFirst(hulk_u32, hulk_u32);  // fs1: the drive's find-first-file
#endif
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindFirstSoundtrack(hulk_u32 a0, hulk_u32 a1) {
    HULK_XDK_TRACE("XFindFirstSoundtrack");
#if defined(HULK_NATIVE_SDL) && !defined(HULK_NATIVE_NO_FS)
    return hulk_fs_xdk_FindFirst(a0, a1);
#else
    (void)a0; (void)a1;
    hulk_host_SetLastError(HULK_ERROR_FILE_NOT_FOUND);
    return HULK_INVALID_HANDLE;
#endif
}
