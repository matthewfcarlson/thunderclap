// The XDK / XAPI / Bink imports of the native image: one stand-in per library function the tree calls.
// First written by tools/native_shim.py --skeleton from build/native/shim-inventory.json (docs/native-build.md "Platform shim");
// maintained by hand from here on (the tool refuses to overwrite it).
//
// The tree calls a library function under many names (one per source that declares it, with its own
// parameter types); tools/native_link.py aliases every one of them to the hulk_xdk_<name> below by the
// XBE address in its HULK_XDK_IMPORTS line. Each prototype keeps only what the callers' machine code
// depends on: the calling convention, the stack bytes the callee pops, and the return register
// (float: st0). Typed signatures come with the real backends (src/platform/sdl/, SDL3).
#ifndef HULK_PLATFORM_SDL_XDK_IMPORTS_H
#define HULK_PLATFORM_SDL_XDK_IMPORTS_H

#include "xdk_shim.h"

// One X(xbe address, name, subsystem) per import; the stand-in is hulk_xdk_<name>.
#define HULK_XDK_IMPORTS(X) \
    X(0x0037d480, D3D_GetDeviceCaps, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037d780, D3D_CheckDeviceFormat, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037d8e0, D3D_SetPushBufferSize, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037d900, Direct3D_CreateDevice, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037d9e0, D3DDevice_GetCreationParameters, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037da20, D3DDevice_SetGammaRamp, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dab0, D3DDevice_GetGammaRamp, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037db40, D3DDevice_SetTransform, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dc60, D3DDevice_GetTransform, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dcf0, D3DDevice_GetViewport, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dd30, D3DDevice_SetMaterial, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dd80, D3DDevice_SetBackMaterial, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dde0, D3DDevice_GetLight, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037ded0, D3DDevice_Release, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037df40, D3DDevice_GetVisibilityTestResult, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dfb0, D3DDevice_SetVerticalBlankCallback, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037dff0, D3DDevice_BlockUntilVerticalBlank, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037eb70, D3DDevice_Reset, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037ec20, D3DDevice_SetRenderTarget, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037efc0, D3DDevice_GetBackBuffer2, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037f3b0, D3DDevice_CopyRects, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037f6e0, D3DDevice_GetRenderTarget2, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037f700, D3DDevice_GetDepthStencilSurface2, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037f720, D3DDevice_SetViewport, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037f950, D3DDevice_SetLight, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037fc10, D3DDevice_LightEnable, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037fda0, D3DDevice_SetTexture, "graphics: Direct3D 8 (Xbox)") \
    X(0x0037ff80, D3DDevice_SetPalette, "graphics: Direct3D 8 (Xbox)") \
    X(0x00380010, D3DDevice_SetIndices, "graphics: Direct3D 8 (Xbox)") \
    X(0x00381df0, D3DDevice_Swap, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382100, D3DDevice_CreateTexture2, "graphics: Direct3D 8 (Xbox)") \
    X(0x003821d0, D3DTexture_GetSurfaceLevel2, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382220, D3DTexture_LockRect, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382320, D3DVolumeTexture_LockBox, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382400, D3DDevice_CreateImageSurface_RenderTarget, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382520, D3DSurface_GetDesc, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382540, D3DSurface_LockRect, "graphics: Direct3D 8 (Xbox)") \
    X(0x003828b0, D3DResource_AddRef, "graphics: Direct3D 8 (Xbox)") \
    X(0x003828f0, D3DResource_Release, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382db0, D3DDevice_CreateVertexBuffer2, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382e00, D3DVertexBuffer_Lock2, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382e90, D3DDevice_CreatePalette2, "graphics: Direct3D 8 (Xbox)") \
    X(0x00382ef0, D3DPalette_Lock2, "graphics: Direct3D 8 (Xbox)") \
    X(0x00383210, D3DDevice_DrawVerticesUP, "graphics: Direct3D 8 (Xbox)") \
    X(0x003834c0, D3DDevice_DrawVertices, "graphics: Direct3D 8 (Xbox)") \
    X(0x00383560, D3DDevice_DrawIndexedVertices, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384030, D3DDevice_CreateVertexShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384170, D3DDevice_GetVertexShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384190, D3DDevice_SetVertexShaderConstant1, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384240, D3DDevice_SetVertexShaderConstant4, "graphics: Direct3D 8 (Xbox)") \
    X(0x003843d0, D3DDevice_SetVertexShaderConstantNotInline, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384610, D3DDevice_SetStreamSource, "graphics: Direct3D 8 (Xbox)") \
    X(0x00384b70, D3DDevice_SetVertexShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385290, D3DDevice_SetRenderState_Simple, "graphics: Direct3D 8 (Xbox)") \
    X(0x003858a0, D3DDevice_SetRenderState_CullMode, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385950, D3DDevice_SetRenderState_NormalizeNormals, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385990, D3DDevice_SetRenderState_TextureFactor, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385bc0, D3DDevice_SetRenderState_FillMode, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385c70, D3DDevice_SetRenderState_TwoSidedLighting, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385d40, D3DDevice_SetTextureState_TexCoordIndex, "graphics: Direct3D 8 (Xbox)") \
    X(0x00385e50, D3DDevice_SetTextureState_BumpEnv, "graphics: Direct3D 8 (Xbox)") \
    X(0x00386870, D3DDevice_SetRenderState_ZEnable, "graphics: Direct3D 8 (Xbox)") \
    X(0x00386900, D3DDevice_SetRenderState_StencilEnable, "graphics: Direct3D 8 (Xbox)") \
    X(0x00386be0, D3DDevice_SetRenderState_MultiSampleAntiAlias, "graphics: Direct3D 8 (Xbox)") \
    X(0x00386d70, D3DDevice_Clear, "graphics: Direct3D 8 (Xbox)") \
    X(0x00387160, D3DDevice_CreatePixelShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x003871b0, D3DDevice_DeletePixelShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00387210, D3DDevice_GetPixelShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00387610, D3DDevice_SetPixelShader, "graphics: Direct3D 8 (Xbox)") \
    X(0x00387810, D3DDevice_SetPixelShaderConstant, "graphics: Direct3D 8 (Xbox)") \
    X(0x0038a5d0, D3D_KickOffAndWaitForIdle, "graphics: Direct3D 8 (Xbox)") \
    X(0x0038abf0, Get2DSurfaceDesc, "graphics: Direct3D 8 (Xbox)") \
    X(0x0038acb0, D3D_GetSurfaceDesc_helper, "graphics: Direct3D 8 (Xbox)") \
    X(0x003a04fc, XGBuffer_GetBufferPointer, "graphics: XGraphics") \
    X(0x003a41dc, XGBuffer_Release, "graphics: XGraphics") \
    X(0x003a8753, XGAssembleShader, "graphics: XGraphics") \
    X(0x003a9114, XGIsSwizzledFormat, "graphics: XGraphics") \
    X(0x003a9a93, XGSwizzleRect, "graphics: XGraphics") \
    X(0x003aa8fb, XGSwizzleBox, "graphics: XGraphics") \
    X(0x003c4701, IDirectSound_Release, "audio: DirectSound (Xbox)") \
    X(0x003c4737, IDirectSoundBuffer_Release, "audio: DirectSound (Xbox)") \
    X(0x003c4789, DirectSoundUseFullHRTF, "audio: DirectSound (Xbox)") \
    X(0x003c696c, IDirectSound_DownloadEffectsImage, "audio: DirectSound (Xbox)") \
    X(0x003c6b86, IDirectSoundBuffer_SetHeadroom, "audio: DirectSound (Xbox)") \
    X(0x003c6ba2, IDirectSoundBuffer_SetMixBinVolumes_8, "audio: DirectSound (Xbox)") \
    X(0x003c6bbe, IDirectSoundBuffer_Play, "audio: DirectSound (Xbox)") \
    X(0x003c6c06, IDirectSoundBuffer_Stop, "audio: DirectSound (Xbox)") \
    X(0x003c6ca2, IDirectSoundBuffer_GetStatus, "audio: DirectSound (Xbox)") \
    X(0x003c6cbe, IDirectSoundBuffer_GetCurrentPosition, "audio: DirectSound (Xbox)") \
    X(0x003c6cde, IDirectSoundBuffer_SetCurrentPosition, "audio: DirectSound (Xbox)") \
    X(0x003c6e34, DirectSoundDoWork, "audio: DirectSound (Xbox)") \
    X(0x003c89b1, IDirectSoundBuffer_SetFrequency, "audio: DirectSound (Xbox)") \
    X(0x003c93c9, IDirectSoundBuffer_SetBufferData, "audio: DirectSound (Xbox)") \
    X(0x003c98ca, IDirectSound_CommitDeferredSettings, "audio: DirectSound (Xbox)") \
    X(0x003c9ea7, IDirectSound_CreateSoundBuffer, "audio: DirectSound (Xbox)") \
    X(0x003ca02f, IDirectSound_SetI3DL2Listener, "audio: DirectSound (Xbox)") \
    X(0x003ca1f5, DirectSoundCreate, "audio: DirectSound (Xbox)") \
    X(0x00355791, XFindNextSoundtrack, "audio: user soundtracks (a song-info query, 6 words; sa1)") \
    X(0x003559b9, XOpenSoundtrackSong, "audio: user soundtracks") \
    X(0x00355ab5, XFindFirstSoundtrack, "XAPI find-first file (mapped path, find data): core::XboxDrive::vfunc_18; the name is historical (sa1)") \
    X(0x00364da0, Bink_364da0, "movies: Bink") \
    X(0x00364dc0, Bink_364dc0, "movies: Bink") \
    X(0x00364fe0, Bink_364fe0, "movies: Bink") \
    X(0x00365f30, Bink_365f30, "movies: Bink") \
    X(0x00366940, Bink_366940, "movies: Bink") \
    X(0x00366b40, Bink_366b40, "movies: Bink") \
    X(0x00367bc0, Bink_367bc0, "movies: Bink") \
    X(0x003681d0, Bink_3681d0, "movies: Bink") \
    X(0x00368530, Bink_368530, "movies: Bink") \
    X(0x00368660, Bink_368660, "movies: Bink") \
    X(0x003eac33, XInitDevices, "input: XPP / XInput") \
    X(0x003eb6e5, XInputOpen, "input: XPP / XInput") \
    X(0x003eb73b, XInputClose, "input: XPP / XInput") \
    X(0x003eb91f, XInputGetState, "input: XPP / XInput") \
    X(0x003eb992, XInputSetState, "input: XPP / XInput") \
    X(0x003eba81, XGetDevices, "input: XPP / XInput") \
    X(0x003ebaa3, XGetDeviceChanges, "input: XPP / XInput") \
    X(0x00208b9c, GetDiskFreeSpaceExA, "file I/O") \
    X(0x00209a8e, XGetDiskSectorSizeA, "file I/O") \
    X(0x0020bbc2, CloseHandle, "file I/O") \
    X(0x0020ff8d, ReadFile, "file I/O") \
    X(0x0021007a, WriteFile, "file I/O") \
    X(0x00210150, SetEndOfFile, "file I/O") \
    X(0x002101d4, SetFilePointer, "file I/O") \
    X(0x002109b6, GetFileSize, "file I/O") \
    X(0x002109f1, CreateFileA, "file I/O") \
    X(0x0021257d, XapiOpenDirectory, "file I/O") \
    X(0x00209237, XFormatUtilityDrive, "saves / storage") \
    X(0x00209b29, XMUNameFromDriveLetter, "saves / storage") \
    X(0x002120e1, XCalculateSignatureBegin, "saves / storage") \
    X(0x002120f5, XCalculateSignatureUpdate, "saves / storage") \
    X(0x00212143, XCalculateSignatureEnd, "saves / storage") \
    X(0x0035618d, XCreateSaveGame, "saves / storage") \
    X(0x003563f0, XDeleteSaveGame_XFindFirstSaveGame, "saves / storage") \
    X(0x003564c0, XFindFirstSaveGame, "saves / storage") \
    X(0x003565ca, XFindNextSaveGame, "saves / storage") \
    X(0x00356611, XFindClose, "saves / storage") \
    X(0x003ebfe2, XMountMUA, "saves / storage") \
    X(0x003ec280, XUnmountMU, "saves / storage") \
    X(0x0020bc3e, SetThreadPriority, "threads / sync / fibers") \
    X(0x0020bd91, ResumeThread, "threads / sync / fibers") \
    X(0x0020be50, ExitThread, "threads / sync / fibers") \
    X(0x0020c0dd, CreateThread, "threads / sync / fibers") \
    X(0x0020c14b, GetCurrentThreadId, "threads / sync / fibers") \
    X(0x0020c2c9, CreateSemaphoreA, "threads / sync / fibers") \
    X(0x0020c380, ReleaseSemaphore, "threads / sync / fibers") \
    X(0x0020c6f7, WaitForSingleObject, "threads / sync / fibers") \
    X(0x0020c723, Sleep, "threads / sync / fibers") \
    X(0x0035547e, CreateFiber, "threads / sync / fibers") \
    X(0x0035550a, DeleteFiber, "threads / sync / fibers") \
    X(0x0035551d, SwitchToFiber, "threads / sync / fibers") \
    X(0x00355563, ConvertThreadToFiber, "threads / sync / fibers") \
    X(0x00354cd1, QueryPerformanceCounter, "timing") \
    X(0x00354ce2, QueryPerformanceFrequency, "timing") \
    X(0x00355364, GetLocalTime, "timing") \
    X(0x00209f01, GlobalMemoryStatus, "memory") \
    X(0x0020c731, HeapCreate, "memory") \
    X(0x0020c79c, HeapFree, "memory") \
    X(0x0020d7ff, HeapSize, "memory") \
    X(0x0020e1a1, HeapAlloc, "memory") \
    X(0x00209c04, XLaunchNewImageA, "process / system settings") \
    X(0x00209d27, XGetLaunchInfo, "process / system settings") \
    X(0x00209f50, XGetLanguage, "process / system settings") \
    X(0x0020a0b7, GetLastError, "process / system settings") \
    X(0x00354c8f, XGetAudioFlags, "process / system settings") \
    X(0x00356667, XGetVideoFlags, "process / system settings") \
    X(0x00355d0d, OutputDebugStringA, "debug")

