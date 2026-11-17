// Stand-ins for graphics: XGraphics: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"
#include "../crt/host_crt.h"

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XGBuffer_GetBufferPointer(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("XGBuffer_GetBufferPointer");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGBuffer_Release(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("XGBuffer_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGAssembleShader(hulk_uptr a0, hulk_uptr a1, hulk_u32 a2, hulk_u32 a3, hulk_uptr a4, hulk_uptr a5, hulk_uptr a6, hulk_uptr a7, hulk_uptr a8, hulk_uptr a9, hulk_uptr a10) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8; (void)a9; (void)a10;
    HULK_XDK_TRACE("XGAssembleShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGIsSwizzledFormat(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XGIsSwizzledFormat");
    return 0;
}

// (x64t18, D89) The shim's textures are linear (graphics_d3d8.cpp), so "swizzling" a rectangle or a box into one is a
// copy. XGSwizzleRect (source, source pitch or 0 for packed rows, const RECT* or 0 for all, destination, the
// destination's width and height, const POINT* or 0 for its origin, bytes a pixel) and XGSwizzleBox (source, row and
// slice pitch or 0, const D3DBOX* or 0, destination, width, height, depth, const XGPOINT3D* or 0, bytes a pixel), from
// their documented parameters and the game's calls (d3dTexture 0x00326a10: whole levels, packed rows). The destination
// rows are `width` pixels apart, as the shim's levels are laid out.
static void hulk_xg_copy(const unsigned char* src, hulk_u32 srcPitch, unsigned char* dst, hulk_u32 dstPitch,
                         hulk_u32 rowBytes, hulk_u32 rows)
{
    for (hulk_u32 y = 0; y < rows; y++)
        hulk_host_memcpy(dst + y * dstPitch, src + y * srcPitch, rowBytes);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleRect(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2, hulk_uptr a3, hulk_u32 a4, hulk_u32 a5, hulk_uptr a6, hulk_u32 a7) {
    HULK_XDK_TRACE("XGSwizzleRect");
    if (!a0 || !a3 || !a7)
        return 0;
    const int* rect = (const int*)a2;          // RECT { left, top, right, bottom }
    const int* point = (const int*)a6;         // POINT { x, y }
    hulk_u32 x0 = rect ? (hulk_u32)rect[0] : 0, y0 = rect ? (hulk_u32)rect[1] : 0;
    hulk_u32 w = rect ? (hulk_u32)(rect[2] - rect[0]) : a4, h = rect ? (hulk_u32)(rect[3] - rect[1]) : a5;
    hulk_u32 dx = point ? (hulk_u32)point[0] : 0, dy = point ? (hulk_u32)point[1] : 0;
    hulk_u32 srcPitch = a1 ? a1 : w * a7, dstPitch = a4 * a7;
    if (dx + w > a4 || dy + h > a5)
        return 0;
    hulk_xg_copy((const unsigned char*)a0 + y0 * srcPitch + x0 * a7, srcPitch,
                 (unsigned char*)a3 + dy * dstPitch + dx * a7, dstPitch, w * a7, h);
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleBox(hulk_uptr a0, hulk_u32 a1, hulk_u32 a2, hulk_uptr a3, hulk_uptr a4, hulk_u32 a5, hulk_u32 a6, hulk_u32 a7, hulk_uptr a8, hulk_u32 a9) {
    HULK_XDK_TRACE("XGSwizzleBox");
    if (!a0 || !a4 || !a9)
        return 0;
    const hulk_u32* box = (const hulk_u32*)a3;  // D3DBOX { Left, Top, Right, Bottom, Front, Back }
    const hulk_u32* point = (const hulk_u32*)a8;
    hulk_u32 x0 = box ? box[0] : 0, y0 = box ? box[1] : 0, z0 = box ? box[4] : 0;
    hulk_u32 w = box ? box[2] - box[0] : a5, h = box ? box[3] - box[1] : a6, d = box ? box[5] - box[4] : a7;
    hulk_u32 dx = point ? point[0] : 0, dy = point ? point[1] : 0, dz = point ? point[2] : 0;
    hulk_u32 rowPitch = a1 ? a1 : w * a9, slicePitch = a2 ? a2 : rowPitch * h;
    hulk_u32 dstRow = a5 * a9, dstSlice = dstRow * a6;
    if (dx + w > a5 || dy + h > a6 || dz + d > a7)
        return 0;
    for (hulk_u32 z = 0; z < d; z++)
        hulk_xg_copy((const unsigned char*)a0 + (z0 + z) * slicePitch + y0 * rowPitch + x0 * a9, rowPitch,
                     (unsigned char*)a4 + (dz + z) * dstSlice + dy * dstRow + dx * a9, dstRow, w * a9, h);
    return 0;
}
