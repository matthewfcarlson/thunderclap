// Stand-ins for input: XPP / XInput: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInitDevices(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XInitDevices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputOpen(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("XInputOpen");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputClose(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XInputClose");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputGetState(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XInputGetState");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputSetState(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XInputSetState");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDevices(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XGetDevices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDeviceChanges(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XGetDeviceChanges");
    return 0;
}
