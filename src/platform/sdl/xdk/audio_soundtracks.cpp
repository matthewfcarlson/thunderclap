// Stand-ins for audio: user soundtracks: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSoundtrack(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("XFindNextSoundtrack");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XOpenSoundtrackSong(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XOpenSoundtrackSong");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindFirstSoundtrack(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XFindFirstSoundtrack");
    return 0;
}
