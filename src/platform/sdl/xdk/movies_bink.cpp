// Stand-ins for movies: Bink: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364da0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_364da0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364dc0(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_364dc0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_364fe0(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_364fe0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_365f30(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5, hulk_u32 a6, hulk_u32 a7, hulk_u32 a8, hulk_u32 a9, hulk_u32 a10) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8; (void)a9; (void)a10;
    HULK_XDK_TRACE("Bink_365f30");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_366940(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_366940");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_366b40(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("Bink_366b40");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_367bc0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_367bc0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_3681d0(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_3681d0");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Bink_368530(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Bink_368530");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_Bink_368660(void) {
    HULK_XDK_TRACE("Bink_368660");
    return 0;
}
