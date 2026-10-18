// Library code and data the tree reaches by XBE address, beyond the 167 imports of imports.h (docs/native-build.md
// "Start-up"): XAPI / D3D / DSOUND / XGRAPHICS / Bink internals that the game's code calls or reads directly, and
// the kernel import slots it calls through. Never decompiled: each stand-in is our own, shaped by the game's call
// sites (pushes, cleanup, use of the result), as imports.h's are (docs/platform-boundary.md, rules 1-3).
//
// tools/native_link.py (tools/native_host.py library_table) reads the tables: every symbol bound to an X row's
// address is aliased to hulk_lib_<name>; every reference to a D row's address to our definition of that data.
#ifndef HULK_PLATFORM_SDL_XDK_LIBRARY_H
#define HULK_PLATFORM_SDL_XDK_LIBRARY_H

#include "xdk_shim.h"

// X(xbe address, name, "what the call sites say") per function; the stand-in is hulk_lib_<name>.
#define HULK_LIB_FUNCTIONS(X) \
    X(0x00355bc2, XapiConvertTime, "XAPI (saves/soundtracks): stdcall (int, int* out) -> int; core::Drive::vfunc_19") \
    X(0x00355c13, XapiCreatePath, "XAPI (saves/soundtracks): stdcall (char* path, int flag) -> int, 0 then GetLastError") \
    X(0x00355c7f, XapiCheckPath, "XAPI (saves/soundtracks): stdcall (const char* path) -> int") \
    X(0x00367610, Bink_367610, "Bink: stdcall (void*, void*, unsigned) from movie::PlayerBink") \
    X(0x00367660, Bink_367660, "Bink: stdcall (int, int, void*, int), once per track (0x44-byte records)") \
    X(0x0037d240, Direct3D_Object, "D3D: stdcall (int) -> object handed to a wrapper's Init (pddi device set-up)") \
    X(0x00382ce0, D3DDevice_CreateIndexBuffer2, "D3D: stdcall (length) -> index buffer") \
    X(0x00385850, D3DDevice_SetRenderState_FogColor, "D3D: stdcall (value)") \
    X(0x003869a0, D3DDevice_SetRenderState_StencilFail, "D3D: stdcall (value)")

// D(xbe address, our symbol, bytes) per data item.
#define HULK_LIB_DATA(D) \
    D(0x003f2c88, _hulk_lib_slot_RtlLeaveCriticalSection, 4) \
    D(0x003f2c8c, _hulk_lib_slot_RtlEnterCriticalSection, 4) \
    D(0x003f2d38, _hulk_lib_slot_RtlInitializeCriticalSection, 4) \
    D(0x0039db00, _hulk_lib_d3d_state, 1136) \
    D(0x003d5e68, _hulk_lib_dsound_words, 8) \
    D(0x003ea774, _hulk_lib_xpp_gamepad_type, 4) \
    D(0x003ea820, _hulk_lib_xpp_mu_type, 4)

extern "C" {
hulk_u32 HULK_STDCALL hulk_lib_XapiConvertTime(hulk_u32, hulk_u32);                        // 0x00355bc2
hulk_u32 HULK_STDCALL hulk_lib_XapiCreatePath(hulk_u32, hulk_u32);                         // 0x00355c13
hulk_u32 HULK_STDCALL hulk_lib_XapiCheckPath(hulk_u32);                                    // 0x00355c7f
hulk_u32 HULK_STDCALL hulk_lib_Bink_367610(hulk_u32, hulk_u32, hulk_u32);                  // 0x00367610
hulk_u32 HULK_STDCALL hulk_lib_Bink_367660(hulk_u32, hulk_u32, hulk_u32, hulk_u32);        // 0x00367660
hulk_u32 HULK_STDCALL hulk_lib_Direct3D_Object(hulk_u32);                                  // 0x0037d240
hulk_u32 HULK_STDCALL hulk_lib_D3DDevice_CreateIndexBuffer2(hulk_u32);                     // 0x00382ce0
hulk_u32 HULK_STDCALL hulk_lib_D3DDevice_SetRenderState_FogColor(hulk_u32);                // 0x00385850
hulk_u32 HULK_STDCALL hulk_lib_D3DDevice_SetRenderState_StencilFail(hulk_u32);             // 0x003869a0
}

#endif
