// Stand-ins for audio: DirectSound (Xbox): each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_Release(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("IDirectSound_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Release(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("IDirectSoundBuffer_Release");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundUseFullHRTF(void) {
    HULK_XDK_TRACE("DirectSoundUseFullHRTF");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_DownloadEffectsImage(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("IDirectSound_DownloadEffectsImage");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetHeadroom(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("IDirectSoundBuffer_SetHeadroom");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("IDirectSoundBuffer_SetMixBinVolumes_8");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Play(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("IDirectSoundBuffer_Play");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Stop(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("IDirectSoundBuffer_Stop");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetStatus(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("IDirectSoundBuffer_GetStatus");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetCurrentPosition(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("IDirectSoundBuffer_GetCurrentPosition");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("IDirectSoundBuffer_SetCurrentPosition");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_DirectSoundDoWork(void) {
    HULK_XDK_TRACE("DirectSoundDoWork");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetFrequency(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("IDirectSoundBuffer_SetFrequency");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetBufferData(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("IDirectSoundBuffer_SetBufferData");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CommitDeferredSettings(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("IDirectSound_CommitDeferredSettings");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CreateSoundBuffer(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("IDirectSound_CreateSoundBuffer");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_SetI3DL2Listener(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("IDirectSound_SetI3DL2Listener");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_DirectSoundCreate(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("DirectSoundCreate");
    return 0;
}