extern "C" {

// --- graphics: Direct3D 8 (Xbox) (graphics_d3d8.cpp, 73 functions)
hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetDeviceCaps(hulk_u32, hulk_u32, hulk_uptr);  // 0x0037d480
hulk_u32 HULK_STDCALL hulk_xdk_D3D_CheckDeviceFormat(hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32);  // 0x0037d780
hulk_u32 HULK_STDCALL hulk_xdk_D3D_SetPushBufferSize(hulk_u32, hulk_u32);  // 0x0037d8e0
hulk_u32 HULK_STDCALL hulk_xdk_Direct3D_CreateDevice(hulk_u32, hulk_u32, hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr);  // 0x0037d900
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetCreationParameters(hulk_uptr);  // 0x0037d9e0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetGammaRamp(hulk_u32, hulk_uptr);  // 0x0037da20
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetGammaRamp(hulk_uptr);  // 0x0037dab0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTransform(hulk_u32, hulk_uptr);  // 0x0037db40
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetTransform(hulk_u32, hulk_uptr);  // 0x0037dc60
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetViewport(hulk_uptr);  // 0x0037dcf0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetMaterial(hulk_uptr);  // 0x0037dd30
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetBackMaterial(hulk_uptr);  // 0x0037dd80
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetLight(hulk_u32, hulk_uptr);  // 0x0037dde0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Release(void);  // 0x0037ded0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVisibilityTestResult(hulk_u32, hulk_uptr, hulk_uptr);  // 0x0037df40
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVerticalBlankCallback(hulk_uptr);  // 0x0037dfb0
hulk_u32 HULK_CDECL hulk_xdk_D3DDevice_BlockUntilVerticalBlank(void);  // 0x0037dff0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Reset(hulk_uptr);  // 0x0037eb70
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderTarget(hulk_uptr, hulk_uptr);  // 0x0037ec20
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetBackBuffer2(hulk_u32);  // 0x0037efc0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CopyRects(hulk_uptr, hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr);  // 0x0037f3b0
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetRenderTarget2(void);  // 0x0037f6e0
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetDepthStencilSurface2(void);  // 0x0037f700
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetViewport(hulk_uptr);  // 0x0037f720
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetLight(hulk_u32, hulk_uptr);  // 0x0037f950
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_LightEnable(hulk_u32, hulk_u32);  // 0x0037fc10
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTexture(hulk_u32, hulk_uptr);  // 0x0037fda0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPalette(hulk_u32, hulk_uptr);  // 0x0037ff80
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetIndices(hulk_uptr, hulk_u32);  // 0x00380010
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Swap(hulk_u32);  // 0x00381df0
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreateTexture2(hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32);  // 0x00382100
hulk_uptr HULK_STDCALL hulk_xdk_D3DTexture_GetSurfaceLevel2(hulk_uptr, hulk_u32);  // 0x003821d0
hulk_u32 HULK_STDCALL hulk_xdk_D3DTexture_LockRect(hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr, hulk_u32);  // 0x00382220
hulk_u32 HULK_STDCALL hulk_xdk_D3DVolumeTexture_LockBox(hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr, hulk_u32);  // 0x00382320
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateImageSurface_RenderTarget(hulk_u32, hulk_u32, hulk_u32, hulk_uptr);  // 0x00382400 D3DDevice_CreateImageSurface/RenderTarget
hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_GetDesc(hulk_uptr, hulk_uptr);  // 0x00382520
hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_LockRect(hulk_uptr, hulk_uptr, hulk_uptr, hulk_u32);  // 0x00382540
hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_AddRef(hulk_uptr);  // 0x003828b0
hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_Release(hulk_uptr);  // 0x003828f0
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexBuffer2(hulk_u32);  // 0x00382db0
hulk_uptr HULK_STDCALL hulk_xdk_D3DVertexBuffer_Lock2(hulk_uptr, hulk_u32);  // 0x00382e00
hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreatePalette2(hulk_u32);  // 0x00382e90
hulk_uptr HULK_STDCALL hulk_xdk_D3DPalette_Lock2(hulk_uptr, hulk_u32);  // 0x00382ef0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVerticesUP(hulk_u32, hulk_u32, hulk_uptr, hulk_u32);  // 0x00383210
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVertices(hulk_u32, hulk_u32, hulk_u32);  // 0x003834c0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawIndexedVertices(hulk_u32, hulk_u32, hulk_uptr);  // 0x00383560
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexShader(hulk_uptr, hulk_uptr, hulk_uptr, hulk_u32);  // 0x00384030
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVertexShader(hulk_uptr);  // 0x00384170
hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant1(hulk_u32, hulk_uptr);  // 0x00384190
hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant4(hulk_u32, hulk_uptr);  // 0x00384240
hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstantNotInline(hulk_u32, hulk_uptr, hulk_u32);  // 0x003843d0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetStreamSource(hulk_u32, hulk_uptr, hulk_u32);  // 0x00384610
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVertexShader(hulk_uptr);  // 0x00384b70
hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetRenderState_Simple(hulk_u32, hulk_u32);  // 0x00385290
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_CullMode(hulk_u32);  // 0x003858a0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_NormalizeNormals(hulk_u32);  // 0x00385950
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_TextureFactor(hulk_u32);  // 0x00385990  [called as a member function (thiscall)]
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_FillMode(hulk_u32);  // 0x00385bc0  [callers disagree: stdcall/4 x2, cdecl x1]
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_TwoSidedLighting(hulk_u32);  // 0x00385c70
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTextureState_TexCoordIndex(hulk_u32, hulk_u32);  // 0x00385d40
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTextureState_BumpEnv(hulk_u32, hulk_u32, hulk_u32);  // 0x00385e50
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_ZEnable(hulk_u32);  // 0x00386870
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_StencilEnable(hulk_u32);  // 0x00386900
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_MultiSampleAntiAlias(hulk_u32);  // 0x00386be0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Clear(hulk_u32, hulk_uptr, hulk_u32, hulk_u32, hulk_u32, hulk_u32);  // 0x00386d70
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreatePixelShader(hulk_uptr, hulk_uptr);  // 0x00387160
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DeletePixelShader(hulk_uptr);  // 0x003871b0
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetPixelShader(hulk_uptr);  // 0x00387210
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShader(hulk_uptr);  // 0x00387610
hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShaderConstant(hulk_u32, hulk_uptr, hulk_u32);  // 0x00387810
hulk_u32 HULK_CDECL hulk_xdk_D3D_KickOffAndWaitForIdle(void);  // 0x0038a5d0
hulk_u32 HULK_STDCALL hulk_xdk_Get2DSurfaceDesc(hulk_uptr, hulk_u32, hulk_uptr);  // 0x0038abf0
hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetSurfaceDesc_helper(hulk_uptr, hulk_u32, hulk_uptr);  // 0x0038acb0 D3D GetSurfaceDesc helper

// --- graphics: XGraphics (graphics_xgraphics.cpp, 6 functions)
hulk_uptr HULK_STDCALL hulk_xdk_XGBuffer_GetBufferPointer(hulk_uptr);  // 0x003a04fc
hulk_u32 HULK_STDCALL hulk_xdk_XGBuffer_Release(hulk_uptr);  // 0x003a41dc
hulk_u32 HULK_STDCALL hulk_xdk_XGAssembleShader(hulk_uptr, hulk_uptr, hulk_u32, hulk_u32, hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr);  // 0x003a8753
hulk_u32 HULK_STDCALL hulk_xdk_XGIsSwizzledFormat(hulk_u32);  // 0x003a9114
hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleRect(hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr, hulk_u32, hulk_u32, hulk_uptr, hulk_u32);  // 0x003a9a93
hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleBox(hulk_uptr, hulk_u32, hulk_u32, hulk_uptr, hulk_uptr, hulk_u32, hulk_u32, hulk_u32, hulk_uptr, hulk_u32);  // 0x003aa8fb

// --- audio: DirectSound (Xbox) (audio_dsound.cpp, 18 functions)
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_Release(hulk_uptr);  // 0x003c4701
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Release(hulk_uptr);  // 0x003c4737
hulk_u32 HULK_CDECL hulk_xdk_DirectSoundUseFullHRTF(void);  // 0x003c4789
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_DownloadEffectsImage(hulk_uptr, hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr);  // 0x003c696c
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetHeadroom(hulk_uptr, hulk_u32);  // 0x003c6b86
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetMixBinVolumes_8(hulk_uptr, hulk_uptr);  // 0x003c6ba2
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Play(hulk_uptr, hulk_u32, hulk_u32, hulk_u32);  // 0x003c6bbe
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_Stop(hulk_uptr);  // 0x003c6c06
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetStatus(hulk_uptr, hulk_uptr);  // 0x003c6ca2
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_GetCurrentPosition(hulk_uptr, hulk_uptr, hulk_uptr);  // 0x003c6cbe
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetCurrentPosition(hulk_uptr, hulk_u32);  // 0x003c6cde
hulk_u32 HULK_CDECL hulk_xdk_DirectSoundDoWork(void);  // 0x003c6e34
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetFrequency(hulk_uptr, hulk_u32);  // 0x003c89b1
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSoundBuffer_SetBufferData(hulk_uptr, hulk_uptr, hulk_u32);  // 0x003c93c9
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CommitDeferredSettings(hulk_uptr);  // 0x003c98ca
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_CreateSoundBuffer(hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr);  // 0x003c9ea7
hulk_u32 HULK_STDCALL hulk_xdk_IDirectSound_SetI3DL2Listener(hulk_uptr, hulk_uptr, hulk_u32);  // 0x003ca02f
hulk_u32 HULK_STDCALL hulk_xdk_DirectSoundCreate(hulk_uptr, hulk_uptr, hulk_uptr);  // 0x003ca1f5

// --- audio: user soundtracks (audio_soundtracks.cpp, 3 functions)
hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSoundtrack(hulk_u32, hulk_u32, hulk_uptr, hulk_uptr, hulk_uptr, hulk_u32);  // 0x00355791
hulk_uptr HULK_STDCALL hulk_xdk_XOpenSoundtrackSong(hulk_u32, hulk_u32);  // 0x003559b9
hulk_uptr HULK_STDCALL hulk_xdk_XFindFirstSoundtrack(hulk_uptr, hulk_uptr);  // 0x00355ab5

// --- movies: Bink (movies_bink.cpp, 10 functions)
hulk_u32 HULK_STDCALL hulk_xdk_Bink_364da0(hulk_uptr);  // 0x00364da0 FUN_00364da0
hulk_u32 HULK_STDCALL hulk_xdk_Bink_364dc0(hulk_u32, hulk_uptr);  // 0x00364dc0 FUN_00364dc0
hulk_uptr HULK_STDCALL hulk_xdk_Bink_364fe0(hulk_uptr, hulk_u32);  // 0x00364fe0 FUN_00364fe0
hulk_u32 HULK_STDCALL hulk_xdk_Bink_365f30(hulk_uptr, hulk_uptr, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32, hulk_u32);  // 0x00365f30 FUN_00365f30
hulk_u32 HULK_STDCALL hulk_xdk_Bink_366940(hulk_uptr);  // 0x00366940 FUN_00366940
hulk_u32 HULK_STDCALL hulk_xdk_Bink_366b40(hulk_uptr, hulk_u32);  // 0x00366b40 FUN_00366b40
hulk_u32 HULK_STDCALL hulk_xdk_Bink_367bc0(hulk_uptr);  // 0x00367bc0 FUN_00367bc0
hulk_u32 HULK_STDCALL hulk_xdk_Bink_3681d0(hulk_uptr);  // 0x003681d0 FUN_003681d0
hulk_u32 HULK_STDCALL hulk_xdk_Bink_368530(hulk_uptr);  // 0x00368530 FUN_00368530
hulk_u32 HULK_CDECL hulk_xdk_Bink_368660(void);  // 0x00368660 FUN_00368660

// --- input: XPP / XInput (input_xpp.cpp, 7 functions)
hulk_u32 HULK_STDCALL hulk_xdk_XInitDevices(hulk_u32, hulk_uptr);  // 0x003eac33
hulk_uptr HULK_STDCALL hulk_xdk_XInputOpen(hulk_uptr, hulk_u32, hulk_u32, hulk_uptr);  // 0x003eb6e5
hulk_u32 HULK_STDCALL hulk_xdk_XInputClose(hulk_uptr);  // 0x003eb73b
hulk_u32 HULK_STDCALL hulk_xdk_XInputGetState(hulk_uptr, hulk_uptr);  // 0x003eb91f
hulk_u32 HULK_STDCALL hulk_xdk_XInputSetState(hulk_uptr, hulk_uptr);  // 0x003eb992
hulk_u32 HULK_STDCALL hulk_xdk_XGetDevices(hulk_uptr);  // 0x003eba81
hulk_u32 HULK_STDCALL hulk_xdk_XGetDeviceChanges(hulk_uptr, hulk_uptr, hulk_uptr);  // 0x003ebaa3

// --- file I/O (file_io.cpp, 10 functions)
hulk_u32 HULK_STDCALL hulk_xdk_GetDiskFreeSpaceExA(hulk_uptr, hulk_uptr, hulk_uptr, hulk_uptr);  // 0x00208b9c
hulk_u32 HULK_STDCALL hulk_xdk_XGetDiskSectorSizeA(hulk_uptr);  // 0x00209a8e
hulk_u32 HULK_STDCALL hulk_xdk_CloseHandle(hulk_uptr);  // 0x0020bbc2
hulk_u32 HULK_STDCALL hulk_xdk_ReadFile(hulk_uptr, hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr);  // 0x0020ff8d
hulk_u32 HULK_STDCALL hulk_xdk_WriteFile(hulk_uptr, hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr);  // 0x0021007a
hulk_u32 HULK_STDCALL hulk_xdk_SetEndOfFile(hulk_uptr);  // 0x00210150
hulk_u32 HULK_STDCALL hulk_xdk_SetFilePointer(hulk_uptr, hulk_u32, hulk_uptr, hulk_u32);  // 0x002101d4
hulk_u32 HULK_STDCALL hulk_xdk_GetFileSize(hulk_uptr, hulk_uptr);  // 0x002109b6
hulk_uptr HULK_STDCALL hulk_xdk_CreateFileA(hulk_uptr, hulk_u32, hulk_u32, hulk_uptr, hulk_u32, hulk_u32, hulk_uptr);  // 0x002109f1
hulk_u32 HULK_STDCALL hulk_xdk_XapiOpenDirectory(hulk_uptr);  // 0x0021257d XapiOpenDirectory (NtOpenFile dir)

// --- saves / storage (saves.cpp, 12 functions)
hulk_u32 HULK_CDECL hulk_xdk_XFormatUtilityDrive(void);  // 0x00209237
hulk_u32 HULK_STDCALL hulk_xdk_XMUNameFromDriveLetter(hulk_u32, hulk_uptr, hulk_u32);  // 0x00209b29
hulk_uptr HULK_STDCALL hulk_xdk_XCalculateSignatureBegin(hulk_u32);  // 0x002120e1
hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureUpdate(hulk_uptr, hulk_uptr, hulk_u32);  // 0x002120f5
hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureEnd(hulk_uptr, hulk_uptr);  // 0x00212143
hulk_u32 HULK_STDCALL hulk_xdk_XCreateSaveGame(hulk_uptr, hulk_uptr, hulk_u32, hulk_u32, hulk_uptr, hulk_u32);  // 0x0035618d
hulk_u32 HULK_STDCALL hulk_xdk_XDeleteSaveGame_XFindFirstSaveGame(hulk_uptr, hulk_uptr);  // 0x003563f0 XDeleteSaveGame / XFindFirstSaveGame
hulk_uptr HULK_STDCALL hulk_xdk_XFindFirstSaveGame(hulk_uptr, hulk_uptr);  // 0x003564c0
hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSaveGame(hulk_uptr, hulk_uptr);  // 0x003565ca
hulk_u32 HULK_STDCALL hulk_xdk_XFindClose(hulk_uptr);  // 0x00356611
hulk_u32 HULK_STDCALL hulk_xdk_XMountMUA(hulk_u32, hulk_u32, hulk_uptr);  // 0x003ebfe2
hulk_u32 HULK_STDCALL hulk_xdk_XUnmountMU(hulk_u32, hulk_u32);  // 0x003ec280

// --- threads / sync / fibers (threads.cpp, 13 functions)
hulk_u32 HULK_STDCALL hulk_xdk_SetThreadPriority(hulk_uptr, hulk_u32);  // 0x0020bc3e
hulk_u32 HULK_STDCALL hulk_xdk_ResumeThread(hulk_uptr);  // 0x0020bd91
hulk_u32 HULK_STDCALL hulk_xdk_ExitThread(hulk_u32);  // 0x0020be50
hulk_uptr HULK_STDCALL hulk_xdk_CreateThread(hulk_uptr, hulk_u32, hulk_uptr, hulk_uptr, hulk_u32, hulk_uptr);  // 0x0020c0dd
hulk_u32 HULK_CDECL hulk_xdk_GetCurrentThreadId(void);  // 0x0020c14b
hulk_uptr HULK_STDCALL hulk_xdk_CreateSemaphoreA(hulk_uptr, hulk_u32, hulk_u32, hulk_uptr);  // 0x0020c2c9
hulk_u32 HULK_STDCALL hulk_xdk_ReleaseSemaphore(hulk_uptr, hulk_u32, hulk_uptr);  // 0x0020c380
hulk_u32 HULK_STDCALL hulk_xdk_WaitForSingleObject(hulk_uptr, hulk_u32);  // 0x0020c6f7
hulk_u32 HULK_STDCALL hulk_xdk_Sleep(hulk_u32);  // 0x0020c723
hulk_uptr HULK_STDCALL hulk_xdk_CreateFiber(hulk_u32, hulk_uptr, hulk_uptr);  // 0x0035547e
hulk_u32 HULK_STDCALL hulk_xdk_DeleteFiber(hulk_uptr);  // 0x0035550a
hulk_u32 HULK_STDCALL hulk_xdk_SwitchToFiber(hulk_uptr);  // 0x0035551d
hulk_uptr HULK_STDCALL hulk_xdk_ConvertThreadToFiber(hulk_uptr);  // 0x00355563

// --- timing (timing.cpp, 3 functions)
hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceCounter(hulk_uptr);  // 0x00354cd1
hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceFrequency(hulk_uptr);  // 0x00354ce2
hulk_u32 HULK_STDCALL hulk_xdk_GetLocalTime(hulk_uptr);  // 0x00355364

// --- memory (memory.cpp, 5 functions)
hulk_u32 HULK_STDCALL hulk_xdk_GlobalMemoryStatus(hulk_uptr);  // 0x00209f01
hulk_uptr HULK_STDCALL hulk_xdk_HeapCreate(hulk_u32, hulk_u32, hulk_u32);  // 0x0020c731
hulk_u32 HULK_STDCALL hulk_xdk_HeapFree(hulk_uptr, hulk_u32, hulk_uptr);  // 0x0020c79c
hulk_u32 HULK_STDCALL hulk_xdk_HeapSize(hulk_uptr, hulk_u32, hulk_uptr);  // 0x0020d7ff
hulk_uptr HULK_STDCALL hulk_xdk_HeapAlloc(hulk_uptr, hulk_u32, hulk_u32);  // 0x0020e1a1

// --- process / system settings (system.cpp, 6 functions)
hulk_u32 HULK_STDCALL hulk_xdk_XLaunchNewImageA(hulk_uptr, hulk_uptr);  // 0x00209c04
hulk_u32 HULK_STDCALL hulk_xdk_XGetLaunchInfo(hulk_uptr, hulk_uptr);  // 0x00209d27
hulk_u32 HULK_CDECL hulk_xdk_XGetLanguage(void);  // 0x00209f50
hulk_u32 HULK_STDCALL hulk_xdk_GetLastError(void);  // 0x0020a0b7
hulk_u32 HULK_CDECL hulk_xdk_XGetAudioFlags(void);  // 0x00354c8f
hulk_u32 HULK_CDECL hulk_xdk_XGetVideoFlags(void);  // 0x00356667

// --- debug (debug.cpp, 1 functions)
hulk_u32 HULK_STDCALL hulk_xdk_OutputDebugStringA(hulk_uptr);  // 0x00355d0d

}  // extern "C"

#endif
