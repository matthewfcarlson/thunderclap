// Stand-ins for graphics: Direct3D 8 (Xbox): each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetDeviceCaps(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3D_GetDeviceCaps");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_CheckDeviceFormat(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("D3D_CheckDeviceFormat");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_SetPushBufferSize(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3D_SetPushBufferSize");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Direct3D_CreateDevice(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("Direct3D_CreateDevice");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetCreationParameters(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetCreationParameters");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetGammaRamp(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetGammaRamp");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetGammaRamp(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetGammaRamp");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTransform(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetTransform");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetTransform(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_GetTransform");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetViewport(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetViewport");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetMaterial(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetMaterial");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetBackMaterial(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetBackMaterial");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetLight(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_GetLight");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Release(void) {
    HULK_XDK_TRACE("D3DDevice_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVisibilityTestResult(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_GetVisibilityTestResult");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVerticalBlankCallback(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetVerticalBlankCallback");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_D3DDevice_BlockUntilVerticalBlank(void) {
    HULK_XDK_TRACE("D3DDevice_BlockUntilVerticalBlank");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Reset(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_Reset");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderTarget(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetRenderTarget");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetBackBuffer2(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetBackBuffer2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CopyRects(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("D3DDevice_CopyRects");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetRenderTarget2(void) {
    HULK_XDK_TRACE("D3DDevice_GetRenderTarget2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetDepthStencilSurface2(void) {
    HULK_XDK_TRACE("D3DDevice_GetDepthStencilSurface2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetViewport(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetViewport");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetLight(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetLight");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_LightEnable(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_LightEnable");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTexture(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetTexture");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPalette(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetPalette");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetIndices(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetIndices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Swap(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_Swap");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateTexture2(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5, hulk_u32 a6) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6;
    HULK_XDK_TRACE("D3DDevice_CreateTexture2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DTexture_GetSurfaceLevel2(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DTexture_GetSurfaceLevel2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DTexture_LockRect(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("D3DTexture_LockRect");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DVolumeTexture_LockBox(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("D3DVolumeTexture_LockBox");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateImageSurface_RenderTarget(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_CreateImageSurface_RenderTarget");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_GetDesc(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DSurface_GetDesc");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_LockRect(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DSurface_LockRect");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_AddRef(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DResource_AddRef");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_Release(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DResource_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexBuffer2(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_CreateVertexBuffer2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DVertexBuffer_Lock2(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DVertexBuffer_Lock2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreatePalette2(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_CreatePalette2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DPalette_Lock2(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DPalette_Lock2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVerticesUP(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_DrawVerticesUP");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVertices(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_DrawVertices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawIndexedVertices(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_DrawIndexedVertices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexShader(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_CreateVertexShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVertexShader(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetVertexShader");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant1(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstant1");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant4(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstant4");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstantNotInline(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstantNotInline");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetStreamSource(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetStreamSource");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVertexShader(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetVertexShader");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetRenderState_Simple(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_Simple");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_CullMode(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_CullMode");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_NormalizeNormals(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_NormalizeNormals");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_TextureFactor(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_TextureFactor");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_FillMode(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_FillMode");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_TwoSidedLighting(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_TwoSidedLighting");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTextureState_TexCoordIndex(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetTextureState_TexCoordIndex");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTextureState_BumpEnv(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetTextureState_BumpEnv");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_ZEnable(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_ZEnable");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_StencilEnable(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_StencilEnable");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderState_MultiSampleAntiAlias(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetRenderState_MultiSampleAntiAlias");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Clear(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("D3DDevice_Clear");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreatePixelShader(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_CreatePixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DeletePixelShader(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_DeletePixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetPixelShader(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetPixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShader(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetPixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShaderConstant(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetPixelShaderConstant");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_D3D_KickOffAndWaitForIdle(void) {
    HULK_XDK_TRACE("D3D_KickOffAndWaitForIdle");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Get2DSurfaceDesc(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("Get2DSurfaceDesc");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetSurfaceDesc_helper(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3D_GetSurfaceDesc_helper");
    return 0;
}
