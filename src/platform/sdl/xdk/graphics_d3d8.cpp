// Stand-ins for graphics: Direct3D 8 (Xbox): each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory. The textures, their
// surfaces and palettes are real (x64t18, the end of the file).
#include "imports.h"
#include "../crt/host_crt.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetDeviceCaps(hulk_u32 a0, hulk_u32 a1, hulk_uptr a2) {
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

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetCreationParameters(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetCreationParameters");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetGammaRamp(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetGammaRamp");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetGammaRamp(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetGammaRamp");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTransform(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetTransform");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetTransform(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_GetTransform");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetViewport(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetViewport");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetMaterial(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetMaterial");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetBackMaterial(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetBackMaterial");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetLight(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_GetLight");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Release(void) {
    HULK_XDK_TRACE("D3DDevice_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVisibilityTestResult(hulk_u32 a0, hulk_uptr a1, hulk_uptr a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_GetVisibilityTestResult");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVerticalBlankCallback(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetVerticalBlankCallback");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_D3DDevice_BlockUntilVerticalBlank(void) {
    HULK_XDK_TRACE("D3DDevice_BlockUntilVerticalBlank");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CopyRects(hulk_uptr a0, hulk_uptr a1, hulk_u32 a2, hulk_uptr a3, hulk_uptr a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("D3DDevice_CopyRects");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetViewport(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetViewport");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetLight(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetLight");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_LightEnable(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_LightEnable");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetTexture(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetTexture");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPalette(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetPalette");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetIndices(hulk_uptr a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetIndices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Swap(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_Swap");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateImageSurface_RenderTarget(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_uptr a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_CreateImageSurface_RenderTarget");
    return 0;
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexBuffer2(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_CreateVertexBuffer2");
    return 0;
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DVertexBuffer_Lock2(hulk_uptr a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DVertexBuffer_Lock2");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVerticesUP(hulk_u32 a0, hulk_u32 a1, hulk_uptr a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_DrawVerticesUP");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawVertices(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_DrawVertices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DrawIndexedVertices(hulk_u32 a0, hulk_u32 a1, hulk_uptr a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_DrawIndexedVertices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreateVertexShader(hulk_uptr a0, hulk_uptr a1, hulk_uptr a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("D3DDevice_CreateVertexShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetVertexShader(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetVertexShader");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant1(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstant1");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstant4(hulk_u32 a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstant4");
    return 0;
}

extern "C" hulk_u32 HULK_FASTCALL hulk_xdk_D3DDevice_SetVertexShaderConstantNotInline(hulk_u32 a0, hulk_uptr a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetVertexShaderConstantNotInline");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetStreamSource(hulk_u32 a0, hulk_uptr a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetStreamSource");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetVertexShader(hulk_uptr a0) {
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

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Clear(hulk_u32 a0, hulk_uptr a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("D3DDevice_Clear");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_CreatePixelShader(hulk_uptr a0, hulk_uptr a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("D3DDevice_CreatePixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_DeletePixelShader(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_DeletePixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_GetPixelShader(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetPixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShader(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_SetPixelShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetPixelShaderConstant(hulk_u32 a0, hulk_uptr a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("D3DDevice_SetPixelShaderConstant");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_D3D_KickOffAndWaitForIdle(void) {
    HULK_XDK_TRACE("D3D_KickOffAndWaitForIdle");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Get2DSurfaceDesc(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("Get2DSurfaceDesc");
    return 0;
}


// ---------------------------------------------------------------------------------------------------------------
// (x64t18, D89) Textures, their surfaces and palettes: real objects in host memory.
//
// Written from Direct3D 8's public interface (CreateTexture / GetLevelDesc / LockRect / GetSurfaceLevel, the
// D3DSURFACE_DESC, D3DVOLUME_DESC, D3DLOCKED_RECT and D3DLOCKED_BOX structures, AddRef / Release) and from the game's
// call sites (src/platform/xbox/pure3d: d3dTexture 0x00326330 / 0x003265f0 / 0x00326900 / 0x00326a10, d3dDisplay,
// d3dExtFramebufferEffects, the toon shaders), never from the library's code. The game's own tables give each D3D
// format's size: FUN_0031c180 the bits a pixel (16: 2..5, 0x10, 0x11, 0x1d, 0x28; 32: 6, 7, 0x12, 0x1e; 8: 0xb, the
// palettised one), FUN_0031c290 / FUN_00325fd0 the block formats (0xc DXT1, 0xe DXT2/3, 0xf DXT4/5).
//
// Every level is linear (no swizzling: XGSwizzleRect / XGSwizzleBox copy, graphics_xgraphics.cpp), top row first,
// `pitch` bytes a row (a row of 4x4 blocks for the DXT formats). The objects carry what a renderer needs to upload
// them (format, size, levels, the bits); nothing draws them yet: the native image has no graphics device (the Wine
// build replaces pure3d's d3d layer with the pddi/bgfx backend, which never calls these).
//
// What the game reads of a level description: D3DSURFACE_DESC as 7 words (format, type, usage, size, multisample type,
// width, height), D3DVOLUME_DESC likewise (format, type, usage, size, width, height, depth). D3DLOCKED_RECT is
// { INT Pitch; void* pBits; } and D3DLOCKED_BOX { INT RowPitch; INT SlicePitch; void* pBits; } with the pointer at
// its natural alignment (the game's records, include/decls/pddi_texture.h HulkD3dTexture, lay them out so).

namespace {

enum : hulk_u32 {
    kResMagic = 0x48443352u,          // "R3DH": the first word of every object below
    kRTypeSurface = 1, kRTypeVolume = 2, kRTypeTexture = 3, kRTypeVolumeTexture = 4, kRTypeCubeTexture = 5,
    kRTypePalette = 0x100,            // (ours: D3DPalette is not a D3DRESOURCETYPE)
    kMaxLevels = 16,
};

struct Level {
    hulk_u32 width, height, depth;
    hulk_u32 pitch;                   // bytes from a row (of blocks) to the next
    hulk_u32 slicePitch;              // bytes from a slice to the next (the level's size for a 2D level)
    hulk_u32 size;                    // all of the level's bytes
    unsigned char* bits;
};

struct Res {
    hulk_u32 magic;
    hulk_u32 refs;
    hulk_u32 type;                    // kRType*
    hulk_u32 format;                  // the D3D format the game asked for
    hulk_u32 usage;
    hulk_u32 levelCount;
    Level levels[kMaxLevels];         // textures (faces of a cube texture share each level's block: 6 slices)
    unsigned char* memory;            // one block for every level
    Res* parent;                      // a surface: the texture whose level it is (holds a reference)
    hulk_u32 parentLevel;
    hulk_u32 serial;                  // creation order (for the trace and a renderer's cache)
    hulk_u32 dirty;                   // set by a lock, for a renderer to upload and clear
};

hulk_u32 s_serial;

Res* res(hulk_uptr p)
{
    Res* r = (Res*)p;
    return r && r->magic == kResMagic ? r : 0;
}

// bits a pixel (0: a block format, see blockBytes)
hulk_u32 formatBits(hulk_u32 f)
{
    switch (f) {
    case 2: case 3: case 4: case 5: case 0x10: case 0x11: case 0x1d: case 0x28: return 16;
    case 6: case 7: case 0x12: case 0x1e: return 32;
    case 0xb: return 8;
    case 0xc: case 0xe: case 0xf: return 0;
    default: return 32;               // (a format the game's tables do not size: 4 bytes, enough for any of them)
    }
}

hulk_u32 blockBytes(hulk_u32 f)
{
    return f == 0xc ? 8 : (f == 0xe || f == 0xf) ? 16 : 0;
}

void layout(Level* l, hulk_u32 format, hulk_u32 w, hulk_u32 h, hulk_u32 d)
{
    l->width = w ? w : 1;
    l->height = h ? h : 1;
    l->depth = d ? d : 1;
    hulk_u32 block = blockBytes(format), rows;
    if (block) {
        l->pitch = ((l->width + 3) / 4) * block;
        rows = (l->height + 3) / 4;
    } else {
        l->pitch = l->width * (formatBits(format) / 8);
        rows = l->height;
    }
    l->slicePitch = l->pitch * rows;
    l->size = l->slicePitch * l->depth;
}

void release(Res* r)
{
    if (!r || !r->refs || --r->refs)
        return;
    Res* parent = r->parent;
    hulk_host_free(r->memory);
    r->magic = 0;
    hulk_host_free(r);
    if (parent)
        release(parent);
}

const Level* level(const Res* r, hulk_u32 i)
{
    if (r->type == kRTypeSurface)
        return &r->parent->levels[r->parentLevel];
    return i < r->levelCount ? &r->levels[i] : 0;
}

void surfaceDesc(const Res* r, const Level* l, hulk_uptr out)
{
    hulk_u32* d = (hulk_u32*)out;
    if (!d || !l)
        return;
    d[0] = r->format;
    d[1] = kRTypeSurface;
    d[2] = r->usage;
    d[3] = l->slicePitch;
    d[4] = 0;                         // D3DMULTISAMPLE_NONE
    d[5] = l->width;
    d[6] = l->height;
}

struct LockedRect { int pitch; unsigned char* bits; };
struct LockedBox { int rowPitch; int slicePitch; unsigned char* bits; };

// the first byte of RECT { left, top, right, bottom } (or the level's) in a level
unsigned char* at(const Res* r, const Level* l, const int* rect)
{
    if (!rect)
        return l->bits;
    hulk_u32 block = blockBytes(r->format);
    if (block)
        return l->bits + (hulk_u32)(rect[1] / 4) * l->pitch + (hulk_u32)(rect[0] / 4) * block;
    return l->bits + (hulk_u32)rect[1] * l->pitch + (hulk_u32)rect[0] * (formatBits(r->format) / 8);
}

} // namespace

// D3DDevice_CreateTexture2 (width, height, depth, levels, usage, format, resource type): the texture (type 3), volume
// texture (4, `depth` slices) or cube texture (5, six faces) with `levels` levels (0: down to 1x1), or 0.
extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreateTexture2(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5, hulk_u32 a6) {
    HULK_XDK_TRACE("D3DDevice_CreateTexture2");
    hulk_u32 w = a0 ? a0 : 1, h = a1 ? a1 : 1, d = a6 == kRTypeVolumeTexture ? (a2 ? a2 : 1) : 1;
    hulk_u32 slices = a6 == kRTypeCubeTexture ? 6 : 1;
    hulk_u32 n = a3, full = 1;
    for (hulk_u32 m = w > h ? w : h; m > 1; m >>= 1)
        full++;
    if (a6 == kRTypeVolumeTexture) {
        hulk_u32 fd = 1;
        for (hulk_u32 m = d; m > 1; m >>= 1)
            fd++;
        if (fd > full)
            full = fd;
    }
    if (n == 0 || n > full)
        n = full;
    if (n > kMaxLevels)
        n = kMaxLevels;
    Res* r = (Res*)hulk_host_calloc(1, sizeof(Res));
    if (!r)
        return 0;
    r->magic = kResMagic;
    r->refs = 1;
    r->type = a6 == kRTypeVolumeTexture || a6 == kRTypeCubeTexture ? a6 : kRTypeTexture;
    r->format = a5;
    r->usage = a4;
    r->levelCount = n;
    r->serial = ++s_serial;
    hulk_u32 total = 0;
    for (hulk_u32 i = 0; i < n; i++) {
        Level* l = &r->levels[i];
        layout(l, a5, w >> i, h >> i, d >> i);
        if (slices > 1) {             // a cube texture's faces: six slices of the level
            l->depth = slices;
            l->size = l->slicePitch * slices;
        }
        total += (l->size + 15) & ~15u;
    }
    r->memory = (unsigned char*)hulk_host_calloc(1, total ? total : 16);
    if (!r->memory) {
        hulk_host_free(r);
        return 0;
    }
    hulk_u32 off = 0;
    for (hulk_u32 i = 0; i < n; i++) {
        r->levels[i].bits = r->memory + off;
        off += (r->levels[i].size + 15) & ~15u;
    }
    return (hulk_uptr)r;
}

// D3DTexture_GetLevelDesc (texture, level, D3DSURFACE_DESC*): the game calls it Get2DSurfaceDesc
// (tools/native_bind.py GAME_NAME_ROWS)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DTexture_GetLevelDesc(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2) {
    HULK_XDK_TRACE("D3DTexture_GetLevelDesc");
    Res* r = res(a0);
    if (!r)
        return 0;
    surfaceDesc(r, level(r, a1), a2);
    return 0;
}

// D3DTexture_GetSurfaceLevel2 (texture, level): a new surface on the level (one reference; it holds one on the
// texture until it is released)
extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DTexture_GetSurfaceLevel2(hulk_uptr a0, hulk_u32 a1) {
    HULK_XDK_TRACE("D3DTexture_GetSurfaceLevel2");
    Res* t = res(a0);
    if (!t || t->type == kRTypeSurface || t->type == kRTypePalette || a1 >= t->levelCount)
        return 0;
    Res* s = (Res*)hulk_host_calloc(1, sizeof(Res));
    if (!s)
        return 0;
    s->magic = kResMagic;
    s->refs = 1;
    s->type = kRTypeSurface;
    s->format = t->format;
    s->usage = t->usage;
    s->parent = t;
    s->parentLevel = a1;
    s->serial = ++s_serial;
    t->refs++;
    return (hulk_uptr)s;
}

// D3DTexture_LockRect (texture, level, D3DLOCKED_RECT*, const RECT* or 0, flags)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DTexture_LockRect(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2, hulk_uptr a3, hulk_u32 a4) {
    (void)a4;
    HULK_XDK_TRACE("D3DTexture_LockRect");
    Res* r = res(a0);
    const Level* l = r ? level(r, a1) : 0;
    LockedRect* out = (LockedRect*)a2;
    if (!l || !out)
        return 0;
    out->pitch = (int)l->pitch;
    out->bits = at(r, l, (const int*)a3);
    r->dirty |= 1u << a1;
    return 0;
}

// D3DVolumeTexture_LockBox (volume texture, level, D3DLOCKED_BOX*, const D3DBOX* or 0, flags)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DVolumeTexture_LockBox(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2, hulk_uptr a3, hulk_u32 a4) {
    (void)a4;
    HULK_XDK_TRACE("D3DVolumeTexture_LockBox");
    Res* r = res(a0);
    const Level* l = r ? level(r, a1) : 0;
    LockedBox* out = (LockedBox*)a2;
    if (!l || !out)
        return 0;
    const hulk_u32* box = (const hulk_u32*)a3;   // D3DBOX { Left, Top, Right, Bottom, Front, Back }
    int rect[2] = { box ? (int)box[0] : 0, box ? (int)box[1] : 0 };
    out->rowPitch = (int)l->pitch;
    out->slicePitch = (int)l->slicePitch;
    out->bits = at(r, l, box ? rect : 0) + (box ? box[4] * l->slicePitch : 0);
    r->dirty |= 1u << a1;
    return 0;
}

// D3DSurface_GetDesc (surface, D3DSURFACE_DESC*): ours; any other surface (the device's render targets, which this
// shim does not make yet) keeps the caller's description
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_GetDesc(hulk_uptr a0, hulk_uptr a1) {
    HULK_XDK_TRACE("D3DSurface_GetDesc");
    Res* r = res(a0);
    if (r && r->type == kRTypeSurface)
        surfaceDesc(r, level(r, 0), a1);
    return 0;
}

// D3DSurface_LockRect (surface, D3DLOCKED_RECT*, const RECT* or 0, flags)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DSurface_LockRect(hulk_uptr a0, hulk_uptr a1, hulk_uptr a2, hulk_u32 a3) {
    (void)a3;
    HULK_XDK_TRACE("D3DSurface_LockRect");
    Res* r = res(a0);
    LockedRect* out = (LockedRect*)a1;
    if (!r || r->type != kRTypeSurface || !out)
        return 0;
    const Level* l = level(r, 0);
    out->pitch = (int)l->pitch;
    out->bits = at(r->parent, l, (const int*)a2);
    r->parent->dirty |= 1u << r->parentLevel;
    return 0;
}

// D3DResource_AddRef / D3DResource_Release: the new count (an object this shim did not make: 0, as before)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_AddRef(hulk_uptr a0) {
    HULK_XDK_TRACE("D3DResource_AddRef");
    Res* r = res(a0);
    return r ? ++r->refs : 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DResource_Release(hulk_uptr a0) {
    HULK_XDK_TRACE("D3DResource_Release");
    Res* r = res(a0);
    if (!r || !r->refs)
        return 0;
    hulk_u32 left = r->refs - 1;
    release(r);
    return left;
}

// D3DDevice_CreatePalette2 (D3DPALETTESIZE: 0 256, 1 128, 2 64, 3 32 entries): a palette of D3DCOLORs
extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_CreatePalette2(hulk_u32 a0) {
    HULK_XDK_TRACE("D3DDevice_CreatePalette2");
    hulk_u32 entries = 256u >> (a0 & 3);
    Res* r = (Res*)hulk_host_calloc(1, sizeof(Res));
    if (!r)
        return 0;
    r->memory = (unsigned char*)hulk_host_calloc(entries, 4);
    if (!r->memory) {
        hulk_host_free(r);
        return 0;
    }
    r->magic = kResMagic;
    r->refs = 1;
    r->type = kRTypePalette;
    r->levelCount = 1;
    r->levels[0].width = entries;
    r->levels[0].height = r->levels[0].depth = 1;
    r->levels[0].pitch = r->levels[0].slicePitch = r->levels[0].size = entries * 4;
    r->levels[0].bits = r->memory;
    r->serial = ++s_serial;
    return (hulk_uptr)r;
}

// D3DPalette_Lock2 (palette, flags): the entries
extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DPalette_Lock2(hulk_uptr a0, hulk_u32 a1) {
    (void)a1;
    HULK_XDK_TRACE("D3DPalette_Lock2");
    Res* r = res(a0);
    if (!r || r->type != kRTypePalette)
        return 0;
    r->dirty |= 1;
    return (hulk_uptr)r->levels[0].bits;
}

// 0x0038acb0: the game's volume textures' level description (d3dTexture 0x003265f0 / 0x00326900 call it with the
// volume texture, a level and their D3DVOLUME_DESC): D3DVolumeTexture_GetLevelDesc
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3D_GetSurfaceDesc_helper(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2) {
    HULK_XDK_TRACE("D3D_GetSurfaceDesc_helper");
    Res* r = res(a0);
    const Level* l = r ? level(r, a1) : 0;
    hulk_u32* d = (hulk_u32*)a2;
    if (!l || !d)
        return 0;
    if (r->type != kRTypeVolumeTexture) {
        surfaceDesc(r, l, a2);
        return 0;
    }
    d[0] = r->format;
    d[1] = kRTypeVolume;
    d[2] = r->usage;
    d[3] = l->size;
    d[4] = l->width;
    d[5] = l->height;
    d[6] = l->depth;
    return 0;
}

// ---- the device's back buffer and depth buffer (x64t18): shim textures the size and formats of the game's
// D3DPRESENT_PARAMETERS, so the render-target queries return real surfaces (d3dDisplay 0x0031ae70 sizes the display
// from the render target's description). The game's record is 32-bit words throughout (d3dDisplay.cpp
// PresentParams: BackBufferWidth, BackBufferHeight, BackBufferFormat, ..., AutoDepthStencilFormat at word 9).
namespace {
Res* s_backBuffer;                    // the textures (one reference each, the device's)
Res* s_depthBuffer;
Res* s_renderTarget;                  // the current targets' surfaces (a reference each, SetRenderTarget's)
Res* s_depthSurface;
hulk_u32 s_device;                    // what *ppDevice points at (the game only tests it)

Res* surfaceOf(Res* t)
{
    return t ? res(hulk_xdk_D3DTexture_GetSurfaceLevel2((hulk_uptr)t, 0)) : 0;
}

void setTargets(Res* rt, Res* ds)
{
    if (rt)
        rt->refs++;
    if (ds)
        ds->refs++;
    release(s_renderTarget);
    release(s_depthSurface);
    s_renderTarget = rt;
    s_depthSurface = ds;
}

void makeBuffers(const hulk_u32* pp)
{
    Res* back = res(hulk_xdk_D3DDevice_CreateTexture2(pp[0], pp[1], 1, 1, 1, pp[2], kRTypeTexture));
    Res* depth = pp[8] ? res(hulk_xdk_D3DDevice_CreateTexture2(pp[0], pp[1], 1, 1, 2, pp[9], kRTypeTexture)) : 0;
    Res* rt = surfaceOf(back);
    Res* ds = surfaceOf(depth);
    setTargets(rt, ds);
    release(rt);
    release(ds);
    release(s_backBuffer);
    release(s_depthBuffer);
    s_backBuffer = back;
    s_depthBuffer = depth;
}

Res* addRef(Res* r)
{
    if (r)
        r->refs++;
    return r;
}
} // namespace

// Direct3D_CreateDevice (adapter, device type, window, behaviour flags, D3DPRESENT_PARAMETERS*, IDirect3DDevice8**)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Direct3D_CreateDevice(hulk_u32 a0, hulk_u32 a1, hulk_uptr a2, hulk_u32 a3, hulk_uptr a4, hulk_uptr a5) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("Direct3D_CreateDevice");
    if (a4)
        makeBuffers((const hulk_u32*)a4);
    if (a5)
        *(hulk_uptr*)a5 = (hulk_uptr)&s_device;
    return 0;
}

// D3DDevice_Reset (D3DPRESENT_PARAMETERS*): new buffers for the new parameters
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_Reset(hulk_uptr a0) {
    HULK_XDK_TRACE("D3DDevice_Reset");
    if (a0)
        makeBuffers((const hulk_u32*)a0);
    return 0;
}

// D3DDevice_SetRenderTarget (render target or 0 to keep it, depth surface or 0 for none)
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_D3DDevice_SetRenderTarget(hulk_uptr a0, hulk_uptr a1) {
    HULK_XDK_TRACE("D3DDevice_SetRenderTarget");
    Res* rt = res(a0);
    setTargets(rt ? rt : s_renderTarget, res(a1));
    return 0;
}

// D3DDevice_GetBackBuffer2 (index; -1 the front buffer): a reference to the back buffer's surface (one buffer)
extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetBackBuffer2(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("D3DDevice_GetBackBuffer2");
    return (hulk_uptr)surfaceOf(s_backBuffer);
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetRenderTarget2(void) {
    HULK_XDK_TRACE("D3DDevice_GetRenderTarget2");
    return (hulk_uptr)addRef(s_renderTarget);
}

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_D3DDevice_GetDepthStencilSurface2(void) {
    HULK_XDK_TRACE("D3DDevice_GetDepthStencilSurface2");
    return (hulk_uptr)addRef(s_depthSurface);
}
